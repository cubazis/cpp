#include <iostream>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void all_buses(const map<string, vector<string>> & buses){
	if(buses.size() == 0){
		cout << "No buses" << endl;
	}else{
		for(const auto& [key, value]: buses){
			cout << "Bus " << key << ": ";
			for(const auto& stop:value){
				cout << stop << " ";
			}
			cout << endl;
		}
	}

}

bool bus_has_stop(const vector<string> & stops, const string stop){
	if(find(stops.begin(), stops.end(), stop) != stops.end()) {
		return true;
	}
	return false;
}

void stops_for_bus(map<string, vector<string>> & buses, const vector<string> hard_buses, const string bus){
	if(buses.count(bus) == 0){
		cout << "No bus" << endl;
	} else{
		vector<string> bus_stops = buses[bus];
		map<string, vector<string>> all_stops;
		vector<string> indexes;
		for(const auto& stop: bus_stops){
			vector<string> buses_for_stop;
			for(const auto& key: hard_buses){
				if(bus != key){
					if(bus_has_stop(buses[key], stop)){
						buses_for_stop.push_back(key);
					}
				}
			}
			indexes.push_back(stop);
			all_stops[stop] = buses_for_stop;
		}
		for(const auto& stop: indexes){
			cout << "Stop " << stop << ": ";
			if(all_stops[stop].size() == 0){
				cout << "no interchange" << endl;
			}else{
				for(const auto& b: all_stops[stop]){
					cout << b << " ";
				}
				cout << endl;
			}
		}
	}
}

void buses_for_stop(map<string, vector<string>> & buses, const vector<string> & hard_buses, const string stop){
	vector<string> buses_for_stop;
	for(const auto& key: hard_buses){
		if(bus_has_stop(buses[key], stop)){
			buses_for_stop.push_back(key);
		}
	}
	if(buses_for_stop.empty()){
		cout << "No stop" << endl;
	}else{
		for(const string & b: buses_for_stop){
			cout << b << " ";
		}
		cout << endl;
	}
}

void print(const map<string, vector<string>> & buses){
	for(const auto& [key, value]: buses){
		cout << key << ": ";
		for(const auto& stop: value){
			cout << stop << " ";
		}
		cout << endl;
	}
}

void process(map<string, vector<string>> & buses, vector<string> & hard_buses){
	string op;
	getline(cin >> ws, op);
	istringstream iss(op);
	for(string s; iss >> s; ){
		if(s == "NEW_BUS"){
			string bus;
			int num_of_stops;
			iss >> s;
			bus = s;
			iss >> s;
			num_of_stops = stoi(s);
			string stop;
			vector<string> stops;
			for (int i = 0; i < num_of_stops; ++i) {
				iss >> s;
				stop = s;
				stops.push_back(stop);
			}
			buses[bus] = stops;
			hard_buses.push_back(bus);
			break;
		} else if(s == "BUSES_FOR_STOP"){
			string stop;
			iss >> stop;
			buses_for_stop(buses, hard_buses, stop);
			break;
		} else if(s == "STOPS_FOR_BUS"){
			string bus;
			iss >> bus;
			stops_for_bus(buses, hard_buses, bus);
			break;
		}else if(s == "ALL_BUSES"){
			all_buses(buses);
			break;
		}
		//print(buses);
	}
}

int main() {
	int N;
	cin >> N;
	map<string, vector<string>> buses;
	vector<string> hard_buses;
	for (int i = 0; i < N; ++i) {
		process(buses, hard_buses);
	}
}