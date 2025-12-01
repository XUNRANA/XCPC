#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,l,r;
string s;
int calc(int k)//计算小于等于k的字串数量
{
	if(!k) return 0ll;
	vector<int>cnt(26);
	int op=0,res=0;
	for(int i=1,j=1;j<=n;j++)
	{   
		cnt[s[j]-'a']++; 
		if(cnt[s[j]-'a']==1) op++;//不同字母的个数
		while(i<=n&&op>k) if(--cnt[s[i++]-'a']==0) op--;//核心代码 
		res+=j-i+1; 
	}
	return res;
}
void solve()
{
	cin>>n>>l>>r;
	cin>>s;
	s=' '+s;
	cout<<calc(r)-calc(l-1);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
