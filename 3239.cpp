#include <iostream>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		int k=0;
		if(n%6!=2&&n%6!=3)
		{
			if(n%2==1)
			{
				for(i=2;i<=n-1;i+=2)
					printf("%d ",i);
				for(i=1;i<=n;i+=2)
					printf("%d ",i);
			}
			else
			{
				for(i=2;i<=n;i+=2)
					printf("%d ",i);
				for(i=1;i<=n-1;i+=2)
					printf("%d ",i);
			}
		}
		else
		{
			if(n%2==1)
				k=(n-1)/2;
			else
				k=n/2;
			if(k%2==0&&n%2==0)
			{
				for(i=k;i<=n;i+=2)
					printf("%d ",i);
				for(i=2;i<=k-2;i+=2)
					printf("%d ",i);
				for(i=k+3;i<=n-1;i+=2)
					printf("%d ",i);
				for(i=1;i<=k+1;i+=2)
					printf("%d ",i);
			}
			else if(k%2==0&&n%2==1)
			{
				for(i=k;i<=n-1;i+=2)
					printf("%d ",i);
				for(i=2;i<=k-2;i+=2)
					printf("%d ",i);
				for(i=k+3;i<=n-2;i+=2)
					printf("%d ",i);
				for(i=1;i<=k+1;i+=2)
					printf("%d ",i);
				printf("%d",n);
			}
			else if(k%2==1&&n%2==0)
			{
				for(i=k;i<=n-1;i+=2)
					printf("%d ",i);
				for(i=1;i<=k-2;i+=2)
					printf("%d ",i);
				for(i=k+3;i<=n;i+=2)
					printf("%d ",i);
				for(i=2;i<=k+1;i+=2)
					printf("%d ",i);
			}
			else if(k%2==1&&n%2==1)
			{
				for(i=k;i<=n-2;i+=2)
					printf("%d ",i);
				for(i=1;i<=k-2;i+=2)
					printf("%d ",i);
				for(i=k+3;i<=n-1;i+=2)
					printf("%d ",i);
				for(i=2;i<=k+1;i+=2)
					printf("%d ",i);
				printf("%d",n);
			}
		}
		printf("\n");
	}
	return 0;
}

//һ����n mod 6 != 2 �� n mod 6 != 3ʱ����һ����Ϊ��

//

//2,4,6,8,...,n,1,3,5,7,...,n-1       (nΪż��)

//

//2,4,6,8,...,n-1,1,3,5,7,...,n       (nΪ����)

//

//(�������е�i����Ϊai����ʾ�ڵ�i��ai�з�һ���ʺ�... ʡ�Ե������У�����������2��������ͬ)

//

//������n mod 6 == 2 �� n mod 6 == 3ʱ��

//

//(��nΪż��,k=n/2����nΪ����,k=(n-1)/2)

//

//k,k+2,k+4,...,n,2,4,...,k-2,k+3,k+5,...,n-1,1,3,5,...,k+1         (kΪż��,nΪż��)

//

//k,k+2,k+4,...,n-1,2,4,...,k-2,k+3,k+5,...,n-2,1,3,5,...,k+1,n       (kΪż��,nΪ����)

//

//k,k+2,k+4,...,n-1,1,3,5,...,k-2,k+3,...,n,2,4,...,k+1               (kΪ����,nΪż��)

//

//k,k+2,k+4,...,n-2,1,3,5,...,k-2,k+3,...,n-1,2,4,...,k+1,n           (kΪ����,nΪ����)

//

