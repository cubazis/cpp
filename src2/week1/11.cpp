#include <iostream>
#include <tuple>
#include <utility>
#include <set>
#include <map>
using namespace std;

class Cities {
public:
	tuple<bool, string> FindCountry(const string & city) const {
		if(city_to_country.count(city) == 1){
			return {true, city_to_country.at(city)};
		}else if(ambiguous_cities.count(city) == 1){
			return {false, "Ambiguous"};
		} else {
			return {false, "Not exist"};
		}
	}

private:
	map<string, string> city_to_country;
	set<string> ambiguous_cities;
};

int main() {
	Cities c;
	bool succ;
	string message;
	/** хранит ссылки на объекты */
	tie(succ, message) = c.FindCountry("Volgograd");
	cout << succ << " " << message << endl;
	/** статический биндинг */
	auto [succ1, message1] =  c.FindCountry("Moscow");
	cout << succ1 << " " << message1 << endl;
	return 0;
}