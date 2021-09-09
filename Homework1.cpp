#include <cmath>
#include <iostream>

using namespace std;

template <typename T>
bool parseNum(T* num) {
    cin >> *num;
    if (getchar() != '\n') {
        return false;
    }
    return true;
}

int num_task;

int end() {
    cout << "Enter number of task (if you want to exit the programm, enter 0): ";
    cin >> num_task;
    return num_task;
}

void Number1() {
    
    cout << "Number 1\n";
    cout << "Mikhail\n";
    end();
    return;
}

void Number2() {

    cout << "Number 2\n";
    float a, b;
    cout << "Enter A: ";
    cin >> a;
    cout << "Enter B: ";
    cin >> b;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    if (b == 0)
        cout << "You can't devide " << a << " into " << b << endl;
    else
        cout << "a / b = " << a / b << endl;
    end();
    return;
}

void Number3() {

    cout << "Number 3" << endl;
    float b, c;

    cout << "Enter B: ";
    if (!parseNum(&b)){
        cout << "Input error!" << endl;
        end();
        return;
    }

    cout << "Enter C: ";
    if (!parseNum(&c)){
        cout << "Input error!" << endl;
        end();
        return;
    }

    cout << b << "x + " << c << " = 0" << endl;
    cout << "Answer: ";
    if (b == 0 && c == 0){
        cout << "Infinity" << endl;
    }
    else if (b == 0){
        cout << "No roots" << endl;
    }
    else{
        cout << -c / b << endl;
    }
    end();
}

void Number4() {

    cout << "Number 4" << endl;
    float a, b, c;
    cout << "Enter A: ";
    if (!parseNum(&a)) {
        cout << "Input error!" << endl;
        end();
        return;
    }

    cout << "Enter B: ";
    if (!parseNum(&b)) {
        cout << "Input error!" << endl;
        end();
        return;
    }

    cout << "Enter C: ";
    if (!parseNum(&c)) {
        cout << "Input error!" << endl;
        end();
        return;
    }

    cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
    cout << "Answer:" << endl;

    if (a == 0.0) {
        if (b == 0) {
            cout << "No roots" << endl;
        } else if (c != 0) {
            cout << "x = " << -b / c << endl;
        } else {
            cout << "x = " << 0.0 << endl;
        }
        end();
        return;
    }

    float D = b * b - 4 * a * c;
    if (D < 0.0) {
        cout << "No roots" << endl;
    } else if (D == 0.0) {
        cout << "x = " << -b / (2 * a);
    } else {
        float ans1 = ((-b) + sqrt(D)) / (2 * a);
        float ans2 = ((-b) - sqrt(D)) / (2 * a);
        ans1 = ans1 == -0.0 ? 0.0 : ans1;
        ans2 = ans2 == -0.0 ? 0.0 : ans2;
        cout << "x1 = " << ans1 << endl;
        cout << "x2 = " << ans2 << endl;
    }
    end();
    return;
}

void Number5(){

    cout << "Number 5" << endl;
    int a;
    bool IsDay = false, IsLampTurnedOn = false, IsCurOpen = false;
    cout << "Enter 1 or 0" << endl;
    cout << "Is it a Day?" << endl;
    cin >> IsDay;
    cout << "Are the curtains open?" << endl;
    cin >> IsCurOpen;
    cout << "Is the lamp turned on?" << endl;
    cin >> IsLampTurnedOn;
    if ((IsDay && IsCurOpen) || IsLampTurnedOn) {
        cout << "It's lightly in the room" << endl;
    } else {
        cout << "It's dark" << endl;
    }
    end();

}


int main() {
    cout << "Homework 1\n";
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
                cout << "Probably, you entered an incorrect cymbols... Try again" << endl;
                end();
                break;

        } 
    }
    return 0;
}