#include <iostream>
#include <bitset>
using namespace std;
/*
На вход дано целое положительное число N. Выведите его в двоичной системе счисления без ведущих нулей.
5 101
32 100000
1 1
 */

int main() {
	int N;
	cin >> N;
	bitset<64> bits = N;
	string str = bits.to_string();
	cout << str.erase(0, str.find_first_not_of('0')) << endl;
	return 0;
}