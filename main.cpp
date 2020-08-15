#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <dirent.h>
#include <windows.h>
#include <mmsystem.h>
#include <pthread.h>

#include "cowsandbulls.h"
#include "bollywood.h"
#include "acct.h"
#include "calc.h"
#include "calendar.h"
#include "tiktaktoe original.cpp"

const int BLUE = 1;
const int GREEN = 2;
const int RED = 4;
const int WHITE = 15;
const int ORANGE = 6;

using namespace std;

int signin();
void gotoxy(short x, short y);
void intro();
void intro1();
void input();
void input_case1();
void input_case2();
void input_case3();
void input_default();
void showBlinkingLights(string temp, int t);
void changeColour(int colour);
void gotoxy(short x, short y);
void music();
void MainMenu();
void thread();

void gotoxy(short x, short y){
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void input_default()
{
    intro1();
    gotoxy(30, 13);
    cout << "You have entered a wrong input...\n";
    Sleep(1000);
    for(int i = 0; i < 5; i++){
        gotoxy(30, 14);
        cout << "Redirecting to main menu in " << 5 - i << " seconds";
        Sleep(1000);
        changeColour(BLUE);
    }
    changeColour(WHITE);
    MainMenu();
}

void input_case3()
{
    intro1();
    gotoxy(45, 13);
    cout << "Shutting Down";
    Sleep(500);
    for(int i = 0; i < 3; i++){
        gotoxy(49, 14);
        changeColour(RED);
        cout << "__";Sleep(500);
        gotoxy(51, 15);
        changeColour(ORANGE);
        cout << "\\";
        gotoxy(51, 16);
        cout << "/";Sleep(500);
        gotoxy(49, 16);
        changeColour(RED);
        cout << "__";Sleep(500);
        gotoxy(48, 16);
        changeColour(ORANGE);
        cout << "\\";
        gotoxy(48, 15);
        cout << "/";Sleep(500);
    }
    gotoxy(45, 17);
    changeColour(WHITE);
    exit(0);
}

void input_case2()
{
    intro1();
    gotoxy(20, 13);
    int s_t;
    cout << "For how many seconds you want to make your computer sleep --> ";
    cin >> s_t;
    Sleep(s_t * 1000);
    MainMenu();
}

void input_case1()
{
    intro1();
    gotoxy(35, 13);
    cout << "Feature coming soon ^_^";
    Sleep(3000);
    MainMenu();
}

void dirtrav() {
    struct dirent *dp;
    DIR *dir = opendir(".");
    if (dir == NULL) {
        printf("Could not open the directory!!");
        return;
    }
    printf ("Contents of the current directory: \n");
    int i = 1;
    while ((dp = readdir(dir)) != NULL) {
        printf("%d.\t%s\n", i, dp->d_name);
        i++;
    }
    char name[50];
    while(1) {
        i = 1;
        printf ("\nPress '..' to move back a directory");
        printf ("\nPress '\\' to move to root directory");
        printf ("\nType '0' to return to main menu");
        printf("\nOR Enter the name of the folder from the current directory you want to open: \n");
        gets(name);
        if (strcmp(name, "0") == 0)
            return;
        system("CLS");
        dir  = opendir(name);
        if (dir == NULL) {
            printf("Could not open the directory %s!!", name);
            //return 0;
        }
        printf ("Contents of the current directory: \n");
        while ((dp = readdir(dir)) != NULL) {
           printf("%d.\t%s\n", i, dp->d_name);
           i++;
        }
    }
    closedir(dir);
}


void input()
{
    changeColour(WHITE);
    switch (getch()){
        case '7':{
            // bollywood
            PlaySound(NULL, NULL, 0);
            system("CLS");
            bollywood s("begin");
            MainMenu();
            break;
        }
        case '8':{
            // cows and bulls
            PlaySound(NULL, NULL, 0);
            system("CLS");
            film w("begin");
            MainMenu();
            break;
        }
        case '9':{
            //calendar
            PlaySound(NULL, NULL, 0);
            system("cls");
            calendar ob;
            getch();
            MainMenu();
            break;
        }
        case '4':{
            //calculator
            PlaySound(NULL, NULL, 0);
            system("CLS");
            string temp;
            getline(cin, temp);
            calc c;
            MainMenu();
            break;
        }
        case '5':{
            // directory traverser
            PlaySound(NULL, NULL, 0);
            system("CLS");
            dirtrav();
            MainMenu();
            break;
        }
        case '6':{
            // Tic tac toe.cpp
            changeColour(ORANGE);
            PlaySound(NULL, NULL, 0);
            system("CLS");
            tiktaktoe();
            changeColour(WHITE);
            MainMenu();
            break;
        }
        case '1':{
            PlaySound(NULL, NULL, 0);
            input_case1();
            break;
        }
        case '2':{
            PlaySound(NULL, NULL, 0);
            input_case2();
            break;
        }
        case '3':{
            input_case3();
            break;
        }
        default:{
            PlaySound(NULL, NULL, 0);
            input_default();
            break;
        }
    }
}


//colors required:->
/*    0 = Black       8 = Gray
    1 = Blue        9 = Light Blue
    2 = Green       A = Light Green
    3 = Aqua        B = Light Aqua
    4 = Red         C = Light Red
    5 = Purple      D = Light Purple
    6 = Yellow      E = Light Yellow
    7 = White       F = Bright White*/

void changeColour(int colournumber) {
	HANDLE h;

	h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, colournumber);
}

