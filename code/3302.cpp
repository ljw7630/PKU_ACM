#include <iostream>
using namespace std;

int t;
char s1[105],s2[105];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",&s1,&s2);
		int len1=strlen(s1);
		int len2=strlen(s2);
		int c1=0,c2=len2-1,j;
		bool flag=false;
		for(j=0;j<len1;++j)
		{
			if(s2[c1]==s1[j])
				c1++;
			if(s2[c2]==s1[j])
				c2--;
			if(c1==len2)
			{
				printf("YES\n");
				break;
			}
			if(c2==-1)
			{
				printf("YES\n");
				break;
			}
		}
		if(j==len1)
			printf("NO\n");
	}
	return 0;
}