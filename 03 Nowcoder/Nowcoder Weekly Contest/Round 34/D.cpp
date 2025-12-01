#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010],mx;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
	
    if(mx==0)
	{
		cout<<"1 ";
		for(int i=2;i<=n;i++) cout<<"2 ";
		cout<<"\n";
	}
	else
	{
		vector<int>b;
		for(int i=1;i<=n;i++) 
		if(a[i]) b.push_back(a[i]);
		int ans=0;
		for(int i=1;i<b.size();i++) ans+=abs(b[i]-b[i-1]);
		
        if(ans>1) cout<<"-1\n";
		else if(ans==1)
		{
            int p=b[0];
			for(int i=1;i<=n;i++)
			{
				if(a[i]) cout<<a[i]<<" ",p=a[i];
				else cout<<p<<" ";
			}
		}
		else if(ans==0)
		{
			if(a[1]&&a[n]) cout<<"-1\n";
			else 
			{
				if(!a[1]) 
				{
					cout<<b[0]+1<<" ";
					for(int i=2;i<=n;i++) cout<<b[0]<<" ";
				}
				else
				{
					for(int i=1;i<=n-1;i++) cout<<b[0]<<" ";
					cout<<b[0]+1<<" ";
				}
			}
		}
 	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

