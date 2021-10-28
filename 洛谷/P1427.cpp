#include<iostream>
#include<stack>
using namespace std;
stack<int> q;
int main(){
    
    
    while(1)
    {
        int x;
        cin>>x;
        if(x==0) break;
        q.push(x);
    }
    while(!q.empty())
    {
        cout<<q.top();
        q.pop();
    }
    return 0;
}