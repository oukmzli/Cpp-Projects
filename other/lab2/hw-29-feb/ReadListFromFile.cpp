#include "main.h"

NODE** ReadListFromFile(int dataAmount, FILE* inputFile){
    if(dataAmount != 0){
    NODE** firstNode = (NODE**)malloc(sizeof(NODE));
    *firstNode = (NODE*)malloc(sizeof(NODE));
    NODE* tmp = *firstNode;
    char bufferChar = '\0';
    while(dataAmount > 0){
        for(int i = 0; i < MAX_SIZE; i++){
            *((*firstNode)->info + i) = '\0';
        } 
        fscanf(inputFile,"%[^\n]s",(*firstNode)->info);  
        int index;
        for(int i = 0; i < MAX_SIZE; i++){
            if(*((*firstNode)->info + i) == '\0'){
                index = i;
                break;
            }
        } 
        if(index != MAX_SIZE - 1){
            for(int i = index; i < MAX_SIZE; i++)
                *((*firstNode)->info + i) = ' ';
        }
        *((*firstNode)->info + MAX_SIZE - 1) = '\0';
        bufferChar = fgetc(inputFile);    
        if(feof(inputFile)){
            printf("Koniec pliku\n");
            (*firstNode)->next = NULL;
            break; 
        }
        dataAmount--;
        if(dataAmount != 0){
            (*firstNode)->next = (NODE*)malloc(sizeof(NODE));
            (*firstNode)->next->prev = *(firstNode);
            *firstNode = (*firstNode)->next;
        }
        if(dataAmount == 0 || feof(inputFile))
            (*firstNode)->next = NULL;
    }
    *firstNode = tmp;
    tmp = NULL;
    return firstNode;
    }
    else
        return NULL;
}