#include <bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
    sort(b+1,b+1+n);
    if(n&1)
    {
        double l=1.0*(b[n/2+1]+b[n/2+2])/2;
        double m=1.0*(b[n/2]+b[n/2+2])/2;
        double r=1.0*(b[n/2+1]+b[n/2])/2;
        int t=b[n/2+1];
        for(int i=1;i<=n;i++)
        {
            if(a[i]<t) printf("%.1f\n",l);
            else if(a[i]==t) printf("%.1f\n",m);
            else printf("%.1f\n",r);
        }
    }
    else
    {
        int tl=b[n/2];
        int tr=b[n/2+1];
        for(int i=1;i<=n;i++)
        {
            if(a[i]<=tl) printf("%.1f\n",1.0*tr);
            else printf("%.1f\n",1.0*tl);
        }
    }
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

