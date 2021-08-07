#include <bits/stdc++.h>
using namespace std;

struct nodeint
{
    int value;
    struct nodeint *next;
}*headint,*tempint,*LLint;
void menu()
{
    printf("1 to push\n");
    printf("2 to pop\n");
    printf("3 to print\n");
    printf("4 to show top\n");
    printf("5 to delete\n");
}
void create()
{
    tempint = (struct nodeint *)malloc(sizeof(struct nodeint));
}
void push(int element)
{
    if(headint == NULL)
    {
        create();
        tempint->value = element;
        tempint->next = NULL;
        headint = tempint;
    }
    else
    {
        create();
        tempint->value = element;
        tempint->next = headint;
        headint = tempint;
    }
}
void pop()
{
    if(headint != NULL)
    {
        headint = headint->next;
    }
}
void print()
{
    LLint = headint;
    while(LLint != NULL)
    {
        printf("%d\n",LLint->value);
        LLint = LLint->next;
    }
}
void clear_LLint()
{
    LLint = headint;
    while(LLint != NULL)
    {
        tempint = LLint;
        LLint = LLint->next;
        free(tempint);

    }
}
struct nodechar
{
    char value;
    struct nodechar *next;
}*headchar,*tempchar,*LLchar;
void menuchar()
{
    printf("1 to push\n");
    printf("2 to pop\n");
    printf("3 to print\n");
    printf("4 to show top\n");
    printf("5 to delete\n");
}
void createchar()
{
    tempchar = (struct nodechar *)malloc(sizeof(struct nodechar));
}
void pushchar(char element)
{
    if(headchar == NULL)
    {
        create();
        tempchar->value = element;
        tempchar->next = NULL;
        headchar = tempchar;
    }
    else
    {
        create();
        tempchar->value = element;
        tempchar->next = headchar;
        headchar = tempchar;
    }
}
void popchar()
{
    if(headchar != NULL)
    {
        headchar = headchar->next;
    }
}
void printchar()
{
    LLchar = headchar;
    while(LLchar != NULL)
    {
        printf("%c\n",LLchar->value);
        LLchar = LLchar->next;
    }
}
void clear_LLchar()
{
    LLchar = headchar;
    while(LLchar != NULL)
    {
        tempchar = LLchar;
        LLchar = LLchar->next;
        free(tempchar);

    }
}

int main(void)
{
    char arr[200];
    char newarr[200];
    cin >> arr;
    int len = strlen(arr);
    int i,j = -1,flagone = 0, flagtwo = 0, flagthree = 0;
    for(i = 0; i < len; i++)
    {
        if(arr[i] >= '0' && arr[i] <= '9')
        {
            j++;
            newarr[j] = arr[i];
        }
        else
        {
            if(headchar == NULL)
            {
                pushchar(arr[i]);
                if(arr[i] =='(')
                {
                    flagone++;
                }
                else if(arr[i] =='{')
                {
                    flagtwo++;
                }
                else if(arr[i] =='[')
                {
                    flagthree++;
                }
            }
            else
            {
                if(arr[i] == ')' && flagone > 0)
                {
                    flagone--;
                    while(1)
                    {
                        if(headchar->value == ')')
                        {
                            popchar();
                            break;
                        }
                        if(headchar == NULL)
                        {
                            break;
                        }
                        else
                        {
                            j++;
                            newarr[j] = headchar->value;
                            popchar();
                        }
                    }
                    continue;
                }
                else if(arr[i] == '}' && flagtwo > 0)
                {
                    flagtwo--;
                    while(1)
                    {
                        if(headchar->value == '}')
                        {
                            popchar();
                            break;
                        }
                        if(headchar == NULL)
                        {
                            break;
                        }
                        else
                        {
                            j++;
                            newarr[j] = headchar->value;
                            popchar();
                        }
                    }
                }
            }
        }
    }
}



