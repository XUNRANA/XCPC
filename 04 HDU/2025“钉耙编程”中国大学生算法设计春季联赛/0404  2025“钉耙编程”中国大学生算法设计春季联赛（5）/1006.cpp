#include <bits/stdc++.h>
using namespace std;
#define int long long
int d,r,x,y;
int dis(int x1,int y1)
{
    return (int)(sqrtl((x1-x)*(x1-x)+(y1-y)*(y1-y))+0.5);
}
double dis1(int x1,int y1)
{
    return sqrtl((x1-x)*(x1-x)+(y1-y)*(y1-y));
}
void solve()
{
    cin>>d>>r>>x>>y;
    if(x>=-r&&x<=r&&y>=-d&&y<=d)
    {
        cout<<min({abs(r-x),abs(x+r),dis(-r,d),dis(r,-d),dis(-r,-d),dis(r,d)});
        return ;
    }
    if(y>d)
    {
        cout<<min({dis(-r,d),dis(r,d),(int)(fabs(r-dis1(0,d))+0.5)})<<"\n";
    }
    else if(y<-d)
    {
        cout<<min({dis(-r,-d),dis(r,-d),(int)(fabs(r-dis1(0,-d))+0.5)})<<"\n";
    }
    else if(x<-r)
    {
        cout<<-r-x<<"\n";
    }
    else if(x>r)
    {
        cout<<x-r<<"\n";
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