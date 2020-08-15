#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <mmsystem.h>
#include "cowsandbulls.h"

using namespace std;

void film::rules()
{
    gotoxy(28, 2);
    cout << "\t\t\tINSTRUCTIONS\n\n\n";
    gotoxy(45, 3);
    cout << "--------------------";
    gotoxy(18, 5);
    cout << "1 - Computer will choose a word and you have to guess it.\n";
    gotoxy(18, 7);
    cout << "2 - There will be only 4 letter words in this game (with no repetition of";
    gotoxy(22, 8);
    cout << "characters).\n";
    gotoxy(18, 10);
    cout << "3 - If entered word has 1 letter matching to the chosen word on correct position";
    gotoxy(22, 11);
    cout << "then 1 BULL is printed.\n";
    gotoxy(18, 13);
    cout << "4 - If entered word has 1 letter matching to the chosen word on incorrect ";
    gotoxy(22, 14);
    cout << "position then 1 COW is printed.\n";
    gotoxy(18, 16);
    cout << "5 - For hint, just press '.' .\n";
    gotoxy(18, 18);
    cout << "6 - Word's letters will not be printed until hint is called or either the player";
    gotoxy(22, 19);
    cout << "wins or looses.\n";
    gotoxy(18, 21);
    cout << "7 - 10 chances will be given and it will be deducted after every action taken by";
    gotoxy(22, 22);
    cout << "the player.\n";
    gotoxy(18, 24);
    cout << "8 - There are only 2 hints available for a player i.e. the player can see only ";
    gotoxy(22, 25);
    cout << "1st and 2nd letter of the word.\n";
    gotoxy(18, 26);
    cout << "9 - PRESS 0 TO EXIT TO MAIN MENU AT ANY TIME";
    gotoxy(18, 28);
    showBlinkingLights("Excited !!!", 3);
    cout << "Press any key to continue ...";
    getch();
    aalu = 2;
    system("CLS");
    newintro();
}

void film::gotoxy(short x, short y){
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void film::clearScreen(int characterLength) {
	for (int i = 0; i < characterLength; i++) {
		cout << "\b";
	}
}

void film::changeColour(int colour) {
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colour);
}

void film::showBlinkingLights(string temp, int t) {
	changeColour(RED);
	//Beep(250, 300);
	cout << temp;
	if(t == 1){
        clearScreen(19);
	}
	else if(t == 3){
        clearScreen(11);
	}
	Sleep(500);

	changeColour(GREEN);
	//Beep(280, 300);
	cout << temp;
	if(t == 1){
        clearScreen(19);
	}
	else if(t == 3){
        clearScreen(11);
	}
	Sleep(500);

	changeColour(BLUE);
	//Beep(250, 500);
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


void film::intro()
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
    cout << "\t\t|    ____   ____                  ____       / ____                          ____ |\n";
    cout << "\t\t|   |      |    |  \\          /  |          / |    |  |    |  |      |      |     |\n";
    cout << "\t\t|   |      |    |   \\        /   |____     /  |____|  |    |  |      |      |____ |\n";
    cout << "\t\t|   |      |    |    \\  /\\  /         |   /   |    |  |    |  |      |           ||\n";
    cout << "\t\t|   |____  |____|     \\/  \\/      ____|  /    |____|  |____|  |____  |____   ____||\n";
    cout << "\t\t|  -------------------------------------/-----------------------------------------|\n";
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

void film::newintro()
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


film::film(): aalu(1), BLUE(1), GREEN(2), RED(4), WHITE(15), ORANGE(6){
    read();
}

string film::read(){
    string line[2398];
    int i=0;
    ifstream fp("c&b.txt");
    while(getline(fp,line[i])){
        i++;
    }
    return selection(line);
}
string film::selection(string line[]){
    srand(time(0));
    int i = (rand() % 1000) + 1;
    str = line[i];
    for(int j=0;j<4;j++){
        a[j]='-';
    }
    return str;
}
void film::print(){
    gotoxy(32, 20);
    cout << "Word is: ";
    for(int i = 0; i < 4; i++){
        cout << a[i];
    }
}
string film::getword(){
    string word;
    gotoxy(32, 16);
    cout<<"Enter a 4 letter Word -->";
    cin>>word;
    return word;
}

void film::chance(int a){
    gotoxy(32, 12);
    cout<<"____________________________________________"<<endl;
    gotoxy(32, 14);
    cout<<"Chances Remaining: " << 10 - a << endl;
}

void film::hint(){
    system("cls");
    newintro();
    for(int j = 0;j < 4;j++){
        if(a[j] == '-'){
            a[j] = str[j];
            print();
        return;
        }
    }
}

void film::insertion(string a){
    int c = 0, d = 0;
    for(int j=0;j<4;j++){
        if(str[j]==a[j])
        {
            c++;
        }
        if(str[j]!=a[j]){
            for(int i=0;i<4;i++){
                if(str[j]==a[i])
                    d++;
            }
        }
    }
    gotoxy(20, 4);
    cout << c << " BULLS\n";
    gotoxy(20, 5);
    cout << d << " COWS\n";
    gotoxy(20, 7);
    cout << "Please wait for 1 second";
    Sleep(1000);
}

bool film::isEqual(string word){
    for(int i=0;i<4;i++){
        if(word[i]!=str[i]){
            return 0;
        }
    }
    return 1;
}

bool film::isEquals(){
for(int i=0;i<4;i++){
    if(a[i]!=str[i]){
        return 0;
    }
}
return 1;
}

void film::gameplay(){
    int k=0,l=0;
    string word;
    while(k!=10){
        aalu = 2;
        chance(k);
        word = getword();
        if (word == "0")
            return;
        if(word=="."){
            if(l < 3){
                hint();
                if(isEquals()){
                    gotoxy(32, 16);
                    cout<<"Word is: "<<str;
                    gotoxy(32, 18);
                    cout<<"Congratulations!!! You won the game"<<endl;
                    PlaySound(TEXT("SMALL_CROWD_APPLAUSE-Yannick_Lemieux-1268806408.wav"),NULL,SND_SYNC);
                    return;
                    //exit(0);
                }
                l++;
                k++;
            }
            else{
                gotoxy(32, 19);
                cout<<"No more hints available"<<endl;
            }
        }
        else{
            insertion(word);
            Sleep(1000);
            system("CLS");
            newintro();
            if(isEqual(word)){
                gotoxy(32, 16);
                cout<<"Word is: "<<str;
                gotoxy(32, 18);
                cout<<"Congratulations!!! You won the game"<<endl;
                PlaySound(TEXT("SMALL_CROWD_APPLAUSE-Yannick_Lemieux-1268806408.wav"),NULL,SND_SYNC);
                return;
                //exit(0);
            }
            k++;
        }
    }
    system("CLS");
    newintro();
    gotoxy(38, 13);
    cout<<"You have exhausted your 10 moves"<<endl;
    PlaySound(TEXT("SAD - SOUND EFFECT.wav"),NULL,SND_SYNC);
    gotoxy(38, 15);
    cout<<"Game over"<<endl;
    gotoxy(38, 17);
    cout<<"Word is "<<str<<endl;

}
film::film(string a): aalu(1), BLUE(1), GREEN(2), RED(4), WHITE(15), ORANGE(6){
    intro();
    film start;
    start.gameplay();
}
