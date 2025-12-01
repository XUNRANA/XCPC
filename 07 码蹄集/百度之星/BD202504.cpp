#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int l,r;
    cin>>l>>r;
    if(l==r)
    {
        if(l==1) cout<<"0\n";
        else cout<<"infty\n";
    } 
    else 
    {
        int ans=l-1;
        int x=2*l-r-1;
        if(x<=0) cout<<ans<<"\n";
        else
        {

        
            int f=x%(r-l);
            int c=x/(r-l);
            ans+=(f+x)*(c+1)/2;

            cout<<ans<<"\n";
        }
    }
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
