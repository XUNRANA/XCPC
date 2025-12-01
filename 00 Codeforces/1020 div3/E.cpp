#include <bits/stdc++.h>
using namespace std;
int n,q;
int p[200010];
int idx[200010];
int c1,c2;
int c11,c22;
void fx(int l,int r,int i)
{
    int m=l+r>>1;
    if(m==i) return ;
    else if(m<i)
    {
        if(p[m]>p[i]) c1++;
        else c11++;
        fx(m+1,r,i);
    }
    else
    {
        if(p[m]<p[i]) c2++;
        else c22++;
        fx(l,m-1,i);
    }
}
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++) 
    {
        cin>>p[i];
        idx[p[i]]=i;
    }
    while(q--)
    {
        int l,r,x;
        cin>>l>>r>>x;
        if(idx[x]<l||idx[x]>r) cout<<"-1 ";
        else
        {
            c1=c2=c11=c22=0;
            fx(l,r,idx[x]);
            // cout<<c1<<" "<<c2<<"\n";
            if(max(c1,c2)>min(x-1,n-x)||c11+c1>x-1||c2+c22>n-x) cout<<"-1 ";
            else cout<<max(c1,c2)*2<<" ";
        }
    }
    cout<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
