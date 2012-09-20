#include <iostream>
using namespace std;
char s1[100002],s2[100002];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int l1,l2,count,i,j;
	while(scanf("%s",s1)!=EOF)
	{
		scanf("%s",s2);	
		l1=strlen(s1);
		l2=strlen(s2);
		i=0;
		for(j=0;j<l2;j++)
		{
			if(s1[i]==s2[j])
				i++;
			if(i==l1)
				break;
		}
		if(i<l1)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}