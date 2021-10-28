#include <bits/stdc++.h>
using namespace std;

int c[2000][2000][3];


int getPixel(const char &ch1, const char &ch2)      //将输入的十六进制转换成十进制.
{
    return (isalpha(ch1)? 10 + ch1 - 'a': ch1 - '0') * 16 + (isalpha(ch2)? 10 + ch2 - 'a': ch2 - '0');
}
void outChar(const char &ch)        //将每个字符以其ASCII码值的十六进制输出.
{

    cout << "\\x" << hex << uppercase << setw(2) << int(ch);      //hex是按十六进制输出的意思，uppercase是将所有字母转换成大写字母输出的意思，setw（2）域宽是2.
    return;
}

void outInt(int x){
    vector<int>arr;
    char ch;
    arr.push_back(x);
    for(int i=arr.size()-1;i>=0;i--){ 
        ch=arr[i]+48;
        cout << "\\x" << hex << uppercase << setw(2) << int(ch); 
    }   
    return ;
}
int main()
{

    int n, m, p, q;
    string s;

    scanf("%d%d%d%d", &m, &n, &p, &q);
    int area = p * q;
    cout.fill('0');       //域宽中遇到空的地方都以字符'0'占位.


    for(int i = 1; i <= n; i ++){

        for(int j = 1; j <= m; j ++){
            cin >> s;

            if(s.size() == 2){
                s += string(5, s[1]);
            }
            else if(s.size() == 4)
                s = "#" + string(2, s[1]) + string(2, s[2]) + string(2, s[3]);

            for(int k = 0; k < 3; k ++)
                c[i][j][k] = getPixel(s[k + k + 1], s[k + k + 2]);     //tolower()转换成小写字母的函数.将每个像素块的颜色R,G,B以十进制记录下来.
        }
    }

    int R, G, B, r = 0, g = 0, b = 0;

    for(int i = 1; i <= n; i += q){
        for(int j = 1; j <= m; j += p){
            R = G = B = 0;
            for(int ii = i; ii < i + q; ii ++)
            for(int jj = j; jj < j + p; jj ++){
                R += c[ii][jj][0];
                G += c[ii][jj][1];
                B += c[ii][jj][2];
            }

            R /= area, G /= area, B /= area;       //求出压缩后的像素块的颜色.

             //以下为根据题意的具体输出情况.
            if(!(R == r && G == g && B == b)){
                if(!R && !G && !B)
                   cout<<"\\x1B\\x5B"<<"\\x30\\x6D";
                else
                    cout<< "\\x1B\\x5B\\x34\\x38\\x3B\\x32\\x3B" ;
            }

            r = R, g = G, b = B;
            outChar(' ');//每个像素块后 空格
        }
        //每行后判断是否需要默认输出
        if(r || g || b) cout<<"\\x1B\\x5B"<<"\\x30\\x6D";
        cout<<"\x0A";
        r = g = b = 0;

    }

    return 0;
}
