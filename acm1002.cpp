#include<iostream>
#include<string>
using namespace std;
int main(){
	char a[1000],b[1000];
	int a_int[1001],b_int[1001];
	int t,a_len,b_len,max_len,j=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a>>b;
		a_len=strlen(a);
		b_len=strlen(b);
		int tmp=0;
		for(int j=a_len-1;j>=0;j--){
			a_int[tmp++]=a[j]-'0';
		}
		tmp=0;
		for(j=b_len-1;j>=0;j--){
			b_int[tmp++]=b[j]-'0';
		}
		if(a_len=b_len){
			a_int[a_len]=0;
			b_int[b_len]=0;
		}
		if(a_len>b_len){
			for(j=b_len;j<=a_len;j++){
				b_int[j]=0;
			}
			a_int[a_len]=0;
		}
		if(a_len<b_len){
			for(j=a_len;j<=b_len;j++){
				a_int[j]=0;
			}
			b_int[b_len]=0;
		}
		max_len=(a_len>=b_len)?a_len:b_len;
		for(j=0;j<=max_len;j++){
			a_int[j]+=b_int[j];
			if(a_int[j]>=10){
				a_int[j]-=10;
				a_int[j+1]+=1;
			}
		}
		
		cout<<"Case "<<i<<":"<<endl;
		cout<<a<<" "<<"+"<<" "<<b<<" "<<"="<<" ";
		if(a_int[max_len]==0){
           for(j=max_len-1;j>=0;j--)
               cout<<a_int[j];
        }else{
           for(j=max_len;j>=0;j--)
               cout<<a_int[j];
        }

        if(i!=t)
            cout<<endl<<endl;
        else
            cout<<endl;
	}
	return 0;
}