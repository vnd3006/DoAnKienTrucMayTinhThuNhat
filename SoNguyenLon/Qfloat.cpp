#include "Qfloat.h"

bool Qfloat::getBit(int index)
{
	return (data[index / 32] >> (31 - index % 32)) & 1;
}

void Qfloat::setBit(int index, bool bit)
{
	if (bit == 0)
		data[index / 32] = (~(1 << (31 - index))) & data[index / 32];
	else
		data[index / 32] = (1 << (31 - index)) | data[index / 32];

}

string Chia(string nguyen) {
	if (nguyen == "0")
		return "0";
	else {
		vector<int> s;
		int temp = 0;
		for (int i = 0; i < nguyen.length(); i++) {
			int num = nguyen[i] - '0';
			temp = num % 2 + temp * 10;
			if (temp % 2 == 0) {
				temp = 0;
				s.push_back(0);
			}
			else {
				s.push_back(1);
			}
		}
	}
}
void Qfloat::ScanQfloat(Qfloat& x)
{
	string num;
	cout << "Nhap so thuc: ";
	cin >> num;
	int index = num.find('.');
	string nguyen = num.substr(0,index);
	
	string thapphan = num.substr(index+1);
}

void Qfloat::PrintQfloat(Qfloat x)
{
}

Qfloat Qfloat::BinToDec(int* data)
{
	
}

string Qfloat::DecToBin(Qfloat x)
{
	
}
