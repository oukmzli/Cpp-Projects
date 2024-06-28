#include "main.h"

void Remove(NODE* currentNode, NODE** firstNode){
    if(*firstNode != NULL && currentNode != NULL){
        if(currentNode->next == NULL)
            return;
        else if(currentNode->next->next = NULL)
            Remove(currentNode->next);
        else{
            
            NODE* tmp = currentNode->next->next;
            
            currentNode->next->prev = NULL;
            
            for(int i = 0; i < MAX_SIZE; i++)
                *(currentNode->next->info + i) = '\0';
            
            currentNode->next->next = NULL;

            free(currentNode->next);

            currentNode->next = tmp;

            tmp->prev = currentNode;

            tmp = NULL;
        
        }
    }
}