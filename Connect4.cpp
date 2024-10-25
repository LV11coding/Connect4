#include <iostream>
using namespace std;

int main() {
    int space[6][7] = {{0}};
    int filled[7] = {5, 5, 5, 5, 5, 5, 5};
    bool turn = false;
    bool finish = false;
    int pos_pl = 0;

    auto check_win = [&](int player) -> bool {
       
        for (int row = 0; row < 6; row++) {
            for (int col = 0; col < 7; col++) {
                if (col <= 3 && space[row][col] == player && space[row][col + 1] == player &&
                    space[row][col + 2] == player && space[row][col + 3] == player) {
                    return true;
                }
                if (row <= 2 && space[row][col] == player && space[row + 1][col] == player &&
                    space[row + 2][col] == player && space[row + 3][col] == player) {
                    return true;
                }
                if (row <= 2 && col <= 3 && space[row][col] == player && space[row + 1][col + 1] == player &&
                    space[row + 2][col + 2] == player && space[row + 3][col + 3] == player) {
                    return true;
                }
                if (row >= 3 && col <= 3 && space[row][col] == player && space[row - 1][col + 1] == player &&
                    space[row - 2][col + 2] == player && space[row - 3][col + 3] == player) {
                    return true;
                }
            }
        }
        return false;
    };

    while (true) {
        for (int ver = 0; ver < 6; ver++) {
            for (int hor = 0; hor < 7; hor++) {
                cout << space[ver][hor] << " ";
            }
            cout << endl;
        }
        cout << endl;

        cout << "Player " << (turn ? 2 : 1) << "'s turn. Enter the column number (1-7): ";
        cin >> pos_pl;

        if (pos_pl < 1 || pos_pl > 7) {
            cout << "Invalid column! Please enter a number between 1 and 7." << endl;
            continue;
        }

        if (filled[pos_pl - 1] < 0) {
            cout << "There are no more spaces in this column!" << endl;
            continue;
        }

        space[filled[pos_pl - 1]][pos_pl - 1] = (turn ? 2 : 1);

        if (check_win(turn ? 2 : 1)) {
            for (int ver = 0; ver < 6; ver++) {
                for (int hor = 0; hor < 7; hor++) {
                    cout << space[ver][hor] << " ";
                }
                cout << endl;
            }
            cout << endl;
            cout << "Player " << (turn ? 2 : 1) << " wins!" << endl;
            return 0;
        }

        filled[pos_pl - 1]--;
        turn = !turn;
    }
}
