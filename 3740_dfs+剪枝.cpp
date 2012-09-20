#include <iostream>
using namespace std;

int m,n,globalcount;
int colsum[355],cal[20];
bool mustrow[20],mustcol[355],map[20][355];
bool globalflag;

void dfs(int index)
{
	if(index>=n)
		return;
	int j;
	for(int i=index;i<m;++i)
	{
		bool flag=true;
		for(j=0;j<n;++j)
		{
			if(map[i][j])
			{
				if(mustcol[j]==false)
					mustcol[j]=true;
				else
				{
					flag=false;
					break;
				}
			}
		}
		if(flag)
		{
			globalcount+=cal[i];
			if(globalcount==n)
			{
				globalflag=true;
				return;
			}
			else if(globalcount>n)
			{
				return;
			}
			else
			{
				dfs(i+1);
			}
			globalcount-=cal[i];
			if(globalflag)
				return;
		}
		for(int k=0;k<j;++k)  // 就是这里,把有效位才置0
		{
			if(map[i][k])
			{
				mustcol[k]=false;
			}
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		memset(mustrow,false,sizeof(mustrow));
		memset(mustcol,false,sizeof(mustcol));
		memset(colsum,0,sizeof(colsum));
		memset(cal,0,sizeof(cal));
		for(int i=0;i<m;++i)
		{
			for(int j=0;j<n;++j)
			{
				scanf("%d",&map[i][j]);
				if(map[i][j])
				{
					colsum[j]++;
					cal[i]++;
				}
			}
		}
		bool flag=true;
		int c=0;
		for(int j=0;j<n;++j)
		{
			if(colsum[j]==0)
			{
				flag=false;
			}
			else if(colsum[j]==1)
			{
				for(int i=0;i<m;++i)
				{
					if(map[i][j])
					{
						if(!mustrow[i])
						{
							mustrow[i]=true;
							for(int k=0;k<n;++k)
							{
								if(map[i][k])
								{
									if(mustcol[k]==true)
									{
										flag=false;
										break;
									}
									else
									{
										mustcol[k]=true;
										c++;
									}
								}
							}
							break;
						}
						else
							break;
					}
				}
			}
			if(!flag)
				break;
		}
		if(!flag)
			printf("It is impossible\n");
		else if(c==n)
			printf("Yes, I found it\n");
		else
		{
			memset(mustrow,false,sizeof(mustrow));
			memset(mustcol,false,sizeof(mustcol));
			globalflag=false;
			globalcount=0;
			dfs(0);
			if(!globalflag)
				printf("It is impossible\n");
			else
				printf("Yes, I found it\n");
		}
	}
	return 0;
}
