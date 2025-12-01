#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
	string s,p;
	cin>>s>>p;
	int ls=s.size();
	int lp=p.size();
	if(p.size()==1) 
	{
		cout<<p<<"\n";
		return ;
	}
	int ans=10000;
	int l=0;
	for(int i=0;i<ls;i++)
	{
		if(s[i]==p[0])
		{
			int k=1;
			for(int j=i+1;j<ls;j++)
			{
				if(j-i+1>ans) break;
				if(k<lp&&s[j]==p[k]) k++;
				if(k==lp) 
				{
					if(j-i+1<ans)
					{
						ans=j-i+1;
						l=i;
					}
					break;
				}
			}
		}
	}
	cout<<s.substr(l,ans)<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
