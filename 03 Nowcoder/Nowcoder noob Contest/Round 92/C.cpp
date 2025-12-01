#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
struct zhongzi
{
	int lv;                           //种子等级 
	int num=0;                        //种子数目 
}a[N];
signed main()
{
	int n,i,t,x,level,max=0,count,max1=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>level;
		if(level>max1) 
		max1=level;                     //找到最大等级种子 
		a[i].lv=level;
		a[i].num++;
	}
	cin>>x;
	for(i=1;i<=n;i++)
		if(a[i].lv==x)
			max+=a[i].num;              //算出初始情况下x等级种子有多少个 
	while(max1>x)                       //当最大等级种子小于等于x之后割的种子都会导致x等级种子为0 
	{
		count=0;                        //用于计算本次割地之后x等级种子数目 
		for(i=1;i<=n;i++)
		{
			a[i].lv=ceil(a[i].lv/3.0);  //开始割种 
			a[i].num=a[i].num*2;        //数目翻倍 
			if(a[i].lv==x)              //遍历所有种子，找到等级为x的种子并计数 
			count+=a[i].num;
		}
		if(count>max)
		max=count;
		max1=ceil(max1/3.0);            //最大等级下降 
	}
	cout<<max;
}