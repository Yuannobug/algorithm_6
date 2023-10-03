#include<iostream>
using namespace std;

#include<string>

int color[32][32] = { 0 };

void changecolor(string str,int& num,int x,int y,int len)//字符串，下标，坐标x,y,一次操作的大小
{
	if (num == str.size())
	{
		return;
	}
	char ch = str[num++];
	int i = 0; int j = 0;
	if (ch == 'f')//黑色方块
	{
		for (i = x; i < x+len; i++)
		{
			for (j = y; j < y+len; j++)
			{
				if (color[i][j] == 0)
				{
					color[i][j] = 1;
				}
			}
		}
	}
	if (ch == 'p')//灰色方块
	{
		changecolor(str, num , x, y + len / 2, len / 2);
		changecolor(str, num , x , y , len / 2);
		changecolor(str, num , x + len / 2, y , len / 2);
		changecolor(str, num , x + len / 2, y+len/2, len / 2);
	}

}

int main()
{
	int i = 0; int j = 0; int count = 0;
	string str1; string str2;
	for (i = 0; i < 32; i++)
	{
		for (j = 0; j < 32; j++)
		{
			color[i][j] = 0;
		}
	}
	int tmp1 = 0; int tmp2 = 0;
	cin >> str1; cin >> str2;
	changecolor(str1,tmp1,0,0,32);
	changecolor(str2,tmp2,0,0,32);
	for (i = 0; i < 32; i++)
	{
		for (j = 0; j < 32; j++)
		{
			if (color[i][j] == 1)
			{
				count++;
			}
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}