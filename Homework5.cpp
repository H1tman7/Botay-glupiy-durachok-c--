#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <stdbool.h>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <string.h>
#include <set>
#include <map>
#include <iterator>
#include <stdlib.h>

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
    cout << "Text files.Number 26" << endl;

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

void Number4(){
    cout << "Text files.Number 14" << endl;

    FILE* out = fopen("Files.Number14.txt", "a");
    char c;
    while((c = getchar()) != EOF){
        fputc(c, out);    
    }

    fclose(out);
    return;
}

void Number5(){
    cout << "Rows.Number26(The third word)" << endl; 
    string s;
    cout << "Enter string: ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, s);
    int n = s.length(), PoS = 0, count = 0;
    bool fl = false;
    
    if (s[n] != ' ')
        count++;
    for(int i = 0; i < 3; i++){
        while(s[PoS] == ' '){
            PoS++;
        }

        while(s[PoS] != ' '){
            if(PoS < n)
                PoS++;
            else
                break;
        }
        if(s[PoS] == ' ')
            count++;
    }

    if(count < 3){
        cout << "Input Error!" << endl;
    }
    else{
        if (s[PoS] == ' '){
            PoS--;
            fl = true;   
        }

        int i = -1;
        char ToReverse[n-4] = { '\0' };
        while(s[PoS] != ' '){
            if(fl){
                ToReverse[++i] = s[PoS];
                PoS--;    
            }
            else
                ToReverse[++i] = s[--PoS];
        }

        for(int b = 0; b <= i; b++){
            cout << ToReverse[b];
        }
        cout << endl;
    }
    return;
}

void Number6(){
    cout << "Rows.Number42(the same numbers)" << endl;
            
    set <int> first;
    set <int> final;
    map <int, int> slovarik;
    bool flag = false;
    int nums[10000] = { '\0' }, i = 0;
    
    cout << "Enter your numbers" << endl;
    cout << "0) ";
    while (cin >> nums[i++]){
        cout << i << ") ";
    }
    --i;

    for(int j = 0; j < i; j++){
        first.insert(nums[j]);
    }

    for(int j = 0; j < i; j++){
        ++slovarik[nums[j]];
    }
    cout << endl;

    map <int, int> :: iterator sl_it = slovarik.begin();
    for(int k = 0; sl_it != slovarik.end(); sl_it++, k++){
        if(sl_it->second > 1){
            cout << "count of '" << sl_it->first << "' = " << sl_it->second << ". Their indexes: ";
            flag = true;
            final.insert(sl_it->first);
            for(int a = 0; a < i; a++){
                if(sl_it->first == nums[a]){
                    cout << a << " ";
                }
            }
            cout << endl;
        }
    }
    if(flag){
        cout << "sorted array: " << endl;
        copy(final.begin(), final.end(), ostream_iterator<int>(cout, " "));
    }
    else
        cout << "There is no repeated items";
    cout << endl;
    return;
}

void Number7(){
    cout << "Files.Number26" << endl;

    cout << "Enter count of students: ";
    int students;
    float avg;
    cin >> students;

    if(students < 1){
        cout << "Input Error!" << endl;
        return;
    }
    string number, name;

    string **data = new string *[students];
    for(int i = 0; i < students; i++){
        data[i] = new string[8];
    }

    map <char, int> mp = {
        { 'A',  5  },
        { 'B',  4  },
        { 'C',  3  },
        { 'D',  2  },
        { 'F',  1  },
        { '5',  5  },
        { '4',  4  },
        { '3',  3  },
        { '2',  2  },
        { '1',  1  },
        { '0',  0  }
    };

    ofstream fout("Students(26).txt");
    fout << "Number of record book\tStudent's name\t\t\t\t\t\t1\t2\t3\t4\t5\tAvg\n\n";
    for(int i = 0; i < students; i++){
        avg = 0;
        for(int j = 0; j < 7; j++){
            if (!j){
                cout << "Enter number of " << i + 1<< " record book: ";
                cin >> data[i][j];
                data[i][j] = data[i][j].substr(0, 18);
                fout << data[i][j];
                for(int k = data[i][j].length(); k < 24; k++){
                    fout << " ";
                }
            }
            else if(j == 1){
                cout << "Enter Student's name: ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, data[i][j]);
                data[i][j] = data[i][j].substr(0, 34);
                fout << data[i][j];
                for(int k = data[i][j].length(); k < 36; k++){
                    fout << " ";
                }
            }
            else{
                cout << "Enter " << j - 1 << " grade: ";
                cin >> data[i][j];
                fout << data[i][j] << " \t";
                avg += atoi(data[i][j].c_str());
            }
        }
        data[i][7] = to_string(avg / 5);
        fout << setprecision(3) << avg / 5 << endl;
    }
    

    string temp;
    for (int i = 0; i < students - 1; i++){ 
        for (int j = i + 1; j < students; j++){
            if (data[i][7] < data[j][7]){
                for (int k = 0; k < 8; ++k){
                    temp = data[j][k];
                    data[j][k] = data[i][k];
                    data[i][k] = temp;
                }
            }
        }
	}
    fout.close();
    fout.open("Students(26).txt");
    fout << "Number of record book\tStudent's name\t\t\t\t\t\t1\t2\t3\t4\t5\tAvg\n\n";
    for(int i = 0; i < students; i++){
        for(int j = 0; j < 8; j++){
            if( j < 7 ){
                fout << data[i][j];
                if (!j){
                    for(int k = data[i][j].length(); k < 24; k++){
                        fout << " ";
                    }
                }
                else if(j == 1){
                    for(int k = data[i][j].length(); k < 36; k++){
                        fout << " ";
                    }
                }
                else{
                    fout << " \t";
                }
            }
            else{
                avg = atof(data[i][j].c_str()) ;
                fout << setprecision(3) << avg;
            }
        }
        fout << endl;
    }

    fout.close();

    for (int i = 0; i < students; i++) {
        delete[] data[i];
    }
	delete[] data;

    return;
}

