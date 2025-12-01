#include <bits/stdc++.h>
using namespace std;
#define int long long


//0---- 0-1
//1---- 1-2
int x1,x2,y11,y2,a[100010];
void solve() 
{
    int n;
    cin>>n;
    while(n--)
    {
        cin>>x1>>y11>>x2>>y2;
        a[x1]++;
        a[x2]--;
    }
    int cnt=0;
    for(int i=1;i<=100000;i++) 
    {
        a[i]+=a[i-1];
        if(a[i]) cnt++;
    }
    cout<<cnt<<"\n";
}

signed  main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
