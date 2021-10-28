#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;

string ans[26];//记录每个字母的编码 

typedef struct HTree//哈夫曼树结点 
{
	int weight;
	char letter;
	string s; //字母编码
	HTree *Lchild=NULL,*Rchild=NULL;//注意初始化为空指针 
}HTree;

struct cmp//结点权值比较 
{
	bool operator()(HTree* &a,HTree* &b)
	{
		return a->weight>b->weight;
	}
};

void LevelOrderTraverse(HTree* T)//二叉树的层次遍历（广度优先遍历） 
{
	if(T==NULL) return;
	queue<HTree*> q; //定义一个结点队列
	q.push(T); //在队尾插入一个元素
	HTree *p=NULL;
	while(!q.empty())
	{
		p=q.front();//返回队列中第一个元素
		q.pop(); //将队列中最靠前的位置的元素拿掉
		//cout<<p->weight<<endl;
		if(p->letter>='a'&&p->letter<='z')
			ans[p->letter-'a']=p->s;//记录字母对应的编码 
		if(p->Lchild)
		{
			p->Lchild->s=p->s+"0";//左子树为0 
			q.push(p->Lchild);
		}
		if(p->Rchild)
		{
			p->Rchild->s=p->s+"1";//右子树为1 
			q.push(p->Rchild);
		}
	}
}



int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	priority_queue<HTree*,vector<HTree*>,cmp > q;//小顶堆，结点权值小的优先 
	int n,w;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>w;
		HTree *t=new HTree;
		t->weight=w;
		t->letter='a'+i;
		q.push(t);
	}
	for(int i=0;i<n-1;i++)
	{
		HTree *t=new HTree;
		HTree *a=q.top(); //访问优先队列的队头元素
		q.pop(); //弹出优先队列的队头元素
		HTree *b=q.top(); //
		q.pop();
		t->Lchild=a;
		t->Rchild=b;
		t->weight=a->weight+b->weight;
		q.push(t); //插入元素到优先队列队尾并排序
	}//构造哈夫曼树 
	HTree *t=q.top();//最后剩下的一个结点即为哈夫曼树的根节点 
	
	LevelOrderTraverse(t);//遍历哈夫曼树得到每个字母的编码 
	for(int i=0;i<n;i++)
	{
		char c='a'+i;
		cout<<c<<" "<<ans[i]<<endl;
	}//打印结果 
	return 0;
}
