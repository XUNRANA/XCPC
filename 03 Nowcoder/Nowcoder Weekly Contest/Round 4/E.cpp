#include <bits/stdc++.h>
using namespace std;
string a[510][510];
bool cmp(string a,string b)
{
    for(int i=0;i<min(a.size(),b.size());i++)
    {
        if(a[i]!=b[i])
        {
            if(a[i]>b[i]) return 1;
            else return 0;
        }
    }
    
    if(a.size()>b.size()) return 1;
    else return 0;
}
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]="";
    map<string,pair<int,int>>mp;
    map<string,set<pair<int,int>> >pos;
    for(int i=1;i<=k;i++)
    {
        int x,y;
        string s;
        cin>>s>>x>>y;

        if(a[x][y]!="")
        {
            if(cmp(s,a[x][y]))
            {
                pos[a[x][y]].erase({x,y});
                
                pos[s].insert({x,y});
                mp[s]={x,y};
                a[x][y]=s;
            }
        }
        else
        {         
            pos[s].insert({x,y});
            mp[s]={x,y};
            a[x][y]=s;
        }
    }
    
    int q;
    cin>>q;
    while(q--)
    {
        string s,ans;
        char ch;
        cin>>s>>ch;
        
        if(!pos.count(s)||pos[s].empty())
        {
            cout<<"unexisted empire.\n";
            continue;
        }
        
        int nx=mp[s].first;
        int ny=mp[s].second;
        if(ch=='A') ny--;
        else if(ch=='D') ny++;
        else if(ch=='W') nx--;
        else if(ch=='S') nx++;
        
        if(nx<1||nx>n||ny<1||ny>m) ans="out of bounds!";
        else 
        {
            
            if(a[nx][ny]=="")
            {
                ans="vanquish!";
                pos[s].insert({nx,ny});
                a[nx][ny]=s;
                mp[s]={nx,ny};
            }
            else if(a[nx][ny]==s) 
            {
                ans="peaceful.";
                mp[s]={nx,ny};
            }
            else 
            {
                if(pos[s].size()>pos[a[nx][ny]].size()||(pos[s].size()==pos[a[nx][ny]].size()&&cmp(s,a[nx][ny])))
                {
                    ans=s+" wins!";
                    string t=a[nx][ny];
                    for(auto i:pos[a[nx][ny]])
                    {
                        a[i.first][i.second]=s;
                        pos[s].insert(i);
                    }
                    
                    pos[t].clear();
                    
                    mp[s]={nx,ny};
                }
                else 
                {
                    ans=a[nx][ny]+" wins!";
                    string t=s;
                    for(auto i:pos[s])
                    {
                        a[i.first][i.second]=a[nx][ny];
                        pos[a[nx][ny]].insert(i);
                    }
                    pos[t].clear();
                }
            }
        }
        cout<<ans<<"\n";
    }

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	while(T--) solve();
}
