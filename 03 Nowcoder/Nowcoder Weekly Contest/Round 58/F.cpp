#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int n,m,ansl,ansr,a[200010],b[200010],l[200010],r[200010],k[200010];
int ck(int x)
{
    for(int i=1;i<=n;i++) 
    {
        if(a[i]<=x) b[i]=b[i-1]+1;
        else b[i]=b[i-1];
    }
	for(int i=1;i<=m;i++)
	{
		int cnt=0;
		cnt=b[r[i]]-b[l[i]-1];
		if(cnt>k[i]) return 1;
		else if(cnt<k[i]) return -1;
	}
	return 0;
}
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%P;
		a=a*a%P;
		b>>=1;
	}
	return res;
}
int inv(int x)
{
	return ksm(x,P-2);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>l[i]>>r[i]>>k[i];
	int l=1,r=n;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(ck(mid)==1) r=mid-1;
		else l=mid+1; 
	}
	ansr=l-1;
	l=1,r=n;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(ck(mid)!=-1) r=mid-1;
		else l=mid+1;
	}
	ansl=l;
	if(ansr==ansl) cout<<1<<" "<<ansr<<"\n";
	else cout<<inv(ansr-ansl+1)<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

