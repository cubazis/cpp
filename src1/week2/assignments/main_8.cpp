#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void PrintVector(const vector<int>& v) {
	for (int s : v) {
		cout << s << " ";
	}
	cout << endl;
}

int main() {
	int N;
	cin >> N;
	vector<int> days(N);
	for(int & day:days){
		cin >> day;
	}
	int mean = accumulate(begin(days), end(days), 0.0) / days.size();
	int i = 0;
	vector<int> rec;
	for(int day:days){
		if(day > mean){
			rec.push_back(i);
		}
		++i;
	}
	cout << rec.size() << endl;
	PrintVector(rec);
}