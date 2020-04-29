#include "ClassQInt.h"

QInt::QInt()
{

	data[0] = data[1] = data[2] = data[3] = 0;

}

// sobichia nhỏ

void ChuanHoa(string &a, string &b)
{
	int dodai1 = a.length();
	int dodai2 = b.length();
	if (dodai1 >= dodai2)
	{
		b.insert(0, dodai1 - dodai2, '0');
	}
	else
	{
		a.insert(0, dodai2 - dodai1, '0');
	}
}

// Bỏ các số 0 ở đầu
void ChuanHoaSo0(string &a)
{
	int i = 0;
	if (a[i] == '0')
	{
		while (a[i] == '0')
		{
			a.erase(a.begin() + i);

		}
	}
	else
		return;


}

void Cong(string a, string b, string &ketqua)
{
	ketqua = "";
	ChuanHoa(a, b);
	int temp = 0;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		temp = a[i] - '0' + b[i] - '0' + temp;
		ketqua.insert(0, 1, (char)(temp % 10 + 48));
		temp /= 10;
	}
	if (temp > 0)
	{
		ketqua.insert(0, 1, (char)(temp + 48));
	}
	ChuanHoaSo0(ketqua);
}

void Tru(string sotru, string sobitru, string &ketqua)
{
	ketqua = "";
	int length = sotru.size();
	while (sobitru.size() < length)
	{
		sobitru.insert(0, 1, '0');
	}

	int sodu = 0;
	int temp;
	for (int i = length - 1; i >= 0; i--)
	{
		if (sotru[i] < sobitru[i] + sodu)
		{
			ketqua.push_back((char)(sotru[i] - sobitru[i] - sodu + 10 + 48));
			sodu = 1;
		}
		else
		{
			ketqua.push_back((char)(sotru[i] - sobitru[i] - sodu + 48));
			sodu = 0;
		}
	}
	reverse(ketqua.begin(), ketqua.end());

	ChuanHoaSo0(ketqua);
}

void Nhan(string a, int b, string &ketqua)
{
	ketqua = "";
	int temp = 0;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		temp = b * (a[i] - '0') + temp;
		ketqua.insert(0, 1, (char)(temp % 10 + 48));
		temp /= 10;
	}
	if (temp > 0)
	{
		ketqua.insert(0, 1, (char)(temp + 48));
	}
	ChuanHoaSo0(ketqua);
}


// https://www.geeksforgeeks.org/divide-large-number-represented-string/ (ý tưởng phép chia)
void Chia(string sochia, int sobichia, string &ketqua)
{
	ketqua = "";
	int i = 0;
	int temp = sochia[i] - '0';
	while (temp < sobichia)
	{
		temp = temp * 10 + (sochia[++i] - '0');
	}
	while (i < sochia.size())
	{
		ketqua += (temp / sobichia) + '0';
		temp = (temp%sobichia) * 10 + sochia[++i] - '0';
	}
	if (ketqua.length() == 0)
	{
		ketqua = "0";
	}
	ChuanHoaSo0(ketqua);
}

void LuyThuaCua2(int somu, string &ketqua)
{
	ketqua = "2";
	for (int i = 0; i < somu - 1; i++)
	{
		Nhan(ketqua, 2, ketqua);
	}
	if (somu == 0)
		ketqua = "1";
	ChuanHoaSo0(ketqua);
}

bool QInt::getBit(int i)
{

	return (data[i / 32] >> (31 - i % 32)) & 1;

}

void QInt::setBit(int i, bool bit)
{

	if (bit == 0)
		data[i / 32] = (~(1 << (31 - i))) & data[i / 32];
	else
		data[i / 32] = (1 << (31 - i)) | data[i / 32];

}

void QInt::convertDecToQInt(string s)
{
	string temp = s;
	bool dau = 0;
	bool ok = 0;
	if (temp[0] == '-')
	{
		dau = 1;
		temp.erase(temp.begin());
	}
	int cuoi = temp[temp.size() - 1] - '0';
	int dem = 0;
	setBit(dem, cuoi % 2);
	if (dau == 1 && cuoi % 2 == 1)
	{
		ok = 1;
	}

	dem++;
	while (temp != "1")
	{
		Chia(temp, 2, temp);
		cuoi = temp[temp.size() - 1] - '0';
		if (ok == 1)
			setBit(dem, (cuoi + 1) % 2);
		else
			setBit(dem, (cuoi) % 2);
		if (dau == 1 && cuoi % 2 == 1)
			ok = 1;
		dem++;
	}

	while (dem < 128)
	{
		if (dau == 1 && ok == 1)
		{
			setBit(dem, 1);
		}
		else
		{
			setBit(dem, 0);
		}

		dem++;
	}



}

