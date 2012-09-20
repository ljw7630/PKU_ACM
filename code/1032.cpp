#include <iostream>
using namespace std;
int N;
int store[1000];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,sum,pos,temp;
	while(scanf("%d",&N)!=EOF)
	{
		sum=0;
		pos=0;
		for(i=2;;i++)
		{
			sum+=i;
			if(sum>N)
				break;
			else
				store[pos++]=i;
		}
		sum-=i;
		N-=sum;
		temp=pos;
		while(N!=0)
		{
			store[--temp]++;
			N--;
			if(temp==0)
				temp=pos;
		}
		for(i=0;i<pos;i++)
		{
			printf("%d",store[i]);
			if(i!=pos-1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}