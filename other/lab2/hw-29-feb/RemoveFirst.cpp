#include "main.h"

void Remove(NODE** firstNode){
    if(*firstNode != NULL){
        if((*firstNode)->next == NULL){
           (*firstNode)->prev = NULL;
           
           for(int i = 0; i < MAX_SIZE; i++)
                *((*firstNode)->info + i) = '\0';
           
           (*firstNode)->next = NULL;
           
           free(*firstNode);
        }
        else{
            NODE* tmp = (*firstNode)->next;
        
            (*firstNode)->next = NULL;
            
            for(int i = 0; i < MAX_SIZE; i++)
                *((*firstNode)->info + i) = '\0';
            
            tmp->prev = NULL;
            
            free(*firstNode);

            *firstNode = tmp;

            tmp = NULL;

        }
    }
}