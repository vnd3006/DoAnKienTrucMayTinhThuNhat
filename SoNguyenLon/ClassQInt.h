#pragma once
#include <iostream>

using namespace std;

class QInt
{

private:
	int data[4];
public:
	QInt();
	void ScanQInt();
	void PrintQInt();
	bool* DecToBin();
	QInt BinToDec(bool* bit);
	char* BinToHex(bool* bit);
	char* DecToHex();
	QInt operator+(const QInt& x);
	QInt operator-(const QInt& x);
	QInt operator*(const QInt& x);
	QInt operator/(const QInt& x);

};

