#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Qfloat
{
	int* data = new int[4];
public:
	Qfloat();
	bool getBit(int index);
	void setBit(int index, bool bit);
	void ScanQfloat();
	void PrintQfloat();
	string BinToDec(string);
	string DecToBin(string);	 
	Qfloat operator=(Qfloat x);
};

