//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int pre(char ch){
	if(ch=='+' || ch == '-')
		return 1;
	else if(ch == '*' || ch=='/'){
		return 2;
	}
	else
	return 0;
}
char *InfixToPost(const char * infix){
	int len = strlen(infix);
	char *postfix = (char*)malloc((len+1)*sizeof(char));
	int st[100];
	int top=-1;
	int i,j;
	for(i=0;i<len;i++){
		char current = infix[i];
		if(current >='0' && current <='9'){
			postfix[j++]=infix[i];
		}
		else if(current=='('){
			st[++top]=infix[i];
		}
		else if(current==')'){
			while(top>=0 && st[top]!='('){
				postfix[j++]=st[top--];
			}
			//'(' popped
			if(top>=0 && st[top]=='('){
				top--;
			}
		}
		else{
			while(top>=0 && pre(st[top])>= pre(current)){
				postfix[j++]=st[top--];
			}
			st[++top]=current;
		}
	}
	while(top>=0){
		postfix[j++]=st[top--];
	}
	postfix[j]='\0';
	return postfix;
}
int result(char* postfix){
	int len = strlen(postfix);
	int st[100];
	int top=-1;
	int i;
	for(i=0;i<len;i++){
		char current = postfix[i];
		if(current>='0'  && current <='9'){
			st[++top]=current -'0';
		}
		else {
			int op2=st[top--];
			int op1 = st[top--];
			switch(current){
				case '+':
					st[++top] = op1+op2;
					break;
				case '-':
					st[++top]=op1-op2;
					break;
				case '/':
					st[++top]=op1 / op2;
					break;
				case '*':
					st[++top]=op1 * op2;
					break;
				default:
					printf("\nInvalid operator");
					exit(0);
			}
		}
	}
	int anss=st[top--];
	return anss;
	
}
int main(){
	const char* infix="3+4*(2-7)/5";
	char *postfix = InfixToPost(infix);
	
	printf("%s ",infix);
	printf("\n%s ",postfix);
	int ans = result(postfix);
	printf("\nvalue is %d ",ans);
	free(postfix);
	
}
