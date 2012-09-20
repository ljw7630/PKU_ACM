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

//一、当n mod 6 != 2 且 n mod 6 != 3时，有一个解为：

//

//2,4,6,8,...,n,1,3,5,7,...,n-1       (n为偶数)

//

//2,4,6,8,...,n-1,1,3,5,7,...,n       (n为奇数)

//

//(上面序列第i个数为ai，表示在第i行ai列放一个皇后；... 省略的序列中，相邻两数以2递增。下同)

//

//二、当n mod 6 == 2 或 n mod 6 == 3时，

//

//(当n为偶数,k=n/2；当n为奇数,k=(n-1)/2)

//

//k,k+2,k+4,...,n,2,4,...,k-2,k+3,k+5,...,n-1,1,3,5,...,k+1         (k为偶数,n为偶数)

//

//k,k+2,k+4,...,n-1,2,4,...,k-2,k+3,k+5,...,n-2,1,3,5,...,k+1,n       (k为偶数,n为奇数)

//

//k,k+2,k+4,...,n-1,1,3,5,...,k-2,k+3,...,n,2,4,...,k+1               (k为奇数,n为偶数)

//

//k,k+2,k+4,...,n-2,1,3,5,...,k-2,k+3,...,n-1,2,4,...,k+1,n           (k为奇数,n为奇数)

//

