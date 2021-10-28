#include<iostream>
using namespace std;

void Swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
};
void Perm(int list[], int k, int m)
{
	if(k == m)
	{
		for(int i = 0;i <= m;i++) cout << list[i]<<" ";
		cout << endl;
	}
	else
		for(int i = k;i <= m;i++)
		{
			Swap(list[k], list[i]);
			Perm(list, k+1, m);
			Swap(list[k],list[i]);
		}
};

int main()
{
	int a[50],k = 0,m;
	int i=0;
	while(cin>>a[i]){
		i++;
		m=i-1;
		if(cin.get()=='\n') break;
	};
		
	Perm(a,k,m);
	return 0;
}
