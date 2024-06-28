#include "main.h"

void Remove(NODE* firstNode){
    if(firstNode != NULL){
        if(firstNode->next == NULL)
            Remove(&firstNode);
        else{
            NODE* tmp = firstNode;

            while(firstNode->next != NULL)
                firstNode = firstNode->next;

            for(int i = 0; i < MAX_SIZE; i++)
                *(firstNode->info + i) = '\0';

            firstNode->prev->next = NULL;

            firstNode->prev = NULL;

            free(firstNode);

            firstNode = tmp;

            tmp = NULL;
        }
    }

}