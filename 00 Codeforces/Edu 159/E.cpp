#include <bits/stdc++.h>
using namespace std;

int nex[1000010][26];
int cnt[1000010];
int tot;
void insert(string s)//插入trie树 
{
	int now=0;
	for(auto i:s)
	{
		if(!nex[now][i-'a']) nex[now][i-'a']=tot++;
		now=nex[now][i-'a'];
		cnt[now]++;
	}
}
int query(string s)
{
	int now=0;
	int res=0;
	for(auto i:s)
	{
		if(!nex[now][i-'a']) return res;
		now=nex[now][i-'a'];
		res+=cnt[now];
	}
	return res;
}
string s[1000010];
void solve()
{
	int n;
	cin>>n;
	tot=1;
	int sz=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		sz+=s[i].size();
		insert(s[i]);
	}
	long long ans=2ll*n*sz;
	for(int i=1;i<=n;i++) 
	{
		reverse(s[i].begin(),s[i].end());
		ans-=2*query(s[i]);
	}
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
