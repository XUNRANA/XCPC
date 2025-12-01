#include <bits/stdc++.h>
using namespace std;
int a[500010],t,n,m,op,x,y;
int lowbit(int x)
{
	return x&-x;
}
void update(int i,int x)
{
	while(i<=n)
	{
		a[i]+=x;
		i+=lowbit(i);
	}
}
int sum(int i)
{
	int res=0;
	while(i)
	{
		res+=a[i];
		i-=lowbit(i);
	}
	return res;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		update(i,t);
	}
	while(m--)
	{
		cin>>op>>x>>y;
		if(op==1) update(x,y);
		else cout<<sum(y)-sum(x-1)<<"\n";
	}
}
