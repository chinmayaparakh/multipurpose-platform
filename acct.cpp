#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include "acct.h"
using namespace std;

std::ostream & operator << (std::ostream &out, const acct & obj) {
    out << obj.username << endl;
    out << obj.password << endl;
    out << obj.name << endl;
    out << obj.gender << endl;
    out << obj.age << endl;
    return out;
}

std::istream & operator >> (std::istream &in,  acct &obj) {
    in >> obj.username;
    in >> obj.password;
    in >> obj.name;
    in >> obj.gender;
    in >> obj.age;
    return in;
}

//bool checkuser(string user) {}

string acct::encrypt() {
    for (int i = 0; i < password.size(); i++)
        password[i] = password[i] ^ 2;
    return password;
}

void acct::gotoxy(short x, short y){
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void save(acct &obj) {
    ofstream fp;
    fp.open("accounts.txt", ios::app);
    fp << obj;
}

int acct::signup() {
    signup_overview();
    gotoxy(50, 10);
    string temp1, temp2;
    getline(cin, name);
    getline(cin, name);
    gotoxy(63, 12);
    getline(cin, username);
    gotoxy(54, 14);
    getline(cin, temp1);
    gotoxy(50, 16);
    getline(cin, temp2);
    while (temp1 != temp2) {
        gotoxy(30, 14);
        cout << "\aRE-ENTER YOUR PASSWORD -->\n";
        gotoxy(57, 14);
        cout << "\b ";
        getline(cin, temp1);
        gotoxy(50, 16);
        getline(cin, temp2);
    }
    password = temp1;
    gotoxy(49, 18);
    cin >> age;
    gotoxy(60, 20);
    cin >> gender;
    gotoxy(30, 22);
    cout << "Saving your details...";
    Sleep(1000);
    encrypt();
    save(*this);
    return login();
}

void acct::signup_overview(){
    system("CLS");
    cout << "\t __________________________________________________________________________________________\n";
    cout << "\t|                                          SIGNUP                                          |\n";
    cout << "\t| ________________________________________________________________________________________ |\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||              ____________________________________________________________              ||\n";
    cout << "\t||                                        WELCOME                                         ||\n";
    cout << "\t||              ____________________________________________________________              ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                    ENTER YOUR NAME -->                                                 ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                    ENTER YOUR DESIRED USER NAME -->                                    ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                    ENTER YOUR PASSWORD -->                                             ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                    RETYPE PASSWORD -->                                                 ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                    ENTER YOUR AGE -->                                                  ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                    ENTER YOUR GENDER (M / F) -->                                       ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||________________________________________________________________________________________||\n";
    cout << "\t|__________________________________________________________________________________________|\n";
}

void acct::login_overview(){
    system("CLS");
    cout << "\t __________________________________________________________________________________________\n";
    cout << "\t|                                         LOGIN                                            |\n";
    cout << "\t| ________________________________________________________________________________________ |\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||              ____________________________________________________________              ||\n";
    cout << "\t||                                   WELCOME USER                                         ||\n";
    cout << "\t||              ____________________________________________________________              ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                    ENTER YOUR USERNAME -->                                             ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                    ENTER YOUR PASSWORD -->                                             ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||              ____________________________________________________________              ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||________________________________________________________________________________________||\n";
    cout << "\t|__________________________________________________________________________________________|\n";
}

int acct::login() {
    login_overview();
    string user, pass;
    gotoxy(54, 10);
    getline(cin, user);
    getline(cin, user);
    gotoxy(54, 12);
    getline(cin, pass);

    ifstream fp;
    fp.open("accounts.txt", ios::in);

    acct obj;
    //fp.read((char*)&obj, sizeof(obj));

    while (!fp.eof()) {
        fp >> obj;
        //fp.read((char*)&obj, sizeof(obj));
        if (obj.username == user) {
            if (obj.encrypt() == pass) {
                system("CLS");
                return 1;
            }
            else {
                return 0;
            }
        }
    }
    return 0;
}
