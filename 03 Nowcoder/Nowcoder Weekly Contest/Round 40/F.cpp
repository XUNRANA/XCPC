#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
double a[100010],p[100010],s,res,ans,t,avg1,avg; 
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],s+=a[i];
    if(n<=2)
    {
        printf("%.6f",s);
        return ;
    }
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--) p[i]=p[i+1]+a[i];
	avg=2*s/n;
	for(int i=1;i<=n;i++)
	{
		avg1=(s-a[i])/(n-1);
		int j=upper_bound(a+1,a+1+n,avg1)-a;
        res=p[j]+(j-1)*avg1;
        res-=max(a[i],avg1);
		t=a[i]+res/(n-1);
        ans+=max(t,avg);
	}
    printf("%.6f",ans/n);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
