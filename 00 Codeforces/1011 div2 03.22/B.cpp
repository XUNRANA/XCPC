#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<pair<int,int>>ans;
	vector<int>b;
	for(int i=n;i>=1;i--)
	{
		if(!a[i]&&i-1>=1&&!a[i-1])
		{
			int f=i;
			int s=i-1;
			while(s-1>=1&&!a[s-1]) s--;
			ans.push_back({s,f});
			i=s;
			b.push_back(1);
		}
		else b.push_back(a[i]);
	}
	
	if(b.size()==1)
	{
		cout<<"3\n";
		cout<<3<<" "<<n<<"\n";
		cout<<1<<" "<<2<<"\n";
		cout<<1<<" "<<2<<"\n";
		return ;
	}
	
	for(int i=0;i<b.size()/2;i++) swap(b[i],b[b.size()-1-i]);
	int cnt=b.size();
	for(int i=b.size()-1;i>=0;i--) 
	if(!b[i])
	{
		cnt--;
		if(i+1<b.size()) ans.push_back({i+1,i+2});
		else if(i-1>=0) ans.push_back({i,i+1});
	}
	ans.push_back({1,cnt});
	cout<<ans.size()<<"\n";
	for(auto i:ans) cout<<i.first<<" "<<i.second<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
