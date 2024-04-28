#include <iostream>
#include <string>

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
//Prints out the current board

void displayGameStats(int ties, int player1Score, int player2Score);
//Prints out the “stats” for all the games : number of games tied, number of games player 1 won, and number of
//games player 2 won.

int main() {

	string player1;string player2;
	int ties = 0; int player1Score = 0; int player2Score = 0;
	char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	cout << "The legendary Tic Tac Toe." <<endl;
	cout << endl;
	cout << "Enter usernames to start :) " << endl;
	cout << "player1: "; getline(cin, player1);
	cout << "player2: "; getline(cin, player2);
	cout << endl;


	displayBoard(board);
	//displayGameStats(ties, player1Score, player2Score, player1, player2);
	return 0;
}


int getPlayerInput(string playerName) {
	int input;
	cout << playerName << ", please enter your move (1-9): ";
	cin >> input;
	return input;
}

//This function is used to determine whether the user is putting in a valid Tic Tac Toe input
bool isLegalMove(char board[], int location) {
	return (location >= 1 && location <= 9 && board[location - 1] != 'X' && board[location - 1] != 'O');
}

void placeMarkOnBoard(char board[], char playerMark, int location) {
	board[location - 1] = playerMark;
}

void clearBoard(char board[]) {
	for (int i = 0; i < 9; i++) {
		board[i] = '1' + i;
	}
}

bool hasThreeInARow(char board[], char playerMark) {
	for (int i = 0; i < 3; i++) {
		if (board[i] == playerMark && board[i + 3] == playerMark && board[i + 6] == playerMark) {
			return true;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (board[i] == playerMark && board[i * 3+1] == playerMark && board[i *3 + 2] == playerMark) {
			return true;
		}
	}
	if ((board[0] == playerMark && board[4] == playerMark && board[8] == playerMark) ||
		(board[2] == playerMark && board[4] == playerMark && board[6] == playerMark)) {
		return true;
	}
	return false;
}

void displayBoard(char board[]) {
	cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
	cout << "-----------" << endl;
	cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "-----------" << endl;
	cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

void displayGameStats(int ties, int player1Score, int player2Score, string player1, string player2) {
	cout << "Ties: " << ties << endl;
	cout << player1 << "Wins: " << player1Score << endl;
	cout << player2 << "Wins: " << player2Score << endl;
}