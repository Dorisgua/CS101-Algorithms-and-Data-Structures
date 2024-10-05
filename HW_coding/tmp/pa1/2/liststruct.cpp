#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
struct node{  
    int data;  
    char name[30];
    struct node *next;  
};      
   
struct node *head, *tail = NULL;  
   
void addNode(int data, char string[]) {  

    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data; 
    // CHANGE HERE: copy char array argument to name
    strncpy(newNode->name, string, 30);
    newNode->next = NULL;  
      
    if(head == NULL) {   
        head = newNode;  
        tail = newNode;  
    }  
    else {  
        tail->next = newNode;  
        tail = newNode;  
    }  
}  
   
void sortList() {  
        struct node *current = head, *index = NULL;  
        int temp;  
        char temp1[30];
        
        if(head == NULL) {  
            return;  
        }  
        else {  
            while(current != NULL) {  
                index = current->next;  
                  
                while(index != NULL) {  
                
                    if(current->data > index->data) {  
                        temp = current->data;  
                        current->data = index->data;  
                        index->data = temp; 
                        
                        // CHANGE HERE: swap the name along with data
                        strncpy(temp1, current->name, 30);
                        strncpy(current->name, index->name, 30);
                        strncpy(index->name, temp1, 30);
                        
                    }  
                    index = index->next;  
                }  
                current = current->next;  
            }      
        }  
    }  
   

void display() {  
 
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty \n");  
        return;  
    }  
    while(current != NULL) {  
 
        printf("%d - %s\n", current->data, current->name);  
        current = current->next;  
    }  
    printf("\n");  
}
int main()  
{  
    char string1[10] = "Aaron";
    char string2[10] = "Baron";
    char string3[10] = "Carla";
    
    addNode(9, string1);  
    addNode(7, string2);  
    addNode(2, string3);   

    printf("Original list: \n");  
    display();  

    sortList();  
   
    printf("Sorted list: \n");  
    display();  
          
    return 0;  
}  