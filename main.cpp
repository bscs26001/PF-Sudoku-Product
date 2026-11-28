#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
#include <cctype>
using namespace std;

const int Size = 9;
struct Sudoku {
    char board[Size][Size];
    char initial[Size][Size];
    bool completed;
    int moveCount;
    time_t startTime;
};
bool readInt(int* value);
void newGame(Sudoku* s, const char* filename);
void printBoard(const Sudoku* s);
bool placeNumber(Sudoku* s, int row, int col, int value);
bool isValidMove(const Sudoku* s, int row, int col, char value, string& errorMsg);
void eraseNumber(Sudoku* s, int row, int col);
bool checkCompletion(Sudoku* s);
void playGame(Sudoku* s);
int main() {
    Sudoku game = {};
    int choice = -1;
    newGame(&game, "puzzle.txt");
    while (choice != 0) {
        cout << "\n ======SUDOKU======\n";
        cout << "1. New game\n";
        cout << "2. Play a Move\n";
        cout << "3. Save game (Phase 2)\n";
        cout << "4. Load game (Phase 2)\n";
        cout << "5. Board status(Phase 2)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        if (!readInt(&choice)) {
            cout << "Enter a valid number\n";
            choice = -1;
            continue;
        }
        if (choice == 1) {
            newGame(&game, "puzzle.txt");
            if (game.startTime != 0) {
                cout << "Puzzle loaded successfully!\n";
                printBoard(&game);
            }
            else {
                cout << "Failed to load puzzle. Check file name and format.\n";
            }
        }
        else if (choice == 2) {

        }
        else if (choice == 3) {
            cout << "Not implemented in Phase 1" << endl;
        }
        else if (choice == 4) {
            cout << "Not implemented in Phase 1" << endl;
        }
        else if (choice == 5) {
            cout << "Not implemented in Phase 1" << endl;
        }
    }
    return 0;
}
bool readInt(int* value) {
    if (cin >> *value) {
        cin.ignore(10000, '\n');
        return true;
    }
    cin.clear();
    cin.ignore(10000, '\n');
    return false;
}
void newGame(Sudoku* s, const char* filename) {
    ifstream fin(filename);
    if (!fin) {
        s->startTime = 0;
        return;
    }
    Sudoku temp = {};
    string line;
    for (int i = 0; i < Size; i++) {
        if (!(getline(fin, line)) || line.length() < 9) {
            s->startTime = 0;
            return;
        }
        for (int j = 0; j < Size; j++) {
            char c = line[j];
            if (c != '.' && (c < '1' || c > '9')) {
                s->startTime = 0;
                return;
            }
            temp.board[i][j] = c;
            temp.initial[i][j] = c;
        }
    }
    fin.close();
    string errorMsg;
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            if (temp.initial[i][j] != '.') {
                char v = temp.board[i][j];
                temp.board[i][j] = '.';
                if (!isValidMove(&temp, i, j, v, errorMsg)) {
                    s->startTime = 0;
                    return;
                }
                temp.board[i][j] = v;
            }
        }
    }
    *s = temp;
    s->moveCount = 0;
    s->startTime = time(0);
    s->completed = false;

}
void printBoard(const Sudoku* s) {
    cout << "\n    1 2 3   4 5 6   7 8 9\n";
    cout << "  +-------+-------+-------+\n";
    for (int i = 0; i < Size; i++) {
        cout << (i + 1) << " | ";
        for (int j = 0; j < Size; j++) {
            char displayChar = s->board[i][j];
            if (s->initial[i][j] == '.' && displayChar != '.') {
                displayChar = 'a' + (displayChar - '1');
            }
            cout << displayChar << " ";
            if ((j + 1) % 3 == 0 && j != 8) {
                cout << "|";
            }
        }
        cout << "|\n";
        if ((i + 1) % 3 == 0) {
            cout << "  +-------+-------+-------+\n";
        }
    }
}

bool isValidMove(const Sudoku* s, int row, int col, char value, string& errorMsg) {
    if (row < 0 || row >= Size || col < 0 || col >= Size) {
        errorMsg = "Row or Column out of bounds";
        return false;
    }
    for (int j = 0; j < Size; j++) {
        if (s->board[row][j] == value) {
            cout << "Value already exists in this row.";
            return false;
        }
    }
    for (int i = 0; i < Size; i++) {
        if (s->board[i][col] == value) {
            cout << "Value already exists in this column.";
            return false;
        }
    }
    int startRow = row - (row % 3);
    int startCol = col - (col % 3);
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (s->board[i][j] == value) {
                errorMsg = "Value already exists in this 3x3 box.";
                return false;
            }
        }
    }
    return true;
}
