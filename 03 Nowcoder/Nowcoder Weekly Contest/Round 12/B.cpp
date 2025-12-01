#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	string a="meituan";
	int k=0;
	set<int>s;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char ch;
			cin>>ch;
			if(s.count(i)) continue;
			if(ch==a[k]) 
			{
				k++;
				s.insert(i);
			}
		}
	}
	if(k==a.size()) cout<<"YES\n";
	else cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
