#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int p[200010];
int a[200010];
void solve()
{
    int n;
    cin>>n;
    n*=2;

    int s=0;//奇数-偶数
    int ss=0;//所有的和
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        ss+=a[i];
        if(i%2==0) a[i]=-a[i];
        p[i]=p[i-1]+a[i];
        s+=a[i];
    }

    set<int>st[2];
    int mx=abs(s);
    for(int i=1;i<=n;i++)
    {
        if(i>1)
        {
            //让s尽量为0
            
            // s-2*x->0;
            // s-2*(p[i]-y)===0
            // s===2*(p[i]-y)
            // y=p[i]-s/2
        
            auto it=st[i&1].lower_bound(p[i]-s/2);
        
            if(it!=st[i&1].end())
            {
                int d=p[i]-(*it);
                mx=min(mx,abs(s-2*d));
            }

            if(it!=st[i&1].begin())
            {
                it--;
                int d=p[i]-(*it);
                mx=min(mx,abs(s-2*d));
            }

            // it=st[i&1].lower_bound(p[i]-(s+1)/2);
        
            // if(it!=st[i&1].end())
            // {
            //     int d=p[i]-(*it);
            //     mx=min(mx,abs(s-2*d));
            // }
            
            // if(it!=st[i&1].begin())
            // {
            //     it--;
            //     int d=p[i]-(*it);
            //     mx=min(mx,abs(s-2*d));
            // }

        }
        st[(i-1)&1].insert(p[i-1]);
    }

    cout<<(ss-mx)/2<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}