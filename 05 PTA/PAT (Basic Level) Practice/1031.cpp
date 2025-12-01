#include <bits/stdc++.h>
using namespace std;
#define int long long

int val[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char is[]={'1','0','X','9','8','7','6','5','4','3','2'};
void solve()
{
    int n;
    cin>>n;
    vector<string>res;
    while(n--)
    {
        string s;
        cin>>s;
        int ans=0;
        int f=0;
        for(int i=0;i<17;i++)
        if(isdigit(s[i])) ans+=val[i]*(s[i]-'0');
        else f=1;
        if(f||is[ans%11]!=s[17]) res.push_back(s); 
    }
    if(res.size()) for(auto i:res) cout<<i<<"\n";
    else cout<<"All passed\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

