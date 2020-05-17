#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
Напишите функцию MoveStrings, которая принимает два вектора строк, source и destination,
и дописывает все строки из первого вектора в конец второго.
После выполнения функции вектор source должен оказаться пустым.
*/

void MoveStrings(vector<string> & source, vector<string> & destination){
	for (auto w: source) {
		destination.push_back(w);
	}
	source.clear();
}

int main() {
	vector<string> a = {"one", "twp"};
	vector<string> b = {"three"};
	MoveStrings(a, b);
	for (auto w: b) {
		cout << w;
	}
	for (auto w: a) {
		cout << w;
	}
}