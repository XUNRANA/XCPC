#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int l,r;
    cin>>l>>r;
    int a=l,c=r,b=0;
    int o=__lg(r);
    bool fl=1;
    int t=0;
    for(int i=o;i>=0;--i)
	{
        int x=l>>i&1,y=r>>i&1;
        if(x==y)
		{
			if(fl) b|=x<<i;
            else b|=(x^1)<<i;
        }
        else
		{
			if(fl)
			{
				for(int j=i;j>=0;--j)
                if((l>>j&1)==(r>>j&1))
				{
                    t=l>>j&1;
                    break;
                }
                b|=t<<i;
                fl=0;
            }
            else b|=(t^1)<<i;
        }
    }
    cout<<a<<' '<<b<<' '<<c<<'\n';
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
