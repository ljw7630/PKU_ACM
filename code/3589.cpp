#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);	
	int t;
	string s1,s2;;
	scanf("%d",&t);
	while(t--)
	{
		cin >> s1 >> s2;
		int c=0,m=0;
		string::iterator it;
		for(int i=0;i<4;++i)
		{
			int it=s1.find(s2[i]);
			if(it==i)
			{
				c++;
			}
			else if(it!=-1)
			{
				m++;
			}
		}
		printf("%dA%dB\n",c,m);
	}
	return 0;
}