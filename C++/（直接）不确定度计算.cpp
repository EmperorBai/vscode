#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
int labTimes;
double getConfuse(double *a,double avege)
{
	double result=0;
	for(int i=0;i<labTimes;i++)
	{	
		result=result+(a[i]-avege)*(a[i]-avege);
	}
	return sqrt(result/(labTimes*(labTimes-1)));
}
double getUx(double ua,double ub)
{
	return sqrt(ua*ua+ub*ub);	
}
int main(){
	double a[10],ave,sum,Uxa,Uxb,Ux;
	cout<<"Please enter labTimes:";
	cin>>labTimes;
	cout<<"Please enter error value:";
	cin>>Uxb;
	cout<<"Please enter measure value:"<<endl;
	for(int i=0;i<labTimes;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	cout<<"-----------------------------------------"<<endl;
	ave=sum/labTimes;
	Uxb/=sqrt(3);
	Uxa=getConfuse(a,ave);
	Ux=getUx(Uxa,Uxb);
	cout<<fixed<<setprecision(6);
	cout<<"Average: "<<ave<<endl;
	cout<<"UxA: "<<Uxa<<endl;
	cout<<"UxB: "<<Uxb<<endl; 
	cout<<"UX: "<<Ux<<endl;
	cout<<"EUx: "<<Ux/ave*100;
    return 0;
}
