#include <bits/stdc++.h>
using namespace std;
#define int long long
double a1,b1,c1,a2,b2,c2;
void solve()
{
    cin>>a1>>b1>>c1>>a2>>b2>>c2;
    double t=(b1*b2+a2)*(b1*b2+a2)-4*a1*b2*(b2*c1+c2);
    
    if(a1*b2==0)
    {
        if(b1*b2+a2==0)
        {
            if(b2*c1+c2==0) cout<<"INF\n";
            else cout<<"0\n";
        }
        else cout<<"1\n";
    }
    else 
    {
        if(t>0) cout<<"2\n";
        else if(t==0) cout<<"1\n";
        else cout<<"0\n";
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
