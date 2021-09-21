#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <stdbool.h>
// #include <map>
// #include <functional>
// using dict_fun_t = map<int, function<void()>>;


using namespace std;

int num_task;

int end() {
    cout << "Enter number of task (if you want to exit the programm, enter 0): ";
    cin >> num_task;
    return num_task;
}

void Number1() {
    cout << "Number 1" << endl;

    float S, p, n;
    cout << "Enter percent: ";
    cin >> p;
    cout << "Enter sum: ";
    cin >> S;
    cout << "Enter count of ages: ";
    cin >> n;

    if (S <= 0 || n <= 0.003 || p < -100 || p > 100) {
        cout << "Error input!" << endl;
        return;
    }

    cout << "Monthly payment = " << (S * p / 100 * pow((1 + p / 100), n)) / (12 * (pow(1 + p / 100, n) - 1)) << endl;

    return;
}

void Number2() {
    cout << "Number 2" << endl;

    float S, m, n, monthly, ans = INFINITY, closest = 10e10;

    cout << "Enter sum: ";
    cin >> S;

    cout << "Enter count of ages: ";
    cin >> n;

    cout << "Enter monthly payment: ";
    cin >> m;

    if (S < 0 || n < 0.003 || m < 0) {
        cout << "Input Error!" << endl;
        end();
        return;
    }

    for (float p = -100; p <= 100; p += 0.01) {
        monthly = (S * (p / 100) * pow((1 + (p / 100)), n)) / (12 * (pow((1 + (p / 100)), n) - 1));
        if (abs(m - monthly) < closest) {
            closest = abs(m - monthly);
            ans = p;
        }
    }

    cout << "Answer = " << ans << " %" << endl;
    return;

}

void Number3() {
    cout << "Number 3" << endl;
    ofstream fout("The File.txt"); // Объект выходного потока

    fout << "Hello!";
    cout << "Enter something:" << endl;
    char str[255];

    while (fgets(str,255,stdin)) {
        fout << str;
    }

    cout << "Ok, I wrote down this information in the file. You can check this one!\n" << endl;
    fout.close();

    ifstream fin("The File.txt");
    cout << "This is what contains in this file:" << endl;
    cout << "-----------------------------------------------------" << endl;
    char ch;
    while (fin.get(ch)) {
        cout << ch;
    }
    cout << "-----------------------------------------------------" << endl;
    cout << "The end.\n" << endl;

    fin.close();

    return;
}

void Number4(){
    cout << "Number 4" << endl;

    ifstream fin("Task 4.txt");
    char c;
    bool flag = false, sp = false;

    while (fin.get(c)){
        if (c >= '0' && c <= '9'){
            cout << c;
            flag = true;
            sp = false;
        }
        if (c == '\n'){
            cout << endl;
            flag = false;
        }
        else if (!flag){
            if (!sp){
            cout << " ";
            sp = true;
            }
        }
        else{
            flag = false;
        }
    }
    printf("\n");
    return;
}

/*
void Number5(){
    cout << "Number 5" << endl;
    char string[30];

    cout << "Enter 30-letters string: " << endl;

    for(int i = 0; i < 30; i++){
        cin >> string[i];
    }

    for(int i = 0; i < 30; i++){
        cout << i+1 << "element = " << string[i] << endl;
    }

    std::sort();


    return;
}
*/


int main() {
    cout << "Homework 3" << endl;

    while (true) {
        end();
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

        case 3:
            Number3();
            break;

        case 4:
            Number4();
            break;
/*
        case 5:
            Number5();
            break;
*/
        default:
            cout << "Probably you entered an incorrect number. Try again!" << endl;
            break;
        }
    }
    return 0;
}


/*
5 task - русский алфавит. не использ. библиотеку. пузырек
        нельзя вектора.... можно - циклы массивы, if-ы
*/




/*
int main() {
    cout << "Homework 3" << endl;

    dict_fun_t dict = {
        { 1, Number1 },
        { 2, Number2 },
    };


    while (1) {
        char s[100];
        fgets(s, 100, stdin);
        if (s[0] == '0') {
            cout << "Ok, programm is finished." << endl;
            break;
        }

        int n = atoi(s);

        if (n && dict.count(n)) {
            dict[n]();
        } else {
            cout << "Probably you entered an incorrect number. Try again!" << endl;
        }
    }

    return 0;
}
*/