#include <iostream>
#include <cmath>
using namespace std;
char str[35];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%s",str)!=EOF)
	{
		int sum=0;
		int len=strlen(str);
		if(len==1)
			if(str[0]=='0')
				break;
		for(int i=0;str[i];++i)
		{
			int temp=1;
			for(int i=1;i<=len;++i)
				temp*=2;
			sum+=(str[i]-'0')*(temp-1);
			len--;
		}
		printf("%d\n",sum);
	}
	return 0;
}