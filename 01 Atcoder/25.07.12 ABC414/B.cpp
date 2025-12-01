#include <bits/stdc++.h>
using namespace std;
#define int long long

char ch[110];
int c[110];
void solve()
{
    int n;
    cin>>n;
    int sum=0;
    int f=0;
    for(int i=1;i<=n;i++)
    {
        cin>>ch[i]>>c[i];
        sum+=c[i];
        if(sum>100) f=1;
    }

    if(!f)
    {
        string ans="";
        for(int i=1;i<=n;i++)
        {
            while(c[i]--) ans+=ch[i];
        }
        cout<<ans<<"\n";
    }
    else cout<<"Too Long\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}