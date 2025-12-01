#include <bits/stdc++.h>
using namespace std;
#define int long long


int n;
int dp[200010][2];
int a[200010];
int b[200010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    vector<int>c,d;
    for(int i=1;i<=n;i++)
    if(i&1)
    {
        c.push_back(a[i]);
        d.push_back(b[i]);
    }
    else
    {
        c.push_back(b[i]);
        d.push_back(a[i]);
    }

    if(c.back()==d.back()) 
    {
        cout<<n<<"\n";
        return ;
    }

    int pc=c[n-1];
    int pd=d[n-1];

    set<int>s1,s2;
    for(int i=n-2;i>=0;i--)
    {
        if(c[i]==d[i])
        {
            cout<<i+1<<"\n";
            return ;
        }
        else
        {
            if(s1.count(c[i])||s2.count(d[i]))
            {
                cout<<i+1<<"\n";
                return ;
            }
            else 
            {
                s1.insert(pc);
                s2.insert(pd);
                if(s1.count(d[i])||s2.count(c[i]))
                {
                    cout<<i+1<<"\n";
                    return ;
                }
                else
                {
                    pc=c[i];
                    pd=d[i];
                }
            }
        }
    }
    cout<<"0\n";

}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}