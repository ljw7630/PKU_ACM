#include <iostream>
using namespace std;
int n,key[202],k;
char origin[202],result[202];

int getround(int i)
{
	int count,now;
	now=key[i]-1;count=1;
	while(now!=i)
	{
		count++;
		now=key[now]-1;	
	}
	return count;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,len,round,tempk,now;
	char space;
	char temp;
	while(scanf("%d\n",&n)!=EOF&&n)
	{
		memset(key,0,sizeof(key));
		for(i=0;i<n;i++)
			scanf("%d",&key[i]);
		scanf("\n");
		while(scanf("%d",&k)!=EOF)
		{
			if(k==0)
			{
				printf("\n");
				break;
			}
			memset(origin,NULL,sizeof(origin));
			scanf("%c",&space);
			gets(origin);
			len=strlen(origin);
			if(origin[len-1]=='\r')
			{
				origin[len]='\0';			
				len--;
			}
			for(i=0;i<n-len;i++)
				origin[len+i]=' ';
			memset(result,NULL,sizeof(result));
			for(i=0;i<n;i++)
			{
				round = getround(i);
				tempk=k%round;
				now=i;
				while(tempk--)
				{
					now=key[now]-1;
				}
				temp=origin[i];
				result[now]=temp;
			}
			printf("%s\n",result);
		}
	}
	return 0;
}