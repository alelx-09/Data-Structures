#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <cstdlib>


using namespace std;

void menu();
void load_exam();
void create_exam();
void display_question_set(string Q_set);
void submenu();
int choose=0;

int main()
{
    menu();
    return 0;
}

void menu()
{
    cout << "\n___QUESTIONS___" << endl;
    cout << "(1) Load an Exam" << endl;
    cout << "(2) Write Question Set" << endl;
    cout << "(3) Quit" << endl;
    cout << "Choice: ";
    cin >> choose;

    switch(choose)
    {
    case 1:
        system("CLS");
        load_exam();
        break;
    case 2:
        system("CLS");
        create_exam();
        break;
    case 3:
        system("CLS");
        cout << "THANK YOU" << endl;
        break;
    }
}

void load_exam()
{
    system("CLS");
    string str;
    ifstream myfile ("../text/Qset.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,str) )
            cout << str << endl;
        myfile.close();
        string Qset;
        cout << "Choice: ";
        cin >> Qset;
        display_question_set(Qset);
    }

    else
    {
        cout << "Unable to Load Question Set"<< endl;
        cout << "Contact Admin" << endl;
    }

}

void display_question_set(string Q_set)
{
    system("CLS");
    string str;
    string qtxt="../text/"+Q_set+".txt";
    int n = qtxt.length();
    char path[n+1];
    strcpy(path, qtxt.c_str());

    ifstream myfile (path);
    if (myfile.is_open())
    {
        while ( getline (myfile,str) )
            cout << str << endl;
        myfile.close();
        submenu();
    }

    else
    {
        cout << "No set Found"<< endl;
        cout << "Create One ?" << endl;
        cout << "(1) Yes\n"<<"(2) No\n"<< endl;
        cin >> choose;
        switch(choose)
        {
        case 1:
            system("CLS");
            create_exam();
            break;
        case 2:
            break;
        }
    }

}

void create_exam()
{
    system("CLS");
    cout << "\nCREATE A QUESTION SET" << endl;
    cout << "\n\nSET NAME: ";
    string Q_set_name;
    fflush(stdin);
    getline(cin,Q_set_name);
    cout << "QUESTIONS: ";


    ofstream myfile ("../text/Qset.txt",std::ofstream::out | std::ofstream::app);
    ifstream num ("../text/Qnum.txt");

    string qNum;
    fflush(stdin);
    getline(num,qNum);
    myfile << "(" << qNum << ")" << " " << Q_set_name << endl;
    num.close();
    myfile.close();
    string filepath="../text/"+qNum+".txt";

    fstream newQset;
    char newfile[100];
    strcpy(newfile, filepath.c_str());
    newQset.open(newfile,ios::out);
    newQset << flush;
    newQset.close();

    ofstream file (newfile);
    fflush(stdin);

    if (file.is_open())
    {
        string str;
        while(getline(cin,str))
        {
            if(str.empty())
                break;

            file << str << endl;
        }
        file.close();

        ofstream update_num ("../text/Qnum.txt");
        int updateNum = qNum[0]-48;
        update_num << ++updateNum << endl;
        update_num.close();
    }
    else
        cout << "Unable to open file";

        submenu();

}

void submenu()
{
    cout << "\n\n[1] Back to Main";
    cout << "\n\n[2] Quit" << endl;
    cin >> choose;
    switch(choose)
    {
    case 1:
        system("cls");
        menu();
        break;

    case 2:
        system("cls");
        cout << "THANK YOU" << endl;
        break;
    }
}
