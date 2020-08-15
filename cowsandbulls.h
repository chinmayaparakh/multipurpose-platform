#ifndef COWSANDBULLS_H
#define COWSANDBULLS_H


class film {

private:
    std::string str;
    char a[4];
    int aalu;// = 1;
    const int BLUE;// = 1;
    const int GREEN;// = 2;
    const int RED;// = 4;
    const int WHITE;// = 15;
    const int ORANGE;// = 6;

public:
    film();
    std::string read();
    std::string selection(std::string line[]);
    void print();
    std::string getword();
    void chance(int a);
    void hint();
    void insertion(std::string a);
    bool isEqual(std::string word);
    bool isEquals();
    void gameplay();
    film(std::string a);

    void rules();
    void newintro();
    void intro();
    void showBlinkingLights(std::string temp, int t);
    void changeColour(int colour);
    void clearScreen(int characterLength);
    void gotoxy(short x, short y);

};

#endif // COWSANDBULLS_H
