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
        cout << "1" << endl;
    }
    else if (x == 0){
        cout << "0" << endl;
    }
    else
        cout << "-1" << endl;
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
    cout << "Number 5 " << endl;
	// HWND hwnd = GetConsoleWindow();
	// HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	// HDC hdc = GetDC(hwnd);
	// SelectObject(hdc, Pen);
	// MoveToEx(hdc, 300, 0, NULL);
	// LineTo(hdc, 300, 250);
	// MoveToEx(hdc, 0, 125, NULL);
	// LineTo(hdc, 1000, 125);
	// for (double x = -10; x <= 20; x += 0.001) {
	// 	MoveToEx(hdc, 50 * x + 300, -50 * sin(x) + 125, NULL);
	// 	LineTo(hdc, 50 * x + 300, -50 * sin(x) + 125);
	// }
	// ReleaseDC(hwnd, hdc);
	// std::cin.get();

    return;
}

