#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int x,y;
}a[1010];
bool cmp(node a1,node a2)
{
    if(a1.y==a2.y) return a1.x<a2.x;
    return a1.y<a2.y;
}
int n;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].x;
    for(int i=1;i<=n;i++) cin>>a[i].y;
    sort(a+1,a+1+n,cmp);
    set< array<int,4> >st;
    set<int>st1;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int nx=a[i].x+a[j].x;
            int ny=a[i].y+a[j].y;
            int dx=a[j].x-a[i].x;
            int dy=a[j].y-a[i].y;
            
            if(dy==0)
            {
                st1.insert(nx);
                continue;
            }
            int dy1=-1*dx;
            int dx1=dy;
            int g=__gcd(abs(dx1),abs(dy1));
            dx1/=g;
            dy1/=g;
            int fm=dx1*ny-dy1*nx;
            int fz=dx1;
            g=__gcd(abs(fm),abs(fz));
            fm/=g;
            fz/=g;
            if(fm<0) fm*=-1,fz*=-1;
            st.insert({dx1,dy1,fz,fm});
        }
    }
    cout<<st.size()+st1.size()<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
