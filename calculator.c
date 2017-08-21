/*
 * file name:calculator.c
 * version imformation:v1
 * Author:KrisYWL
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BASE (10)
#define MAX(x,y) ((x)>(y)?(x):(y))

/****Big number calculator****/
typedef struct bignumber_s{
	char sign;	//sign of the number
	int len;	//len of the number
	char data[];	//every number
}bignumber_s;

/****templet of big number calculator creation****/
bignumber_s *make_bignumber_temp(int len,int sign)
{
	bignumber_s *temp =malloc(sizeof(bignumber_s)+len);
	if(temp==NULL){
		perror("Malloc");
		exit(-1);
	}	
	temp->sign = sign;
	temp->len = len;
	memset(temp->data,0,len);
	return temp;
}

const char *strip_str(const char *str)
{
	int i=0;
	int len=strlen(str);
	for(i=0;i<len-1&&str[i]=='0';i++);
	return str+i;
}

void fill_data_fromstr(bignumber_s *n,const char *str)
{
	int i=0;
	int len=n->len;
	for(i=0;i<len;i++){
		int d=str[len-1-i]-'0';
		if(d>=0&&d<=9)
			n->data[i]=d;
		else{
			fprintf(stderr,"Invalid Number:%d\n",str);
			exit(-1);
		}
	}
}

bignumber_s *make_bignumber_fromstr(const char *str)
{
	int sign = 0;
	if(str[0]=='-'){
		sign = 1;
		str++;
	}
	const char *striped_str=strip_str(str);
	int len = strlen(striped_str);
	bignumber_s *temp = make_bignumber_temp(len,sign);
	fill_data_fromstr(temp,striped_str);
	return temp;
	
}

void print_bignumber(bignumber_s *b)
{
	int len =b->len;
	char *str=malloc(len+1);
	int i=0;

	for(i=0;i<len;i++){
		str[i]=b->data[len-i-1]+'0';
	}
	str[len]='\0';

	fprintf(stdout,"%s%s\n",b->sign==1?"-":"",strip_str(str));
	free(str);

}

void usage(const char *s)
{
	fprintf(stderr,"Usage:%s number1 +-*/ number2.\n",s);
	exit(-1);
}

void add_impl(bignumber_s *a,bignumber_s *b,bignumber_s*r)
{
	int i = 0;
	char carry = 0;
	int len = r->len;
	for(i=0;i<len;i++){
		if(i<a->len)carry+=a->data[i];
		if(i<b->len)carry+=b->data[i];
		r->data[i]=carry%BASE;
		carry/=BASE;
	}
}
bignumber_s *calc_add(bignumber_s *a,bignumber_s *b)
{
	int len = MAX(a->len,b->len)+1;
	bignumber_s *result = make_bignumber_temp(len,0);
	add_impl(a,b,result);
	return result;
}
void sub_impl(bignumber_s *a,bignumber_s *b,bignumber_s *r)
{
	int i=0;
	int borrow=0;
	int len=r->len;
	int temp=0;
	for(i=0;i<len;i++){
		temp=a->data[i]+BASE-borrow-((i<b->len)?b->data[i]:0);
		r->data[i]=temp%BASE;
		borrow=temp/BASE?0:1;	
	}
}
bignumber_s *calc_sub(bignumber_s *a,bignumber_s *b)
{
	int len = a->len;
	bignumber_s *result=make_bignumber_temp(len,0);
	sub_impl(a,b,result);
	return result;
}
bignumber_s *calc_mul(bignumber_s *a,bignumber_s *b)
{
	return NULL;	
}
bignumber_s *calc_div(bignumber_s *a,bignumber_s *b)
{
	return NULL;
}





int main(int argc,char *argv[])
{
	bignumber_s *a = make_bignumber_fromstr(argv[1]);
	bignumber_s *b = make_bignumber_fromstr(argv[3]);
	if(argc!=4) usage(argv[0]);
	if(strcmp(argv[2],"+")==0)
		print_bignumber(calc_add(a,b));
	else if(strcmp(argv[2],"-")==0)
		print_bignumber(calc_sub(a,b));
	else if(strcmp(argv[2],"*")==0)
		print_bignumber(calc_mul(a,b));
	else if(strcmp(argv[2],"/")==0)
		print_bignumber(calc_div(a,b));
	else usage(argv[0]);
	return 0;
}	








