#include <bits/stdc++.h>
using namespace std;
#define int long long

int p[100000];
void solve()
{
	for(int i=0;i<100000;i++) p[i]=-1;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		p[x]=y;
		p[y]=x;
	}
	int m;
	cin>>m;
	set<int>st;
	for(int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		st.insert(x);
	}
	vector<int>ans;
	for(auto i:st)
	{
		if(p[i]==-1) ans.push_back(i);
		else if(!st.count(p[i])) ans.push_back(i);
	}
	cout<<ans.size()<<"\n";
	int f=0;
	for(auto i:ans)
	{
		if(f) cout<<" ";
		if(i<10) cout<<"0000";
		else if(i<100) cout<<"000";
		else if(i<1000) cout<<"00";
		else if(i<10000) cout<<"0";
		cout<<i;
		f=1;
	}
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
