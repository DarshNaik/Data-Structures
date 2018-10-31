#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node*next;
    struct node*pre;
};




void create_begin(struct node **d,int item)
{
  struct node * newnode;
    newnode=new node;
    newnode->data=item;
    newnode->pre=NULL;
    newnode->next=NULL;
    if(*d==NULL)
    {
        *d=newnode;
    }

      else
      {
         newnode->next=*d;
         *d=newnode;
      }
}
void create_end(struct node **d,int item)

{
    struct node *newnode;
    newnode=new node;
    newnode->data=item;
    newnode->next=NULL;
    newnode->pre=NULL;

    if(*d==NULL)
    {
        *d=newnode;
    }


    else
    {
        struct node *temp=*d;
        while(temp->next!=NULL)
           temp=temp->next;
        //newnode->next=NULL;
         newnode->pre=temp;
         temp->next=newnode;

    }
}


void create_middle(struct node**d,int position,int item)
{
    struct node *newnode;
    newnode=new node;
    newnode->data=item;
    if(*d==NULL)
    {
        *d=newnode;
        newnode->next=NULL;
        newnode->pre=NULL;
    }

    else

    {
        struct node * temp=*d;
        struct node * tem;
         for( int i=1;i<position;i++)
            {   tem=temp;
                temp=temp->next;
            }
            tem->next=newnode;
            newnode->next=temp;
            newnode->pre=tem;
    }
}



void deleted(struct node **d,int item)
{   struct node * temp =*d;

while(temp!=NULL)
    {
         if(temp->data==item)
       {
           if(*d==temp)
            {(*d)=(*d)->next;
              (*d)->pre=NULL;
            }

        else
         {  if(temp->next==NULL)
               temp->pre->next=NULL;
           else
           {
               temp->pre->next=temp->next;
               temp->next->pre=temp->pre;
           }

        }
     }
    temp=temp->next;
    }

}




void display(struct node **d)
{
     if(*d==NULL)
        cout<<"empty";
     else
     {
         struct node *temp=*d;
         while(temp!=NULL)
         {
             cout<<temp->data<<"\n";
             temp=temp->next;
          }
     }
}

int main()
{
     struct node *d=NULL;
     int n,i,j;
     cin>>n;
     for(i=0;i<n;i++)
     {
         cin>>j;
         create_end(&d,j);
     }

     display(&d);

   int k;
   cin>>k;
       cout<<"After deleting"<<"\n";


     deleted(&d,k);
     display(&d);


     return 0;
}
