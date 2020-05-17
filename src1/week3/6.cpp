#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void print(const vector<string> & v){
	for (const auto & i: v) {
		cout << i << " ";
	}
	cout << endl;
}

bool compare(string a, string b){
	transform(a.begin(), a.end(), a.begin(), ::tolower);
	transform(b.begin(), b.end(), b.begin(), ::tolower);
	if(a < b){
		return true;
	}
	return false;
}

int main() {
	size_t N;
	cin >> N;
	vector<string> v;
	string x;
	for (size_t i = 0; i < N; ++i) {
		cin >> x;
		v.push_back(x);
	}
	sort(begin(v), end(v), compare);
	print(v);
}

/*
int main() {
  // считываем вектор строк
  int n;
  cin >> n;
  vector<string> v(n);
  for (string& s : v) {
    cin >> s;
  }

  // сортируем
  sort(begin(v), end(v),
       // компаратор для сортировки — лямбда-функция, сравнивающая строки без учёта регистра
       [](const string& l, const string& r) {
         // сравниваем лексикографически...
         return lexicographical_compare(
             // ... все символы строки l ...
             begin(l), end(l),
             // ... со всеми символами строки r ...
             begin(r), end(r),
             // ..., используя в качестве компаратора сравнение отдельных символов без учёта регистра
             [](char cl, char cr) { return tolower(cl) < tolower(cr); }
         );
       }
  );

  // выводим отсортированный вектор
  for (const string& s : v) {
    cout << s << ' ';
  }

  return 0;
}
 */