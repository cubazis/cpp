#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v {1, 3, 5, 1, 6, 2};
	for(auto & i: v){
		cout << ++i << endl;
	}
}