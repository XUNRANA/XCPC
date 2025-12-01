#include <bits/stdc++.h>
using namespace std;
int n,t,f[200010],ans;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
        f[t]=1;
	}
    for(int i=1;i<=200000;i++) if(f[i]) ans++;
    for(int i=1;i<=900;i++)
    {
        int res=i;
        int l=i+1;
        for(int j=1;j<=200000;j++)
        {
            if(f[j])
            {
                res++;
                j+=l-1;
            }
        }
        ans=min(ans,res);
    }
    cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
