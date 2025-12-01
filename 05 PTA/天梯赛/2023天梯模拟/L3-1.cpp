
#include<bits/stdc++.h>
using namespace std;
#define maxn 610938
#define inf 1290311
int n,m,t;
struct no
{
    int x,y,nowtime,shu;
};
map<pair<int,int> ,pair<int,int>>mp;
int mapp[200][200];
queue<no>Q;
int dx[6]={1,-1,0,0};
int pre1[200];
int pre2[200];
int dy[6]={0,0,1,-1};
int mark[200][200];
int tx,ty;
int dis[200][200][2];
void bfs()
{
    dis[tx][ty][0]=0;
    dis[tx][ty][1]=0;
    memset(mark,0,sizeof(mark));
    queue<pair<int,int> >K;
    K.push(make_pair(tx,ty));
    while(K.size())
    {
        pair<int ,int> p1=K.front();
        K.pop();
        int x=p1.first;
        int y=p1.second;
        mark[x][y]=0;
        for(int i=0;i<4;i++)
        {
            if(x+dx[i]>=2&&y+dy[i]>=2&&x+dx[i]<=n+1&&y+dy[i]<=m+1)
            {
                
                if(x+dx[i]==tx&&y+dy[i]==ty)continue;
                if(dis[x+dx[i]][y+dy[i]][0]>dis[x][y][0]+1+mapp[x+dx[i]][y+dy[i]])
                {
                    dis[x+dx[i]][y+dy[i]][0]=dis[x][y][0]+1+mapp[x+dx[i]][y+dy[i]];
                    if(!mark[x+dx[i]][y+dy[i]])
                    {
                        mark[x+dx[i]][y+dy[i]]=1;
                        K.push(make_pair(x+dx[i],y+dy[i]));
                    }
                }
            }
        }
    }
    memset(mark,0,sizeof(mark));
    K.push(make_pair(tx,ty));
    while(K.size())
    {
        pair<int ,int> p1=K.front();
        K.pop();
        int x=p1.first;
        int y=p1.second;
        mark[x][y]=0;
        for(int i=0;i<4;i++)
        {
            if(x+dx[i]>=2&&y+dy[i]>=2&&x+dx[i]<=n+1&&y+dy[i]<=m+1)
            {
                if(x+dx[i]==tx&&y+dy[i]==ty)continue;
                if(dis[x+dx[i]][y+dy[i]][1]>dis[x][y][1]+mapp[x+dx[i]][y+dy[i]])
                {
                    dis[x+dx[i]][y+dy[i]][1]=dis[x][y][1]+mapp[x+dx[i]][y+dy[i]];
                    
                    mp[make_pair(x+dx[i],y+dy[i])]=make_pair(x,y);
                
                    if(!mark[x+dx[i]][y+dy[i]])
                    {
                        mark[x+dx[i]][y+dy[i]]=1;
                        K.push(make_pair(x+dx[i],y+dy[i]));
                    }
                }
                else
                {
                    if(dis[x+dx[i]][y+dy[i]][1]==dis[x][y][1]+mapp[x+dx[i]][y+dy[i]])
                    {
                        if(dis[x+dx[i]][y+dy[i]][0]<=dis[x][y][0]+1+mapp[x+dx[i]][y+dy[i]])continue;
                        
                        mp[make_pair(x+dx[i],y+dy[i])]=make_pair(x,y);
                        if(!mark[x+dx[i]][y+dy[i]])
                        {
                            mark[x+dx[i]][y+dy[i]]=1;
                            K.push(make_pair(x+dx[i],y+dy[i]));
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    cin>>n>>m>>t;
    for(int i=1;i<=n+2;i++)
    for(int j=1;j<=m+2;j++)
    {
        {
            dis[i][j][0]=inf;
            dis[i][j][1]=inf;
        }
    
        cin>>mapp[i][j];
        if(i==1||i==n+2||j==1||j==m+2)
        {
            if(!mapp[i][j]) continue;
            if(i==1&&(j==1||j==m+2))continue;
            if(i==n+2&&(j==1||j==m+2))continue;
                for(int k=0;k<4;k++)
            {
                if(i+dx[k]>=2&&j+dy[k]>=2&&i+dx[k]<=n+1&&j+dy[k]<=m+1)
                {
                    Q.push(no{i+dx[k],j+dy[k],0,mapp[i][j]});
                }
            }
        }
        if(mapp[i][j]<0)
        {
            tx=i;
            ty=j;
        }
    }
    int fla=0;
    bfs();
    while(Q.size())
    {
        no tmp=Q.front();
        Q.pop();
        int x=tmp.x;
        int y=tmp.y;
        int pret=1+mapp[x][y];
        int num=tmp.shu;
        if(num>mapp[x][y])
        {
            num-=mapp[x][y];
            mapp[x][y]=0;
        }
        else
        {
            mapp[x][y]-=num;
            continue;
        }
    
        while(!(x==tx&&y==ty))
        {
            pair<int,int>R;
            R=mp[make_pair(x,y)];
            x=R.first;
            y=R.second;
            
             if(mapp[x][y])
            {
                if(x==tx&&y==ty)continue;
                pret=pret+1+mapp[x][y];
                if(num>mapp[x][y])
                {
                    num-=mapp[x][y];
                    mapp[x][y]=0;
                }
                else
                {
                    mapp[x][y]-=num;
                    break;
                }
            }
            else
            {
                if(x==tx&&y==ty)continue;
                pret++;
            }
        }
        if(x==tx&&y==ty)
        {
            int w=max(0,min(t-pret,num));
            mapp[tx][ty]+=w;
            mapp[tx][ty]=min(mapp[tx][ty],0);
            if(mapp[tx][ty]==0)
            {
                fla=1;
            }
        }
    }
    for(int i=2;i<=n+1;i++)
    for(int j=2;j<=m+1;j++)
    {
        if(j==2)
        cout<<mapp[i][j];
        else
        {
            cout<<" "<<mapp[i][j];
            if(j==m+1&&i!=n+1)
            cout<<endl;
        }
    }
    if(fla==1)
    {
        cout<<endl;
        cout<<"Game Over";
    }
}
