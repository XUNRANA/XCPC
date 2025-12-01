#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j;
    int q,n,k;
    cin>>q;
    while(q--)
    {
        cin>>n>>k;
        int t=k-(n+1);
        if(t&1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(t<0||t/4+(t%4!=0)>(n-1)/4)
        {
            cout<<-1<<endl;
            continue;
        }
        int ans=(t)/4*4;
        if((t)%4!=0) ans+=3;
        cout<<ans<<endl;
    }  
}