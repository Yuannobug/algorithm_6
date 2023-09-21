#include<iostream>
using namespace std;

#include<stack>
#include<string>

int main()
{
	int A = 1; string B; stack<int> C;
	int i = 0; int tmp = 0; int judge = 1;
	cin >> B;
	i = 0;
	while (i < B.size())
	{
		if (A == B[i]-'0')
		{
			A++; i++;
		}
		else if(C.size()!=0&& C.top() == B[i]-'0')
		{
			C.pop();
			i++;
		}
		else if (A<= B.size())
		{
			C.push(A);
			A++;
		}
		else
		{
			judge = 0;
			break;
		}
	}
	if (judge == 0)
	{
		cout << "no" << endl;
	}
	else
	{
		cout << "yes" << endl;
	}
	system("pause");
	return 0;
}