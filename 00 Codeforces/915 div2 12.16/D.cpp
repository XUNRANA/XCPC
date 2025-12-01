#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x,j,sum,s,ans,cnt[1000010],a[1000010];
void solve()
{
	cin>>n;
	j=ans=0;
	map<int,int>m;
	for(int i=0;i<=n;i++) cnt[i]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]=1;
		while(cnt[j]==1) j++;
		m[j]++; 
	}
	priority_queue<pair<int,int> >q;
	sum=0; 
	for(auto i:m) 
	{
		sum+=i.first*i.second;
		q.push({i.first,i.second});
	}
	ans=max(ans,sum);
	
	for(int i=1;i<=n;i++)
	{
	    s=0;	
	    while(!q.empty()&&q.top().first>a[i]) 
		{
			sum-=q.top().first*q.top().second;
			s+=q.top().second;
			q.pop();
		}
		q.push({a[i],s});
		q.push({n,1});
		sum+=a[i]*s+n;
		ans=max(ans,sum);
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1; 
	while(t1--) solve();
}
