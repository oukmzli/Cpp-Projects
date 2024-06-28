#include "main.h"

void Remove(NODE** firstNode, NODE* currentNode){

    if(*firstNode != NULL && currentNode != NULL){
        if(*firstNode == currentNode)
            return;
        else if((*firstNode)->next = currentNode)
            Remove(firstNode);
        else{
            NODE* tmp = currentNode->prev->prev;
            
            currentNode->prev->prev = NULL;

            for(int i = 0; i < MAX_SIZE; i++)
                *(currentNode->info + i) = '\0';

            currentNode->prev->next = NULL;

            free(currentNode->prev);

            currentNode->prev = tmp;

            tmp->next = currentNode;

            tmp = NULL;
        }
    }

}
