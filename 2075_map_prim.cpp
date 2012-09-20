#include <iostream>
#include <string>
#include <map>
using namespace std;
map <string,int> mymap;

double themap[1001][1001];
double res;

double prim(int v,int n)
{
	double lowcost[1001];
	for(int i=2;i<=n;++i)
		lowcost[i]=themap[v][i];
	lowcost[1]=-1.0;
	double mini;
	int u=0;
	double sum=0.0;
	for(int i=0;i<n-1;++i)
	{
		mini=1000000000;
		for(int j=1;j<=n;++j)
		{
			if(lowcost[j]+1-0.0<1e-6)
				continue;
			if(mini>lowcost[j])
			{
				mini=lowcost[j];
				u=j;
			}
		}
		lowcost[u]=-1;
		sum+=mini;
		for(int j=1;j<=n;++j)
		{
			if(themap[u][j]<lowcost[j])
				lowcost[j]=themap[u][j];
		}
	}
	return sum;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	double cable;
	int n,edge;
	string t1,t2;
	while(cin >> cable)
	{
		for(int i=0;i<1001;++i)
			for(int j=0;j<1001;++j)
				themap[i][j]=1000000000;
		mymap.clear();
		cin >> n;
		for(int i=1;i<=n;++i)
		{
			cin >> t1;
			mymap[t1]=i;
		}
		cin >> edge;
		double len;
		for(int i=0;i<edge;++i)
		{
			cin >> t1 >> t2 >> len;
			themap[mymap[t1]][mymap[t2]]=len;
			themap[mymap[t2]][mymap[t1]]=len;
		}
		res=prim(1,n);
		if(res>cable)
			printf("Not enough cable\n");
		else
			printf("Need %.1lf miles of cable\n",res);
	}
}