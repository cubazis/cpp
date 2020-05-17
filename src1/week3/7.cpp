#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void print(const vector<string> & v){
	for (const auto & i: v) {
		cout << i << " ";
	}
	cout << endl;
}

string EstimateLength(const string& s) {
	return s.size() > 10 ? "long" : "short";
}

int Foo(int a, int b) {
	int x = 0;
	if (a == 0) {
		return 0;
	}
	int y;
	if (b < 100) {
		y = b / a;
	} else {
		int a = b - 100;
		y = a * a;
	}
	x = y - a - b;
	return x * x;
}

string GetPositivity(int x) {
	return x > 0 ? "positive"
	             : (x == 0 ? "zero" : "negative");
}

int main(){
	cout << GetPositivity(-5) << endl;
}