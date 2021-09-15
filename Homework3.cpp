#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;

int num_task;

int end() {
    cout << "Enter number of task (if you want to exit the programm, enter 0): ";
    cin >> num_task;
    return num_task;
}


void Number1(){
    cout << "Number 1" << endl;


    float S,r,p,n;
    cout << "Enter percent: ";
    cin >> p;
    cout << "Enter sum: ";
    cin >> S;
    cout << "Enter count of ages: ";
    cin >> n;

    if (S <= 0 || n <= 0.003 || p < -100 || p > 100){
        cout << "Error input!" << endl;
        end();
        return;
    }

    r = p / 100;
    cout << "m = " << ( S * r * pow((1 + r), n) ) / ( 12 * ( pow(1 + r, n) - 1) ) << endl;

    end();
    return;
}

void Number2(){
    cout << "Number 2" << endl;

    float S, r, m, n;

    cout << "Enter sum: ";
    cin >> S;

    cout << "Enter count of ages: ";
    cin >> n;

    cout << "Enter monthly payment: ";
    cin >> m;




    return;

}


int main() {
    cout << "Homework 3" << endl;
    end();

    while (true) {
        switch (num_task) {
            case 0:
                cout << "Ok, programm is finished." << endl;
                return 0;
                
            case 1:
                Number1();
                break;

            case 2:
                Number2();
                break;
/*
            case 3:
                Number3();
                break;

            case 4:
                Number4();
                break;

            case 5:
                Number5();
                break;
*/
            default:
                cout << "Probably you entered an incorrect number. Try again!" << endl;
                end();
                break;
        }
    }
    return 0;
}











/*

1 задача - дата минимум 0,003 гоба(1 день)


Ссуда - невозможно выразить процент; в цикле перебирать проценты -100 до 100; придумать способ быстрее(для плюса)
        как можно продасть свою верность за 40 евро - гуглим.

3 task - если создать файл из программы - убедиться, что можно добавить больше 1 строки( самый безопасный метод - просто открыть готовый файл)

4 task - тестовый файл. не выводим буквы(если буквы - ставим пробелы)

5 task - русский алфавит. не использ. библиотеку. пузырек
        нельзя вектора.... можно - циклы массивы, if-ы


конспект лекций
136страница. - работа с файлами

*/