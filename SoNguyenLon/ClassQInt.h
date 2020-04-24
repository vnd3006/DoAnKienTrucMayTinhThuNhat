#pragma once
#include <iostream>

using namespace std;

class QInt
{

private:
	int data[4];
public:
	QInt();
	void ScanQInt(QInt& x);
	void PrintQInt(QInt& x);
	bool* DecToBin(QInt x);
	QInt BinToDec(bool* bit);
	char* BinToHex(bool* bit);
	char* DecToHex(QInt x);
	QInt operator+(const QInt& x);
	QInt operator-(const QInt& x);
	QInt operator*(const QInt& x);
	QInt operator/(const QInt& x);

};

