#include <iostream>
#include <string>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char s1[50],s2[50];
	int s3[100];
	int i,j;
	while(scanf("%s%s",&s1,&s2)!=EOF)
	{
		int len1=strlen(s1);
		i=0;
		while(s1[i])
			s1[i++]-='0';
		for(i=0;i<len1/2;++i)
			swap(s1[i],s1[len1-i-1]);

		int len2=strlen(s2);
		i=0;
		while(s2[i])
			s2[i++]-='0';
		for(i=0;i<len2/2;++i)
			swap(s2[i],s2[len2-i-1]);

		memset(s3,0,sizeof(s3));
		for(i=0;i<len1;++i)
			for(j=0;j<len2;++j)
				s3[i+j]+=s1[i]*s2[j];
		int inc=0,newinc=0;
		for(i=0;i<len1+len2;++i)
		{
			newinc=(inc+s3[i])/10;;
			s3[i]=(inc+s3[i])%10;
			inc=newinc;
		}
		int pos;
		for(i=len1+len2;i>=0;--i)
		{
			if(s3[i]!='\0')
			{
				pos=i;
				break;
			}
		}
		for(i=pos;i>=0;--i)
			printf("%d",s3[i]);
		printf("\n");
	}
	return 0;
}