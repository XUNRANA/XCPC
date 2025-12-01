#include <bits/stdc++.h>
using namespace std;
int m,x,t,sum;
void solve()
{
	cin>>m>>x>>t;
	m--;
	sum=0;
	priority_queue<int,vector<int>,less<int>>q;
	while(m--)
	{
		sum+=x;
		cin>>t;
		if(sum>=t) q.push(t),sum-=t;
		else if(!q.empty()&&q.top()>t) sum+=q.top()-t,q.pop(),q.push(t);
	}
	cout<<q.size()<<'\n';
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
