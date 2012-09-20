#include <iostream>
#include <string>

using namespace std;

char haabMon[19][10]={ "pop","no","zip","zotz","tzec","xul","yoxkin","mol",
					   "chen","yax","zac","ceh","mac","kankin","muan",
						"pax","koyab","cumhu","uayet"};
char tzolkin[20][10]={ "imix","ik","akbal","kan","chicchan","cimi","manik",
					   "lamat","muluk","ok","chuen","eb","ben","ix","men",
                       "cib","caban","eznab","canac","ahau"};

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int num,i,j;
	char getday[10];
	char getmon[10];
	int getyear,daysum;

	scanf("%d",&num);
	printf("%d\n",num);
	for(i=0;i<num;i++)
	{
		daysum=0;
		scanf("%s",&getday);
		scanf("%s",&getmon);
		scanf("%d",&getyear);
		getday[strlen(getday)-1]='\0';
		daysum=atoi(getday);
		j=0;
		while(strcmp(getmon,haabMon[j])!=0)
			j++;
		daysum+=j*20;
		daysum+=getyear*365;

		printf("%d %s %d\n",daysum%13+1,tzolkin[daysum%20],daysum/260);
	}
	return 0;
}