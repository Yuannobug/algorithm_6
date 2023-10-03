#include<iostream>
#include<cstring>
using namespace std;

int sumlist[2000] = { 0 };

void Settree(int place)
{
	int num = 0;
	cin >> num;
	if (num == -1)
	{
		return;
	}
	sumlist[place] += num;
	Settree(place - 1);
	Settree(place + 1);
}

void Init()
{
	int num = 0; int place = 0;
	cin >> num;
	if (num == -1)
	{
		return;
	}
	place = 1000;
	sumlist[place] += num;
	Settree(place - 1);
	Settree(place + 1);
}

int main()
{
	int p = 0;
	Init();
	while (sumlist[p] == 0)p++;
	while (sumlist[p] != 0)cout << sumlist[p++] << "  ";
	system("pause");
	return 0;
}