#ifndef EDUCORE_H
#define EDUCORE_H

#if defined(_WIN32) || defined(WIN32)

    #define OS_Windows 1
    #include <windows.h>
    #include <stdio.h>
    #include <tchar.h>
    #define DIV 1048576
    #define WIDTH 7

    void gotoxy(int x, int y)
    {
      COORD coord;
      coord.X = x;
      coord.Y = y;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    void clearScreen()
    {
        system("cls");
    }

    void SetConsoleSize(int x, int y){
        COORD coord;
        coord.X = x;
        coord.Y = y;

        _SMALL_RECT rect;
        rect.Top = 0;
        rect.Left = 0;
        rect.Bottom = y-1;
        rect.Right = x-1;

        SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &rect);
    }

#endif

#ifdef __unix__

    #define OS_Windows 0
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

    void gotoxy(int x,int y)
    {
        printf("%c[%d;%df",0x1B,y,x);
    }

    void clearScreen()
    {
        std::cout << "\033[2J\033[1;1H";
    }

#endif

#endif // EDUCORE_H
