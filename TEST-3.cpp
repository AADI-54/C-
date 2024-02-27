#include <bits/stdc++.h>
using namespace std;

class Mygame
{
private:
    char arr[100][100];
    int m, n, player = 1;
    int choicex, choicey;
    int rowx = 0, clmnx = 0;
    int row0 = 0, clmn0 = 0;
    bool gameover = false;
    int series;

public:
    void setsize(int x, int y)
    {
        m = x;
        n = y;
    }
    void setdata(void)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = '-';
            }
        }
    }
    void print(void)
    {
        for (int k = -1; k < n; k++)
        {
            cout << k << "   ";
        }
        cout << endl;
        for (int i = 0; i < m; i++)
        {
            cout << " " << i << "   ";

            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << "   ";
            }
            cout << endl;
        }
    }
    void logic(void)
    {
        while (!gameover)
        {
            print();
            int p1 = 0, p2 = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (arr[i][j] == 'X')
                    {
                        p1++;
                        rowx = i;
                        clmnx = j;
                    }
                    if (arr[i][j] == '0')
                    {
                        p2++;
                        row0 = i;
                        clmn0 = j;
                    }
                    // if (check_win(rowx, clmnx, 'X') || check_win(row0, clmn0, '0'))
                    // {
                    //     gameover = true;
                    // }
                }
            }
            cout << "Player " << (player == 1 ? "one" : "two") << " => ";
            cin >> choicex >> choicey;
            if (arr[choicex][choicey] == 'X' || arr[choicex][choicey] == 'O')
            {
                cerr << "Invalid Move!!\n";
            }
            else
            {
                arr[choicex][choicey] = (player == 1) ? 'X' : 'O';
                player = (player == 1) ? 2 : 1;
            }
        }
    }

    // bool check_win(int row, int col, char c)
    // {
    //     int count = 0;
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (arr[row][j] == c)
    //         {
    //             count++;
    //         }
    //     }
    //     if (count == series)
    //     {
    //         return true;
    //     }
    //     count = 0;

    //     for (int i = 0; i < m; i++)
    //     {
    //         if (arr[i][col] == c)
    //         {
    //             count++;
    //         }
    //     }
    //     if (count == series)
    //     {
    //         return true;
    //     }
    //     count = 0;

    //     if (row == col)
    //     {
    //         for (int i = 0; i < m; i++)
    //         {
    //             if (arr[i][i] == c)
    //             {
    //                 count++;
    //             }
    //         }
    //         if (count == series)
    //         {
    //             return true;
    //         }
    //     }
    //     count = 0;

    //     if (row + col == m - 1)
    //     {
    //         for (int i = 0; i < m; i++)
    //         {
    //             if (arr[i][m - i - 1] == c)
    //             {
    //                 count++;
    //             }
    //         }
    //         if (count == series)
    //         {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

} tic;
int main()
{
    int size,series;
    cout << "enter size of game: ";
    cin >> size;

    tic.setsize(size, size);
    while (series)
    {
        tic.setdata();
        tic.logic();
        tic.setdata();
        series--;
    }
    
    
    cout << "exited";
}