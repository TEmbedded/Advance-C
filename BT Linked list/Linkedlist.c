#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Khai báo một node*/
typedef struct node
{
    int value; // data input node
    struct node* next; // address of next node in linked list
    
}node;
/*
node *createNode(int value); 
void push_back(node** array, int value); // them 1 node vao phia cuoi
void push_front(node **array, int value); // them 1 node vao phia truoc
void pop_back(node **array); // xoa node cuoi
void pop_front(node **array); // xoa node dau tien
int front(node *array); // lay gia tri cua node dau tien
int back(node *array); // lay gia tri cua node cuoi cung
void insert(node **array, int value, int pos); // them 1 node vao mot vi tri bat ky
void deletee(node **array, int pos); // xoa 1 node tai mot vi tri bat ky
int size(node **array); // lay kich thuoc cua list
int get(node **array, int pos); 
bool empty(node **array); // kiem tra list co rong hay khong

*/
 //Function to create a new node
node *createNode(int value){
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}
/*
Add a new node input the front position of linkedlist
*/
void push_front(node **array, int value){
    node* temp; // Create a new node with the provided value
    temp = createNode(value);
    if(*array = NULL){
        array = temp;
    }
    else{
        temp->next = *array; 
        *array = temp;
    }
}

// Add a new node input the last position of linkedlist
void push_back(node** array, int value)
{
    node* temp;
    temp = createNode(value);
    if (*array = NULL){ //if linkedlist doesn't any node yet
        array= temp;
    }
    else{               // if linkedlist has some node
        node* p = *array; // use p instead of array because we using pointer, use array will change the structure of linked list
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;     //check next node until it's a last node
        }
        p->next = temp; // assign next of previous node equal address of the new created node 
    }
    
} 
/* ---------------------------------------------- */  
/*----- Delete the last node of the Linkedlist----*/ 
/* ---------------------------------------------- */
void pop_back(node **array){
    if ( array == NULL) return; // if linkedlist haven't any node yet
    node* p, * temp;
    p = *array;
    if(p->next = NULL){ //if linkedlist have an only node
        temp = p->next;
    }
    else // if linkedlist have more than a node
    {
        while (p->next->next != NULL)     // free the last node in the list
        {
        p = p->next;
        }
        temp = p->next;
        p->next = NULL;
    }
    free(temp);
}
/* ---------------------------------------------- */  
/*---- Delete the front node of the Linkedlist----*/ 
/* ---------------------------------------------- */
void pop_front(node **array){
    if ( array == NULL) return; // if linkedlist haven't any node yet

    node* temp = *array; 
    *array = (*array)->next; 
    free(temp); 
}
/* ---------------------------------------------- */  
/*-- return the first value of the Linked list----*/ 
/* ---------------------------------------------- */
int front(node *array){
    int value = array->value;
    return value;
}
/* ---------------------------------------------- */  
/*--- return the last value of the Linked list----*/ 
/* ---------------------------------------------- */
int back(node *array){
    while (array->next != NULL)
    {
        array = array->next;
    }
    int value = array->value;
    return value;
}
/* ---------------------------------------------- */  
/*- Add a node in any position of the Linked list-*/ 
/* ---------------------------------------------- */
void insert(node** array, int value, int pos){
     node* tempt;
     tempt = createNode(value);
     if(array == NULL){
        return tempt;
     }
    // thêm vào vị trí đầu tiên trong linked list
    if (pos = 0){
        tempt->next = *array;
        *array = tempt;
    }
     
     int i = 0;
     node* p = *array;
     
     while (p->next != NULL && i < pos -1)
     {
        p = p->next;
        i++;
     }
     tempt->next = p->next; //thay con trỏ null bằng địa chỉ con trỏ của node pos -1 
     p->next = tempt; // thay con trỏ địa chỉ pos -1 bằng địa chỉ tempt
}   
/* ------------------------------------------------- */  
/*- Delete a node in any position of the Linked list-*/ 
/* ------------------------------------------------- */
void delete(node **array, int pos){
    // có hàm kiểm tra linkedlist có rỗng không rồi
    int count = 0;
    node* temp = *array;
    node* prev= NULL;

    while (temp->next != NULL && count < pos)
     {
        prev = temp;
        temp = temp->next;
        count++;
     }
     if(temp == NULL){ // If it can't find temp which we want delete
        printf ( " Position need to delete haven't exist.\n");
        return;
     } 
    prev->next = temp->next;
    free(temp);
} 
/* ------------------------------------------------- */  
/*-------- To get size of the Linked list------------*/ 
/* ------------------------------------------------- */
int size(node* array){   
    int count = 1;
    if( array == NULL){
        count = 0;
        return count;
    }
    while ( array != NULL)
    {
        count++;
        array = array->next;
    }
    return count;   
}
/* -----------------------------------------------------*/  
/*--- Return value at the position of the Linked list---*/ 
/* -----------------------------------------------------*/
int get(node **array, int pos){
    int i = 0;
    node* p = * array;
    while(p->next != NULL && pos != i){
        p = p->next;
        i++;
    }
    int value = p->value;
    return value;
}
/* --------------------------------------------------*/  
/*--- Check if linked list is empty or not-----------*/ 
/* --------------------------------------------------*/
bool empty(node *array){
    if(array == NULL){
        return true;
    }else{
        return false;
    }
}

int main()
{
    node* arr = NULL;
    push_back(&arr, 2);
    push_back(&arr, 7);
    push_back(&arr, 4);
    push_back(&arr, 5);
    push_back(&arr, 3);
    push_back(&arr, 10);

    printf("Value test: %d\n", get(arr, 2));
    printf("Value test: %d\n", get(arr, 0));
    printf("Value test: %d\n", get(arr, 5));


	return 0;
}