void showBlinkingLights(string temp, int t) {
	changeColour(6);
	cout << temp;
	Sleep(2000);

	changeColour(7);
	cout << temp;
	Sleep(2000);

	changeColour(2);
	cout << temp;
}

void intro(){
    changeColour(6);
    system("CLS");
    gotoxy(0, 0);
    cout << "\t __________________________________________________________________________________________\n";
    cout << "\t|                                       MAIN MENU                                          |\n";
    cout << "\t| ________________________________________________________________________________________ |\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||              ___________            ____________            ____________               ||\n";
    cout << "\t||             |           |          |  \\ ___ /   |          | __________ |              ||\n";
    cout << "\t||             | _ _ _ _ _ |          |  (\\o o/)   |          ||__|__|__|_||              ||\n";
    cout << "\t||             ||_|_|_|_|_||          |  |  ^  |   |          ||__|__|__|_||              ||\n";
    cout << "\t||             |           |          |  (_---_)   |          ||__|__|__|_||              ||\n";
    cout << "\t||             | BOLLYWOOD |          |COWS & BULLS|          |  CALENDAR  |              ||\n";
    cout << "\t||             |___________|          |____________|          |____________|              ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||              ____________            ___________            ____________               ||\n";
    cout << "\t||             |   ______   |          |   _       |          |  __|__|__  |              ||\n";
    cout << "\t||             |  | + | *|  |          |  / \\-___  |          |  __|__|__  |              ||\n";
    cout << "\t||             |  | / | -|  |          | |       | |          |    |  |    |              ||\n";
    cout << "\t||             |  |______|  |          | |_______| |          |            |              ||\n";
    cout << "\t||             | CALCULATOR |          | DIRECTORY |          |TIC-TAC-TOE |              ||\n";
    cout << "\t||             |____________|          |___________|          |____________|              ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||              ___________            ___________            ___________                 ||\n";
    cout << "\t||             | \\      /  |          |     |     |          |     |     |                ||\n";
    cout << "\t||             |  \\    /   |          |    /|\\    |          |    /|\\    |                ||\n";
    cout << "\t||             |   \\  /    |          |   / | \\   |          |   / | \\   |                ||\n";
    cout << "\t||             |    \\/     |          |   \\___/   |          |   \\___/   |                ||\n";
    cout << "\t||             |COMING SOON|          |   SLEEP   |          |  POWEROFF |                ||\n";
    cout << "\t||             |___________|          |___________|          |___________|                ||\n";
    cout << "\t||________________________________________________________________________________________||\n";
    cout << "\t|__________________________________________________________________________________________|\n";
    gotoxy(95, 28);
    input();
}

