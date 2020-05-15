class Component:
    name = ""
    brief = ""


class Variable(Component):
    c_type = ""
    o_type = ""


class Method(Component):
    c_type = ""
    o_type = ""
    text = ""


class Class(Component):
    methods = list()
    variables = list()

    def __init__(self):
        self.methods = list()
        self.variables = list()

    def add_method(self, m: Method):
        self.methods.append(m)

    def add_variable(self, v: Variable):
        self.variables.append(v)


def remove_blank(s: str):
    return s.replace(" ", "")


def variable_parser(s: str, o_type: str) -> Variable:
    tmp = Variable()

    s = s.replace("    ", "")
    tmp.c_type = s.split(" ")[0]
    tmp.name = s.split(";")[0]
    tmp.brief = s.split("@brief ")[1]
    tmp.o_type = o_type

    return tmp


def method_parser(s: str, o_type: str) -> Method:
    tmp = Method()

    s = s.replace("    ", "")
    str_line = s.split("\n")

    tmp.o_type = o_type
    for line in str_line:
        if "@brief" in line:
            tmp.brief = line.split("@brief ")[1]
        else:
            tmp.text += (line.replace(";", "").replace("*/", ""))
    return tmp


def class_parser(s: str, tmp) -> Class:

    stack = ""
    current_o_type = ""
    str_lines = s.split('\n')

    for l in str_lines:
        if "@brief" in l and ";" not in l and "///" not in l:
            tmp.brief = l.split("@brief ")[1]
            stack += (l+'\n')
        elif "class" in l:
            tmp.name = l.split("class ")[1].replace(" {", "")
        elif ":" in l:
            current_o_type = l.replace(":", "")
        elif "///" in l and ";" in l:
            tmp.add_variable(variable_parser(l, current_o_type))
        elif "///" in l:
            stack = ""
            stack += (l + '\n')
        elif "}" in l:
            stack = ""
            continue
        elif ";" in l:
            stack += (l + '\n')
            tmp.add_method(method_parser(stack, current_o_type))
            stack = ""

        elif "" == l or "*" in l:
            continue
        else:
            stack += (l + '\n')

    return tmp


def parser(s: str):
    class_str_list: list = s.split("/**")[1:]
    for class_str in class_str_list:
        class_list.append(Class())
        class_parser(class_str, class_list[-1])


def gen_table() -> str:
    res = ""

    for c in class_list:
        res += c.name + "\n"
        res += c.brief + "\n"
        for i in c.variables:
            res += (i.name + '\t' + i.brief + '\t' + i.o_type) + "\n"
        for i in c.methods:
            res += (i.text + '\t' + i.brief + '\t' + i.o_type) + "\n"

    return res


filenames = ['Block.h',
             'BlockList.h',
             'Board.h',
             'Game.h',
             'IO.h',
             'Node.h',
             'Point.h',
             'Position.h',
             'Queue.h',
             'Stack.h',
             'Tetromino.h',
             'const.h']

for i in filenames:
    class_list = []
    target_text = ""
    f = open("../" + i, encoding="UTF8")
    target_text += (f.read() + '\n')
    parser(target_text)
    r = gen_table()
    f = open(i + ".tsv", "w")
    f.write(r)

