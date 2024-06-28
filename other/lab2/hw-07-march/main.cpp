#include <stdio.h>
#include <stdlib.h>

struct Record {
    int id;
    float value;
    char name[50];
    char type;
    unsigned long timestamp;
};

void printLine(const char* start, const char* middle, const char* end) {
    printf("%s", start);
    for(int i = 1; i < 10; i++) printf("─");
    printf("%s", middle);
    for(int i = 11; i < 21; i++) printf("─");
    printf("%s", middle);
    for(int i = 22; i < 72; i++) printf("─");
    printf("%s", middle);
    for(int i = 73; i < 83; i++) printf("─");
    printf("%s", middle);
    for(int i = 84; i < 94; i++) printf("─");
    printf("%s\n", end);
}

void printHeader() {
    printLine("┌", "┬", "┐");
    printf("│%-9s│%-10s│%-50s│%-10s│%-10s│\n", "ID", "Value", "Name", "Type", "Timestamp");
    printLine("├", "┼", "┤");
}

void printRecord(struct Record record) {
    printf("│%-9d│%-10.4f│%-50s│%-10c│%-10lu│\n", record.id, record.value, record.name, record.type, record.timestamp);
}

int main() {
    int n;
    printf("%s\t%s\t%s\t%s\t%s", "Enter", "the", "number", "of", "records:");
    scanf("%d", &n);
    
    struct Record* records = (struct Record*)malloc(n * sizeof(struct Record));
    
    for (int i = 0; i < n; i++) {
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d:\n", "Enter", "id,", "value,", "name,", "type,", "timestamp", "for record", i+1);
        scanf("%d %f %49s %c %lux", &records[i].id, &records[i].value, records[i].name, &records[i].type, &records[i].timestamp);
    }
    
    printHeader();
    for (int i = 0; i < n; i++) {
        printRecord(records[i]);
        if(i < n - 1) printLine("├", "┼", "┤");
    }
    printLine("└", "┴", "┘");
    
    free(records);
    return 0;
}
