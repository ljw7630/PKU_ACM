#include <iostream>
using namespace std;

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(min(a,min(b,c))<168)
		cout << "CRASH " << min(a,min(b,c)) << endl;
	else
		cout << "NO CRASH" << endl;
	return 0;
}