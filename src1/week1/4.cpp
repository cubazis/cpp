#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int count_fives(){
	vector<int> nums = {1, 2, 3, 4, 5, 5};
	int q = 0;
	for (auto c : nums) {
		if(c == 5) {
			q += 1;
		}
	}
	cout << q << endl;
	return 0;
}

int count_fives_algo(){
	vector<int> nums = {1, 2, 3, 4, 5, 5};
	int q = count(begin(nums), end(nums), 5);
	cout << q << endl;
	return 0;
}

int sort_ints_algo(){
	vector<int> nums = {1, 5, 4, 2, 2, 5};
	sort(begin(nums), end(nums));
	for (auto c : nums) {
		cout << c << endl;
	}
	return 0;
}

int sort_strings_algo(){
	string word = "babax";
	sort(begin(word), end(word));
	cout << word << " " << count(begin(word), end(word), 'a');
	return 0;
}


int main() {
	//count_fives();
	//count_fives_algo();
	//sort_ints_algo();
	sort_strings_algo();
}