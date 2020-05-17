#include <iostream>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;



void process(map<vector<string>, int> & buses){
	string op;
	getline(cin >> ws, op);
	istringstream iss(op);
	int num_of_stops;
	string stop;
	for(string s; iss >> s; ){
		num_of_stops = stoi(s);
		vector<string> stops;
		for (int i = 0; i < num_of_stops; ++i) {
			iss >> stop;
			stops.push_back(stop);
		}
		if(buses.count(stops) == 0){
			int j = buses.size()+1;
			buses[stops] = j;
			cout << "New bus " << j << endl;
		}else{
			cout << "Already exists for " << buses[stops] << endl;
		}
	}
}

int main() {
	int N;
	cin >> N;
	map<vector<string>, int> buses;
	for (int i = 1; i <= N; ++i) {
		process(buses);
	}
}