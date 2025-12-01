#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    vector<int>num;
    int l=0,r=s.size()-1;
    while(l<r)
    {
        int a=s[l]-'0';
        int b=s[r]-'0';
        num.push_back(a*10+b);
        l++;
        r--;
    }
    
    for(int i=1;i<num.size();i+=2) 
    {
        int a=num[i-1];
        int b=num[i];
        cout<<a<<"+"<<b<<"="<<a+b<<"\n";
    }
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
