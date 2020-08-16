#include <iostream>
#include <vector>


void printB(std::vector<int> const &input)
{
	std::cout << "---------------" << std::endl;
	for (unsigned int i = 6; i < 9; i++) {

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
			std::cout << "  ";
		}
		else if (input.at(i) == 1)
		{
			std::cout << "X ";
		}
		else if (input.at(i) == 2)
		{
			std::cout << "O ";
		}
		if (i % 3 == 2)
		{
			std::cout << std::endl;
		}
	}

	for (int i = 0; i < 3; i++) {

		if (!input.at(i))
		{
			std::cout << "  ";
		}
		else if (input.at(i) == 1)
		{
			std::cout << "X ";
		}
		else if (input.at(i) == 2)
		{
			std::cout << "O ";
		}
		if (i % 3 == 2)
		{
			std::cout << std::endl;
		}
	}
	std::cout << "---------------" << std::endl;
}


void print(std::vector<int> const &input)
{
	for (unsigned int i = 0; i < input.size(); i++) {


		std::cout << input.at(i) << ' ';

		if (i % 3 == 2)
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void TakeTurn(int spot, int val, std::vector<int> &ip, std::vector<int> &avail)
{
	ip.at(spot - 1) = val;
	for (unsigned int i = 0; i < avail.size(); i++) {
		if (avail.at(i) == spot) {
			avail.erase(avail.begin() + i);
			break;
		}
	}
	
}

bool isIn(std::vector<int> &ip, int val)
{
	for (unsigned int i = 0; i < ip.size(); i++)
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
	if (ip.at(0) == val1 and ip.at(1) == val1 and ip.at(2) == val1) {
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

	// Col 1
	if (ip.at(0) == val1 and ip.at(3) == val1 and ip.at(6) == val1) {
		return val1;
	}
	if (ip.at(0) == val2 and ip.at(3) == val2 and ip.at(6) == val2) {
		return val2;
	}

	// Col 2
	if (ip.at(1) == val1 and ip.at(4) == val1 and ip.at(7) == val1) {
		return val1;
	}
	if (ip.at(1) == val2 and ip.at(4) == val2 and ip.at(7) == val2) {
		return val2;
	}

	// Col 3
	if (ip.at(2) == val1 and ip.at(5) == val1 and ip.at(8) == val1) {
		return val1;
	}
	if (ip.at(2) == val2 and ip.at(5) == val2 and ip.at(8) == val2) {
		return val2;
	}

	// ---- DIAG ----

	// DIAG 1
	if (ip.at(2) == val1 and ip.at(4) == val1 and ip.at(6) == val1) {
		return val1;
	}
	if (ip.at(2) == val2 and ip.at(4) == val2 and ip.at(6) == val2) {
		return val2;
	}

	// DIAG 2
	if (ip.at(0) == val1 and ip.at(4) == val1 and ip.at(8) == val1) {
		return val1;
	}
	if (ip.at(0) == val2 and ip.at(4) == val2 and ip.at(8) == val2) {
		return val2;
	}

	return 0;
}

bool isEnd() {
	return true;
}

int optimalMove(std::vector<int> grid,std::vector<int> &moves, std::vector<int> avail)
{
	int temp;
	int move;
	for (unsigned int i = 0; i < avail.size(); i++) {
		
		move = avail.at(i);
		temp = grid.at(move - 1);
		grid.at(move - 1) = 2;
		
		if (hasWon(grid)) {
			return move;
		}
		grid.at(move - 1) = temp;
	}

	for (unsigned int i = 0; i < avail.size(); i++) {

		move = avail.at(i);
		temp = grid.at(move - 1);
		grid.at(move - 1) = 1;
		
		if (hasWon(grid)) {
			return move;
		}
		grid.at(move - 1) = temp;
	}


	if (!isIn(moves, 5)) {
		return 5;
	}
	for (unsigned int i = 0; i < avail.size(); i++) {
		if (avail.at(i) == 1) return 1;
		else if (avail.at(i) == 3) return 3;
		else if (avail.at(i) == 7) return 7;
		else if (avail.at(i) == 9) return 9;
	}
	if (avail.size()) return avail.at(0);

	return 0;
}

int main()
{

	//int ran;

	//std::cout <<  << std::endl;

	int xWins = 0;
	int oWins = 0;
	int ties = 0;
	int move;
	int whoWon;
	int compMove;
	
	bool isComp = false;
	bool gameOver = false;
	
	while (true) {

		std::vector<int> board(9, 0);
		std::vector<int> exampleBoard = { 7, 8, 9, 4, 5, 6, 1, 2, 3 };
		std::vector<int> availMoves = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
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
				TakeTurn(move, 1, board, availMoves);
				moves.push_back(move);

			}

			if (hasWon(board))
			{
				whoWon = hasWon(board);
				if (whoWon == 1) {
					std::cout << "X won" << std::endl;
					xWins++;
				}
				else if (whoWon == 2) {
					std::cout << "O won" << std::endl;
					oWins++;
				}
				std::cout << "Game Over" << std::endl;
				std::cout << std::endl << "X Wins: " << xWins << " O Wins: " << oWins << " Ties: " << ties << std::endl;
				break;
			}
			
			compMove = optimalMove(board, moves, availMoves);

			if (compMove)
			{
				TakeTurn(compMove, 2, board, availMoves);
				moves.push_back(compMove);
			}

			printB(board);

			if (hasWon(board))
			{
				whoWon = hasWon(board);
				if (whoWon == 1) { 
					std::cout << "X won" << std::endl; 
					xWins++; 
				}
				else if (whoWon == 2) {
					std::cout << "O won" << std::endl; 
					oWins++;
				}
				std::cout << "Game Over" << std::endl;
				std::cout << std::endl << "X Wins: " << xWins << " O Wins: " << oWins << " Ties: " << ties << std::endl;
				break;
			}

			if (moves.size() == 9)
			{
				std::cout << "Tie" << std::endl << "Game Over" << std::endl;
				ties++;
				std::cout << std::endl << "X Wins: " << xWins << " O Wins: " << oWins << " Ties: " << ties << std::endl;
				break;
			}
			
		}
	}
	std::cin.get();
	std::cin.get();
}
