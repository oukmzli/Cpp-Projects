#include "main.h"
//main file
int main(){
    FILE* input;
    OBJECT_TYPE testObject = "testStr";
    input = fopen("inputFile.txt", "r");
    FILE* output;
    output = fopen("outputFile.txt", "w");
    if(input == NULL || output == NULL){
        printf("Blad otwarcia pliku\n");
        return -1;
    }
    //test:
    NODE** head = ReadListFromFile(34,input);
    Display(*head);
    printf("--------------------\n");
    //insert last
    Insert(head,testObject);
    Display(*head);
    printf("--------------------\n");
    //insert first
    Insert(testObject, head);
    Display(*head);
    printf("--------------------\n");
    //remove first
    Remove(head);
    Display(*head);
    printf("--------------------\n");
    //insert after
    Insert(*head, testObject);
    Display(*head);
    printf("--------------------\n");
    //insert before
    Insert(head,(*head)->next->next,testObject);
    Display(*head);
    printf("--------------------\n");
    //remove last
    Remove(*head);
    Display(*head);
    printf("--------------------\n");
    //print to file
    PrintListToFile(*head, output);
    
    ClearList(head);
    if(head == NULL)
        printf("list cleared\n");
    return 0;
}
