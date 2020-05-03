#include "Qfloat.h"
bool KTraBitGiongNhau(string s, char c)
{
	for (int i = 0; i < s.size(); i++)
		if (s[i] != c)
			return false;
	return true;
}
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
string Cong(string a, string b)
{
	int i = a.size() - 1;
	int j = b.size() - 1;
	string KetQua = "";
	int temp = 0;
	while (i >= 0 || j >= 0)
	{
		int x = (i >= 0) ? a[i] - '0' : 0;
		int y = (j >= 0) ? b[j] - '0' : 0;
		int Tong = x + y + temp;
		temp = Tong / 10;
		KetQua = (char)(Tong % 10 + '0') + KetQua;
		if (i >= 0)
			i--;
		if (j >= 0)
			j--;
	}
	if (temp > 0)
		KetQua = (char)(temp + '0') + KetQua;
	return KetQua;
}
void ChuanHoa(string &a, string &b)
{
	int dodai1 = a.size();
	int dodai2 = b.size();
	if (dodai1 >= dodai2)
	{
		b.insert(0, dodai1 - dodai2, '0');
	}
	else
	{
		a.insert(0, dodai2 - dodai1, '0');
	}
}
void ChuanHoaSo0(string &a)
{
	int i = 0;
	if (a[i] == '0')
	{
		if (a == "0") return;
		while (a[i] == '0')
		{
			a.erase(a.begin() + i);
		}
	}
	else
		return;
}
void ChuanHoaBit(string &a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == ' ')
		{
			a.erase(a.begin() + i);
		}
	}
}
void ChuanHoaTP(string &a, string &b)
{
	int dodai1 = a.size();
	int dodai2 = b.size();
	if (dodai1 >= dodai2)
	{
		while (dodai1 > dodai2)
		{
			b += '0';
			dodai2++;
		}
	}
	else
	{
		while (dodai2 > dodai1)
		{
			a += '0';
			dodai1++;
		}
	}
}
string CongTP(string a, string b)
{
	string KetQua = "";
	ChuanHoaTP(a, b);
	int temp = 0;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		if (a[i] == '.')
		{
			KetQua = '.' + KetQua;
		}
		else
		{
			temp = a[i] - '0' + b[i] - '0' + temp;
			KetQua.insert(0, 1, (char)(temp % 10 + 48));
			temp /= 10;
		}
	}
	if (temp > 0)
	{
		KetQua.insert(0, 1, (char)(temp + 48));
	}
	return KetQua;
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
string Qfloat::BinToDec(string s)
{
	ChuanHoaBit(s);
	if (s.size() != 32) //128
		return "Du lieu sai!";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != '0' && s[i] != '1')
			return "Du lieu sai!";
	}

	string Sign = s.substr(0, 1);
	string Exp = s.substr(1, 8); //1, 15
	string M = s.substr(9, 23);// 16,112
	string Dau = "";
	if (Sign == "1")
		Dau = "-";
	//Kiểm tra trường hợp đặc biệt
	if (KTraBitGiongNhau(Exp, '0'))
	{
		if (KTraBitGiongNhau(M, '0'))
		{
			return "0";
		}
		else
		{
			return "So khong the chuan hoa!";
		}
	}
	if (KTraBitGiongNhau(Exp, '1'))
	{
		if (KTraBitGiongNhau(M, '0'))
		{
			return "So vo cung!";
		}
		else
		{
			return "So bao loi!";
		}
	}

	//Tính giá trị Exp;
	string ExpDec = "0";
	string temp = "1";
	if (Exp[Exp.size() - 1] == '1')
		ExpDec = "1";
	for (int i = Exp.size() - 2; i >= 0; i--)
	{
		temp = nhan2(temp);
		if (Exp[i] == '1')
		{
			ExpDec = Cong(ExpDec, temp);
		}
	}
	//CHuyển giá trị sang int 
	int _Exp = 0;
	for (int i = 0; i < ExpDec.size(); i++)
	{
		_Exp = _Exp * 10 + ExpDec[i] - '0';
	}
	int E = _Exp - 127;//K

	//Tìm phần nguyên và phần thập phân ở hệ 2
	string IntBin = "1";
	string FracBin = M;
	while (E != 0)
	{
		if (E > 0)
		{
			IntBin += FracBin[0];
			FracBin.erase(0, 1);
			FracBin += '0';
			E--;
		}
		else
		{
			FracBin = IntBin[IntBin.size() - 1] + FracBin;
			IntBin.erase(IntBin.size() - 1, 1);
			IntBin = '0' + IntBin;
			E++;
		}
	}
	//Xóa số 0 dư trước phần nguyên và số 0 dư sau phần thập phân
	ChuanHoaSo0(IntBin);
	while (FracBin.size() > 1 && FracBin[FracBin.size() - 1] == '0')
		FracBin.erase(FracBin.size() - 1, 1);

	//Chuyển phần nguyên sang hệ 10
	string IntDec = "0";
	temp = "1";
	if (IntBin[IntBin.size() - 1] == '1')
		IntDec = "1";
	if (IntBin.size() > 1)
	{
		for (int i = IntBin.size() - 2; i >= 0; i--)
		{
			temp = nhan2(temp);
			if (IntBin[i] == '1')
			{
				IntDec = Cong(IntDec, temp);
			}
		}
	}
	//Chuyển phần thập phân sang hệ 10
	string FracDec = "0.0";
	temp = "1";
	for (int i = 0; i < FracBin.size(); i++)
	{
		temp = chia2_thapphan(temp);
		if (FracBin[i] == '1')
		{
			FracDec = CongTP(FracDec, temp);
		}
	}
	FracDec = FracDec.substr(2, FracDec.size() - 2);
	string KetQua = "";
	if (FracDec == "0")
		KetQua = IntDec;
	else
		KetQua = Dau + IntDec + '.' + FracDec;
	return KetQua;
}

void Qfloat::PrintQfloat()
{
	string s = "";
	for (int i = 0; i < 128; i++)
	{
		if (getBit(i))
		{
			s += '1';
		}
		else
			s += '0';
	}
	string KetQua = BinToDec(s);
	cout << KetQua << endl;
}
Qfloat Qfloat::operator=(Qfloat x)
{
	for (int i = 0; i < 4; i++)
		this->data[i] = x.data[i];
	return *this;
}
