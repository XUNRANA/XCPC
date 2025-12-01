#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int p,m,n;
    cin>>p>>m>>n;
    map<string,int>mp1,mp2,mp3;
    set<string>st;
    for(int i=1;i<=p;i++)
    {
        string s;
        int x;
        cin>>s>>x;
        st.insert(s);
        mp1[s]=x;
    }

    for(int i=1;i<=m;i++)
    {
        string s;
        int x;
        cin>>s>>x;
        mp2[s]=x;
    }

    
    for(int i=1;i<=n;i++)
    {
        string s;
        int x;
        cin>>s>>x;
        mp3[s]=x;
    }

    vector<pair<int,string>>a;
    for(auto s:st)
    {
        if(mp1[s]>=200)
        {
            if(mp2.count(s))
            {
                int g=0;
                if(mp2[s]>mp3[s]) g=(2*mp2[s]+3*mp3[s]+2)/5;
                else g=mp3[s];
                if(g>=60)
                a.push_back({-g,s});
            }
            else
            {
                int g=mp3[s];
                if(g>=60)
                a.push_back({-g,s});
            }
        }
    }
    sort(a.begin(),a.end());
    for(auto i:a) 
    {
        int x=mp1[i.second];
        int y=-1,z=-1;
        
        if(mp2.count(i.second)) y=mp2[i.second];
        
        if(mp3.count(i.second)) z=mp3[i.second];


        // cout<<mp[i.second]<<" "<<
        cout<<i.second<<" "<<x<<" "<<y<<" "<<z<<" "<<-i.first<<"\n";
    }
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
