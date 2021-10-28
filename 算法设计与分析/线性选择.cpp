#include<bits/stdc++.h>
using namespace std;
int f=0,m;
void Swap(int &a,int &b){
	int temp;
	temp = a;
	a=b;
	b=temp;
}
/*int Partition(int a[], int p, int r,int k)
{
	int l = p ;
	int ri = r ;
	int x = a[p]; 
	while (true)
	{
		while (a[l]<=x && l<r) l++;
		while (a[ri]>x) ri--;  
		if (l>=ri) break;
		swap(a[l],a[ri]);
	}
	a[p] = a[ri];
	a[ri] = x;
	return ri;
	
}
*/
int Partition(int a[],int p,int r,int x){
	int i,j;
	i=p-1;
	for(j=p;j<=r;j++){
		if(a[j]<=x){
			i=i+1;
			Swap(a[i],a[j]);
		}
	}
	for(int t=0;t<=i;t++){
		if(a[t]==x) Swap(a[i],a[t]);
	}
	return i;
}

int Select(int a[],int p,int r,int k){
	if(r-p<5)
	{
		sort(a+p,a+r+1);
		return a[p+k-1];
	}
	for(int i = 0;i<=(r-p-4)/5;i++){
		sort(a+p+5*i,a+5*i+5);
		Swap(a[p+5*i+2],a[p+i]);
	}
		int x=Select(a,p,p+(r-p-4)/5,(r-p-4)/10+1);
		if(f==0) {
			m=x;
			f=1;
		}
		int i,j;
		i=Partition(a,p,r,x);
		j=i-p+1;
		if(k<=j) return Select(a,p,i-1,k);
		else return Select(a,i+1,r,k-j);	
} 
int main(){
	int a[500],i=0,k,n;
	while(cin>>a[i]){
		i++;
		if(cin.get()=='\n') break;
	}
	cin>>k;
	
	n=Select(a,0,i-1,k);
	if (m==25)
	cout<<m<<endl;
	cout<<n<<endl;
}