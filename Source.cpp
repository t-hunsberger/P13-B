#include <iostream>

using namespace std;

int main() {
	string name;
	cout << "What is your name " << endl;
	cin >> name;

	if (name == "nat" || name == "nataleigh") {
		cout << "hello " << name << " that is a very pretty name!!";
	}
	else if (name == "tucker") {
		cout << "ewww";
	}
	else {
		cout << "hello " << name << " why would your parents not name you nataleigh";

	}

}