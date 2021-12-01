#include "header4.hpp"
#include <algorithm>

int num_task;
int end() {
    cout << "Enter number of task (if you want to exit the programm, enter 0): ";
    cin >> num_task;
    return num_task;
}

void Number1(){
    unsigned long long a, b, c;
    int ans = 0;
    cin >> a >> b >> c;

    c -= a;
    while (c > b){
        c -= b;
        ans++;
    }
    cout << ans << endl;

    return;
}

void Number2(){
    unsigned long long m;
    cout << "Enter M: ";
    cin >> m;

    if ((m - 4 * (m % 3)) / 3 >= 0 && m != 1 && m != 2 && m != 5)
        cout << (m - 4 * (m % 3)) / 3 << endl << m % 3 << endl;
    else
        cout << 0 << endl << 0 << endl;

    return;
}

void Number3(){

    uint64_t n, m;
    cout << "n: ";
    cin >> n;
    cout << "m: ";
    cin >> m;

    cout << ((n + 1) * (m + 1) * (n * m)) / 4 << endl;

    return;
}

void Number4(){
    int n, k, i = 0, ans = 0, max = 0;
    cout << "enter N: ";
    cin >> n;
    int place[54 + 1] = { '\0' };
    int del4[9] = { '\0' };

    while (n > 0){
        cin >> k;
        place[k] = 1;
        if (k % 4 == 0 && k < 37){
            del4[i] = k;
            i++;
        }
        n--;
    }

    sort(&del4[0], &del4[9]);
    i = 8;
    int prev = 100;

    while(del4[i] != 0){
        if (place[del4[i]] && place[del4[i] - 1] && place[del4[i] - 2] && place[del4[i] - 3]) {
            if(place[54 - 2 * (del4[i] / 4 - 1)] && place[53 - 2 * (del4[i] / 4 - 1)]){
                if(prev == 100){
                    ans = 1;
                    max = 1;
                }
                else if(abs(del4[i] - prev) == 4){
                    ans += 1;
                    if (ans > max)
                        max = ans;
                }
                else
                    ans = 1;
            }
        }
        prev = del4[i];
        i--;
    }

    cout << "ans = " << max << endl;

    return;
}

void Number5(){
    int N, K;
    cin >> N >> K;

    while (K != 1){
        N = (N - K % 2) / 2;
        K /= 2;
    }
    cout << (N - 1) / 2 << endl << N / 2 << endl;

    return;
}

int main(){
    cout << "Spinners" << endl;
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