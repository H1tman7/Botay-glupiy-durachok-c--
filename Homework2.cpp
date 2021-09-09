#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

/*
int main(){
    cout << "Homework 2" << endl;
    cout << "Number 1" << endl;

    float h, R, r, l;

    cout << "Enter Heigh: ";
    cin >> h;
    cout << "Enter Radius #1: ";
    cin >> R;
    cout << "Enter radius #2: ";
    cin >> r;
    cout << "Enter wall length: ";
    cin >> l;

    cout << "Volume = " << (1.0 / 3.0) * (M_PI * h * (R * R + R * r + r * r)) << endl;
    cout << "Square = " << M_PI *(R * R + l * (R + r) + r * r) << endl;
    return 0;
}

*/

int main(){
    cout << "Number 2" << endl;
    float x,a;
    
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter a: ";
    cin >> a;

    if (abs(x) < 1){
        if (abs(x) > 0){
            cout << a * log(abs(x));
        }
        

    }



    return 0;
}