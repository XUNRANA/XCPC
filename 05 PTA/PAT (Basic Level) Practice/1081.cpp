#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s;
    getline(cin,s);
    // cin>>s;
    int f=0;
    int f1=0;
    for(auto i:s) 
    if(islower(i)||isupper(i)) f|=1;
    else if(isdigit(i)) f|=2;
    else if(i!='.') f1=1;
    
    if(s.size()<6) cout<<"Your password is tai duan le.\n";
    else 
    {
        if(f1) cout<<"Your password is tai luan le.\n";
        else if(f==1) cout<<"Your password needs shu zi.\n";
        else if(f==2) cout<<"Your password needs zi mu.\n";
        else cout<<"Your password is wan mei.\n";
    }
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
    cin.ignore();
	while(T--) solve(); 
}
