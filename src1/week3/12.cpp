#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
using namespace std;

string FindNameByYear(const map<int, string>& names, int year) {
	string name;  // изначально имя неизвестно

	// перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
	for (const auto& item : names) {
		// если очередной год не больше данного, обновляем имя
		if (item.first <= year) {
			name = item.second;
		} else {
			// иначе пора остановиться, так как эта запись и все последующие относятся к будущему
			break;
		}
	}

	return name;
}

void printVec(const vector<string> & vec){
	cout << vec.size() << endl;
	for(const string item: vec){
		cout << item << " ";
	}
	cout << endl;
}

string FindNameByYearHistory(const map<int, string>& names, int year) {
	string name;
	vector<string> history;
	string last = "";
	for (const auto& item : names) {
		// если очередной год не больше данного, обновляем имя
		if (item.first <= year) {
			name = item.second;
			if(item.second != last && item.first <= year){
				history.push_back(item.second);
				last = item.second;
			}
		} else {
			// иначе пора остановиться, так как эта запись и все последующие относятся к будущему
			break;
		}
	}
	if(history.size() > 1){
		string res = " (";
		for (int i = history.size()-2; i >=0 ; --i) {
			res += history[i];
			if(i != history.size()-1 && i != 0){
				res +=", ";
			}
		}
		res += ")";
		name += res;
	}
	return name;
}

class Person {
public:
	void ChangeFirstName(int year, const string & first_name) {
		first_names[year] = first_name;
	}
	void ChangeLastName(int year, const string & last_name) {
		last_names[year] = last_name;
	}
	string GetFullName(int year) {
		// получаем имя и фамилию по состоянию на год year
		const string first_name = FindNameByYear(first_names, year);
		const string last_name = FindNameByYear(last_names, year);

		// если и имя, и фамилия неизвестны
		if (first_name.empty() && last_name.empty()) {
			return "Incognito";

			// если неизвестно только имя
		} else if (first_name.empty()) {
			return last_name + " with unknown first name";

			// если неизвестна только фамилия
		} else if (last_name.empty()) {
			return first_name + " with unknown last name";

			// если известны и имя, и фамилия
		} else {
			return first_name + " " + last_name;
		}
	}
	string GetFullNameWithHistory(int year) {
		// получаем имя и фамилию по состоянию на год year
		const string first_name = FindNameByYearHistory(first_names, year);
		const string last_name = FindNameByYearHistory(last_names, year);

		// если и имя, и фамилия неизвестны
		if (first_name.empty() && last_name.empty()) {
			return "Incognito";

			// если неизвестно только имя
		} else if (first_name.empty()) {
			return last_name + " with unknown first name";

			// если неизвестна только фамилия
		} else if (last_name.empty()) {
			return first_name + " with unknown last name";

			// если известны и имя, и фамилия
		} else {
			return first_name + " " + last_name;
		}
	}

private:
	map<int, string> first_names;
	map<int, string> last_names;
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
	test_3();
	return 0;
}