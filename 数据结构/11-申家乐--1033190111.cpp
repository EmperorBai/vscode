#include<stdio.h>
#include<stdlib.h>

#define MaxSize 100

typedef struct BiTNode{
	int data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct stack{
	BiTree elem[MaxSize];
	int top;
} *Stack;

typedef struct queue
{
	BiTree elem[MaxSize];
	int front;
	int rear;
} *Queue;

//堆栈函数
Stack CreateStack();
void CreateStack(Stack s);
int IsEmpty(Stack s);
int IsFull(Stack s);
void Push(Stack s, BiTree item);
BiTree Pop(Stack s);

//队列函数 
Queue CreateQueue();
void AddQueue(Queue q, BiTree T);
BiTree DeletaQueue(Queue q);
int QueueLength(Queue q);

//二叉树函数
void CreateBiTree(BiTree *T);
void ProOrderTraversal(BiTree T);
void InOrderTraversal(BiTree T);
void PostOrderTraversal(BiTree T);
void LevelOrderTraversal(BiTree T);
void ProOrderTraversalNoRecursive(BiTree T);
void InOrderTraversalNoRecursive(BiTree T);
void PostOrderTraversalNoRecursive(BiTree T);

//二叉树应用函数
void PrintLeaves(BiTree T);
int GetTreeHeight(BiTree T);
BiTree RebuildTreeProIn(char *pro, char *in, int len);
BiTree RebuildTreeInPost(char *in, char *post, int len);
//创建堆栈
Stack CreateStack()
{
	Stack s;
	s = (Stack)malloc(sizeof(stack));
	if (!s)
	{
		printf("初始化堆栈失败");
		exit(-1);
	}
	s->top = -1;//初始化栈顶指针
	return s;
}

//判断堆栈是否为空
int IsEmpty(Stack s)
{
	return (s->top == -1) ? 1 : 0;
}

//判断堆栈是否为满
int IsFull(Stack s)
{
	return (s->top == MaxSize - 1) ? 1 : 0;
}

//压栈操作
void Push(Stack s, BiTree item)
{
    if (IsFull(s))
        printf("堆栈满，无法插入元素");
    else
        s->elem[++(s->top)] = item;
}

//退栈操作
BiTree Pop(Stack s)
{
    if (IsEmpty(s))
    {
        printf("堆栈空，无法弹出元素");
        exit(-1);
    }
    else
        return s->elem[(s->top)--];
}
//创建队列
Queue CreateQueue()
{
	Queue q;
	q = (Queue)malloc(sizeof(queue));
	if (!q)
	{
		printf("初始化队列失败");
		exit(-1);
	}
	q->front = 0;
	q->rear = 0;
}

//入队操作(队列操作记得对MaxSize取余)
void AddQueue(Queue q, BiTree T)
{
	if ((q->rear + 1) % MaxSize == q->front)
	{
		printf("队列满，无法插入元素");
		exit(-1);
	}
	q->elem[q->rear] = T;
	q->rear = (q->rear + 1) % MaxSize;
}

//出队操作
BiTree DeletaQueue(Queue q)
{
	BiTree elem;
	if (q->front == q->rear)
	{
		printf("队列满，无法插入元素");
		exit(-1);
	}
	elem = q->elem[q->front];
	q->front = (q->front + 1) % MaxSize;
	return elem;
}

//队列长度
int QueueLength(Queue q)
{
	return (q->rear - q->front + MaxSize) % MaxSize;
}
//根据前序扩展序列创建二叉树 特点是没有使用指针的指针，容易理解。
BiTree CreateBiTree()
{
	BiTree T;
	char data, tmp;

	scanf("%c", &data);
	tmp = getchar();//过滤回车键

	if (data == '#')
		T = NULL;
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		if(!T) exit(-1);
		T->data = data;
		printf("输入%c的左子节点：", data);
		T->lchild = CreateBiTree();
		printf("输入%c的右子节点：", data);
		T->rchild = CreateBiTree();
	}
	return T;
}
//前序遍历二叉树(递归)
void ProOrderTraversal(BiTree T)
{
	if (T)
	{
		printf("%c", T->data);
		ProOrderTraversal(T->lchild);
		ProOrderTraversal(T->rchild);
	}
}

//中序遍历二叉树(递归)
void InOrderTraversal(BiTree T)
{
	if (T)
	{
		InOrderTraversal(T->lchild);
		printf("%c", T->data);
		InOrderTraversal(T->rchild);
	}
}

//后序遍历二叉树(递归)
void PostOrderTraversal(BiTree T)
{
	if (T)
	{
		PostOrderTraversal(T->lchild);
		PostOrderTraversal(T->rchild);
		printf("%c", T->data);
	}
}
//前序遍历二叉树（非递归）
void ProOrderTraversalNoRecursive(BiTree T)
{
	BiTree r = T;
	Stack s = CreateStack();

	while (r || !IsEmpty(s))
	{
		while (r)//输出父母节点、遍历左子树
		{
			printf("%c", r->data);
			Push(s, r);
			r = r->lchild;
		}
		if (!IsEmpty(s))
		{
			r = Pop(s);
			r = r->rchild;
		}
	}
}

