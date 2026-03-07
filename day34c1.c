#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node *temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

int main()
{
    char exp[100];

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    char *token = strtok(exp, " ");

    while (token != NULL)
    {

        if (isdigit(token[0]))
        {
            push(atoi(token));
        }
        else
        {
            int b = pop();
            int a = pop();
            int result;

            switch (token[0])
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            }

            push(result);
        }

        token = strtok(NULL, " ");
    }

    printf("%d\n", pop());

    return 0;
}