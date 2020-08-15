#ifndef CALC_H
#define CALC_H


class calc {

    public:
        calc();
        void gotoxy(short x, short y);
        int precedence(char operatr);
        int applyOp(int a, int b, char operatr);
        int evaluate(std::string calc);
        //~calc();

};

#endif // CALC_H
