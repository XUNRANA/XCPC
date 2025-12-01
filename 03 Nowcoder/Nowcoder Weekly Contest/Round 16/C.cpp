#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define N 100010
int n,h,a;
struct node
{
	int h,a;
}b[N];
bool cmp(node b1,node b2)
{
	if(b1.h==b2.h) return b1.a>b2.a;
	return b1.h<b2.h;
}
void solve()
{
	cin>>n>>h>>a;
	for(int i=1;i<=n;i++) cin>>b[i].h;
	for(int i=1;i<=n;i++) cin>>b[i].a;
	sort(b+1,b+1+n,cmp);
	vector<int>c;
	for(int i=1;i<=n;i++) 
	{
		if(b[i].a>=a||b[i].h>=h) continue;
		if(lower_bound(c.begin(),c.end(),b[i].a)==c.end()) c.push_back(b[i].a);
		else *lower_bound(c.begin(),c.end(),b[i].a)=b[i].a;
	}
	cout<<c.size()<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

/*
#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,h,a,ans=0;
	cin>>n>>h>>a;
	vector<pair<int,int>>v(n); 
	for(int i=0;i<n;i++) cin>>v[i].first;
	for(int i=0;i<n;i++) cin>>v[i].second;
	sort(v.begin(),v.end());
	vector<int>dp(n+1);
	for(int i=0;i<n;i++) 
    if(v[i].first<h&&v[i].second<a) 
    {
        dp[i]=1;
        ans=max(ans,dp[i]);
    }
	for(int i=0;i<n;i++)
	{
		if(v[i].first>=h||v[i].second>=a) continue;
		for(int j=0;j<i;j++)
		{
			if(v[j].first>=h||v[j].second>=a) continue;
			if(v[j].first<v[i].first&&v[j].second<v[i].second)
            {
                dp[i]=max(dp[i],dp[j]+1);
			    ans=max(ans,dp[i]);
            }
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
*/
