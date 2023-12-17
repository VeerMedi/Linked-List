#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};

//Function for inserting node at beginning 
struct node* insertBegin(struct node* start, struct node* newnode){

    newnode->link = start;
    start = newnode;

    return start;
}

//Function for inserting node end 
struct node* inserEnd(struct node* end, struct node* newnode){

    end->link = newnode;
    end = newnode;

    return end;
}

//Function for inserting node in between
void insertPos(int count, int pos, struct node* start, struct node* newnode){
    if(pos < count){
        struct node* tptr;
        int cpos = 1; 
        for (tptr = start; tptr != NULL; tptr = tptr->link ){
            cpos++;
            if (cpos == pos){
                break;
            }

        } 
    
        newnode-> link = tptr -> link;
        tptr->link = newnode;
    }
}

//Function for displaying Linked List
void display(struct node* start){
    struct node* curNode = NULL;

    for (curNode = start; curNode != NULL; curNode = curNode->link){
        printf("%d %x ",curNode->data, curNode->link);
        if (curNode->link != NULL){
            printf("%c ",26);
        }
    }
    printf("\n");
}


int main() {

    struct node* start = NULL;
    struct node* end;

    struct node node1,node2,node3;

    int count = 0;

    printf("Linked List Before : \n");
    display(start);

    int choice = 1;

    while (choice){
        

        int pos;

        printf("Enter the pos to insert : ");
        scanf("%d",&pos);
        
        //Creating new node 
        struct node* newnode;
        newnode=(struct node*)malloc(sizeof(struct node));

        printf("Enter the data for new node : ");
        scanf("%d", &newnode->data);

        newnode->link = NULL;
        
        if (start == NULL){
            start = newnode;
            end = newnode;
            newnode->link = NULL;
            count++;
            
        }

        else if (pos == 1)
        {   
            start = insertBegin(start,newnode);
            count++;
        }

        else if (pos >= count) {
            end = inserEnd(end,newnode);
            count++;
        }
        
        else{;
            insertPos(count,pos,start,newnode);
            count++;
        }
        
        printf("Linked List After : \n");
        display(start);

        printf("Do you want to add more nodes(0/1) : ");
        scanf("%d", &choice);
    }

    return 0;
}