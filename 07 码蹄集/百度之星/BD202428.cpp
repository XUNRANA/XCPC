#include <bits/stdc++.h>
using namespace std;


int n,q;
int b[400010];
int f[400010][20];
int last_pos[26]; 

string s;
void solve()
{
    cin>>n>>q>>s;
    s=s+s;
    s=" "+s;
    for(int i=1;i<=n;i++) cin>>b[i],b[i+n]=b[i];
    n*=2;


    for(int i = 0; i < 26; i++) last_pos[i] = n + 1; 
    for(int i = n; i >= 1; i--) 
    {
        int char_idx = s[i] - 'A';
        f[i][0] = last_pos[char_idx] + 1;    
        last_pos[char_idx] = i;
    }
    f[n+1][0] = n + 2;
    f[n+2][0] = n + 2;

    for(int i=1;i<=19;i++)
    for(int j=1;j<=n+2;j++)
    f[j][i]=f[f[j][i-1]][i-1];

    while(q--)
    {
        int op,x,y,l,r;
        cin>>op;
        if(op==1) 
        {
            cin>>x>>y;
            b[x]=b[x+n/2]=y;
        }
        else
        {
            cin>>l>>r;
            if(l>r) r+=n/2;
            int ans=0;
            while(l<=r)
            {
                for(int i=19;i>=0;i--)
                {
                    if(f[l][i]<=r+1) 
                    {
                        l=f[l][i];
                    }
                }
                if(l<=r) 
                {
                    ans+=b[l];
                    l++;
                }
            }
            cout<<ans<<"\n";
        }
    }
} 

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
