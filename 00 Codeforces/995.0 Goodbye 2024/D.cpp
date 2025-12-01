#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int a[200010],b[200010];
int ta[200010],tb[200010],c[200010];
int n,q;
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%P;
        a=a*a%P;
        b>>=1;
    }
    return res;
}
int inv(int x)
{
    return ksm(x,P-2);
}
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i],ta[i]=a[i];
    for(int i=1;i<=n;i++) cin>>b[i],tb[i]=b[i];
    sort(ta+1,ta+1+n);
    sort(tb+1,tb+1+n);
    for(int i=1;i<=n;i++) c[i]=min(ta[i],tb[i]);
    int res=1;
    for(int i=1;i<=n;i++) res=res*c[i]%P;
    cout<<res<<" ";
    while(q--)
    {
        int o,x;
        cin>>o>>x;
        if(o==1) 
        {
            int i=upper_bound(ta+1,ta+1+n,a[x])-ta;
            ta[i-1]++;

            int tc=c[i-1];
            c[i-1]=min(ta[i-1],tb[i-1]);
            res=res*inv(tc)%P;
            res=res*c[i-1]%P;
            
            a[x]++;
        }
        else 
        {
            int i=upper_bound(tb+1,tb+1+n,b[x])-tb;
            tb[i-1]++;

            int tc=c[i-1];
            c[i-1]=min(ta[i-1],tb[i-1]);
            res=res*inv(tc)%P;
            res=res*c[i-1]%P;
            
            b[x]++;
        }

        cout<<res<<" ";
    }
    cout<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
