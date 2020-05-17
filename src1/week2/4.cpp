#include <iostream>
#include <vector>
#include <tuple>
#include <bits/stdc++.h>
using namespace std;

void move_day(vector<string> & to_day, vector<string> from_day){
	for(string deal:from_day){
		to_day.push_back(deal);
	}
}

void print_day(const vector<string> & day){
	cout << day.size() << " ";
	for(string deal:day){
		cout << deal << " ";
	}
	cout << endl;
}

void init_month(vector<vector<string>> & month, vector<int> months, int & current_month){
	for (int i = 0; i < months[current_month]; ++i) {
		vector<string> day = {};
		month.push_back(day);
	}
}
void print_month(const vector<vector<string>> & month){
	for(int i = 0; i < month.size(); ++i){
		cout << i << ":";
		for (string deal:month[i]) {
			cout << deal << " ";
		}
	}
	cout << endl;
}

void update_month(vector<vector<string>> & month, int next_month_len){
	if(month.size() > next_month_len){
		for (int i = month.size()-1; i >next_month_len-1 ; --i) {
			move_day(month[next_month_len-1], month[i]);
		}
	}
	month.resize(next_month_len);
}

void todo(vector<vector<string>> & month, vector<int> months, int & current_month){
	if(month.empty()){
		init_month( month, months, current_month);
	}
	string op;
	getline(cin >> ws, op);
	istringstream iss(op);
	for(string s; iss >> s; ){
		if(s == "NEXT"){
			++current_month;
			if(current_month == months.size()){
				current_month = 0;
			}
			update_month(month, months[current_month]);
		}else if(s == "ADD"){
			iss >> s;
			int day_num = stoi(s)-1;
			iss >> s;
			vector<string> day = month[day_num];
			day.push_back(s);
			month[day_num] = day;
		}else if(s == "DUMP"){
			iss >> s;
			print_day(month[stoi(s)-1]);
		}
		//print_month(month);
	}
}

int main() {
	vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int N;
	cin >> N;
	vector<vector<string>> month;
	int current = 0;
	for(int i=0; i<N; ++i){
		todo(month, months, current);
		//cout << i << endl;
	}
}