#include<iostream>
using namespace std;
class String{
private:
    int length;
    char *s;
public:
    //构造
    String(){//构造函数
        length=0;
        s=new char[100];
    }
    String(const char *str);//重载构造函数
    String(const String &str);//拷贝构造函数
    //功能
	String &StrInsert(int i, const String str) const;//插入字符串
	String &StrDelate(int i, int len) const;//删除字符串
	String &StrSubstr(int i, int len) const;//求子串
	void print() const;
    void clear();//清空字符串
    int size();//返回字符串长度
    int find(String str,int pos=0);//寻找pos位置的字符并返回


    /*String substr(int pos,int n){
        //求子串
        char *p = new char[n+1];
    if(!p) return String();
    if(pos+n>=length) return String();
    int i=pos;
    for(int j=0;j<=n;j++,i++){
        p[j]=s[i];
    }
    string str(p);
    delete []p;
    return str;
    }
    */
    bool Insert(String str, int pos) const;//插入字符串
    bool delate(int pos,int n);//删除字符串
    String strcat(String str1,String str2);//将str2拼接到str1后面
};
String ::String(const char *str){
    length=0;
    s=new char[100];
    while (str[length] != '\0')
	{
	    s[length] = str[length];
	    ++length;
	}
}
String :: String(const String &str){
    s=new char[100];
    length = 0;
    while(length < str.length)
    {
        s[length] = str.s[length];
        ++length;
    }
} 
void String :: clear(){
    length=0;
}

String &String::StrInsert(int i, const String str) const
{
	String c;
 
	if (i < 1 || i > length + 1)
	{
		return c;
	}
 
	int j = 0;
	int k = 0;
 
	while (j < i - 1)
	{
		c.s[j] = s[j];
		++j;
	}
 
	while (k < str.length)
	{
		c.s[j] = str.s[k];
		++j;
		++k;
	}
 
	k = i - 1;
 
	while (k < length)
	{
		c.s[j] = s[k];
		++j;
		++k;
	}
 
	c.length = j;
	return c;
}
 
String &String::StrDelate(int i, int len) const
{
	String c;
 
	if (i < 1 || len < 0 || i + len - 1 > length)
	{
		return c;
	}
 
	int j = 0;
	int k = i - 1 + len;
 
	while (j < i - 1)
	{
		c.s[j] = s[j];
		++j;
	}
 
	while (k < length)
	{
		c.s[j] = s[k];
		++j;
		++k;
	}
 
	c.length = j;
	return c;
}
 
String &String::StrSubstr(int i, int len) const
{
	String c;
 
	if (i < 1 || len < 0 || i - 1 + len > length)
	{
		return c;
	}
 
	int j = 0;
	int k = i - 1;
 
	while (k < i - 1 + len)
	{
		c.s[j] = s[k];
		++j;
		++k;
	}
 
	c.length = j;
	return c;
}

void String::print() const
{
	for (int i = 0; i < length; ++i)
	{
		cout << s[i];
	}
 
	cout << endl;
}

int String :: size(){
    return length;
}
int String :: find(String str,int pos){
    int i = pos,j= 0; 
    while(i < length && j < str.size() )
    { 
        if(s[i] == str.s[j])
        {    //当前字符匹配，i,j递增 
            i++;  
            j++; 
        } 
        else{     //否则i回退，j返回模式串首，重新开始 
            i = i -j + 1;  
            j = 0; 
        } 
    } 
    if(j >= str.size()) return i-j; //匹配成功 
    else return -1;         //失败

}
String String :: strcat(String str1,String str2){

}

int main(){
    char ch[]="ABDEFGH";
    String s1(ch);
    String s2(ch);
    s1=s2.StrSubstr(3,2);
    cout<<"字符串s1长度为："<<s1.size()<<endl;
    cout<<"输出字符串s1：";
    s1.print();
    cout<<endl;

    String s("abc");
    s1.StrInsert(0,s);
    cout<<"字符串s1长度为："<<s1.size()<<endl;
    cout<<"输出字符串s1：";
    s1.print();
    cout<<endl;

    s1.StrDelate(6,3);
    cout<<"字符串s1长度为："<<s1.size()<<endl;
    cout<<"输出字符串s1：";
    s1.print();
    cout<<endl;

    s1.clear();//清空字符串
    cout<<"字符串s1长度为："<<s1.size()<<endl;
    cout<<endl;

}