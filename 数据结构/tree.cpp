#include<iostream>
using namespace std;
template<class T> 
class ArList{
	T *data;
	int capacity,n;
	private:
		bool realloc();	
	public:
		ArList(int cap = 100){data = new T[cap];capacity = cap;n = 0;}
		bool insert(int i,T e);//在位置i插入新元素e 
		bool remove(int i);    //删除第i个元素 
		bool get(int i,T &e);  //得到第i个元素放入e 
		bool set(int i,T e);   //修改第i个元素的值为e 
		bool insert_front(T e);//新元素插入在第一个 
		bool push_back(T e);   //新元素加到最后面 
		bool remove_front();   //删除第一个元素 
		bool pop_back();       //删除最后一个元素 
		int size(){return n;}  //得到线性表的大小 
		int find(T e);         //查询满足某条件的元素 
		int traverse();        //便历访问每个元素
		
};
template<class T>
bool ArList<T> :: realloc(){
	T * p = new T[2*capacity];
	if(!p) return false;
	for(int i = 0;i<capacity;i++)
		p[i] = data[i];
	capacity *=2;
	delete[] data; data = p;
	return true;
}
template<class T>
bool ArList<T> :: insert(int i,T e){
	if(i<1||i>n+1)
		return false;
	if(n>=capacity){
		if(!realloc()) return false;
	}
	for(int j = n;j>=i;j--){
		data[j]=data[j-1];
	}
	data[i-1] = e;
	n++;
}
template<class T>
bool ArList<T> :: remove(int i){
	if(i < 1||i > n)
		return false;
	T *p,*q;
	p = &(data[i]);
	q = data + n - 1;
	for(;p <= q; ++ p)
		*(p-1) = *p;
	--n;
	return true;
}
template<class T>
bool ArList<T> :: get(int i,T &e){
	if(i < 1||i > n)
		return false;
	e = data[i-1];
	return true;
}
template<class T>
bool ArList<T> :: set(int i,T e){
	if(i < 1||i > n)
		return false;
	data[i-1] = e;
	return true;
}
template<class T>
bool ArList<T> :: insert_front(T e){
	if(n>=capacity){
		if(!realloc()) return false;
	}
	for(int i = n;i>=1;i--){
		data[i]=data[i-1];
	}
	data[0]=e;
	n++;
}
template<class T>
bool ArList<T> :: push_back(T e){
	if(n>=capacity){
		if(!realloc()) return false;
	}
	data[n] = e;
	n++;
	return true;
}
template<class T>
bool ArList<T> :: remove_front(){
	T *p,*q;
	p = &(data[0]);
	q = data + n - 1;
	for(;p <= q; ++ p)
		*(p-1) = *p;
	--n;
	return true;
}
template<class T>
bool ArList<T> :: pop_back(){
	T *p,*q;
	p = &(data[n]);
	q = data + n - 1;
	for(;p <= q; ++ p)
		*(p-1) = *p;
	--n;
	return true;
}
template<class T>
int ArList<T> :: find(T e){
	for(int i=0; i < n;i++)
		if(data[i]==e)
		 return i+1;
	return 0;
}
template<class T>
int ArList<T> :: traverse(){
	if(n == 0)
	{
		cout<<"该线性表为空表"<<endl; 
		return false;
	}
	for(int i=0; i < n;i++){
		cout<<data[i]<<" ";
	}
	return true;	
}
  
//
int main(){
	ArList<int> L;
	int n=5,m;
	cout<<"未赋值的表：  " ;
	L.traverse(); 
	cout<<endl;
	
	for(int i=1;i<=n;i++){
		L.insert(i,i);
	};
	cout<<"赋值后的列表：";
	L.traverse();
	cout<<endl;
	
	cout<<"线性表的大小："<<L.size()<<endl;
		
	cout<<"删除表中元素：";
	L.remove(1);//2 3 4 5
	L.traverse();
	cout<<endl;
	
	cout<<"表首的插入：  ";
	L.insert_front(7);//出现过问题 
	L.traverse();
	cout<<endl;
	
	cout<<"表尾的插入：  ";
	L.push_back(7);
	L.traverse();
	cout<<endl;
	
	cout<<"表中元素修改："; 
	L.set(2,9);
	L.traverse();
	cout<<endl;
	
	cout<<"删除首元素：  ";
	L.remove_front();
	L.traverse();
	cout<<endl;
	
	cout<<"删除尾元素：  ";
	L.pop_back();
	L.traverse();
	cout<<endl;
	
	 
}