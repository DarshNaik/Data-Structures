#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
}*head;

void insert(int x)
{
    struct Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if(head == NULL )
    {    temp->next = head;
        head = temp;
        return;
    }
    Node* temp2 = head;
    while(temp2->next!=NULL)
        temp2 = temp2->next;
    temp->next = temp2->next;
    temp2->next = temp;
}

void delalternate()
{
    if(head==NULL)
        return;
    struct Node* prev = head;
    struct Node* nexxt = head->next;
    while(prev!=NULL && nexxt!=NULL)
    {
        prev->next = nexxt->next;
    
    free(nexxt);
    prev = prev->next;
    if(prev!=NULL)
        nexxt=prev->next;
    }
}

void pr()
{
    struct Node* temp = head;
    while(temp!= NULL)
    {
        cout<<"->"<<temp->data;
        temp = temp->next;
        
    }
}

int main()
{
    head = NULL;
    int n,a,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        insert(a);
    }
    pr();
    cout<<endl;
    delalternate();
    pr();
    return 0;
}
