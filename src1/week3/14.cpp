#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

class Person {
public:
	Person(const string& first_name, const string& second_name, int age) {
		first = first_name;
		second = second_name;
		page = age;
	}
	tuple<string, string, int> get_info() const {
		return {first, second, page};
	}
private:
	string first;
	string second;
	int page;
};

ostream & operator << (ostream & outstream, const Person & p){
	tuple<string, string, int> info = p.get_info();
	outstream << get<0>(info) << " " << get<1>(info) << " " << get<2>(info);
	return outstream;
}

void printVec(const vector<Person> & vec){
	for(const Person & p:vec){
		cout << p << endl;
	}
}

int main(){
	vector<Person> vec;
	vec.push_back({"Adil", "Adelshin", 25});
	vec.push_back({"Alexa", "Adelshina", 24});
	Person p("One", "Two", 32);
	vec.push_back(p);
	vec.push_back(Person("Alexander", "Pushkin", 37));
	printVec(vec);

}


