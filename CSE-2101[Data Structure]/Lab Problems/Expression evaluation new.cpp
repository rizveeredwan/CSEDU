#include <bits/stdc++.h>
using namespace std;

int check_precision(char a)
{
    if(a == '/') return 4;
    if(a == '*') return 3;
    if(a == '+') return 2;
    if(a == '-') return 1;
    else return 0;
}
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
void createint()
{
    tempint = (struct nodeint *)malloc(sizeof(struct nodeint));
}
void pushint(int element)
{
    if(headint == NULL)
    {
        createint();
        tempint->value = element;
        tempint->next = NULL;
        headint = tempint;
    }
    else
    {
        createint();
        tempint->value = element;
        tempint->next = headint;
        headint = tempint;
    }
}
void popint()
{
    if(headint != NULL)
    {
        headint = headint->next;
    }
}
void printint()
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
        createchar();
        tempchar->value = element;
        tempchar->next = NULL;
        headchar = tempchar;
    }
    else
    {
        createchar();
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
            continue;
        }
        else
        {
            if(headchar == NULL)
            {
                pushchar(arr[i]);
              //  cout << headchar->value << endl;
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
                        if(headchar == NULL)
                        {
                            break;
                        }
                        else if(headchar->value == '(')
                        {
                            popchar();
                            break;
                        }
                        else
                        {
                            j++;
                            newarr[j] = headchar->value;
                       //     cout << "ase 1" << headchar->value << endl;
                            popchar();
                        }
                    }

                }
                else if(arr[i] == '}' && flagtwo > 0)
                {
                    flagtwo--;
                    while(1)
                    {
                        if(headchar == NULL)
                        {
                            break;
                        }
                        if(headchar->value == '{')
                        {
                            popchar();
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
                else if(arr[i] == ']' && flagthree > 0)
                {
                    flagthree--;
                    while(1)
                    {
                        if(headchar == NULL)
                        {
                            break;
                        }
                        if(headchar->value == '[')
                        {
                            popchar();
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
            else
            {
                int check_top,check_now;
                if(headchar == NULL)
                {
                    pushchar(arr[i]);
                 //   cout << headchar->value << endl;
                    continue;
                }
                check_top = check_precision(headchar->value);
                check_now = check_precision(arr[i]);
                if(check_now == 0)
                {
                    pushchar(arr[i]);
                    if(arr[i] == '(') flagone++;
                    if(arr[i] == '{') flagtwo++;
                    if(arr[i] == '[') flagthree++;
                    continue;
                }
                if(check_top == 0)
                {
                    pushchar(arr[i]);
                //    cout << headchar->value << endl;
                    continue;
                }
                else if(check_top <= check_now)
                {
                    pushchar(arr[i]);
                   // cout << "dhuke baal" << endl;
                 //   cout << headchar->value << endl;
                  //  cout <<headchar->next->value << " new" << endl;
                }
                else if(check_top > check_now)
                {
                    while(1)
                    {
                        if(headchar == NULL)
                        {
                            break;
                        }
                        check_top = check_precision(headchar->value);
                        check_now = check_precision(arr[i]);
                        //cout << "top = " << check_top << " now = " << check_now << endl;
                        if(check_top <= check_now)
                        {
                           // cout <<"dhuke" << endl;
                            break;
                        }
                        if(check_top > check_now)
                        {
                            j++;
                            newarr[j] = headchar->value;
                            popchar();
                        }
                    }
                     pushchar(arr[i]);
                   //cout << headchar->value << endl;
                }

           }
        }
    }
}
printchar();
while(headchar != NULL)
{
    j++;
    newarr[j] = headchar->value;
    popchar();
}
j++;
newarr[j] = '\0';
cout << newarr << endl;
for(i= 0; i < strlen(newarr); i++)
{
    if(newarr[i] >= '0' && newarr[i] <= '9')
    {
        int a = newarr[i] - '0';
        pushint(a);
    }
    else
    {
        int a = headint->value;
        popint();
        int b = headint->value;
        popint();
        int sign = check_precision(newarr[i]);
        if(sign == 4)
        {
            pushint(b/a);
        }
        if(sign == 3)
        {
            pushint (a * b);
        }
        if(sign == 2)
        {
            pushint(a+b);
        }
        if(sign == 1)
        {
            pushint(b-a);
        }
    }
}
printf("%d\n",headint->value);
return 0;
}



