#include <iostream>
using namespace std;

int k,len,n,i,j,changeLen,t;
int people[30];
int temp[10000],count,result[13];

bool check()
{
	for(i=0;i<len;i++)
		people[i]=i;

	for(i=0,j=0,changeLen=len;i<k;i++)
	{
		j=(j+n-1)%changeLen;
		if(people[j]<k)
			return true;
		for(t=j;t<changeLen-1;t++)
			people[t]=people[t+1];
		changeLen--;
	}
	result[k]=n;
	return false;
}

bool isIn()
{
	for(i=0;i<count-1;i++)
	{
		if(k==temp[i])
		{
			return true;
		}
	}
	return false;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	count=0;
	while(scanf("%d",&k)!=EOF&&k!=0)
	{
		temp[count++]=k;
		len=2*k;
		n=k+1;

		if(!isIn())
		{
			while(check())
			{
				n++;
			}
		}
	}
	for(i=0;i<count;i++)
	{
		printf("%d\n",result[temp[i]]);
	}
	return 0;
}