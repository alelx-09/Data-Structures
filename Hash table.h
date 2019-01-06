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

// Creating a class STACK
class stack
{
    public:
        struct node *top;
        int collisonId;
        stack() // constructor
        {
            top=NULL;
            collisonId=0;
        }

        stack( stack &x)
        {
            top = x.top;
        }

        stack( int collisonId)
        {
            this->collisonId = collisonId;
        }

        void push(int id); // to insert an element
        void pop();  // to delete an element
        void show(); // to show the stack
        void setCollisionId(int s){ this->collisonId = s;}
};
// PUSH Operation
void stack::push(int id)
{
    int value1;
    double value2;
    struct node *ptr;

    cout<<"\nPUSH Operation for contributor id : "<< id << endl;

    ptr=new node;

    ptr->id=id;


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

    ptr->next=NULL;

    if(top!=NULL)
        ptr->next=top;
    top=ptr;

    cout<<"\nNew Contributor is inserted to the stack!!! \n";

}
// POP Operation
void stack::pop()
{
    struct node *temp;
    if(top==NULL)
    {
        cout<<"\nThe stack is empty!!!";
    }
    temp=top;
    top=top->next;
    cout<<"\n POP Operation........\n Poped Contributor id is "<<temp->id << endl;
    delete temp;
}

// Show stack
void stack::show()
{
    cout<<" --------------   ----------------"<< endl ;
    struct node *ptr1=top;
    if(top==NULL)
    {
        cout<<"\nThe stack #"<< this->collisonId <<" is empty!!!\n";
    }
    else
    {
        int elements=0;
    cout<<"\n The stack #"<< this->collisonId <<" is : \n";

    while(ptr1!=NULL)
    {
        elements++;
        cout<<"contributor id : "<< ptr1->id<<endl;
        cout<<"contributor name : "<< ptr1->name<<endl;
        cout<<"contributor city : "<< ptr1->city<<endl;
        cout<<"contributor country : "<< ptr1->country<<endl;
        cout<<"contributor phone : "<< ptr1->phone<<endl;
        cout<<"contribution amount: "<< ptr1->contribution<<endl;
        cout<<" -> \n";

        ptr1=ptr1->next;
    }
    cout<<" --------------   ----------------"<< endl ;
    cout<<"total elements in stack  #"<< this->collisonId <<" is : "<<elements <<endl;

    }
}

class hash_table
{
    public:

        struct stack bucket1;
        struct stack bucket2;
        struct stack bucket3;
        struct stack bucket4;
        struct stack bucket5;

        void show();


        hash_table()
        {

            bucket1.setCollisionId(1);
            bucket2.setCollisionId(2);
            bucket3.setCollisionId(3);
            bucket4.setCollisionId(4);
            bucket5.setCollisionId(5);
        }

};

void hash_table:: show()
{
    cout<<" --------------  # #  ----------------"<< endl ;
    cout<<" showing the hash table and its 5 buckets \n" ;
    bucket1.show();
    bucket2.show();
    bucket3.show();
    bucket4.show();
    bucket5.show();

}
int hash_function(int key) //returns the hash_bucket index for this key
{
    //return (rand() + key% 5 ) % 5;
    return key % 5;
}
int main()
{

    cout<<"\n\t\t STACK USING LINKED LIST \n\n";

    hash_table ht;
    stack s;


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

	  string data;
	  int columns=0, IDasKey;

	  node *ptr=new node;

	  while (getline( templine, data,','))
	  {
	    if(columns==0)
            ptr->name=data;

        else if(columns==1)
            ptr->city=data;

        else if(columns==2)
            ptr->country=data;

        else if(columns==3)
            ptr->phone=data;

        else if(columns==4)
        {
            double tempDbl = atof(data.c_str());
            ptr->contribution= tempDbl;
        }

        else if(columns==5)
        {
            IDasKey = atoi(data.c_str());
            ptr->id= IDasKey;
        }

	    columns++;
	  }

	  rows++;

	  int hashedIndex = hash_function(IDasKey);

      if(hashedIndex==0)
      {
            ptr->next=NULL;
            if(ht.bucket1.top!=NULL)
                ptr->next= ht.bucket1.top;
            ht.bucket1.top=ptr;


      }
      else if(hashedIndex==1)
      {
            ptr->next=NULL;
            if(ht.bucket2.top!=NULL)
                ptr->next= ht.bucket2.top;
            ht.bucket2.top=ptr;
      }
      else if(hashedIndex==2)
      {
            ptr->next=NULL;
            if(ht.bucket3.top!=NULL)
                ptr->next= ht.bucket3.top;
            ht.bucket3.top=ptr;
      }
      else if(hashedIndex==3)
      {
            ptr->next=NULL;
            if(ht.bucket4.top!=NULL)
                ptr->next= ht.bucket4.top;
            ht.bucket4.top=ptr;

      }
      else if(hashedIndex==4)
      {
            ptr->next=NULL;
            if(ht.bucket5.top!=NULL)
                ptr->next= ht.bucket5.top;
            ht.bucket5.top=ptr;

      }
	}

	cout<<" now showing all the hash buckets of the stack \n" ;
	ht.show();

    file.close();

    cout<<"\n\n\n";
    while(1)
    {
        cout<<"\n\n 1:PUSH\n2:POP\n3:DISPLAY Linked list\n4:EXIT";
        cout<<"\nEnter your choice(1-4): ";
        int choice;
        cin>>choice;

        if(choice == 1)
        {
                int contributorId;
                cout<<"enter the contributor id \n";
                cin>> contributorId;
                int  hashed_Index = hash_function(contributorId);

                  if(hashed_Index==0)
                  {
                        ht.bucket1.push(contributorId);
                  }
                  else if(hashed_Index==1)
                  {
                        ht.bucket2.push(contributorId);
                  }
                  else if(hashed_Index==2)
                  {
                        ht.bucket3.push(contributorId);
                  }
                  else if(hashed_Index==3)
                  {
                        ht.bucket4.push(contributorId);
                  }
                  else if(hashed_Index==4)
                  {
                        ht.bucket5.push(contributorId);
                  }
        }
        else if( choice ==2 )
        {
            int bucketNum;
            cout<<"enter the bucket # to pop from \n";
            cin>> bucketNum;


              if(bucketNum==1)
              {
                    ht.bucket1.pop();
              }
              else if(bucketNum==2)
              {
                    ht.bucket2.pop();
              }
              else if(bucketNum==3)
              {
                    ht.bucket3.pop();
              }
              else if(bucketNum==4)
              {
                    ht.bucket4.pop();
              }
              else if(bucketNum==5)
              {
                    ht.bucket5.pop();
              }
              cout<<"\n \t popped from bucket # "<< bucketNum<< endl ;

        }

        else if(choice == 3){ ht.show();}
        else if( choice == 4){ return 0;}

        else cout<<"\nPlease enter correct choice(1-4)!!";

    }
    cout<<"ends \n" ;
}
