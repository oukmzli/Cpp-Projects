#include "main.h"
void Insert(OBJECT_TYPE insertedObject, NODE** firstNode){
    if(*firstNode==NULL){
        *firstNode = (NODE*)malloc(sizeof(NODE));
        
        (*firstNode)->prev = NULL;

        for(int i = 0; i < MAX_SIZE; i++)
            *((*firstNode)->info + i) = '\0';
        
        for(int i = 0; i < MAX_SIZE && *(insertedObject + i) != '\0'; i++)
            *((*firstNode)->info + i) = '\0';
        
        (*firstNode)->next = NULL;
    }
    else{
        NODE* newFirst = (NODE*)malloc(sizeof(NODE));
        
        newFirst->next = (*firstNode);
        
        newFirst->prev = NULL;

        for(int i = 0; i < MAX_SIZE; i++)
            *(newFirst->info + i) = '\0';
        
        for(int i=0; i < MAX_SIZE && *(insertedObject+i) != '\0'; i++)
            *(newFirst->info+i) = *(insertedObject+i);
        
        (*firstNode)->prev = newFirst;
        
        *firstNode = newFirst;
    }
}