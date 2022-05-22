#include <iostream>
using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[3][3], char);

//Function to check for user input is within 0-2 and update
//boolean withinBounds
void checkBounds(int, int);

//Boolean for the while loop
bool withinBounds = false;

//Declaring a constant int for looping
const int ARR_LENGTH = 3;

//Declaring an int for game turn counter
int turnCounter = 0;

//Function to check for duplicate entries
void checkDuplicates(char[][3], int, int);

//Function to check for row matches
bool matchRows(char[][3], char);

//Function to check for column matches
bool matchCols(char[][3], char);

//Function to check for diagonal matches
bool matchDiag(char[][3], char);

int main() {
	//
	//	PLEASE DO NOT CHANGE function main
	//
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);

	while (true) {
		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);
		if (isWon('X', board)) {
			cout << "X player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board)) {
			cout << "O player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}
	}

	return 0;
}

//Print out the game board to the console.
void displayBoard(char board[][3])
{	//Formatted to match the given output
	cout << "\n";
	for (int i=0; i<ARR_LENGTH; i++) //rows
	{
		cout << "-------------\n";
		for (int j = 0; j < ARR_LENGTH; j++) { //columns
			cout << "| "<<board[i][j] <<" ";
		}
		cout << "|\n";
	}
	cout << "-------------\n";
}

//Takes user input and puts in inside the board
void makeAMove(char board[3][3], char player)
{
	//Variables to store user input for row and column 
	int row=0, col=0;

	//While loop to get input again if the input is invalid
	while (withinBounds != true)
	{
		//Enter row
		cout << "Enter a row(0, 1, 2) for player "<<player<<" : ";
		cin >> row;
		//Enter col
		cout << "Enter a column(0, 1, 2) for player " <<player<<" : ";
		cin >> col;

		//Calling the function to see if within the bound of the board
		checkBounds(row, col);

		//Calling the function to check for duplicates and update 
		//the bool for the while loop
		checkDuplicates(board, row, col);
	}
	//Updating the board
	board[row][col] = player;

	//Setting boolean back to false so that the next time this method is called it has
	//to go through the while loop at least once
	withinBounds = false;
}

bool isWon(char player, char board[][3]) {
	//if else if to check all ways of winning
	if (matchRows(board, player)) {
		return true;
	}
	else if (matchCols(board, player)) {
		return true;
	}
	else if (matchDiag(board, player)) {
		return true;
	}
	else {
		return false;
	}

}

bool isDraw(char board[][3])
{
	//each time this method is called the counter increases
	turnCounter++;

	//if there is no winner by the 9th round the game must be a draw
	if (turnCounter > 8) {
		return true;
	}

	return false;
}

//Function to check for invalid input
void checkBounds(int row, int col) {
	//if outside the bound of baord makes the bool false;
	if (row > 3) {
		withinBounds = false;
		cout << "Invalid input.\n";
	}
	else if (col > 3) {
		withinBounds = false;
		cout << "Invalid input.\n";
	}
	else {
		withinBounds = true;
	}
}

//Function to check for duplicate entries
void checkDuplicates(char board[][3], int row, int col) {
	//Checks to see if the given row and col has a value that is not
	//empty, then changes the bool to false so that the loop goes ahead and 
	//gets a new input
	if (board[row][col] != ' ') {
		withinBounds = false;
		cout << "This cell is occupied. Try a different cell.\n";
	}
}

//Function to check for row matches
bool matchRows(char board[][3], char player) {
	//counter for how many matches found. Player wins if
	//the counter is 3.
	int numOfMatches = 0;

	//check row 0
	for (int i = 0; i < ARR_LENGTH; i++) {
		if (board[0][i] == player) {
			numOfMatches++;
		}
		if (numOfMatches == 3) {
			return true;
		}
	}
	numOfMatches = 0; //reset counter to 0 before checking each loop
	//check row 1
	for (int i = 0; i < ARR_LENGTH; i++) {
		if (board[1][i] == player) {
			numOfMatches++;
		}
		if (numOfMatches == 3) {
			return true;
		}
	}
	numOfMatches = 0; //reset counter to 0 before checking each loop
	//check row 2
	for (int i = 0; i < ARR_LENGTH; i++) {
		if (board[2][i] == player) {
			numOfMatches++;
		}
		if (numOfMatches == 3) {
			return true;
		}
	}

	return false;
}

//Function to check for column matches
bool matchCols(char board[][3], char player) {
	//counter for how many matches found. Player wins if
	//the counter is 3.
	int numOfMatches = 0;

	//check col 0
	for (int i = 0; i < ARR_LENGTH; i++) {
		if (board[i][0] == player) {
			numOfMatches++;
		}
		if (numOfMatches == 3) {
			return true;
		}
	}
	numOfMatches = 0; //reset counter to 0 before checking each loop
	//check row 1
	for (int i = 0; i < ARR_LENGTH; i++) {
		if (board[i][1] == player) {
			numOfMatches++;
		}
		if (numOfMatches == 3) {
			return true;
		}
	}
	numOfMatches = 0; //reset counter to 0 before checking each loop
	//check row 2
	for (int i = 0; i < ARR_LENGTH; i++) {
		if (board[i][2] == player) {
			numOfMatches++;
		}
		if (numOfMatches == 3) {
			return true;
		}
	}	
	return false;
}

//Function to check for diagonal matches
bool matchDiag(char board[][3], char player) {
	//checking cells diagnoally both right to left and left to right
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
		return true;
	}
	else if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
		return true;
	}
	return false;
}