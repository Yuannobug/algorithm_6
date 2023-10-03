#include<iostream>
using namespace std;

#include<string>

string midtree; string lasttree;

typedef struct node
{
	char code;
	int leftnode;
	int rightnode;
}node,*pnode;

void Init_tree(pnode head, int i,int& lenght)
{
	int address = 0; int mid = 0; int j = 0; int left = 0;
	head[lenght].code = lasttree[i];
	head[lenght].leftnode = -1;
	head[lenght].rightnode = -1;
	left = lenght;
	lenght++; i--;
	while (i != -1)
	{
		head[lenght].code = lasttree[i];
		head[lenght].leftnode = -1;
		head[lenght].rightnode = -1;
		address = midtree.find(head[lenght].code);
		j = lenght - 1;
		while (j != -1)
		{
			mid = midtree.find(head[j].code);
			if (address > mid&& head[j].rightnode==-1)
			{
				head[j].rightnode = lenght;
				break;
			}
			else if(address > mid && head[j].rightnode != -1)
			{
				head[j + 1].leftnode = lenght;
				break;
			}
			else if (address < mid)
			{
				if (j > left)
				{
					j--;
				}
				else
				{
					head[left].leftnode = lenght;
					left = lenght;
					break;
				}
			}
		}
		lenght++; i--;
	}

}

void Print(pnode l,int address)
{
	cout << l[address].code << "  ";
	if (l[address].leftnode != -1)
	{
		Print(l, l[address].leftnode);
	}
	if (l[address].rightnode != -1)
	{
		Print(l, l[address].rightnode);
	}
}

int main()
{
	pnode l = NULL; int stk = 0; 
	int i = 0; char ch = 0; int lenght = 0;
	cin >> midtree; cin >> lasttree;
	l = new node[lasttree.size()];
	i = lasttree.size()-1;
	Init_tree(l, i,lenght);
	Print(l,0);
	system("pause");
	return 0;
}