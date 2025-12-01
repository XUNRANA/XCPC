#include <bits/stdc++.h>
using namespace std;


bool is(int x)
{
	if(x<2) return 0;
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
int rk[10010];
void solve()
{
	int n,q,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		rk[x]=i;
	}
	cin>>q;
	set<int>st;
	while(q--)
	{
		cin>>x;
		string res=to_string(x);
		while(res.size()<4) res="0"+res;
		if(!rk[x]) cout<<res<<": Are you kidding?\n";
		else 
		{
			if(st.count(x)) 
			{
				cout<<res<<": Checked\n";
				continue;
			}
			if(rk[x]==1) cout<<res<<": Mystery Award\n";
			else if(is(rk[x])) cout<<res<<": Chocolate\n";
			else cout<<res<<": Minion\n";
			st.insert(x);
		}
	}	
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
