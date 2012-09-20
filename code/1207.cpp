#include <iostream>
using namespace std;
int i,j,ti,tj;

int cycle(int m)
{
	int count=1;
	while(m!=1)
	{
		if(m%2==0)
			m/=2;
		else
			m=3*m+1;
		count++;
	}
	return count;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int m,n,maxcycle,res;
	while(scanf("%d%d",&ti,&tj)!=EOF)
	{
		if(ti>tj)
		{
			i=tj;
			j=ti;
		}
		else
		{
			i=ti;
			j=tj;
		}
		maxcycle=0;
		for(m=i;m<=j;m++)
		{
			res=cycle(m);
			if(res>maxcycle)
				maxcycle=res;
		}
		printf("%d %d %d\n",ti,tj,maxcycle);
	}
	return 0;
}