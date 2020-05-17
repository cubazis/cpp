#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	double N, X, Y, A, B;
	cin >> N >> A >> B >> X >> Y;
	if(N > B){
		cout << N - N*(Y/100) << endl;
	}else if(N > A){
		cout << N - N*(X/100) << endl;
	} else {
		cout << N << endl;
	}
	return 0;
}