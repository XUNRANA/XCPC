#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int x,y,ans;
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
int jc[300];
void init()
{
    jc[0]=1;
    for(int i=1;i<=200;i++) jc[i]=jc[i-1]*i%P;
}
int C(int a,int b)
{
    int res=1;
    for(int i=a;i>=a-b+1;i--) res=res*i%P;
    return res*ksm(jc[b],P-2)%P;
}
void solve()
{
    cin>>x>>y;
    if(x==1||y==1) 
    {
        cout<<"1\n";
        return ;
    }
    map<int,int>mp;
    for(int i=2;i*i<=x;i++)
    {
        while(x%i==0)
        {
            mp[i]++;
            x/=i;
        }
    }
    if(x!=1) mp[x]++;

    ans=1;
    for(auto i:mp) ans=ans*C(i.second+y-1,i.second)%P;
    cout<<ans<<"\n";
}

signed main()
{
    init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
