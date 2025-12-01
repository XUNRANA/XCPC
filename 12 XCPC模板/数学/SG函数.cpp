for(int i=1;i<=n;i++) 
{
	cin>>a[i];
	ans^=a[i];
}

if(!ans) cout<<"lose\n";//sg函数为0，必败态 
else
{
	for(int i=1;i<=n;i++) 
	if(a[i]>(a[i]^ans))//找到一个必败态，转移给对手 
	{
		cout<<a[i]-(a[i]^ans)<<" "<<i<<"\n";
		a[i]^=ans;
		break;
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
}