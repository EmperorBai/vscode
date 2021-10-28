#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool Iskhao(char ch)
{
    if (ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}')    return true;

    return false;
}
void Match(char* str)
{
    char a[100];
    int i=0,falg=0;
    for(;*str!='\0';str++){
        if(Iskhao(*str)){
            a[i]=*str; 
            i++;
        }
    };
    if(i%2!=0) cout<<"no";
    else{
        for(int j=0;j<(i/2);j++){
            if(a[j]-a[i-j-1]!=-1&&a[j]-a[i-j-1]!=-2) falg++; 
        }
        if(falg>0) cout<<"no";
        else cout<<"yes"; 
    }  
};

int main()
{
    char str[100];
    gets(str);
    Match(str);
    return 0;
}
//测试样例 {[(a+b)/2-3]*5}