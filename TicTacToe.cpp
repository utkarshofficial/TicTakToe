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

void blockShow(char a[3][3]){
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " <<endl;
    cout << "  " << a[0][0] << "  |  " << a[0][1] << "  |  " << a[0][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << a[1][0] << "  |  " << a[1][1] << "  |  " << a[1][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << a[2][0] << "  |  " << a[2][1] << "  |  " << a[2][2] << endl;

    cout << "     |     |     " << endl << endl;
}



int main()
{
    // for title and color
    system("title TicTacToe by Utkarsh");
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
    a[0][0]='1';
    a[0][1]='2';
    a[0][2]='3';
    a[1][0]='4';
    a[1][1]='5';
    a[1][2]='6';
    a[2][0]='7';
    a[2][1]='8';
    a[2][2]='9';


    // output the blocks
    blockShow(a);
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
                int p1;
                cout << "X player turn : ";
                cin >> p1;
                // for 0 row
                if(p1==1){
                    x1=0;x2=0;
                }
                if(p1==2){
                    x1=0;x2=1;
                }
                if(p1==3){
                    x1=0;x2=2;
                }
                // for 1 row
                if(p1==4){
                    x1=1;x2=0;
                }
                if(p1==5){
                    x1=1;x2=1;
                }
                if(p1==6){
                    x1=1;x2=2;
                }
                // for 2 row
                if(p1==7){
                    x1=2;x2=0;
                }
                if(p1==8){
                    x1=2;x2=1;
                }
                if(p1==9){
                    x1=2;x2=2;
                }
                if(p1<=0 || p1>=10){
                    cout << "Invalid Move\n";
                    // invalid move accepter
                    goto a;
                }
                
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
                blockShow(a);

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
                int p2;
                cout << "O player turn : ";
                cin >> p2;
                // for 0 row
                if(p2==1){
                    o1=0;o2=0;
                }
                if(p2==2){
                    o1=0;o2=1;
                }
                if(p2==3){
                    o1=0;o2=2;
                }
                // for 1 row
                if(p2==4){
                    o1=1;o2=0;
                }
                if(p2==5){
                    o1=1;o2=1;
                }
                if(p2==6){
                    o1=1;o2=2;
                }
                // for 2 row
                if(p2==7){
                    o1=2;o2=0;
                }
                if(p2==8){
                    o1=2;o2=1;
                }
                if(p2==9){
                    o1=2;o2=2;
                }
                if(p2<=0 || p2>=10){
                    cout << "Invalid Move\n";
                    // invalid move accepter
                    goto b;
                }
                

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
                blockShow(a);

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
