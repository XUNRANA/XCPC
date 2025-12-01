#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve () 
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        s=s.substr(0,s.size()-4);
        int n=s.size();
        if(n>=2&&s.substr(n-2)=="ri") cout<<s.substr(0,n-2)<<"tte\n";
        else if(n>=3&&s.substr(n-3)=="chi") cout<<s.substr(0,n-3)<<"tte\n";
        else if(n>=2&&(s.substr(n-2)=="mi"||s.substr(n-2)=="bi"||s.substr(n-2)=="ni")) cout<<s.substr(0,n-2)<<"nde\n";
        else if(n>=2&&s.substr(n-2)=="ki")
        {
            if(s=="iki") cout<<"itte\n";
            else cout<<s.substr(0,n-2)<<"ite\n";
        }
        else if(n>=2&&s.substr(n-2)=="gi") cout<<s.substr(0,n-2)<<"ide\n";
        else if(n>=3&&s.substr(n-3)=="shi")cout<<s.substr(0,n-3)<<"shite\n";
    }
}


int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //  cin >> t;
    while (t--)
    solve();
    return 0;
}