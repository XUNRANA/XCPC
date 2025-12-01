#include <bits/stdc++.h>
using namespace std;
long long n,q,l,r,x,a[200010];
string s;
int main()
{
    cin>>n>>q>>s;
    s=" "+s;
    while(q--)
    {
        cin>>l>>r>>x;
        a[l]+=x;
        a[r+1]-=x;
    }
    for(int i=1;i<=n;i++)
    {
        a[i]+=a[i-1];
        cout<<char((a[i]+s[i]-'a')%26+'a');
        //cout<<char((s[i]-'0'+a[i])%26+'a');
    }
}
