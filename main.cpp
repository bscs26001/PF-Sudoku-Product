#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
#include <cctype>
using namespace std;

const int Size=9;
struct Sudoku {
    char board[Size][Size];
    char initial[Size][Size];
    bool completed;
    int moveCount;
    time_t startTime;
};
bool readInt(int*value);
void newGame(Sudoku*s,const char*filename);
void printBoard(const Sudoku*s);
bool placeNumber(Sudoku*s, int row, int col, int value);
bool isValidMove(const Sudoku*s,int row,int col,char value, string &errorMsg);
void eraseNumber(Sudoku*s,int row, int col);
bool checkCompletion(Sudoku*s);
void playGame(Sudoku*s);
int main() {
    Sudoku game ={};
    int choice=-1;
    newGame(&game,"puzzle.txt");
    while (choice!= 0) {
        cout<<"\n ======SUDOKU======\n";
        cout<<"1. New game\n";
        cout<<"2. Play a Move\n";
        cout<<"3. Save game (Phase 2)\n";
        cout<<"4. Load game (Phase 2)\n";
        cout<<"5. Board status(Phase 2)\n";
        cout<<"0. Exit\n"
        cout<<"Enter choice: ";
        if (!readInt(&choice)) {
            cout<<"Enter a valid number\n";
            choice=-1;
            continue;
        }
        if (choice==1){}
        else if(choice==2){}
        else if (choice==3){
            cout<<"Not implemented in Phase 1"<<endl;
        }
        else if (choice==4){
            cout<<"Not implemented in Phase 1"<<endl;}
        else if (choice==5){
            cout<<"Not implemented in Phase 1"<<endl;
    }
    return 0;
}