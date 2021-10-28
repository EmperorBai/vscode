#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
int farmer(int location)
{
	if(0!=(location&0x08))
		return 1;
	else return 0;
}
int wolf(int location)
{
	if(0!=(location&0x04))
		return 1;
	else return 0;
}
int cabbage(int location)
{
	if(0!=(location&0x02))
		return 1;
	else return 0;
}
int goat(int location)
{
	if(0!=(location&0x01))
		return 1;
	else return 0;
}//用四位二进制整数检测每个对象是否在北岸 
int safe(int location)
{
	if(goat(location)==cabbage(location)&&goat(location)!=farmer(location))
		return 0;//羊吃白菜 
	if(goat(location)==wolf(location)&&goat(location)!=farmer(location))
		return 0;//狼吃羊 
	return 1;//其他状态是安全的 
}//安全状态的判断 
int main()
{
	int route[16];//记录路径
    queue<int> moveTo;
	memset(route,-1,sizeof(route));
	route[0]=0;
	moveTo.push(0);//初始状态加入moveto和route 
    //队列非空&&还没到终止状态 
	while(!moveTo.empty()&&route[15]==-1)
	{
		int state=moveTo.front();
		moveTo.pop();//出队当前状态 
		for(int i=1;i<=8;i<<=1) 
		{
			if(((state&i)!=0)==((state&0x08)!=0))
			{
				int newstate=state^(0x08|i);
				if(safe(newstate)&&route[newstate]==-1)//newstate安全且未访问过 
				{
					moveTo.push(newstate);
					route[newstate]=state;
				}
			}
		}
	}
	if(route[15]!=-1) {
		stack<int> c;
		for(int i=15;i>=0;i=route[i]){
			c.push(i);
			if(i==0) break;
		}
		while(!c.empty()){
			cout<<c.top()<<" ";
			c.pop();
		}
		cout<<endl;
	}
	return 0;
}
