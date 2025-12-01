memset(dis,0x3f3f3f3f,sizeof(dis));
for(int k=1;k<=n;k++)//中间点最前面 (floyd) 
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);