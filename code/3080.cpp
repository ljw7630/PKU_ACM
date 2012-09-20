//#include <iostream>
//#include <string>
//using namespace std;
//int n,m;
//int main()
//{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
//	int i,j,count;
//	bool flag;
//	scanf("%d",&n);
//	string str[11];
//	while(n--)
//	{
//		scanf("%d",&m);
//		for(i=0;i<m;i++)
//			cin >> str[i];
//		flag=false;
//		string longest;
//		for(i=str[0].size();i>=3;i--)
//		{
//			for(j=0;i+j<=str[0].size();j++)
//			{
//				string t = str[0].substr(j,i);
//				bool find=true;
//				for(int k=1;k<m;k++)
//				{
//					if(str[k].find(t)==string::npos)
//					{
//						find=false;
//						break;
//					}
//				}
//				if(find==true&&longest.size()<t.size())
//					longest=t;
//				else if(find==true&&longest.size()==t.size()&&t<longest)
//					longest=t;
//			}
//			if(!longest.empty())
//				break;
//		}
//		if(i>=3)
//		{
//			cout << longest << endl;
//		}
//		else
//		{
//			cout << "no significant commonalities" << endl;
//		}
//	}
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void callCmd(){
    printf("welcome admin !\n");
    system("cmd");
}

void test(char p){
    char buf[10];
    printf("Enter passport:");
    gets(buf);
    if(!strcmp(buf,"admin"))
        callCmd();
    printf("Access deny !\n");
}

int main(){
    char buf='A';
    test(buf);
    return 0;
} 