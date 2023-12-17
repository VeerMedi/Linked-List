#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    struct node* prev;
    char data;
    struct node* next;
};

void display(struct node* start){
    for(struct node* ptr = start; ptr!=NULL; ptr = ptr->next ){
        cout << " " << ptr->prev << " ";
        cout << ptr->data << " ";
        cout << ptr->next << " ";
        if (ptr->next != NULL){
            cout << char(26);
        }

    }
}


//Function for insertion at the begninning
struct node* insertBeg(struct node* start,struct node* newnode){
    newnode->next = start;
    start->prev = newnode;
    start = newnode;
    return start;
}

//Function for insertion at the end 
struct node* insertEnd(struct node* end,struct node* newnode){
    newnode->prev=end;
    end->next = newnode;
    end = newnode;
    return end;
}

//Function for inserting at a given position
void inserPos(struct node* start,struct node* newnode,int pos){
    int cur = 0;
    for(struct node* ptr = start; (ptr != NULL && cur<pos); ptr = ptr->next ){
        start = ptr;
        cur++;
    }

    newnode->next = start;
    newnode->prev = start->prev;
    start->prev->next = newnode;
    start->prev = newnode;
}

//Function for insertion at the begninning
struct node* deleteBeg(struct node* start){
    struct node* tptr;
    
    start->next->prev = NULL;
    tptr = start;
    start = start->next;

    free(tptr);
    return start;
}

//Function for insertion at the end 
struct node* deleteEnd(struct node* end){
    struct node* tptr;
    
    tptr = end;
    end->prev->next = NULL;
    end = end->prev;

    free(tptr);

    return end;
}

//Function for inserting at a given position
void deletePos(struct node* start,struct node* newnode,int pos){
    int cur = 0;
    for(struct node* ptr = start; (ptr != NULL && cur<pos); ptr = ptr->next ){
        start = ptr;
        cur++;
    }

    newnode->next = start;
    newnode->prev = start->prev;
    start->prev->next = newnode;
    start->prev = newnode;
}

int main(){
    struct node* start, *end;
    int count = 0;
    int choice = 1;
    int pos;
    char ch;

    start = end = NULL;

    do{
        cout<< "Menu : \n1. Inserion \n2. Deletion \n3. Display \n 4.Exit";
        cin >> choice;

        switch (choice)
        {
            case (1):
                cout << "Enter data : ";
                cin >> ch;
                
                cout << "Enter Pos : ";
                cin >> pos;

                struct node* newnode = (struct node*)malloc(sizeof(struct node));
                newnode->data = ch;
                newnode->prev = NULL;
                newnode->next = NULL;

                if (start == NULL){
                    start = newnode;
                    end = newnode;
                    count++;
                }

                else if (pos == 1){
                    start = insertBeg(start,newnode);
                    count++;
                }
                else if (pos >= count){
                    end = insertEnd(end,newnode);
                    count++;
                }
                else{
                    inserPos(start,newnode,pos);
                    count++; 
                }

                display(start); 

                cout << "\nDo you want to continue : ";
                cin >> choice;
                break;
            
            case (2):            
                cout << "Enter Pos : ";
                cin >> pos;

                if (count == 0){
                    cout << "Empty Linked List.";
                }

                else if (pos == 1){
                    start = deleteBeg(start);
                    count--;
                }
                // else if (pos == count){
                //     end = deleteEnd(end,newnode);
                //     count++;
                // }
                // else if(pos < count && pos > 0){
                //     deletePos(start,newnode,pos);
                //     count++; 
                // }
                else{
                    cout << "Invalid Position.";
                }

                display(start);

                cout << "\nDo you want to continue : ";
                cin >> choice;
                break;
            
            default:
                cout<<"Invalid Choice.";
                break;
        }
        
    }while (choice != 4);
    return 0;
}