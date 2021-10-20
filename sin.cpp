#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <FCNTL.H>
#include <io.h>
#include <malloc.h>
#include <cmath>
#define WIN_H (300)
#define WIN_W (1000)

//----------------------------------------

//----------------------------------------
// глобальные переменные и константы

#define AppWindowName "Application"
#define ChildWindowName "ChildAppWindow"

#define CHILD_1        201     // идентификатор дочернего окна


HINSTANCE hIns;             // описатель приложения

//----------------------------------------
// объявление функций

ATOM RegisterClassMainWindow (void);

HWND CreateMainWindow (void);

LRESULT CALLBACK WndProcMain (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);


//----------------------------------------
// описание функций


//
// Основная функция оконных приложений
//
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow){

    MSG msg;
    
    hIns = hInstance;

    if (CreateMainWindow() == NULL) {
        return 0;
    }

    // Основной цикл обработки сообщений
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

//--------------------

//
// Регистрация класса основного окна приложения
//
ATOM RegisterClassMainWindow() {

WNDCLASSEX WndClass;

    WndClass.cbSize         = sizeof (WndClass);        // размер структуры класса
    WndClass.style          = 0;
    WndClass.lpfnWndProc    = WndProcMain;              // адрес оконной процедуры класса
    WndClass.cbClsExtra     = 0;                        // размер дополнительной памяти класса
    WndClass.cbWndExtra     = sizeof(void*);            // размер дополнительной памяти окна
    WndClass.hInstance      = hIns;                     // описатель приложения
    WndClass.hIcon          = LoadIcon (hIns, "MainIcon");
    WndClass.hCursor        = LoadCursor (NULL, IDC_ARROW); // курсор окна
    WndClass.hbrBackground  = (HBRUSH) GetStockObject (BLACK_BRUSH);
    WndClass.lpszMenuName   = NULL;
    WndClass.lpszClassName  = AppWindowName;            // имя класса
    WndClass.hIconSm        = LoadIcon (hIns, "MainIcon");

    return RegisterClassEx(&WndClass);
}

//--------------------



//
// Создание основного окна приложения
//
HWND CreateMainWindow() {

    HWND hwnd;

    RegisterClassMainWindow();

    hwnd = CreateWindowEx(WS_EX_CONTROLPARENT | WS_EX_APPWINDOW,
                          AppWindowName,
                          "Application",
                          WS_OVERLAPPEDWINDOW,
                          10, 10,
                          WIN_W, WIN_H,
                          NULL,                 // описатель родительского окна
                          NULL,                 // описатель главного меню (для главного окна)
                          hIns,NULL);

    if (hwnd == NULL) {
        MessageBox(NULL,"Ошибка создания основного окна приложения","",MB_OK);
        return NULL;
    }

    // отображение окна
    ShowWindow(hwnd, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    return hwnd;
}

//--------------------



void paint(HWND hwnd) {

    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);

    HPEN Pen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
    SelectObject(hdc, Pen);

    MoveToEx(hdc, WIN_W / 2, 0, NULL);
    LineTo(hdc, WIN_W / 2, WIN_H);
    MoveToEx(hdc, 0, WIN_H / 2, NULL);
    LineTo(hdc, WIN_W, WIN_H / 2);

    for (double x = -10; x <= 10; x += 0.01) {
        MoveToEx(hdc, 50 * x + WIN_W / 2, -100 * sin(x) + WIN_H / 2, NULL);
        LineTo(hdc, 50 * x + WIN_W / 2, -100 * sin(x) + WIN_H / 2);
    }

    EndPaint(hwnd, &ps);
}

//
// Функция обработки сообщений главного окна приложения.
//
LRESULT CALLBACK WndProcMain(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {

    switch (iMsg){

        case WM_CREATE:
            return 0;

        case WM_PAINT:
            paint(hwnd);
            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        }

    return DefWindowProc(hwnd, iMsg, wParam, lParam);
}