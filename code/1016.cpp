#include <iostream>
#include <string>
using namespace std;
char str[16][101];

void translate(int times)
{
	int i,j,count,pointto,ge,shi;
	char temp[101],m;
	if(times>=15)
	{
		printf("%s can not be classified after 15 iterations\n",str[0]);
		return;
	}
	strcpy(temp,str[times]);
	for(i=0;temp[i]!='\0';i++)
	{
		for(j=i;temp[j]!='\0';j++)
		{
			if(temp[i]>temp[j])
			{
				m=temp[i];
				temp[i]=temp[j];
				temp[j]=m;
			}
		}
	}
	m=temp[0],count=1,pointto=0;
	for(i=1;temp[i]!='\0';i++)
	{
		if(temp[i]==m)
			count++;
		else if(count<10)
		{
			str[times+1][pointto]=count+48;
			str[times+1][pointto+1]=m;
			pointto+=2;
			count=1;
		}
		else
		{
			ge=count%10;shi=(count-ge)/10;
			str[times+1][pointto]=shi+48;
			str[times+1][pointto+1]=ge+48;
			str[times+1][pointto+2]=m;
			pointto+=3;
			count=1;
		}
		m=temp[i];
	}
	if(count<10)
	{
		str[times+1][pointto]=count+48;
		str[times+1][pointto+1]=m;
		pointto+=2;
		count=1;
	}
	else
	{
		ge=count%10;shi=(count-ge)/10;
		str[times+1][pointto]=shi+48;
		str[times+1][pointto+1]=ge+48;
		str[times+1][pointto+2]=m;
		pointto+=3;
		count=1;
	}
	str[times+1][pointto]='\0';
	if(times==0&&strcmp(str[0],str[1])==0)
	{
		printf("%s is self-inventorying\n",str[0]);
		return;
	}
	else if(times!=0&& strcmp(str[times],str[times+1])==0)
	{
		printf("%s is self-inventorying after %d steps\n",str[0],times);
		return;
	}
	else
	{
		for(i=0;i<times;i++)
		{
			if(strcmp(str[i],str[times+1])==0)
			{
				printf("%s enters an inventory loop of length %d\n",str[0],times+1-i);
				return;
			}
		}
	}
	translate(times+1);
	return;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%s",&str[0]);
	while(true)
	{
		if(str[0][0]=='-')
			break;
		translate(0);
		scanf("%s",&str[0]);
	}

	return 0;
}