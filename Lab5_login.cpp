/*
                                                Lab - #05
                                        Code written by Himanshu Gupta
                                     Completion of Code Date - 04/11/2022

Working-
    1-  User can issue books from library.
    2-  User can only issue one copy of one book.
    3-  Atmost three different book user can issue.
    4-  If user returns book after more then fifteen days then they have to pay fine 10 rupees for extra each days.

Working of fuctions
1-  Functions of Library Class
        1-  Constructor
        2-  Node * ret_curr_node()
                it will return head of library books
        3-  CreateLibrary()
                It creat library and call function to creatCurrNode
        4-  CrearCurr_Node()
                It creats a node of some data for Library
        5-  return_book()
                It takes some data then check for fine and delete from issue book and add book in the library
        6-  search()
                It return true if book present in the book otherwise false or issued to someone else
        other function are understandable.

2-  Functions of User Class
        1-  Constructor
        2-  node * ret_issue_book()
                it will return head  of issued book linked list data structure
        3-  getNode()
                creats node for issue book
        4-  creatlist()
                creats a linkedlist for storing data of users
        5-  issue()
                issue books

*/

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string.h>
#include <ctime>
#include <iomanip>
using namespace std;
const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};

typedef struct S_date
{
    int d, m, y;
} S_date;

ofstream out("Output.txt");

// For Library , Structure of Node

class Node
{
public:
    string title;
    string author;
    string publiser;
    int n_copy;
    int position;
    Node *next;
    Node(string title_name, string author_name, string publiser_name, int position_no, int no_copy)
    {
        title = title_name;
        author = author_name;
        publiser = publiser_name;
        position = position_no;
        n_copy = no_copy;
        next = NULL;
    }
};

// Class node for storing issued book

class node
{
public:
    string title;
    string author;
    string user_name;
    string date;
    int n_copy;

    node *next;

    node(string title_name, string author_name, string student, string date1, int no_copy)
    {
        title = title_name;
        author = author_name;
        user_name = student;
        date = date1;
        n_copy = no_copy;
        next = NULL;
    }
};

// class node for login of user and admin

class node1
{
public:
    string user_name;
    string password;
    node1 *next;
    node1(string user, string pass)
    {
        user_name = user;
        password = pass;
    }
};

class login1
{
    node1 *user_head;
    node1 *admin_head;

public:
    login1()
    {
        user_head = NULL;
        admin_head = NULL;
    }
    bool login(string name, string pwd);
    bool login(string name, string pwd, string xyz);
    void registerUser(string name, string pwd);
    void creat_admin_list(string xyz, string abc);
};

bool login1 ::login(string name, string pwd)
{
    node1 *tempxxx = user_head;
    while (tempxxx != NULL)
    {
        if (tempxxx->user_name == name && tempxxx->password == pwd)
        {
            cout << "Login succesfull " << endl;
            return true;
        }
        else if (tempxxx->user_name == name)
        {
            cout << "Incurrect Password \nPlease try again with currect password " << endl;
            return false;
        }
        else
        {
            return 0;
        }

        tempxxx = tempxxx->next;
    }
}

bool login1 ::login(string name, string pwd, string xyz)
{
    node1 *tempxxx = admin_head;
    while (tempxxx != NULL)
    {
        if (tempxxx->user_name == name && tempxxx->password == pwd)
        {
            cout << "Login succesfull " << endl;
            return true;
        }
        else if (tempxxx->user_name == name)
        {
            cout << "Incurrect Password \nPlease try again with currect password " << endl;
            return false;
        }
        else
        {
            return false;
        }
        tempxxx = tempxxx->next;
    }
}

