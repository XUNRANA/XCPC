#include <bits/stdc++.h>
using namespace std;
#define int long long
int tr[400010];
int a[400010];
int n;
int lowbit(int x)
{
	return x&-x;
}
void add(int i,int x)
{
	while(i<=n)
	{
		tr[i]+=x;
		i+=lowbit(i);
	}
}
int query(int i)
{
	int res=0;
	while(i)
	{
		res+=tr[i];
		i-=lowbit(i);
	}
	return res;
}
void solve()
{
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) tr[i]=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        add(i,a[i]);
    }
    int ans=0,cnt=0;
    while(q--)
    {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1)
        {
            add(x,y-a[x]);
            a[x]=y;
        }
        else
        {
            cnt++;
            ans^=cnt*(query(y)/100-query(x-1)/100);
        }
    }
    cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}