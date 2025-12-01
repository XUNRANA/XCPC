#include <iostream>
using namespace std;
int a[200010];
int ans[200010];
void solve()
{
    int n,x,y;
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(x==0)
    {
        int f=0;
        for(int i=1;i<=n;i++) if(!a[i]) f=1;
        
        if(!f)
        {
            for(int i=1;i<n;i++) cout<<"1 ";
            cout<<"\n";
        }
        else cout<<"-1\n";
    }
    else if(x==1)
    {
        if(a[1])
        {
            while(x--) cout<<"0 ";
            while(y--) cout<<"1 ";
            cout<<"\n";
        }
        else if(a[n])
        {
            while(y--) cout<<"1 ";
            while(x--) cout<<"0 ";
            cout<<"\n";
        }
        else cout<<"-1\n";
    }    
    else if(x>=2)
    {
        if(a[1])
        {
            while(x--) cout<<"0 ";
            while(y--) cout<<"1 ";
            cout<<"\n";
        }
        else if(a[n])
        {
            while(y--) cout<<"1 ";
            while(x--) cout<<"0 ";
            cout<<"\n";
        }
        else
        {
            for(int i=2;i<n;i++)
            {
                if(a[i])
                {
                    ans[i-1]=0;
                    ans[i]=0;
                    x-=2;
                    for(int j=1;j<i-1;j++) 
                    if(x) ans[j]=0,x--;
                    else ans[j]=1; 

                    for(int j=i+1;j<n;j++)
                    if(x) ans[j]=0,x--;
                    else ans[j]=1; 

                    for(int i=1;i<n;i++) cout<<ans[i]<<" ";
                    cout<<"\n";
                    return ;
                }
            }
            cout<<"-1\n";
        }
    }
}
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}