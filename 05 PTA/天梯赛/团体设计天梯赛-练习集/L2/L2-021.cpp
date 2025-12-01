#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
	string s;
	int k;
	int c;
}a[110];
bool cmp(node a1,node a2)
{
	if(a1.c==a2.c) return a1.k<a2.k;
	return a1.c>a2.c;
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		int k;
		cin>>s>>k;
		a[i].s=s;
		a[i].k=k;
		set<int>st;
		while(k--)
		{
			int c;
			cin>>c;
			st.insert(c);
		}
		a[i].c=st.size();
	}
	sort(a+1,a+1+n,cmp);
	vector<string>ans;
	for(int i=1;i<=n;i++) if(ans.size()<3) ans.push_back(a[i].s);
	while(ans.size()<3) ans.push_back("-");
	int f=0;
	for(auto i:ans) 
	{
		if(f) cout<<" ";
		cout<<i;
		f=1;
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

