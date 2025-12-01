#include <bits/stdc++.h>
using namespace std;
int a[200010];
int n,x,y;
void solve()
{
    cin>>n>>x>>y;
    if(n%2==0)//1 0 1 0
    {
        for(int i=1;i<=n;i++) a[i]=i&1;
        if(a[x]==a[y])
        {
            if(a[x]==0) for(int i=1;i<=n;i++) a[i]^=1;
            a[x]=2;
        }
        for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
    }
    else//2 0 1 0 1
    {
        for(int i=1;i<=n;i++) a[i]=i&1;
        a[1]=2;
        if(x!=1)
        {
            if(a[x]==a[y])
            {
                if(a[x]==0) for(int i=2;i<=n;i++) a[i]^=1;
                if(x!=2) a[x]=2;
                else a[y]=2;
            }
        }
        for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
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
