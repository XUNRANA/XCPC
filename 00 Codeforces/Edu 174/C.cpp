#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353

int n,a[200010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    int ans=0;
    int cnt=0;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1) 
        {
            cnt++;
            res++;
            res%=P;
            // b.push_back(0);
        }
        else if(a[i]==2)
        {
            res*=2;
            res%=P;
            // for(auto &j:b) j++;
        }
        else
        {
            ans=(ans+(res-cnt+P)%P)%P;

            // int res=0;
            // for(auto j:b) res+=ksm(2,j)-1;
            // ans+=res;
        }
    }
    cout<<ans<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

