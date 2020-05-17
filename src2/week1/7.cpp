#include <iostream>
#include <vector>
using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

bool operator < (const Date & one, const Date & two){
	return vector<int>{one.year, one.month, one.day} < vector<int>{two.year, two.month, two.day};
}


int main() {
	cout << (Date{2017, 6, 8} < Date{2017, 1, 26}) << endl;
}