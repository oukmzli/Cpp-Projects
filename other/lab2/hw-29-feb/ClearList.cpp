#include "main.h"

void ClearList(NODE** firstNode){
    if(*firstNode != NULL){
        if((*firstNode)->next == NULL)
            Remove(firstNode);
        else{
            NODE* tmp = (NODE*)malloc(sizeof(NODE));
            
            while(*firstNode != NULL){
                tmp = *firstNode;
                *firstNode = (*firstNode)->next;
                free(tmp);
            }    
        }
    }
}