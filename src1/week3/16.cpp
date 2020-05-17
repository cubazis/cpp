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
	Person(const string& first, const string& second, const int& year) {
		myFirst = first;
		mySecond = second;
		myYear = year;
		ChangeFirstName(year, first);
		ChangeLastName(year, second);
	}

	void ChangeFirstName(int year, const string & first_name) {
		if(year >= myYear){
			first_names[year] = first_name;
		}

	}
	void ChangeLastName(int year, const string & last_name) {
		if(year >= myYear){
			last_names[year] = last_name;
		}
	}
	string GetFullName(int year) const {
		if(year < myYear){
			return "No person";
		}
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
	string GetFullNameWithHistory(int year) const {
		if(year < myYear){
			return "No person";
		}
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
	string myFirst;
	string mySecond;
	int myYear;
};

int main() {
	Person person("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for (int year : {1965, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	return 0;
}

/*
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

vector<string> FindNamesHistory(const map<int, string>& names_by_year,
                                int year) {
  vector<string> names;
  for (const auto& item : names_by_year) {
    if (item.first <= year && (names.empty() || names.back() != item.second)) {
      names.push_back(item.second);
    }
  }
  return names;
}

string BuildJoinedName(vector<string> names) {
  reverse(begin(names), end(names));
  string joined_name = names[0];
  for (int i = 1; i < names.size(); ++i) {
    if (i == 1) {
      joined_name += " (";
    } else {
      joined_name += ", ";
    }
    joined_name += names[i];
  }
  if (names.size() > 1) {
    joined_name += ")";
  }
  return joined_name;
}

class Person {
public:
  // конструктор
  Person(const string& first_name, const string& last_name,
         int new_birth_year) {
    birth_year = new_birth_year;
    first_names[birth_year] = first_name;
    last_names[birth_year] = last_name;
  }
  void ChangeFirstName(int year, const string& first_name) {
    // игнорируем запись, если год меньше года рождения
    if (year >= birth_year) {
      first_names[year] = first_name;
    }
  }
  void ChangeLastName(int year, const string& last_name) {
    if (year >= birth_year) {
      last_names[year] = last_name;
    }
  }
  string GetFullName(int year) const {
    // обрабатываем случай, когда год меньше года рождения
    if (year < birth_year) {
      return "No person";
    }
    const vector<string> first_names = FindFirstNamesHistory(year);
    const vector<string> last_names = FindLastNamesHistory(year);
    // объединяем имя и фамилию через пробел
    return first_names.back() + " " + last_names.back();
  }
  string GetFullNameWithHistory(int year) const {
    if (year < birth_year) {
      return "No person";
    }
    const string first_name = BuildJoinedName(FindFirstNamesHistory(year));
    const string last_name = BuildJoinedName(FindLastNamesHistory(year));
    return first_name + " " + last_name;
  }
private:
  vector<string> FindFirstNamesHistory(int year) const {
    return FindNamesHistory(first_names, year);
  }
  vector<string> FindLastNamesHistory(int year) const {
    return FindNamesHistory(last_names, year);
  }

  int birth_year;
  map<int, string> first_names;
  map<int, string> last_names;
};
 */