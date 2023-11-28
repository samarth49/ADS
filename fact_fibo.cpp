#include <stdio.h>
#include <stdlib.h>
#define max 100

struct st {
    int top;
    int arr[max];
};

void init(struct st *s) {
    s->top = -1;
}

void push(struct st *s, int data) {
    if (s->top < max - 1) {
        s->arr[++s->top] = data;
    } else {
        printf("Overflow\n");
        return;
    }
}

int pop(struct st *s) {
    int item = -1;
    if (s->top == -1) {
        printf("Underflow\n");
    } else {
        item = s->arr[s->top];
        s->top--;
    }
    return item;
}

void display(struct st *s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int factorial(struct st *s, int n) {
    for (int i = n; i >= 1; i--) {
        push(s, i);
    }

    int ans = 1;
    while (s->top >= 0) {
        ans = ans * pop(s);
    }

    return ans;
}
void fibo(struct st *s,int n){
	int a=0,b=1,next;
	for(int i=1;i<=n;i++){
		push(s,a);
		next=a+b;
		a=b;
		b=next;
	}
	
}
int main() {
    struct st s;
    init(&s);
    display(&s);

    printf("Enter the number of which you want to know the factorial: ");
    int n;
    scanf("%d", &n);

    int ans = factorial(&s, n);
    printf("Factorial of %d is %d\n", n, ans);
    fibo(&s,n);
    printf("Fabionaccie series is: ");
    display(&s);

    return 0;
}

