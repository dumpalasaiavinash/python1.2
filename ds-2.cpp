#include<iostream>
#include<stdlib.h>




typedef struct Node
{
    int data;
    struct Node *next;
}node;

node *head = NULL;

//insert fun
void insert(int data, int position)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    
    
    if(position==1)
    {
        temp->next = head;
        head = temp;
        return ;
    }
    node *traverse = head;
    for(int i=0; i<position-2; i++)
    {
        traverse = traverse->next;
    }
    temp->next = traverse->next;
    traverse->next = temp;
}
    //print fun
    void print()
    {
        printf("\n Linked List is:");
        node *p = head;
        while(p)
        {
            printf(" %d",p->data);
            p = p->next;
        }
        printf("\n");
    }

void deleteNode(struct Node **head_ref, int key)
{
    
    struct Node* temp = *head_ref, *prev;
    
    
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) return;
    
    prev->next = temp->next;
    
    free(temp);
}



    int main()
    {
        insert(1,1);
        insert(2,2);
        insert(3,3);
        insert(-1,4);
        insert(-2,5);
        print();
       
        deleteNode(&head,-1);
        
        print();
    }
