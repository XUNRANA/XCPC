#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a,b;
int f;
void dfs(int idx,int s)
{
	if(idx==n)
	{
		if(s>=a&&s<=b)
		{
			f=1;
			cout<<s<<"\n";
		}
		return ;
	}
	for(int i=0;i<=9;i++)
	{
		int t=s*10+i;
		if(t%(idx+1)!=0) continue;
		dfs(idx+1,t);
	}
}
void solve()
{
	cin>>n>>a>>b;
	a=max(a,(int)pow(10,n-1));
	b=min(b,(int)pow(10,n)-1);
	int l=to_string(a)[0]-'0';
	int r=to_string(b)[0]-'0';
	for(int i=l;i<=r;i++) dfs(1,i);
	if(!f) cout<<"No Solution\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}


