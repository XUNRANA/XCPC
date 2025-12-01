#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>ans;
int n;
string s;
bool insert(int x)
{
    char ch;
    if(x==0) ch='T';
    else if(x==1) ch='I';
    else ch='L';
    for(int i=0;i<s.size();i++)
    if(i+1<s.size()&&s[i]!=s[i+1]&&s[i]!=ch&&s[i+1]!=ch)
    {
        ans.push_back(i+1);
        s=s.substr(0,i+1)+ch+s.substr(i+1);
        return 1;
    }
    return 0;
}

void solve()
{
    cin>>n;
    cin>>s;
    vector<int>c(3,0);
    for(auto i:s)
    if(i=='T') c[0]++;
    else if(i=='I') c[1]++;
    else c[2]++;
    int mx=n;
    ans.clear();
    while(1)
    {
        int f=0;
        for(int i=0;i<3;i++)
        if(c[i]!=mx)
        {
            if(insert(i)) 
            {
                c[i]++;
                f=1;
            }
        }
        if(!f) break;
    }

    for(int i=0;i<3;i++) if(c[i]!=mx) 
    {
        cout<<"-1\n";
        return ;
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans) cout<<i<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
