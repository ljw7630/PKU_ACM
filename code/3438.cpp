#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	string str;
	string res;
	scanf("%d",&n);
	while(n--)
	{
		cin >> str;
		res.clear();
		int index=0;
		int count=1;
		for(int i=1;i!=str.size()+1;++i)
		{
			if(str[i]!=str[index])
			{
				stringstream s;
				string ss;
				s << count;
				s >> ss;
				res+=ss+str[index];
				index=i;
				count=1;
			}
			else
			{
				count++;
			}
		}
		cout << res << endl;
	}
	return 0;
}