void intro1()
{
    system("CLS");
    cout << "\t __________________________________________________________________________________________\n";
    cout << "\t|                                       MAIN MENU                                          |\n";
    cout << "\t| ________________________________________________________________________________________ |\n";
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

void *music(void * arg){
    PlaySound(TEXT("music.wav"),NULL,SND_LOOP|SND_ASYNC);
}

static void *menu(void * arg)
{
    changeColour(6);
    system("CLS");
    gotoxy(0, 0);
    cout << "\t __________________________________________________________________________________________\n";
    cout << "\t|                                       MAIN MENU                                          |\n";
    cout << "\t| ________________________________________________________________________________________ |\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||              ___________            ____________            ____________               ||\n";
    cout << "\t||             |           |          |  \\ ___ /   |          | __________ |              ||\n";
    cout << "\t||             | _ _ _ _ _ |          |  (\\o o/)   |          ||__|__|__|_||              ||\n";
    cout << "\t||             ||_|_|_|_|_||          |  |  ^  |   |          ||__|__|__|_||              ||\n";
    cout << "\t||             |           |          |  (_---_)   |          ||__|__|__|_||              ||\n";
    cout << "\t||             | BOLLYWOOD |          |COWS & BULLS|          |  CALENDAR  |              ||\n";
    cout << "\t||             |___________|          |____________|          |____________|              ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||              ____________            ___________            ____________               ||\n";
    cout << "\t||             |   ______   |          |   _       |          |  __|__|__  |              ||\n";
    cout << "\t||             |  | + | *|  |          |  / \\-___  |          |  __|__|__  |              ||\n";
    cout << "\t||             |  | / | -|  |          | |       | |          |    |  |    |              ||\n";
    cout << "\t||             |  |______|  |          | |_______| |          |            |              ||\n";
    cout << "\t||             | CALCULATOR |          | DIRECTORY |          |TIC-TAC-TOE |              ||\n";
    cout << "\t||             |____________|          |___________|          |____________|              ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||              ___________            ___________            ___________                 ||\n";
    cout << "\t||             | \\      /  |          |     |     |          |     |     |                ||\n";
    cout << "\t||             |  \\    /   |          |    /|\\    |          |    /|\\    |                ||\n";
    cout << "\t||             |   \\  /    |          |   / | \\   |          |   / | \\   |                ||\n";
    cout << "\t||             |    \\/     |          |   \\___/   |          |   \\___/   |                ||\n";
    cout << "\t||             |COMING SOON|          |   SLEEP   |          |  POWEROFF |                ||\n";
    cout << "\t||             |___________|          |___________|          |___________|                ||\n";
    cout << "\t||________________________________________________________________________________________||\n";
    cout << "\t|__________________________________________________________________________________________|\n";
    gotoxy(95, 28);
    changeColour(WHITE);
    input();
}

static void *introstart(void * arg)
{
    system("COLOR 09");
    cout << "\t\t                           ____         ____   ____            ____              \n";
    cout << "\t\t            \\          /  |      |     |      |    |  |\\  /|  |                  \n";
    cout << "\t\t             \\        /   |__    |     |      |    |  | \\/ |  |__                \n";
    cout << "\t\t              \\  /\\  /    |      |     |      |    |  |    |  |                  \n";
    cout << "\t\t               \\/  \\/     |____  |____ |____  |____|  |    |  |____              \n";
    cout <<endl<<endl<< "\t\t              --------------------------------------------------------           \n";
    gotoxy(30, 7);
    Sleep(1500);
    showBlinkingLights("ENTERING PROJECT...", 2);
    Sleep(4000);
    gotoxy(1,30);
    cout<<endl<<"\t\t\t\t\t\t    ";
    changeColour(4);
    cout<<"-:CREDITS:-"<<endl;
    Sleep(1800);
    changeColour(1);
    cout<<endl<<"\t\t\t\t\t           ";
    cout<<"SPARSH GUPTA"<<endl;
    Sleep(1900);
    changeColour(2);
    cout<<endl<<"\t\t\t\t\t          ";
    cout<<"CHINMAYA PARAKH"<<endl;
    Sleep(3700);
    changeColour(6);
    cout<<endl<<"\t\t\t\t\t          ";
    cout<<"KARTIK DHOLAKIA"<<endl;
    for(int i=0;i<15;i++)
    {
        Sleep(500);
        cout<<endl<<" ";
    }
    Sleep(3000);
    intro();
}

void thread()
{
    pthread_t th1, th2;
    pthread_create(&th1, 0, &introstart, 0);
    pthread_create(&th2, 0, &music, 0);
    pthread_join(th1, 0);
    pthread_join(th2, 0);
}

void MainMenu()
{
    pthread_t th1, th2;
    pthread_create(&th1, 0, &menu, 0);
    pthread_create(&th2, 0, &music, 0);
    pthread_join(th1, 0);
    pthread_join(th2, 0);
}


int signin() {
    changeColour(ORANGE);
    system("CLS");
    cout << "\t __________________________________________________________________________________________\n";
    cout << "\t|                                     LOGIN / SIGNUP                                       |\n";
    cout << "\t| ________________________________________________________________________________________ |\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||              ____________________________________________________________              ||\n";
    cout << "\t||                                       WELCOME                                          ||\n";
    cout << "\t||              ____________________________________________________________              ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                    1 --> SIGNUP                                                        ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                    2 --> LOGIN                                                         ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||              ____________________________________________________________              ||\n";
    cout << "\t||                                                                                        ||\n";
    cout << "\t||                             ENTER YOUR CHOICE -->                                      ||\n";
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
    cout << "\t||________________________________________________________________________________________||\n";
    cout << "\t|__________________________________________________________________________________________|\n";
    acct obj;
    char c;
    gotoxy(61, 16);
    cin >> c;
    if (c == '1') {
        return obj.signup();
    }
    else if (c == '2')
        return obj.login();
    else {
        gotoxy(40, 19);
        cout << "Wrong choice entered!!";
        gotoxy(35, 20);
        cout << "Redirecting you to the main page again...";
        Sleep(2000);
        system("CLS");
        signin();
    }

}


int main() {
    if (signin() == 0) {
        system("CLS");
        gotoxy(35, 12);
        cout << "Either user not exists or credentials are wrong";
        gotoxy(35, 13);
        cout << "Redirecting you back onto the main page again...";
        Sleep(2000);
        main();
    }
    thread();
    return 0;
}
