#include <iostream>
#include <set>

using namespace std;

/*
struct Incognizable {
  int x = 0;
  int y = 0;
};
 */

class Incognizable{
public:
	Incognizable(){
		s = {};
	}
	Incognizable(int t){
		s = {};
		s.insert(t);
	}
	Incognizable(int t1, int t2){
		s = {};
		s.insert(t1);
		s.insert(t2);
	}
	void print(){
		for(const int & i:s){
			cout << i << " ";
		}
		cout << endl;
	}
private:
	set<int> s;
};

int main(){
	Incognizable a;
	Incognizable b = {};
	Incognizable c = {0};
	Incognizable d = {0, 1};
	return 0;
}