//中序遍历二叉树（非递归）
void InOrderTraversalNoRecursive(BiTree T)
{
	BiTree r = T;
	Stack s = CreateStack();
	/*Stack s = NULL;
	CreateStack(s);
	printf("%d\n", s->top);*/
		
	while (r || !IsEmpty(s))
	{
		while (r)//遍历左子树
		{
			Push(s, r);
			r = r->lchild;
		}
		if (!IsEmpty(s))
		{
			r = Pop(s);
			printf("%c", r->data);
			r = r->rchild;
		}
	}
}

//后序遍历二叉树（非递归）
void PostOrderTraversalNoRecursive(BiTree T)
{
	BiTree pre, r = T;
	Stack s = CreateStack();
	pre = NULL;

	while (r || !IsEmpty(s))
	{
		while (r)
		{
			Push(s, r);
			r = r->lchild;
		}
		if (!IsEmpty(s))
		{
			r = Pop(s);
			if (r->rchild != NULL && r->rchild != pre)//右节点存在且没有被访问过
			{
				Push(s, r);
				r = r->rchild;
			}
			else//右节点已经被访问过，处理相对根节点（父母节点）
			{
				printf("%c", r->data);
				pre = r;
				r = NULL;
			}
		}
	}
}
void LevelOrderTraversal(BiTree T)
{
	BiTree r = T;
	Queue q;
 
	if (!r) return;
	q = CreateQueue();
	AddQueue(q, r);
	while (QueueLength(q))
	{
		r = DeletaQueue(q);
		printf("%c", r->data);
		if (r->lchild) AddQueue(q, r->lchild);
		if (r->rchild) AddQueue(q, r->rchild);
	}
}
//打印二叉树的叶子结点
void PrintLeaves(BiTree T)
{
	if (T)
	{
		PrintLeaves(T->lchild);
		PrintLeaves(T->rchild);
		if (!T->lchild && !T->rchild)
			printf("%c", T->data);
	}
}

//求二叉树的高度
int GetTreeHeight(BiTree T)
{
	int HL, HR, MaxH;
	if (T)
	{
		HL = GetTreeHeight(T->lchild);
		HR = GetTreeHeight(T->rchild);
		MaxH = (HL > HR) ? HL : HR;
		return MaxH + 1;
	}
	return 0;
}
//根据前序序列和中序序列建立二叉树 
BiTree RebuildTreeProIn(char *pro, char *in, int len)
{
	BiTree t;
	int i = 0;//头结点的下标
 
	if (len <= 0)
		t = NULL;
	else
	{
		while (i < len && in[i] != *pro)//在中序序列中寻找根节点		
			i++;
		if (i >= len)
		{
			printf("中序序列没有找到根节点，前序序列和中序序列有误，无法建立二叉树！");
			exit(-1);
		}
		else
		{
			t = (BiTree)malloc(sizeof(BiTNode));
			t->data = *pro;
			t->lchild = RebuildTreeProIn(pro + 1, in, i);
			t->rchild = RebuildTreeProIn(pro + i + 1, in + i + 1, len - 1 - i);//加起来的长度是len-1
		}
	}
	return t;
}
 
//根据中序序列和后序序列建立二叉树 
BiTree RebuildTreeInPost(char *in, char *post, int len)
{
	BiTree t;
	int i = 0;//头结点的下标
 
	if (len <= 0)
		t = NULL;
	else
	{
		while (i < len && in[i] != post[len - 1])//在中序序列中寻找根节点
			i++;
		if (i >= len)
		{
			printf("中序序列没有找到根节点，中序序列和后序序列有误，无法建立二叉树！");
			exit(-1);
		}
		else
		{
			t = (BiTree)malloc(sizeof(BiTNode));
			t->data = in[i];
			t->lchild = RebuildTreeInPost(in, post, i);
			t->rchild = RebuildTreeInPost(in + i + 1, post + i, len - i - 1);//加起来的长度是len-1
		}
	}
	return t;
}
//主程序
//测试序列：AB#D##C## 
//测试序列：ABD##FE###CG#H##I##
void main()
{
	BiTree T;
	char *pro = "ABCDEF", *in1 = "CBAEDF", *in2 = "ABCDEFG", *post = "BDCAFGE";
	printf("请输入数据：");
	CreateBiTree(&T);
 
	printf("层序遍历结果为：");
	LevelOrderTraversal(T);
	printf("\n");
 
	printf("前序遍历结果为：");
	ProOrderTraversal(T);
	printf("\n");
	printf("非递归前序遍历结果为：");
	ProOrderTraversalNoRecursive(T);
	printf("\n");
 
	printf("中序遍历结果为：");
	InOrderTraversal(T);
	printf("\n");
	printf("非递归中序遍历结果为：");
	InOrderTraversalNoRecursive(T);
	printf("\n");
 
	printf("后序遍历结果为：");
	PostOrderTraversal(T);
	printf("\n");
	printf("非递归后序遍历结果为：");
	PostOrderTraversalNoRecursive(T);
	printf("\n");
 
	printf("叶子结点为：");
	PrintLeaves(T);
	printf("\n");
	printf("二叉树的高度为%d", GetTreeHeight(T));
	printf("\n");
	
	printf("**************************");
	printf("后序遍历结果为：");
	PostOrderTraversal(RebuildTreeProIn(pro, in1, 6));//正确输出结果为CBEFDA
	printf("\n");
	printf("前序遍历结果为:");
	ProOrderTraversal(RebuildTreeInPost(in2, post, 7));//正确输出结果为EACBDGF
	printf("\n");
}
