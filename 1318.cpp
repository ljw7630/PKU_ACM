#include <iostream>
#include <algorithm>
using namespace std;
char dic[100][8],t[101],sdic[100][8];
inline int cmp(const void *a,const void *b)
{
	return strcmp((char *)a,(char *)b);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i=0,j,temp;
	bool flag;
	while(scanf("%s",&dic[i])&&dic[i][0]!='X')
		i++;
	qsort(dic,i,sizeof(dic[0]),cmp);
	for(j=0;j<i;j++)
	{
		temp=strlen(dic[j]);
		for(int k=0;k<temp;k++)
			sdic[j][k]=dic[j][k];
		sort(dic[j],dic[j]+temp);
	}
	while(scanf("%s",&t)&&t[0]!='X')
	{
		flag=false;
		temp=strlen(t);
		sort(t,t+temp);
		for(j=0;j<i;j++)
		{
			if(strlen(sdic[j])!=temp)
				continue;
			if(strcmp(dic[j],t)==0)
			{
				flag=true;
				printf("%s\n",sdic[j]);
			}
		}
		if(!flag)
			printf("NOT A VALID WORD\n");
		printf("******\n");
	}
	return 0;
}