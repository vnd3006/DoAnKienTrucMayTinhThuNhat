#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class QInt
{

private:
	int data[4];
public:
	QInt();
	bool getBit(int i);
	void setBit(int i, bool bit);
	void convertDecToQInt(string s);
	string convertQIntToDec();
	vector<bool> convertDecToBin(string s);
	string convertBinToDec(vector<bool> bit);
	string convertBinToHex(vector<bool> bit);
	string convertDecToHex(string s);
	QInt operator+(QInt x);
	QInt operator-(QInt x);
	QInt operator*(QInt x);
	//Cap gia tri QInt tra ve trong phep chia la cap thuong va so du
	pair<QInt, QInt> operator/(QInt x);
	QInt operator<(QInt x);
	QInt operator>(QInt x);
	QInt operator==(QInt x);
	QInt operator<=(QInt x);
	QInt operator>=(QInt x);
	QInt operator=(QInt x);
	QInt operator&(QInt x);
	QInt operator|(QInt x);
	QInt operator^(QInt x);
	QInt operator~();
	QInt operator<<(int k);
	QInt operator>>(int k);
	QInt rol();
	QInt ror();

	void ScanQInt();
	void PrintQInt();
};

