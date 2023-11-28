//infix to prefix 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int precedence(char ch){
	if(ch=='+'|| ch=='-')
		return 1;
	if(ch=='*'|| ch=='/')
		return 2;
	else
		return 0;
}
int operatorr(char ch){
	return (ch=='+'|| ch=='-' || ch=='/' || ch=='*');
}
char *infixtopre(const char *infix){
	int length=strlen(infix);
	char *prefix = (char *)malloc((length+1)*sizeof(char));
	int st[100];
	int top=-1;
	int k=0;
	//reverse string;
	for(int i=length-1;i>=0;i--){
		char current = infix[i];
		if(current>='0' && current <='9'){
			prefix[k++]=current;
		}
		//push
		else if(current==')'){
			st[++top]=current;
		}
		else if(current=='('){
			while(top!=-1 && st[top]!=')'){
				prefix[k++]=st[top--];
			}
			st[top--];
		}
		else{
			while(top>=0 && precedence(st[top])>=precedence(current)){
				prefix[k++]=st[top--];
			}
			st[++top]=current;
		}
		
	}
	while(top>=0){
		prefix[k++]=st[top--];
	}
	prefix[k]='\0';
	for(int i=0,k=strlen(prefix)-1;i<k;i++,k--){
		char temp=prefix[i];
		prefix[i]=prefix[k];
		prefix[k]=temp;
	}
	return prefix;
}

int evaluate(char *prefix){
	int operand1 ,operand2;
	int i;
	int st[100];
	int top=-1;
	for(i=0;prefix[i]!='\0';i++){
		char current = prefix[i];
		if(current>='0' && current<='9'){
			st[++top]=current-'0';
		}
		else if(operatorr(current)){
			operand2=st[top--];
			operand2=st[top--]; 
			switch(current){
				case '+':
					st[++top] = operand1 + operand2;
					break;
				case '-':
					st[++top]=operand1 - operand2;
					break;
				case '/':
					st[++top]=operand1 / operand2;
					break;
				case '*':
					st[++top]=operand1 * operand2;
					break;
			}
		}
		
	}
	return st[top--];
	
}
int main(){
	const char* infix="3+4*(2-7)/5";
	char *prefix=infixtopre(infix);
	printf("prefix is %s ",prefix);
	int ans = evaluate(prefix);
	printf("\n%d :",ans);
	return 0;
}
