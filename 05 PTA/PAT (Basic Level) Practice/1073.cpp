#include <bits/stdc++.h>
using namespace std;
#define int long long

int sc[110];
int cc[110];
int z[110][5];
int l[110];
int cnt[1010][110][5];
//a b c d e
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>sc[i];
        sc[i]*=2;
        int k;
        cin>>k;
        l[i]=k;
        cin>>k;
        cc[i]=k;
        while(k--)
        {
            char ch;
            cin>>ch;
            z[i][ch-'a']=1;
        }
    }
    cin.ignore();
    for(int j=1;j<=n;j++)
    {
        string s;
        getline(cin,s);
        int c=0;
        for(auto i:s)
        {
            if(i=='(') 
            {
                c++;
            }
            else if(islower(i))
            {
                cnt[j][c][i-'a']=1;
            }
        }
    }

    // for(int j=1;j<=m;j++,cout<<"\n")
    // for(int k=0;k<5;k++) cout<<z[j][k]<<" ";
    // cout<<"\n";

    map<array<int,2>,int>mp;
    for(int i=1;i<=n;i++) 
    {
        int res=0;
        for(int j=1;j<=m;j++)
        {
            int c=0;
            int f=0;
            for(int k=0;k<l[j];k++) 
            {
                if(cnt[i][j][k]==z[j][k])
                {
                    if(cnt[i][j][k]) c++;
                }
                else
                {
                    // if(cnt[i][j][k]) 
                    mp[{j,k}]++;
                    f|=cnt[i][j][k];
                }
            }

            if(!f&&c)
            {
                // cout<<c<<" "<<j<<" "<<cc[j]<<"???\n";
                if(c==cc[j]) res+=sc[j];
                else res+=sc[j]/2;
            }
        }
        // cout<<i<<" "<<res<<"?\n";
        cout<<res/2;
        if(res&1) cout<<".5\n";
        else cout<<".0\n"; 
    }
    vector<array<int,3>>ans;
    int mx=0;
    for(auto i:mp) mx=max(mx,i.second);
    
    for(auto i:mp) 
    {
        if(i.second==mx)
        ans.push_back({i.second,i.first[0],i.first[1]});
    }
    sort(ans.begin(),ans.end());
    
    if(ans.size()) for(auto i:ans) cout<<i[0]<<" "<<i[1]<<"-"<<char('a'+i[2])<<"\n";
    else cout<<"Too simple\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
