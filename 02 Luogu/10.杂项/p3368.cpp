#include <bits/stdc++.h>
using namespace std;
int a[500010],t[500010],tmp,op,x,y,k,n,m;
int lowbit(int i)
{
	return i&-i;
}
void add(int i,int x)
{
	while(i<=n)
	{
		t[i]+=x;
		i+=lowbit(i);
	}
}
int sum(int i)
{
	int res=0;
	while(i)
	{
		res+=t[i];
		i-=lowbit(i);
	}
	return res;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) add(i,a[i]-a[i-1]);
	while(m--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>x>>y>>k;
			add(x,k);
			add(y+1,-k);
		}
		else
		{
			cin>>x;
			cout<<sum(x)<<"\n";
		}
	}
}
