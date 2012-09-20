#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int t,n,i,j;
	int record[21];
	int table[21];
	table[0]=1;
	for(int i=1;i<21;++i)
		table[i]=table[i-1]*3;
	scanf("%d",&t);
	while(t--)
	{
		memset(record,0,sizeof(record));
		scanf("%d",&n);
		int index=0;
		while(n)
		{
			record[index++]=n%3;
			n/=3;
		}
		for(i=0;i<index;++i)
		{
			if(record[i]==2)
			{
				record[i]=-1;
				record[i+1]++;
			}
			else if(record[i]==3)
			{
				record[i]=0;
				record[i+1]++;
			}
		}
		for(i=0;i<index+1;++i)
		{
			if(record[i]<0)
			{
				printf("%d",table[i]);
				break;
			}
		}
		if(i==index+1)
			printf("empty");
		else
		{
			for(j=i+1;j<index+1;++j)
				if(record[j]<0)
					printf(",%d",table[j]);
		}
		for(i=0;i<index+1;++i)
		{
			if(record[i]>0)
			{
				printf(" %d",table[i]);
				break;
			}
		}
		if(i==index+1)
			printf(" empty");
		else
		{
			for(j=i+1;j<index+1;++j)
				if(record[j]>0)
					printf(",%d",table[j]);
		}
		printf("\n");
	}
	return 0;
}