#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define P 1000000007
int n,a[100010],c[2],ans;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<=30;i++)
    {
        c[0]=c[1]=0;
        for(int j=1;j<=n;j++)
        {            
            if(a[j]>>i&1) 
            {
                ans+=c[0]*(n-j+1)%P*(1<<i)%P;
                ans%=P;
                c[1]+=j;
                c[1]%=P;
            }
            else 
            {
                ans+=c[1]*(n-j+1)%P*(1<<i)%P;
                ans%=P;
                c[0]+=j;
                c[0]%=P;
            }
        }
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
