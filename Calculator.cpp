#include <iostream>

void GetResult(char oper, double number1, double number2)
{
	if (oper == '+') {
		std::cout << number1 <<  " + " << number2 << " = " << number1 + number2 << "\n\n\n";
	}
	else if (oper == '-') {
		std::cout << number1 << " - " << number2 << " = " << number1 - number2 << "\n\n\n";
	}
	else if (oper == '*') {
		std::cout << number1 << " * " << number2 << " = " << number1 * number2 << "\n\n\n";
	}
	else if (oper == '/') {
		std::cout << number1 << " / " << number2 << " = " << number1 / number2 << "\n\n\n";
	}
}

int main()
{
	double num1, num2;
	char opp;
	while (true) {
		
		// Number 1
		std::cout << "Please enter your first number: \n";
		std::cin >> num1;
		
		// Operation
		std::cout << "Please specify your operation type + - * or /: ";
		std::cout << "(Enter the number of it 1-4)\n";
		std::cin >> opp;

		// Allow user to quit
		if (opp == 'q') { break; }

		// Number 2
		std::cout << "Please enter your second number: \n";
		std::cin >> num2;
		std::cout << std::endl;

		if (num2 == 0 and opp == '/') 
			std::cout << "Cannot divide by 0\n";
		else GetResult(opp, num1, num2); 
	}
	return 0;
}
