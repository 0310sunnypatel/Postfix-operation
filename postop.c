#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct stack
{
    char data[20];
    int top;
}s;
void initialize(struct stack *s)
{
    s->top=-1;
}
char pop(struct stack *s)
{
    if(s->top==-1)
        printf("Stack Underflow\n");
    else
    {
        return s->data[s->top];
        s->top--;
    }
}
float result(int op2,int op1,char ele)
{
    if(ele=='+')
        return op2+op1;
    else if(ele=='-')
        return op2-op1;
    else if(ele=='*')
        return op2*op1;
    else if(ele=='/')
        return op2-op1;
    else if(ele=='^')
        return op2^op1;
}
void push(struct stack *s,char ele)
{
    if(s->top==9)
        printf("Overflow\n");
    else if(isalnum(ele))
    {
        s->top++;
        s->data[s->top]=ele;
    }
    else
    {
        int op1,op2;
        float r;
        op2=pop(&s);
        op1=pop(&s);
        r=result(op2,op1,ele);
        push(&s,r);
    }
}
void display(struct stack *s)
{
    int i;
    if(s->top==-1)
        printf("Stack Underflow\n");
    else
    {
        printf("The Result of Postfix Expression is :\t");
        for(i=s->top;i>=0;i--)
            printf("%f ",s->data[i]);
    }
}
void main()
{
    initialize(&s);
    int i;
    char postfix[20];
    printf("Enter the Postfix expression :\t");
    gets(postfix);
    for(i=0;postfix[i]!='\0';i++)
        push(&s,postfix[i]);
    display(&s);

}


