#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Напишите функцию MoveStrings, которая принимает два вектора строк, source и destination,
и дописывает все строки из первого вектора в конец второго.
После выполнения функции вектор source должен оказаться пустым.
*/

vector<int> Reverse(const vector<int>& v){
	vector<int> res = v;
	reverse(begin(res), end(res));
	return res;
}

int main() {
	vector<int> numbers = {1, 5, 3, 4, 2};
	vector<int> res = Reverse(numbers);
	for (auto w: numbers) {
		cout << w << " ";
	}
	cout << endl;
	for (auto w: res) {
		cout << w << " ";
	}
}