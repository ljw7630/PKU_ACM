//#include <iostream>
//using namespace std;
//double factorial(int j)
//{
//	double ans=1;
//	if(j==0)
//		return 1;
//	else
//		for(int k=1;k<=j;k++)
//			ans*=k;
//	return 1.0/ans;
//}
//int main()
//{
//	freopen("out.txt","w",stdout);	
//	printf("n e\n");
//	printf("- -----------\n");
//	printf("0 1\n");
//	printf("1 2\n");
//	printf("2 2.5\n");
//	cout.setf(ios::fixed);
//	cout.setf(ios::showpoint);
//	cout.precision(9);
//	for(int i=3;i<=9;i++)
//	{
//		printf("%d ",i);
//		double sum=0;
//		for(int j=0;j<=i;j++)
//		{
//			sum+=factorial(j);
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}
#include <iostream>
using namespace std;
double factorial(int j)
{
	double ans=1;
	if(j==0)
		return 1;
	else
		for(int k=1;k<=j;k++)
			ans*=k;
	return 1.0/ans;
}
int main()
{
	freopen("out.txt","w",stdout);	
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	for(int i=3;i<=9;i++)
	{
		printf("%d ",i);
		double sum=0;
		for(int j=0;j<=i;j++)
		{
			sum+=factorial(j);
		}
		printf("%.9lf\n",sum);
	}
	return 0;
}