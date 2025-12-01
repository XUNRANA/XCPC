int lowbit(int x)
{
	return x&-x;
}
void update(int i,int x)
{
	while(i<=n)
	{
		tr[i]+=x;
		i+=lowbit(i);
	}
}
int query(int i)
{
	int res=0;
	while(i)
	{
		res+=tr[i];
		i-=lowbit(i);
	}
	return res;
}


void update(int x,int y,int k,int cr)//二维点（x，y）加k，所属类别为cr 
{
	for(int i=x;i<=n;i+=lowbit(i))
	for(int j=y;j<=m;j+=lowbit(j))
	t[i][j][cr]+=k;
}
/*
cin>>x1>>x2>>y11>>y2>>c;
cout<<sum(x2,y2,c)-sum(x1-1,y2,c)-sum(x2,y11-1,c)+sum(x1-1,y11-1,c)<<"\n";
*/ 
int sum(int x,int y,int cr)//求区间和 
{
	int res=0;
	for(int i=x;i;i-=lowbit(i))
	for(int j=y;j;j-=lowbit(j))
	res+=t[i][j][cr];
	return res;
}