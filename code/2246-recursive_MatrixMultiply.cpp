#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct MATRIX
{
	int l;
	int r;
	int res;
	friend MATRIX operator *(MATRIX a,MATRIX b)
	{
		MATRIX temp;
		if(a.l==0||a.r==0)
			return b;
		if(b.l==0||b.r==0)
			return a;
		temp.l=a.l;
		temp.r=b.r;
		if(a.r!=b.l||a.res==-1||b.res==-1)
			temp.res=-1;
		else
			temp.res=a.l*a.r*b.r+a.res+b.res;
		return temp;
	}
}ma[27];

MATRIX cal(string str)
{
	MATRIX a;
	if(str.empty())
	{
		a.l=0,a.r=0,a.res=0;
		return a;
	}
	a=ma[str[0]-'A'];
	for(int i=1;i<str.size();++i)
	{
		if(a.r!=ma[str[i]-'A'].l)
		{
			a.res=-1;
			return a;
		}
		a.res=a.res+a.l*a.r*ma[str[i]-'A'].r;
		a.r=ma[str[i]-'A'].r;
	}
	return a;
}

MATRIX eval(string str)
{
	MATRIX temp;
	int i,j;
	for(i=0;i<str.size();++i)
	{
		if(str[i]=='(')
			break;
	}
	if(i==str.size())
	{
		return cal(str);
	}
	else
	{
		int c=0;
		for(j=i+1;j<str.size();++j)
		{
			if(str[j]=='(')
			{
				c++;
			}
			else if(str[j]==')')
			{
				if(c==0)
					break;
				else
					--c;
			}
		}
		string t2;
		for(int k=i+1;k<j;++k)
		{
			t2.push_back(str[k]);
		}
		string t1,t3;
		if(i!=0)
		{
			for(int k=0;k<i;++k)
				t1.push_back(str[k]);
		}
		if(j!=str.size()-1)
		{
			for(int k=j+1;k<str.size();++k)
				t3.push_back(str[k]);
		}
		return eval(t1)*eval(t2)*eval(t3);
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,l,r;
	char id;
	string str;
	cin >> n;
	for(int i=0;i<n;++i)
	{
		cin >> id >> l >> r;
		ma[id-'A'].l=l;
		ma[id-'A'].r=r;
		ma[id-'A'].res=0;
	}
	while(cin >> str)
	{
		MATRIX temp=eval(str);
		if(temp.res<0)
			cout << "error" << endl;
		else
			cout << temp.res << endl;
	}
	return 0;
}