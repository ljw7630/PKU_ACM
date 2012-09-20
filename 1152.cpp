//n-1|x+y <=> n-1|(n-1)x+(x+y) <=> n-1|nx+y

#include <iostream>
using namespace std;

char str[36000];
int maxi,i;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%s",str)!=EOF)
	{
		maxi=0;
		long sum=0;
		for(i=0;str[i]!='\0';++i)
		{
			if(str[i]>='0'&&str[i]<='9')
				str[i]=str[i]-'0';
			else if(str[i]>='A' && str[i]<='Z')
				str[i]=str[i]-'A'+10;
			else if(str[i]>='a'&&str[i]<='z')
				str[i]=str[i]-'a'+36;
			if(str[i]>maxi)
				maxi=str[i];
			sum+=str[i];
		}
		int res=maxi+1;
		for(;res<63;++res)
		{
			if(sum%(res-1)==0)
			{
				printf("%d\n",res);
				break;
			}
		}
		if(res==63)
			printf("such number is impossible!\n");
	}
	return 0;
}