#include<iostream>
using namespace std;
//挑选最小值
int SelectMin(int x,int y,int z,int i)
{
    return x;
};
//编码节点
struct HCode{
    char data;
    char code[100];
};

//节点
struct HNode{
    int weight; //结点权值
    int parent; //双亲指针
    int LChild; //左孩子指针
    int RChild; //右孩子指针
};
//哈夫曼树
class Huffman
{
private:
    HNode *HTree; // Huffman树
    HCode *HCodeTable; //编码表

public:
    void CreateHTree(int a[], int n);   //创建Huffman树
    void CreateHCodeTable(char b[], int n); //创建编码表
    void Encode(char *s, char *d, int n);   //编码
    void Decode(char *s, char *d, int n);   //解码
    ~Huffman();
};

//输入参数a[]，储存每种字符的权值，n为字符的种类
void Huffman :: CreateHTree(int a[], int n)
{
    HTree = new HNode[2*n-1];
    for(int i=0; i<n;i++)
    {
        HTree[i].weight = a[i];
        HTree[i].LChild = HTree[i].RChild = HTree[i].parent = -1;
    }
    int x,y;
    //建哈夫曼树
    for(int i = n; i<2*n-1;i++)
    {
        SelectMin(x,y,0,i);
        HTree[x].parent = HTree[y].parent = i;
        HTree[i].weight = HTree[x].weight + HTree[y].weight;
        HTree[i].LChild = x;
        HTree[i].RChild = y;
        HTree[i].parent = -1;

    }

}

//生成编码表
void Huffman :: CreateHCodeTable(char b[], int n)
{
    HCodeTable = new HCode[n];        // 生成编码表
    for(int i = 0; i < n;i++)
    {
        HCodeTable[i].data = b[i];
        int child = i;                //孩子节点编号
        int parent = HTree[i].parent; //当前节点父节点编号
        int k = 0;
        while(parent != -1)
        {
            if(child == HTree[parent].LChild) //左孩子标'0'
                HCodeTable[i].code[k] = '0';
            else
                HCodeTable[i].code[k] = '1';  //右孩子标'1'
            k++;
            child = parent;
            parent = HTree[child].parent;
        }
        HCodeTable[i].code[k] = '\0';
        //Reverse(HCodeTable[i].code);  //将编码字符逆制
    }
}
//编码算法

//解码算法
void Huffman :: Decode(char *s, char *d, int n)
{
    while(*s != '\0')
    {
        int parent = 2*n -2; // 根节点在HTree中的下标
        while(HTree[parent].LChild != -1)
        {
            if(*s == '0')
                parent = HTree[parent].LChild;
            else
                parent = HTree[parent].RChild;
        }
        *d = HCodeTable[parent].data;
        d++;
    }
}
int main()
{
    int n, i = 0;
    int x[100];
    while(cin>>x[i]){
		i++;
		if(cin.get()=='\n') break;
	}
    
    return 0;
}