string QInt::convertQIntToDec()
{

	string ketqua = "0";
	vector<int> c;
	int dem;


	for (int i = 0; i < 127; i++)
	{
		bool bit = getBit(i);
		string b;
		LuyThuaCua2(i, b);
		Nhan(b, bit, b);
		Cong(ketqua, b, ketqua);
	}
	if (getBit(127) == 1)
	{
		string temp;
		LuyThuaCua2(127, temp);
		Tru(temp, ketqua, ketqua);
		ketqua.insert(0, 1, '-');
	}
	else
	{
		bool bit = getBit(127);
		string b;
		LuyThuaCua2(127, b);
		Nhan(b, bit, b);
		Cong(ketqua, b, ketqua);
	}


	return ketqua;

}

vector<bool> QInt::convertDecToBin(string s)
{

	vector<bool> rs;
	string temp = s;
	bool dau = 0;
	bool ok = 0;
	if (temp[0] == '-')
	{
		dau = 1;
		temp.erase(temp.begin());
	}
	int cuoi = temp[temp.size() - 1] - '0';
	int dem = 0;
	rs.push_back(cuoi % 2);
	if (dau == 1 && cuoi % 2 == 1)
	{
		ok = 1;
	}

	dem++;
	while (temp != "1")
	{
		Chia(temp, 2, temp);
		cuoi = temp[temp.size() - 1] - '0';
		if (ok == 1)
			rs.push_back((cuoi + 1) % 2);
		else
			rs.push_back(cuoi % 2);
		if (dau == 1 && cuoi % 2 == 1)
			ok = 1;
		dem++;
	}

	while (dem < 128)
	{
		if (dau == 1 && ok == 1)
		{
			rs.push_back(1);
		}
		else
		{
			rs.push_back(0);
		}

		dem++;
	}
	reverse(rs.begin(), rs.end());
	return rs;

}

string QInt::convertBinToDec(vector<bool> vbit)
{

	string ketqua = "0";
	vector<int> c;
	int dem;
	reverse(vbit.begin(), vbit.end());
	while (vbit.size() < 127)
	{
		vbit.push_back(0);
	}
	for (int i = 0; i < 127; i++)
	{
		bool bit = vbit[i];
		string b;
		LuyThuaCua2(i, b);
		Nhan(b, bit, b);
		Cong(ketqua, b, ketqua);
	}
	if (vbit[127] == 1)
	{
		string temp;
		LuyThuaCua2(127, temp);
		Tru(temp, ketqua, ketqua);
		ketqua.insert(0, 1, '-');
	}
	else
	{
		bool bit = vbit[127];
		string b;
		LuyThuaCua2(127, b);
		Nhan(b, bit, b);
		Cong(ketqua, b, ketqua);
	}


	return ketqua;

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
	QInt a = ~x, b;
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
	/*bool q1 = 0, q0;
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

	}*/
	return q;

}

pair<QInt, QInt> QInt::operator/(QInt x)
{

	return pair<QInt, QInt>();

}

QInt QInt::operator<(QInt x)
{
	return QInt();
}

QInt QInt::operator>(QInt x)
{
	return QInt();
}

QInt QInt::operator==(QInt x)
{
	return QInt();
}

QInt QInt::operator<=(QInt x)
{
	return QInt();
}

QInt QInt::operator>=(QInt x)
{
	return QInt();
}

QInt QInt::operator=(QInt x)
{
	for (int i = 0; i < 4; i++)
		this->data[i] = x.data[i];
	return *this;
}

QInt QInt::operator&(QInt x)
{
	return QInt();
}

QInt QInt::operator|(QInt x)
{
	return QInt();
}

QInt QInt::operator^(QInt x)
{
	return QInt();
}

QInt QInt::operator~()
{
	QInt temp;
	for (int i = 0; i < 128; i++)
		temp.setBit(i, (this->getBit(i) + 1) % 2);
	return temp;
}

