#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		firsts[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		lasts[year] = last_name;
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
	void print(){
		for (const auto & [year, first]:firsts) {
			cout << year << " " << first << "; ";
		}
		cout << endl;
		for (const auto & [year, last]:lasts) {
			cout << year << " " << last << "; ";
		}
		cout << endl;

	}
private:
	map<int, string> firsts;
	map<int, string> lasts;
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
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	//person.print();
	person.ChangeLastName(1967, "Sergeeva");
	//person.print();
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}

/*
// если имя неизвестно, возвращает пустую строку
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

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
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

private:
  map<int, string> first_names;
  map<int, string> last_names;
};
 */