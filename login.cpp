#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string line = "----------------------------------------";

bool IsLoggedIn() {
    string username, password, un, pw, bio;

    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> password;

    ifstream read( username + ".txt",ios::out);
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password) {
        return true;
    }
    else {
        return false;
    }
}
void userProfile() {
    int pick;
    char bio[100];
    system("clear");
    cout << "Hello and Welcome to your profile!!" << endl;
    cout << line;
    cout << "These are your options as of now:\n1. Edit Bio\nPlease select an option: ";
    switch (pick) {
        case 1: {
            cout << "Enter Bio information\n >>> "; cin >> bio;
            ofstream file;

        }
        
            
    
        default: {
        userProfile();
        }
    };

}


int main() {
    int choice;

    cout << "1: Register\n2: Login\nYour choice >> "; cin >> choice;
    if (choice == 1) {
        string username, password;

        cout << "Select a username: "; cin >> username;
        cout << "Select a password: "; cin >> password;

        ofstream file;
        file.open(username + ".txt",ios::out);
        file << username << endl << password;
        file.close();

        main();
    }
    else if (choice == 2) {
        bool status = IsLoggedIn();

        if (!status) {
            cout << "Wrong login!" << endl;
            
            return 0;
        }
        else {
            cout << "Successfully logged in!" << endl;
            
            return 1;
        }
    }
}