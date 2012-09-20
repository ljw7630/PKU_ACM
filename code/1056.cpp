#include <iostream>
#include <string>
using namespace std;
string input[9];
int len[9];
int main()
{	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,count,swap,cal,flag,record;
	string temp;
	count=0;
	record=0;
	while(cin>>input[count])
	{
		len[count]=input[count].size();
		count++;
		if(input[count-1]=="9")
		{
			record++;
			count-=1;
			for(i=0;i<count;i++)
			{
				for(j=i+1;j<count;j++)
				{
					if(len[i]>len[j])
					{
						swap=len[i];
						len[i]=len[j];
						len[j]=swap;
						temp=input[i];
						input[i]=input[j];
						input[j]=temp;
					}
					else if(len[i]==len[j])
					{
						for(k=0;k<len[i];k++)
						{
							if(input[i][k]>input[j][k])
							{
								swap=len[i];
								len[i]=len[j];
								len[j]=swap;
								temp=input[i];
								input[i]=input[j];
								input[j]=temp;
								break;
							}
							else if(input[i][k]<input[j][k])
							{
								break;
							}
						}
					}
				}
			}
			flag=0;
			for(i=0;i<count;i++)
			{
				for(j=i+1;j<count;j++)
				{
					cal=0;
					if(len[i]!=len[j])
					{
						for(k=0;k<len[i];k++)
						{
							if(input[i][k]==input[j][k])
								cal++;
						}
						if(cal==len[i])
						{
							flag=1;
							printf("Set %d is not immediately decodable\n",record);
							break;
						}

					}
				}
				if(flag==1)
					break;
			}
			if(flag!=1)
			{
				printf("Set %d is immediately decodable\n",record);
			}
			count=0;
		}
	}
	return 0;
}