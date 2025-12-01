#include <bits/stdc++.h>
using namespace std;
int t,n,k;
int a[500100],c[500100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		vector<int>b,d;
		cin>>n>>k;
		map<int,int>m1;
		for(int i=1;i<=2*n;i++) cin>>a[i],c[i]=0;
		for(int i=1;i<=n;i++) c[a[i]]++;
		
		for(int i=1;i<=n;i++) 
		if(c[i]==1&&b.size()<2*k) b.push_back(i),d.push_back(i);
		
		if(b.size()&1) b.pop_back(),d.pop_back();
		
		for(int i=1;i<=n;i++) 
		{
			if(c[i]==2&&b.size()<2*k) b.push_back(i),b.push_back(i);
			if(c[i]==0&&d.size()<2*k) d.push_back(i),d.push_back(i);
		}
		for(auto i:b) cout<<i<<" ";
		cout<<"\n";
		for(auto i:d) cout<<i<<" ";
		cout<<"\n";
	}
}
