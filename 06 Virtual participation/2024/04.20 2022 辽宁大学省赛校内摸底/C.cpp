#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,ans;
	cin>>n;
	map<string,int>m;
	m["A"]=1e8;
	m["B"]=1e8;
	m["C"]=1e8;
	m["AB"]=1e8;
	m["AC"]=1e8;
	m["BC"]=1e8;
	m["ABC"]=1e8;
	for(int i=1;i<=n;i++)
	{
		int c;
		string s;
		cin>>c>>s;
		sort(s.begin(),s.end());
		m[s]=min(c,m[s]);
	}
	ans=1e8;
	ans=min({ans,m["A"]+m["B"]+m["C"],m["AB"]+m["C"],m["AB"]+m["BC"],m["AB"]+m["AC"],m["BC"]+m["AC"],m["AC"]+m["B"],m["BC"]+m["A"],m["ABC"]});
	if(ans==1e8) cout<<"-1\n";
	else cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1=1;
	//cin>>t1;
	while(t1--) solve(); 
}
