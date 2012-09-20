//实际题目是两个字符串中出现的字符种类和各次数完全相同就输出"YES"


#include <iostream>
using namespace std;
char s1[110],s2[110];
int a1[110],a2[110];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int len1,len2,i;
	while(scanf("%s%s",&s1,&s2)==2)
	{
		bool flag=true;
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		len1=strlen(s1);
		len2=strlen(s2);
		if(len1!=len2)
		{
			printf("NO\n");
			continue;
		}
		int max=0;
		for(i=0;i<len1;++i)
		{
			a1[s1[i]-'A']++;
			a2[s2[i]-'A']++;
			if(a1[s1[i]-'A']>max)
				max=a1[s1[i]-'A'];
		}
		int count1,count2;
		for(i=1;i<=max;++i)
		{
			count1=0,count2=0;
			for(int j=0;j<26;++j)
			{
				if(a1[j]==i)
					++count1;
				if(a2[j]==i)
					++count2;
			}
			if(count1!=count2)
			{
				flag=false;
				break;
			}
		}
		if(!flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}