#include <bits/stdc++.h>
using namespace std;

char positions[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int series;

class Mygame
{
private:
    int i, j, p = 0, p1 = 0, p2 = 0, draw = 0;
    int player = 1;
    bool gameover = false;

public:
    void print(void)
    {
        cout << " Tic Tac Toe \n";
        cout << "Player 1 wins: " << p1 << " <--|--> "
             << "Player 2 wins: " << p2 << " <-- | --> "
             << "Draws" << draw << endl;
        for (i = 0; i < 9; i++)
        {
            if (i % 3 == 0 && i != 0)
                cout << "\n--------------\n";
            cout << " | " << positions[i];
            if (i % 3 == 2)
                cout << " | ";
        }
        cout << "\n";
    }

    void logic(void)
    {
        player = 1;
        p = 0;
        gameover = false;
        while (!gameover)
        {
            print();
            if (positions[0] == positions[1] && positions[1] == positions[2] ||
                positions[3] == positions[4] && positions[4] == positions[5] ||
                positions[6] == positions[7] && positions[7] == positions[8] ||
                positions[0] == positions[3] && positions[3] == positions[6] ||
                positions[1] == positions[4] && positions[4] == positions[7] ||
                positions[2] == positions[5] && positions[5] == positions[8] ||
                positions[0] == positions[4] && positions[4] == positions[8] ||
                positions[2] == positions[4] && positions[4] == positions[6])
            {
                cout << "Player " << (player == 1 ? "two" : "one") << " Wins!! this round" << endl;
                player == 1 ? p2++ : p1++;
                gameover = true;
            }
            else if (p == 9)
            {
                cout << "this round was a Draw" << endl;
                draw++;
                gameover = true;
            }
            else
            {
                int choice;
                cout << "Player " << (player == 1 ? "one" : "two") << " => ";
                cin >> choice;
                if (choice < 1 || choice > 9 || positions[choice - 1] == 'X' || positions[choice - 1] == 'O')
                {
                    cerr << "Invalid Move!!\n";
                }
                else
                {
                    positions[choice - 1] = (player == 1) ? 'X' : 'O';
                    p++;
                    player = (player == 1) ? 2 : 1;
                }
            }
        }
    }
    void reset(void)
    {
        int r = 49;
        for (int i = 0; i < 10; i++)
        {
            positions[i] = r;
            r++;
        }
    }
    void check_win(void)
    {
        if (p1 > series / 2)
        {
            cout << "player 1 won the match" << endl;
        }
        else if (p2 > series / 2)
        {
            cout << "player 2 won the match" << endl;
        }
        else
        {
            cout << "it was a complete draw" << endl;
        }
    }
} tic;

int main()
{
    cout << "Enter Matches u want to play: ";
    cin >> series;
    while (series)
    {
        system("cls");
        tic.logic();
        tic.reset();
        series--;
    }
    tic.check_win();
    return 0;
}
