#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char s[20];
bool a[20],t[20];

void flip(int j)
{
	a[j]^=1;
	if(j>3)
		a[j-4]^=1;
	if(j<12)
		a[j+4]^=1;
	if(j%4)
		a[j-1]^=1;
	if(j%4!=3)
		a[j+1]^=1;
}

bool ok()
{
	int sum=0;
	for(int i=0;i<16;++i)
	{
		sum+=a[i];
	}
	if(!sum||sum==16)
		return true;
	return false;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	for(int i=0;i<4;++i)
	{
		scanf("%s",s);
		for(int j=0;j<4;++j)
			if(s[j]=='b')
				a[i*4+j]=t[i*4+j]=1;
	}
	if(ok())
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<17;++i)
	{
		memset(s,0,sizeof(s));
		for(int j=0;j<i;++j)
		{
			s[15-j]=1;
		}
		do
		{
			memcpy(a,t,sizeof(a));
			for(int j=0;j<16;++j)
				if(s[j])
					flip(j);
			if(ok())
			{
				printf("%d\n",i);
				return 0;
			}
		}while(next_permutation(s,s+16));
	}
	printf("Impossible\n");

	return 0;
}