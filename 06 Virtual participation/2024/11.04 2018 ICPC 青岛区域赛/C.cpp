#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve()
{
	int n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	
	if(s==t)
	{
		cout<<n*(n+1)/2<<"\n";//²»»á»»ÐÐ£¿£¿£¿£¿£¿ 
		return ;
	}
	
	vector<int>f(n,0);
	
	for(int i=0;i<n;i++) if(s[i]!=t[i]) f[i]=1;
	
	vector<pair<int,int>>v;
	
	for(int i=0;i<n;i++) 
	if(f[i]==1)
	{
		int j=i+1;
		while(j<n&&f[j]==1) j++;
		v.push_back({i,j-1});
		i=j;
	}
		
	if(v.size()==1) 
	{
		cout<<2*(n-1)<<"\n";
		return ;
	}
	else if(v.size()==2) 
	{ 
		cout<<"6\n";
		return ;
	}
	else  
	{
		cout<<"0\n";
		return ;
	}
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
