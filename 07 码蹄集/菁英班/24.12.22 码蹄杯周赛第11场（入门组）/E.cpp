#include <bits/stdc++.h>
using namespace std;
int n;
int a[550][550];
bool ck(int v,set<int>st)
{
	for(auto i:st)
	{
		if(!a[v][i]||!a[i][v]) return false;
	}
	return true;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	for(int j=1;j<=n;j++)
	{
		int x;
		cin>>x;
		a[i][j]=x;
	}
	set<int>st,st1;
	st.insert(1);
	for(int i=2;i<=n;i++) 
	{	
		if(a[1][i]&&a[i][1]&&ck(i,st))
		{
			st.insert(i);
			continue;
		}
		if(ck(i,st1)) st1.insert(i);
		else 
		{
			cout<<"No\n";
			return ;
		}
	}
	
	if(st1.size()==0)
	{
		cout<<"Yes\n";
		cout<<(st.size()+1)/2<<"\n";
	}
	else 
	{
		cout<<"Yes\n";
		cout<<max(st.size(),st1.size())<<"\n";
	}

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
