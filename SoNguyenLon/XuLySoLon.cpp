#include "XuLySoLon.h"

int SoSanh(vector<int> a, vector<int> b)
{
	if (a.size() > b.size())
		return -1;
	if (a.size() < b.size())
		return 1;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		if (a[i] > b[i])
			return -1;
		if (a[i] < b[i])
			return 1;
	}
	return 0;
}

void LoaiBoSo0(vector<int>& x)
{
	while (x[x.size() - 1] == 0 && x.size() > 1)
	{
		x.pop_back();
	}
}

void Cong(string a, string b, string& c)
{
	vector<int> x, y, z;
	z.clear();
	for (int i = a.size() - 1; i >= 0; i--)
	{
		x.push_back(a[i] - '0');
	}
	// Xóa đi các số 0 
	LoaiBoSo0(x);
	// Tương tự 
	for (int i = b.size() - 1; i >= 0; i--)
	{
		y.push_back(b[i] - '0');
	}

	LoaiBoSo0(y);

	int length = x.size() > y.size() ? x.size() : y.size();
	x.resize(length);
	y.resize(length);
	int sodu = 0;
	int temp;
	for (int i = 0; i < length; i++)
	{
		temp = x[i] + y[i] + sodu;
		z.push_back(temp % 10);
		sodu = temp / 10;
	}
	if (sodu > 0)
	{
		z.push_back(temp / 10);
	}
	c = "";
	for (int i = z.size() - 1; i >= 0; i--)
	{
		c += (z[i] + '0');
	}
}

void Tru(vector<int> sotru, vector<int> sobitru, vector<int>& ketqua)
{
	ketqua.clear();
	int length = sotru.size();
	sobitru.resize(length);
	int sodu = 0;
	for (int i = 0; i < length; i++)
	{
		if (sotru[i] < sobitru[i] + sodu)
		{
			ketqua.push_back(sotru[i] - sobitru[i] - sodu + 10);
			sodu = 1;
		}
		else
		{
			ketqua.push_back(sotru[i] - sobitru[i] - sodu);
			sodu = 0;
		}
	}
	LoaiBoSo0(ketqua);
}

void Nhan(string a, string b, string& c)
{
	vector<int> x, y, z;
	z.clear();
	for (int i = a.size() - 1; i >= 0; i--)
	{
		x.push_back(a[i] - '0');
	}
	// Xóa đi các số 0 
	LoaiBoSo0(x);
	// Tương tự 
	for (int i = b.size() - 1; i >= 0; i--)
	{
		y.push_back(b[i] - '0');
	}

	LoaiBoSo0(y);

	for (int i = 0; i < x.size(); i++)
	{
		vector<int> temp;
		int sodu = 0, temp1;
		for (int j = 0; j < y.size(); j++)
		{
			temp1 = x[i] * y[j] + sodu;
			temp.push_back(temp1 % 10);
			sodu = temp1 / 10;
		}

		if (sodu > 0)
		{
			temp.push_back(sodu);
		}
		for (int j = 0; j < i; j++)
		{
			temp.insert(temp.begin(), 0);
		}
		/*for (int j = z.size() - 1; j >= 0; j--)
		{
			c = "";
			c += (z[j] + '0');
		}*/
		string temp2 = "";
		for (int j = temp.size() - 1; j >= 0; j--)
		{
			temp2 += (temp[j] + '0');
		}
		Cong(c, temp2, c);
	}

}

void Chia(string sochia, string sobichia, string& ketqua)
{
	// Lưu string vào vector
	vector<int> x, y, z;
	z.clear();
	for (int i = sochia.size() - 1; i >= 0; i--)
	{
		x.push_back(sochia[i] - '0');
	}
	// Xóa đi các số 0 ở đầu
	LoaiBoSo0(x);
	// Tương tự cho số bị chia
	for (int i = sobichia.size() - 1; i >= 0; i--)
	{
		y.push_back(sobichia[i] - '0');
	}
	LoaiBoSo0(y);

	vector<int> temp;
	while (x.size() > 0)
	{
		int ketthuc = x.size() - 1;
		int batdau = ketthuc - y.size() + 1;
		if (batdau < 0)
			batdau = 0;
		int dem = batdau;

		if (temp.size() == 0)
			while (dem <= ketthuc)
			{
				//temp.push_back(x[batdau]);
				temp.insert(temp.begin(), char(x.back()));
				x.pop_back();
				dem++;
			}
		else
			while (dem <= ketthuc)
			{
				//temp.insert(temp.begin(), x[batdau]);
				temp.insert(temp.begin(), char(x.back()));
				x.pop_back();
				dem++;
			}
		if (SoSanh(temp, y) != -1 && x.size() > 0)
		{
			temp.insert(temp.begin(), x[batdau - 1]);
			x.pop_back();
		}
		LoaiBoSo0(temp);
		dem = 0;
		while (SoSanh(temp, y) != 1)
		{
			dem++;
			Tru(temp, y, temp);
		}
		if (dem >= 10)
		{
			int temp1 = dem % 10;
			dem /= 10;
			int temp2 = dem % 10;
			dem /= 10;
			z.insert(z.begin(), temp2);
			z.insert(z.begin(), temp1);
		}
		else
		{
			z.insert(z.begin(), dem);
		}
	}
	ketqua = "";
	for (int i = z.size() - 1; i >= 0; i--)
	{
		ketqua += (z[i] + '0');
	}
}

void LuyThuaCua2(int somu, string& ketqua)
{
	ketqua = "2";
	for (int i = 0; i < somu - 1; i++)
	{
		Nhan(ketqua, "2", ketqua);
	}
	if (somu == 0)
		ketqua = "1";

}