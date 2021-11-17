#include "header4.hpp"

void Number1(){
    cout << "Number 1" << endl;
    int sum = 0;
    int num;
    char ch;
    int a;

    ofstream fout("Homework4.Task1.txt");

    cout << "Enter your numbers:" << endl;
    for (int i = 0; i < 10; i++){
        cin >> a; 
        fout << a;
        fout << " ";
    }
    fout.close();

    ifstream fin("Homework4.Task1.txt");
    for(int i = 0; i < 10; i++){
        fin >> a;
        sum += a;
    }
    fin.close();

    cout << "Sum = " << sum << endl;

    return;
}

void sign(){
    float x;
    cout << "Enter x: ";
    cin >> x;
    cout << "Answer: ";
    if (x > 0){
        cout << "+" << endl;
    }
    else if (x == 0){
        cout << "0" << endl;
    }
    else
        cout << "-" << endl;
    cout << endl;
    return;
}

void Number2(){
    cout << "Number 2" << endl;
    sign();
    return;
}

void rectangle(){
    cout << "Rectangle" << endl;

    float a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    if (a <= 0 || b <= 0){
        cout << "Input Error" << endl;
        return;
    }
    cout << "S = "<< a * b << endl;

    return;
}

void triangle(){
    cout << "Triangle" << endl;

    float h, a;
    cout << "Enter h: ";
    cin >> h;
    cout << "Enter a: ";
    cin >> a;

    if (h <= 0 || a <= 0 ){
        cout << "Input Error" << endl;
        return;
    }
    cout << "S = " << 0.5 * h * a << endl;

    return;
}

void circle(){
    cout << "Circle" << endl;

    float R;
    cout << "Enter R: ";
    cin >> R;

    if (R <= 0){
        cout << "Input Error" << endl;
        return;
    }
    cout << "S = "<< R * R * M_PI << endl;

    return;
}

void Number3(){
    int a;
    cout << "Enter number(1 - rectangle; 2 - triangle; 3 - circle): ";
    cin >> a;
    
    switch (a){
        case 1:
            rectangle();
            break;
            
        case 2:
            triangle();
            break;

        case 3:
            circle();
            break;

        default:
            cout << "Input Error" << endl;
            break;
    }

    return;
}

void Number4(){
    cout << "Number 4\n" << endl;

    int i, k;
    for (i = 1; i <= 6; i++){
        cout << "* * * * * * * *" << setfill('=') << setw(32) << "=" << endl;
    }
    for (k = 1; k <= 7; k++){
        cout << setfill('=') << setw(47) << "=" << endl;
    }
    cout << endl;

    return;
}

void Number5(){
    cout << "Number 5" << endl;
    system(".\\sin.exe");
    return;
}


void Number6(){
    cout << "Number 6" << endl;

    // map <char,int>alph = {
    //     { 'I', 1    },
    //     { 'V', 5    },
    //     { 'X', 10   },
    //     { 'L', 50   },
    //     { 'C', 100  },
    //     { 'D', 500  },
    //     { 'M', 1000 }
    // };

    // string num;
    // bool flag = true, check = true;
    // int count = 0, same = 1, sum = 0, temp = 0;
    // cout << "Enter Number: ";
    // cin >> num;
    
    // for (int i = num.length() - 1; i >= 0; i--){
    //     int curr = alph[num[i]];

    //     //для первого числа. присваиваем темповую переменную
    //     if (temp == 0){ 
    //         temp = curr;
    //         sum = curr;
    //     }



    //     else if(curr > temp){
    //         sum += curr;
    //         flag = true;
    //     }

    //     else if (curr == temp && flag){
    //         sum += curr;
    //         same += 1;
            
    //         if (same > 3){
    //             check = false;
    //             break;
    //         }
    //     }

    //     else if (curr < temp){
    //         sum -= curr;
    //         flag = false;

    //     }

    //     else{
    //         check = false;
    //         break;
    //     }

    //     temp = curr;

    // }



    // if (check){
    //     cout << "sum = " << sum << endl;
    // }
    // else{
    //     cout << "Input Error!" << endl;
    // }

    // cout << endl;
    // Number6();
    return;
}

