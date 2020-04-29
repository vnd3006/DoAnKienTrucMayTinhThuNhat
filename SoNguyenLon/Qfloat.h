#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Qfloat
{
	int* data = new int [4];
	bool getBit(int index);
	void setBit(int index, bool bit);
	void ScanQfloat(Qfloat& );
	void PrintQfloat(Qfloat );
	Qfloat BinToDec(int*);
	string DecToBin(Qfloat);
};

