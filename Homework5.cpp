#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <stdbool.h>
#include <iomanip>
#include <cstdlib>

using namespace std;

int num_task;
int end() {
    cout << "Enter number of task (if you want to exit the programm, enter 0): ";
    cin >> num_task;
    return num_task;
}

int prime(int x) {
    for (int i = sqrt(x); i > 1; i--){
        if (!(x % i))
            return 0;
    }
    return 1;
}

int nod(unsigned long long a, unsigned long long b){
    if (a == b) {
        return b;
    }
    else{
        if (a > b) {
            return nod(a-b,b);
            }
        else{
            return nod(a,b-a);
        }
    }
}

void Number1_1(unsigned long long a, unsigned long long b){
    cout << "Division method" << endl;

    while (a != 0 && b != 0){
            if (a > b){
                a = a % b;
            }
            else{
                b = b % a;
            }
        }
        cout << "Answer: " << a + b << endl;
    return;
}

void Number1_2(unsigned long long a, unsigned long long b){
    cout << "Subtraction method" << endl;

    while (a != b){
        if (a > b){
            a = a - b;
        }
        else{
            b = b - a;
        }
    }
    cout << "Answer: " << a << endl;
    return;
}

void Number1_3(unsigned long long a, unsigned long long b){
    cout << "Recursion method" << endl;

    cout << "Answer: " << nod(a,b) << endl;    
    return;
}

void Number1(){
    cout << "Number 1 <Euclidean algorithm>" << endl;

    unsigned int num;
    long long a,b,temp;
    
    cout << "Enter number of realization of Euclidean algorithm:\n1 - Division Method\n2 - Subtraction\n3 - Recursion\n";
    cin >> num;

    cout << "Enter the first number: ";
    cin >> a;
    a = abs(a);
    cout << "Enter the second number: ";
    cin >> b;
    b = abs(b);


    switch (num){
        case 1:
            Number1_1(a,b);
            break;
        case 2:
            Number1_2(a,b);
            break;
        case 3:
            Number1_3(a,b);
            break;
        default:
            cout << "Probably you entered the wrong number" << endl;
    }

    return;
}

void Number2(){
    cout << "Number 2" << endl;
    unsigned long long n;

    cout << "Enter your Number: ";
    cin >> n;

    int count = 0; //count of prime numbers less than N

    int razm = ceil(sqrt(n));
    if (razm % 2 == 0){
        razm += 1;
    }

    cout << "Sieve of Eratosthenes" << endl;
    int *a = new int[n + 1];    
    for (int i = 0; i < n + 1; i++)
        a[i] = i;
    for (int p = 2; p < n + 1; p++){
        if (a[p] != 0){
            cout << a[p] << endl;
            count += 1;
            for (int j = p*p; j < n + 1; j += p){
                a[j] = 0;
            }
        }
    }
    cout << "Count of Prime Numbers = " << count << endl;


    cout << "\nUlam's spiral" << endl;
    cout << "Check file 'Ulam.txt'" << endl;

////////////////////////////////////  
    //Initialize an array
    int **matr = new int* [razm];

    for(int i = 0; i < razm; i++){
        matr[i] = new int[razm];
    }
////////////////////////////////////

    int iter;
    int num = razm*razm;
    int x = razm - 1, y = razm - 1; 

////////////////////////////////////
    //To Fill the matrix
    for (int i = 0; i < razm; i++){
        for (int j = 0; j < razm; j++){
            matr[i][j] = 1;
        }
    }
////////////////////////////////////

    for(int i = 0; i < razm; i++){

        //left
        while (y > i){
            matr[x][y] = num;
            num--;
            y--;
        }

        //up
        while(x > i){
            matr[x][y] = num;
            num--;
            x--;
        }

        //right
        while (y < razm - i - 1){
            matr[x][y] = num;
            num--;
            y++;
        }

        //down        
        i+=1;
        while (x < razm - i - 1){
            matr[x][y] = num;
            num--;
            x++;
        }
        i-=1;

    }

////////////////////////////////////
    //Printing finished matrix

    ofstream fout("Ulam.txt");
    int k;
    if (n >= 1000)
        k = 4;
    else if (n >= 10000)
        k = 5;
    else
        k = 3;

    for(int i = 0; i < razm; i++){
        for (int j = 0; j < razm; j++){
            if (prime(matr[i][j]) && matr[i][j] <= n && matr[i][j] != 1){
                fout << setw(k) << right << matr[i][j] << " ";
            }
            else{
                fout << setw(k+1) << right << "";
            }
        }
        fout << endl;
    }
////////////////////////////////////


////////////////////////////////////
// Delete this array from memmory
    for(int i = 0; i < razm; i++){
        delete [] matr[i];
    }

    delete[] matr;
///////////////////////////////////

    return;
}

void Number3(){
    cout << "Text files.Number 26." << endl;

    FILE* f = fopen("Files.Number26.txt", "r");

    fseek(f, 0, SEEK_END);
    int count = 0;
    unsigned long long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    char* data = (char*) malloc(size);
    char buf[size];
    fread(buf, 1, size, f);
    fclose(f);

    for(int i = 0; i < size; i++){
        if (buf[i] == '\n')
            count++;
    }

    char from,into;
    cout << "What is the cymbol you want to replace? ";
    cin >> from;
    cout << "What is the cymbol you want to replace it with? ";
    cin >> into;

    FILE* out = fopen("Files.Number26.txt", "w");

    for(int i = 0; i < size - count; i++){
        if (buf[i] == from)
            fputc(into, out);    
        else
            fputc(buf[i], out);
    }

    fclose(out);
    return;
}


int main() {
    cout << "Homework 5" << endl;

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

        // case 4:
        //     Number4();
        //     break;

        // case 5:
        //     Number5();
        //     break;

        default:
            cout << "Probably you entered an incorrect number. Try again!" << endl;
            break;
        }
    }
    return 0;
}