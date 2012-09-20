#include <iostream>
using namespace std;
int num;
bool record[260];
char store[500];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,count,in;
	while(scanf("%d",&num)!=EOF&&num!=0)
	{
		scanf("%s",store);
		memset(record,false,sizeof(record));
		for(count=in=i=0;store[i]!=0;i++)
		{
			if(record[store[i]]==false)
			{
				record[store[i]]=true;
				in++;
				if(in>num)
					count++;
			}
			else
			{
				record[store[i]]=false;
				in--;
			}
		}
		if(count==0)
			printf("All customers tanned successfully.\n");
		else
			printf("%d customer(s) walked away.\n",count);
	}
	return 0;
}
