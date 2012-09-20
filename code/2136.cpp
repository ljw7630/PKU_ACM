#include <iostream>
#include <string>
using namespace std;
string buffer;
int cal[30];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	memset(cal,0,sizeof(cal));
	for(int i=0;i<4;i++)
	{
		getline(cin,buffer);
		for(int j=0;j<buffer.length();++j)
		{
			if(buffer[j]>='A'&&buffer[j]<='Z')
			{
				cal[buffer[j]-'A']++;
			}
		}
	}
	int maxi=0;
	for(int i=0;i<26;++i)
		if(maxi<cal[i])
			maxi=cal[i];
	for(int i=maxi;i>0;--i)
	{
		for(int j=0;j<26;++j)
		{
			if(cal[j]==i)
			{
				printf("*");
				--cal[j];
			}
			else
				printf(" ");
			if(j!=25)
				printf(" ");
		}
		printf("\n");
	}
	for(int i=0;i<26;++i)
	{
		printf("%c",i+'A');
		if(i!=25)
			printf(" ");
	}

	return 0;
}