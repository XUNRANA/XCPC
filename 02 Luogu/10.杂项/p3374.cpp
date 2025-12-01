#include <bits/stdc++.h>
using namespace std;
int t[500010],tmp,op,x,y,n,m;
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
	for(int i=1;i<=n;i++) cin>>tmp,add(i,tmp);
	while(m--)
	{
		cin>>op>>x>>y;
		if(op==1) add(x,y);
		else cout<<sum(y)-sum(x-1)<<"\n";
	}
}
