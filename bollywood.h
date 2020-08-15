#ifndef BOLLYWOOD_H
#define BOLLYWOOD_H


class bollywood
{
private:
    std::string movie;
    char a[50];
    int aalu;
public:
    bollywood();
    std::string read();
    std::string selection(std::string line[]);
    void print();
    int getletter();
    void chance(int a);
    void hint();
    void insertion(char b);
    bool isCheck(char b);
    bool isEqual();
    void gameplay();
    bollywood(std::string a);

    //sparsh's:
    void rules();
    void newintro();
    void intro();
    void showBlinkingLights(std::string temp, int t);
    void changeColour(int colour);
    void clearScreen(int characterLength);
    void gotoxy(short x, short y);

    const int BLUE;// = 1;
    const int GREEN;// = 2;
    const int RED;// = 4;
    const int WHITE;// = 15;
    const int ORANGE;// = 6;

};

#endif // BOLLYWOOD_H
