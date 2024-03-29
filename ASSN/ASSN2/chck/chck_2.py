#
# POSTECH CSED232 ASSN2 CMD GENERATOR
# Python 3.7+
#
# by beta@plus, minjae gwon.
# github.com/beta-lux
#

import random
import string
from functools import partial
from operator import is_not

USER_NUM = 0
POST_NUM = 0

post_list = []
user_list = []

MAIN = "MAIN"
MY_PAGE = "MYPAGE"
FEED = "FEED"
FRIENDS = "FRIENDS"
POST_LIST = "POSTLIST"
POST = "POST"


class Context:
    c = {
        "MAIN": False,
        "MYPAGE": False,
        "FEED": False,
        "FRIENDS": False,
        "POSTLIST": False,
        "POST": False
    }

    def init(self):
        for key in self.c:
            self.c[key] = False

    def set(self, target):
        self.init()
        self.c[target] = True

    def status(self, target):
        if not self.c[target]:

            print("context error!")
        return self.c[target]


class User:
    def __init__(self, _id, _name, _birth, _pw):
        self.id = _id
        self.name = _name
        self.birth = _birth
        self.pw = _pw
        self.friends = []


current_user: User = None
context = Context()


def py_gen_user(info=f"beta_{USER_NUM}"):
    global USER_NUM
    USER_NUM += 1
    return User(info, f"name_{USER_NUM}", f"2000/12/{USER_NUM}", info)


def sign_up(info=f"beta_{USER_NUM}") -> str:
    if not context.status(MAIN):
        return ""

    user = py_gen_user(info)
    user_list.append(user)
    return f"1\n" \
           f"{user.id}\n" \
           f"{user.name}\n" \
           f"{user.birth}\n" \
           f"{user.pw}\n"


def sign_in(user: User) -> str:
    global current_user
    if not context.status(MAIN):
        return ""
    context.set(MY_PAGE)
    current_user = user
    return f"2\n" \
           f"{user.id}\n" \
           f"{user.pw}\n"


def sign_out() -> str:
    global current_user
    if not context.status(MY_PAGE):
        return ""
    current_user = None
    context.set(MAIN)
    return f"3\n"


def delete_my_account() -> str:
    if not context.status(MY_PAGE):
        return ""
    global current_user
    context.set(MAIN)
    user_list.remove(current_user)
    filter(partial(is_not, None), user_list)
    return f"4\n"


def menu_my_page_to_friends() -> str:
    if not context.status(MY_PAGE):
        return ""
    context.set(FRIENDS)
    return f"1\n"


def menu_my_page_to_feed() -> str:
    if not context.status(MY_PAGE):
        return ""
    context.set(FEED)
    return f"2\n"


def add_friends(fid) -> str:
    if not context.status(FRIENDS):
        return ""

    if fid is None:
        fid = user_list[random.randint(0, len(user_list))].id

    for key in user_list:
        if key.id == fid and key not in current_user.friends:
            current_user.friends.append(key)
            break

    return f"1\n" \
           f"{fid}\n"


def delete_friends(fid) -> str:
    if not context.status(FRIENDS):
        return ""

    if fid is None:
        fid = user_list[random.randint(0, len(user_list))].id

    for key in user_list:
        if key.id == fid and key in current_user.friends:
            current_user.friends.remove(key)
            break
    return f"2\n{fid}\n"


def my_friends() -> str:
    if not context.status(FRIENDS):
        return ""
    return "3\n"


def menu_friends_to_my_page() -> str:
    if not context.status(FRIENDS):
        return ""
    context.set(MY_PAGE)
    return "4\n"


def all_feed():
    if not context.status(FEED):
        return ""
    context.set(POST_LIST)
    return "1\n"


def post(content):
    if not context.status(FEED):
        return ""
    return f"2\n" \
           f"{content}\n"


def my_posting():
    if not context.status(FEED):
        return ""
    context.set(POST_LIST)
    return "3\n"


def menu_feed_to_my_page():
    if not context.status(FEED):
        return ""
    context.set(MY_PAGE)
    return "4\n"


def select_post_number(n): # context-check will be disabled here, because of diversity.
    # if not context.status(POST_LIST):
    #    return ""
    #
    # context.set(POST)
    return str(n) + '\n'


def like(y): # context-check will be disabled here, because of diversity.
    # if not context.status(POST):
    #     return ""
    return f"{y}\n"


def comment(com): # context-check will be disabled here, because of diversity.
    # if not context.status(POST):
    #    return ""

    return f"{com}\n"


def make_rnd_name():
    return ''.join(random.choice(string.ascii_letters + string.digits) for _ in range(8))

# enjoy here!
# some example of using this.
def simulate():
    context.set(MAIN)
    res = ""

    for _ in range(50):
        res += sign_up(make_rnd_name())

    res += sign_in(user_list[0])
    res += menu_my_page_to_feed()
    res += post(make_rnd_name())
    res += menu_feed_to_my_page()
    res += sign_out()

    for u in user_list[1:]:
        res += sign_in(u)
        res += menu_my_page_to_friends()
        res += add_friends(user_list[0].id)
        res += menu_friends_to_my_page()
        res += menu_my_page_to_feed()
        res += all_feed()
        res += select_post_number(0)
        res += like("y")
        res += comment(make_rnd_name())
        res += select_post_number(-1)
        context.set(FEED)
        res += menu_feed_to_my_page()
        res += delete_my_account()

    # put this output to command.txt
    print(res)

    f = open("command.txt", "w")
    f.write(res)
    f.close()

simulate()