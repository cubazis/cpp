#include <iostream>
#include <bitset>
using namespace std;

/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> bits;

    cin >> n;
    while (n > 0) {
        bits.push_back(n % 2);
        n /= 2;
    }

    for (int i = bits.size() - 1; i >= 0; --i) {
        cout << bits[i];
    }
    return 0;
}

 */

int main() {
	int N;
	cin >> N;
	bitset<64> bits = N;
	string str = bits.to_string();
	cout << str.erase(0, str.find_first_not_of('0')) << endl;
	return 0;
}