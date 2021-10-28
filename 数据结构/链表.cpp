#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;
Status InList(LinkList &L)//初始化单链表
{
	L = new LNode;
	L->next = NULL;
	return OK;
}
void Input(LinkList &L, int n)//后插法创建单链表
{
	cout << "请递增输入链表内容!!" << endl;
	LinkList p, r;
	L->next = NULL;
	r = L;
	for (int i = 0; i < n; i++)
	{
		p = new LNode;
		p->next = NULL;
		cin >> p->data;
		r->next = p;
		r = p;
	}
}
void MergeList(LinkList &LA, LinkList &LB, LinkList &LC)//算法实现，单链表合并
{
	LinkList pa, pb, pc;
	pa = LA->next;
	pb = LB->next;
	LC = LA;
	pc = LC;
	while (pa&&pb)
	{
		if (pa->data < pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else if (pa->data>pb->data)
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pa = pa->next;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	delete LB;
}
int main()
{
	int num_a,num_b;
	LinkList LA, LB, LC, p;
	cout << "请输入第一个链表从长度!!" << endl;
	cin >> num_a;
	InList(LA);
	Input(LA, num_a);
	cout << "请输入第二个链表从长度!!" << endl;
	cin >> num_b;
	InList(LB);
	Input(LB, num_b);
	InList(LC);
	MergeList(LA, LB, LC);
	p = LC->next;
	cout << "运行结果：" << endl;
	while (p)
	{
		cout << p->data<<" ";
		p = p->next;
	}
	cout << ""<<endl;
	system("pause");
	return 0;
}
