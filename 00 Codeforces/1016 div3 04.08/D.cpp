#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1030][1030];
int cnt;
void dfs(int x,int y,int l)
{
    if(l)
    {  
        dfs(x,y,l-1);
        dfs(x+(1<<l),y+(1<<l),l-1);
        dfs(x+(1<<l),y,l-1);
        dfs(x,y+(1<<l),l-1);
        
    }
    else
    {
        a[x][y]=++cnt;
        a[x+1][y+1]=++cnt;
        a[x+1][y]=++cnt;
        a[x][y+1]=++cnt;
    }
}

void solve()
{
    int n,q,x,y,d;
    string s;
    cin>>n>>q;
    vector<int>a;
    for(int i=n-1;i>=0;i--) a.push_back(1<<i);
    while(q--)
    {
        string s;
        cin>>s;
        if(s=="->")
        {
            cin>>x>>y;
            int ans=0;
            for(auto l:a)
            {
                if(x>l&&y>l)
                {
                    ans+=l*l;
                }
                else if(x>l)
                {
                    ans+=2*l*l;
                }
                else if(y>l)
                {
                    ans+=3*l*l;
                }
                if(x>l) x-=l;
                if(y>l) y-=l;
            }

            cout<<ans+1<<"\n";
        }
        else
        {
            cin>>d;
            d--;
            x=1,y=1;
            for(auto l:a)
            {
                if(d>=3*l*l)
                {
                    y+=l;
                    d-=3*l*l;
                }
                else if(d>=2*l*l)
                {
                    x+=l;
                    d-=2*l*l;
                }
                else if(d>=l*l)
                {
                    x+=l;
                    y+=l;
                    d-=l*l;
                }
            }
            cout<<x<<" "<<y<<"\n";
        }
    }
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

