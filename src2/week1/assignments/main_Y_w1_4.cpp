#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

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
	if (size == 0){
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