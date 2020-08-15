#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include "bollywood.h"

using namespace std;

void bollywood::rules()
{
    gotoxy(28, 2);
    cout << "\t\t\tINSTRUCTIONS\n\n\n";
    gotoxy(45, 3);
    cout << "--------------------";
    gotoxy(18, 6);
    cout << "1 - You will have to guess the movie name in this game.\n";
    gotoxy(18, 8);
    cout << "2 - You will get a total of 8 chances to guess the movie name.\n";
    gotoxy(18, 10);
    cout << "3 - You will also get 8 hints for revealing characters of the movie.\n";
    gotoxy(18, 12);
    cout << "4 - Also please use only alphabets\n";
    gotoxy(18, 14);
    cout << "5 - To exit to main menu press 0\n";
    gotoxy(18, 16);
    showBlinkingLights("Excited !!!", 3);
    cout << "Press any key to continue ...";
    getch();
    aalu = 2;
    system("CLS");
    newintro();
}

void bollywood::gotoxy(short x, short y){
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void bollywood::clearScreen(int characterLength) {
	for (int i = 0; i < characterLength; i++) {
		cout << "\b";
	}
}

void bollywood::changeColour(int colour) {
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colour);
}

void bollywood::showBlinkingLights(string temp, int t) {
	changeColour(RED);
	Beep(250, 300);
	cout << temp;
	if(t == 1){
        clearScreen(19);
	}
	else if(t == 3){
        clearScreen(11);
	}
	Sleep(500);

	changeColour(GREEN);
	Beep(280, 300);
	cout << temp;
	if(t == 1){
        clearScreen(19);
	}
	else if(t == 3){
        clearScreen(11);
	}
	Sleep(500);

	changeColour(BLUE);
	Beep(250, 500);
	cout << temp;
	if(t == 1){
        clearScreen(19);
	}
	else if(t == 3){
        clearScreen(11);
	}
	Sleep(500);
	if(t == 1){
        cout << "";
	}
	else {
        Beep(340, 200);
        Beep(350, 200);
        Beep(360, 200);
	}

	changeColour(WHITE);
}

bollywood::bollywood(): aalu(1), BLUE(1), GREEN(2), RED(4), WHITE(15), ORANGE(6){
    aalu = 1;
    read();
}
string bollywood::read(){
    string line[100];
    int i = 0;
    ifstream fp("movie.txt");
    while(getline(fp,line[i]))
    {
        i++;
    }
    return selection(line);
}
string bollywood::selection(string line[]){
    srand(time(0));
    int i = (rand() % 100) + 1;
    movie = line[i];
    int n = movie.length();
    for(int j=0;j<n;j++){
        if(movie[j]==' '){
            a[j]=' ';
        }
        else
            a[j]='-';
    }
    return movie;
}
void bollywood::print(){
    int n = movie.length();
    gotoxy(38, 13);
    cout<<"Name of the movie: ";
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
}
int bollywood::getletter(){
    char let;
    gotoxy(27, 17);
    cout<<"Letter: ";
    cin>>let;
    return let;
}
void bollywood::chance(int a){
    gotoxy(27, 15);
    cout<<"Chances Remaining: "<<8 - a<<endl;
}
void bollywood::hint(){
    int n = movie.length();
    for(int j = 0; j < n; j++){
        if(a[j] == '-'){
            a[j] = movie[j];
            return;
        }
    }
}
void bollywood::insertion(char b){
    int n = movie.length();
    for(int j = 0; j < n; j++){
        if(movie[j] == b){
            a[j] = b;
        }
    }
}
bool bollywood::isCheck(char b){
    int n = movie.length();
    for(int j = 0; j < n; j++){
        if(movie[j] == b){
            a[j] = b;
            return 1;
        }
    }
    return 0;
}
bool bollywood::isEqual(){
    int n = movie.length();
    for(int i = 0; i < n; i++){
        if(a[i] != movie[i]){
            return 0;
        }
    }
    return 1;
}
void bollywood::gameplay(){
    int k = 0;
    char letter;
    while(k != 8){
        aalu = 2;
        system("CLS");
        newintro();
        print();
        chance(k);
        letter = getletter();
        if (letter == '0')
            return;
        if(letter=='.'){
            hint();
            if(isEqual()){
                print();
                system("CLS");
                newintro();
                gotoxy(38, 13);
                cout<<"Congratulations!!! You won the game"<<endl;
                PlaySound(TEXT("SMALL_CROWD_APPLAUSE-Yannick_Lemieux-1268806408.wav"),NULL,SND_SYNC);
                return;
                //exit(0);
            }
        }
        if(isCheck(letter)){
            insertion(letter);
            if(isEqual()){
                print();
                system("CLS");
                aalu = 2;
                newintro();
                gotoxy(38, 13);
                cout<<"Congratulations!!! You won the game"<<endl;
                PlaySound(TEXT("SMALL_CROWD_APPLAUSE-Yannick_Lemieux-1268806408.wav"),NULL,SND_SYNC);
                return;
            }
        }
        else
            k++;
    }
    system("CLS");
    aalu = 2;
    newintro();
    gotoxy(38, 14);
    cout<<"You have exhausted your 8 moves"<<endl;
    gotoxy(38, 15);
    cout<<"Game over"<<endl;
    gotoxy(38, 16);
    cout<<"Name of the movie is "<<movie<<endl;
    PlaySound(TEXT("SAD - SOUND EFFECT.wav"),NULL,SND_SYNC);
    Sleep(3000);
}

