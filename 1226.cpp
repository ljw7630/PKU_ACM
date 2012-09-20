#include <iostream>
#include <string.h>
using namespace std;
int t,n,templen,minstr,minlen;
char str[102][102],invstr[102][102],tempstr[102];
bool flag[102];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,count,ans,begin,end;
	bool sign;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0,minlen=1000;i<n;i++)
		{
			scanf("%s",&str[i]);
			templen=strlen(str[i]);
			for(j=0;j<templen;j++)
			{
				invstr[i][j]=str[i][templen-j-1];
			}
			invstr[i][j]='\0';
			if(templen<minlen)
			{
				minlen=templen;
				minstr=i;
			}
		}
		ans=minlen;
		sign=false;
		while(ans!=0)
		{
			for(begin=0,end=ans;end<=minlen;begin++,end++)//×Ó×Ö·û´®³¤¶Èend-begin
			{
				for(j=0;j<ans;j++)
				{
					tempstr[j]=str[minstr][begin+j];
				}
				tempstr[j]='\0';
				memset(flag,false,sizeof(flag));
				for(j=0;j<n;j++)
				{
					if(strstr(str[j],tempstr)!=NULL)
						flag[j]=true;
				}	
				for(j=0;j<n;j++)
				{
					if(strstr(invstr[j],tempstr)!=NULL)
						flag[j]=true;
				}
				for(j=0;j<n;j++)
					if(flag[j]==false)
						break;
				if(j==n)
				{
					sign=true;
					break;
				}
			}
			if(sign==true)
			{
				break;
			}
			ans--;
		}
		printf("%d\n",ans);
	}
	return 0;
}