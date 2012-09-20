#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
using namespace std;

int binary[8000001];
char str[1000001];
int ccount;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,lenstr;
	map<string,char>myMap;
	myMap["00"]='a';
	myMap["01"]='o';
	myMap["10"]='d';
	myMap["11"]=' ';
	scanf("%d",&t);
	while(t--)
	{
		int index=0;
		int len=0;
		scanf("%s",str);
		lenstr=strlen(str);
		for(int i=0;i<lenstr;++i)
		{
			int tmp[8]={0};
			int index=0;
			char tempChar=str[i];
			while(tempChar!=0)
			{
				tmp[index++]=tempChar%2;
				tempChar/=2;
			}
			for(int j=0;j<8;++j)
				binary[len++]=tmp[j];
		}
		string result;
		string cmpstr;
		for(int i=0;i<len;i+=2)
		{
			cmpstr.push_back(binary[i]+'0');
			cmpstr.push_back(binary[i+1]+'0');
			result.push_back(myMap[cmpstr]);
			cmpstr="";
		}
		ccount=0;
		for(int i=0;i<result.size()-2;++i)
		{
			if(result[i]=='d'&&result[i+1]=='a'&&result[i+2]=='o')
				ccount++;
		}
		cout << ccount << endl;
	}
	return 0;
}