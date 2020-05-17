#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
Напишите функцию, которая

называется PalindromFilter
возвращает vector<string>
принимает vector<string> words и int minLength и возвращает все строки из вектора words, которые являются палиндромами и имеют длину не меньше minLength
Входной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.

 */


bool IsPalindrom(string str){
	for (int i = 0, j = str.size()-1; i < str.size(); ++i, --j) {
		if(str[i] != str[j]) {
			return false;
		}
	}
	return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength){
	vector<string> res;
	for (auto w: words) {
		if(IsPalindrom(w) && (w.size() >= minLength)){
			res.push_back(w);
		}
	}
	return res;

}

int main() {
	vector<string> test = {"aaabaaa", "aabaa", "aba", "as"};
	vector<string> res = PalindromFilter(test, 5);
	for(auto w: res){
		cout << w << endl;
	}
}