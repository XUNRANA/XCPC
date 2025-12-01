#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,s,ans,p,p1;
signed main()
{
	cin>>n>>s;
	vector<pair<int,int>>a(n);
	for(int i=0;i<n;i++) cin>>a[i].second>>a[i].first;
	sort(a.begin(),a.end()); 
	for(int i=1;i<n;i++) a[i].second+=a[i-1].second;
	for(int i=0;i<n;i++)
	{
		if(a[n-1].second-p<s)
		{
			ans=p1*s;
			if(i==0) 
			{
				ans+=a[i].first*a[i].second;
				i++;
			}
			for(int j=i;j<n;j++) ans+=(a[j].first-p1)*(a[j].second-a[j-1].second);
			break; 
		}
		p1=a[i].first;
		p=a[i].second;
	} 
	cout<<ans<<"\n";
} 
