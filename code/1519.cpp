#include <iostream>
using namespace std;
int n,len;
char s[1000001];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%s",&s)!=EOF&&s[0]!='0')
	{
		n=0;
		len=strlen(s);
		for(int i=0;i<len;i++)
			n+=s[i]-'0';
		n=n%9;
		if(n==0)
			printf("9\n");
		else
			printf("%d\n",n);
	}
	return 0;
}