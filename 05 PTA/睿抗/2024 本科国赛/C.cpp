#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5];
void solve() 
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int s=0;
    vector<int>b;
    do
    {
        int t=0;
        for(int i=1;i<=n;i++) t=t*10+a[i];
        b.push_back(t);
        s+=t*t;
    }while(next_permutation(a+1,a+1+n));
    int len=b.size();
    for(int i=0;i<(1<<len);i++)
    {
        int ss=0;
        int cc=0;
        for(int j=0;j<len;j++)
        if(i>>j&1) ss+=b[j]*b[j],cc++;
        if(cc==len/2&&ss==s/2)
        {
            for(int j=0;j<len;j++)
            if(i>>j&1) cout<<b[j]<<"\n";
            return ;
        }
    }
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}