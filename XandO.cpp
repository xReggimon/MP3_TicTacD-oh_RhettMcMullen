#include <iostream>

using namespace std;

int getPlayerInput(string playerName);
/*Returns a value between 1 and 9, inclusive, indicating the square where the current player wants to place
his / her mark on the board.The input routine is to use the name of the player whose turn it is and is to check for
correct input.You may assume that the input is an integer, but the value entered might be where a mark on the
board already exists or is out of the expected range of legal values.
*/
bool isLegalMove(char board[], int location);
//Returns true if the indicated location on the board yet not yet been played, false otherwise.

void placeMarkOnBoard(char board[], char playerMark, int location);
//Places the indicated mark at the specified board location; routine assumes that this is a legal placement.

void clearBoard(char board[]);
//Restores the tic - tac - toe board to its original(i.e., with no crosses or circles being marked) configuration.

bool hasThreeInRow(char board[], char playerMark);
//Returns true if, for the specified mark, the board has the equivalent of three of those marks in a row, either
//vertically, horizontally, or diagonally.

void displayBoard(char board[]);
//Prints out the current board; the board display must be as shown above.

void displayGameStats(int ties, int player1Score, int player2Score);
//Prints out the “stats” for all the games : number of games tied, number of games player 1 won, and number of
//games player 2 won.

int main() {

}