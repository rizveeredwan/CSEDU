#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    struct node *left,*right;
}*ll,*root,*temp,*dhor;

int levelcounter = 0;
void menu()
{
    cout << "********************************" << endl;
    cout << "Press 1 to insert" << endl;
    cout << "Press 2 to traverse in pre-order" <<  endl;
    cout << "Press 3 to traverse in in-order" <<  endl;
    cout << "Press 4 to traverse post-order" << endl;
    cout << "Press 5 to search" << endl;
    cout << "Press 6 to delete" << endl;
    cout <<"Please give your choice: " ;
}

void in(int number)
{
    if(root == NULL)
    {
        root = (struct node*)malloc(sizeof(struct node));
        root->value = number;
        root->left = NULL;
        root->right = NULL;
    }
    //cout << root->value << endl;
    else if(root != NULL)
    {
        temp = root;
        while(temp != NULL)
        {
            if(temp->value < number)
            {
                cout << temp->value << endl;
                if(temp->right == NULL)
                {
                    ll = (struct node*)malloc(sizeof(struct node));
                    ll->value = number;
                    ll->right = NULL;
                    ll->left = NULL;
                    temp->right = ll;
                    cout << temp->right->value <<  endl;
                    break;
                }
                else if(temp->right != NULL)
                {
                    temp = temp->right;
                }
            }
            else if(temp->value >= number)
            {
                cout << temp->value << endl;
                if(temp->left == NULL)
                {
                    ll = (struct node*)malloc(sizeof(struct node));
                    ll->value = number;
                    ll->right = NULL;
                    ll->left = NULL;
                    temp->left = ll;
                    cout << temp->left->value <<  endl;
                    break;
                }
                else if(temp->left != NULL)
                {
                    temp = temp->left;
                }
            }
        }
    }
    levelcounter++;
}
void traverse_preorder(struct node *temp)
{
    if(temp == NULL) return;
    printf("%d\n",temp->value);
    traverse_preorder(temp->left);
    traverse_preorder(temp->right);
}
void traverse_inorder(struct node *temp)
{
    if(temp == NULL)return;
    traverse_inorder(temp->left);
    printf("%d\n",temp->value);
    traverse_inorder(temp->right);
}
void traverse_postorder(struct node *temp)
{
    if(temp == NULL) return;
    traverse_postorder(temp->left);
    traverse_postorder(temp->right);
    printf("%d\n",temp->value);
}
void sch(int number)
{
    temp = root;
    int level = -1;
    int flag = 0;
    while(temp != NULL)
    {
        level++;
        if(temp->value == number)
        {
            flag = 1;
            break;
        }
        if(temp->value < number)
        {
            if(temp->right != NULL)
            {
                temp = temp->right;
            }
        }
        if(temp->value > number)
        {
            if(temp ->left!= NULL) temp = temp->left;
        }
        if(level > levelcounter)
        {
            break;
        }
    }
    if(flag == 0)
    {
        cout << "We didn't get the number in the BST." << endl;
    }
    if(flag == 1)
    {
        cout << "We find the  number at " << level << endl;
    }
}
void del(int number)
{
    temp = root;
    int level = -1,sign = -1,st,RD,LD;
    while(temp != NULL)
    {
        level++;
        if(temp->value == number)
        {
            if(temp->right == NULL && temp->left == NULL)
            {
                sign = 0;
                st = level;
                break;
            }
            else if(temp->right == NULL || temp->left == NULL)
            {
                sign = 1;
                st = level;
                break;
            }
            else
            {
                sign = 2;
                st = level;
                dhor = temp;
                break;
            }
        }
        if(temp->value < number)
        {
            if(temp->right != NULL)
            {
                temp = temp->right;
                RD = 1;
                LD = 0;
            }
        }
        if(temp->value > number)
        {
            if(temp->left != NULL)
            {
                temp = temp->left;
                RD = 0;
                LD = 1;
            }
        }
        if(level > levelcounter)
        {
            break;
        }
    }
    if(sign == -1)
    {
        cout <<"The number is not found in the BST" << endl;
    }
    else
    {
        cout << "The number is found at " << level << "and " << "RD = " << RD << " and LD = " << LD <<" sign =  " << sign << endl;
    }
    if(sign == 0)
    {
        temp = root;
        level = -1;
        while(temp != NULL)
        {
            level++;
            if(level + 1 == st)
            {
                if(RD == 1) temp->right = NULL;
                else if(LD == 1) temp->left = NULL;
                break;
            }
            if(temp->value < number)
            {
                if(temp->right != NULL) temp = temp->right;
            }
            if(temp->value > number)
            {
                if(temp->left != NULL) temp  =  temp->left;
            }
            if(level > levelcounter) break;
        }
    }
    else if(sign == 1)
    {
        level = -1;
        temp = root;
        while(temp != NULL)
        {
            level++;
            if(level + 1 == st)
            {
                if(RD == 1)
                {
                    ll = temp-> right;
                    cout << " ll " << ll->value << endl;
                    if(ll->right != NULL)
                    {
                        temp->right = ll->right;
                    }
                    if(ll->left != NULL)
                    {
                        temp->right = ll->left;
                    }
                }
                else if(LD == 1)
                {
                    ll = temp-> left;
                    cout << " ll " << ll->value << endl;
                    if(ll->right != NULL)
                    {
                        temp->left = ll->right;
                    }
                    if(ll->left != NULL)
                    {
                        temp->left = ll->left;
                    }
                }
                break;
            }
            if(temp->value < number)
            {
                if(temp->right != NULL) temp = temp->right;
            }
            if(temp->value > number)
            {
                if(temp->left != NULL) temp  =  temp->left;
            }
            if(level > levelcounter) break;
        }
    }
    else if(sign == 2)
    {
        temp = dhor -> right;
        int bslevel = 0;
        int sw;
        int savevalue,mRD,mLD;
        while(temp != NULL)
        {
            bslevel++;
            if(temp->left == NULL) {
            dhor = temp;
            savevalue = dhor->value;
            if(temp->right == NULL) {
                sw = 0;
            }
            else sw = 1;
             break;
            }
            else {
                temp = temp->left;
            }
        }
        st = st + bslevel;
        cout << st << " st " << savevalue << endl;
        if(sw == 0)
        {
            temp = root;
            level = -1;
            while(temp != NULL)
            {
                level++;
                if(temp->value == number) {
                    temp->value = savevalue;
                }
                if(level + 1 == st) {
                   if(temp->right != NULL && temp->right->value == savevalue) {
                    temp->right = NULL;
                   }
                   if(temp->left != NULL && temp->left->value == savevalue) {
                    temp->left = NULL;
                   }
                    break;
                }
                if(temp->value < savevalue) {
                    if(temp->right != NULL)temp = temp->right;
                }
                if(temp->value > savevalue) {
                    if(temp->left != NULL) temp = temp->left;
                }
                if(level > levelcounter) {
                    break;
                }

            }
        }
        else if(sw == 1)
        {
            temp = root;
            level = -1;
            while(temp != NULL)
            {
                level++;
                if(temp->value == number)
                {
                    temp->value = savevalue;
                }
                if(level + 1 == st) {
                    cout << "ase" << temp ->value << endl;
                    if(temp->right != NULL && temp->right->value == savevalue) {
                        temp->right = temp->right->right;
                    }
                    if(temp->left != NULL && temp->left->value == savevalue) {
                        temp->left = temp->left->right;
                    }

                    break;
                }
                if(temp->value < savevalue) {
                   if(temp->right != NULL) temp = temp->right;
                }
                if(temp->value > savevalue) {
                   if(temp->left != NULL) temp = temp->left;
                }
                if(level > levelcounter) {
                    break;
                }

            }
        }

    }
}
int main(void)
{
    int option,number;
    while(1)
    {
        menu();
        cin >> option;
        if(option == 1)
        {
            cout <<"Give number to put in the tree : " ;
            cin >> number;
            in(number);
        }
        if(option == 2)
        {
            cout <<"Traversing in preorder: " << endl;
            traverse_preorder(root);
        }
        if(option == 3)
        {
            cout <<"Traversing in inorder: " << endl;
            traverse_inorder(root);
        }
        if(option == 4)
        {
            cout <<"Traversing in postorder: " << endl;
            traverse_postorder(root);
        }
        if(option == 5)
        {
            cout <<"Give number to search in the BST: " ;
            cin >> number;
            sch(number);
        }
        if(option == 6)
        {
            cout << "Give number to delete : " ;
            cin >> number;
            del(number);
        }

    }
}
