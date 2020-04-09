#include "User.h"

User::User(string &id, string &name, string &birthday, string &password) {
    this->id.assign(id);
    this->name.assign(name);
    this->birthday.assign(birthday);
    this->password.assign(password);
}

Node<User>* UserList::addUser(Stream& s) {
    string infos[4];
    string msgs[4] = {"ID: ", "Name: ", "Birthday: ", "Password: "};

    for(int i = 0; i < 4; i++){
        cout << msgs[i];
        infos[i].assign(s.in<string>());
    }

    for(auto user = list->first; user != nullptr; user = user->next){
        if(user->data->id == infos[0]){
            return nullptr;
        }
    }

    auto* tmp = new User(infos[0], infos[1], infos[2], infos[3]);
    Node<User>* user = list->add(tmp);
    cout << "Registration Done!" << endl;
    return user;

}

Node<User>* UserList::signIn(Stream &s) {
    string id, password;
    cout << "ID: ";
    id.assign(s.in<string>());
    cout << "Password: ";
    password.assign(s.in<string>());

    for(auto user = list->first; user != nullptr; user = user->next){
        if(user->data->id == id && user->data->password == password){
            return user;
        }
    }
    return nullptr;
}

User* UserList::removeUser(Node<User>* user) {
    list->drop(user);
}