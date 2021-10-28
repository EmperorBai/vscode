#include<iostream>
#include<algorithm>
using namespace std;
int x[500];
int m[500][500];
void Knapsack(int v[], int w[], int c, int n)
{
    int jMax = min(w[n]-1,c);
    for(int j = 0; j <= jMax; j++) m[n][j] = 0;
    for(int j = w[n]; j <= c; j++) m[n][j] = v[n];
    for(int i = n-1; i >1; i--){
        jMax = min(w[i]-1,c);
        for(int j = 0;j <= jMax; j++) m[i][j] = m[i+1][j];
        for(int j = w[i]; j <= c;j++) m[i][j] = max(m[i+1][j],m[i+1][j-w[i]] + v[i]);
    }
    m[1][c] = m[2][c];
    if(c >= w[1]) m[1][c] = max(m[1][c],m[2][c-w[1]]+v[1]);
}

void Traceback(int w[],int c, int n)
{
    for(int i = 1; i < n;i++)
    {
        if(m[i][c] == m[i+1][c]) x[i] = 0;
        else{
            x[i] = 1;
            c -= w[i];
        }
    x[n] = (m[n][c])? 1 : 0;
    }
    
}

int main()
{
    int c,n,v[500],w[500];
    cin >> c >> n;
    for(int i = 1; i < n+1; i++) cin >> v[i];
    for(int i = 1; i < n+1; i++) cin >> w[i];
    Knapsack(v, w, c, n);
    Traceback(w, c,  n);
    cout << m[1][c] << endl;
	for(int i = 1;i <= n;i++)
        if(x[i] == 1) cout << i << " ";

    return 0;
}