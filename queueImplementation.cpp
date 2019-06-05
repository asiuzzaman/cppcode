#include <iostream>
using namespace std;

struct Point
{
    int first;
    int second;
};

struct Node
{
    Point pt;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void Push(Point p)
{
    Node *temp = new Node();
    temp->pt.first = p.first;
    temp->pt.second = p.second;
    temp->next = NULL;
    if (front == NULL and rear == NULL)
    {
        front = rear = temp;
        return; // ei return na dile choda khaba........
    }
    rear->next = temp;
    rear = temp;
}

void Pop()
{
    Node *temp = new Node();
    temp = front;
    if(front==NULL) {
        cout<<"The queue is Empty()...."<<endl;
    }
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }
    free(temp);
}
void Print()
{
    Node *temp = new Node();
    temp = front;
    while (temp != NULL)
    {
        cout << temp->pt.first << " " << temp->pt.second << endl;
        temp = temp->next;
    }
    cout << endl;
}
Point Top(){
    
    return front->pt;
}

int main()
{
    cout << "my main starts....." << endl;
    Push({1, 10});
    Push({2, 20});
    //Print();
    Push({3,30});
    Push({4,40});
    Print();
    Pop();
    Print();
    cout<<"The Top: "<<Top().first<<" "<<Top().second<<endl;
    Print();
    Pop();
    Print();
    Push({6,60});
    Print();

}