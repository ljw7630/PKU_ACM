//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
//	string s;
//	while(cin>>s&&s!="#")
//	{
//		if(next_permutation(s.begin(),s.end()))
//			cout << s << endl;
//		else
//			cout << "No Successor" << endl;
//	}
//	return 0;
//}
#include<iostream>
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char a[100],temp;
	int i,len,j,h,max,loop,t,flag,s;
	while(gets(a))
	{
		flag=0;
		max=999999;
		if(a[0]=='#')
			return 0;
		len=strlen(a);
		for(i=len-2;i>=0;i--)
		{
			if(a[i]<a[i+1])
			{
				flag=1;
				j=i;
				for(h=i+1;h<len;h++)
				{	if(a[h]>a[j]&&a[h]<=max)//取等于，测试数据：acbb
					{
						max=a[h];
						loop=h;
					}
				}
					temp=a[j];
					a[j]=a[loop];
					a[loop]=temp;
			//puts(a);
		//	cout<<j<<" "<<len<<endl;
			for(s=j+1,t=len-1;s<len,s<t;s++,t--)
			{
				//cout<<"s"<<s<<"t"<<t<<endl;
				temp=a[s];
				a[s]=a[t];
				a[t]=temp;
				//puts(a);
			}
			a[len]='\0';
			break;
			
			}
			

		}
		if(flag==1)
		puts(a);
		else
			cout<<"No Successor"<<endl;
	}
}
