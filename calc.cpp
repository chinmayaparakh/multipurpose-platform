#include <stdio.h>
#include <string>
#include <conio.h>
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <windows.h>

#include "calc.h"

using namespace std;

void calc::gotoxy(short x, short y){
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int calc::precedence(char operatr){
    if(operatr == '+'||operatr == '-')
    return 1;
    if(operatr == '*'||operatr == '/')
    return 2;
    return 0;
}

int calc::applyOp(int a, int b, char operatr){
    switch(operatr){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

int calc::evaluate(string calc){
    stack <int> values;
    stack <char> operators;
    for(int i = 0; i < calc.length(); i++){
        if(calc[i] == ' ')
            continue;
        else if(calc[i] == '('){
            operators.push(calc[i]);
        }
        else if(isdigit(calc[i])){
            int val = 0;
            while(i < calc.length() && isdigit(calc[i])){ //For considering multiple digit numbers
                val = (val*10) + (calc[i]-'0');
                i++;
            }
            values.push(val);
        }
        else if(calc[i] == ')')
        {
            while(!operators.empty() && operators.top() != '(')
            {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(applyOp(val1, val2, op));
            }
            if(!operators.empty())
               operators.pop();
        }
        else
        {
            while(!operators.empty() && precedence(operators.top()) >= precedence(calc[i])){
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(applyOp(val1, val2, op));
            }
            operators.push(calc[i]);
        }
    }
    while(!operators.empty()){
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = operators.top();
        operators.pop();
        values.push(applyOp(val1, val2, op));
    }
    return values.top();
}

calc::calc() {
    cout << "\t\t\tWelcome to our advanced calculator\n\n";
    cout << "Our calculator uses stacks for calculation purposes, so it is the fastest\n\n";
    cout << "Given below is our calculator\n\n\n";
    cout << "\t\t\t_________________________________\n";
    cout << "\t\t\t|-------------------------------|\n";
    cout << "\t\t\t|                               |\n";
    cout << "\t\t\t| |---------------------------| |\n";
    cout << "\t\t\t| |                           | |\n";
    cout << "\t\t\t| |                           | |\n";
    cout << "\t\t\t| |---------------------------| |\n";
    cout << "\t\t\t|                               |\n";
    cout << "\t\t\t| |---|   |---|   |---|   |---| |\n";
    cout << "\t\t\t| | 7 |   | 8 |   | 9 |   | + | |\n";
    cout << "\t\t\t| |---|   |---|   |---|   |---| |\n";
    cout << "\t\t\t|                               |\n";
    cout << "\t\t\t| |---|   |---|   |---|   |---| |\n";
    cout << "\t\t\t| | 4 |   | 5 |   | 6 |   | - | |\n";
    cout << "\t\t\t| |---|   |---|   |---|   |---| |\n";
    cout << "\t\t\t|                               |\n";
    cout << "\t\t\t| |---|   |---|   |---|   |---| |\n";
    cout << "\t\t\t| | 1 |   | 2 |   | 3 |   | * | |\n";
    cout << "\t\t\t| |---|   |---|   |---|   |---| |\n";
    cout << "\t\t\t|                               |\n";
    cout << "\t\t\t| |---|   |---|   |---|   |---| |\n";
    cout << "\t\t\t| | 0 |   | . |   | = |   | / | |\n";
    cout << "\t\t\t| |---|   |---|   |---|   |---| |\n";
    cout << "\t\t\t|-------------------------------|\n";
    cout << "\t\t\t|_______________________________|\n";
    string temp;
    cout << "Just Press 0 to come out of our program\n";
    gotoxy(27, 12);
    getline(cin, temp);
    if (temp.compare("0") == 0){
        return;
    }
    int t = evaluate(temp);
    system("CLS");
    while (1){
        int l = 0, temp1 = t;
        while(temp1 != 0){
            temp1 /= 10;
            l++;
        }
        cout << "\t\t\t\t\t_________________________________\n";
        cout << "\t\t\t\t\t|-------------------------------|\n";
        cout << "\t\t\t\t\t|                               |\n";
        cout << "\t\t\t\t\t| |---------------------------| |\n";
        printf("\t\t\t\t\t| |%27d| |\n", t);
        cout << "\t\t\t\t\t| |                           | |\n";
        cout << "\t\t\t\t\t| |---------------------------| |\n";
        cout << "\t\t\t\t\t|                               |\n";
        cout << "\t\t\t\t\t| |---|   |---|   |---|   |---| |\n";
        cout << "\t\t\t\t\t| | 7 |   | 8 |   | 9 |   | + | |\n";
        cout << "\t\t\t\t\t| |---|   |---|   |---|   |---| |\n";
        cout << "\t\t\t\t\t|                               |\n";
        cout << "\t\t\t\t\t| |---|   |---|   |---|   |---| |\n";
        cout << "\t\t\t\t\t| | 4 |   | 5 |   | 6 |   | - | |\n";
        cout << "\t\t\t\t\t| |---|   |---|   |---|   |---| |\n";
        cout << "\t\t\t\t\t|                               |\n";
        cout << "\t\t\t\t\t| |---|   |---|   |---|   |---| |\n";
        cout << "\t\t\t\t\t| | 1 |   | 2 |   | 3 |   | * | |\n";
        cout << "\t\t\t\t\t| |---|   |---|   |---|   |---| |\n";
        cout << "\t\t\t\t\t|                               |\n";
        cout << "\t\t\t\t\t| |---|   |---|   |---|   |---| |\n";
        cout << "\t\t\t\t\t| | 0 |   | . |   | = |   | / | |\n";
        cout << "\t\t\t\t\t| |---|   |---|   |---|   |---| |\n";
        cout << "\t\t\t\t\t|-------------------------------|\n";
        cout << "\t\t\t\t\t|_______________________________|\n";
        gotoxy(44, 5);
        getline(cin, temp);
        if (temp.compare("0") == 0){
            break;
        }
        t = evaluate(temp);
        system("CLS");
    }
}
