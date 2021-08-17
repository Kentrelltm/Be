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



int main() {
    int choice;
    string username, password, bio;
    

    cout << "1: Register\n2: Login\nYour choice >> "; cin >> choice;
    if (choice == 1) {
        // string username, password;

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
            char pick;
            
            system("clear");
            cout << "Successfully logged in!" << endl;
            cout << "Welcome to your profile!!\n\n" << endl;
            cout << "Name: " + username << endl;
            cout << "Edit bio?\n\n\t\t\t (Yes/No)" << endl; cin >> pick;
            if (pick == 'y') {
                cout << "\n\n\t >>>> "; cin >> bio;

                ofstream file;
                file.open(username + ".txt",ios::in);
                file << bio << endl;
                cout << bio << endl;
                main();
            }
            else {
                main();
            }
            
            

        };
    };
};