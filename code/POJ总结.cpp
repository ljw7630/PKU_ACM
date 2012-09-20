1000 A+B Problem // 入门级
    while(scanf("%d%d",&a,&b)!=EOF)
		printf("%d\n",a+b);
		
1002 487-3279 // 排序 字符串操作
	没什么好说的，读入一个字符串，转化成要求的格式，用一个二维的大字符数组存储起来
	//精髓 
	qsort((void *)result, n,sizeof(result[0]),cmp);
	int cmp(const void *a,const void *b)
	{
		return ( strcmp((char*)a,(char*)b) );
	}
	
1003 Hangover // 水题
	水题一道
	for(i=2,sum=0;sum<len;i++)
		sum+=(1/i);
		
1004 Financial Management // 水题
	水题一道，求月平均
	while(scanf("%lf",&perMon)!=EOF)
	{
		if(count==11)
		{
			count=0;
			printf("$%.2lf",(sum+perMon)/12);
			sum=0;
		}
		else
		{
			count++;
			sum+=perMon;
		}
	}
	
1005 I Think I Need a Houseboat // 数学水题
	挺漂亮的解法
	计算半径的平方，然后计算在这个半径内的面积除以100的倍数，上去整
	ceil(pi*x^2*y^2/100)
	
1006 Biorhythms // 数论 中国余数定理
	discuss上面说是中国余数定理，于是找了一下，惭愧
	scanf("%d%d%d%d",&p,&e,&i,&d);
	if(p==-1&&e==-1&&i==-1&&d==-1)
		break;
	count++;
	p%=23;
	e%=28;
	i%=33;
	c=(5544*p+14421*e+1288*i)%21252;

	if(c<=d)  // 这里没考虑清楚，惭愧
		c+=(21252-d);
	else
		c-=d;
		
1007 DNA Sorting // 数组操作,计数,排序
	求逆序对，想法很简单，处理？不写了

1008 Maya Calendar // 数学分析,模运算
	两种日历的转换
	daysum=atoi(getday);
	daysum+=findmon*20;
	daysum+=getyear*365;
	printf("%d %s %d\n",daysum%13+1,tzolkin[daysum%20],daysum/260);
	
1012 Joseph  // 数组操作
	// k个好人k个坏人，处死第一个好人之前有多少个坏人被处死
	for(i=0,j=0,changeLen=len;i<k;i++)
	{
		j=(j+n-1)%changeLen;  // 注意细节
		if(people[j]<k)    // 好方法
			return true;
		for(t=j;t<changeLen-1;t++)
			people[t]=people[t+1];
		changeLen--;
	}
	
1013 Counterfeit Dollar // 好的想法
	// 找假币并指出是轻的还是重的
	// 初始化硬币为0
	// 已经平的用一个比较大的值标记并不再寻找
	// 遍历数组找出绝对值最大的嫌疑硬币即为所求
	
1014 Dividing // dp
	// 定义dp[i]为价值i的可达性
	// 根据输入计算出sum后与1如果不为0则是奇数,退出
	// 否则,sum=sum/2,dp[0]=1
	for(i=0;i<6;i++)
	{
		for(j=sum;j>-1;j--)
		{
			if(dp[j]==0)
			{
				continue;
			}
			if(dp[j+i+1]==1) // 剪枝 避免重复拓展
			{				
				continue;
			}
			pos=j;
			for(k=0;k<num[i];k++)
			{
				pos+=(i+1);
				if(pos>sum)
					break;
				dp[pos]=1;
			}
		}
	}