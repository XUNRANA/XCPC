#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,a[200010];
int ans[200010];
struct node
{
    int l,r,i;
}q[200010];
int B;

bool cmp(node q1,node q2)//按l/B、r排序 
{
	if(q1.l/B!=q2.l/B) return q1.l<q2.l;
	return q1.r<q2.r;
}
map<int,int>mp;
int sum;
void add(int x)//扩展一个数 
{
    mp[x]++;
}
void del(int x)//删除一个数 
{
    mp[x]--;
}




void solve()
{
    cin>>n>>m;
    B=sqrt(n);
    for(int i=1;i<=n;i++) cin>>a[i];
    
    for(int i=1;i<=m;i++)
    {
        cin>>q[i].l>>q[i].r;
        q[i].i=i;
    }

    sort(q+1,q+1+m,cmp);


    for(int i=1,l=1,r=0;i<=m;i++)
	{
		while(l>q[i].l) add(a[--l]);//左扩展 
		while(r<q[i].r) add(a[++r]);//右扩展 
		while(l<q[i].l) del(a[l++]);//左删除 
		while(r>q[i].r) del(a[r--]);//右删除 
		ans[q[i].i]=sum;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<"\n";

}
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}