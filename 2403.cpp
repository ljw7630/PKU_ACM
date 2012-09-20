#include <iostream>
#include <string>
#include <map>
using namespace std;

int sum;
int n,m;
map<string,int>mymap;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string str;
	int money;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		while(m--)
		{
			cin >> str >> money;
			mymap[str]=money;
		}
		while(n--)
		{
			sum=0;
			while(true)
			{
				cin >> str;
				if(str==".")
					break;
				map<string,int>::const_iterator itr=mymap.find(str);
				if(itr!=mymap.end())
					sum+=itr->second;
			}
			cout << sum << endl;
		}
	}
	return 0;
}