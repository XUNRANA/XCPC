#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[300010],cnt[300010],vt[300010];
bool ck(int x,int y,int o)
{
	if(o) return x>y;
	return y>x;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) vt[i]=cnt[i]=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	vector<int>ans;
	for(int i=1;i<=n;i++)
	{
		cnt[a[i]]--;
		if(!ans.size())
		{
			ans.push_back(a[i]);
			vt[a[i]]=1;
			continue;
		}
		if(vt[a[i]]) continue;
		while(ans.size())
		{
			int sz=ans.size();
			if(cnt[ans[sz-1]]&&ck(a[i],ans[sz-1],sz&1))
			{
				vt[ans[sz-1]]=0;
				ans.pop_back();
			}
			else if(sz>1&&cnt[ans[sz-1]]&&cnt[ans[sz-2]]&&ck(a[i],ans[sz-2],(sz-1)&1))
			{
				vt[ans[sz-1]]=0;
				vt[ans[sz-2]]=0;
				ans.pop_back();
				ans.pop_back();
			}
			else break;
		}
		ans.push_back(a[i]);
		vt[a[i]]=1;
		
		

	}
	cout<<ans.size()<<"\n";
	for(auto i:ans) cout<<i<<" ";
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
