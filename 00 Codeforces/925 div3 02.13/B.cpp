#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200010],s,s1,n;
void solve()
{
	s=s1=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],s+=a[i];
	if(s%n==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>s/n) s1+=a[i]-s/n;
			else if(a[i]<s/n)
			{
				s1-=s/n-a[i];
				if(s1<0)
				{
					cout<<"NO\n";
					return ;
				}
			}	
		} 
	}
	cout<<"YES\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
