#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
Напишите функцию UpdateIfGreater, которая принимает два целочисленных аргумента:
first и second. Если first оказался больше second,
Ваша функция должна записывать в second значение параметра first.
При этом указанная функция не должна ничего возвращать,
а изменение параметра second должно быть видно на вызывающей стороне.
 */

void UpdateIfGreater(int first, int & second){
	if(first > second){
		second = first;
	}
}

int main() {
	int a, b;
	cin >> a >> b;
	UpdateIfGreater(a, b);
	cout << a << " " << b << endl;
}