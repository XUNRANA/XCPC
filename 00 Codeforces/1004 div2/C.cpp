#include <bits/stdc++.h>
using namespace std;
#define int long long

int is(int x)
{
    while(x)
    {
        if(x%10==7) return 1;
        x/=10;
    }
    return 0;
}
void solve()
{
    int n;
    cin>>n;
    int ans=9;
    for(int m=10;m<=1e17;m*=10)
    {
        int x=n;
        int sum=0;
        while(sum<=10&&!is(x))
        {
            x+=m-1;
            sum++;
        }
        if(is(x)) ans=min(ans,sum);
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

