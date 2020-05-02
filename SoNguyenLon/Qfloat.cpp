#include "Qfloat.h"

string reverse(string s) {
	string result;
	for (int i = s.length() - 1; i >= 0; i--) {
		result += s[i];
	}
	return result;
}
string nhan2(string so) {
	int temp = 0;
	string s;
	for (int i = so.length() - 1; i >= 0; i--) {
		if (so[i] != '.') {
			int num = so[i] - '0';
			s += (num * 2 + temp) % 10 + '0';
			temp = (temp + num * 2);
			if (temp >= 10) {
				temp = temp / 10;
			}
			else {
				temp = 0;
			}
		}
		else {
			s += '.';
		}
	}
	if (temp > 0) {
		s += (temp + '0');
	}
	s = reverse(s);

	//Kiem tra phai so thap phan khong
	int check = s.find('.');
	if (check > 0) {
		//Xoa so 0
		int index = -1;
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] != '0') {
				index = i;
				break;
			}
		}
		if (index != -1)
		{
			if (s[index] == '.')
				s = s.substr(0, index);
			else
				s = s.substr(0, index + 1);
		}
	}
	return s;
}
string chia2(string nguyen) {
	string s;
	int temp = 0;
	if ((nguyen[0] == '1' || nguyen[0] == '0') && nguyen.length() == 1)
		return "0";
	for (int i = 0; i < nguyen.length(); i++) {
		int num = nguyen[i] - '0';
		temp = num + temp * 10;
		if (temp >= 2) {
			s += temp / 2 + '0';
			temp = temp - temp / 2 * 2;
		}
		else if (i == nguyen.length() - 1)
			s += '0';
	}
	return s;
}
string chia2_thapphan(string so) {
	string s;
	int temp = 0;
	bool check = false;
	for (int i = 0; i < so.length(); i++) {
		if (so[i] != '.')
		{
			int num = so[i] - '0';
			temp = num + temp * 10;
			if (temp >= 2) {
				s += temp / 2 + '0';
				temp = temp - temp / 2 * 2;
			}
			else
			{
				if (i < so.length()) {
					s += '0';
				}
			}
		}
		else
		{
			check = true;
			if (s.length() == 0) {
				s = "0.";
			}
			else
				s += '.';
		}
	}
	if (temp > 0) {
		if (check) {
			s += '5';
		}
		else
			s += ".5";
	}
	return s;
}
Qfloat::Qfloat() {
	data[0] = data[1] = data[2] = data[3] = data[4] = 0;
}
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
void Qfloat::ScanQfloat()
{
	string num;
	cin >> num;
	//Dua bit vao data
	string result = DecToBin(num);
	for (int i = 0; i < 128; i++) {
		if (result[0] - '0' == 0) {
			setBit(i, 0);
		}
		else {
			setBit(i, 1);
		}
	}
}

void Qfloat::PrintQfloat(Qfloat x)
{
}

Qfloat Qfloat::BinToDec(int* data)
{
	
}

string Qfloat::DecToBin(string num)
{
	//Chuyen phan nguyen qua nhi phan
	//Vi tri dau "." trong chuoi num
	int index = num.find('.');
	string nguyen;
	if (num[0] == '-')
		nguyen = num.substr(1, index - 1);
	else
		nguyen = num.substr(0, index);
	string np_nguyen = "";
	while (nguyen != "0") {
		if ((nguyen[nguyen.length() - 1] - '0') % 2 == 0) {
			np_nguyen = '0' + np_nguyen;
		}
		else {
			np_nguyen = '1' + np_nguyen;
		}
		nguyen = chia2(nguyen);
	}
	if (np_nguyen.length() == 0)
		np_nguyen += '0';
	//Chuyen phan thap phan qua nhi phan
	string np_tp = "";
	string thapphan = "0" + num.substr(index);
	while (1) {
		thapphan = nhan2(thapphan);
		if (thapphan[0] < '1') {
			np_tp += '0';
		}
		else {
			np_tp += '1';
			if (thapphan == "1") {
				break;
			}
			thapphan[0] = '0';
		}
	}

	//Luu vo bien np
	string np = np_nguyen + "." + np_tp;
	cout << np << endl;
	//
	string s = "";
	string e = "";
	string m = "";
	if (num[0] == '	-')
		s += '1';
	else
		s += '0';

	//vi tri dau "." trong chuoi nhi phan
	int index1 = np.find('.');
	//Chuyen e ra nhi phan
	string _e = "";
	int somu;
	if (index1 == 1)
	{
		for (int j = 2; j < np.length(); j++) {
			if (np[j] == '1') {
				somu = index1 - j + 127;//16383;
				break;
			}
		}
	}
	else {
		somu = index1 - 1 + 127;// 16383;
	}
	//Dung bien temp de tinh phan tri
	int temp = somu - 127;
	//Chuyen so mu qua nhi phan roi dua vao chuoi e
	while (somu != 0) {
		char x = somu % 10 + '0';
		_e = x + _e;
		somu = somu / 10;
	}
	while (_e != "0") {
		if ((_e[_e.length() - 1] - '0') % 2 == 0) {
			e = '0' + e;
		}
		else {
			e = '1' + e;
		}
		_e = chia2(_e);
	}
	//Chua du 15 bit thi them 0 vao de du 15 bit
	if (e.length() < 15) {
		int n = e.length();
		for (int i = 0; i < 15 - n; i++) {
			e = '0' + e;
		}
	}

	//Luu phan tri m
	int temp2 = index1 - temp;
	if (temp < 0)
		temp2++;
	for (int i = temp2; i < np.length(); i++) {
		if (np[i] != '.')
			m += np[i];
	}
	//Neu khong du 112 bit thi them '0' vao cho du 
	if (m.length() < 112) {
		int n = m.length();
		for (int i = 0; i < 112 - n; i++) {
			m += '0';
		}
	}
	return s + " " + e + " " + m;
}
