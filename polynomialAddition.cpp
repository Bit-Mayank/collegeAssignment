#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*@bit-mayank
 **It is incomplete don't rely on it!
 */
class Node
{
public:
    int coef;
    int deg;
    Node *next;

    Node(int coef, int deg)
    {
        this->coef = coef;
        this->deg = deg;
        this->next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = nullptr;
    }

    void insert(int coef, int deg)
    {
        Node *newNode = new Node(coef, deg);
        if (!head)
        {
            this->head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = newNode;
    }

    void display()
    {
        if (!head)
            return;

        Node *temp = head;
        while (temp)
        {
            cout << temp->coef << " " << temp->deg << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

void fillLL(LinkedList &ll, string s)
{
    int size = s.size();

    int i = 0;
    while (i < size)
    {
        int coef;
        int deg;

        if (s[i] == 'x' && (i == 0))
        {
            coef = 1;
            deg = (s[i + 1] - '0');
            if (isdigit(s[i + 1]))
            {
                ll.insert(coef, deg);
            }
            else
            {
                ll.insert(coef, 1);
            }
        }
        else if (s[i] == 'x')
        {
            coef = (s[i - 1] - '0');
            if (i + 1 < size)
                deg = (s[i + 1] - '0');

            if (!isdigit(s[i - 1]))
            {
                coef = 1;
            }
            if (!isdigit(s[i + 1]))
            {
                deg = 1;
            }

            ll.insert(coef, deg);
        }
        else if (i == size - 1 && s[i] != 'x')
        {
            coef = (s[i] - '0');
            ll.insert(coef, 0);
        }
        i++;
    }
}

Node *addPolynomial(LinkedList &ll1, LinkedList &ll2)
{
    LinkedList ll;
    Node *temp1 = ll1.head;
    Node *temp2 = ll2.head;
    Node *temp3 = ll.head;

    while (temp1)
    {
        while (temp2)
        {
            if (temp1->deg == temp2->deg)
            {
                int sum = temp1->coef + temp2->coef;
                Node *newNode = new Node(sum, temp1->deg);
                if (!ll.head)
                {
                    ll.head = newNode;
                    temp3 = ll.head;
                    break;
                }

                while (temp3->next)
                    temp3 = temp3->next;
                temp3->next = newNode;
            }

            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return ll.head;
}

void displayPolynomial(Node *&head)
{
    cout << "Output: ";
    Node *temp = head;
    while (temp)
    {
        cout << temp->coef << "x" << temp->deg << "+";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    string s1;
    string s2;
    cout << "Enter first Polynomial Expression: ";
    cin >> s1;

    cout << "Enter second polynonial Expression: ";
    cin >> s2;

    LinkedList ll1, ll2, ll3;
    fillLL(ll1, s1);
    fillLL(ll2, s2);

    ll3.head = addPolynomial(ll1, ll2);

    displayPolynomial(ll3.head);
    return 0;
}