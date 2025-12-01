#include <bits/stdc++.h>
using namespace std;
#define N 200010
string s;
int n,l,r;
vector<int>z;
bool ck(int x)
{
	int cnt=0;
	for(int i=1;i<=n;i++) if(z[i]>=x) i+=x-1,cnt++;
	return cnt>=l;
}
vector<int> zfun(string s)//z算法，z[i]表示s[i...n]与s[1..n]的lcp 
{
	vector<int>z(s.size(),0);
	z[1]=n;
	for(int i=2,l=1,r=1;i<=n;i++)
	{
		z[i]=i<=r? min(z[i-l+1],r-i+1):0;
		while(i+z[i]<=n&&s[i+z[i]]==s[1+z[i]]) z[i]++;
		if(i+z[i]-1>r) r=i+z[i]-1,l=i;
	}
	return z;
}
vector<int>g[N];
int ans[N];
void solve()
{
	cin>>n>>l>>r>>s;
	for(int i=1;i<=n;i++) g[i].clear(),ans[i]=0;
	s="$"+s;
	z=zfun(s);
	for(int i=1;i<=n;i++) g[z[i]].push_back(i);
	set<int>st;
	for(int i=n;i>=1;i--)//枚举lcp 
	{
		for(auto t:g[i]) st.insert(t);//能跳的下表 
		int cnt=0,j=1;
		while(j<=n)
		{
			auto it=st.lower_bound(j);
			if(it==st.end()) break;
			cnt++;//段数 
			j=*it+i;
		}
		ans[cnt]=max(ans[cnt],i);//更新 
	}
	ans[n+1]=0;
	for(int i=n;i>=1;i--) ans[i]=max(ans[i],ans[i+1]);//i+1段的lcp，i段一定也满足 
	for(int i=l;i<=r;i++) cout<<ans[i]<<" ";
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
