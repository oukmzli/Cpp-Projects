#include "main.h"
void Display(NODE* firstNode){
    if(firstNode != NULL ){
        int objectCount = 0;
        NODE* tmp = firstNode;
        while(firstNode!=NULL){
            printf("%d: ", objectCount);
            for(int i = 0; i < MAX_SIZE; i++)
                printf("%c", *(firstNode->info + i));
    
            printf("|\n");
            
            firstNode = firstNode->next;
            
            objectCount++;
        }
        firstNode = tmp;
        tmp = NULL;
    
    }
    else{
        printf("List is empty\n");
    }
}