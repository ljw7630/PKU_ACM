//保证根节点永远是0:
//对于x
//如果是y的朋友,那么原根节点被置为y的敌人
//否则因为y与x是敌人,所以原根节点被置为新根的朋友
//原来与parent的relation如果是朋友
//那么(relation[x]+relation[parent])%2在更新的时候不变
//如果与原来的parent是敌人:
//1.如果根节点与x是朋友
//(1+new parent relation==1)%2就变成0
//2.如果根节点与x是敌人
//那么parent还是0 所以relation[x]还是1

#include <iostream>
using namespace std;
const int maxn=1e5+2;
int father[maxn];
int relation[maxn];

int findset(int p)
{
	if(father[p]!=p)
	{
		int pa=father[p];
		father[p]=findset(father[p]);
		relation[p]=(relation[p]+relation[pa])%2;
	}
	return father[p];
}

void unionset(int x,int y,int fax,int fay)
{
	father[fax]=fay;
	relation[fax]=(relation[y]-relation[x]+3)%2;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,n,m,x,y,fax,fay;
	char ch;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			father[i]=i,relation[i]=0;
		for(int i=0;i<m;++i)
		{
			scanf("%*c%c%d%d",&ch,&x,&y);
			fax=findset(x);
			fay=findset(y);
			if(ch=='D')
			{
				if(fax!=fay)
					unionset(x,y,fax,fay);
			}
			else if(ch=='A')
			{
				if(fax!=fay)
					printf("Not sure yet.\n");
				else if(relation[x]==relation[y])
					printf("In the same gang.\n");
				else
					printf("In different gangs.\n");
			}
		}
	}
	return 0;
}