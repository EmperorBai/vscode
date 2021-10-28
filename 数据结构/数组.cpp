#include<iostream>
using namespace std;
int main(){
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int max=a[0],flag=1;
    for(int i=0;i<n;i++)
    {
        if(max<a[i])
        {
            max=a[i];
            flag=i+1;
        }
    }
    cout<<max<<" "<<flag;
}