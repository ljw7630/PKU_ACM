#include <iostream>
#include <vector>
using namespace std;

class STAMP
{
public:
	int n;
	vector<int>vec;
	int mini;
	int maxi;
};

int solve(int num,vector<int> &vec,int up,int down)
{
	bool dp[11][10005];
	memset(dp,false,sizeof(dp));
	for(int i=0;i<vec.size();++i)
	{
		dp[num-1][vec[i]]=true;
	}
	for(int i=num-2;i>=0;--i)
	{
		for(int j=down;j<=up*(num-i-1);++j)
		{
			for(int k=0;k<vec.size();++k)
			{
				if(dp[i+1][j])
				{
					dp[i][j]=true;
					dp[i][j+vec[k]]=true;
				}
			}
		}
	}
	int c=0;
	for(int i=down;i<=up*num;++i)
	{
		if(dp[0][i])
			c++;
		else
			break;
	}
	return c;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int temps,tempn,num,t,mini,maxi,bestid,bestres,tempres;
	while(scanf("%d",&temps)!=EOF&&temps)
	{
		STAMP stamp[11];
		bestres=-1;
		scanf("%d",&tempn);
		for(int i=0;i<tempn;++i)
		{
			scanf("%d",&num);
			stamp[i].n=num;
			stamp[i].mini=INT_MAX;
			stamp[i].maxi=0;
			for(int j=0;j<num;++j)
			{
				scanf("%d",&t);
				stamp[i].vec.push_back(t);
				if(t<stamp[i].mini)
					stamp[i].mini=t;
				if(t>stamp[i].maxi)
					stamp[i].maxi=t;
			}
			tempres=solve(temps,stamp[i].vec,stamp[i].maxi,stamp[i].mini);
			if(tempres>bestres)
			{
				bestid=i;
				bestres=tempres;
			}
			else if(tempres==bestres)
			{
				if(stamp[i].n<stamp[bestid].n)
				{
					bestid=i;
					bestres=tempres;
				}
				else if(stamp[i].n==stamp[bestid].n)
				{
					if(stamp[i].maxi<stamp[bestid].maxi)
					{
						bestid=i;
						bestres=tempres;
					}
				}
			}
		}
		printf("max coverage = %d :",bestres);
		for(int i=0;i<stamp[bestid].n;++i)
		{
			cout << " " << stamp[bestid].vec[i];
		}
		printf("\n");
	}
	return 0;
}