#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class QInt
{

private:
	int data[4];
	//Vector binData luu tru so QInt o dang nhi phan
	vector<bool> binData;
public:
	QInt();
	void ScanQInt();
	void PrintQInt();
	vector<bool> DecToBin(string s);
	string BinToDec(vector<bool> bit);
	string BinToHex(vector<bool> bit);
	string DecToHex(string s);
	QInt operator+(const QInt& x);
	QInt operator-(const QInt& x);
	QInt operator*(const QInt& x);
	//Cap gia tri QInt tra ve trong phep chia la cap thuong va so du
	pair<QInt, QInt> operator/(const QInt& x);

};

