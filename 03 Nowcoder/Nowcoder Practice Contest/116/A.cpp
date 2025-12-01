#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a,k,q,l,r;
    cin>>a>>k>>q;
    while(q--)
    {
        cin>>l>>r;
        if(k%2==0)
        {
            if((a+(l-1)*k)%2==0) cout<<-1<<endl;
            else cout<<1<<endl;
        }
        else
        {
            if((r-l+1)%2==0) cout<<0<<endl;
            else if((a+(l-1)*k)%2==0) cout<<-1<<endl;
            else cout<<1<<endl;
        }
    }
}