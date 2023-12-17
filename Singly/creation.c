#include<stdio.h>

struct node
{
    int data;
    struct node* link;
};

void main() {
    struct node* start = NULL;

    struct node node1,node2,node3;


    node1.data = 10;
    node1.link = &node2;

    node2.data = 20;
    node2.link = &node3;

    node3.data = 30;
    node3.link = NULL;

    start = &node1;

    struct node* curNode; 
    int count = 1;

    printf("Using For Loop. \n");

    for (curNode = start; curNode != NULL; curNode = curNode->link){
        printf("%d %d ",curNode->data, curNode->link);
        if (curNode->link != NULL){
            printf("%c ",26);
        }
        count++;
    }


    curNode = start;
    
    count = 1;

    printf("\nUsing While Loop\n");
    while(curNode != NULL){
        printf("%d %d ",curNode->data, curNode->link);
        if (curNode->link != NULL){
            printf("%c ",26);
        }
        curNode = curNode -> link;
        count++;
    }
    
}