//ST表，快速查询区间最大值/最小值 
int f[100010][22]; 
for(int i=1;i<=n;i++) cin>>f[i][0];//初始化区间[i,i]的最大值 
for(int i=1;i<=21;i++) 
for(int j=1;j+(1<<i)-1<=n;j++)
f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);//动态规划更新 

while(m--)
{
	cin>>l>>r;
	k=log2(r-l+1);//求区间长度 
	cout<<max(f[l][k],f[r-(1<<k)+1][k])<<"\n";//输出区间最大值 
}