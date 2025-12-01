#include <iostream>
#include <vector>
using namespace std;
void print(vector<int>&v)
{
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}
void emptysize()
{
	vector<int>v1;
	for(int i=0;i<10;i++) v1.push_back(i+1);
	print(v1);
	
	if(v1.empty()) cout<<"empty"<<endl;  //为真 
	else 
	{
		cout<<"not empty"<<endl;
		cout<<"capacit: "<<v1.capacity()<<endl;  //16
		cout<<"size: "<<v1.size()<<endl;         //10 容量>大小 
	}
	v1.resize(15,100); //填充后五个为100 若只有一个参数 则填充0 
	print(v1);
	v1.resize(5);
	print(v1);         //缩小大小 直接截断 
}
int main()
{
	emptysize();
}
