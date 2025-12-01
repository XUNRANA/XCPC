#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,a,b;
int fx(int l,int r)
{
    return (l+r)*(r-l+1)/2;
}
void solve()
{
    cin>>n>>a>>b;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=i*(n+1-i);
        if(i>1)
        {
            int r=i-1;//长为1的有i-1个
            int l=i-min(i-1,n+1-i);//最多长为i-1，至少有1
            ans+=fx(l,r);
        }
    }
    b=min(b,a+1-b); 
    vector<int>res(n+2,0);
    for(int i=1;i<=n+1;i++)
    {
        int d=a+1-i;
        if(i<=a) res[i]=min({i,d,b});
        else if(i>a+1&&2*(a+1)-i>=1) res[i]=res[2*(a+1)-i];
    }
    for(int i=1;i<=n+1;i++) ans-=res[i];
    cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
