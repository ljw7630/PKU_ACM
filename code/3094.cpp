#include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(getline(cin,s)&&s[0]!='#')
	{
		int sum=0;
		for(int i=0;i<s.length();++i)
		{
			if(s[i]==' ')
				continue;
			else
			{
				sum+=(i+1)*(s[i]-'A'+1);
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}