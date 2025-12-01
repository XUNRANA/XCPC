#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,a[2010][2010];
string s;
signed main()
{
    cin>>n>>m;
    map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        int l=0;
        for(int j=1;j<=n;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='0') l++;
            else 
            {
                if(l) mp[l]++;
                l=0;
            }
        }
        if(l) mp[l]++;
    }
    cin>>s;
    ans=0;
    for(auto i:mp)
    {
        if(i.first>=m) ans+=(i.first-m+1)*i.second;
    }
    cout<<ans<<"\n";
}
