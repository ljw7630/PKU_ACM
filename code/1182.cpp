#include <iostream>
using namespace std;

int n,k,d,x,y,rx,ry;
int p[50005],kind[50005];

int FIND(int t)
{
	int temp;
	if(p[t]==-1)
		return t;
	else
	{
		temp=FIND(p[t]);
		kind[t]=(kind[p[t]]+kind[t])%3;
		p[t]=temp;
		return temp;
	}	
}

void UNION(int x,int y)
{
	p[ry]=rx;
	kind[ry]=(kind[x]-kind[y]+3+d-1)%3;
	return;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int count=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		p[i]=-1,kind[i]=0;
	for(int i=0;i<k;++i)
	{
		scanf("%d%d%d",&d,&x,&y);
		if(x>n||y>n)
		{
			count++;
			continue;
		}
		rx=FIND(x);
		ry=FIND(y);
		if(rx==ry)
		{
			if(d==1&&kind[x]!=kind[y])
			{
				count++;
				continue;
			}
			if(d==2&&(kind[x]-kind[y]+3)%3!=2)
			{
				count++;
				continue;
			}
		}
		else
		{
			UNION(x,y);
		}
	}
	printf("%d\n",count);
	return 0;
}