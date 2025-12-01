#include <bits/stdc++.h>
using namespace std;
int n,a[110];
bool ck()
{
    int g=0;
    int mi=1e6;
    for(int i=1;i<=n;i++) 
    {
        g=__gcd(g,a[i]);
        if(a[i]) mi=min(mi,a[i]);
    }
    return g==mi;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--)
    {
        for(int j=i-1;j>=1;j--)
        if(a[i]%a[j]==0) a[i]=0;
    }

    
    set<int>st;
    for(int i=1;i<=n;i++) 
    {
        if(a[i]) st.insert(a[i]);
    }
    
    int ans=n-st.size();
    n=0;
    for(auto i:st) a[++n]=i;


    int g=0;
    for(int i=1;i<=n;i++) g=__gcd(g,a[i]);
    if(g==a[1]) cout<<ans+n-1<<"\n";
    else 
    {
        int g=0;
        for(int i=2;i<=n;i++) g=__gcd(g,a[i]);
        if(g>a[1]) 
        {
            cout<<ans+n<<"\n";
            return ;
        }


        int cnt=0;
        for(int i=2;i<=n;i++) cnt+=(a[i]%a[1]==0);
        if(cnt==n-2) 
        {
            cout<<ans+n<<"\n";
            return ;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int t=a[j];
                a[j]%=a[i];
                if(ck()) 
                {
                    cout<<ans+n<<"\n";
                    return ;
                }
                a[j]=t;
            }
        }
        cout<<ans+n+1<<"\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}