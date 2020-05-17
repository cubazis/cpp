#include <iostream>
#include <vector>
using namespace std;

void process(vector<bool> & worried){
	string s;
	cin >> s;
	if(s == "WORRY_COUNT"){
		cout << count(begin(worried), end(worried), true) << endl;
	}
	if(s == "COME"){
		cin >> s;
		worried.resize(worried.size() + stoi(s), false);
	}
	if(s == "WORRY"){
		cin >> s;
		worried[stoi(s)] = true;
	}
	if(s == "QUIET"){
		cin >> s;
		worried[stoi(s)] = false;
	}
}

int main() {
	int N;
	cin >> N;
	vector<bool> worried;
	for(int i=0; i<N; ++i){
		process(worried);
	}
}