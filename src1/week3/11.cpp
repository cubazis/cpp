#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		firsts[year] = first_name;
		firsts_years.insert(year);
	}
	void ChangeLastName(int year, const string& last_name) {
		lasts[year] = last_name;
		lasts_years.insert(year);
	}
	string GetFullName(int year) {
		if(firsts.empty() && lasts.empty()){
			return "Incognito";
		}
		string first = search_name(year, firsts);
		string last = search_name(year, lasts);
		if(first.empty() && last.empty()){
			return "Incognito";
		}
		if(first.empty()){
			return last + " with unknown first name";
		}
		if(last.empty()){
			return first + " with unknown last name";
		}
		return first + " " + last;
	}
	string GetFullNameWithHistory(int year) {
		if(firsts.empty() && lasts.empty()){
			return "Incognito";
		}
		string first = search_name_full(year, firsts, firsts_years);
		string last = search_name_full(year, lasts, lasts_years);
		if(first.empty() && last.empty()){
			return "Incognito";
		}
		if(first.empty()){
			return last + " with unknown first name";
		}
		if(last.empty()){
			return first + " with unknown last name";
		}
		return first + " " + last;
	}
private:
	map<int, string> firsts;
	set<int> firsts_years;
	map<int, string> lasts;
	set<int> lasts_years;
	static string search_name(const int & year, const map<int, string> & m){
		if(m.count(year) == 1){
			return m.at(year);
		} else{
			auto it = m.lower_bound(year);
			if(it != m.begin()){
				--it;
			}
			if(year < it->first){
				return "";
			}
			return it->second;
		}

	}
	static string get_history(const int & year, const map<int, string> & m, const set<int> & s){
		string res = "";
		vector<string> validate;
		validate.push_back(m.at(year));
		string last = m.at(year);
		for (auto i = s.find(year); i != s.begin(); --i) {
			//res += m.at(*i);
			if(year != *i){
				const string & tmp = m.at(*i);
				if(last != tmp){
					//cout << *i<< endl;
					validate.push_back(tmp);
					last = tmp;
					//cout << tmp << " ";
					//res += tmp;
				}
			}
		}
		string bgn = m.at(*s.begin());
		if(last != bgn){
			//cout << bgn;
			validate.push_back(bgn);
		}
		if(validate.empty()){
			return "";
		}
		res += validate[0];
		if(validate.size() > 1){
			res += " (";
			for (int j = 1; j < validate.size(); ++j) {
				if(j > 1){
					res += ", ";
				}
				res += validate[j];

			}
			res += ")";
		}

		return res;
	}
	static string search_name_full(const int & year, const map<int, string> & m, const set<int> & s){
		string res;
		if(m.count(year) == 1){
			string str =  get_history(year, m, s);
			if(str.empty()){
				res = m.at(year);
			} else{
				res = str;
			}

		} else{
			auto it = m.lower_bound(year);
			if(it != m.begin()){
				--it;
			}
			if(year < it->first){
				return "";
			}
			string str = get_history(it->first, m, s);
			if(str.empty()){
				res = it->second;
			} else{
				res = str;
			}
		}
		return res;
	}
};

void test_1(){
	Person person;

	person.ChangeFirstName(1900, "Eugene");
	person.ChangeLastName(1900, "Sokolov");
	person.ChangeLastName(1910, "Sokolov");
	person.ChangeFirstName(1920, "Evgeny");
	person.ChangeLastName(1930, "Sokolov");
	cout << person.GetFullNameWithHistory(1940) << endl;

	// >> Evgeny (Eugene) Sokolov
}

void test_2(){
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1990, "Polina");
	person.ChangeLastName(1990, "Volkova-Sergeeva");
	cout << person.GetFullNameWithHistory(1990) << endl;

	person.ChangeFirstName(1966, "Pauline");
	cout << person.GetFullNameWithHistory(1966) << endl;

	person.ChangeLastName(1960, "Sergeeva");
	for (int year : {1960, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1961, "Ivanova");
	cout << person.GetFullNameWithHistory(1967) << endl;
	/*
	Incognito
	Polina with unknown last name
	Polina Sergeeva
	Polina Sergeeva
	Appolinaria (Polina) Sergeeva
	Polina Volkova (Sergeeva)
	Appolinaria (Polina) Volkova (Sergeeva)
	Polina (Appolinaria, Polina) Volkova-Sergeeva (Volkova, Sergeeva)
	Pauline (Polina) with unknown last name
	Sergeeva with unknown first name
	Pauline (Polina) Sergeeva
	Pauline (Polina) Sergeeva (Ivanova, Sergeeva)
	 */
}

void test_3(){
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeFirstName(1965, "Appolinaria");

	person.ChangeLastName(1965, "Sergeeva");
	person.ChangeLastName(1965, "Volkova");
	person.ChangeLastName(1965, "Volkova-Sergeeva");

	for (int year : {1964, 1965, 1966}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}
	/*
	Incognito
	Appolinaria Volkova-Sergeeva
	Appolinaria Volkova-Sergeeva
	 */
}

void test_0(){
	Person person;
	for (int year : {1964, 1965, 1966}) {
		cout << person.GetFullName(year) << endl;
	}
}

int main() {
	test_0();
	return 0;
}