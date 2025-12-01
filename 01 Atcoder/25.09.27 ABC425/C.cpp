#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
int a[400010];
int s[400010];
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(int i=1;i<=2*n;i++) s[i]=s[i-1]+a[i];

    // for(int i=1;i<=2*n;i++) cout<<a[i]<<" ";
    // cout<<"\n";

    // for(int i=1;i<=2*n;i++) cout<<s[i]<<" ";
    // cout<<"\n";

    int d=0;
    while(q--)
    {
        int op,l,r,c;
        cin>>op;
        if(op==2) 
        {
            cin>>l>>r;
            cout<<s[r+d]-s[l+d-1]<<"\n";
        }
        else 
        {
            cin>>c;
            d+=c;
            d%=n;
        }
    }

}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