QInt QInt::operator<<(int k)
{
	return QInt();
}

QInt QInt::operator>>(int k)
{
	return QInt();
}

QInt QInt::rol()
{
	return QInt();
}

QInt QInt::ror()
{
	return QInt();
}

// Các thao tác với số nguyên lớn( ví dụ nhân chia thì cả 2 cùng lớn)
//int SoSanh(vector<int> a, vector<int> b)
//{
//	if (a.size() > b.size())
//		return -1;
//	if (a.size() < b.size())
//		return 1;
//	for (int i = a.size() - 1; i >= 0; i--)
//	{
//		if (a[i] > b[i])
//			return -1;
//		if (a[i] < b[i])
//			return 1;
//	}
//	return 0;
//}
//
//void LoaiBoSo0(vector<int> &x)
//{
//	while (x[x.size() - 1] == 0 && x.size() > 1)
//	{
//		x.pop_back();
//	}
//}
//
//void Cong(string a, string b, string &c)
//{
//	vector<int> x, y, z;
//	z.clear();
//	for (int i = a.size() - 1; i >= 0; i--)
//	{
//		x.push_back(a[i] - '0');
//	}
//	// Xóa đi các số 0 
//	LoaiBoSo0(x);
//	// Tương tự 
//	for (int i = b.size() - 1; i >= 0; i--)
//	{
//		y.push_back(b[i] - '0');
//	}
//
//	LoaiBoSo0(y);
//	
//	int length = x.size() > y.size() ? x.size() : y.size();
//	x.resize(length);
//	y.resize(length);
//	int sodu = 0;
//	int temp;
//	for (int i = 0; i < length; i++)
//	{
//		temp = x[i] + y[i] + sodu;
//		z.push_back(temp % 10);
//		sodu = temp / 10;
//	}
//	if (sodu > 0)
//	{
//		z.push_back(temp / 10);
//	}
//	c = "";
//	for (int i = z.size() - 1; i >= 0; i--)
//	{
//		c += (z[i] + '0');
//	}
//}
//
//void Tru(vector<int> sotru, vector<int> sobitru, vector<int> &ketqua)
//{
//	ketqua.clear();
//	int length = sotru.size();
//	sobitru.resize(length);
//
//	int sodu = 0;
//	int temp;
//	for (int i = 0; i < length; i++)
//	{
//		if (sotru[i] < sobitru[i] + sodu)
//		{
//			ketqua.push_back(sotru[i] - sobitru[i] - sodu + 10);
//			sodu = 1;
//		}
//		else
//		{
//			ketqua.push_back(sotru[i] - sobitru[i] - sodu);
//			sodu = 0;
//		}
//	}
//	LoaiBoSo0(ketqua);
//}
//
//void Nhan(string a, string b, string &c)
//{
//	vector<int> x, y, z;
//	z.clear();
//	for (int i = a.size() - 1; i >= 0; i--)
//	{
//		x.push_back(a[i] - '0');
//	}
//	// Xóa đi các số 0 
//	LoaiBoSo0(x);
//	// Tương tự 
//	for (int i = b.size() - 1; i >= 0; i--)
//	{
//		y.push_back(b[i] - '0');
//	}
//
//	LoaiBoSo0(y);
//
//	for (int i = 0; i < x.size(); i++)
//	{
//		vector<int> temp;
//		int sodu = 0, temp1;
//		for (int j = 0; j < y.size(); j++)
//		{
//			temp1 = x[i] * y[j] + sodu;
//			temp.push_back(temp1 % 10);
//			sodu = temp1 / 10;
//		}
//
//		if (sodu > 0)
//		{
//			temp.push_back(sodu);
//		}
//		for (int j = 0; j < i; j++)
//		{
//			temp.insert(temp.begin(), 0);
//		} 
//		/*for (int j = z.size() - 1; j >= 0; j--)
//		{
//			c = "";
//			c += (z[j] + '0');
//		}*/
//		string temp2 = "";
//		for (int j = temp.size() - 1; j >= 0; j--)
//		{
//			temp2 += (temp[j] + '0');
//		}
//		Cong(c, temp2, c);
//	}
//
//}
//
//void Chia(string sochia, string sobichia, string &ketqua)
//{
//	// Lưu string vào vector
//	vector<int> x, y, z;
//	z.clear();
//	for (int i = sochia.size() - 1; i >= 0; i--)
//	{
//		x.push_back(sochia[i] - '0');
//	}
//	// Xóa đi các số 0 ở đầu
//	LoaiBoSo0(x);
//	// Tương tự cho số bị chia
//	for (int i = sobichia.size() - 1; i >= 0; i--)
//	{
//		y.push_back(sobichia[i] - '0');
//	}
//	LoaiBoSo0(y);
//
//	vector<int> temp;
//	while (x.size() > 0)
//	{
//		int ketthuc = x.size() - 1;
//		int batdau = ketthuc - y.size() + 1;
//		if (batdau < 0)
//			batdau = 0;
//		int dem = batdau;
//
//		if (temp.size() == 0)
//			while (dem <= ketthuc)
//			{
//				//temp.push_back(x[batdau]);
//				temp.insert(temp.begin(), char(x.back()));
//				x.pop_back();
//				dem++;
//			}
//		else
//			while (dem <= ketthuc)
//			{
//				//temp.insert(temp.begin(), x[batdau]);
//				temp.insert(temp.begin(), char(x.back()));
//				x.pop_back();
//				dem++;
//			}
//		if (SoSanh(temp, y) != -1 && x.size() > 0)
//		{
//			temp.insert(temp.begin(), x[batdau - 1]);
//			x.pop_back();
//		}
//		LoaiBoSo0(temp);
//		dem = 0;
//		while (SoSanh(temp, y) != 1)
//		{
//			dem++;
//			Tru(temp, y, temp);
//		}
//		if (dem >= 10)
//		{
//			int temp1 = dem % 10;
//			dem /= 10;
//			int temp2 = dem % 10;
//			dem /= 10;
//			z.insert(z.begin(), temp2);
//			z.insert(z.begin(), temp1);
//		}
//		else
//		{
//			z.insert(z.begin(), dem);
//		}
//	}
//	ketqua = "";
//	for (int i = z.size() - 1; i >= 0; i--)
//	{
//		ketqua += (z[i] + '0');
//	}
//}
//
//void LuyThuaCua2(int somu, string &ketqua)
//{
//	ketqua = "2";
//	for (int i = 0; i < somu - 1; i++)
//	{
//		Nhan(ketqua, "2", ketqua);
//	}
//	if (somu == 0)
//		ketqua = "1";
//	
//}






