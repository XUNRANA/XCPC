#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int l,r,g;
    cin>>l>>r>>g;
    l+=g-1;
    l/=g;
    r/=g;
    int len=r-l;
    while(len>=0)
    {
        for(int j=l;j+len<=r;j++)
        {
            if(__gcd(j,j+len)==1)
            {
                cout<<j*g<<" "<<(j+len)*g<<"\n";
                return ;
            }
        }
        len--;
    }
    cout<<"-1 -1\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

