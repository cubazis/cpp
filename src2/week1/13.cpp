#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <chrono>
using namespace std;

enum class Lang {
	DE, FR, IT
};

ostream& operator << (ostream& output, const Lang & lang)
{
	if(lang == Lang::DE){
		output << "DE";
	}
	if(lang == Lang::FR){
		output << "FR";
	}
	if(lang == Lang::IT){
		output << "IT";
	}
	//output << static_cast<std::underlying_type<Lang>::type>(lang);
	return output;
}

ostream& operator << (ostream& output, const map<Lang, string> & map)
{
	for (const auto & item:map) {
		output << item.first << ": " << item.second << endl;
	}
	return output;
}

struct Region {
	string std_name;
	string parent_std_name;
	map<Lang, string> names;
	int64_t population;
};

int main() {
	auto start = std::chrono::high_resolution_clock::now();

	map<Lang, string> m1 = {{Lang::DE, "A"}, {Lang::DE, "B"}};
	map<Lang, string> m2 = {{Lang::DE, "A"}, {Lang::DE, "B"}};
	cout << m1 << endl;
//	cout << (m1 == m2) << endl;
//	cout << (m1 < m2) << endl;
//	cout << (m1 > m2) << endl;


	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "Elapsed time: " << elapsed.count() << " s\n";
	return 0;
}

void test_1(){
	cout << (Lang::DE < Lang::FR) << endl;
	cout << (Lang::FR < Lang::IT) << endl;
	cout << endl;
	cout << (pair{Lang::DE, "A"} == pair{Lang::DE, "A"}) << endl;
	cout << endl;
	cout << (pair{Lang::DE, "A"} == pair{Lang::DE, "B"}) << endl;
	cout << (pair{Lang::DE, "A"} < pair{Lang::DE, "B"}) << endl;
	cout << (pair{Lang::DE, "A"} > pair{Lang::DE, "B"}) << endl;
	cout << endl;
	cout << (pair{Lang::DE, "A"} == pair{Lang::FR, "A"}) << endl;
	cout << (pair{Lang::DE, "A"} < pair{Lang::FR, "A"}) << endl;
	cout << (pair{Lang::DE, "A"} > pair{Lang::FR, "A"}) << endl;
	cout << endl;

}