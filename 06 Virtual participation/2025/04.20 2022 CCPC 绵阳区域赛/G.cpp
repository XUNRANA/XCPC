#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int n;
void solve() 
{
    cin>>n;
    vector<int>a;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    } 
    int cnt=0;
    while(a.size()>1)
    {
        vector<int>b;
        if(a[0]>a[1]) b.push_back(a[0]);
        
        for(int i=1;i<a.size()-1;i++) if(a[i]>a[i-1]&&a[i]>a[i+1]) b.push_back(a[i]);

        if(a[a.size()-1]>a[a.size()-2]) b.push_back(a[a.size()-1]);
        a=b;
        cnt++;
    }
    cout<<cnt<<"\n";
}

int32_t main() 
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}