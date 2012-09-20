#include <iostream>
using namespace std;
int n,m;
int topo[27],deg[27],matrix[27][27];
char str[5];

int toposort()
{
	int i,j,temp[27],num,u,now=0;
	bool sign=false;
	memset(topo,0,sizeof(topo));
	for(i=1;i<=n;i++)
		temp[i]=deg[i];
	for(i=1;i<=n;i++)
	{
		num=0;
		for(j=1;j<=n;j++)
		{
			if(temp[j]==0)
			{
				u=j;
				num++;
			}
		}
		if(num==0)
			return 0;
		if(num>1)
			sign=true;
		temp[u]=-1;
		topo[now++]=u;
		for(int v=1;v<=n;v++)
		{
			if(matrix[u][v]==1)
				temp[v]--;
		}
	}
	if(sign)
		return -1;
	return 1;

}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,u,v,res;
	bool flag;
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0)
	{
		memset(deg,0,sizeof(deg));
		memset(matrix,0,sizeof(matrix));
		flag=false;
		for(i=1;i<=m;i++)
		{
			scanf("%s",&str);
			if(flag)
				continue;
			u=str[0]-'A'+1;
			v=str[2]-'A'+1;
			matrix[u][v]=1;
			deg[v]++;
			res=toposort();
			if(res==0)
			{
				printf("Inconsistency found after %d relations.\n",i);
				flag=1;
			}
			else if(res==1)
			{
				printf("Sorted sequence determined after %d relations: ",i);
				for(j=0;j<n;j++)
				{
					printf("%c",topo[j]+'A'-1);
				}
				printf(".\n");
				flag=1;
			}
		}
		if(!flag)
		{
			printf("Sorted sequence cannot be determined.\n");
		}
	}
	return 0;
}
