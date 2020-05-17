#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v {1, 3, 5, 1, 6, 2};
	cout << count_if(begin(v), end(v), [](int x){
		if(x > 2){
			return true;
		} else{
			return false;
		}
	});
}