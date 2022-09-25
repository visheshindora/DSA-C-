// ASSIGNMENT 1 (DSA)
// Name: Vishesh Indora
// Branch: ECE 
// SID: 21105056

#include <iostream>  
#include <string>
  
using namespace std;

//creating a class such that it contains name and age of the family member and pointers for the next and previous members of the family.
class Family
{
    public :
    Family *prev;
    string name; //for name of the member 
    int age;
    Family *next;

    Family(string name, int age)
    {
        this->name = name;
        this->age = age;
        this->prev = NULL;
        this->next = NULL;
    }

};


/*
Functions implemented in this assignment are-

1.Taking a doubly linked list as input.
2.Removing any member of the family from the list,users choice also given.
3.Printing a doubly linked list.
4.Family class(made for implementing doubly linked list)
*/


// By using this function user can specify the size of his/her family and then input the name and age of every member of the family.
Family *takeinputand_appendatlast()
{

    int n;
    cout << "Enter the size of the family : ";
    cin >> n;
    cout << endl;

    Family *head = NULL;
    Family *nxt = NULL;
    Family *previous = NULL;

    for (int i = 1; i <= n; i++)
    {
        string a;
        cout << "Enter " << i << "th Family Member Name : ";
        cin >> a;

        int age;
        cout << "Enter " << i << "th Family Member Age : ";
        cin >> age;

        Family *newmember = new Family(a, age);

        if (head == NULL)
        {
            head = newmember;
            nxt = newmember;
            previous = newmember;
        }
        else
        {
            previous->next = newmember;
            newmember->prev = previous;
            nxt = newmember;
            previous = nxt;
        }
    }
    return head;
}

//To remove any member of the family from the list.
Family *remove_element_from_index_i(Family *head, int i)
{
    if (head == NULL)
    {
        return head;
    }
    Family *temp = head;
    if (i == 0)
    {
        temp = temp->next;
        temp->prev = NULL;
        head = temp;
        return head;
    }
    else
    {
        int count = 0;
        Family *temp1 = head;
        Family *temp2 = NULL;

        while (count < (i - 1))
        {
            temp1 = temp1->next;
            count++;
        }
        Family *to_be_deleted = temp1->next;
        temp2 = to_be_deleted->next;
        temp1->next = temp2;
        temp2->prev = temp1;

        delete to_be_deleted;
        return head;
    }
}

// This function will print every member of the list.
void printdoubleLL(Family *head)
{
    Family *temp = head;
    cout << endl
         << "FAMILY TREE--" << endl;
    while (temp != NULL)
    {
        cout << "Members Name : " << temp->name << " "
             << "Members Age : " << temp->age << endl;
        temp = temp->next;
    }
}

int main()
{

    // taking input and appending it at the end of the linked list
    Family *head = takeinputand_appendatlast();
    printdoubleLL(head);

    // remove a family member from anywhere in the list
    int i;
    cin >> i;
    Family *remo = remove_element_from_index_i(head, i);
    printdoubleLL(remo);
}

