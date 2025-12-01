#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    if(n==1) cout<<"1\n";
    else if(n==2) cout<<abs(a[1]-a[2])+1<<"\n";
    else
    {
        int x=a[n/2],res1=0;
        int y=a[n/2+1],res2=0;
        for(int i=1;i<=n;i++) res1+=abs(a[i]-x),res2+=abs(a[i]-x);
        cout<<min(res1,res2)+1<<"\n";
    }
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000010],l,r,m,ans;
int ck(int x)
{
	int res=0;
	for(int i=1;i<=n;i++) res+=abs(a[i]-x);
	return res;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	l=0,r=1e9;
	while(l<=r)
	{
		m=l+r>>1;
		if(ck(m)<ck(m+1)) r=m-1,ans=m;
		else l=m+1;
	}
	cout<<ck(ans)+1<<"\n";
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

*/
