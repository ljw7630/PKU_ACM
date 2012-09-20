#include <iostream>
using namespace std;

int main()
{
	void hanoi(int,char,char,char);
	void move(char,char);
	int n;
	printf("How many dics:\n");
	scanf("%d",&n);
	hanoi(n,'a','b','c');
	system("pause");
	return 0;
}

void move(char a,char b)
{
	printf("%c ---> %c\n",a,b);
}

void hanoi(int n,char a,char b,char c)
{
	if(n==1)
	{
		move(a,c);
	}
	else
	{
		hanoi(n-1,a,c,b);
		move(a,c);
		hanoi(n-1,b,a,c);	
	}
}