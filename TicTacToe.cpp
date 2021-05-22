#include <iostream>
#include <unistd.h>
#include <windows.h>
using namespace std;

/*
THIS PROGRAM IS MAKED BY UTKARSH SHARMA @utkarshofficial
██╗   ██╗████████╗██╗  ██╗ █████╗ ██████╗ ███████╗██╗  ██╗
██║   ██║╚══██╔══╝██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██║  ██║
██║   ██║   ██║   █████╔╝ ███████║██████╔╝███████╗███████║
██║   ██║   ██║   ██╔═██╗ ██╔══██║██╔══██╗╚════██║██╔══██║
╚██████╔╝   ██║   ██║  ██╗██║  ██║██║  ██║███████║██║  ██║
 ╚═════╝    ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝
 */
int main()
{
    // for title and color
    system("title TicTacToe");
    system("color f");

    // for console width and height
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect); 
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 320, 300, TRUE);

    // for play again 
    again:
    int x1, x2, o1, o2;
    char o = 'O', x = 'X';

    // char array for blocks
    char a[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a[i][j] = '~';
        }
    }
    // output the blocks
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
    cout<<endl;
    sleep(1);

    // count var for draw
    int drawConut=0;
    while (true)
    {       
            // draw condition
            drawConut++;
            if(drawConut==10){
                cout<<"Game Draw\n";
                return 0;
            }
        // invalid move repeater
        a:
            cout << "X player turn , row column : ";
            cin >> x1 >> x2;
            x1 -= 1;
            x2 -= 1;
            // conditions for genuine moves
            if (a[x1][x2] == x || a[x1][x2] == o || x1<0 || x1>2 || x2<0 || x2>2 )
            {
                cout << "Invalid Move\n";
                // invalid move accepter
                goto a;
            }
            // input to array
            a[x1][x2] = x;
            system("cls");
            
            // output the update array
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << a[i][j] << "  ";
                }
                cout << endl;
            }
            cout<<endl;
            // Winner condtions for O
            if ((a[0][0] == x && a[0][1] == x && a[0][2] == x) || (a[1][0] == x && a[1][1] == x && a[1][2] == x) || (a[2][0] == x && a[2][1] == x && a[2][2] == x) || (a[0][0] == x && a[1][0] == x && a[2][0] == x) || (a[0][1] == x && a[1][1] == x && a[2][1] == x) || (a[0][2] == x && a[1][2] == x && a[2][2] == x) || (a[0][0] == x && a[1][1] == x && a[2][2] == x) || (a[0][2] == x && a[1][1] == x && a[2][0] == x))
            {
                cout << x << " Player Winer !\n";
                break;
            }
            // draw condition
            drawConut++;
            if(drawConut==10){
                cout<<"Game Draw\n";
                break;
            }
        // invalid move repeater
        b:
            cout << "O player turn , row column : ";
            cin >> o1 >> o2;
            o1 -= 1;
            o2 -= 1;
            // conditions for genuine moves
            if (a[o1][o2] == o || a[o1][o2] == x || o1<0 || o1>2 || o2<0 || o2>2 )
            {
                cout << "Invalid Move\n";
                // invalid move accepter
                goto b;
            }
            // input to array
            a[o1][o2] = o;
            system("cls");

            // output the update array
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << a[i][j] << "  ";
                }
                cout << endl;
            }
            cout<<endl;

            // Winner condtions for O
            if ((a[0][0] == o && a[0][1] == o && a[0][2] == o) || (a[1][0] == o && a[1][1] == o && a[1][2] == o) || (a[2][0] == o && a[2][1] == o && a[2][2] == o) || (a[0][0] == o && a[1][0] == o && a[2][0] == o) || (a[0][1] == o && a[1][1] == o && a[2][1] == o) || (a[0][2] == o && a[1][2] == o && a[2][2] == o) || (a[0][0] == o && a[1][1] == o && a[2][2] == o) || (a[0][2] == o && a[1][1] == o && a[2][0] == o))
            {
                cout << o << " Player Winer !\n";
                break;
            }
            
    }
    // asking for one more play
    string ask;cout<<"For play again type y or n(n) : ";cin>>ask;
    if(ask=="y" || ask=="yes")
    {
        system("cls");
        goto again;
    }
    else
        cout<<"Thank your for playing !\n";
    system("pause");
    return 0;
}