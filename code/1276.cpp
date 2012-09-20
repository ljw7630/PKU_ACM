#include <iostream>
#include <algorithm>
using namespace std;
int cash,n;
bool flag[100001];
class Bill
{
public:
	int nk;
	int dk;
	bool friend operator <(Bill a,Bill b)
	{
		if(a.dk<b.dk)
			return true;
		else
			return false;
	}
}bill[11];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,max,temp;
	while(scanf("%d%d",&cash,&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&bill[i].nk,&bill[i].dk);
		}
		if(!cash||!n)
		{
			printf("0\n");
			continue;
		}
		memset(flag,false,sizeof(flag));
		sort(bill,bill+n);
		flag[0]=true;
		max=0;
		for(i=0;i<n;i++)
		{
			for(j=max;j>=0;j--)
			{
				if(flag[j])
				{
					for(k=1;k<=bill[i].nk;k++)
					{
						temp=k*bill[i].dk+j;
						if(temp>cash)
							break;
						if(max<=temp)
						{
							max=temp;
						}
						flag[temp]=true;
					}
				}
			}
		}
		printf("%d\n",max);
	}
	return 0;
}