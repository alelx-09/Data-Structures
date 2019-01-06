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
        void printAnElemenet(node *n);  // to show a single element
        void print(int id); // to print a single element matching the id
        void printAll(); // to print all element

};


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
    cout<<" --------------   ----------------"<< endl ;
    struct node *temp = this->top;
    while(temp != NULL)
    {
        this->printAnElemenet(temp);
        temp = temp->next;
    }
    cout<<" --------------   ----------------"<< endl ;
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
// Function to insert a given node in a sorted linked list
void sortedInsert(struct node**, struct node*);

// function to sort a singly linked list using insertion sort
void insertionSort(struct node **head_ref)
{
    cout<<"-----------------## ---------------\n" ;
    cout<<" performing insertion sort \n" ;
    // Initialize sorted linked list
    struct node *sorted = NULL;

    // Traverse the given linked list and insert every
    // node to sorted
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

/* function to insert a new_node in a list. Note that this
  function expects a pointer to head_ref as this can modify the
  head of the input linked list (similar to push())*/
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

void add(struct node** head_ref)
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
int main()
{

     struct node *a = NULL;
     linkedList LL;

    //readfile
    fstream file;
    file.open("contributors.csv");
    if( !file.is_open())
    {
        cout<<"can not read file \n";
    }

    string line;

    int rows = 0;
    while (getline( file, line,'\n'))
	{
	  istringstream templine(line);

	  string id;
	  int columns=0, IDasKey;

	  node *ptr=new node;

	  while (getline( templine, id,','))
	  {
	    if(columns==0)
            ptr->name=id;

        else if(columns==1)
            ptr->city=id;

        else if(columns==2)
            ptr->country=id;

        else if(columns==3)
            ptr->phone=id;

        else if(columns==4)
        {
            double tempDbl = atof(id.c_str());
            ptr->contribution= tempDbl;
        }

        else if(columns==5)
        {
            IDasKey = atoi(id.c_str());
            ptr->id= IDasKey;

            // add this inputted note to the linked list
            LL.addtoLL(ptr);
            //sortedInsert(&LL.top, ptr);
        }

	    columns++;
	  }

	  rows++;

	}


    file.close();

    cout<<" before sort showing the list after reading input file contributors.csv \n";
    LL.printAll();

/**

    cout<<" now sorting\n";
    insertionSort(&LL.top);

    cout<<" after sorting showing \n";
    LL.printAll();
**/
    while(1)
    {
        cout<<"\n-----------------------------------------------------------";
        cout<<"\n\t\t Insertion Sort on LINKED LIST \n\n";
        cout<<"1:Add \n 2:Print single contributor \n 3:DISPLAY LINKED LIST\n 4: sort list \n 5:EXIT";
        cout<<"\nEnter your choice(1-5): ";

        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
                //add(&LL.top);
                LL.add(&LL.top);
                break;

            case 2:
                int idToPrint;
                cout<<"enter the contributor id to print info \n";
                cin>> idToPrint;
                LL.print(idToPrint);
                break;

            case 3:
                LL.printAll();
                break;

            case 4:
                insertionSort(&LL.top);
                cout<<"   ****   after sorting, displaying the list:    ****   "<< endl ;
                LL.printAll();
                break;

            case 5:
                return 0;
                break;
            default:
                cout<<"\nPlease enter correct choice(1-5)!!";
                break;
        }
    }

    cout<<"ends \n" ;
}




