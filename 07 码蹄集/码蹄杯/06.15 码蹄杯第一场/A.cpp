#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string a,b;
    cin>>a>>b;
    int n=a.size();
    int i=0,j=n-1;
    while(i<n&&a[i]==b[i]) i++;

    if(i==n) cout<<"Y\n";
    else
    {
        while(j>0&&a[j]==b[j]) j--; 
        string a1=a.substr(i,j-i+1);
        string b1=b.substr(i,j-i+1);
        // cout<<a1<<" "<<b1<<"\n";
        reverse(a1.begin(),a1.end());

        if(a1==b1) cout<<"Y\n";
        else cout<<"N\n";
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