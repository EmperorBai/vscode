#include <iostream>
using namespace std;
class SqStringClass
{
public:
	/* 静态数据成员 */
	static const int MAXSIZE;
	/* 构造函数, 析构函数 */
	SqStringClass(void);
	explicit SqStringClass(const SqStringClass &str);
	explicit SqStringClass(const char *str);
	~SqStringClass(void);
	/* 成员函数 */
	int StrLength(void) const;
	SqStringClass &StrIns(int i, const char *str) const;
	SqStringClass &StrIns(int i, const SqStringClass &str) const;
	SqStringClass &StrDel(int i, int len) const;
	SqStringClass &StrSub(int i, int len) const;
	SqStringClass &StrRep(int i, int len, const char *str) const;
	SqStringClass &StrRep(int i, int len, const SqStringClass &str) const;
	void Display(void) const;
	/* 成员运算符重载 */
	SqStringClass &operator=(const SqStringClass &str);
	SqStringClass &operator=(const char *str);
	SqStringClass &operator+(const SqStringClass &str) const;
	SqStringClass &operator+(const char *str) const;
	char &operator[](int i);
	operator char *(void) const;
	/* 友元运算符重载 */
	friend std::istream &operator>>(std::istream &in, SqStringClass &str);
	friend std::ostream &operator<<(std::ostream &out, const SqStringClass &str);
protected:
private:
	char *data;
	int length;
};
 
std::istream &operator>>(std::istream &in, SqStringClass &str);
std::ostream &operator<<(std::ostream &out, const SqStringClass &str);
const int SqStringClass::MAXSIZE = 100;
 
SqStringClass::SqStringClass(void)
{
	data = new char[MAXSIZE];
	length = 0;
}
 
SqStringClass::SqStringClass(const SqStringClass &str)
{
	data = new char[MAXSIZE];
	length = 0;
 
	while (length < str.length)
	{
		data[length] = str.data[length];
		++length;
	}
}
 
SqStringClass::SqStringClass(const char *str)
{
	data = new char[MAXSIZE];
	length = 0;
 
	while (str[length] != '\0')
	{
		data[length] = str[length];
		++length;
	}
}
 
SqStringClass::~SqStringClass(void)
{
	delete []data;
}
 
int SqStringClass::StrLength(void) const
{
	return length;
}
 
SqStringClass &SqStringClass::StrIns(int i, const char *str) const
{
	static SqStringClass s;
 
	if (i < 1 || i > length + 1)
	{
		return s;
	}
 
	int j = 0;
	int k = 0;
 
	while (j < i - 1)
	{
		s.data[j] = data[j];
		++j;
	}
 
	while (str[k] != '\0')
	{
		s.data[j] = str[k];
		++j;
		++k;
	}
 
	k = i - 1;
 
	while (k < length)
	{
		s.data[j] = data[k];
		++j;
		++k;
	}
 
	s.length = j;
	return s;
}
 
SqStringClass &SqStringClass::StrIns(int i, const SqStringClass &str) const
{
	static SqStringClass s;
 
	if (i < 1 || i > length + 1)
	{
		return s;
	}
 
	int j = 0;
	int k = 0;
 
	while (j < i - 1)
	{
		s.data[j] = data[j];
		++j;
	}
 
	while (k < str.length)
	{
		s.data[j] = str.data[k];
		++j;
		++k;
	}
 
	k = i - 1;
 
	while (k < length)
	{
		s.data[j] = data[k];
		++j;
		++k;
	}
 
	s.length = j;
	return s;
}
 
SqStringClass &SqStringClass::StrDel(int i, int len) const
{
	static SqStringClass s;
 
	if (i < 1 || len < 0 || i + len - 1 > length)
	{
		return s;
	}
 
	int j = 0;
	int k = i - 1 + len;
 
	while (j < i - 1)
	{
		s.data[j] = data[j];
		++j;
	}
 
	while (k < length)
	{
		s.data[j] = data[k];
		++j;
		++k;
	}
 
	s.length = j;
	return s;
}
 
SqStringClass &SqStringClass::StrSub(int i, int len) const
{
	static SqStringClass s;
 
	if (i < 1 || len < 0 || i - 1 + len > length)
	{
		return s;
	}
 
	int j = 0;
	int k = i - 1;
 
	while (k < i - 1 + len)
	{
		s.data[j] = data[k];
		++j;
		++k;
	}
 
	s.length = j;
	return s;
}
 
