#include <bits/stdc++.h>
using namespace std;
#define int long long

int c[3][2];
void solve()
{
    int n;
    cin>>n;
    map<char,char>mp,ca,cb;
    mp['C']='J';
    mp['J']='B';
    mp['B']='C';
    int cnt=0;
    while(n--)
    {
        char a,b;
        cin>>a>>b;
        if(mp[a]==b) 
        {
            if(a=='B') c[0][0]++;
            else if(a=='C') c[1][0]++;
            else c[2][0]++;
        }
        else if(mp[b]==a) 
        {
            if(b=='B') c[0][1]++;
            else if(b=='C') c[1][1]++;
            else c[2][1]++;
        }
        else cnt++;
    }
    cout<<c[0][0]+c[1][0]+c[2][0]<<" "<<cnt<<" "<<c[0][1]+c[1][1]+c[2][1]<<"\n";
    cout<<c[0][1]+c[1][1]+c[2][1]<<" "<<cnt<<" "<<c[0][0]+c[1][0]+c[2][0]<<"\n";
    int mx1=max({c[0][0],c[1][0],c[2][0]});
    int mx2=max({c[0][1],c[1][1],c[2][1]});
    if(c[0][0]==mx1) cout<<"B";
    else if(c[1][0]==mx1) cout<<"C";
    else if(c[2][0]==mx1) cout<<"J";
    if(c[0][1]==mx2) cout<<" B";
    else if(c[1][1]==mx2) cout<<" C";
    else if(c[2][1]==mx2) cout<<" J";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

