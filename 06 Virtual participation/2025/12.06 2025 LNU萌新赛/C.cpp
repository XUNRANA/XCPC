#include <bits/stdc++.h>
using namespace std;

int n;
string s[1010];

void solve()
{
    while(cin>>n)
    {
        int f=0;
        for(int i=1;i<=n;i++) 
        {
            cin>>s[i];
            if(!f)
            {
                if(s[i][0]==s[i][1]&&s[i][0]=='O')
                {
                    s[i][0]=s[i][1]='+';
                    f=1;
                }
                else if(s[i][3]==s[i][4]&&s[i][3]=='O')
                {
                    s[i][3]=s[i][4]='+';
                    f=1;
                }
            }
        }
        if(f) 
        {
            cout<<"YES\n";
            for(int i=1;i<=n;i++) cout<<s[i]<<"\n";
        }
        else cout<<"NO\n";
    }
} 
signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}