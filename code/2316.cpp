#include <iostream>
#include <string>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string str;
	cin>>str;
	string res(str);
	while(cin>>str)
	{
		for(int i=0;i<str.size();++i)
		{
			res[i]+=str[i]-'0';
			if(res[i]>'9')
				res[i]-=10;
		}
	}
	cout << res << endl;
}