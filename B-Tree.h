

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

struct node
{
    int id;
    string name;
    string city;
    string country;
    string phone;
    double contribution;

    struct node *next;
};

class linkedList
{
     public:
        struct node *top;

        linkedList() // constructor
        {
            top=NULL;
        }
        linkedList( struct node *n)
        {
            top  = n ;
        }
        void addtoLL(node *n); // to insert an element
        void add(struct node** head_ref);
        void deletefromLL(node *n);
        void deletefromLLbyID(int id);
        void printAnElemenet(node *n);  // to show a single element
        void print(int id); // to print a single element matching the id
        void printAll(); // to print all element
        bool searchByName(string name);
        node* binary_searchByName(string name);

};

struct node* middle (struct node *start, struct node *last)
{
    if(start == NULL){ return NULL;}
    struct node *slow = start;
    struct node *fast = start->next;

    while( fast!= last)
    {
        fast = fast->next;

        if( fast != last)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
};
struct node* linkedList:: binary_searchByName(string name)
{
    ///assumed that the list is sorted
    struct node *start = this->top;
    struct node *last = NULL;
    do
    {
        node *mid = middle(start, last);

        if(mid == NULL){ return NULL;}

        if( mid->name == name || name.compare(mid->name) == 0 )
        {
            return mid;
        }
        else if( mid->name < name )
        {
            start =  mid -> next;
        }
        else
        {
            last = mid;
        }


    }while( last == NULL || last->next != start);

    return NULL;

}

bool linkedList:: searchByName(string name)
{
    struct node *temp = (this->top);
    while(temp != NULL)
    {
        string r = temp->name;
        //if( strcmp(name,r) == 0)
        if( name.compare(r) == 0)
        {
            cout<<"found contributor \n";
            this->printAnElemenet(temp);
            return true;

        }
        temp = temp->next;
    }
    cout<<" contributor not found \n";
    return false;

}


void linkedList::add(struct node** head_ref)
{
    int value1;
    double value2;

    cout<<"\n add contructor called \n";

    struct node* ptr = new node;

    cout<<"Enter a Contributor id to insert: ";
    cin>>value1;
    ptr->id=value1;

    // to ignore any escape characters after the int
    string temp;
    getline(cin, temp);

    cout<<"Enter Contributor name: ";
    getline(cin,ptr->name);

    cout<<"Enter Contributor city: ";
    getline(cin,ptr->city);

    cout<<"Enter Contributor country: ";
    getline(cin,ptr->country);

    cout<<"Enter Contributor phone: ";
    getline(cin,ptr->phone);

    cout<<"Enter contribution amount :";
    cin>>value2;
    ptr->contribution=value2;

    struct node* current;
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->id >= ptr->id)
    {
        ptr->next = *head_ref;
        *head_ref = ptr;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = *head_ref;
        while (current->next!=NULL &&
               current->next->id < ptr->id)
        {
            current = current->next;
        }
        ptr->next = current->next;
        current->next = ptr;
    }
}
void linkedList::addtoLL(node* new_data)
{
     /* allocate node */
    struct node* new_node = new node;

    /* put in the data  */
    new_node->id  = new_data->id;
    new_node->name  = new_data->name;
    new_node->city  = new_data->city;
    new_node->country  = new_data->country;
    new_node->contribution  = new_data->contribution;
    new_node->phone  = new_data->phone;

    /* link the old list off the new node */
    new_node->next = (this->top);

    /* move the head to point to the new node */
    (this->top)    = new_node;
}
void linkedList ::deletefromLLbyID( int id)
{
    // Store head node
    struct node* temp = this->top, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->id == id)
    {
        this->top = temp->next;   // Changed head
        free(temp);               // free old head
        return;
    }
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;

    cout<<" deleted node with id : "<< id << endl ;
    free(temp);  // Free memory

}
void linkedList:: printAnElemenet(node *n)
{
    struct node *ptr1 = (this->top);
    while(ptr1->id != n->id)
    {
        ptr1 = ptr1->next;
    }
    cout<<"\n showing details for contributor id : "<< ptr1->id<<endl;
    cout<<"contributor name : "<< ptr1->name<<endl;
    cout<<"contributor city : "<< ptr1->city<<endl;
    cout<<"contributor country : "<< ptr1->country<<endl;
    cout<<"contributor phone : "<< ptr1->phone<<endl;
    cout<<"contribution amount: "<< ptr1->contribution<<endl;
    cout<<" -> \n";

}
void linkedList:: print(int id)
{
    cout<<" --------------   ----------------"<< endl ;
    cout<<"\n showing details for contributor id : "<< id<<endl;
    cout<<" --------------   ----------------"<< endl ;
    struct node *ptr1 = (this->top);

    while(ptr1->id != id)
    {
        if( ptr1 ->next == NULL)
        {
            cout<<"\n contributor id : "<< id<<"does not exist"<< endl;
            break;
        }
        ptr1 = ptr1->next;
    }

    cout<<"contributor name : "<< ptr1->name<<endl;
    cout<<"contributor city : "<< ptr1->city<<endl;
    cout<<"contributor country : "<< ptr1->country<<endl;
    cout<<"contributor phone : "<< ptr1->phone<<endl;
    cout<<"contribution amount: "<< ptr1->contribution<<endl;
    cout<<" -> \n";

}
void linkedList:: printAll()
{
    struct node *temp = this->top;
    while(temp != NULL)
    {
        this->printAnElemenet(temp);
        temp = temp->next;
    }
}

// Function to insert a given node in a sorted linked list
void sortedInsert(struct node**, struct node*);

// function to sort a singly linked list using insertion sort
void insertionSort(struct node **head_ref)
{
    // Initialize sorted linked list
    struct node *sorted = NULL;

    // Traverse the given linked list and insert every node to sorted
    struct node *current = *head_ref;
    while (current != NULL)
    {
        // Store next for next iteration
        struct node *next = current->next;

        // insert current in sorted linked list
        sortedInsert(&sorted, current);

        // Update current
        current = next;
    }

    // Update head_ref to point to sorted linked list
    *head_ref = sorted;
}
void sortedInsert(struct node** head_ref, struct node* new_node)
{

    struct node* current;
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->id >= new_node->id)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = *head_ref;
        while (current->next!=NULL &&
               current->next->id < new_node->id)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void sortedInsertByName(struct node** head_ref, struct node* new_node);
void insertionSortByName(struct node **head_ref)
{
    // Initialize sorted linked list
    struct node *sorted = NULL;

    // Traverse the given linked list and insert every node to sorted
    struct node *current = *head_ref;
    while (current != NULL)
    {
        // Store next for next iteration
        struct node *next = current->next;

        // insert current in sorted linked list
        sortedInsertByName(&sorted, current);

        // Update current
        current = next;
    }

    // Update head_ref to point to sorted linked list
    *head_ref = sorted;
}
// function to insert a new_node in a list.