void QInt::ScanQInt()
{
	string qint;
	getline(cin, qint);
	string temp = qint;
	bool dau = 0;
	bool ok = 0;
	if (temp[0] == '-')
	{
		dau = 1;
		temp.erase(temp.begin());
	}
	int cuoi = temp[temp.size() - 1] - '0';
	int dem = 0;
	setBit(dem, cuoi % 2);
	if (dau == 1 && cuoi % 2 == 1)
	{
		ok = 1;
	}

	dem++;
	while (temp != "1")
	{
		Chia(temp, 2, temp);
		cuoi = temp[temp.size() - 1] - '0';
		if (ok == 1)
			setBit(dem, (cuoi + 1) % 2);
		else
			setBit(dem, (cuoi) % 2);
		if (dau == 1 && cuoi % 2 == 1)
			ok = 1;
		dem++;
	}

	while (dem < 128)
	{
		if (dau == 1 && ok == 1)
		{
			setBit(dem, 1);
		}
		else
		{
			setBit(dem, 0);
		}

		dem++;
	}




}



void QInt::PrintQInt()
{

	string ketqua = "0";
	vector<int> c;
	int dem;


	for (int i = 0; i < 127; i++)
	{
		bool bit = getBit(i);
		string b;
		LuyThuaCua2(i, b);
		Nhan(b, bit, b);
		Cong(ketqua, b, ketqua);
	}
	if (getBit(127) == 1)
	{
		string temp;
		LuyThuaCua2(127, temp);
		Tru(temp, ketqua, ketqua);
		ketqua.insert(0, 1, '-');
	}
	else
	{
		bool bit = getBit(127);
		string b;
		LuyThuaCua2(127, b);
		Nhan(b, bit, b);
		Cong(ketqua, b, ketqua);
	}


	cout << ketqua;
}