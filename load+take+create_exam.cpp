#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <cstdlib>


using namespace std;


void menu();
void submenu();
void load_exam();
void create_exam();
string update_entry(string Q_set_name);
void update_index();
void display_question_set(string Q_set);

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

    string anstext="../text/"+Q_set+"ans.txt";
    int m = anstext.length();
    char path2[m+1];
    strcpy(path2, anstext.c_str());

    ifstream myfile (path);
    ifstream ans(path2);

    int score=0,total=0;
    if (myfile.is_open())
    {
        while ( getline (myfile,str) )
        {
            if(str=="EOQ")
            {
                cout << "[  Only write option. Ex. B  ]" <<endl;
                string uAns,myAns;
                cout << "Ans: ";
                fflush(stdin);
                getline(cin,uAns);
                cout << endl;
                cout << "Your Answer: " << uAns << endl;
                fflush(stdin);
                ans >> myAns;

                if(uAns==myAns)
                {
                    cout << "Your Answer is CORRECT!" <<endl;
                    score++;
                }
                else
                {
                    cout << "WRONG Answer! ";
                    cout << "Correct Answer is: " << myAns <<endl;

                }
                ++total;
                cout << endl;

            }
            else
                cout << str << endl;
        }
        cout << "Thank You\nThat's all for now" << endl;
        cout << "Your Score: " << score << " out of " << total << endl;
        submenu();
    }

    else
    {
        cout << "No set Found"<< endl;
        submenu();
    }
    ans.close();
    myfile.close();

}


void create_exam()
{
    system("CLS");
    cout << "\nCREATE A QUESTION SET" << endl;
    cout << "\n\nSET NAME: ";
    string Q_set_name;
    fflush(stdin);
    getline(cin,Q_set_name);

    string qNumber = update_entry(Q_set_name);
    string filepath="../text/"+qNumber+".txt";

    fstream newQset;
    char newfile[100];
    strcpy(newfile, filepath.c_str());
    newQset.open(newfile,ios::out);
    newQset << flush;
    newQset.close();

    string anstext="../text/"+qNumber+"ans.txt";
    int m = anstext.length();
    char path2[m+1];
    strcpy(path2, anstext.c_str());
    fstream ansfile;
    ansfile.open(path2,ios::out);
    ansfile << flush;
    ansfile.close();
    ofstream ans(path2,std::ofstream::out | std::ofstream::app);

    ofstream file (newfile);
    fflush(stdin);
    if (file.is_open())
    {
        file << "\n\t____" << Q_set_name << "____"<<endl << endl << endl;
        cout << "Number of Questions: ";
        int nQuestion;
        cin >> nQuestion;
        for(int i=1; i<=nQuestion; i++)
        {
            cout << "\n\nType of Question: \n(1)MCQ  (2)True/False" << endl;
            cout << "Choice: ";
            cin >> choose;
            string question,option;
            cout << "\nQuestion "<<i<<": ";
            fflush(stdin);
            getline(cin,question);
            file << "  Question " << i << ": "<< question<< endl;
            if(choose==1)
            {
                cout << "Number of Options: ";
                int nOption;
                cin >> nOption;
                char op='A';
                for(int j=0; j<nOption; j++)
                {
                    cout << op << ": ";
                    fflush(stdin);
                    getline(cin,option);
                    file <<"\t"<< op++ << ". " << option  << endl;
                }

            }
            else if(choose==2)
            {
                cout << "A" << ": True"<<endl;
                cout << "B" << ": False"<<endl;

                file <<"\t" << "A. True" << endl;
                file <<"\t" << "B. False"<< endl;

            }
            file << "EOQ" << endl;
            cout << "Correct Answer: ";
            string answer;
            cin >> answer;
            ans << answer << endl << endl;
            file << endl;
        }
    }
    else
        cout << "Unable to open file";
    ans.close();
    file.close();
    update_index();
    submenu();

}


void update_index()
{
    ifstream getCurrentIndex ("../text/Qnum.txt");
    int updateNum;
    getCurrentIndex >> updateNum;
    getCurrentIndex.close();

    ofstream index_increment ("../text/Qnum.txt");
    index_increment << ++updateNum << endl;
    index_increment.close();
}

string update_entry(string Q_set_name)
{
    ofstream myfile ("../text/Qset.txt",std::ofstream::out | std::ofstream::app);
    ifstream num ("../text/Qnum.txt");

    string qNum;
    fflush(stdin);
    getline(num,qNum);
    myfile << "(" << qNum << ")" << " " << Q_set_name << endl;
    num.close();
    myfile.close();
    return qNum;
}

void submenu()
{
    cout << "\n\n\t[1] Back to Main";
    cout << "\n\n\t[2] Quit" << endl;
    cout << "  Choice: ";

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
