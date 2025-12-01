#include <bits/stdc++.h>
using namespace std;
#define N 300010
int n,m,op,x,y,t,tr[N];
int lowbit(int x)
{
	return x&-x;
}
int query(int i)
{
	int res=0;
	while(i)
	{
		res^=tr[i];
		i-=lowbit(i);
	}
	return res;
}
void update(int i,int x)
{
	while(i<N)
	{
		tr[i]^=x;
		i+=lowbit(i);
	}
}

void solve()
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
		else cout<<(query(y)^query(x-1))<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

