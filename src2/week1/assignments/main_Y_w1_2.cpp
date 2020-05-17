#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
using namespace std::placeholders;

void print(const vector<int> & v){
	cout << v.size() << endl;
	for(const auto & item:v){
		cout << item << " ";
	}
	cout << endl;
}

bool func(int mean, int x){
	return x > mean;
}

bool IsLess(int x){
	return x < 0;
}

int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}
	size_t mean = accumulate(begin(v), end(v), 0.0) / v.size();
	auto IsGreater = [mean](auto && PH1) { return func(mean, PH1); };
	for (int j = 0; j < N; ++j) {
		if(IsGreater(v[j])){
			v[j] = j;
		} else{
			v[j] = -1;
		}
	}
	v.erase(std::remove_if(v.begin(), v.end(), IsLess), v.end());
	print(v);
}