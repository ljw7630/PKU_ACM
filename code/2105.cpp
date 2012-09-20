#include <iostream>
using namespace std;

int n,ip[32];
int num[8]={128,64,32,16,8,4,2,1};

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char t[50];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",&t);
		for(int i=0;i<32;i++)
		{
			if(t[i]=='0')
				ip[i]=0;
			else
				ip[i]=1;
		}
		int sum=0,count=0;
		for(int i=0;i<32;i++)
		{
			sum+=ip[i]*num[count];
			count++;
			if((i+1)%8==0)
			{
				if(i==31)
					printf("%d\r\n",sum);
				else
					printf("%d.",sum);
				sum=0;
				count=0;
			}
		}
	}

	return 0;
}