SqStringClass &SqStringClass::StrRep(int i, int len, const char *str) const
{
	static SqStringClass s;
 
	if (i < 1 || len < 0 || i - 1 + len > length)
	{
		return s;
	}
 
	int j = 0;
	int k = 0;
 
	while (j < i)
	{
		s.data[j] = data[j];
		++j;
	}
 
	while (str[k] != '\0')
	{
		s.data[j] = str[k];
		++j;
		++k;
	}
 
	k = i - 1 + len;
 
	while (k < length)
	{
		s.data[j] = data[k];
		++j;
		++k;
	}
 
	s.length = j;
	return s;
}
 
SqStringClass &SqStringClass::StrRep(int i, int len, const SqStringClass &str) const
{
	static SqStringClass s;
 
	if (i < 1 || len < 0 || i - 1 + len > length)
	{
		return s;
	}
 
	int j = 0;
	int k = 0;
 
	while (j < i)
	{
		s.data[j] = data[j];
		++j;
	}
 
	while (k < str.length)
	{
		s.data[j] = str.data[k];
		++j;
		++k;
	}
 
	k = i - 1 + len;
 
	while (k < length)
	{
		s.data[j] = str.data[k];
		++j;
		++k;
	}
 
	s.length = j;
	return s;
}
 
void SqStringClass::Display(void) const
{
	for (int i = 0; i < length; ++i)
	{
		cout << data[i];
	}
 
	cout << endl;
}
 
SqStringClass &SqStringClass::operator=(const SqStringClass &str)
{
	if (&str != this)
	{
		for (int i = 0; i < str.length; ++i)
		{
			data[i] = str.data[i];
		}
 
		length = str.length;
	}
 
	return *this;
}
 
SqStringClass &SqStringClass::operator=(const char *str)
{
	int i = 0;
 
	while (str[i] != '\0')
	{
		data[i] = str[i];
		++i;
	}
 
	length = i;
	return *this;
}
 
SqStringClass &SqStringClass::operator+(const SqStringClass &str) const
{
	static SqStringClass s;
	int i = 0;
	int j = 0;
 
	while (i < length)
	{
		s.data[i] = data[i];
		++i;
	}
 
	while (j < str.length)
	{
		s.data[i] = str.data[j];
		++i;
		++j;
	}
 
	s.length = i;
	return s;
}
 
SqStringClass &SqStringClass::operator+(const char *str) const
{
	static SqStringClass s;
	int i = 0;
	int j = 0;
 
	while (i < length)
	{
		s.data[i] = data[i];
		++i;
	}
 
	while (str[j] != '\0')
	{
		s.data[i] = str[j];
		++i;
		++j;
	}
 
	s.length = i;
	return s;
}
 
char &SqStringClass::operator[](int i)
{
	return data[i];
}
 
SqStringClass::operator char *(void) const
{
	static char *s = new char[length + 1];
 
	for (int i = 0; i < length; ++i)
	{
		s[i] = data[i];
	}
 
	s[length] = '\0';
	return s;
}
 
istream &operator>>(istream &in, SqStringClass &str)
{
	char c;
	int i = 0;
 
	while ((c = in.get()) != '\n')
	{
		str.data[i++] = c;
	}
 
	str.length = i;
	return in;
}
 
ostream &operator<<(ostream &out, const SqStringClass &str)
{
	for (int i = 0; i < str.length; ++i)
	{
		out << str.data[i];
	}
 
	return out;
}

int main()
{
	SqStringClass S0("打印Hello World");
	SqStringClass S1("#include");
	SqStringClass S2("<>\n");
	SqStringClass S3("\"\"\n");
	SqStringClass S4("using namespace std;\n");
	SqStringClass S5("int main(void)\n");
	SqStringClass S6("{\n");
	SqStringClass S7("    cout << ");
	SqStringClass S8("Hello World!");
	SqStringClass S9(" << endl;\n");
	SqStringClass S10("}");
	SqStringClass S11("iostream");
	SqStringClass S12("SqStringClass.h");
	SqStringClass S13(S0.StrDel(1, 4));
 
	/* cout << (S1 + S2) << (S1 + S3) << S4 << S5 << S6 << S7 << S8 << S9 << S10 << endl; */
	/* error, 由于运算顺序S1 + S2和S1 + S3存放到了同一变量static SqStringClass s里导致覆盖 */
	cout << S0 << endl;
	cout << S1 + S2.StrIns(2, S11);
	cout << S1 + S3.StrIns(2, S12) << S4 << S5 << S6 << S7 << S8 << S9 << S10 << endl;
	cout << S13.StrIns(S13.StrLength() + 1, "!") << endl;
 
	system("PAUSE");
	return 0;
}
 