#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

class ReversibleString {
public:
	ReversibleString() {
		s = "";
	}
	ReversibleString(const string& str) {
		s = str;
	}
	void Reverse(){
		int len = s.length();
		int n=len-1;
		for(int i=0;i<(len/2);i++){
			swap(s[i],s[n]);
			n = n-1;
		}
	}
	string ToString() const {
		return  s;
	}
private:
	string s;
};

int main() {
	ReversibleString s("live");
	s.Reverse();
	cout << s.ToString() << endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	string tmp = s_ref.ToString();
	cout << tmp << endl;

	ReversibleString empty;
	cout << '"' << empty.ToString() << '"' << endl;

	return 0;
}

/*
#include <algorithm>
#include <string>

using namespace std;

class ReversibleString {
public:
  ReversibleString() {}
  ReversibleString(const string& s) {
    data = s;
  }
  void Reverse() {
    reverse(begin(data), end(data));
  }
  string ToString() const {
    return data;
  }
private:
  string data;
};
 */
