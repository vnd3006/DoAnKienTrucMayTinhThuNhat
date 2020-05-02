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
	for (int i = 0; i < nguyen.length(); i++) {
		int num = nguyen[i] - '0';
		temp = num + temp * 10;
		if (temp >= 2) {
			s += temp / 2 + '0';
			temp = temp - temp / 2 * 2;
		}
		else if (temp < 2 && i == nguyen.length() - 1)
			return "0";
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
	int index = num.find('.');
	if (index < 0)
	{
		num += ".0";
	}
	index = num.find('.');
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

	string np_tp = "";
	string thapphan = "0" + num.substr(index);
	while (thapphan != "0") {
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
	string np = np_nguyen + "." + np_tp;
	cout << np << endl;
	//vi tri dau "."
	int index1 = np.find('.');
	//
	string s = "";
	string e = "";
	string m = "";
	if (num[0] == '-')
		s += '1';
	else
		s += '0';
	//Chuyen e ra nhi phan
	string _e = "";
	int i = index1 - 1 + 127;
	
	while (i != 0) {
		char x = i % 10 + '0';
		_e = x + _e;
		i = i / 10;
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
	if (e.length() < 15) {
		int n = e.length();
		for (int i = 0; i < 15 - n; i++) {
			e = '0' + e;
		}
	}
	//

	for (int i = 1; i < np.length(); i++) {
		if (np[i] != '.')
			m += np[i];
	}
	if (m.length() < 112) {
		int n = m.length();
		for (int i = 0; i < 112 - n; i++) {
			m += '0';
		}
	}

	//Dua bit vao data
	string result = s + e + m;
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

//Qfloat Qfloat::BinToDec(int* data)
//{
//	
//
//}

//string Qfloat::DecToBin(Qfloat x)
//{
//	
//}
