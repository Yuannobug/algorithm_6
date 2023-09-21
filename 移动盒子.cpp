#include<iostream>
using namespace std;

typedef struct box
{
	int left;
	int right;
	long num;
};

void Init(box* boxes, int n)
{
	int i = 0;
	boxes[0].num = 0;
	boxes[0].left = n;
	boxes[0].right = 1;
	for (i = 1; i < n; i++)
	{
		boxes[i].num = i;
		boxes[i].left = i - 1;
		boxes[i].right = i + 1;
	}
	boxes[i].num = i;
	boxes[i].left = i - 1;
	boxes[i].right = 0;
}

int main()
{
	long long n = 0; int m = 0; int i = 0; int tmp = 0; long address = 0;
	box* boxes = NULL; int box1 = 0; int box2 = 0; long long sum = 0;
	int box1_l = 0; int box1_r = 0; int box2_l = 0; int box2_r = 0;
	int op = 0; bool judge = 0;//judge=0 翻转偶数次 judge=1翻转奇数次
	cin >> n;
	cin >> m;
	boxes = new box[n + 1];
	Init(boxes, n);
	for (i = 0; i < m; i++)
	{
		cin >> op;
		if (op == 4)
		{
			judge = !judge;
			continue;
		}
		cin >> box1; cin >> box2;
		if ((op == 1||op==2 )&& judge)
		{
			op = 3 - op;
		}
		else if (op == 3&&boxes[box1].right==box2)
		{
			tmp = box2;
			box2 = box1;
			box1 = tmp;	
		}
		if (boxes[box1].right == box2 && op == 1)
		{
			continue;
		}
		if (boxes[box1].left == box2 && op == 2)
		{
			continue;
		}
		box1_l = boxes[box1].left; box1_r = boxes[box1].right;
		box2_l = boxes[box2].left; box2_r = boxes[box2].right;
		if (op == 1)
		{
			boxes[box1_l].right = boxes[box1].right;
			boxes[box1_r].left = boxes[box1].left;
			boxes[box2_l].right = box1;
			boxes[box1].left = box2_l;
			boxes[box1].right = box2;
			boxes[box2].left = box1;
		}
		else if (op == 2)
		{
			boxes[box1_l].right = boxes[box1].right;
			boxes[box1_r].left = boxes[box1].left;
			boxes[box2_r].left = box1;
			boxes[box1].left = box2;
			boxes[box1].right = box2_r;
			boxes[box2].right = box1;
		}
		else if (op == 3&& boxes[box1].left == box2)
		{
			boxes[box2_l].right = box1;
			boxes[box1_r].left = box2;
			boxes[box1].right = box2;
			boxes[box2].left = box1;
			boxes[box1].left = box2_l;
			boxes[box2].right = box1_r;
		}
		else if (op == 3)
		{
			boxes[box1_l].right = box2;
			boxes[box1_r].left = box2;
			boxes[box2_l].right = box1;
			boxes[box2_r].left = box1;
			boxes[box1].left = box2_l;
			boxes[box1].right = box2_r;
			boxes[box2].left = box1_l;
			boxes[box2].right = box1_r;
		}
	}
	for (i = 0; i < n+1; i++)
	{
		address = boxes[address].right;
		if (i % 2 == 0)
		{
			sum += boxes[address].num;
		}
	}
	if (judge != 0&&n%2==0)
	{
		sum = (n + 1) * n / 2 - sum;

	}
	cout << sum;
	system("pause");
	return 0;
}