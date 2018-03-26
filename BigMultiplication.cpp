#include<stdio.h>
#include<string.h>
int main(){
	int a[200],b[200],sum[400],a_len,b_len,max_len,i,tmp;
	char a_nums[200],b_nums[200];
	bool StartOutpt=false;
	scanf("%s%s",&a_nums,&b_nums);
	a_len=strlen(a_nums);
	b_len=strlen(b_nums);
	tmp=0;
	for(i=a_len-1;i>=0;i--){
		a_nums[i]-='0';
		a[tmp]=a_nums[i];
		tmp++;
	}
	tmp=0;
	for(i=b_len-1;i>=0;i--){
		b_nums[i]-='0';
		b[tmp]=b_nums[i];
		tmp++;
	}
	if(a_len==b_len){
		a[a_len]=0;
		b[b_len]=0;
	}
	if(a_len>b_len){
		for(i=b_len;i<=a_len-1;i++)
			b[i]=0;
	}
	if(a_len<b_len){
		for(i=a_len;i<=b_len-1;i++)
			a[i]=0;
	}
	max_len=(a_len>=b_len)?a_len:b_len;
	for(i=0;i<max_len*2;i++){
		sum[i]=0;
	}
	for(i=0;i<max_len;i++){
		for(int j=0;j<max_len;j++){
			sum[i+j]+=a[i]*b[j];
		}
	}
	for(i=0;i<max_len*2;i++){
		if(sum[i]>=10){
			sum[i+1]+=sum[i]/10;
			sum[i]=sum[i]%10;
		}
	}

	for(i=max_len*2-1;i>=0;i--){
		if(sum[i]!=0)
			StartOutpt=true;
		if(StartOutpt)
			printf("%d",sum[i]);
	}
	return 0;
}