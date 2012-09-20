//Ҫʹa1x1+a2x2+..+akxk=1
//��ʹx1,x2..xkΪ������
//�൱��res=m^n-{�й�Լ��Ϊ2��nԪ��}..-{�����й�Լ����nԪ��}
//���������й�Լ��Ϊd��nԪ�飬������Ԫ�ص�����Ϊ(m/d)^n

#include <iostream>
#include <cmath>
using namespace std;

__int64 n,m;
__int64 len,tempres;
int p[130000],now[130000];

void getprime(__int64 s)
{
	len=0;
	for(int i=2;i*i<=s;++i)
	{
		if(s%i==0)
		{
			while(s%i==0)
				s/=i;
			p[len++]=i;	
		}
	}
	if(s!=1)
		p[len++]=s;
}

__int64 thepow(__int64 x,__int64 y) // x^y
{
	__int64 t=x;
	for(__int64 i=1;i<y;++i)
		t=t*x;
	return t;
}

void get(__int64 a,__int64 b,__int64 c)  // a��ǰ���������index��b��ǰ��������c�����ܸ���
{
	if(b==c)
	{
		__int64 t=m;
		for(__int64 i=0;i<c;++i)
		{
			t/=now[i];
		}
		tempres+=thepow(t,n);
	}
	else
	{
		for(__int64 i=a;i<len;++i)
		{
			now[b]=p[i];
			get(i+1,b+1,c);
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	__int64 res;
	while(scanf("%I64d%I64d",&n,&m)!=EOF)
	{
		res=thepow(m,n);
		getprime(m);
		for(__int64 i=0;i<len;++i)
		{
			tempres=0;
			get(0,0,i+1);
			if(i%2==0)
			{
				res-=tempres;
			}
			else
			{
				res+=tempres;
			}
		}
		printf("%I64d\n",res);
	}
	return 0;
}

