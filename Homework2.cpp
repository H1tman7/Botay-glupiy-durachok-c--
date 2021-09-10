#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int num_task;

int end() {
    cout << "Enter number of task (if you want to exit the programm, enter 0): ";
    cin >> num_task;
    return num_task;
}

void Number1() { 
    cout << "Number 1" << endl;

    float h, R, r;

    cout << "Enter Heigh: ";
    cin >> h;
    cout << "Enter Radius #1: ";
    cin >> R;
    cout << "Enter radius #2: ";
    cin >> r;

    if (r <= 0 || R <= 0 || h <= 0) {
        cout << "It is not a frustum!" << endl;
    }else{
        float l = sqrt((R - r) * (R - r) + h * h);
        cout << "Volume = " << (1.0 / 3.0) * (M_PI * h * (R * R + R * r + r * r)) << endl; 
        cout << "Square = " << M_PI *(R * R + l * (R + r) + r * r) << endl;
    }

    end();
    return; 
    }

void Number2() {
    cout << "Number 2" << endl;

    float x, a;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter a: ";
    cin >> a;

    if (abs(x) < 1) {
        cout << a << " * log(e) |" << x << "|" << endl << "Answer: ";
        if (x != 0) {
            if (a * log(abs(x)) == -0)
                cout << 0 << endl;
            else
                cout << a * log(abs(x)) << endl;
        } else
            cout << "Error" << endl;
    }

    else {
        cout << "sqrt(" << a << " - " << x << "^2)" << endl << "Answer: ";
        if ((a - x * x) >= 0)
            cout << sqrt((a - x * x)) << endl;
        else
            cout << "Error" << endl;
    }
    end();
    return;
}

void Number3() {
    cout << "Number 3" << endl;

    float x, y, b;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    cout << "Enter b: ";
    cin >> b;

    cout << "log(e)(" << b << " - " << y << ") * sqrt(" << b << " - " << x
         << ")" << endl
         << "Answer: ";

    if (b - y <= 0 || b - x < 0)
        cout << "Error" << endl;
    else
        cout << "z = " << (log(b - y) * sqrt(b - x) == -0 ? 0 : log(b - y) * sqrt(b - x)) << endl;
    end();
    return;
}

void Number4() {
    cout << "Number 4" << endl;

    long long N,B;
    float M,S;

    cout << "Enter start number: ";
    cin >> M;

    cout << "Enter count of numbers: ";
    cin >> N;

    cout << "Up:1 Down:-1:   ";
    cin >> B;

    cout << "Enter Step: ";
    cin >> S;

    if (B == 1){
        while(N != 0){
        cout << M << "; ";
        M+=S;
        N-=1;
        }
        cout << "\n";
    }else if (B == -1){
        while (N != 0){
            cout << M << "; ";
            M-=S;
            N-=1;
        }
        cout << "\n";
    }

    end();
    return;
}

void Number5(){

    float x = -4;

    cout << "Number 5" << endl;

    cout << setw(5) << "x" << setw(5) << "|" << setw(6) << "y" << endl;

    for (float x =-4; x <= 4; x += 0.5){
        cout << setw(17) << setfill('-') << "" << endl;
        cout << setfill(' ') << setw(5) << x << setw(5) << "|" << setprecision(3) << setw(7) << (x * x - 2 * x  + 2)/(x - 1) << endl;
    }
    cout << setw(17) << setfill('-') << "" << endl;
    end();
    return;
}


int main() {
    cout << "Homework 2" << endl;
    end();

    while (true) {
        switch (num_task) {
            case 0:
                cout << "Ok, programm is finished.";
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

            case 5:
                Number5();
                break;

            default:
                cout << "Probably you entered an incorrect number. Try again!"
                     << endl;
                end();
                break;
        }
    }

    return 0;
}