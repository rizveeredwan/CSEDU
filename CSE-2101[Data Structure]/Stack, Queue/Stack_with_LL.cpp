#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    struct node *next;
}*head,*temp,*LL;
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
    temp = (struct node *)malloc(sizeof(struct node));
}
void push(int element)
{
  if(head == NULL)
  {
      create();
      temp->value = element;
      temp->next = NULL;
      head = temp;
  }
  else
  {
      create();
      temp->value = element;
      temp->next = head;
      head = temp;
  }
}
void pop()
{
    if(head != NULL)
    {
        head = head->next;
    }
}
void print()
{
    LL = head;
    while(LL != NULL)
    {
        printf("%d\n",LL->value);
        LL = LL->next;
    }
}
void clear_LL()
{
    LL = head;
    while(LL != NULL)
    {
        temp = LL;
        LL = LL->next;
        free(temp);

    }
}
int main()
{
    while(1)
    {
      menu();
      int input,option;
      cin >> option;
      if(option == 1)
      {
          cin >> input;
          push(input);
      }
      if(option == 2)
      {
          pop();
      }
      if(option == 3)
      {
          print();
      }
      if(option == 4)
      {
          printf("%d\n",head->value);
      }
      if(option == 5)
      {
          clear_LL();
      }
    }
    return 0;
}
