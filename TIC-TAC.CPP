#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
char positions[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main()
{
    int i, p, j, n = 11;
    int player = 1;
    int series = 0;
    int p1 = 0, p2 = 0, draw = 0;
    bool gameover = false;
    cout << "enter series: ";
    cin >> series;
    while (series)
    {
        for (p = 1; p <= 10; p++)
        {
            printf(" Tic Tac Toe \n");
            int mid_num = 0;
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n; j++)
                {
                    if (j == 4 || j == 8 || i == 4 || i == 8)
                        cout << "~ ";
                    else if (j % 2 == 0 && i % 2 == 0)
                    {
                        cout << positions[mid_num];
                        mid_num++;
                    }
                    else
                        cout << "  ";
                }
                cout << "\n";
            }

            if (positions[0] == positions[1] && positions[1] == positions[2])
            {
                if (player == 2)
                {
                    cout << "Player One Wins!!";
                    p1++;
                    break;
                }
                else
                {
                    cout << "Player Two Wins!!";
                    p2++;
                    break;
                }
            }
            else if (positions[3] == positions[4] && positions[4] == positions[5])
            {
                if (player == 2)
                {
                    cout << "Player One Wins!!";
                    p1++;
                    break;
                }
                else
                {
                    cout << "Player Two Wins!!";
                    p2++;
                    break;
                }
            }
            else if (positions[6] == positions[7] && positions[7] == positions[8])
            {
                if (player == 2)
                {
                    cout << "Player One Wins!!";
                    p1++;
                    break;
                }
                else
                {
                    cout << "Player Two Wins!!";
                    p2++;
                    break;
                }
            }
            else if (positions[0] == positions[3] && positions[3] == positions[6])
            {
                if (player == 2)
                {
                    cout << "Player One Wins!!";
                    p1++;
                    break;
                }
                else
                {
                    cout << "Player Two Wins!!";
                    p2++;
                    break;
                }
            }
            else if (positions[1] == positions[4] && positions[4] == positions[7])
            {
                if (player == 2)

                {
                    cout << "Player One Wins!!";
                    p1++;
                    break;
                }
                else
                {
                    cout << "Player Two Wins!!";
                    p2++;
                    break;
                }
            }
            else if (positions[2] == positions[5] && positions[5] == positions[8])
            {
                if (player == 2)
                {
                    cout << "Player One Wins!!";
                    p1++;
                    break;
                }
                else
                {
                    cout << "Player Two Wins!!";
                    p2++;
                    break;
                }
            }
            else if (positions[0] == positions[4] && positions[4] == positions[8])
            {
                if (player == 2)
                {
                    cout << "Player One Wins!!";
                    p1++;
                    break;
                }
                else
                {
                    cout << "Player Two Wins!!";
                    p2++;
                    break;
                }
            }
            else if (positions[2] == positions[4] && positions[4] == positions[6])
            {
                if (player == 2)
                {
                    cout << "Player One Wins!!";
                    p1++;
                    break;
                }
                else
                {
                    cout << "Player Two Wins!!";
                    p2++;
                    break;
                }
            }
            if (p == 10)
            {
                cout << "Draw";
                draw++;
                break;
            }
            int choice;
            if (player == 1)
            {
                cout << "First Player => ";
                cin >> choice;
                if (positions[choice - 1] == 'x' || positions[choice - 1] == '0')
                {
                    cerr << "Wrong Move!!";
                    p--;
                }
                else
                {
                    positions[choice - 1] = 'x';
                    player++;
                }
            }
            else if (player == 2)
            {
                cout << "Second Player => ";
                cin >> choice;
                if (positions[choice - 1] == 'x' || positions[choice - 1] == '0')
                {
                    cerr << "Wrong Move!!";
                    p--;
                }
                else
                {
                    positions[choice - 1] = '0';
                    player--;
                }
            }
            cout << "\n\n\n";
        }
        player = 1;
        int reset = 49;
        for (int i = 0; i < 10; i++)
        {
            positions[i] = reset;
            reset++;
        }
        series--;
    }
    if (p1 > series / 2)
    {
        cout << "PLayer 1 wins the match";
    }
    else if (p2 > series / 2)
    {
        cout << "PLayer 2 wins the match";
    }
    else
    {
        cout << "its a draw";
    }
}