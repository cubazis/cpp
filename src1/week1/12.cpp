#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	double a;
	double b;
	double c;
	cin >> a >> b >> c;
	vector<double> vec = {a, b, c};
	double D = b*b - 4*a*c;
	if(a == 0 && b == 0){
		cout << " " << endl;
	}else if(a == 0){
		cout << -c/b  << endl;
	}else if(D > 0){
		double x1 = (-b - sqrt(D))/(2*a);
		double x2 = (-b + sqrt(D))/(2*a);
		cout << x1 << " " << x2 << endl;
	} else if(D == 0){
		double x1 = -b/(2*a);
		cout << x1 << endl;
	} else{
		cout << " " << endl;
	}}