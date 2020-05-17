#include <iostream>
#include <vector>
#include <map>
using namespace std;

void print_map_1(const map<string, int> & m){
	for(const auto& [key, value]: m){
		cout << key << ": " << value << endl;
	}
}

void print_map_2(const map<int, string> & m){
	for(const auto& [key, value]: m){
		cout << key << ": " << value << endl;
	}
}

//map<string, int> build_reversed_map(const map<int, string> & m){
//	map<string, int> reversed;
//	for(auto item: m){
//		reversed[item.second] = item.first;
//	}
//	return reversed;
//}

map<string, bool> BuildReversedMap(const map<bool, string>& m) {
	map<string, bool> result;
	for (const auto& item : m) {
		result[item.second] = item.first;
	}
	return result;
}


int main() {
	map<int, string> m = {{1, "odd"}, {2, "even"}, {1, "one"}};
	m[2] = "two";
	m.erase(1);
	m[3] = "three";
	m.erase(4);
	m[5] = "five";
	cout << m.size();
}