void Number8(){
    cout << "Files.Number5" << endl;
    ifstream fin("Matrices(5).txt");

    int m, n, min, ans, ans1, ans2;
    bool flag, done;

    for(int number = 0; number < 5; number++){
        fin >> m >> n;
        // cout << "m = " << m << " n = " << n << endl;
        if(m < 1 || n < 1){
            cout << "Input Error" << endl;
            continue;
        }
        else{
            done = false;
            //инициализация массива
            int **matrix = new int *[m];
            for(int i = 0; i < m; i++){
                matrix[i] = new int[n];
            }
            //заполнение массива элементами из файла
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++)
                    fin >> matrix[i][j];
            }
            //основной цикл по нахождению ответа
            for(int i = 0; i < m; i++){  // цикл по строкам
                min = matrix[i][0];
                flag = true;
                for(int j = 0; j < n; j++){ // цикл по столбцам
                    if(matrix[i][j] <= min){ // поиск минимума во всей строке
                        min = matrix[i][j];
                        ans1 = i;           //индекс строки
                        ans2 = j;           //индекс столбца
                    }
                }
                for(int a = 0; a < m; a++){
                    if (matrix[a][ans2] > min){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    cout << number + 1 << ") Answer: (" << ans1 << ";"<< ans2 << ")\t Value = " << min << endl;
                    done = true;
                    break;
                }
            }
            if(!done){
                cout << number + 1 << ") There is no such items" << endl;
            }
        }
    }

    return;
}

int is_prime(int i){
    for(int k = 2; k < pow(i, 0.5) + 1; k++){
        if(i % k == 0 && i != k){
            return 0;
            break;
        }
    }
    return 1;
}

void Number9(){
    cout << "Sophie Germain Primes" << endl;

    float m,n;
    cout << "Enter M and N" << endl;
    cin >> m >> n;
    if (n < 0 && m < 0){
        cout << "Input Error" << endl;
        return;
    }
    else if (n < m){
        int temp = m;
        m = n;
        n = temp;
    }

    long long a,b;
    a = m < 2 ? 2 : ceil(m); b = floor(n);

    cout << "Numbers: " << endl;

    for(int i = a; a <= b; i++){
        if(i > b){
            break;
        }
        else if(is_prime(i)){
            if(is_prime(2 * i + 1)){
                cout << i << " ";
            }
        }
    }
    cout << endl;
    return;
}

void balls(){
    cout << "Balls" << endl;


    return;
}

void extra(){
    cout << "Text files.Number 15(not mine)" << endl;

    FILE* f = fopen("Files.Number15.txt", "r");
    
    char word[1000] = { '\0' };
    printf("Enter a word: "); 
    cin >> word;
 
    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    fseek(f, 0, SEEK_SET);
 
    int i = 0;
    char c = '\0';
    char* buf = new char[size + 1];
    while ((c = fgetc(f)) != EOF)
          buf[i++] = c;
 
    fclose(f);

    const char* w = NULL;
    if ((w = strstr(buf, word)) != NULL)
        cout << "Yes, there is the word in this file" << endl;
    else 
        cout <<"No, word \"" << word << "\"" << " not found" << endl;

    return;
}

int main() {
    cout << "Homework 5" << endl;

    while (true) {
        cin.clear();
        fflush(stdin);
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

        case 6:
            Number6();
            break;

        case 7:
            Number7();
            break;
        
        case 8:
            Number8();
            break;

        case 9:
            Number9();
            break;

        case 10:
            balls();
            break;
        
        case 100:
            extra();
            break;

        default:
            cout << "Probably you entered an incorrect number. Try again!" << endl;
            break;
        }
    }
    return 0;
}