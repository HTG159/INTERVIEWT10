#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
     struct Node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation fail!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertFrist(Node**head, int data){
    Node*newNode = createNode(data);
    if(newNode == NULL)
    return;
    newNode->next = *head;
    *head = newNode;
}

void insertLast(Node **head, int data){
    Node* newNode = createNode(data);
    if(newNode == NULL)
        return;
    if(*head == NULL){
        insertFrist(head,data);
        return;
    }
    Node*temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteFirst(Node**head){
    if(*head == NULL){
        printf("The List is empty!\n");
    }
    Node*temp = *head;
    *head = temp->next;
    free(temp);
}
void deleteLast(Node **head){
    if(*head == NULL){
        printf("The List is empty!\n");
    }
    Node *temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
Node *firstNode (Node**head){
    Node*temp = *head;
    return temp;
}
Node *LastNode (Node**head){
    if(*head == NULL){
        printf("This List is empty!\n");
    }
    Node*temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp;
}
int getSizeList(Node**head){
    int count = 0;
    Node*temp = *head;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}
Node* getNode(Node**head, int pos){
    if(*head == NULL){
        printf("this List is empty!\n");
    }
    if(pos == 1){
        return *head;
    }
    if(pos - 1 > getSizeList(head)){
        printf("Nhap lai vi tri!");
        return NULL;
    }
    Node*temp = *head;
    int count = 1;
    while(count < pos) {
        temp = temp->next;
        count++;
    }
    return temp;
}
void insertNode(Node**head, int pos, int data){
    if(pos == 1){
        insertFrist(head,data);
        return;
    }
    if(pos - 1 > getSizeList(head)){
        printf("Nhap lai vi tri!");
    }
    Node*newNode = createNode(data);
    Node*temp = *head;
    int count = 1;

    while(count < pos - 1){
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return;
}
void deleteNode(Node**head, int pos){
    if(pos == 1){
        deleteFirst(head);
        return;
    }
    if(pos - 1 > getSizeList(head)){
        printf("Nhap lai vi tri!");
    }
    Node*temp = *head;
    int count = 1;
    while(count < pos - 1 ){
        temp = temp->next;
        count++;
    }
    Node*noteDelete = temp->next;
    temp->next = noteDelete->next;
    free(noteDelete);
    return;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void freeList(Node*head){
    Node*temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    Node* head = NULL;

    insertFrist(&head, 10);
    insertFrist(&head, 20);
    insertLast(&head, 30);

    printf("Initial List: ");
    printList(head);

    deleteNode(&head, 2);
    printf("After deleting position 2: ");
    printList(head);

    freeList(head);

    return 0;
}

