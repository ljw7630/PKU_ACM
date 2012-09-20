#include <iostream>
#include <algorithm>
using namespace std;

char str[205],temp[205];
int len;

bool nextpermutation()
{
	int pos1,pos2;
	bool flag=false;
	for(int i=len-2;i>-1;--i)
	{
		if(str[i]<str[i+1])
		{
			pos1=i;
			flag=true;
			break;
		}
	}
	if(!flag)
		return false;
	for(int i=len-1;i>pos1;--i)
	{
		if(str[pos1]<str[i])
		{
			pos2=i;
			break;
		}
	}
	int t=str[pos2];
	str[pos2]=str[pos1];
	str[pos1]=t;
	int count=0;
	for(int i=pos1+1;i<len;++i)
	{
		temp[count++]=str[i];
	}
	int c=1;
	for(int i=count-1;i>-1;--i)
	{
		str[pos1+c]=temp[i];
		c++;
	}
	return true;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%s",str)!=EOF)
	{
		len=strlen(str);
		sort(str,str+len);
		printf("%s\n",str);
		while(nextpermutation())
		{
			printf("%s\n",str);
		}
	}
	return 0;
}