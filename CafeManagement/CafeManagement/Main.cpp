#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

void main(void)
{
	ifstream inFile("output.txt");

	while (!inFile.eof()) {
		inFile.getline(inputString, 100);
		cout << inputString << endl;
	}
	inFile.close();
}