#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1,s2;
	int t1[13],t2[13];
	while(cin>>s1>>s2&&(s1!="0"||s2!="0"))
	{
		memset(t1,0,sizeof(t1));
		memset(t2,0,sizeof(t2));
		for(int i=0;i<s1.size();++i)
			t1[i]=s1[s1.size()-i-1]-'0';
		for(int i=0;i<s2.size();++i)
			t2[i]=s2[s2.size()-i-1]-'0';
		int len=max(s1.size(),s2.size());
		for(int i=0;i<len;++i)
			t1[i]=t1[i]+t2[i];
		int c=0;
		int ccount=0;
		int i=0;
		int temp;
		while(i!=len)
		{
			temp=t1[i]+c;
			t1[i]=(temp)%10;
			c=(temp)/10;
			if(c!=0)
				ccount++;
			i++;
		}
		if(ccount==0)
			printf("No carry operation.\n");
		else if(ccount==1)
			printf("1 carry operation.\n");
		else
			printf("%d carry operations.\n",ccount);
	}
	return 0;
}