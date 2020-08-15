#ifndef ACCT_H
#define ACCT_H


class acct {
    std::string password;
    char gender;
    std::string name;
    short int age;
public:
    std::string username;
    void gotoxy(short x, short y);
    std::string encrypt();
    int signup();
    void login_overview();
    int login();
    void signup_overview();
    friend std::ostream & operator << (std::ostream &out, const acct & obj);

    friend std::istream & operator >> (std::istream &in,  acct &obj);

};

#endif // ACCT_H
