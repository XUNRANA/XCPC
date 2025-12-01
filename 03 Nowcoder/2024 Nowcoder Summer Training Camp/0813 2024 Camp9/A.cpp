#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int n,m,a=0,b=0,c,d;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='x')
            {
                if(!a&&!b) a=i,b=j,c=i,d=j;
                else c=i,d=j;
            }
        }
    }
    
    n=(c-a+1),m=(d-b+1);
   // cout<<n<<" "<<m<<"\n";
    int t=gcd(n,m);
    n/=t;
    m/=t;
    for(int i=1;i<=n;i++,cout<<"\n")for(int j=1;j<=m;j++) cout<<"x";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}