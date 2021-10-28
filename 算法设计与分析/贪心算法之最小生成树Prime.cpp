#include<iostream>
using namespace std;
#define INF 0X7fffffff;


void Prime(int n, int c[][100])
{
    int lowcost[50];
    int closest[50] = {1} ;
    bool s[50] = {false};

    s[0] = true;
    for(int i = 1; i < n; i++)
    {
        lowcost[i] = c[0][i];
    }
    //求邻接点
    for(int i = 0; i < n; i++)
    {
        float min = INF;
        int j = 1;
        for(int k = 1; k < n; k++)
        {
            if((lowcost[k]<min&&(!s[k]))&&lowcost[k] != 0)
            {
                min = lowcost[k];
                j = k;
            }
        }
        if(i < n-1) cout << j+1 << " " << closest[j]+1 << " " << c[j][closest[j]] << endl;
        s[j] = true;

        for(int k = 1; k < n; k++)
        {
            if((!s[k])&&c[j][k]!=0)
            {
                if (c[j][k] < lowcost[k] || lowcost[k] == 0)
                {
                    lowcost[k] = c[j][k];
                    closest[k] = j;
                }
            }
        }

    }

}

int main()
{
    int n;
    int c[100][100];
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> c[i][j];
    Prime(n,c);
}