#include <iostream>
#include <string>
using namespace std;

string command;
string selection;
string program;
string notepadString;
int x;
int y;
int result;
string calcOperation;

void notepad() {
	cout << "\nnotepad. enter 'EOL' to exit.\n";
	while (true) {
		cin >> notepadString;
		if (notepadString == "EOL") {
			break;
		}
	}
	cout << "\nEOL\n";
}

bool calculator() {
	cout << "\nCalculator\n";
	cout << "Enter 1 number: ";
	cin >> x;
	cout << "Enter 2 number: ";
	cin >> y;
	cout << "Enter operation (+-/*): ";
	cin >> calcOperation;
	if (calcOperation == "+") {
		cout << "Result: " << x + y << endl;
	}else if (calcOperation == "-") {
		cout << "Result: " << x - y << endl;
	}else if (calcOperation == "*") {
		cout << "Result: " << x * y << endl;
	}else if (calcOperation == "/") {
		if (x == 0 or y == 0) {
			cout << "\033[0;31mError. Can't divide by zero.\033[0m\n";
			return false;
		}
		cout << "Result: " << x / y << endl;
	}else{
		cout << "\033[0;31mError. Unsupported operation '" << calcOperation << "'.\033[0m\n";
		return false;
	}
	return true;
}

void info() {
	cout << "\nInformation:\n";
	cout << "ShitOS v.3 [C++ " << __cplusplus << "]";
	cout << "System & hardware info:\n";
	cout << "  CPU: emulated\n";
	cout << "  Kernel version: " << __cplusplus << "\n";
	cout << "  GPU: emulated\n";
	cout << "Commands:\n";
	cout << "  info;data;calculator;notepad";
}

void listdir() {
	cout << "\n\033[0;34mprograms\nfiles\033[0m\n";
	cout << "select: \033[1;31m";
	cin >> selection;
	cout << "\033[0m";
	if (selection == "programs") {
		cout << "\n\033[0;34mnotepad\ncalculator\033[0m\n";
		cout << "select: \033[1;31m";
		cin >> program;
		cout << "\033[0m";
		if (program == "calculator") {
			calculator();
		}else if (program == "notepad") {
			notepad();
		}else{
			cout << "\033[0;31mCommand " << program << " not found\033[0m\n";
		}
	}else if (selection == "files") {
		cout << "shit\n";
		cout << "select: \033[1;31m";
		cin >> selection;
		cout << "\033[0m";
		if (selection == "shit") {
			cout << "oh, shit...\n";
		}else{
			cout << "Not found.\n";
		}
	}else{
		cout << "\033[0;31m" << selection << " not found.\033[0m\n";
	}
}

int main() {
	cout << "Welcome to ShitOS [C++ " << __cplusplus << "]\n";
	while (true) { 
		cout << "root@shitos:~$ "; 
		cin >> command; // Command input
		if (command == "data") {
			listdir();
		}else if (command == "exit") {
			break;
		}else if (command == "clear") {
			cout << "\x1b[H\x1b[2J\x1b[3J";
		}else if (command == "info") {
			info();
		}else if (command == "calculator") {
			calculator();
		}else if (command == "notepad") {
			notepad();
		}else{
			cout << "\033[0;31mCommand " << command << " not found!\033[0m\n";
		}
	}
	cout << "\nShutting down.\n";
	return 0;
}
