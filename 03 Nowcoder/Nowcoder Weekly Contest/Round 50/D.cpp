#include <bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,x,z,x1,x2,a1,b1,a2,b2;
void solve()
{
    cin>>a>>b>>c;
    x=b*b-4*a*c;
    if(x<0)
    {
        cout<<"NO\n";
        return ;
    }
    x=(int)sqrt(x);
    if(x*x!=b*b-4*a*c)
    {
        cout<<"NO\n";
        return ;
    }
    a1=2*a;
    b1=-b+x;

    a2=2*a;
    b2=-b-x;

    x1=__gcd(a1,b1);
    a1/=x1;
    b1/=x1;

    x2=__gcd(a2,b2);
    a2/=x2;
    b2/=x2;
    
    if(a%abs(a1*a2))
    {
        cout<<"NO\n";
        return ;
    }
    z=a/a1/a2;
    cout<<z*a1<<" "<<-z*b1<<" "<<a2<<" "<<-b2<<"\n";
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
} 
