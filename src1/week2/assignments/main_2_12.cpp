#include <iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;

void dump(const map<string, string> & countries){
	if(countries.size() == 0){
		cout << "There are no countries in the world" << endl;
	}else{
		for(const auto& [key, value]: countries){
			cout << key << "/" << value << " ";
		}
		cout << endl;
	}

}

void process(map<string, string> & countries){
	string op;
	getline(cin >> ws, op);
	istringstream iss(op);
	for(string s; iss >> s; ){
		if(s == "CHANGE_CAPITAL"){
			string country;
			string capital;
			iss >> country >> capital;
			if(countries.count(country) == 0){
				countries[country] = capital;
				cout << "Introduce new country " << country << " with capital " <<  capital << endl;
			}else{
				if(countries[country] == capital){
					cout << "Country " << country << " hasn't changed its capital" << endl;
				}else{
					string old_capital = countries[country];
					countries[country] = capital;
					cout << "Country " << country << " has changed its capital from " << old_capital << " to " << capital << endl;
				}
			}

		} else if(s == "RENAME"){
			string old_country;
			string new_country;
			iss >> old_country >> new_country;
			if(countries.count(old_country) == 0 || countries.count(new_country) != 0 || old_country == new_country){
				cout << "Incorrect rename, skip" << endl;
			}else{
				string capital = countries[old_country];
				countries.erase(old_country);
				countries[new_country] = capital;
				cout << "Country " << old_country << " with capital " << capital << " has been renamed to " << new_country << endl;
			}
		} else if(s == "ABOUT"){
			string country;
			iss >> country;
			if(countries.count(country) == 0){
				cout << "Country " << country << " doesn't exist" << endl;
			} else{
				cout << "Country " << country << " has capital " << countries[country] << endl;
			}
		}else if(s == "DUMP"){
			dump(countries);
		}
	}
}

int main() {
	int N;
	cin >> N;
	map<string, string> countries;
	for (int i = 0; i < N; ++i) {
		process(countries);
	}
}