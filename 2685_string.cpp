#include <iostream>
#include <string>
using namespace std;

struct change
{
	char ch;
	int value;
}c[4];

int n;
char a[10],b[10],res[10];
int aa,bb,cc;

void changetostr(int v)
{
	memset(res,0,sizeof(res));
	int i,t,count=0;

	for(i=0;i<4;++i)
	{
		t=v/c[i].value;
		if(t!=0)
		{
			if(t==1)
				res[count++]=c[i].ch;
			else
			{
				res[count++]=t+'0';
				res[count++]=c[i].ch;
			}
		}
		v%=c[i].value;
	}
	res[count]='\0';
}

int translate(char s[])
{
	int i,j,k;
	int len=strlen(s);
	int sum=0;
	for(i=0;i<len;++i)
	{
		for(j=0;j<4;++j)
		{
			if(s[i]==c[j].ch)
			{
				sum+=c[j].value;
				break;
			}
		}
		if(j==4)
		{
			for(k=0;k<4;++k)
			{
				if(s[i+1]==c[k].ch)
				{
					sum+=(s[i]-'0')*c[k].value;
					break;
				}
			}
			i++;
		}
	}
	return sum;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	c[0].ch='m',c[0].value=1000;
	c[1].ch='c',c[1].value=100;
	c[2].ch='x',c[2].value=10;
	c[3].ch='i',c[3].value=1;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s%s",a,b);
		aa=translate(a);
		bb=translate(b);
		cc=aa+bb;
		changetostr(cc);
		printf("%s\n",res);
	}
	return 0;
}
