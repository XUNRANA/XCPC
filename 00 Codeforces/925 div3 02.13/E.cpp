#include <bits/stdc++.h>
using namespace std;
int n,m,s,c1,t1;
int f(int x)
{
	int c=0;
	while(x)
	{
		c++;
		x/=10;
	}
	return c;
}
void solve()
{
	s=0;
	cin>>n>>m;
	priority_queue<int> q;
	for(int i=1;i<=n;i++) 
	{
		c1=0;
		cin>>t1;
		s+=f(t1);
		while(t1%10==0) t1/=10,c1++;
		if(c1) q.push(c1);
	}
	
	while(!q.empty())
	{
		s-=q.top();
		q.pop();
		if(!q.empty()) q.pop();		
	}
	if(s>=m+1) cout<<"Sasha\n";
	else cout<<"Anna\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
