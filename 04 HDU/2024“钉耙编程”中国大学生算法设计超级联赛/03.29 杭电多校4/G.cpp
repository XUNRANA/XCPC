#include <bits/stdc++.h>
using namespace std;

void solve() 
{
    int n,q;
    cin>>n>>q;
    vector<int>a(n),b(n),op(n);
    long long ans=0;
    for(int i=0;i<n;i++) cin>>a[i],ans+=a[i];
    for(int i=0;i<n;i++) cin>>b[i],op[i]=b[i];
    int lim=sqrt(n);
    lim=max(1,lim);
    lim=min(n,lim);
    sort(op.begin(),op.end(),greater<int>());
    lim=op[lim-1];
    int ca=0,cb=0;
    vector<int>oa(n),ob(n);
    for(int i=0;i<n;i++)
    {
        if(a[i]<=lim) oa[ca++]=i;
        if(b[i]>lim) ob[cb++]=i;
    }
    while(q--)
    {
        int k;
        cin>>k;
        for(int i=0;i<ca;)
        {
            int t=oa[i];
            if(b[(t+k)%n]>a[t])
            {
                ans+=b[(t+k)%n]-a[t];
                a[t]=b[(t+k)%n];
            }
            if(a[t]>lim) swap(oa[--ca],oa[i]);
            else i++;
        }
        for(int i=0;i<cb;i++)
        {
            int t=ob[i];
            if(a[(t-k+n)%n]<b[t])
            {
                ans+=b[t]-a[(t-k+n)%n];
                a[(t-k+n)%n]=b[t];
            }
        }
        cout<<ans<<"\n";
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