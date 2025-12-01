#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    vector<int>a;
    for(int i=0;i<s.size();i++)
    if(s[i]=='t') a.push_back(i);
    
    double ans=0;
    for(int i=0;i<a.size();i++)
    {
        for(int j=i+1;j<a.size();j++)
        {
            if(a[j]-a[i]+1>=3)
            {
                ans=max(ans,1.0*(j-i+1-2)/(a[j]-a[i]+1-2));
            }
        }
    }
    printf("%.17f",ans);
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

