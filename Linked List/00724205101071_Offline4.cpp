#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
};
node* head = nullptr;

void insertFirst(int x)
{
    node* t = new node;
    t -> data = x;
    t -> next = head;
    head = t;
}
void insertLast(int x)
{
    node* t = new node;
    t -> data = x;
    if(head == nullptr)
    {
        t -> next = nullptr;
        head = t;
    }
    else
    {
        node* p = head;
        while(p->next != nullptr)
        {
            p = p -> next;
        }
        p -> next = t;
        t -> next = nullptr;
    }
}
void printing()
{
    if(head == nullptr)
    {
        cout<< " List is empty " << endl;
    }
    else
    {
        node* p = head;
        while(p != nullptr)
        {
            cout<< p -> data << " ";
            p = p -> next;
        }
        cout<<endl;
    }

}
void deleteFirst()
{
    if(head == nullptr)
    {
        cout<< " List is empty, NOTHING can be deleted." << endl;
    }
    else
    {
        node* p = head;
        head = head -> next;
        delete p;
    }
}
void deleteLast()
{
    if(head == nullptr)
    {
        cout<< " List is empty, NOTHING can be deleted." << endl;
    }
    else if(head->next == nullptr)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        node* p = head;
        node* p1;
        while(p -> next != nullptr)
        {
            p1 = p;
            p = p -> next;
        }
        p1 -> next = nullptr;
        delete p;
    }
}

void last_node()
{
    if(head == nullptr)
    {
        cout<< "List is empty. "<< endl;
    }
    else
    {
        node* p = head;
        while( p -> next != nullptr)
        {
            p = p->next;
        }
        cout << p -> data;
    }
}
void previous_of_the_last_node()
{
    if(head == nullptr)
    {
        cout<< "List is empty. " << endl;
    }
    else if(head->next == nullptr)
    {
        cout<< "Previous node of last node does not exist. " << endl;
    }
    else
    {
        node* p = head;
        while(p->next->next != nullptr)
        {
            p = p-> next;
        }
        cout<< p-> data <<endl;
    }
}
void listSize()
{
    node* p = head;
    int countt = 0;
    while(p != nullptr)
    {
        countt++;
        p = p -> next;
    }
    cout << countt << endl;
}

void reversePrint(node* p)
{
    if(p == nullptr)
    {
        return;
    }

    reversePrint(p->next);
    cout << p->data << " ";
}
void reversePrint()
{
    if(head == nullptr)
    {
        cout<< "ERROR! List is empty." << endl;
        return;
    }
    reversePrint(head);
    cout << endl;
}

void searching(int x)
{
    if(head == nullptr)
    {
        cout<< "ERROR! List is empty." << endl;
    }
    else
    {
        node* p = head;
        int nodeNumber = 1;
        while(p != nullptr)
        {
            if(p->data == x)
            {
                cout << "Element found at node " << nodeNumber << endl;
                return;
            }
            nodeNumber++;
            p = p -> next;
        }
        cout << "Element not found." << endl;
    }
}
void insertbyPosition(int pos, int x)
{
    if(pos <= 1)
    {
        cout << "Invalid position." << endl;
        return;
    }

    node* p = head;
    int count = 1;

    while(p != nullptr && count < pos - 1)
    {
        p = p->next;
        count++;
    }

    if(p == nullptr)
    {
        cout << "Position out of range." << endl;
        return;
    }

    node* t = new node;
    t->data = x;
    t->next = p->next;
    p->next = t;
}
void insertbyValue(int value, int x)
{
    if(head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    node* p = head;

    while(p != nullptr)
    {
        if(p->data == value)
        {
            node* t = new node;
            t->data = x;
            t->next = p->next;
            p->next = t;
            return;
        }

        p = p->next;
    }

    cout << "Invalid" << endl;
}
void deletebyPosition(int pos)
{
    if(head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    if(pos <= 1)
    {
        cout << "Invalid position." << endl;
        return;
    }

    node* p = head;
    int count = 1;

    while(p != nullptr && count < pos - 1)
    {
        p = p->next;
        count++;
    }

    if(p == nullptr || p->next == nullptr)
    {
        cout << "Position out of range." << endl;
        return;
    }

    node* temp = p->next;
    p->next = temp->next;
    delete temp;
}
void deletebyValue(int value)
{
    if(head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    node* p = head;

    while(p->next != nullptr)
    {
        if(p->next->data == value)
        {
            node* temp = p->next;
            p->next = temp->next;
            delete temp;
            return;
        }

        p = p->next;
    }

    cout << "Value not found." << endl;
}
int main(void)
{
    printf("1.Insert an element at the beginning of linked list.\n");
    printf("2.Insert an element at the end of linked list.\n");
    printf("3.Insert an element anywhere between two nodes by position.\n");
    printf("4.Insert an element anywhere between two nodes after a specific value.\n");
    printf("5.Delete an element from beginning.\n");
    printf("6.Delete an element from end.\n");
    printf("7.Delete an element by position (anywhere between two nodes).\n");
    printf("8.Delete an element by value(anywhere between two nodes).\n");
    printf("9.Print the linked list.\n");
    printf("10.Print the linked list in reverse order.\n");
    printf("11.Print the last node.\n");
    printf("12.Print the previous node of the last node.\n");
    printf("13.Print the list size.\n");
    printf("14.Search an element.\n");
    printf("0.Exit\n");

    int i, data;

    for (;;)
    {
        printf("\nEnter option: ");
        scanf("%d", &i);

        if (i == 1)
        {
            printf("Enter value of element: ");
            scanf("%d", &data);
            insertFirst(data);
        }
        else if (i == 2)
        {
            printf("Enter value of element: ");
            scanf("%d", &data);
            insertLast(data);
        }
        else if (i == 3)
        {
            int pos;
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> data;
            insertbyPosition(pos, data);
        }
        else if (i == 4)
        {
            int val;
            cout << "Enter the value after which you want to insert: ";
            cin >> val;
            cout << "Enter new value: ";
            cin >> data;
            insertbyValue(val, data);
        }
        else if (i == 5)
        {
            deleteFirst();
        }
        else if (i == 6)
        {
            deleteLast();
        }
        else if (i == 7)
        {
            int pos;
            cout << "Enter the position to delete: ";
            cin >> pos;
            deletebyPosition(pos);
        }
        else if (i == 8)
        {
            int value;
            cout << "Enter the value to delete: ";
            cin >> value;
            deletebyValue(value);
        }
        else if (i == 9)
        {
            printing();
        }
        else if (i == 10)
        {
            reversePrint();
        }
        else if (i == 11)
        {
            last_node();
        }
        else if (i == 12)
        {
            previous_of_the_last_node();
        }
        else if (i == 13)
        {
            listSize();
        }
        else if (i == 14)
        {
            int x;
            cout << "Enter the element you want to search : ";
            cin >> x;
            searching(x);
        }
        else if (i == 0)
        {
            break;
        }
        else
        {
            printf("Please enter valid input.\n");
        }
    }
}

