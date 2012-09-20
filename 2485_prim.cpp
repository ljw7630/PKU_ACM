#include <iostream>
using namespace std;

int n;
int map[505][505];
int closest[505];
bool isconnect[505];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(isconnect,false,sizeof(isconnect));
		memset(closest,0,sizeof(closest));
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				scanf("%d",&map[i][j]);
			}
		}
		isconnect[0]=true;
		int sum=0,mini,pos=0,rec=0;
		for(int i=0;i<n-1;++i)
		{
			mini=INT_MAX;
			for(int j=1;j<n;++j)
			{
				if(map[j][closest[j]]<mini&&!isconnect[j])
				{
					pos=j;
					mini=map[j][closest[j]];
				}
			}
			if(rec<mini)
				rec=mini;
			isconnect[pos]=true;
			for(int k=1;k<n;++k)
			{
				if(map[k][pos]<map[k][closest[k]]&&!isconnect[k])
				{
					closest[k]=pos;
				}
			}
		}
		printf("%d\n",rec);
	}
	return 0;
}