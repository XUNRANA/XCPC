#include <bits/stdc++.h>
using namespace std;
#define int long long
int p[200010][26];
bool ck(int l,int r,int l1,int r1)
{
    vector<int>a(26,0);
    vector<int>b(26,0);
    for(int i=0;i<26;i++) a[i]=p[r][i]-p[l-1][i];
    for(int i=0;i<26;i++) b[i]=p[r1][i]-p[l1-1][i];
    for(int i=0;i<26;i++) if(a[i]!=b[i]) return 0;
    return 1;
}
bool ck1(int l,int r,int l1,int r1)
{
    vector<int>a(26,0);
    vector<int>b(26,0);
    for(int i=0;i<26;i++) a[i]=p[r][i]-p[l-1][i];
    for(int i=0;i<26;i++) b[i]=p[r1][i]-p[l1-1][i];
    for(int i=0;i<26;i++) if(a[i]<b[i]/2) return 0;
    return 1;
}
void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    s=" "+s;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<26;j++) p[i][j]=p[i-1][j];
        p[i][s[i]-'a']++;
    }

    int i=1,j=n;
    while(i<j&&s[i]==s[j])
    {
        i++;
        j--;
    }
    
    if(i>j) cout<<"0\n";
    else if(ck(i,n/2,n/2+1,j))
    {
        int i1=n/2,j1=n/2+1;
        while(s[i1]==s[j1])
        {
            i1--;
            j1++;
        }
        cout<<i1-i+1<<"\n";
    }
    else
    {
        int l1=n/2-i+1;
        while(!ck1(i,i+l1-1,i,j)) l1++;

        int l2=n/2-i+1;
        while(!ck1(j-l2+1,j,i,j)) l2++;
        cout<<min(l1,l2)<<"\n";
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

