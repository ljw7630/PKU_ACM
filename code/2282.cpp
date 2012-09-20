#include <iostream>
using namespace std;

int s,e,digit[11];

void find(int num,int w)
{
	int inc=num%10;
	for(int i=1;i<=inc;++i)
		digit[i]+=w;
	num/=10;
	int temp=num;
	while(temp)
	{
		digit[temp%10]+=(inc+1)*w;
		temp/=10;
	}
	for(int i=0;i<10;++i)
		digit[i]+=num*w;
	w*=10;
	if(num-1>0)
		find(num-1,w);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	while(scanf("%d%d",&s,&e)!=EOF&&(s||e))
	{
		memset(digit,0,sizeof(digit));
		if(s>e)
		{
			swap(s,e);
		}
		find(s-1,-1);
		find(e,1);
		printf("%d",digit[0]);
		for(int i=1;i<10;++i)
			printf(" %d",digit[i]);
		printf("\n");
	}
	return 0;
}