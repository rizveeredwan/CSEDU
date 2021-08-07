#include <bits/stdc++.h>
using namespace std;

int counter;
int arr[1030];
void menu()
{
    cout << "***************************************" << endl;
    cout << "Press 1 to push in the Queue" << endl;
    cout << "Press 2 to pop from the Queue" << endl;
    cout << "Press 3 to show the Queue" << endl;
    cout << "Press 4 to show the size" << endl;
    cout << "Press 5 to see the front" <<  endl
    cout << "Press 6 to delete the whole Queue" << endl;
    cout << "****************************************" << endl<< endl << endl << endl;
}

void push_in_queue(int input)
{

    if(counter == 1029) {
        cout << "The Queue is full.No element can be pushed in the Queue." << endl;
    }
    else
    {
        counter++;
        arr[counter] = input;
    }
}
void pop_from_queue()
{
    if(counter == -1)
    {
       cout << "No element can be poped from the queue" << endl;
    }
    if(counter == 0) {
        counter = -1;
    }
    if(counter > 0)
    {
        for(int i = 1; i <= counter; i++)
        {
            arr[i - 1] = arr[i];
        }
        counter = counter - 1;
    }
}

void show_whole_queue()
{
    int i;
    for(i = 0; i <= counter; i++)
    {
        cout << arr[i] << endl;
    }
}


int main(void)
{
    counter  = -1;
    int option,input;
    while(1)
    {
        menu();
        cout << "Please give your choice/option." << endl;
        cout << "Your option : ";
        cin >> option;
        if(option == 1)
        {
            cout <<"Give element to push in the Queue" << endl;
            cout <<"Give element: " ;
            cin >> input;
            push_in_queue(input);
        }
        if(option == 2)
        {
            cout << "Poping from the queue" << endl;
            pop_from_queue();
        }
        if(option == 3)
        {
            cout <<"The size of the whole queue " ;
            cout << counter << endl;
        }
        if(option == 4)
        {
            cout << "Print the whole Queue" << endl;
            show_whole_queue();
        }
        if(option == 5)
        {
            cout << "The top of the queue is : " ;
            cout << arr[0] << endl;
        }
        if(option == 6)
        {
            counter = -1;
            break;
        }
    }
    return 0;
}
