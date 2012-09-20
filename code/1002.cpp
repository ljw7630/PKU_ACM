#include <iostream>
#include <string>
using namespace std;
char t1[21],t2[21];
char result[100001][21];
int n,index,temp;

//void mysort()
//{
//	int i,j;
//	for(i=0;i<(index-1);i++)
//	{
//		for(j=i+1;j<(index-1);j++)
//		{
//			if(strcmp(result[i],result[j])>0&&cal[i]!=1)
//			{
//				strcpy(t2,result[j]);
//				strcpy(result[j],result[i]);
//				strcpy(result[i],t2);
//				temp=cal[j];
//				cal[j]=cal[i];
//				cal[i]=temp;
//			}
//		}
//	}
//}
int cmp(const void *a,const void *b)
{
	return ( strcmp((char*)a,(char*)b) );
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,count,flag;
	scanf("%d",&n);
	count=n;
	index=1;
	flag=0;
	for(k=0;k<count;k++)
	{	
		scanf("%s",&t1);
		for(i=0,j=0;t1[i]!='\0';i++)
		{
			if(j==3)
			{
				t2[j]='-';
				j++;
			}
			if(t1[i]=='0')
			{t2[j]='0';j++;continue;}
			if(t1[i]=='1')
			{t2[j]='1';j++;continue;}
			if(t1[i]=='A'||t1[i]=='B'||t1[i]=='C'||t1[i]=='2')
			{t2[j]='2';j++;continue;}
			if(t1[i]=='D'||t1[i]=='E'||t1[i]=='F'||t1[i]=='3')
			{t2[j]='3';j++;continue;}
			if(t1[i]=='G'||t1[i]=='H'||t1[i]=='I'||t1[i]=='4')
			{t2[j]='4';j++;continue;}
			if(t1[i]=='J'||t1[i]=='K'||t1[i]=='L'||t1[i]=='5')
			{t2[j]='5';j++;continue;}
			if(t1[i]=='M'||t1[i]=='N'||t1[i]=='O'||t1[i]=='6')
			{t2[j]='6';j++;continue;}
			if(t1[i]=='P'||t1[i]=='R'||t1[i]=='S'||t1[i]=='7')
			{t2[j]='7';j++;continue;}
			if(t1[i]=='T'||t1[i]=='U'||t1[i]=='V'||t1[i]=='8')
			{t2[j]='8';j++;continue;}
			if(t1[i]=='W'||t1[i]=='X'||t1[i]=='Y'||t1[i]=='9')
			{t2[j]='9';j++;continue;}
		}
		t2[j]='\0';
		strcpy(result[k],t2);
	}
	qsort((void *)result, n,sizeof(result[0]),cmp);
	flag=0;
	for(i=0;i<n;i=j)
	{
		for(j=i+1;i<n;j++)
		{
			if(strcmp(result[j],result[i])!=0)
				break;
		}
		if(j-i!=1)
		{
			printf("%s %d\n",result[i],j-i);
			flag =1;
		}
	}
	if(flag==0)
		printf("No duplicates.\n");
	return 0;
}
//		for(i=0;i<index;i++)
//		{
//			if(strcmp(t2,result[i])!=0)
//			{
//				count++;
//			}
//			else
//			{
//				cal[i]++;
//				flag=1;
//				break;
//			}
//		}
//		if(count=index&&flag==0)
//		{
//			strcpy(result[index-1],t2);
//			cal[index-1]++;
//			index++;		
//		}
//	}
//	mysort();
//	flag=0;
//	for(i=0;i<(index-1);i++)
//	{
//		if(cal[i]>1)
//		{
//			flag=1;
//			printf("%s %d\n",result[i],cal[i]);
//		}
//		if(i==index-1&&flag==0)
//		{
//			printf("No duplicates.\n");
//		}
//	}
//	return 0;
//}