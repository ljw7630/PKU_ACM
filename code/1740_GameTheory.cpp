////取石子游戏:寻找必败态
////当石子为1堆时,先手必胜
////当石子为2堆时,如果石子是两堆相等的,那么后手按照先手步骤,则先手必败,否则
////先手将之转化为两堆相等,后手败
////当石子为3堆时,先手将第三堆取消并转化为两堆相等,先手必胜
////当石子为4堆时,双方均逼迫对方先取走1堆,由上面的结论,两堆相等的时候先手败,
////如果先手能将石子转化成4堆两两相等,则剩,否则,必败
////当石子为5堆时,先手能将之改变成4堆的情况
////如此类推
//
#include<iostream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,a[12],i,j;
	while(scanf("%d",&n)!=EOF&&n)
	{
		j=n;
		while(n--)
		{
			scanf("%d",&a[j-n-1]);
		}
		if(j%2!=0)
			printf("1\n");
		else
		{
			sort(a,a+j);
			for(i=0;i<j-1;i+=2)
			{
				if(a[i]!=a[i+1])
				{
					break;
				}
			}
			if(i==j)
				printf("0\n");
			else
				printf("1\n");
		}
	}
	return 0;
}