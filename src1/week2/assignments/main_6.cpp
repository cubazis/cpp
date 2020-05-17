#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
Напишите функцию MoveStrings, которая принимает два вектора строк, source и destination,
и дописывает все строки из первого вектора в конец второго.
После выполнения функции вектор source должен оказаться пустым.
*/

void swap(int & a, int & b){
	int tmp = a;
	a = b;
	b = tmp;
}

void Reverse(vector<int>& v){

	int len = v.size();
	for (int i = 0, j=len-1; i < (int)len/2; ++i ,--j) {
		swap(v[i], v[j]);
	}
}

int main() {
	vector<int> numbers = {1, 5, 3, 4, 2};
	Reverse(numbers);
	for (auto w: numbers) {
		cout << w << " ";
	}
}