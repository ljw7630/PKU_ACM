#include <iostream>
#include <string>
using namespace std;
int b;
string num;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>b&&b)
	{
		cin >> num;
		int x=0,y=0;
		for(int i=0;i!=num.length();++i)
		{
			x+=num[i]-'0';
		}
		for(int i=0;i!=num.length();++i)
		{
			y=y*b+num[i]-'0';
			y%=x;
		}
		if(!y)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}