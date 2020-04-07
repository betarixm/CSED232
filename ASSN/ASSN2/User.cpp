#include "User.h"

User::User() {
        for(auto &post: userPosts){
            post = nullptr;
        }

        for(auto &user: friends){
            user = nullptr;
        }

        for(auto &commment: userComments){
            commment = nullptr;
        }
}

bool User::deleteFriend(string& friend_id) {
        for(auto& userFriend: friends){
            if(userFriend != nullptr && userFriend->id == friend_id){
                userFriend = nullptr;
                return true;
            }
        }
        return false;
}
User::~User(){

}

bool UserList::addUser(User* newUser){
        if(user_num >= MAX_USER)
            return false;
        for(auto& user: user_db){
            if(user == nullptr){
                user = newUser, user_num++;
                break;
            }
        }
        return true;
    }

bool UserList::dropUser(string& id){
        for(auto& user: user_db){
            if (id == user->name) {
                delete(user), user_num--;
                break;
            }
        }
    }

UserList::UserList(){
        user_num = 0;
        for(auto& i: user_db){
            i = nullptr;
        }
    }
bool UserList::signUp(Stream& s) {
        User* newUser = new User();
        int i;
        cout << "ID: ";
        newUser->id = s.in<string>();

        cout << "Name:  ";
        newUser->name = s.in<string>();

        cout << "Birthday: ";
        newUser->birth_str = s.in<string>();

        cout << "Password: ";
        newUser->password = s.in<string>();

        for(const auto& user : user_db){
            if(user != nullptr && user->id == newUser->id){
                cout << "Duplicated ID!" << endl;
                delete(newUser);
                return false;
            }
        }
        if(addUser(newUser)){
            cout << "Registration Done!" << endl;
            return true;
        } else {
            delete(newUser);
            cout << "Reach the maximum number of member." << endl;
            return false;
        }

    }

    User* UserList::signIn(Stream& s){
        string id, password;
        cout << "ID: ";
        id = s.in<string>();
        cout << "Password: ";
        password = s.in<string>();

        for(const auto& user : user_db){
            if(user->id == id && user->password == password){
                return user;
            }
        }
        cout << "Unregistered account!" << endl;
        return nullptr;
    }

