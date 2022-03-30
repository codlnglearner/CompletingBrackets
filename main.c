/*
I, <Ling Wai Lok>, am submitting the assignment for
an individual project.
I declare that the assignment here submitted is original except for
source material explicitly acknowledged, the piece of work, or a part
of the piece of work has not been submitted for more than one purpose
(i.e. to satisfy the requirements in two different courses) without
declaration. I also acknowledge that I am aware of University policy
and regulations on honesty in academic work, and of the disciplinary
guidelines and procedures applicable to breaches of such policy and
regulations, as contained in the University website
http://www.cuhk.edu.hk/policy/academichonesty/.
It is also understood that assignments without a properly signed
declaration by the student concerned will not be graded by the
teacher(s).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100000

typedef enum{FALSE =0, TRUE = 1} Boolean;

typedef struct{
    int size;
    int top;
    int *stacklist;
}stack;

stack *createS(int size){
    stack *s;
    s = (stack*)malloc(sizeof(stack));
    s->size =size;
    s->stacklist = (int*)malloc(size * sizeof(int));
    s->top = -1;
    return s;
}


Boolean IsFull(stack *s){
    if (s->top == s->size -1)
        return TRUE;
    else return FALSE;
}



Boolean IsEmpty(stack *s){
    if (s->top == -1)
        return TRUE;
    else return FALSE;
}


void push(stack *s, int e){
    if (!IsFull(s)){
        s->top++;
        s->stacklist[s->top] = e;
    }
}


char pop(stack *s){
    int i;
    if (!IsEmpty(s)){
        i = s-> stacklist[s->top];
        s->top--;
        return i;
    }else{printf("error\n"); return -1;}
}

char top(stack *s){ return s->stacklist[s->top];}


Boolean isMatching(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return TRUE;
    else if (character1 == '[' && character2 == ']')
        return TRUE;
    else
        return FALSE;
}

char* isValid(char A[], int A_len)
{
    char* output;
    stack *stack_holder = createS(20000);
    // code here
    int i=0,j=0,fill=1;
    char tmp,B[MAX];
    for(i=0;i<A_len;i++){
        if(A[i]=='('||A[i]=='['){
            push(stack_holder,A[i]);
        }else{
            if(isMatching(top(stack_holder),A[i])){
                pop(stack_holder);
            }else{
                output="invalid";
                fill=0;
            }
        }
    }
    if(fill==1&&IsEmpty(stack_holder)==TRUE){
        output="valid";
    }else if(fill==1){
        while(IsEmpty(stack_holder)==FALSE){
            tmp=pop(stack_holder);
            if(tmp=='('){
                tmp=')';
            }else{
                tmp=']';
            }
            B[j]=tmp;
            j++;
        }
        output=B;
    }
    /*if(top(stack_holder)=='('){
        pop(stack_holder);
        stack_holder->top--;
        A[i+1]=')';
        i++;
    }
    if(top(stack_holder)=='['){
        pop(stack_holder);
        stack_holder->top--;
        A[i+1]=']';
        i++;
    }*/

    return output;
}


int main()
{
    char value;
    char A[MAX];
    int A_len;
    printf("Input the number of chars in A:\n");
    scanf("%d", &A_len);
    printf("Input these chars:\n");
    scanf("%s", A);
    printf("%s", isValid(A, A_len));

    return 0;
}
