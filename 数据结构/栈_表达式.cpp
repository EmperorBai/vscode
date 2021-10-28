#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<double> num;//存储数字
stack<char> opter;//存储运算符
int getIndex(char theta)   //获取theta所对应的索引  
{  
    int index = 0;  
    switch (theta)  
    {  
    case '+':  
        index = 0;  
        break;  
    case '-':  
        index = 1;  
        break;  
    case '*':  
        index = 2;  
        break;  
    case '/':  
        index = 3;  
        break;  
    case '(':  
        index = 4;  
        break;  
    case ')':  
        index = 5;  
        break;  
    case '#':  
        index = 6;  
    default:break;  
    }  
    return index;  
}  
  
char getPriority(char theta1, char theta2)   //获取theta1与theta2之间的优先级  
{  
    const char priority[7][7] =     //算符间的优先级关系  
    {  
        { '>','>','<','<','<','>','>' },  
        { '>','>','<','<','<','>','>' },  
        { '>','>','>','>','<','>','>' },  
        { '>','>','>','>','<','>','>' },  
        { '<','<','<','<','<','=','0' },  
        { '>','>','>','>','0','>','>' },  
        { '<','<','<','<','<','0','=' },  
    };  
  
    int index1 = getIndex(theta1);  
    int index2 = getIndex(theta2);  
    return priority[index1][index2];  
}
double  cul(double a,char theta,double b)//计算两数运算
{
    switch(theta)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: break;
    }
} 
double calculate(string ch)// 计算表达式
{
    int len=ch.size();
    int counter=0;
    opter.push('#');//首先存入‘#’
    for(int i=0;i<len;)
    {
        while (ch[i] != '#' || opter.top() != '#')   //终止条件
        {
            if(ch[i]>='0'&&ch[i]<='9')
            {
                if (counter == 1)
                {
                    double t = num.top();  
                    num.pop();  
                    num.push(t * 10 + (ch[i] - '0'));  
                    counter = 1;
                }else{
                    num.push(ch[i]-'0');
                    counter++;
                }
               
            i++;  
        }  
        else  
        {  
            counter = 0;   //counter置零  
            switch (getPriority(opter.top(), ch[i]))   //获取运算符栈opter栈顶元素与c之间的优先级，用'>'，'<'，'='表示  
            {  
            case '<':               //<则将ch入栈opter  
                opter.push(ch[i]);  
                i++; 
                break;  
            case '=':               //=将opter栈顶元素弹出，用于括号的处理  
                opter.pop();  
                i++; 
                break;  
            case '>':               //>则计算  
                char theta = opter.top();  
                opter.pop();  
                double a = num.top();  
                num.pop();  
                double b = num.top();  
                num.pop();  
                num.push(cul(b, theta, a));  
            }  
        }  
      
    return num.top();   //返回opval栈顶元素的值  

    }


    }
}
int main(){
    string ch;
    cin>>ch;
    cout<<calculate(ch);
    return 0;

}