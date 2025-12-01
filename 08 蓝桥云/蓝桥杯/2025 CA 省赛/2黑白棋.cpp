#include <bits/stdc++.h>
using namespace std;
#define int long long
bool ck(int x)
{
	string s;
	for(int i=5;i>=0;i--) if(x>>i&1) s+='1';
	else s+='0';
	if(s.find("111")!=-1) return 0;
	if(s.find("000")!=-1) return 0;
	return count(s.begin(),s.end(),'1')==3;
}
string fxs(int x)
{
	string s;
	for(int i=5;i>=0;i--) if(x>>i&1) s+='1';
	else s+='0';
	return s;
}
vector<string>s,p;
set<string>st;
int cnt;
bool check(vector<string>p)
{
	for(int i=5;i>=0;i--)
	{
		string t="";
		for(auto j:p)
		{
			t+=j[i];
		}
		if(!st.count(t)) return 0;
	}
	return 1;
}
void dfs(int idx)
{
	if(p.size()==6)
	{
		vector<string>p1=p;
		int f=0;
		do
		{
			if(check(p1)) f=1;
		}while(next_permutation(p1.begin(),p1.end()));	
		if(f)
		{
			cout<<++cnt<<"\n";
			for(auto i:p) cout<<i<<"\n";
			cout<<"\n";
		}
		return ;
	}
	for(int i=idx;i<14;i++)
	{
		p.push_back(s[i]);
		dfs(i+1);
		p.pop_back();
	}
}
void solve()
{
	for(int i=0;i<(1<<6);i++)
	if(ck(i)) 
	{
		s.push_back(fxs(i));
		st.insert(fxs(i));
	}
	dfs(0);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
