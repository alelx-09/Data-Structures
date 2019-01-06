#include<iostream>
#include <iomanip>
#include<string>
using namespace std;
int main()
{
    string name[4];
    float gpa[4];

    for (int i = 0; i < 4; i++)
    {
        cout<<"Enter name(Last, First) of student "<<i+1<<" : ";
        if(i!=0)
            cin.ignore();
        getline(cin, name[i]);
        cout<<"Enter gpa of student "<<i+1<<" : ";
        cin >> gpa[i];
    }

    for (int i = 0; i < 4; i++)
    {
        cout<<name[i]<<' '<<setprecision(2)<<fixed<<gpa[i]<<endl;
    }

}