#include <iostream>
#include <algorithm>
using namespace std;

const int size=21;
int n;
int sq[size];
int start;
bool visit[size];

bool cmp(int a,int b)
{
	return a>b;
}

bool dfs(int m,int left,int len)
{
	if(m==0&&left==0)
		return true;
	int i;
	if(left==0)
	{
		i=0;
		left=len;
	}
	else
		i=start+1;
	for(;i<n;++i)
	{
		if(visit[i]||left<sq[i])
			continue;
		start=i;
		visit[i]=true;
		if(dfs(m-1,left-sq[i],len))
			return true;
		else
			visit[i]=false;
		if(left==sq[i]||left==len)
			break;
	}
	return false;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int sum=0;
		for(int i=0;i<n;++i)
		{
			cin >> sq[i];
			sum+=sq[i];
		}
		if(sum%4)
		{
			cout << "no" << endl;
			continue;
		}
		sort(sq,sq+n,cmp);
		if(dfs(n,0,sum/4))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
		fill(visit,visit+n,0);
	}
	return 0;
}