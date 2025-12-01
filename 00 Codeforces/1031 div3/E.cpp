#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string a,b;
    cin>>a>>b;
    int n=a.size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[i]) ans+=2;
        else
        {
            if(b[i]-a[i]==1)
            {
                ans++;
                int r1=0,r2=0;
                //a
                for(int j=i+1;j<n;j++)
                if(a[j]=='9') r1++;
                else 
                {
                    if(a[j]=='8'&&b[j]=='9') r1++;
                    break;
                }

                for(int j=i+1;j<n;j++)
                if(b[j]=='0') r2++;
                else 
                {
                    if(b[j]=='1'&&a[j]=='0') r2++;
                    break;
                }

                cout<<ans+min(r1,r2)<<"\n";
                return ;
            }
            else 
            {
                cout<<ans<<"\n";
                return ;
            }
        }
    }
    cout<<ans<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}