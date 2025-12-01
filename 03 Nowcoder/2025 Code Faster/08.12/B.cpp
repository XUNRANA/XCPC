#include <iostream>
using namespace std;

int f[5000010];
int is[5000010];


void init()
{
    for(int i=2;i<=5e6;i++)
    {
        if(!f[i])
        {
            for(int j=i;j<=5e6;j+=i) f[j]=1;
            
            long long x=1ll*i*i;
            for(long long j=x;j<=5e6;j+=x) is[j]=1;
        }
    }

    for(int i=2;i<=5e6;i++) is[i]+=is[i-1];
}

void solve()
{
    int x;
    cin>>x;
    cout<<(x-1)-is[x]<<"\n";
}
int main() 
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}