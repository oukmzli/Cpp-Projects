#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
    int id;
    float value;
    char name[50];
    char type;
    unsigned long timestamp;
};

void printLine(const char* start, const char* middle, const char* end, FILE* file) {
    fprintf(file, "%s", start);
    for(int i = 1; i < 10; i++) fprintf(file, "─");
    fprintf(file, "%s", middle);
    for(int i = 11; i < 21; i++) fprintf(file, "─");
    fprintf(file, "%s", middle);
    for(int i = 22; i < 72; i++) fprintf(file, "─");
    fprintf(file, "%s", middle);
    for(int i = 73; i < 83; i++) fprintf(file, "─");
    fprintf(file, "%s", middle);
    for(int i = 84; i < 94; i++) fprintf(file, "─");
    fprintf(file, "%s\n", end);
}

void printHeader(FILE* file) {
    printLine("┌", "┬", "┐", file);
    fprintf(file, "│%-9s│%-10s│%-50s│%-10s│%-10s│\n", "ID", "Value", "Name", "Type", "Timestamp");
    printLine("├", "┼", "┤", file);
}

void printRecord(struct Record record) {
    printf("│%-10d│%-10.4f│%-50s│%-10c│%-10lu│\n", record.id, record.value, record.name, record.type, record.timestamp);
}

void writeRecordsToFile(struct Record* records, int n, const char* filename) {
    
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file for writing");
        return;
    }
    
    printHeader(file);
    for (int i = 0; i < n; i++) {
        fprintf(file, "│%-9d│%-10.4f│%-50s│%-10c│%-10lu│\n",
                records[i].id, records[i].value, records[i].name, records[i].type, records[i].timestamp);
        if(i < n - 1) printLine("├", "┼", "┤", file);
    }
    printLine("└", "┴", "┘", file);
    
    fclose(file);
}


void readRecordsFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    char buffer[1024];
    struct Record record;
    int recordsRead = 0;

    // Пропускаем заголовок и разделители в начале файла
    for (int i = 0; i < 3; i++) fgets(buffer, sizeof(buffer), file);

    while (!feof(file)) {
        if (fscanf(file, "│ %d │ %f │ %49[^│] │ %c │ %lu │%*c",
                   &record.id, &record.value, record.name, &record.type, &record.timestamp) == 5) {
            // Успешное чтение записи, печатаем её
            printRecord(record);
            recordsRead++;
            
            // Пропускаем разделительную строку, если не достигли конца файла
            if (!feof(file)) {
                fgets(buffer, sizeof(buffer), file);
            }
        } else {
            // Не удалось прочитать запись, возможно, достигли конца файла или есть ошибка формата
            break;
        }
    }
    printf("Total records read: %d\n", recordsRead);
    fclose(file);
}

void editRecords(int n, const char* filename) {
    struct Record* records = (struct Record*)malloc(n * sizeof(struct Record));
    readRecordsFromFile(records, n, filename);
    int index;
    
    printf("Enter index of record you want to change: ");
    scanf("%d", &index);
    if (index > n || index < 1) {
        printf("Index is out of bounds");
        return;
    }
    
    printf("Enter id, value, name, type, timestamp for record %d:\n", index);
    scanf("%d %f %49s %c %lu", &records[index-1].id, &records[index-1].value, records[index-1].name, &records[index-1].type, &records[index-1].timestamp);
    
    writeRecordsToFile(records, n, filename);
}

int main(void) {
    int n;
    printf("Enter the number of records: ");
    scanf("%d", &n);
    
    struct Record* records = (struct Record*)malloc(n * sizeof(struct Record));
    
    for (int i = 0; i < n; i++) {
        printf("Enter id, value, name, type, timestamp for record %d:\n", i+1);
        scanf("%d %f %49s %c %lu", &records[i].id, &records[i].value, records[i].name, &records[i].type, &records[i].timestamp);
    }
    
    writeRecordsToFile(records, n, "record.txt");
    editRecords(n, "record.txt");
    
    free(records);
    return 0;
    
}
