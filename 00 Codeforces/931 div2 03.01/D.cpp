#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,f,s;
void fx(int x)
{
	for(int i=63;i>=0;i--) cout<<(x>>i&1? 1:0);
	cout<<"\n";
}
void solve()
{
	cin>>n>>m;
	if((n^m)<n) 
	{
		cout<<"1\n"<<n<<" "<<m<<"\n";
		return ;
	}
	f=s=-1;
	for(int i=63;i>=0;i--) 
	if((n>>i&1)==1)
	{
		if(f==-1) f=i;
		else if(s==-1) s=i;
	}
	/*
	cout<<f<<" "<<s<<"\n";
	fx(n);
	fx((1<<(s+1))-1);
	fx(m);
	*/
	if(s==-1) cout<<-1<<"\n"; 
	else if((1ll<<(s+1))-1==m) cout<<"1\n"<<n<<" "<<m<<"\n";
	else if((1ll<<(s+1))-1>m) cout<<"2\n"<<n<<" "<<(1ll<<(s+1))-1<<" "<<m<<"\n";
	else cout<<-1<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
