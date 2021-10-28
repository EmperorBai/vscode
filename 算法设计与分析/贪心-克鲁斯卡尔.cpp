#include<iostream>
#include<iomanip>
#include <malloc.h>
#include<stdlib.h> 
#include <ctime>
#define maxSize 20 
#define INF 1000 
using namespace std;

typedef struct VexNode{
	int no;
}VexNode; 

typedef struct MGragh{
	int edges[maxSize][maxSize];
	int v,e;
	VexNode vex[maxSize];
}MGraph;

int edgesW[5][5]=
{
	INF,5,1,2,INF,
	5,INF,3,INF,4,
	1,3,INF,6,2,
	2,INF,6,INF,3,
	INF,4,2,3,INF 
};

typedef struct Road{
	int a,b,w;
}Road;

Road road[maxSize];
int v[maxSize];

int getRoot(int a){
	while(a!=v[a]) a=v[a];
	return a;
}

void sort_w(Road road[],int low,int high){
	int i=low,j=high;
	Road temp;
	if(low<high){
		temp=road[low];
		while(i<j){
			while(j>i&&road[j].w>=temp.w) --j;
			if(i<j){
				road[i]=road[j];
				++i;
			}
			while(j>i&&road[i].w<temp.w) ++i;
			if(i<j){
				road[j]=road[i];
				--j;
			}
		}
		road[i]=temp;
		sort_w(road,low,i-1);
		sort_w(road,i+1,high);
	}
}
void Kruskal(MGraph g,int &sum,Road road[]){
	for(int i=0;i<g.v;++i) v[i]=i;
	sort_w(road,0,g.e-1);
	for(int i=0;i<g.e;++i){
		int a=getRoot(road[i].a);
		int b=getRoot(road[i].b);
		if(a!=b){
			v[a]=b;
			sum+=road[i].w;
		}
	}
}


			
int main(int argc, char** argv) {
	MGraph g;
	int sum=0,k=0;
	
	g.e=8;
	g.v=5;
	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j)
	g.edges[i][j]=edgesW[i][j];
	for(int i=0;i<5;++i)
		for(int j=i+1;j<5;++j){
			if(g.edges[i][j]!=INF){
				road[k].a=i;
				road[k].b=j;
				road[k].w=g.edges[i][j];
				++k;
			}
		}

	Kruskal(g,sum,road);
	cout<<sum;

	return 0;
}






