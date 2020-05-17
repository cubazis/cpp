#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	string str;
	cin >> str;
	int pos;
	int counter = 0;
	for (int i = 0; i < str.size(); ++i) {


		if(str[i] == 'f'){
			counter +=1;
			pos = i;
		}
		if(counter == 2) {
			break;
		}
	}
	if(counter == 2){
		cout << pos << endl;
	}else if(counter == 1){
		cout << -1 << endl;
	} else if(counter == 0){
		cout << -2 << endl;
	}
	return 0;
}