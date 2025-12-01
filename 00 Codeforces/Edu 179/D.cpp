#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
    int i;
    int val;
}a[100010];
bool cmp(node a1,node a2)
{
    return a1.val<a2.val;
}
int b[100010];
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        b[i]=x;
        a[i].i=i;
        a[i].val=x/100;
    } 
    sort(a+1,a+1+m,cmp);
    
    int j=1;
    for(int i=1;i<=n;i++)
    {
        if(i&1) for(int k=1;k<=3;k++) cout<<b[a[j].i]<<" "<<b[a[m+1-j].i]<<" ";
        else for(int k=1;k<=3;k++) cout<<b[a[m+1-j].i]<<" "<<b[a[j].i]<<" ";
        if(i%2==0) j++;
        cout<<"\n";
    }
   
    // 4 3 2 2 3 3 2 4 2 3 

    // 4 3 2 2 3 3 2 4 2 3 


    // 2 2 2 2 3 3 3 3 4 4
    
    // 36   10


}
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}