//#include <iostream>
//#include <algorithm>
//#include <set>
//#include <string>
//using namespace std;
//int main()
//{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
//	int n;
//	set<string>vec;
//	string origin;
//	string temp;
//	string t1,t2;
//	scanf("%d",&n);
//	while(n--)
//	{
//		cin>>origin;
//		vec.insert(origin);
//		for(set<string>::size_type i=1;i<=origin.size()-1;++i)
//		{
//			//Ç°ÖÃ ÕýÐò-ÕýÐò
//			
//			//ºóÖÃ ÕýÐò-ÕýÐò
//			t1=origin.substr(0,i);
//			t2=origin.substr(i,origin.size());
//			temp=t2+t1;
//			vec.insert(temp);
//
//			//Ç°ÖÃ ÕýÐò-ÄæÐò
//			t1=origin.substr(0,i);
//			t2=origin.substr(i,origin.size());
//			reverse(t2.begin(),t2.end());
//			temp=t1+t2;
//			vec.insert(temp);
//			//ºóÖÃ ÕýÐò-ÄæÐò
//			temp=t2+t1;
//			vec.insert(temp);
//
//			//Ç°ÖÃ ÄæÐò-ÕýÐò
//			t1=origin.substr(0,i);
//			reverse(t1.begin(),t1.end());
//			t2=origin.substr(i,origin.size());
//			temp=t1+t2;
//			vec.insert(temp);
//			//ºóÖÃ ÄæÐò-ÕýÐò
//			temp=t2+t1;
//			vec.insert(temp);
//
//			//Ç°ÖÃ ÄæÐò-ÄæÐò
//			t1=origin.substr(0,i);
//			reverse(t1.begin(),t1.end());
//			t2=origin.substr(i,origin.size());
//			reverse(t2.begin(),t2.end());
//			temp=t1+t2;
//			vec.insert(temp);
//			//ºóÖÃ ÄæÐò-ÄæÐò
//			temp=t2+t1;
//			vec.insert(temp);
//		}
//		cout << vec.size() <<endl;
//		vec.clear();
//	}
//}

#include <iostream>
using namespace std;
char contain[1005][80];
char origin[80];
char temp[80];
int top;
void insert(char str[])
{
	for(int i=0;i<top;++i)
	{
		if(strcmp(str,contain[i])==0)
			return;
	}
	strcpy(contain[top++],str);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	while(n--)
	{
		top=0;
		scanf("%s",origin);
		insert(origin);
		int len=strlen(origin);
		for(int i=1;i<len;++i)
		{
			//Ç°ÖÃ ÄæÐò-ÕýÐò
			strcpy(temp,origin);
			for(int j=0;j<i;++j)
				temp[i-j-1]=origin[j];
			insert(temp);
			//Ç°ÖÃ ÄæÐò-ÄæÐò
			for(int j=i;j<len;++j)
				temp[i+len-j-1]=origin[j];
			insert(temp);
			//Ç°ÖÃ ÕýÐò-ÄæÐò
			for(int j=0;j<i;++j)
				temp[j]=origin[j];
			insert(temp);
			//ºóÖÃ ÕýÐò-ÕýÐò
			for(int j=i;j<len;++j)
				temp[j-i]=origin[j];
			for(int j=0;j<i;++j)
				temp[len-i+j]=origin[j];
			insert(temp);
			//ºóÖÃ ÄæÐò-ÕýÐò
			for(int j=i;j<len;++j)
				temp[len-j-1]=origin[j];
			insert(temp);
			//ºóÖÃ ÄæÐò-ÄæÐò
			for(int j=0;j<i;++j)
				temp[len-j-1]=origin[j];
			insert(temp);
			//ºóÖÃ ÕýÐò-ÄæÐò
			for(int j=i;j<len;++j)
				temp[j-i]=origin[j];
			insert(temp);
		}
		printf("%d\n",top);
	}
}