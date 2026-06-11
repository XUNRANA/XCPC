#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x,y;

void solve()
{
    cin>>n>>x>>y;
    string s;
    cin>>s;
    int c0=count(s.begin(),s.end(),'0');
    int c1=count(s.begin(),s.end(),'1');
    int c2=count(s.begin(),s.end(),'2');

    int cnt=(x+y)/n;
    int d=(x+y)%n;

    int p0=0,p1=0,p2=0;
    for(int i=0;i<d;i++)
    {
        p0+=(s[i]=='0');
        p1+=(s[i]=='1');
        p2+=(s[i]=='2');   
    }

    if(!c2)
    {   
        if(cnt*c0+p0==x&&cnt*c1+p1==y) cout<<s<<"\n";
        else cout<<"-1\n";
        return ;
    }
    
    int ans0=0;
    int ans1=0;
    int f=0;
    for(int i=0;i<=c2;i++)
    {
        int c00=i;
        int c11=c2-i;
        int nx=(c0+c00)*cnt;
        int ny=(c1+c11)*cnt;

        int dx=x-nx;
        int dy=y-ny;
        if(dx<0||dy<0) continue;
        
        if(p0>dx||p0+min(p2,c00)<dx) continue;
        if(p1>dy||p1+min(p2,c11)<dy) continue;
        
        f=1;
        if(dx-p0>ans0)
        {
            ans0=dx-p0;
            ans1=i-ans0;
        }
        else if(dx-p0==ans0)
        {
            ans1=max(ans1,i-ans0);
        }
    }

    if(!f) 
    {
        cout<<"-1\n";
        return ;
    }

    for(int i=0;i<d;i++) 
    if(s[i]=='2') 
    {
        if(ans0)
        {
            s[i]='0';
            ans0--;
        }
        else s[i]='1';
    }


    for(int i=d;i<n;i++) 
    if(s[i]=='2') 
    {
        if(ans1)
        {
            s[i]='0';
            ans1--;
        }
        else s[i]='1';
    }
    cout<<s<<"\n";

}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}