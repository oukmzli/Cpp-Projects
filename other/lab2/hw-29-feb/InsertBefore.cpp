#include "main.h"
void Insert(NODE** firstNode, NODE* currentNode, OBJECT_TYPE insertedObject){
    if(*firstNode != NULL){
        if(*firstNode == currentNode){
            Insert(insertedObject, firstNode);
        }
        else{
            NODE* insertedNode = (NODE*)malloc(sizeof(NODE));
                        
            insertedNode->prev = currentNode->prev->next;

            for(int i = 0; i < MAX_SIZE; i++)
                *(insertedNode->info + i) = '\0';

            for(int i = 0; i < MAX_SIZE && *(insertedObject + i) != '\0'; i++)
                *(insertedNode->info + i) = *(insertedObject + i); 
            insertedNode->next = currentNode;
            
            currentNode->prev->next = insertedNode;

        }
    }
}