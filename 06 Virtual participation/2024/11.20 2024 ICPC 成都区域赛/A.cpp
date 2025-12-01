#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	if(count(s.begin(),s.end(),'-')==0||s[0]=='-'||s[n-1]=='-'||s[n-2]=='-'||s[n-3]=='-')
	{
		cout<<"No\n";
		return ;
	}
	s=" "+s;
	vector<pair<int,int>>ans;
	for(int i=1;i<=n;i++) 
	if(s[i]=='-')
	{
		for(int j=1;j<=i-2;j++) ans.push_back({j,5});
		
		
		int l=i-1; 
		int tn=n;
		while(1)
		{
			int s=max(tn-4,l);
			ans.push_back({s,5});
			if(s==l) break;
			tn-=3;
		}
		
		for(int j=i;j<=n;j++)
		{
			if(s[j]=='-')
			{
				int st=j-1;
				int cnt=1;
				while(s[j+1]=='-') cnt++,j++;
				ans.push_back({st,4+cnt});
			}
		}
		break;
	}
	

	if(ans.size()>n) cout<<"No\n";
	else
	{	
		cout<<"Yes "<<ans.size()<<"\n";
		for(auto i:ans) cout<<i.first<<" "<<i.second<<"\n";
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
