#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

const int Size=9;
struct Sudoku {
    char board[Size][Size];
    char initial[Size][Size];
    bool completed;
};
bool readInt(int*value);
void newGame(Sudoku*s,const char*filename);
void printBoard(const Sudoku*s);
bool placeNumber(Sudoku*s, int row, int col, int value);
int main() {
    Sudoku game ={};
    int choice=-1;
    newGame(&game,"puzzle.txt");
    while (choice!= 0) {
        cout<<"\n ======SUDOKU======\n";
        cout<<"1. New game\n";
        cout<<"2. Play a Move\n";
        cout<<"3. Save game\n";
        cout<<"4. Load game \n";
        cout<<"5. Exit\n";
        cout<<"enter choice: ";
        if (!readInt(&choice)) {
            cout<<"Enter a valid number\n";
            choice=-1;
            continue;
        }
        if (choice==1){}
        else if (choice==3){}
        else if (choice==4){}
        else if (choice==5){}
    }
    return 0;
}