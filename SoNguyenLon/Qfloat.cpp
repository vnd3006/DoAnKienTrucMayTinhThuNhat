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
string reverse(string s) {
	string result;
	for (int i = s.length() - 1; i >= 0; i--) {
		result += s[i];
	}
	return result;
}

string Nhan2(string thapphan) {
	int temp = 0;
	string s;
	for (int i = thapphan.length() - 1; i > 1; i--) {
		int num = thapphan[i] - '0';
		s += (num * 2 + temp) % 10 + '0';
		temp = (temp + num * 2);
		if (temp >= 10) {
			temp = temp / 10;
		}
		else {
			temp = 0;
		}
	}
	if (temp > 0) {
		s += temp + '0';
	}
	s = reverse(s);
	int lui = thapphan.length() - 2;
	if (lui < s.length()) {
		string _s = s.substr(0, s.length() - lui) + '.' + s.substr(s.length() - lui);
		s = _s;
	}
	else if (lui == s.length()) {
		string _s = "0." + s;
		s = _s;
	}
	else {
		int so0 = lui - s.length();
		string _s = "0.";
		for (int i = 1; i <= so0; i++) {
			_s += '0';
		}
		_s += s;
		s = _s;
	}
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
	return s;
}
string Chia2(string nguyen) {
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
	cin >> num;
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
		nguyen = Chia2(nguyen);
	}

	string np_tp = "";
	string thapphan = "0" + num.substr(index);
	while (1) {
		thapphan = Nhan2(thapphan);
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
		_e = Chia2(_e);
	}
	for (int i = 1; i < np.length(); i++) {
		if (np[i] != '.')
			m += np[i];
	}
	//
	cout << s + " " + e + " " + m;
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
