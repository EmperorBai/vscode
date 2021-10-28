#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

typedef struct BitNode//二叉树 
{
	char data;
	BitNode *Lchild,*Rchild;
}BitNode,*BiTree;

void CreateBiTree(BiTree &T)//建立二叉树：按先序次序输入二叉树中结点的值（字符），“#”表示空树 
{
	char ch;
	cin>>ch;
	if(ch=='#') T=NULL;
	else
	{
		T=new BitNode;
		T->data=ch;
		CreateBiTree(T->Lchild);
		CreateBiTree(T->Rchild);
	}
}

void PreOrderTraverse(BiTree T)//先序遍历（递归） 
{
	if(T==NULL) return;
	cout<<T->data;
	PreOrderTraverse(T->Lchild);
	PreOrderTraverse(T->Rchild);
}

void InOrderTraverse(BiTree T)//中序遍历（递归） 
{
	if(T==NULL) return;
	InOrderTraverse(T->Lchild);
	cout<<T->data;
	InOrderTraverse(T->Rchild);
}

void PostOrderTraverse(BiTree T)//后序遍历（递归） 
{
	if(T==NULL) return;
	PostOrderTraverse(T->Lchild);
	PostOrderTraverse(T->Rchild);
	cout<<T->data;
}

int main()
{
	BiTree T;//二叉树根节点 
	cout<<"请按照序次序输入二叉树，空结点用#表示："<<endl; 
	CreateBiTree(T);//建立二叉树：按先序次序输入二叉树中结点的值（字符），“#”表示空树 
	cout<<"二叉树的先序遍历："<<endl;
	cout<<"递归实现：  ";
	PreOrderTraverse(T);
	cout<<endl;
	cout<<"二叉树的中序遍历："<<endl;
	cout<<"递归实现：  ";
	InOrderTraverse(T);
	cout<<endl;
	cout<<"二叉树的后序遍历："<<endl;
	cout<<"递归实现：  ";
	PostOrderTraverse(T);
	cout<<endl;
	
}
/*
	测试数据：
	1  ABDF##G##E##C##
	2  ABC##DE#G##F###
	3  ABD##E##C#F##
*/