void login1::registerUser(string name, string pwd)
{
    node1 *ptr = user_head;
    node1 *newNode = new node1(name, pwd);
    newNode->next = NULL;
    if (ptr == NULL)
    {
        user_head = newNode;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    cout << "Registered Successfully " << endl;
}

// class User details
class Library;
class User
{

    node *issue_book;
    S_date *date1;

public:
    User();
    node *ret_issue_node();
    node *getNode(string, string, string, string, int);
    void createList(string, string, string, string, int);
    void Display_Issued_book();
    void issue(Library ob, User ob2);
    bool searchUser(string, string, string);
    void delete_from_issue_book(string, string);
    int decrease_no_of_copy(string, string, string);
    void checkFine(string, string, string, string);
};
// Constructor User name;
User::User()
{
    issue_book = NULL;
}

// Class Library

class Library
{
    Node *curr_book;

public:
    Library();
    Node *ret_curr_node();
    void createLibrary();
    Node *createNode_current();
    void return_book(User ob);
    bool search(string, string);
    void increase_no_of_copy(string, string, int);
    void add_books(Library ob);
    void display();
};

// Constructor Library

Library::Library()
{
    curr_book = NULL;
}

void login1 ::creat_admin_list(string xyz = "Himanshu", string abc = "Gupta")
{
    // node1 admin_head;
    node1 *newNode1 = new node1(xyz, abc);
    node1 *newNode2 = new node1(xyz, abc);
    newNode1->user_name = xyz;
    newNode1->password = abc;
    xyz = xyz + " " + abc;
    abc = abc + " " + xyz;
    newNode2->user_name = xyz;
    newNode2->password = abc;
    newNode2->next = NULL;
    newNode1->next = newNode2;
    admin_head = newNode1;
    
}

// Class Date

class Date
{
public:
    string getDate();
    int countLeapYears(S_date);
    int getDifference(S_date, S_date);
    int return_No_of_days(string, string);
};

// Openning Text file for taking input
ifstream inp("Library.txt");

node *User::ret_issue_node()
{
    return issue_book;
}
Node *Library::ret_curr_node()
{
    return curr_book;
}

// Creating Node for Library

Node *Library::createNode_current()
{
    string title_name, author_name, publiser_name, position_no, no_copy;
    // Making Library by Taking data from Library txt file
    getline(inp, title_name);
    getline(inp, author_name);
    getline(inp, publiser_name);
    getline(inp, position_no);
    getline(inp, no_copy);
    int position_n = stoi(position_no);
    int no_cop = stoi(no_copy);

    Node *newNode = new Node(title_name, author_name, publiser_name, position_n, no_cop);
    newNode->title = title_name;
    newNode->author = author_name;
    newNode->publiser = publiser_name;
    newNode->position = position_n;
    newNode->n_copy = no_cop;
    newNode->next = NULL;

    return newNode;
}

// Creating a Library

void Library::createLibrary()
{
    int x = 6;

    while (x--)
    {
        Node *ptr1;
        ptr1 = createNode_current();
        if (curr_book == NULL)
        {
            curr_book = ptr1;
        }
        else
        {
            Node *ptr = curr_book;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = ptr1;
        }
    }
    inp.close();
}

Node *getNew_Node(string titlename, string author_name, string publiser, int n_copy)
{
    int position;
    cout << "Enter rack no. in library " << endl;
    cin >> position;
    Node *newNode = new Node(titlename, author_name, publiser, n_copy, position);
    newNode->author = author_name;
    newNode->title = titlename;
    newNode->position = position;
    newNode->publiser = publiser;
    newNode->n_copy = n_copy;
    newNode->next = NULL;
    return newNode;
}

void Library::add_books(Library l)
{
    Node *ptr = curr_book;
    int n_copy;
    string titlename, author_name, publiser;
    cout << "Enter some details for adding books in library " << endl;
    cout << "Enter title of book " << endl;
    getline(cin >> ws, titlename);
    cout << "Enter author name " << endl;
    getline(cin >> ws, author_name);
    cout << "Enter publiser name " << endl;
    getline(cin >> ws, publiser);
    cout << "Enter no. of copies of this book " << endl;
    cin >> n_copy;
    bool x = l.search(titlename, author_name);
    if (!x)
    {
        Node *newNode = getNew_Node(titlename, author_name, publiser, n_copy);
        if (ptr == NULL)
        {
            ptr = newNode;
            curr_book = ptr;
        }
        else
        {
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = newNode;
        }
    }
    else
    {
        l.increase_no_of_copy(titlename, author_name, n_copy+1);
    }

    cout << "Book added successfully" << endl;
}

// This function search for book present in library or not

bool Library::search(string titl_name, string autho_name)
{
    Node *ptr = curr_book;
    int found = 0;
    while (ptr != NULL)
    {
        cout<<"for seach"<<endl;
        if (ptr->title == titl_name && ptr->author == autho_name)
        {
            if (ptr->n_copy != 0)
            {
                ptr->n_copy -= 1;
                return true;
            }
            else
            {
                cout << "Book is present in library but issued to some body";
                found = 1;
                return false;
            }
        }
        ptr = ptr->next;
    }
    if (found == 0)
        out << "Book Title Name " << titl_name << " and Author Name " << autho_name << " is not found in library." << endl;
    return false;
}

// this function display the data of Total books present in the library

void Library::display()
{

    Node *ptr1 = curr_book;
    if(curr_book != NULL)
    out << left << setw(25) << "Title Name" << left << setw(20) << "A. Name" << setw(10) << "Publ. Name"
        << left << setw(10) << "Position" << left << setw(10) << "# Copies" << endl;
    out << endl;
    while (ptr1 != NULL)
    {
        out << left << setw(25) << ptr1->title << left << setw(20) << ptr1->author << left << setw(10) << ptr1->publiser << left << setw(10) << ptr1->position << left << setw(10) << ptr1->n_copy << endl;
        ptr1 = ptr1->next;
    }
    out << endl;
}

// the work of this function is creating a Linked List data structure for storing the issued books to the user

node *User ::getNode(string title_name, string author_name, string user_name, string date, int NoOfCopy)
{
    node *newNode = new node(title_name, author_name, user_name, date, NoOfCopy);
    newNode->title = title_name;
    newNode->author = author_name;
    newNode->user_name = user_name;
    newNode->n_copy = NoOfCopy;
    newNode->date = date;
    newNode->next = NULL;
    return newNode;
}

void User::createList(string title_name, string author_name, string user_name, string date, int NoOfCopy)
{

    node *newNode = getNode(title_name, author_name, user_name, date, NoOfCopy);

    if (issue_book == NULL)
    {
        issue_book = newNode;
    }
    else
    {
        node *ptr = issue_book;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newNode;
    }
}

// The work of next function is it will display total books issued to the student

void User::Display_Issued_book()
{
    node *ptr1 = ret_issue_node();
    if (ptr1 != NULL)
    {
        out << "The Data Of issued Book from Institution Library to the students-\n"
            << endl;
        out << left << setw(25) << "Title Name" << left << setw(20) << "Auth. Name" << left << setw(15) << "Date"
            << left << setw(15) << "S. Name" << left << setw(20) << "# Copies" << endl;
        out << endl;
    }
    else
    {
        out << "\nThere is no book issued to any student yet " << endl;
    }

    while (ptr1 != NULL)
    {
        out << left << setw(25) << ptr1->title << left << setw(20) << ptr1->author << left << setw(15) << ptr1->date << left << setw(15) << ptr1->user_name << left << setw(20) << ptr1->n_copy << endl;
        ptr1 = ptr1->next;
    }
    cout << endl;
    return;
}

// this function returns true if
//    all condition satisfied by the library managment
// else
//    return false

bool User::searchUser(string s1, string s2, string s3)
{
    // ofstream out("Output.txt");
    node *ptr = issue_book;
    int count = 0;
    if (ptr == NULL)
    {
        return true;
    }
    else
    {
        while (ptr != NULL)
        {
            if (ptr->user_name == s3)
                count++;
            ptr = ptr->next;
        }
        ptr = issue_book;
        if (count < 3)
        {
            while (ptr != NULL)
            {
                if (ptr->title == s1 && ptr->author == s2 && ptr->user_name == s3)
                {
                    if (ptr->n_copy == 1)
                        cout << "This book already issued to you." << endl;
                    else
                        cout << "Although you have returnd this book, this book cannot be issued to you again" << endl;
                    cout << endl;
                    return false;
                }
                ptr = ptr->next;
            }
            return true;
        }
        else
        {
            cout << "\nYou have already issued " << count << " books,\nso more books cannot be issued to you, until you will not return those books" << endl;
            return false;
        }
    }
}

// returns current date function

string Date::getDate()
{
    time_t now = time(0);
    tm *item = localtime(&now);
    int y1 = 1900 + item->tm_year;
    int m1 = 1 + item->tm_mon;
    int d1 = item->tm_mday;
    string str1 = to_string(y1);
    string str2 = to_string(m1);
    string str3 = to_string(d1);
    string x("/");
    string z("0");
    if (m1 < 10)
        str2 = z.append(str2);
    if (d1 < 10)
    {
        str3 = z.append(str3);
    }
    str3 = str3.append(x);
    str3 = str3.append(str2);
    str3 = str3.append(x);
    str3 = str3.append(str1);
    return str3;
}

// issue function
void User::issue(Library l, User u)
{
    // User u;
    Date d;

    string title_name, author_name;
    cout << "Enter the title of the book" << endl;
    getline(cin >> ws, title_name);
    cout << "Enter the author of the book" << endl;
    getline(cin >> ws, author_name);
    bool x = l.search(title_name, author_name);
    if (x)
    {
        string user_name;
        string date1;
        // Enter Your Name
        //  searching user that if they have issued not more than 3 three books and and not
        //  want to issue same copy of issued book;
        cout << "Enter your name" << endl;
        getline(cin >> ws, user_name);
        bool y = searchUser(title_name, author_name, user_name);
        if (y)
        {
            date1 = d.getDate();
            createList(title_name, author_name, user_name, date1, 1);
            cout << "Book issued Successfully" << endl
                 << endl;
        }
    }
}

int Date ::countLeapYears(S_date da)
{
    int years = da.y;

    // Check if the current year needs to be
    // considered for the count of leap years
    // or not
    if (da.m <= 2)
        years--;

    // An year is a leap year if it
    // is a multiple of 4,
    // multiple of 400 and not a
    // multiple of 100.
    return years / 4 - years / 100 + years / 400;
}

// This function returns number of
// days between two given dates
int Date ::getDifference(S_date dt1, S_date dt2)
{
    // COUNT TOTAL NUMBER OF DAYS
    // BEFORE FIRST DATE 'dt1'
    // cout<<"dt1 = "<<dt1.d<<"/"<<dt1.m<<"/"<<dt1.y<<endl;
    // cout<<"dt2 = "<<dt2.d<<"/"<<dt2.m<<"/"<<dt2.y<<endl;
    // initialize count using years and day
    long int n1 = dt1.y * 365 + dt1.d;
    // Add days for months in given date
    for (int i = 0; i < dt1.m - 1; i++)
        n1 += monthDays[i];

    // Since every leap year is of 366 days,
    // Add a day for every leap year
    n1 += countLeapYears(dt1);

    // SIMILARLY, COUNT TOTAL NUMBER OF
    // DAYS BEFORE 'dt2'

    long int n2 = dt2.y * 365 + dt2.d;
    for (int i = 0; i < dt2.m - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);

    // return difference between two counts
    return (n1 - n2);
}

int Date ::return_No_of_days(string date1, string date2)
{
    char day1[20], day2[20], mon1[20], mon2[20], year1[20], year2[20];

    date1.copy(day1, 2, 0);
    date1.copy(mon1, 2, 3);
    date1.copy(year1, 4, 6);
    date2.copy(day2, 2, 0);
    date2.copy(mon2, 2, 3);
    date2.copy(year2, 4, 6);

    int d1 = atoi(day1);
    int m1 = atoi(mon1);
    int y1 = atoi(year1);
    int d2 = atoi(day2);
    int m2 = atoi(mon2);
    int y2 = atoi(year2);

    S_date dt1 = {d1, m1, y1};
    S_date dt2 = {d2, m2, y2};

    return getDifference(dt1, dt2);
}

// this function increase the number of copyies of book when book retruns

void Library::increase_no_of_copy(string title_name, string author_name, int x = 1)
{
    Node *ptr = curr_book;
    while (ptr != NULL)
    {
        if (ptr->title == title_name && ptr->author == author_name)
        {
            ptr->n_copy = ptr->n_copy + x ;
            break;
        }
        ptr = ptr->next;
    }
}

// this function checks for fine

void User::checkFine(string title_name, string author_name, string user_name, string date)
{
    node *ptr1 = issue_book;
    Date d;
    if (issue_book == NULL)
    {
        cout << "Issue book is null" << endl;
    }
    while (ptr1 != NULL)
    {
        if (ptr1->title == title_name && ptr1->author == author_name && ptr1->user_name == user_name)
        {
            int days = d.return_No_of_days(date, ptr1->date);
            if (days > 15)
            {
                out << "You have return book after more than 15 days so you have pay fine for " << days - 15 << " extra days." << endl;
                out << "Fine(10 * no. of  extra days) = " << (days - 15) * 10 << " rupeese only/- ." << endl;
                out << "You can pay fine online thought PHONE PAY , Google Pay , and Net Banking or directly to the library man." << endl;
            }
            out << "Your Book Returned to the Library Successfully." << endl;
            break;
        }
        ptr1 = ptr1->next;
    }
}

int User ::decrease_no_of_copy(string title_name, string author_name, string user_name)
{
    node *ptr = issue_book;
    while (ptr != NULL)
    {
        if (ptr->title == title_name && ptr->author == author_name && ptr->user_name == user_name)
        {
            ptr->n_copy = 0;
            return 1;
        }
        ptr = ptr->next;
    }
    return 0;
}

// This function Return The book to the library and delete book from issue book data structure

void Library::return_book(User u)
{
    string title_name, author_name, user_name, date1;
    cout << "For Return Enter these Detailes- " << endl;
    cout << "Enter the title of the book" << endl;
    getline(cin >> ws, title_name);

    cout << "Enter the author of the book" << endl;
    getline(cin >> ws, author_name);

    cout << "Enter your name" << endl;
    getline(cin >> ws, user_name);

    cout << "Todays date in dd/mm/yyyy formet" << endl;
    getline(cin, date1);

    int x = u.decrease_no_of_copy(title_name, author_name, user_name);
    if (x)
    {
        u.checkFine(title_name, author_name, user_name, date1);
        increase_no_of_copy(title_name, author_name);
    }
    else
    {
        cout << "This book is not issued to you " << endl;
    }
    // u.delete_from_issue_book(title_name, author_name , user_name);
}

// Driver Code

int main()
{
    Library l;
    User u;
    login1 logi;
    int stpPoint = 1;
    int num;
    int x = 0, y = 0, z = 0;
    
    l.createLibrary();
    out << "These are the Books Present In the Library-" << endl;
    l.display();

    cout << "Enter 1 for user and 2 for admin login." << endl;
    cin >> num;

    logi.creat_admin_list();

    if (num == 1)
    {
        string username1;
        string password1;
        cout << "Enter your user_name " << endl;
        cin >> username1;
        cout << "Enter your password " << endl;
        cin >> password1;
        bool xy = logi.login(username1, password1);
        if (xy)
            y = 1;
        else
        {
            cout << "If you want to register yourself in this library then input non zero number else zero" << endl;
            int choice;
            cin >> choice;
            if (choice){
                logi.registerUser(username1, password1);
                y = 1;
                }
            else
                cout << "Thanks coming for in this library" << endl;
        }
    }
    else if (num == 2)
    {
        string username1;
        string password1;
        string xyz;
        cout << "Enter your admin_name " << endl;
        cin >> username1;
        cout << "Enter your password " << endl;
        cin >> password1;
        bool xe = logi.login(username1, password1, xyz);
        if (xe)
            z = 1;
        else
            z = 0;
    }

    if (y)
    {
        cout << "You are login as a user " << endl;
        while (stpPoint)
        {
            int choice;
            out << "\nEnter Number as per your Choice-" << endl;
            out << "1. Issue book from Library" << endl;
            out << "2. Display Total Book Present in Library at present time" << endl;
            out << "3. Return a book." << endl;

            cout << "Enter no. which operation you want " << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                u.issue(l, u);
                break;
            }

            case 2:
            {
                l.display();
                break;
            }
            case 3:
            {
                l.return_book(u);
                break;
            }
            default:
            {
                cout << "You Have entered invalid number." << endl;
            }
            break;
            }
            cout << "If You want to continue then enter Non zero Number-" << endl;
            cin >> stpPoint;
        }
    }

    if (z)
    {
        cout << "You are login as a admin " << endl;
        stpPoint = 1;
        while (stpPoint)
        {
            int choice;
            out << "\nEnter Number as per your Choice-" << endl;
            out << "1. Display Total Book Present in Library at present time" << endl;
            out << "2. Display Issued Book to the student." << endl;
            out << "3. Add books in library " << endl;
            cout << "Enter no. which operation you want " << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                l.display();
                break;
            }

            case 2:
            {
                u.Display_Issued_book();
                break;
            }
            case 3:
            {
                l.add_books(l);
                break;
            }
            default:
            {
                cout << "You Have entered invalid number." << endl;
            }
            break;
            }
            cout << "If You want to continue then enter Non zero Number-" << endl;
            cin >> stpPoint;
        }
    }
    return 0;
}
