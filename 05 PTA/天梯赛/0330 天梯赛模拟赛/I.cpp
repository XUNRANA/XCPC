#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int a;//进入
    int b;//需要运行
    int c;//优先权
    int i;
    bool operator < (const node &a) const{
        if(c==a.c) return i>a.i;
        return c<a.c;
    }
}p[100010];
bool cmp(node p1,node p2)
{
    return p1.a<p2.a;
}
void solve() 
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        int a,b,c;
        cin>>a>>b>>c;
        p[i]={a,b,c,i};
    }
    sort(p+1,p+1+n,cmp);
    priority_queue<node>q;
    vector<int>ans;
    int now=0;
    int j=1;
    int s=0;
    int cnt=0;
    while(cnt<n)
    {
        while(j<=n&&p[j].a<=now)
        {
            q.push(p[j]);
            j++;
        }
        if(!q.empty())
        {
            int a=q.top().a;
            int b=q.top().b;
            int i=q.top().i;
            q.pop();
            ans.push_back(i);
            now+=b;
            s+=now-a;
            cnt++;
        }  
        else if(j<=n) now=p[j].a;
    }

    for(int i=0;i<n;i++) if(i<n-1) printf("p%d,",ans[i]);
    else printf("p%d\n",ans[i]);
    printf("%.2f",1.0*s/n);
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}