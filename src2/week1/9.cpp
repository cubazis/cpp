#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

struct Date1 {
	int year;
	int month;
	int day;
};

struct Date2 {
	int year;
	string month;
	int day;
};

bool operator < (const Date1 & one, const Date1 & two){
	return tie(one.year, one.month, one.day) < tie(two.year, two.month, two.day);
}

bool operator < (const Date2 & one, const Date2 & two){
	return tie(one.year, one.month, one.day) < tie(two.year, two.month, two.day);
}


int main() {
	vector<string> vec = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
	for (int i = 0; i < vec.size(); ++i) {
		for (int j = i+1; j < vec.size(); ++j) {
			cout << vec[i] << " " << vec[j] << " ";
			cout << (Date1{2017, i, 8} < Date1{2017, j, 8}) << " ";
			cout << (Date2{2017, vec[i], 8} < Date2{2017, vec[j], 8}) << endl;
		}

	}
}