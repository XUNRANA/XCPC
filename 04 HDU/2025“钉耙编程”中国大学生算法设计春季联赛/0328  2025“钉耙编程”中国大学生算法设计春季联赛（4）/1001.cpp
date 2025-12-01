#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int h;//血量
    int a;//攻击力
    int i;//编号
    int mx;
}a[10010];
bool cmp(node a1,node a2)
{
    if(a1.h==a2.h)
    {
        if(a1.a==a2.a) return a1.i<a2.i;
        return a1.a<a2.a;
    }
    return a1.h<a2.h;
}
void solve()
{
    int n,u,k,hq;
    cin>>n>>u>>k>>hq;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].a>>a[i].h;
        a[i].i=i;
    }
    sort(a+1,a+1+n,cmp);
    multiset<int>st;
    for(int i=1;i<=n;i++) st.insert(a[i].a);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int uu=u;
        for(int j=1;j<=k;j++)
        {
            if(j==2) uu/=2;
            if(!uu)
            {
                hq-=(k-j+1)*(*st.rbegin());
                if(hq<=0)
                {
                    cout<<cnt<<"\n";
                    return ;
                }
            }
            a[i].h-=uu;
            if(a[i].h<=0)
            {
                cnt++;
                st.erase(st.find(a[i].a));
                if(st.size()) 
                {
                    hq-=*st.rbegin();
                    if(hq<=0)
                    {
                        cout<<cnt<<"\n";
                        return ;
                    }
                }
                break;
            }
            else
            {
                if(st.size()) 
                {
                    hq-=*st.rbegin();
                    if(hq<=0)
                    {
                        cout<<cnt<<"\n";
                        return ;
                    }
                }
            }
        }
    }
    cout<<cnt<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}