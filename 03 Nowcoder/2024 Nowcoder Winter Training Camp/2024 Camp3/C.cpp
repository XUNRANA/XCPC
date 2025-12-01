#include <bits/stdc++.h>
using namespace std;
#define P 233
#define N 100010
unsigned long long p[N],h1[N],h2[N];
bool ck(int l,int r,int sz)
{
	//l r
	//     n-r+1   n-l+1
	if(h1[r]-h1[l-1]*p[r-(l-1)]==h2[sz-l+1]-h2[sz-r+1-1]*p[r-(l-1)]) return 1;
	return 0;
} 
void solve()
{
	int n,m,l=0;
	string s,t,str=" ";
	cin>>n>>m>>s>>t;
	reverse(s.begin(),s.end());
	for(int i=0;i<min(n,m);i++)
	{
		if(s[i]!=t[i]) break;
		str+=s[i];
		l++;
	}
	p[0]=1;
	h1[0]=h2[0]=0;
	for(int i=1;i<=l;i++) 
	{
		h1[i]=h1[i-1]*P+((unsigned long long)str[i]);//正向 
		h2[i]=h2[i-1]*P+((unsigned long long)str[l-i+1]);//反向 
		p[i]=p[i-1]*P;
	}
	vector<int>ans1,ans2;
	for(int i=1;i<=l;i++) if(ck(1,i,l)) ans1.push_back(i);
	
	
	str=" ";
	l=0;
	for(int i=0;i<min(n,m);i++)
	{
		if(s[n-1-i]!=t[m-1-i]) break;
		str+=s[n-1-i];
		l++;
	}
	p[0]=1;
	h1[0]=h2[0]=0;
	for(int i=1;i<=l;i++) 
	{
		h1[i]=h1[i-1]*P+((unsigned long long)str[i]);//正向 
		h2[i]=h2[i-1]*P+((unsigned long long)str[l-i+1]);//反向 
		p[i]=p[i-1]*P;
	}
	for(int i=1;i<=l;i++) if(ck(1,i,l)) ans2.push_back(i);
	if(ans1.empty()||ans2.empty())
	{
		cout<<"-1\n";
		return ;
	}
	int ans=-1;
	for(auto num:ans1)
	{
		int cur=min(n,m)-num;
		auto it=upper_bound(ans2.begin(),ans2.end(),cur);
        if(it!=ans2.begin()) ans=max(ans,num+*(--it));
	}
	if(ans==-1) cout<<"-1\n";
	else cout<<2*ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
