#include <bits/stdc++.h>
using namespace std;
#define int long long
string s,t;
vector<pair<int,char>>ans;
void solve()
{
	cin>>s>>t;
	int i=0,j=0,ls=s.size(),lt=t.size(),f=0;
	while(i<ls&&j<lt)
	{
		if(s[i]==t[j]) i++,j++;
		else
		{
			if(s[i]==t[j+1]&&f==0)
			{
                for(int k=j;k>=0;k--) 
                if(t[k]==t[j]) ans.push_back({k,t[j]});
                else break;
				i++;
				j+=2;
                f=1;
			}
			else
			{
				cout<<"0\n";
				return ;
			}
		}
	}
    if(!ans.size())
    {
        if(t[j]!=t[j-1]) ans.push_back({ls,t[j]});
        else 
        {
            for(int k=j;k>=0;k--) 
            if(t[k]==t[j]) ans.push_back({k,t[j]});
            else break;
        }
    }
    sort(ans.begin(),ans.end());
	cout<<ans.size()<<"\n";
	for(auto i:ans) cout<<i.first<<" "<<i.second<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