void Number7(){
    cout << "Number 7" << endl;
    int v, s[32768];
    unsigned long long m, i, c; 
    srand(time(0));
    s[0] = rand();
    cout << "How large are the numbers?\n0 - small\n1 - big" << endl;
    cin >> v;
    
    if (v == 0){
        m = 37; i = 3; c = 64;
        for (i = 0; i <= 3; i++)
            s[i + 1] = (m * s[i] + i) % c;
        cout << s[i] << endl;            
    }
    else if(v == 1){
        m = 25173; i = 13849; c = 65537;
        for (i = 0; i <= 13849; i++)
            s[i + 1] = (m * s[i] + i) % c;
        cout << s[i] << endl;
    }
    else
        cout << "Input Error!" << endl;       
    return;
}

void Number8(){
    cout << "Number 8" << endl;

    int A[3][4] = {5, 2, 0, 10, 3, 5, 2, 5, 20, 0, 0, 0};
    float B[4][2] = {1.20, 0.50, 2.80, 0.40, 5.00, 1.00, 2.00, 1.50};

    float c[3][2] = {'\0'};
    float sum = 0;
    int k = 0;

    int x;
    for(int k = 0; k < 2; k++){
        x = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 4; j++){
                sum += A[i][j] * B[j][k];
            }
            c[x][k] = sum;
            x++;
            sum = 0;
        }
    }
    float total_profit = 0, total_fees = 0, total_money = 0;
    float min_fee = 100, max_fee = 0;
    int num_mxp,num_mnp,num_max_fee,num_min_fee;
    float max_profit = 0, min_profit = 100;
    for(int i = 0; i < 3; i++){
        total_profit += c[i][0] - c[i][1];
        total_fees += c[i][1];
        total_money += c[i][0];
        for (int j = 0; j < 2; j++){
            cout << c[i][j] << " ";
        }
        if(c[i][0] - c[i][1] > max_profit){
            max_profit = c[i][0] - c[i][1];
            num_mxp = i + 1;
        }
        if(c[i][0] - c[i][1] < min_profit){
            min_profit = c[i][0] - c[i][1];
            num_mnp = i + 1;
        }

        if (c[i][1] > max_fee){
            max_fee = c[i][1];
            num_max_fee = i + 1;
        }

        if (c[i][1] < min_fee){
            min_fee = c[i][1];
            num_min_fee = i + 1;
        }
        cout << endl;
    }

    cout << "1)Profit\nMax - " << num_mxp << "\tMin - " << num_mnp << endl;
    cout << "2)Fees:\nMax - " << num_max_fee << "\tMin - " << num_min_fee << endl;
    cout << "3)Total profit = " << total_profit << endl;
    cout << "4)Total fees = " << total_fees << endl;
    cout << "5)Total money = " << total_money << endl;
    return;
}

void Number9(){
    cout << "Number 9" << endl;

    string x;
    char ans[30];
    int tenth = 0;
    int old_base, new_base;
    cout << "Enter your number: ";
    cin >> x;
    cout << "Enter old base: ";
    cin >> old_base;
    cout << "Enter new base: ";
    cin >> new_base;


    if (old_base != 10){
        for(int i = 0; i < x.length(); i++){
            if(x[i] > '9'){
                tenth += (x[i] - '7') * pow(old_base, x.length() - i - 1);
            }
            else{
                tenth += (x[i] - '0') * pow(old_base, x.length() - i - 1);
            }
        }
    }
    // if (new_base == 10){
    //     cout << tenth << endl;
    // }
    // else{
    //     itoa(tenth,ans,new_base);
    //     cout << ans << endl;
    // }


    return;
}