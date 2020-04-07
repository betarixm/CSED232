


int main() {
    bool isLogin = false;
    int input = 0;
    enum Mode {
        MENU_MAIN,
        MENU_MY_PAGE,
        MENU_FRIENDS,
        MENU_FEED
    };

    Mode mode = MENU_MAIN;
    MainMenu mainMenu = MainMenu();
    FriendsMenu friendsMenu = FriendsMenu();
    MyPageMenu myPageMenu = MyPageMenu();
    FeedMenu feedMenu = FeedMenu();

    User* user = nullptr;
    UserList userList = UserList();

    auto cin_backup = cin.rdbuf();

    Stream s = Stream(cin.rdbuf());
    s._out.open("command.txt", ios::app);

    while(true){
        if(mode == MENU_MAIN){
            input = mainMenu.input(user, s);
            if(input == 0){
                continue;
            } else if (input == 1){
                userList.signUp(s);
            } else if (input == 2){
                user = userList.signIn(s);
                if(user != nullptr){
                    mode = MENU_MY_PAGE;
                }
            } else if (input == 3){

            } else if (input == 4){
                break;
            }
        } else if (mode == MENU_MY_PAGE) {
            input = myPageMenu.input(user, s);
            if(input == 0){
                continue;
            } else if (input == 1){
                mode = MENU_FRIENDS;
            } else if (input == 2){
                mode = MENU_FEED;
            } else if (input == 3){
                user = nullptr;
                mode = MENU_MAIN;
            } else if (input == 4){
                mode = MENU_MAIN;
            }
        } else if (mode == MENU_FRIENDS) {
            input = friendsMenu.input(user, s);
            if(input == 0){
                continue;
            } else if (input == 1){

            } else if (input == 2){

            } else if (input == 3){

            } else if (input == 4){
                mode = MENU_MY_PAGE;
            }
        } else if (mode == MENU_FEED) {
            input = feedMenu.input(user, s);
            if(input == 0){
                continue;
            } else if (input == 1){

            } else if (input == 2){

            } else if (input == 3){

            } else if (input == 4){
                mode = MENU_MY_PAGE;
            }
        }
    }


}


