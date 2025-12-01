#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[4];
int d[4];
void solve()
{
    for(int i=1;i<=3;i++) cin>>a[i];
    for(int i=1;i<=3;i++)
    {
        int x;
        cin>>x;
        d[i]=x-a[i];
    }
    set<int>st;
    int s=0;
    for(int i=1;i<=3;i++)
    {
        if(d[i]%20)
        {
            cout<<"-1\n";
            return ;
        }
        d[i]/=20;
        s+=d[i];
        st.insert((d[i]%3+3)%3);
    }
    if(st.size()!=1||s!=0) 
    {
        cout<<"-1\n";
        return ;
    }
    sort(d+1,d+1+3);
    if(d[2]==0) cout<<d[3]/3*2<<"\n";
    else if(d[2]<0) cout<<-d[2]+(d[3]+2*d[2])/3*2<<"\n";
    else cout<<d[2]+(d[3]-d[2])/3*2<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
