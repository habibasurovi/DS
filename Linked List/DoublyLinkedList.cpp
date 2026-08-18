#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* prev;
    node* next;
};
node* head = nullptr;

void insertFirst(int x)
{
    node* t = new node;
    t -> data = x;
    if(head == nullptr)
    {
        head = t;
        t->next = nullptr;
        t->prev = nullptr;
    }
    else
    {
        t->next = head;
        t->prev = nullptr;
        head->prev = t;
        head = t;
    }
}
void insertLast(int x)
{
    node* t = new node;
    t -> data = x;
    if(head == nullptr)
    {
        head = t;
        t->prev = nullptr;
        t->next = nullptr;
    }
    else
    {
        node* p = head;
        while(p->next != nullptr)
        {
            p = p->next;
        }
        p->next = t;
        t->prev = p;
        t->next = nullptr;
    }
}

void insertbyPosition(int pos, int x)
{
    node* t = new node;
    t -> data = x;

    node* p = head;
    int countt = 1;
    while(p != nullptr && countt != pos-1)
    {
        p = p->next;
        countt++;
    }
    if(p==nullptr && pos<= 1)
    {
        cout<< "Position is out of index";
        return;
    }
    t->next = p->next;
    p->next->prev = t;
    p->next = t;
    t->prev = p;

}
void insertbyValue(int prevValue,int x)
{
    node* t = new node;
    t->data = x;

    node* p = head;
    while(p!= nullptr)
    {
        if(p->data == prevValue)
        {
            t->prev = p;
            t->next = p->next;
            if(p->next != nullptr)
                p->next->prev = t;
            p->next = t;
            return;
        }
        p = p->next;
    }
}

void deleteFirst()
{
    if(head == nullptr)
    {
        cout<< "List is empty"<<endl;
        return;
    }
    node* p = head;
    head = head->next;
    if(head != nullptr)
        head->prev = nullptr;
    p->next = nullptr;
    delete p;
}

void deleteLast()
{
    if(head == nullptr)
    {
        cout<< "List is empty"<<endl;
        return;
    }
    if(head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    node* p = head;
    while(p->next->next != nullptr)
    {
        p = p->next;
    }
    node* p1 = p->next;
    p->next = nullptr;
    delete p1;
}
void deletebyPosition(int pos)
{
    node* p = head;
    int countt = 1;
    while(countt!= pos -1 && p != nullptr)
    {
        p = p->next;
        countt++;
    }
    if(pos<=1 && p==nullptr)
    {
        cout<< "Invalid position"<<endl;
        return;
    }
    node* p1 = p->next;
    p->next = p1->next;
    if(p->next != nullptr)
        p1->next->prev = p;
    delete p1;
}

void deletebyValue(int val)
{
    node* p = head;
    if(head== nullptr)
    {
        cout << "Invalid position" << endl;
    }
    while(p != nullptr)
    {
        if(p->data == val)
        {
            if(p->prev == nullptr)
            {
                deleteFirst();
                return;
            }

            p->prev->next = p->next;
            if(p->next != nullptr)
                p->next->prev = p->prev;
            delete p;
            return;
        }
        p = p->next;
    }
}

void printingF()
{
    node* p = head;
    while(p != nullptr)
    {
        cout<< p->data<< " ";
        p = p->next;
    }
}
void printingB()
{
    node* p = head;
    while(p->next!=nullptr)
    {
        p = p->next;
    }
    while(p!=nullptr)
    {
        cout<< p->data << " ";
        p = p->prev;
    }
}
void reversePrint(node* p)
{
    if(p == nullptr)
    {
        return;
    }
    reversePrint(p->next);
    cout<< p->data << " ";
}

void last_node()
{
    if(head == nullptr)
    {
        cout<< "List is empty. "<< endl;
        return;
    }
    node* p = head;
    while(p->next != nullptr)
    {
        p = p->next;
    }
    cout<< p->data;
}

void previous_of_the_last_node()
{
    if(head == nullptr)
    {
        cout<< "List is empty. "<< endl;
        return;
    }
    node* p = head;
    while(p->next != nullptr)
    {
        p = p->next;
    }
    cout<< p->prev->data;
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
    printf("9.Print the linked list from start.\n");
    printf("10.Print the linked list in reverse order.\n");
    printf("11.Print the last node.\n");
    printf("12.Print the previous node of the last node.\n");
    printf("13.Print the list size.\n");
    printf("14.Search an element.\n");
    printf("15.Print the linked list backward.\n");
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
            printingF();
        }
        else if (i == 10)
        {
            reversePrint(head);
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
        else if(i == 15)
        {
            printingB();
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

