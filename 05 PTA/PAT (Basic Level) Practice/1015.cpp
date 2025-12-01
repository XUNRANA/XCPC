#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int a,b,s,id;
    int r;
}p[100010];
bool cmp(node p1,node p2)
{
    if(p1.r==p2.r)
    {
        if(p1.s==p2.s) 
        {
            if(p1.a==p2.a) return p1.id<p2.id;
            return p1.a>p2.a;
        }
        return p1.s>p2.s;
    }
    return p1.r<p2.r;
}
void solve()
{
    int n,l,h;
    cin>>n>>l>>h;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].id>>p[i].a>>p[i].b;
        if(p[i].a>=l&&p[i].b>=l) p[i].r=4;
        else p[i].r=5;

        if(p[i].r==4)
        {
            if(p[i].a>=h&&p[i].b>=h) p[i].r=1;
            else if(p[i].a>=h) p[i].r=2;
            else if(p[i].a<h&&p[i].b<h&&p[i].a>=p[i].b) p[i].r=3;
        } 
        if(p[i].r!=5) cnt++; 
        p[i].s=p[i].a+p[i].b;
    }
    sort(p+1,p+1+n,cmp);
    cout<<cnt<<"\n";
    for(int i=1;i<=cnt;i++) cout<<p[i].id<<" "<<p[i].a<<" "<<p[i].b<<"\n";

}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}