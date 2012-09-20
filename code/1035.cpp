#include <iostream>
using namespace std;
char dic[10001][16],input[16],result[10001][16];
int len[10001],inputlen;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,count,flag;
	count=0;
	while(scanf("%s",&dic[count])!=EOF&&dic[count][0]!='#')
	{
		len[count]=strlen(dic[count]);
		count++;
	}
	while(scanf("%s",&input)!=EOF&&input[0]!='#')
	{
		inputlen=strlen(input);
		flag=0;
		for(i=0;i<count;i++)
		{
			if(strcmp(input,dic[i])==0)
			{
				printf("%s is correct\n",input);
				flag=1;
				break;
			}
		}
		if(flag!=1)
		{
			printf("%s:",input);
			for(i=0;i<count;i++)
			{
				if(len[i]==inputlen)//replace
				{
					for(j=0,k=0;j<len[i];j++)
					{
						if(input[j]!=dic[i][j])k++;
					}
					if(k==1)printf(" %s",dic[i]);
				}
				else if(len[i]==inputlen-1)//delete
				{
					for(j=0,k=0;k<inputlen;j++,k++)
					{
						if(dic[i][j]!=input[k])j--;
					}
					if(j==len[i])printf(" %s",dic[i]);
				}
				else if(len[i]==inputlen+1)//add
				{
					for(j=0,k=0;j<len[i];j++,k++)
					{
						if(dic[i][j]!=input[k])k--;
					}
					if(k==inputlen)printf(" %s",dic[i]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}