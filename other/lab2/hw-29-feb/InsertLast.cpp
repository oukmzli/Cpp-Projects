#include "main.h"
void Insert(NODE** firstNode, OBJECT_TYPE insertedObject){
    if(*firstNode==NULL){
        Insert(insertedObject, firstNode);
    }
    else{
        NODE* tmp = *firstNode;
        while((*firstNode)->next != NULL)
            *firstNode = (*firstNode)->next;
        
        NODE* newLast = (NODE*)malloc(sizeof(NODE));
        newLast->prev = *firstNode;

        for(int i = 0; i < MAX_SIZE; i++)
            *(newLast->info + i) = '\0'; 
        
        for(int i = 0; i < MAX_SIZE && *(insertedObject + i) != '\0'; i++)
            *(newLast->info + i) = *(insertedObject + i);
        
        newLast->next = NULL;
        
        (*firstNode)->next = newLast;
        *firstNode = tmp;

        tmp = NULL;
    }
}
