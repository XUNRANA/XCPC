#include<bits/stdc++.h>
using namespace std;
int a[510][510],v[510][510],ans,n,m;
queue<int>q;
int T;
int main()
{   
    cin >> T;
    while(T--) {
        memset(a, 0, sizeof(a));
        memset(v, 0, sizeof(v));
        cin>>n>>m;
        ans=n*m;
        for(int i=1;i<=n;++i){
            int r,t;
            scanf("%d",&r);
            for(int j=1;j<=r;++j){
                scanf("%d",&t);
                a[i][t]=1;
            }
        }
        for(int i=1;i<=n;++i){
            if(!a[i][1]){
                q.push(i),q.push(1);
                v[i][1]=1;
            }
        }
        int x,y,t=0,s;
        while(!q.empty()){
            t++;
            s=q.size()/2;
            for(int j=1;j<=s;++j){
                x=q.front();
                q.pop();
                y=q.front();
                q.pop();
                if(y==m){
                    ans=min(ans,t);
                    while(!q.empty())q.pop();
                    break;
                }
                if(y+m-y>=ans||ans==m)break;
                if(!v[x][y+1]&&!a[x][y+1]){
                    v[x][y+1]=1;
                    q.push(x);
                    q.push(y+1);
                }
                if(x<n&&!v[x+1][y]&&!a[x+1][y]){
                    v[x+1][y]=1;
                    q.push(x+1);
                    q.push(y);
                }
                if(x>1&&!v[x-1][y]&&!a[x-1][y]){
                    v[x-1][y]=1;
                    q.push(x-1);
                    q.push(y);
                }
                if(y>1&&!v[x][y-1]&&!a[x][y-1]){
                    v[x][y-1]=1;
                    q.push(x);
                    q.push(y-1);
                }
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}