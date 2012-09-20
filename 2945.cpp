#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str[20005];
int mcount[20005];
int n,m;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF&&n)
	{
		memset(mcount,0,sizeof(mcount));
		for(int i=0;i<n;++i)
			cin>>str[i];
		sort(str,str+n);
		int c=0;
		string t=str[0];
		for(int i=0;i<n;++i)
		{
			if(t==str[i])
				c++;
			else
			{
				t=str[i];
				mcount[c-1]++;
				c=1;
			}
		}
		mcount[c-1]++;
		for(int i=0;i<n;++i)
			printf("%d\n",mcount[i]);
	}
	return 0;
}