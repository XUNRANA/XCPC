#include <bits/stdc++.h>
using namespace std;
#define int long long
int is(string s)
{
    string ss=s;
    reverse(s.begin(),s.end());
    return ss==s;
}
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<(1<<n);i++)
    {

        vector<int>ans;
        string t="";
        int p=0;
        int f=1;

        for(int j=0;j<n;j++)
        if(i>>j&1) t+=s[j];
        else 
        {
            ans.push_back(j+1);
            int x=s[j]-'0';
            if(x<p) f=0;
            p=x;
        }
        

        if(is(t)&&f)
        {
            cout<<ans.size()<<"\n";
            for(auto i:ans) cout<<i<<" ";
            cout<<"\n";
            return ;
        }
    }
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
