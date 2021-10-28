#include<iostream>
using namespace std;
#define MAX 1000
int arc[100][100], x[100], bestx[100];//bestx用来记录最优路径或者中途产生的暂时最优路径，x用来记录路径
int length = 0, best_length = MAX, n;
int k = 1;
void print_res()
{
    for(int i = 1; i < k; i++)
    {
        cout<<bestx[i];
        if(i == k)
        {
            cout << endl;
            break;
        }
        cout<<"->";
    }
}
void Traveling(int t)
{
	int j;
    
    k = 1;
	if (t > n) //到达叶子结点
	{
		if (arc[x[n]][1] != 0 && (length + arc[x[n]][1] < best_length))//推销员到的最后一个城市与出发的城市之间有路径，且当前总距离比当前最优值小
		{
			for (j = 1; j <= n; j++){
                bestx[j] = x[j];
                k++;
            }
				
            print_res();
			best_length = length + arc[x[n]][1];
		}
	}
	else    //没有到达叶子结点
	{
		for (j = t; j <= n; j++)//搜索扩展结点的左右分支，即所有与当前所在城市临近的城市
		{
			if (arc[x[t - 1]][x[j]] != 0 && (length + arc[x[t - 1]][x[j]] < best_length))//若果第t-1个城市与第t个城市之间有路径且可以得到更短的路线
			{
				swap(x[t], x[j]);     //保存要去的第j个城市到x[t]中，从第j个城市出发继续往下走（此时t为父结点，j为子结点）。因为下一步递归的是t+1，递归函数里又是t-1，就相当于把t传了过去，有了swap这一步，就可以在递归函数里从结点j继续往下走了
				length += arc[x[t - 1]][x[t]]; //路线长度增加
				Traveling(t + 1);      //搜索下一个城市。不能上边没有swap，这里传参数j+1。因为若如此做，递归函数里的arc[x[t - 1]][x[j]]就会直接从j往n走,如1-3-4，而实际情况可能是1-3-2-4
				length -= arc[x[t - 1]][x[t]];//回溯到父结点，恢复length的数值，为往另一个子结点走做准备
				swap(x[t], x[j]);//恢复x的顺序（从j子结点回溯到t父结点，为往t的另一个子结点走做准备）
			}
		}
	}
}
int main()
{
	int i, j;
	cin >> n;
	for (i = 1; i <= n; i++)//从i=1开始赋值，如此i=1就代表结点1
		for (j = 1; j <= n; j++)
			cin >> arc[i][j];

	for (i = 1; i <= n; i++)
	{
		x[i] = i;
		bestx[i] = 0;
	}
	Traveling(2);//t=2表示当前正在考虑结点1与其他结点间的路径
	for (i = 1; i <= n; i++)
		cout << bestx[i] << ' ';
	cout << endl;
	cout << best_length << endl;
	return 0;
}
