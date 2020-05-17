#include <iostream>
using namespace std;

int main() {
	int a;
	int b;
	cin >> a >> b;
	if(b == 0){
		cout << "Impossible" << endl;
		return 0;
	}
	if(a < b){
		cout << 0 << endl;
	} else{
		cout << a/b << endl;
	}

	return 0;
}