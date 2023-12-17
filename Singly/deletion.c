#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};

//Function for inserting node at beginning 
struct node* deleteBegin(struct node* start){

    struct node* nextNode;
    nextNode = start;
    start = start->link;
    free(nextNode);

    return start;
}

//Function for deleting last NODE
struct node* deleteEnd(struct node* start,struct node* end){
   
    struct node* tempNode;

    for (tempNode = start; tempNode != NULL; tempNode = tempNode ->link ){
        if(tempNode->link != NULL){
            end = tempNode;
        }
        else{
            break;
        }
        
    }

    end->link=NULL;
    tempNode = tempNode->link;
       
    free(tempNode);

    return end;
}

//Function for deleting node from between
void deletePos(int pos, struct node* start){
    struct node* tempNode;
    tempNode = start;

    int i = 1;

    while(i<pos-1){
        tempNode = tempNode->link;
        i++;
    }

    tempNode->link = tempNode->link->link;

    tempNode = tempNode->link;
    free(tempNode);    
}

//Function for displaying pointer
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
    struct node* end = NULL;
    struct node node1,node2,node3,node4,node5;

    int count = 0;

    

    node1.data = 10;
    node1.link = &node2;
    count++;

    node2.data = 20;
    node2.link = &node3;
    count++;

    node3.data = 30;
    node3.link = &node4;
    count++;

    node4.data = 40;
    node4.link = &node5;
    count++;

    node5.data = 50;
    node5.link = NULL;
    count++;

    start = &node1;
    end = &node5;    

    printf("Linked List Before : \n");
    display(start);

    int choice = 1;

    while (choice){
        
        int pos;

        printf("Enter the pos to delete : ");
        scanf("%d",&pos);
        
        if (start == NULL){
            printf("Linked List is Empty!");  
            break;          
        }

        else if (pos == 1)
        {   
            start = deleteBegin(start);
            count--;
        }

        else if(pos < count){;
            deletePos(pos,start);
            count--;
        }

        else if (pos == count) {
            end = deleteEnd(start,end);
            count--;
        }

        else{
            printf("Inavlid Position.");
            continue;
        }
        
        printf("Linked List After : \n");
        display(start);

        printf("Do you want to add more nodes(0/1) : ");
        scanf("%d", &choice);
    }

    return 0;
}
