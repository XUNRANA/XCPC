#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(i<k&&s[i]>='a') s[i]-=32;
        if(i>=k&&s[i]<'a') s[i]+=32;
    }
    cout<<s;

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

