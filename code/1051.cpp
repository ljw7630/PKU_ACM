#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int num;
string temp;
string all;
int charlen[101];
char morse[30][6]={ {".-"},{"-..."},{"-.-."},{"-.."},{'.'},
{"..-."},{"--."},{"...."},{".."},{".---"},
{"-.-"},{".-.."},{"--"},{"-."},{"---"},
{".--."},{"--.-"},{".-."},{"..."},{"-"},
{"..-"},{"...-"},{".--"},{"-..-"},{"-.--"},
{"--.."},{"..--"},{".-.-"},{"---."},{"----"}};
int main()
{	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,len,now,count,sum=0;
	scanf("%d",&num);
	count=num;
	while(count--)
	{
		i=0;
		cin>>temp;
		while(i!=temp.size())
		{
			switch(temp[i])
			{
			case 'E':
			case 'T':
				charlen[i]=1;
				all+=morse[temp[i]-65];
				break;
			case 'A':
			case 'I':
			case 'M':
			case 'N':
				charlen[i]=2;
				all+=morse[temp[i]-65];
				break;
			case 'D':
			case 'G':
			case 'K':
			case 'O':
			case 'R':
			case 'S':
			case 'U':
			case 'W':
				charlen[i]=3;
				all+=morse[temp[i]-65];
				break;
			case 'B':
			case 'C':
			case 'F':
			case 'H':
			case 'J':
			case 'L':
			case 'P':
			case 'Q':
			case 'V':
			case 'X':
			case 'Y':
			case 'Z':
				charlen[i]=4;
				all+=morse[temp[i]-65];
				break;
			case '_':
				charlen[i]=4;
				all+=morse[26];
				break;
			case ',':
				charlen[i]=4;
				all+=morse[27];
				break;
			case '.':
				charlen[i]=4;
				all+=morse[28];
				break;
			case '?':
				charlen[i]=4;
				all+=morse[29];
				break;
			}
			i++;
		}
		reverse(charlen,charlen+i);
		len=all.size();
		now=0;
		printf("%d: ",num-count);
		for(j=0;j<i;j++)
			sum+=charlen[j];
		for(j=0;j<i;j++)
		{
			temp.clear();
			temp.assign(all,now,charlen[j]);
			now+=charlen[j];
			for(k=0;k<30;k++)
			{
				if(morse[k]==temp)
				{
					if(k<26)
					{
						printf("%c",k+65);
						break;
					}
					else if(k==26)
					{
						printf("_");
						break;
					}
					else if(k==27)
					{
						printf(",");
						break;
					}
					else if(k==28)
					{
						printf(".");
						break;
					}
					else if(k==29)
					{
						printf("?");
						break;
					}
				}
			}
		}
		printf("\n");
		all.clear();
		temp.clear();
		memset(charlen,0,sizeof(charlen));
	}
	return 0;
}