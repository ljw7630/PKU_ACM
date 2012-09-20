#include <iostream>
#include <string>
using namespace std;
string e,str;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(getline(cin,e))
	{
		getline(cin,str);
		for(int i=0;i<str.length();++i)
		{
			if(str[i]>='A'&&str[i]<='Z')
			{
				str[i]=e[str[i]-'A']+'A'-'a';
			}
			else if(str[i]>='a'&&str[i]<='z')
			{
				str[i]=e[str[i]-'a'];
			}
		}
		cout << str;
	}
	return 0;
}