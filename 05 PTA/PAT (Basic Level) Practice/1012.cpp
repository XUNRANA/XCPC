#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[6],c,ff;
void solve()
{
    int n;
    cin>>n;
    int f=1;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x%10==0) a[1]+=x;
        else if(x%5==1) a[2]+=x*f,f*=-1,ff=1;
        else if(x%5==2) a[3]++;
        else if(x%5==3) a[4]+=x,c++;
        else if(x%5==4) a[5]=max(a[5],x);
    }
    for(int i=1;i<=5;i++)
    {
        if(i>1) printf(" ");
        if(i==2)
        {
            if(!ff) printf("N");
            else printf("%d",a[i]);
            continue;
        }
        if(!a[i]) printf("N");
        else if(i==4) printf("%.1f",1.00*a[i]/c);
        else printf("%d",a[i]);
    }
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}