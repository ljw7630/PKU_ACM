#include <iostream>
#include <string>
using namespace std;

const double exp=1e-8;
int cnum,tnum,f,t,count;
string name[35],from,to;
double map[35][35],c;

void floyd()
{
	for(int k=0;k<tnum;++k)
	{
		for(int i=0;i<tnum;++i)
		{
			for(int j=0;j<tnum;++j)
			{
				if(map[i][j]<map[i][k]*map[k][j])
					map[i][j]=map[i][k]*map[k][j];
			}
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	count=0;
	while(cin>>tnum&&tnum>0)
	{
		memset(map,0,sizeof(map));
		for(int i=0;i<tnum;++i)
		{
			cin>>name[i];
		}
		cin>>cnum;
		for(int i=0;i<cnum;++i)
		{
			cin>>from>>c>>to;
			for(int j=0;j<tnum;++j)
			{
				if(name[j]==from)
					f=j;
				if(name[j]==to)
					t=j;
			}
			map[f][t]=max(map[f][t],c);
		}
		for(int i=0;i<tnum;++i)
			map[i][i]=max(map[i][i],1.0);
		floyd();
		int tt;
		for(tt=0;tt<tnum;++tt)
		{
			if(map[tt][tt]-exp>1.0)
				break;
		}
		if(tt!=tnum)
			printf("Case %d: Yes\n",++count);
		else
			printf("Case %d: No\n",++count);
	}
	return 0;
}