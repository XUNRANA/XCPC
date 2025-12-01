#include <bits/stdc++.h>
using namespace std;
int n,x,p[200010],l,r,m,v,pos;
void solve()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++) cin>>p[i];
	pos=find(p+1,p+1+n,x)-p; 
	l=1,r=n+1;
	v=0;
	while(l+1<r)
	{
		m=l+r>>1;
		if(p[m]==x) v=1;
		if(p[m]<=x) l=m;
		else r=m;
	}
	if(p[l]==x)
	{
		cout<<"0\n";
		return ;
	}
	if(v==0||p[l]<=x)//中途找到x，或者最终小于等于x 
	{
		cout<<"1\n";
		cout<<pos<<" "<<l<<"\n";
		return ;
	}
	//最终大于x，中途也没找到x 
	swap(p[l],p[pos]);
	cout<<"2\n";
	cout<<pos<<" "<<l<<"\n";
	pos=l;
	
	l=1,r=n+1;
	v=0;
	while(l+1<r)
	{
		m=l+r>>1;
		if(p[m]==x) v=1;
		if(p[m]<=x) l=m;
		else r=m;
	}
	cout<<pos<<" "<<l<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
