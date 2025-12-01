#include <bits/stdc++.h>
using namespace std;
int n,a[1000010],b[1000010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
	sort(b+1,b+1+n);
	multiset<int>st1,st2;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[i])
		{
			if(st1.empty()) ans++;
			continue;
		}
		
		if(st2.find(a[i])!=st2.end())
		{
			st2.erase(st2.find(a[i]));
		}
		else st1.insert(a[i]);
		
		if(st1.find(b[i])!=st1.end())
		{
			st1.erase(st1.find(b[i]));
		}
		else st2.insert(b[i]);
		
		if(st1.empty()) ans++;
	}
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
