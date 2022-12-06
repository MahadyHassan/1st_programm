#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int value;
    node* next;
    node(int val)
    {
        value=val;
        next=NULL;
    }
};
struct test
{
    int position[1000];
};
int counting_the_size(node* &head)
{
    node* tmp=head;
    int count=0;
    while(tmp!=NULL)
    {
        tmp=tmp->next;
        count++;
    }
    return count;
}
void disply_list(node* &head)
{
    if(head==NULL)
    {
        cout<<"Your list is Empty"<<endl;
    }
    node* tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->value;
        if(tmp->next!=NULL)
        {
            cout<<"->";
        }
        tmp=tmp->next;
    }
    cout<<endl;
}
void insertion_at_head(node* &head,int val)
{
    node* newnode=new node(val);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    newnode->next=head;
    head=newnode;
}
void insertion_at_tail(node* &head, int val)
{
    node* newnode=new node(val);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    node* tmp=head;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=newnode;
}
void insertion_at_specific_position(node* &head, int val, int pos)
{
    if(pos==1)
    {
        insertion_at_head(head,val);
        return ;
    }
    node* newnode=new node(val);
    int i=1;
    node* tmp=head;
    while(i<pos-1)
    {
        tmp=tmp->next;
        i++;
    }
    newnode->next=tmp->next;
    tmp->next=newnode;
}
int search_a_value_from_uniqe_list(node* &head, int val)
{
    int i=1;
    int flag=1;
    node* tmp=head;
    while(tmp!=NULL)
    {
        if(tmp->value==val)
        {
            return i;
            flag=0;
        }
        i++;
        tmp=tmp->next;
    }
    if(flag==1)
    {
        return -1;
    }
}
test search_value_from_Duplication_list(node* &head, int val)
{
    test t;
    int i=1;
    int k=1;
    node* tmp=head;
    while(tmp!=NULL)
    {
        if(tmp->value==val)
        {
            t.position[k]=i;
            k++;
        }
        tmp=tmp->next;
        i++;
    }
    k--;
    t.position[0]=k;

    return t;
}
void insertion_after_specific_value_Unique_List(node* &head,int pos_val, int val)
{
    int pos=search_a_value_from_uniqe_list(head, pos_val);
    insertion_at_specific_position(head,val,pos+1);
}
void insertion_after_specific_value_Duplication_enabled_List(node* &head, int pos_val, int val)
{
    test pos=search_value_from_Duplication_list(head, pos_val);
    int siz=pos.position[0];
    int cont=1;
    for(int i=1;i<=siz;i++)
    {
        int key=pos.position[i];
        insertion_at_specific_position(head,val,key+cont);
        cont++;
    }
}
void Deletion_at_Head(node* &head)
{
    if(head==NULL)
    {
        cout<<"list is NULL"<<endl;
        return;
    }
    else if(head->next==NULL)
    {
        node *delnode=head;
        head=NULL;
        delete delnode;
        return;
    }
    else
    {
        node* delnode=head;
        head=delnode->next;
        delete delnode;
    }
}
void deletion_at_Tail(node* &head)
{

    if(head==NULL || head->next==NULL)
    {
        Deletion_at_Head(head);
        return;
    }
    else
    {
        node *tmp=head;
        while(tmp->next->next!=NULL)
        {
            tmp=tmp->next;
        }
        node* delnode=tmp->next;
        tmp->next=NULL;
        delete delnode;
    }
}
void deletion_at_specific_position(node* &head, int pos)
{
    if(pos>counting_the_size(head))
    {
        cout<<"Delete is not possibole"<<endl;
        return;
    }
    else if( head==NULL || head->next==NULL || pos==counting_the_size(head))
    {
        deletion_at_Tail(head);
        return;
    }
    else if(pos==1)
    {
        Deletion_at_Head(head);
        return;
    }
    else
    {
       node* tmp=head;
       int i=1;
       while(tmp->next!=NULL)
       {
           if(i==pos-1)
           {
               node *delnode=tmp->next;
               tmp->next=delnode->next;
               delete delnode;
               return;
           }
           tmp=tmp->next;
           i++;
       }
    }
}
void delete_by_Value_from_uniqe_list(node* &head, int val)
{
    int del_pos=search_a_value_from_uniqe_list(head,val);
    if(del_pos==-1)
    {
        cout<<"your vale is not found"<<endl;
        return;
    }
    else
    {
        deletion_at_specific_position(head, del_pos);
    }
}
void delete_by_Value_from_duplicate_list(node* &head, int val)
{
    test check=search_value_from_Duplication_list(head, val);
    int size=check.position[0];
    int del=0;
    for(int i=1;i<=size;i++)
    {
        int key=check.position[i];
        deletion_at_specific_position(head,key-del);
        del++;
    }
}
node* reverse_non_recursive(node* &head)
{
    node* previous=NULL, *current=head, *Next=head->next;
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    while(1)
    {
        current->next=previous;
        previous=current;
        current=Next;
        if(current==NULL)
        {
            break;
        }
        Next=Next->next;
    }
    return previous;
}
node* reverse_recursive(node* &head)
{
    if(head->next==NULL)
    {
        return head;
    }
    cout<<head->value<<endl;
    node* newhead=reverse_recursive(head->next);
    cout<<head->value<<endl;

}
int main()
{
    node* head=NULL;
    cout<<"1.Disply list"<<endl;
    cout<<"2.insertion at head"<<endl;
    cout<<"3.insertion at Tail"<<endl;
    cout<<"4.insertion at specific positon"<<endl;
    cout<<"5.search a value from uniqe list"<<endl;
    cout<<"6.Search value from duplicate list"<<endl;
    cout<<"7.insertion after a specific value from uniqe list"<<endl;
    cout<<"8.insertion after a specific value from duplicate list"<<endl;
    cout<<"9.deletion at head"<<endl;
    cout<<"10.Deletion at tail"<<endl;
    cout<<"11.deletion at specific position"<<endl;
    cout<<"12.deletion at value from uniqe list"<<endl;
    cout<<"13.deletion at value from duplicate list"<<endl;
    cout<<"14.Reverse linked list Non Recursive"<<endl;
    cout<<"15.Reverse linked list Recursive"<<endl;



    cout<<"0.Exit"<<endl<<endl;

    int choice;
    cout<<"Enter choice: ";
    cin>>choice;
    while(choice!=0)
    {
        int value;
        int pos;
       if(choice==1)
       {
            disply_list(head);
       }
       else if(choice==2)
       {
            cout<<"Enter value: ";
            cin>>value;
            insertion_at_head(head, value);
       }
       else if(choice==3)
       {
            cout<<"Enter value: ";
            cin>>value;
            insertion_at_tail(head, value);
       }

      else if(choice==4)
      {
            cout<<"Enter positon: ";
            cin>>pos;
            cout<<"Enter value: ";
            cin>>value;
            insertion_at_specific_position(head,value,pos);
      }
      else if(choice==5)
      {
           cout<<"Enter search value: ";
            cin>>value;
            int searc=search_a_value_from_uniqe_list(head, value);
            if(searc==-1)
            {
                cout<<"your value is not found"<<endl;
            }
            else
            {
                cout<<"your search value is positon: ";
                cout<<searc;
                cout<<endl;
            }
      }
      else if(choice==6)
      {
          cout<<"Enter search value: ";
            cin>>value;
            test capture=search_value_from_Duplication_list(head, value);
            int siz=capture.position[0];
            if(siz==0)
            {
                cout<<"search value is not found"<<endl;
            }
            else
            {
                for(int i=1;i<=siz;i++)
                {
                    cout<<capture.position[i];
                    if(i<siz)
                    {
                        cout<<"=>";
                    }
                }
                cout<<endl;
            }
      }
      else if(choice==7)
      {
          int af_value;
          cout<<"Insert at after value: ";
          cin>>af_value;
          cout<<"Enter value: ";
          cin>>value;
          insertion_after_specific_value_Unique_List(head, af_value, value);
      }
      else if(choice==8)
      {
          int af_value;
          cout<<"Insert at after value: ";
          cin>>af_value;
          cout<<"Enter value: ";
          cin>>value;
          insertion_after_specific_value_Duplication_enabled_List(head,af_value,value);
      }
      else if(choice==9)
      {
          Deletion_at_Head(head);
      }
      else if(choice==10)
      {
          deletion_at_Tail(head);
      }
      else if(choice==11)
      {
          cout<<"Enter positon: ";
          cin>>pos;
          deletion_at_specific_position(head, pos);
      }
      else if(choice==12)
      {
          cout<<"Enter value: ";
          cin>>value;
          delete_by_Value_from_uniqe_list(head, value);
      }
      else if(choice==13)
      {
          cout<<"enter value: ";
          cin>>value;
          delete_by_Value_from_duplicate_list(head, value);
      }
      else if(choice==14)
      {
          head=reverse_non_recursive(head);
      }
      else if(choice==15)
      {
          head =reverse_recursive(head);
      }

        cout<<"Next choice: ";
        cin>>choice;
    }



    return 0;
}
