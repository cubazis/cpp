#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
Напишите функцию, которая

называется IsPalindrom
возвращает bool
принимает параметр типа string и возвращает, является ли переданная строка палиндромом
Палиндром - это слово или фраза, которые одинаково читаются слева направо и справа налево. Пустая строка является палиндромом.

 */

bool IsPalindrom(string str){
	for (int i = 0, j = str.size()-1; i < str.size(); ++i, --j) {
		if(str[i] != str[j]) {
			return false;
		}
	}
	return true;
}

int main() {
	string str;
	cin >> str;
	cout << IsPalindrom(str);
	return 0;
}