#include <bits/stdc++.h>
using namespace std;

int idx[1010];
char a[1010][1010];
void solve()
{
	int n,m,s,t;
	cin>>n>>m>>s;
	stack<char>st;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	for(int i=1;i<=n;i++) idx[i]=1;
	string ans="";
	while(1)
	{
		cin>>t;
		if(t==-1) break;
		if(!t)
		{
			if(st.size())
			{
				ans+=st.top();
				st.pop();
			}
			continue;
		}
		if(idx[t]<=m)
		{
			while(st.size()==s)
			{
				ans+=st.top();
				st.pop();
			}
			st.push(a[t][idx[t]]);
			idx[t]++;
		}
	}
	cout<<ans<<"\n";
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

