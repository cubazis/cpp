#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
Напишите функцию, которая

называется Factorial
возвращает int
принимает int и возвращает факториал своего аргумента.
Гарантируется, что аргумент функции по модулю не превышает 10. Для отрицательных аргументов функция должна возвращать 1.

 */

int Factorial(int N){
	if(N<0){
		return 1;
	}
	int fact = 1;
	for (int i = 1; i <= N; ++i) {
		fact *=i;
	}
	return fact;
}

int main() {
	int N;
	cin >> N;
	cout << Factorial(N);
	return 0;
}