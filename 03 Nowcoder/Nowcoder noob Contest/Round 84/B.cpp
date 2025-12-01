#include <bits/stdc++.h>
using namespace std;
int is(int a)
{
    if(a<2) return 0;
    for(int i=2;i*i<=a;i++) if(a%i==0) return 0;
    return 1;
}
int main()
{
    int t,g,l;
    cin>>t;
    while(t--)
    {
        cin>>g>>l;
        if(l%g!=0) cout<<-1<<"\n";
        else cout<<g<<" "<<l<<"\n";
    }
}