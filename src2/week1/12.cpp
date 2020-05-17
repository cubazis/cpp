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
struct Region {
	string std_name;
	string parent_std_name;
	map<Lang, string> names;
	int64_t population;
};

//bool operator == (const Region & one, const Region & two){
//	if(one.std_name != two.std_name){
//		return false;
//	}
//	if(one.parent_std_name != two.parent_std_name){
//		return false;
//	}
//	if(one.population != two.population){
//		return false;
//	}
//	return one.names == two.names;
//}

bool operator == (const Region & one, const Region & two){
	return tie(
		one.std_name,
		one.parent_std_name,
		one.names,
		one.population
	) ==
	       tie(
		       two.std_name,
		       two.parent_std_name,
		       two.names,
		       two.population
	       );
}

bool operator > (const Region & one, const Region & two){
	return tie(
		one.std_name,
		one.parent_std_name,
		one.names,
		one.population
	) >
	       tie(
		       two.std_name,
		       two.parent_std_name,
		       two.names,
		       two.population
	       );
}

bool operator < (const Region & one, const Region & two){
	return tie(
		one.std_name,
		one.parent_std_name,
		one.names,
		one.population
	) <
	       tie(
		       two.std_name,
		       two.parent_std_name,
		       two.names,
		       two.population
	       );
}



int FindMaxRepetitionCount(const vector<Region>& regions){
	int max = 0;
	int rep_count = 1;
	size_t size = regions.size();
	if (!size){
		return 0;
	}
	vector<Region> vec = regions;
	sort(vec.begin(), vec.end());
	for(size_t i = 1; i < size; i++){
		if (vec[i] == vec[i-1]) {
			rep_count++;
		} else {
			rep_count = 1;
		}
		if (rep_count > max) {
			max = rep_count;
		}
	}
	return max;
}

int main() {
	cout << FindMaxRepetitionCount({}) << endl;
	cout << FindMaxRepetitionCount({{
		                                "Moscow",
		                                "Russia",
		                                {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
		                                89
	                                }}) << endl;
	cout << FindMaxRepetitionCount({
		                               {
			                               "Moscow",
			                               "Russia",
			                               {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
			                               89
		                               }, {
			                               "Russia",
			                               "Eurasia",
			                               {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
			                               89
		                               }, {
			                               "Moscow",
			                               "Russia",
			                               {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
			                               89
		                               }, {
			                               "Moscow",
			                               "Russia",
			                               {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
			                               89
		                               }, {
			                               "Russia",
			                               "Eurasia",
			                               {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
			                               89
		                               },
	                               }) << endl;

	cout << FindMaxRepetitionCount({
		                               {
			                               "Moscow",
			                               "Russia",
			                               {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
			                               89
		                               }, {
			                               "Russia",
			                               "Eurasia",
			                               {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
			                               89
		                               }, {
			                               "Moscow",
			                               "Russia",
			                               {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
			                               89
		                               }, {
			                               "Moscow",
			                               "Toulouse",
			                               {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
			                               89
		                               }, {
			                               "Moscow",
			                               "Russia",
			                               {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
			                               31
		                               },
	                               }) << endl;

	Region r1 = {
		"Moscow",
		"Russia",
		{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
		89
	};
	Region r2 = {
		"Moscow",
		"Russia",
		{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
		88
	};
	Region r3 = {
		"Moscow",
		"Russia",
		{{Lang::DE, "Moskau"}, {Lang::DE, "Moscou"}, {Lang::IT, "Mosca"}},
		89
	};
	Region r4 = {
		"Moscow",
		"Russia",
		{{Lang::DE, "Moskau"}, {Lang::FR, "Mosco"}, {Lang::IT, "Mosca"}},
		89
	};
	int N = 250;
	vector<Region> vec;
	for (int i = 0; i < N; ++i) {
		vec.push_back(r1);
		vec.push_back(r2);
		vec.push_back(r3);
		vec.push_back(r4);
	}
	vec.push_back(r1);
	auto start = std::chrono::high_resolution_clock::now();
	cout << FindMaxRepetitionCount(vec) << endl;
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "Elapsed time: " << elapsed.count() << " s\n";
	return 0;
}
