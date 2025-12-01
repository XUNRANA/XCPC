#include <bits/stdc++.h>
using namespace std;
int n,k;
double a[200010],b[200010];
double ans;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	if(n==k) 
	{
		cout<<"0\n";
		return ;
	}
	ans=a[n]-a[1];
    if(k==1)
    {
        printf("%.6f",ans);
        return ;
    }
	for(int i=0;i<=k;i++)
	{
		double res=b[i]-b[0]+b[n]-b[n-k+i];
		res=res/k;
		ans=min(ans,max({a[i+1],a[n-k+i],res})-min({a[i+1],a[n-k+i],res}));
	}
	printf("%.10f",ans);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

