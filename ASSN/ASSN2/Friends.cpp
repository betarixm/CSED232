#include "Friends.h"
#include "User.h"

void Friends::addFriend(Stream &s, UserList *userList) {
    string id;
    cout << "Input ID: ";
    s.getLine(id);
    Node<User>* target = userList->getUserById(id);
    if(target == nullptr){
        cout << id << " is not exist user." << endl;
    } else {
        if(friendsList->exist(target->data())){
            cout << id << " is already your friend." << endl;
        } else {
            auto tmp = friendsList->begin();
            for(; tmp!=nullptr; tmp=tmp->next()){
                if( tmp->data()->id() <= id && ((tmp->next() == nullptr)||(tmp->next() != nullptr && id < tmp->next()->data()->id()))){
                    break;
                }
            }
            friendsList->insert(tmp, target->data());
            cout << id << " is added to your friend." << endl;
        }

    }
}

void Friends::removeFriendById(Stream &s, UserList *userList) {
    string id;
    cout << "Input ID: ";
    s.getLine(id);
    Node<User>* target = userList->getUserById(id);
    if(target == nullptr){
        cout << id <<" is not exist user." << endl;
    } else {
        target = friendsList->find(target->data());
        if(target != nullptr){
            friendsList->drop(target);
            cout << id << " is deleted from your friend list." << endl;
        } else {
            cout << id << " is not your friend." << endl;
        }
    }
}

void Friends::printFriends() {
    if(friendsList->size() == 0){
        cout << "You have not any friends... :(" << endl;
        return;
    }
    for(auto tmp=friendsList->begin(); tmp != nullptr; tmp=tmp->next()){
        tmp->data()->printProfile();
    }
}

void Friends::removeFriendByUser(User *user) {
    for(auto tmp=friendsList->begin(); tmp!=nullptr; tmp=tmp->next()){
        if(tmp->data() == user){
            friendsList->drop(tmp);
        }
    }
}