#include<iostream>
using namespace std;

#include<string>

typedef struct matrix
{
	char sign;
	int row;
	int column;
}matrix;

typedef struct caculate
{
	matrix* l;
	int lenght;
}caculate;

bool myjudge(matrix A, matrix B)
{
	if (B.column == A.row)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	int n = 0; int i = 0; int r = 0; int col = 0; string  ch ;
	int sum = 0; bool is_wrong = 0;
	int r1 = 0; int c1 = 0; int c2 = 0;
	matrix head[24] = { 0 }; string str;
	matrix tmp = { 0 }; caculate caculator = {0};
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> ch;
		cin >> r; cin >> col;
		head[ch[0] - 'A'].row = r;
		head[ch[0] - 'A'].column = col;
		head[ch[0] - 'A'].sign = ch[0];
	}
	i = 0;
	cin >> str;
	caculator.l = new matrix[str.size()];
	caculator.lenght = 0;
	while (1)
	{
		if (i < str.size())
		{
			caculator.l[caculator.lenght].sign = str[i];
			caculator.l[caculator.lenght].row = head[str[i] - 'A'].row;
			caculator.l[caculator.lenght].column = head[str[i] - 'A'].column;
		}
		if (caculator.l[caculator.lenght].sign == '('|| caculator.l[caculator.lenght-1].sign == '(')
		{
			caculator.lenght++;
			i++;
			continue;
		}
		else if (caculator.l[caculator.lenght].sign == ')' && caculator.l[caculator.lenght - 2].sign == '(')
		{
			caculator.l[caculator.lenght - 2].sign = caculator.l[caculator.lenght - 1].sign;
			caculator.l[caculator.lenght - 2].row = caculator.l[caculator.lenght - 1].row;
			caculator.l[caculator.lenght - 2].column = caculator.l[caculator.lenght - 1].column;
			caculator.lenght -= 2;
			caculator.lenght++;
			i++;
		}
		else if (caculator.l[caculator.lenght].sign == ')' && caculator.l[caculator.lenght - 3].sign == '(')
		{
			is_wrong = myjudge(caculator.l[caculator.lenght - 1], caculator.l[caculator.lenght - 2]);
			if (is_wrong == 1)
			{
				cout << "error" << endl;
				break;
			}
			r1 = caculator.l[caculator.lenght - 2].row;
			c1 = caculator.l[caculator.lenght - 2].column;
			c2 = caculator.l[caculator.lenght-1].column;
			sum += r1 * c1 * c2;
			caculator.l[caculator.lenght-3].sign = 't';
			caculator.l[caculator.lenght-3].row = r1;
			caculator.l[caculator.lenght-3].column = c2;
			caculator.lenght -= 2;
			i++;
		}
		else if (caculator.l[caculator.lenght].sign != '(' && caculator.l[caculator.lenght].sign != ')' && caculator.l[caculator.lenght - 1].sign != '(' && caculator.l[caculator.lenght - 1].sign != ')')
		{
			is_wrong=myjudge(caculator.l[caculator.lenght], caculator.l[caculator.lenght - 1]);
			if (is_wrong == 1)
			{
				cout << "error"<<endl;
				break;
			}
			r1 = caculator.l[caculator.lenght - 1].row;
			c1 = caculator.l[caculator.lenght - 1].column;
			c2=  caculator.l[caculator.lenght].column;
			sum += r1 * c1 * c2;
			caculator.lenght--;
			caculator.l[caculator.lenght].sign = 't';
			caculator.l[caculator.lenght].row = r1;
			caculator.l[caculator.lenght].column = c2;
			caculator.lenght++;
			i++;
		}
		if ((caculator.l[0].sign !='(') && (caculator.l[0].sign !=')'))
		{
			cout << sum << endl;
			break;
		}
	}
	system("pause");
	return 0;
}