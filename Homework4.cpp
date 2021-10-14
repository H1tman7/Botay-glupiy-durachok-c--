#include "header4.hpp"

int num_task;
int end() {
    cout << "Enter number of task (if you want to exit the programm, enter 0): ";
    cin >> num_task;
    return num_task;
}

int main() {
    cout << "Homework 4" << endl;

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

        case 5:
            Number5();
            break;

        default:
            cout << "Probably you entered an incorrect number. Try again!" << endl;
            break;
        }
    }
    return 0;
}