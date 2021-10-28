#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
using namespace std;
//结点类
template<class T>
struct Node {
	int data;
	Node<T>* next;
};
//单向链表类
template<class T>
class linkedList {
public:
	linkedList() { //构造函数 
		head=NULL;
		len=0;
	}
	virtual ~linkedList() { delete head; } //析构函数 
	bool initiate();//初始化单链表
	bool isEmpty();							//判断链表是否为空
	int Length();						//链表长度
	bool remove( int position, int& value );//删除位置n的数据，并将删除的数据值放在val中
	bool insert(int i,T e);//在位置i处插入数据e
	void print();//顺序打印单链表

	bool insert_front(T e);//在线性表首位插入元素
	bool push_back(T e);//线性表尾部插入元素
	bool remove_front();//删除首元素
	bool pop_back();//删除尾元素
	bool get(int i,T &e);//得到第i个元素放  入e
	bool set(int i,T e);//修改第i个元素的值为e
	int find(T e);//查找线性表中值为e的元素，找到后返回其位置

private:
	Node<T> *head;
	int len;
};

//请在此处补充所有成员函数的实现
template<class T>
bool linkedList<T>::initiate() 
{
	head=new Node<T>;
	head->next=NULL;
	
	if(head!=NULL) return true;
	else return false;
}

template<class T> 
bool linkedList<T>::isEmpty()
{
	if(head==NULL||head->next==NULL) return true;
	else return false;
}

template<class T>
int linkedList<T>::Length()
{
	return len;
}	

template<class T>
bool linkedList<T>::remove(int position,int&value)
{
	if(head==NULL||head->next==NULL) return false;
	else if(position>len)
	{
		cout<<"position > len, failed"<<endl;
		return false;
	}
	else if(position<=0)
	{
		cout<<"position <= 0, failed"<<endl;
		return false;
	}
	else
	{
		Node<T>*p=head->next;
		Node<T>*q=head;
		for(int i=1;p!=NULL;i++)
		{
			if(position==i)
			{
				value=p->data;
				q->next=p->next;
				delete p;
				len--;
				return true;
			}
			else
			{
				q=p;
				p=p->next;
			}
			
		}
	}
	
}

template<class T> 
bool linkedList<T>::push_back(T e)
{
	Node<T>*arr=head;
	
	while(arr->next!=NULL)
	{
		arr=arr->next;
	}
		
	arr->next=new Node<T>;
	arr=arr->next;
	arr->data=e;
	arr->next=NULL;
	len++;
	return true;
}

template<class T>
void linkedList<T>::print()
{
    if( isEmpty() )
    {
        cout << "Empty" << endl;
        return;
    }
    Node<T>* tmp = head->next;
    while(tmp)
    {
        cout <<tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

template<class T>
bool linkedList<T>::insert(int i,T e){
	Node<T>* p = head;
	int j = 0;
	//让p指向第i-1结点
	while(p&&j<i-1){
		p = p->next;
		++j;
	}
	//第i-1个结点不存在
	if (!p||j>i-1)
		return false;
	//在位置i处插入数据
	Node<T>* q = new Node<T>;
	q->data = e;
	q->next = p->next;
	p->next = q;
	len++;
	return true;
}

template<class T>
bool linkedList<T>::insert_front(T e){
	Node<T>* q=new Node<T>;
	if(!q) return false;
	q->data=e;
	q->next=NULL;
	q->next=head->next;
	head->next=q;
	len++;
	return true;
}

template<class T>
bool linkedList<T>::remove_front(){
	if(isEmpty())
		return false;
	Node<T>* p = head->next;
	Node<T>* q=new Node<T>;
	q=p->next;
	head->next=q;
	--len;
	return true;
}
template<class T>
bool linkedList<T>::pop_back(){
	if(head==NULL||head->next==NULL) return false;
	Node<T>*arr=head;
	
	while(arr->next!=NULL)
	{
		arr=arr->next;
	}
	arr=NULL;
	--len;
	return true;
}
template<class T>
bool linkedList<T>::get(int i,T &e){
	Node<T>* p = head->next;
	int j = 1;
	//让p指向第i结点
	while(p&&j<i){
		p = p->next;
		++j;
	}
	//第i个结点不存在
	if (!p||j>i)
		return false;
	e=p->data;
	return true;
}

template<class T>
bool linkedList<T>::set(int i,T e){
	Node<T>* p = head->next;
	int j = 1;
	//让p指向第i结点
	while(p&&j<i){
		p = p->next;
		++j;
	}
	//第i个结点不存在
	if (!p||j>i)
		return false;
	p->data=e;
	return true;
}

template<class T>
int linkedList<T>::find(T e){
	Node<T>* p = head->next;
	int i=1;
	while(p)
	{
		if(p->data==e) return i;
		p=p->next;
		i++;
	}
	return 0;
}



int main(int argc, char* argv[])
{
    linkedList<int> L1;
    int n;
    int val;
    //初始化链表
    if(!L1.initiate())
        return 0;

    cin>>n;//输入链表中数据个数
    for(int i=0; i<n; i++) //输入n个数，并插入链表
    {
        cin>>val;
        L1.push_back(val);
    }

	cout<<"输出链表长度："<<endl;
    cout << "Origin Length：" << L1.Length() << endl;//输出链表长度

    cout << "打印链表：" <<endl;
    L1.print();//打印链表
	cout<<endl;

	cout<<"在首部插入元素7"<<endl;
	L1.insert_front(7);
	cout<<endl;

	cout<<"在尾部插入元素9"<<endl;
	L1.push_back(9);
	cout<<endl;

	cout<<"删除首部元素"<<endl;
	L1.remove_front();
	L1.print();
	cout<<endl;

	cout<<"删除尾部元素"<<endl;
	L1.pop_back();
	L1.print();
	cout<<endl;

	cout<<"得到第2个元素的值"<<endl;
	L1.get(2,val);
	cout<<val<<endl;

	cout<<"修改第2个元素的只为8"<<endl;
	L1.set(2,8);
	cout<<endl;

	cout<<"遍历链表"<<endl;
	L1.print();
	cout<<endl;

	cout<<"查找1的位置"<<endl;
	L1.find(1);
	cout<<endl;
    
    return 0;
}



