#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    struct node*next;
}*head,*LL,*temp;

void menu()
{
    cout << "***************************************" << endl;
    cout << "Press 1 to push in the Queue" << endl;
    cout << "Press 2 to pop from the Queue" << endl;
    cout << "Press 3 to show the Queue" << endl;
    cout << "Press 4 to show the size" << endl;
    cout << "Press 5 to see the front" <<  endl;
    cout << "Press 6 to delete the whole Queue" << endl;
    cout << "****************************************" << endl<< endl << endl << endl;
}

void creation_of_node()
{
    temp = (struct node*)malloc(sizeof(struct node));
}
void push_in_queue(int input)
{
    if(head == NULL)
    {
        creation_of_node();
        temp->value = input;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        LL = head;
        while(LL->next!= NULL)
        {
            LL = LL->next;
        }
        creation_of_node();
        temp->value = input;
        temp->next = NULL;
        LL->next = temp;
    }
}
void pop_from_queue()
{
    if(head == NULL)
    {
        cout << "There is nothing in the queue" << endl;
    }
    else
    {
       temp = head;
       head = head->next;
       free(temp);
    }
}
void show_whole_queue()
{
    LL = head;
    while(LL != NULL)
    {
        cout << LL->value << endl;
        LL = LL->next;
    }
}
void showing_the_whole_size()
{
    int counter = 0;
    LL = head;
    while(LL != NULL) {
        counter++;
        LL = LL -> next;
    }
    cout <<"The whole size of the queue is = " << counter << endl;
}
void clearing_the_whole_queue()
{

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void)
{
    int input,option;
   while(1)
   {
       menu();
       cout << "Please give your choice " << endl;
       cin >> option;
       if(option == 1)
       {
          cout <<"Please give input to insert in the queue " ;
          cin >> input;
          push_in_queue(input);
       }
       if(option == 2)
       {
           cout << "Poping the first element from the queue" << endl;
           pop_from_queue();
       }
       if(option == 3)
       {
           cout << "Printing all the elements of the queue" << endl;
           show_whole_queue();
       }
       if(option == 4)
       {
           showing_the_whole_size();
       }
       if(option == 5)
       {
           if(head == NULL)
           {
             cout <<"There is nothing in the queue" << endl;
           }
           else
           {
               cout << "The value which is at the top is = " << head->value << endl;
           }
       }
       if(option == 6)
       {
          clearing_the_whole_queue();
          break;
       }
   }
   return 0;
}

