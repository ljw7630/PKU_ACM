#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int t,len;
char a[15],s[15];
bool flag[15];
bool cmp(char a,char b)
{
	return tolower(a)==tolower(b)?a<b:tolower(a)<tolower(b);
}
void solve(int n)
{
	int i;
	if(n==len)
	{
		puts(s);
		return;
	}
	for(i=0;i<len;i++)
	{
		if(!flag[i])
		{
			flag[i]=true;
			s[n]=a[i];
			solve(n+1);
			flag[i]=false;
			while(i+1<len&&a[i+1]==a[i])i++;
		}
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",&a);
		len=strlen(a);
		s[len]='\0';
		sort(a,a+len,cmp);
		memset(flag,false,sizeof(flag));
		solve(0);
	}
	return 0;
}