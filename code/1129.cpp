#include <iostream>
#include <cmath>
using namespace std;
int n,temp1,temp2;
int arr[32];

int change(int k)
{
	int result=0;
	while(k)
	{
		result+=(k%10);
		k/=10;
	}
	return result;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		int count,result;
		memset(arr,0,sizeof(arr));
		temp1=temp2=n+1;
		while(1)
		{
			count=0;
			for(int i=2;i<=(int)sqrt((float)temp1);)
			{
				if(temp1%i==0)
				{
					arr[count++]=i;
					temp1=temp1/i;
				}
				else
				{
					++i;
				}
			}
			arr[count++]=temp1;
			result=0;
			for(int i=0;i<count;i++)
				result+=change(arr[i]);
			if(result==change(temp2)&&temp1!=temp2)
				break;
			temp2++;
			temp1=temp2;
		}
		printf("%d\n",temp2);
	}
	return 0;
}