#include<iostream>
using namespace std;

typedef struct node
{
	int lenght;//自身所对杆长
	int weight;//自身重量
}node,*pnode;

pnode tree = new node[2000]; int treelenght = 0;

void Createnode(int address,int len,int wei)
{
	int leftweight = 0; int leftlenght = 0;
	int rightweight = 0; int rightlenght = 0;
	if (address == 1)
	{
		tree[address - 1].lenght = 0;
		tree[address - 1].weight = 0;
		treelenght++;
	}
	else
	{
		tree[address - 1].lenght = len;
		tree[address - 1].weight = wei;
		treelenght++;
	}
	if (tree[address - 1].weight == 0)
	{
		cin >> leftweight; cin >> leftlenght;
		cin >> rightweight; cin >> rightlenght;
		Createnode(2 * address, leftlenght, leftweight);
		Createnode(2 * address + 1, rightlenght, rightweight);
	}
	if (tree[address - 1].weight != 0)
	{
		tree[address/2-1].weight += tree[address - 1].weight;
	}
}

bool judge(int address)
{	
	if (tree[2 * address - 1].weight * tree[2 * address - 1].lenght
		== tree[2 * address].weight * tree[2 * address].lenght)
	{
		if (address * 2 > treelenght)
		{
			return true;
		}
		judge(2 * address );
		judge(2 * address+1 );
	}
	else
	{
		return false;
	}
}

int main()
{
	Createnode(1,0,0);
	if (judge(1) == true)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	system("pause");
	return 0;
}