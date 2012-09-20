#include <iostream>
using namespace std;
int n,w,s;
char name[65][20];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,count,t,j;
	while(scanf("%d",&n)!=EOF)
	{
		count=n;
		for(i=0;i<n;i++)
			scanf("%s",name[i]);
		scanf("%d,%d",&w,&s);
		w-=1;
		while(count!=0)
		{
			t=(s+w-1)%count;
			printf("%s\n",name[t]);
			for(j=t+1;j<count;j++)
				strcpy(name[j-1],name[j]);
			w=t;
			count--;
		}
	}
}