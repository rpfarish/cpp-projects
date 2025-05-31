#include <iostream>
#include <vector>


void printB(std::vector<int> const &input)
{
	//input.size()
	for (int i = 6; i <9 ; i++) {

		if (!input.at(i))
		{
			std::cout << " " << ' ';
		}
		else if (input.at(i) == 1)
		{
			std::cout << "X" << ' ';
		}
		else if (input.at(i) == 2)
		{
			std::cout << "O" << ' ';
		}
		if (i % 3 == 2)
		{
			std::cout << std::endl;
		}
	}

	for (int i = 3; i < 6; i++) {

		if (!input.at(i))
		{
			std::cout << " " << ' ';
		}
		else if (input.at(i) == 1)
		{
			std::cout << "X" << ' ';
		}
		else if (input.at(i) == 2)
		{
			std::cout << "O" << ' ';
		}
		if (i % 3 == 2)
		{
			std::cout << std::endl;
		}
	}

	for (int i = 0; i < 3; i++) {

		if (!input.at(i))
		{
			std::cout << " " << ' ';
		}
		else if (input.at(i) == 1)
		{
			std::cout << "X" << ' ';
		}
		else if (input.at(i) == 2)
		{
			std::cout << "O" << ' ';
		}
		if (i % 3 == 2)
		{
			std::cout << std::endl;
		}
	}
}


void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {


		std::cout << input.at(i) << ' ';

		if (i % 3 == 2)
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void TakeTurn(int spot, int val, std::vector<int> &ip)
{
	ip.at(spot - 1) = val;
}

bool isIn(std::vector<int> &ip, int val)
{
	for (int i = 0; i < ip.size(); i++)
	{
		if (ip.at(i) == val) {
			return true;
		}
	}
	return false;
}

int hasWon(std::vector<int> &ip)
{
	int val1 = 1;
	int val2 = 2;

	// ---- ROWS ----

	// Row 1
	if (ip.at(0) == val1 and ip.at(1)== val1 and ip.at(2) == val1)  {
		return val1;
	}
	if (ip.at(0) == val2 and ip.at(1) == val2 and ip.at(2) == val2) {
		return val2;
	}
	// Row 2
	if (ip.at(3) == val1 and ip.at(4) == val1 and ip.at(5) == val1) {
		return val1;
	}
	if (ip.at(3) == val2 and ip.at(4) == val2 and ip.at(5) == val2) {
		return val2;
	}
	// Row 3
	if (ip.at(6) == val1 and ip.at(7) == val1 and ip.at(8) == val1) {
		return val1;
	}
	if (ip.at(6) == val2 and ip.at(7) == val2 and ip.at(8) == val2) {
		return val2;
	}

	// ---- COLS ----

	return 0;
}

bool isEnd() {
	return true;
}

int main()
{
	//int xWins = 0;
	//int oWins = 0;
	//int ties = 0;
	bool isComp = false;
	bool gameOver = false;
	int move;
	int whoWon;

	std::vector<int> board(9, 0);
	std::vector<int> exampleBoard = { 7, 8, 9, 4, 5, 6, 1, 2, 3 };
	std::vector<int> moves;

	print(exampleBoard);

	while (true) {
		std::cout << "Enter Your Move:\n";
		std::cin >> move;

		if (isIn(moves, move)) {
			std::cout << "You cannot move there" << std::endl;
			continue;
		}

		if (1 > move || 9 < move) { continue; }
		//std::cout << move << std::endl;

		if (!isComp) {
			TakeTurn(move, 1, board);
			moves.push_back(move);

		}
		else if (isComp) {
			TakeTurn(move, 2, board);
			moves.push_back(move);
		}

		isComp = !isComp;
		std::cout << "---------------" << std::endl;
		printB(board);
		std::cout << "---------------" << std::endl;


		if (hasWon(board))
		{
			whoWon = hasWon(board);
			if (whoWon == 1)std::cout << "X won" << std::endl;
			else if (whoWon == 2)std::cout << "O won" << std::endl;
			std::cout << "Game Over" << std::endl;
			return 0;
	    }

		if (moves.size() == 9)
            {
			//std::cout << "Tie" << std::endl << "Game Over" std::endl;
			return 0;
		}
	}


	return 0;
}
