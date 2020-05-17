#include <iostream>
#include <vector>
#include <limits>
using namespace std;

enum class SomeEnum {
	VALUE
};

void test_1(){
	vector<int> t = {-4, 5, -12};
	int sum = 0;
	for (const int & item: t){
		sum += item;
	}
	cout << sum / t.size() << endl;

}

void test_2(){
	int x = 2'000'000'000;
	cout << x << endl;
	x*= 2;
	cout << x << endl;
}

void test_3(){
	cout << "int8_t " << sizeof(int8_t) << endl;
	cout << "uint8_t " << sizeof(uint8_t) << endl;

	cout << "int16_t " << sizeof(int16_t) << endl;
	cout << "uint16_t " << sizeof(uint16_t) << endl;

	cout << "int32_t " << sizeof(int32_t) << endl;
	cout << "uint32_t " << sizeof(uint32_t) << endl;

	cout << "int64_t " << sizeof(int64_t) << endl;
	cout << "uint64_t " <<sizeof(uint64_t) << endl;

	cout << "int " << sizeof(int) << endl;
	cout << "unsigned " <<sizeof(unsigned) << endl;
}

void test_4(){
	cout << numeric_limits<int>::max() + 1 << endl;
	cout << numeric_limits<int>::min() - 1 << endl;
}

void test_5(){
	int x = 2'000'000'000;
	int y = 2'000'000'000;
	cout << (x+y)/2 << endl;
}

void test_6(){
	uint64_t x = 2'000'000'000;
	uint64_t y = 2'000'000'000;
	cout << (x+y)/2 << endl;
}

void test_7(){
	int64_t x = 2'000'000'000;
	int64_t y = 2'000'000'000;
	cout << (x+y)/2 << endl;
}

void test_8(){
	unsigned int x = 2'000'000'000;
	unsigned int y = 2'000'000'000;
	cout << (x+y)/2 << endl;
}

void test_9(){
	int32_t x = 2'000'000'000;
	int32_t y = 2'000'000'000;
	cout << (x+y)/2 << endl;
}

void test_10(){
	int x = 2'000'000'000;
	unsigned int y = x;
	cout << x << " " << y << endl;
}

void test_11(){
	vector<int> t = {-4, 5, -12};
	int sum = 0;
	for (const int & item: t){
		sum += item;
	}
	cout << sum / static_cast<int>(t.size()) << endl;
}

void test_12(){
	vector<int> vec = {-4, 5, -12};
	for (size_t i = 0; i < vec.size(); ++i) {
		cout << i << " " << vec[i] << endl;
	}
	for (int i = 0; i < static_cast<int>(vec.size()); ++i) {
		cout << i << " " << vec[i] << endl;
	}
}

void test_13(){
	vector<int> vec = {1, 32, 5};
	for (size_t i = 0; i < vec.size() - 1; ++i) {
		cout << vec[i] << " ";
	}
	/** segfault **/
	vector<int> vec1 = {};
	for (size_t i = 0; i + 1 < vec1.size(); ++i) {
		cout << vec[i] << " ";
	}
}

int main() {
	test_3();
}