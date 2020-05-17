#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<char, int> mappa(const string & a){
	map<char, int> m;
	for(const char & c: a){
		++m[c];
	}
	return m;
}

string check(const string & a, const string & b){
	map<char, int> aa = mappa(a);
	map<char, int> bb = mappa(b);
	if(aa.size() != bb.size()){
		return "NO";
	} else{
		for(const auto& [key, value]: aa){
			if(bb.count(key) == 0){
				return "NO";
			}else if(bb[key] != value){
				return "NO";
			}
		}
		return "YES";
	}
}

int main() {
	int N;
	cin >> N;
	string a, b;
	for (int i = 0; i < N; ++i) {
		cin >> a >> b;
		cout << check(a, b) << endl;
	}

}