bollywood::bollywood(string a): aalu(1), BLUE(1), GREEN(2), RED(4), WHITE(15), ORANGE(6){
    intro();
    bollywood start;
    start.gameplay();
}


void bollywood::intro()
{
    changeColour(14);
    cout << "\t\t _________________________________________________________________________________\n";
    cout << "\t\t|                           ____         ____   ____            ____              |\n";
    cout << "\t\t|            \\          /  |      |     |      |    |  |\\  /|  |                  |\n";
    cout << "\t\t|             \\        /   |__    |     |      |    |  | \\/ |  |__                |\n";
    cout << "\t\t|              \\  /\\  /    |      |     |      |    |  |    |  |                  |\n";
    cout << "\t\t|               \\/  \\/     |____  |____ |____  |____|  |    |  |____              |\n";
    cout << "\t\t|              --------------------------------------------------------           |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                              _______   _____                                    |\n";
    cout << "\t\t|                                 |     |     |                                   |\n";
    cout << "\t\t|                                 |     |     |                                   |\n";
    cout << "\t\t|                                 |     |     |                                   |\n";
    cout << "\t\t|                                 |     |_____|                                   |\n";
    cout << "\t\t|                                ---------------                                  |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|    ____    ____                                      ____    ____    ____       |\n";
    cout << "\t\t|   |    |  |    |  |      |      \\  /  \\          /  |    |  |    |  |    \\      |\n";
    cout << "\t\t|   |____|  |    |  |      |       \\/    \\        /   |    |  |    |  |     |     |\n";
    cout << "\t\t|   |    |  |    |  |      |       /      \\  /\\  /    |    |  |    |  |     |     |\n";
    cout << "\t\t|   |____|  |____|  |____  |____  /        \\/  \\/     |____|  |____|  |____/      |\n";
    cout << "\t\t|  ---------------------------------------------------------------------------    |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|_________________________________________________________________________________|\n";
    gotoxy(18, 24);
    showBlinkingLights("Game Starting .....", 1);
    gotoxy(18, 25);
    showBlinkingLights(".........................", 2);
    system("CLS");
    changeColour(WHITE);
    newintro();
    return;
}

void bollywood::newintro()
{
    changeColour(14);
    cout << "\n\t\t _________________________________________________________________________________\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|                                                                                 |\n";
    cout << "\t\t|_________________________________________________________________________________|\n";
    if (aalu == 1){
        rules();
    }
    else{
        gotoxy(32, 15);
    }
}


