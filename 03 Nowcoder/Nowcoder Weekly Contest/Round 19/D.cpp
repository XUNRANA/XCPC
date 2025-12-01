#include <bits/stdc++.h>
using namespace std;
char c[6][6];
int h[6][6];
int cnt1[6][6];//lei
int cnt2[6][6];//not lei
int ok;
int dx[10]={-1,-1,-1,0,0,1,1,1};
int dy[10]={-1,0,1,1,-1,-1,0,1};
void dfs(int x,int y)
{
    if(x==4)
    {
        bool f=true;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(c[i][j]>='0'&&c[i][j]<='9')
                {
                    int rnd=0;
                    int num=c[i][j]-'0';
                    for(int k=0;k<8;k++)
                    {
                        int xx=i+dx[k];
                        int yy=j+dy[k];
                        if(xx<0||yy<0) continue;
                        if(xx>3||yy>3) continue;
                        if(h[xx][yy]) rnd++;
                    }
                    if(num!=rnd) f=false;
                }
            }
        }
        if(f)
        {
            ok++;
            for(int i=0;i<4;i++) for(int j=0;j<4;j++)
            if(h[i][j]) cnt1[i][j]++;
            else cnt2[i][j]++;
        }
        return ;
    }
    
    int ny=y,nx=x;
    
    if(y<3) ny++;
    else nx++,ny=0;
    dfs(nx,ny);//bufang
    
    if(c[x][y]>='0'&&c[x][y]<='9')  return;
    
	h[x][y]++;
	dfs(nx,ny);
	h[x][y]--;
}

void solve()
{
	for(int i=0;i<4;i++) for(int j=0;j<4;j++) cin>>c[i][j];
    dfs(0,0);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(c[i][j]>='0'&&c[i][j]<='9') cout<<c[i][j];
            else if(cnt1[i][j]==ok) cout<<'X';
            else if(cnt2[i][j]==ok) cout<<'O';
            else cout<<'.';
        }
        cout<<endl;
    }
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
