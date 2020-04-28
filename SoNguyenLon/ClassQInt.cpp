#include "ClassQInt.h"

QInt::QInt()
{

	data[0] = data[1] = data[2] = data[3] = 0;

}

bool QInt::getBit(int i)
{

	return (data[i / 32] >> (31 - i % 32)) & 1;

}

void QInt::setBit(int i, bool bit)
{

	if (bit == 0)
		data[i / 32] = (!(1 << (31 - i))) & data[i / 32];
	else
		data[i / 32] = (1 << (31 - i)) | data[i / 32];

}

QInt QInt::reverseBit()
{

	QInt temp;
	for (int i = 0; i < 128; i++)
		temp.setBit(i, (this->getBit(i) + 1) % 2);
	return temp;

}

void QInt::convertDecToQInt(string s)
{



}

string QInt::convertQIntToDec()
{



}

vector<bool> QInt::convertDecToBin(string s)
{



}

string QInt::convertBinToDec(vector<bool> bit)
{



}

string QInt::convertBinToHex(vector<bool> bit)
{

	return convertDecToHex(convertBinToDec(bit));

}

string QInt::convertDecToHex(string s)
{

	/*string ans = "", s1;
	pair<QInt, QInt> temp;
	QInt a, b;
	b.convertDecToQInt("16");
	while (s != "0")
	{

		a.convertDecToQInt(s);
		temp = a / b;
		s1 = temp.second.convertQIntToDec(); //So du
		if (s1.length() == 1) //So du tu 0 den 9 (tuong ung tu 0 den 9 trong he hex)
			s = s1 + s;
		else //So du tu 10 den 15 (tuong ung tu A den F trong he hex)
			s = (char)(s1[1] + 'A' - '0') + s;
		s = temp.first.convertQIntToDec(); //Thuong

	}*/
	return s;

}

QInt QInt::operator+(QInt x)
{

	QInt temp;
	/*char nho = 0, s;
	for (int i = 0; i < 128; i++)
	{

		s = this->getBit(i) + x.getBit(i) + nho;
		if (s == 2)
		{

			temp.setBit(i, 0);
			nho = 1;

		}
		else if (s == 3)
		{

			temp.setBit(i, 1);
			nho = 1;

		}
		else
		{

			temp.setBit(i, nho);
			nho = 0;

		}

	}*/
	return temp;

}

QInt QInt::operator-(QInt x)
{

	//x dao bit de tao ra so bu 1 la a
	QInt a = x.reverseBit(), b;
	//b la so 1
	b.convertDecToQInt("1");
	//a la so bu 2 bang cach lay so bu 1 cong voi 1
	a = a + b;
	//- x bay gio tuong duong voi + a vi a la so doi cua x
	return *this + a;

}

QInt QInt::operator*(QInt x)
{

	QInt a, q = *this;
	bool q1 = 0, q0;
	a.convertDecToQInt("0");
	for (int i = 0; i < 128; i++)
	{

		q0 = q.getBit(127);
		if (q0 == 1 && q1 == 0)
			a = a - x;
		else if (q0 == 0 && q1 == 1)
			a = a + x;
		//Dich phai [A, Q, Q1] 1 don vi
		q1 = q0;
		q >> 1;
		q.setBit(0, a.getBit(127));
		a >> 1;

	}
	return q;

}

pair<QInt, QInt> QInt::operator/(QInt x)
{



}
