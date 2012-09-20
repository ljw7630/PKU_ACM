#include <iostream>
#include <algorithm>
using namespace std;

int n;
char str[15];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
			str[i]=i+'a';
		str[n]='\0';
		printf("%s\n",str);
		while(next_permutation(str,str+n))
			printf("%s\n",str);
	}
	return 0;
}