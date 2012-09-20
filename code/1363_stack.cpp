#include <iostream>
using namespace std;
int n,x[1002],y[1002],c[1002];
int topx,topy,topc;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	bool flag;
	while(scanf("%d",&n)!=EOF&&n)
	{
		while(scanf("%d",&x[n-1])&&x[n-1])
		{
			flag=false;
			topx=topy=n-1;
			topc=-1;
			for(int i=n-2;i>-1;--i)
				scanf("%d",&x[i]);
			for(int i=n-1;i>-1;--i)
				y[i]=n-i;
			while(topx>=0&&topy>=0)
			{
				if(y[topy]==x[topx])
					topy--,topx--;
				else if(y[topy]<x[topx])
				{
					while(y[topy]!=x[topx])
					{
						c[++topc]=y[topy--];
					}
					topy--,topx--;
				}
				else if(y[topy]>x[topx])
				{
					if(topc>-1&&c[topc]==x[topx])
						topc--,topx--;
					else
					{
						printf("No\n");
						flag=true;
						break;
					}
				}
			}
			if(topx<=0)
			{
				printf("Yes\n");
			}
			else if(topy<=0&&!flag)
			{
				while(topx!=-1)
				{
					if(x[topx--]!=c[topc--])
					{
						printf("No\n");
						break;
					}
				}
				if(topx==-1)
					printf("Yes\n");
			}
		}
		printf("\n");
	}
	return 0;
}