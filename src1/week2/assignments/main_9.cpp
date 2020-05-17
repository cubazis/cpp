#include <iostream>
#include <vector>
#include <tuple>
#include <bits/stdc++.h>
using namespace std;

void PrintVector(const vector<bool>& v) {
	for (auto s : v) {
		cout << s << " ";
	}
	cout << endl;
}

void process_shit(vector<bool> & worried){
	string op;
	getline(cin >> ws, op);
	istringstream iss(op);
	for(string s; iss >> s; ){
		if(s == "WORRY_COUNT"){
			cout << count(begin(worried), end(worried), true) << endl;
		}else{
			if(s == "COME"){
				iss >> s;
				worried.resize(worried.size() + stoi(s), false);
			}else if(s == "WORRY"){
				iss >> s;
				worried[stoi(s)] = true;
			}else if(s == "QUIET"){
				iss >> s;
				worried[stoi(s)] = false;
			}
		};
	}
}

int main() {
	int N;
	cin >> N;
	vector<bool> worried;
	for(int i=0; i<N; ++i){
		process_shit(worried);
	}
}