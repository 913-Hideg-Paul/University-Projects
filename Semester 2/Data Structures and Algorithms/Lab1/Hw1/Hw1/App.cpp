#include "Bag.h"
#include "ShortTest.h"
#include "ExtendedTests.h"
#include <iostream>

using namespace std;

int main() {

	testAll();
	cout << "Short tests over" << endl;
	testAllExtended();
	cout << "Extended tests over" << endl;
	cout << "Good!"<<endl;
}