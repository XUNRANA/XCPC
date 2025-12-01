#include <bits/stdc++.h>
using namespace std;
int f[100010],n,g,t,ans;
int gcd(int x,int y)
{
    return y==0? x:gcd(y,x%y);
}
void solve()
{
    g=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        g=gcd(g,t);
        f[t]=1;
    }
    if(g==1) f[1]=1;
    for(int i=2;i<=100000;i++)
    {
        if(f[i]) continue;
        g=0;
        for(int j=i+i;j<=100000;j+=i) if(f[j]) g=gcd(g,j);
        if(g==i) f[i]=1;
    }
    ans=0;
    for(int i=1;i<=100000;i++) if(f[i]) ans++,f[i]=0;
    if((ans-n)&1) cout<<"dXqwq\n";
    else cout<<"Haitang\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
} 