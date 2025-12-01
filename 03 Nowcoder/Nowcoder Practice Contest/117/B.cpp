#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,l,r,k;
    cin>>t;
    while(t--)
    {
        cin>>l>>r>>k;
        if(!k) cout<<((r-l+1)&1)<<endl;
        else 
        {
            int num=r-l+1,cnt;
            if((l&1)&&(num&1)) cnt=num/2+1;
            else cnt=num/2;
            cout<<cnt%2<<endl;
        }
    }
}