#include <iostream>
using namespace std;
char c[10];
int num[3]={9,3,7};
int n;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int count=0;
	scanf("%d",&n);
	while(n--)
	{
		printf("Scenario #%d:\n",++count);
		scanf("%s",c);
		int len=strlen(c);
		int k1=0,k2=0,sum=0,t=0;
		for(int i=len-1;i>-1;--i)
		{
			if(c[i]=='?')
			{
				k1=i;
				k2=num[t++];
			}
			else
				sum+=(c[i]-'0')*num[t++];
			if(t==3)
				t=0;
		}
		for(int i=0;i<10;++i)
		{
			if((sum+i*k2)%10==0)
				c[k1]=i+'0';
		}
		printf("%s\n\n",c);
	}
	return 0;
}