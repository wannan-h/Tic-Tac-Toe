// Tic Tac Toe.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

struct checkerboard {
	char board[3][3];
	int turns;
};

class ticTacToe {
public:
	checkerboard objCheckerboard;
	ticTacToe();
	void initCheckerboard();//All position = *, turns = 0
	void displayCheckerboard();//show checkerboard.	
	bool judgePositionLegal(int position);// judge whether the position is legal. 1 == legal	0 == illegal	
	bool judgeWin();// judge whether win the game. 1 == win		0 == not win	
	void playingGame();//play game
};
ticTacToe::ticTacToe() {
	initCheckerboard();
}

void ticTacToe::initCheckerboard() {//all position set to it's position number
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			this->objCheckerboard.board[i][j] = i * 3 + j + '1';
		}
	}
	this->objCheckerboard.turns = 0;
	this->displayCheckerboard();
}

void ticTacToe::displayCheckerboard() {//show the checkerboard
	cout << "Round " << this->objCheckerboard.turns << " :" << endl;
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			cout <<' '<< this->objCheckerboard.board[i][j] << ' ';
			if (j != 2) {
				cout << '|';
			}
			else {
				cout << endl;
			}
		}
		if (i != 2) {
			cout << "---+---+---" << endl;
		}
	}
	cout << "-----------" << endl;
}

bool ticTacToe::judgePositionLegal(int position) {// 1 == legal	0 == illegal
	int row = position / 3;
	int column = position % 3 - 1;
	if (this->objCheckerboard.board[row][column] == row * 3 + column + '1') {
		return true;
	}
	else {
		return false;
	}
}

bool ticTacToe::judgeWin() {
	for (int i = 0; i <= 2; i++) {
		if (this->objCheckerboard.board[i][0] == this->objCheckerboard.board[i][1] && this->objCheckerboard.board[i][1] == this->objCheckerboard.board[i][2]  ) {
			return true;//case 1    //3 line
		}
		if (this->objCheckerboard.board[0][i] == this->objCheckerboard.board[1][i] && this->objCheckerboard.board[1][i] == this->objCheckerboard.board[2][i]) {
			return true;//case 2	//3 row
		}
	}
	if (this->objCheckerboard.board[0][0] == this->objCheckerboard.board[1][1]&& this->objCheckerboard.board[1][1] == this->objCheckerboard.board[2][2]  ) {
		return true;//case 3		//diagonal
	}
	if (this->objCheckerboard.board[0][2] == this->objCheckerboard.board[1][1]&& this->objCheckerboard.board[1][1] == this->objCheckerboard.board[2][0]) {
		return true;//case 3		//diagonal
	}
	return false;
}

void ticTacToe::playingGame() {
	int chessPosition;
	for (int i = 1; i <= 9; i++) {
		cout << "Please input chess position:";
		while (1) {
			cin >> chessPosition;
			if (this->judgePositionLegal(chessPosition) == false) {
				cout << "illegal position, please reselect position." << endl;
			}
			else {
				break;
			}
		}
		cout << "*******************************" << endl;
		cout << "     *****          ******     " << endl;
		cout << "   *************************   " << endl;
		cout << "  ***************************  " << endl;
		cout << "   *************************   " << endl;
		cout << "    ***********************    " << endl;
		cout << "     *********************     " << endl;
		cout << "      *******************      " << endl;
		cout << "       *****************       " << endl;
		cout << "        ***************	    " << endl;
		cout << "         *************	        " << endl;
		cout << "*******************************" << endl;
		
		this->objCheckerboard.turns++;
		int row = chessPosition / 3;
		int column = chessPosition % 3 - 1;
		if (this->objCheckerboard.turns % 2 == 1) {//			
			this->objCheckerboard.board[row][column] = 'O';
		}
		else {
			this->objCheckerboard.board[row][column] = 'X';
		}
		this->displayCheckerboard();

		if (this->judgeWin()) {
			cout << "Win" << endl;
			if (this->objCheckerboard.turns % 2 == 1) {
				cout << "Player O win the game!!!" << endl;
			}
			else {
				cout << "Player X win the game!!!" << endl;
			}
			break;
		}
	}
	cout << "The game drwa." << endl;
}



int main(){

	ticTacToe objTicTacToe;
	objTicTacToe.playingGame();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
