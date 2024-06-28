#include "main.h"

void PrintListToFile(NODE* firstNode, FILE* outputFile){
    if(firstNode != NULL){
        fprintf(outputFile, "List:\n");
        for (int i = 0; firstNode != NULL; i++) {
            fprintf(outputFile, "NODE %d: %s\n", i, firstNode->info);
            firstNode = firstNode->next;
        }
    }
}
