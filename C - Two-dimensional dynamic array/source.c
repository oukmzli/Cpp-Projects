#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fillRow(int* newRow, int size) {
    int i;
    for (i = 0; i < size; i++) scanf("%d", (newRow + i));
}

void addRow(int*** matrix, int* newRow, int newRowSize, int insertAt, int* numRows, int** rowSizes) {
    if (newRowSize <= 0) return;
    *numRows += 1;
    *matrix = realloc(*matrix, (*numRows) * sizeof(int*));
    *rowSizes = realloc(*rowSizes, (*numRows) * sizeof(int));
    
    int i;
    for (i = *numRows - 1; i > insertAt; i--) {
        *(*matrix + i) = *(*matrix + i - 1);
        *(*rowSizes + i) = *(*rowSizes + i - 1);
    }
    
    *(*matrix + insertAt) = newRow;
    *(*rowSizes + insertAt) = newRowSize;
}

void deleteRow(int*** matrix, int* numRows, int** rowSizes, int deleteAt) {
    if (deleteAt < 0 || deleteAt >= *numRows) return;
    
    free(*(*matrix + deleteAt));
    
    int i;
    for (i = deleteAt; i < *numRows - 1; i++) {
        *(*matrix + i) = *(*matrix + i + 1);
        *(*rowSizes + i) = *(*rowSizes + i + 1);
    }
    
    *numRows -= 1;
    *matrix = realloc(*matrix, (*numRows) * sizeof(int*));
    *rowSizes = realloc(*rowSizes, (*numRows) * sizeof(int));
}

void insertElement(int** row, int* rowSize, int insertAt, int value) {
    *rowSize += 1;
    *row = realloc(*row, *rowSize * sizeof(int));
    if (insertAt > *rowSize-1) insertAt = *rowSize-1;
    
    int i;
    for (i = *rowSize - 1; i > insertAt; i--)
        *(*row + i) = *(*row + i - 1);
    
    *(*row + insertAt) = value;
}

void deleteElement(int** row, int* rowSize, int deleteAt) {
    int i;
    for (i = deleteAt; i < *rowSize - 1; i++)
        *(*row + i) = *(*row + i + 1);
    
    *rowSize -= 1;
    
    int* newRow = realloc(*row, *rowSize * sizeof(int));
    if (newRow != NULL || *rowSize == 0) {
        *row = newRow;
    }
}

void addColumn(int*** matrix, int* numRows, int** rowSizes, int* newColumn, int h, int insertAt) {
    int i;
    for (i = 0; i < *numRows && i < h; i++) {
        insertElement(&(*(*matrix + i)), &(*(*rowSizes + i)), insertAt, *(newColumn + i));
    }
    
    if (h > *numRows) {
        for (i = *numRows; i < h; i++) {
            int* newRow = (int*)malloc(sizeof(int));
            if (!newRow) break;
            *newRow = *(newColumn + i);
            
            addRow(matrix, newRow, 1, *numRows, numRows, rowSizes);
        }
    }
}

void deleteColumn(int*** matrix, int* numRows, int** rowSizes, int deleteAt) {
    int i = 0;
    while (i < *numRows) {
        if (deleteAt >= 0 && deleteAt < *(*rowSizes + i)) {
            deleteElement(&(*(*matrix + i)), &(*(*rowSizes + i)), deleteAt);
            if (*(*rowSizes + i) == 0) {
                deleteRow(matrix, numRows, rowSizes, i);
            } else i++;
        } else i++;
    }
}

void addBlock(int*** matrix, int* numRows, int** rowSizes, int r, int c, int h, int w, int** block) {
    int i;
    for (i = 0; i < h; i++) {
        if (r + i >= *numRows) {
            int* newRow = (int*)malloc(w * sizeof(int));
            memcpy(newRow, *(block + i), w * sizeof(int));
            addRow(matrix, newRow, w, *numRows, numRows, rowSizes);
        } else {
            int j;
            for (j = 0; j < w; j++) {
                if (c + j < *(*rowSizes + r + i)) {
                    insertElement((*matrix + r + i), (*(rowSizes) + r + i), c + j, *(*(block + i) + j));
                } else {
                    insertElement((*matrix + r + i), (*(rowSizes) + r + i), *(*rowSizes + r + i), *(*(block + i) + j));
                }
            }
        }
    }
}

void deleteBlock(int*** matrix, int* numRows, int** rowSizes, int r, int h, int c, int w) {
    int i = 0;
    while (i < h && (r + i) < *numRows) {
        int j; int tempSize = *(*rowSizes + r + i);
        for (j = 0; j < w && c + j < tempSize; j++) {
            deleteElement(&(*(*matrix + r + i)), &(*(*rowSizes + r + i)), c);
        }
        if (*(*rowSizes + r + i) == 0) {
            deleteRow(matrix, numRows, rowSizes, r + i);
            h--;
        } else {
            i++;
        }
    }
}

void fillBlock (int ***matrix, int* numRows, int** rowSizes, int rowSize) {
    int* newRow = (int*)malloc(rowSize * sizeof(int));
    fillRow(newRow, rowSize);
    addRow(matrix, newRow, rowSize, *numRows, numRows, rowSizes);
}


void funcAFR (int ***matrix, int* numRows, int** rowSizes) {
    int rowSize; scanf("%d", &rowSize);
    
    int* newRow = (int*)malloc(rowSize * sizeof(int));
    fillRow(newRow, rowSize);
    addRow(matrix, newRow, rowSize, 0, numRows, rowSizes);
}

void funcALR (int ***matrix, int* numRows, int** rowSizes) {
    int rowSize; scanf("%d", &rowSize);
    
    int* newRow = (int*)malloc(rowSize * sizeof(int));
    fillRow(newRow, rowSize);
    addRow(matrix, newRow, rowSize, *numRows, numRows, rowSizes);
}

void funcAFC(int ***matrix, int* numRows, int** rowSizes) {
    int h; scanf("%d", &h);
    
    int* newColumn = (int*)malloc(h * sizeof(int));
    fillRow(newColumn, h);
    addColumn(matrix, numRows, rowSizes, newColumn, h, 0);
    free(newColumn);
}

void funcALC(int ***matrix, int* numRows, int** rowSizes) {
    int h; scanf("%d", &h);
    
    int* newColumn = (int*)malloc(h * sizeof(int));
    fillRow(newColumn, h);
    
    
    int i;
    for (i = 0; i < *numRows && i < h; i++) {
        insertElement(&(*(*matrix + i)), &(*(*rowSizes + i)), (*(*rowSizes + i)), *(newColumn + i));
    }
    
    if (h > *numRows) {
        for (i = *numRows; i < h; i++) {
            int* newRow = (int*)malloc(sizeof(int));
            if (!newRow) break;
            *newRow = *(newColumn + i);
            
            addRow(matrix, newRow, 1, *numRows, numRows, rowSizes);
        }
    }
    
    free(newColumn);
}

void funcIBR (int ***matrix, int* numRows, int** rowSizes) {
    int r; scanf("%d", &r);
    int rowSize; scanf("%d", &rowSize);
    
    if (r < *numRows) {
        int* newRow = (int*)malloc(rowSize * sizeof(int));
        fillRow(newRow, rowSize);
        addRow(matrix, newRow, rowSize, r, numRows, rowSizes);
    }
}

void funcIAR (int ***matrix, int* numRows, int** rowSizes) {
    int r; scanf("%d", &r);
    int rowSize; scanf("%d", &rowSize);
    
    if (r < *numRows) {
        int* newRow = (int*)malloc(rowSize * sizeof(int));
        fillRow(newRow, rowSize);
        addRow(matrix, newRow, rowSize, r+1, numRows, rowSizes);
    }
}

void funcIBC (int ***matrix, int* numRows, int** rowSizes) {
    int c; scanf("%d", &c);
    int h; scanf("%d", &h);
    
    int* newColumn = (int*)malloc(h * sizeof(int));
    fillRow(newColumn, h);
    addColumn(matrix, numRows, rowSizes, newColumn, h, c);
    free(newColumn);
}

void funcIAC (int ***matrix, int* numRows, int** rowSizes) {
    int c; scanf("%d", &c);
    int h; scanf("%d", &h);
    
    int* newColumn = (int*)malloc(h * sizeof(int));
    fillRow(newColumn, h);
    addColumn(matrix, numRows, rowSizes, newColumn, h, c+1);
    free(newColumn);
}

void funcSWR (int ***matrix, int* numRows, int** rowSizes) {
    int r; scanf("%d", &r);
    int s; scanf("%d", &s);
    
    if (s < *numRows && r < *numRows && s != r) {
        int* tempRow = (*(*matrix + s));
        (*(*matrix + s)) = (*(*matrix + r));
        (*(*matrix + r)) = tempRow;
        
        int tempSize = (*(*rowSizes + s));
        (*(*rowSizes + s)) = (*(*rowSizes + r));
        (*(*rowSizes + r)) = tempSize;
    }
}

void funcSWC (int ***matrix, int* numRows, int** rowSizes) {
    int c; scanf("%d", &c);
    int d; scanf("%d", &d);
    
    int i;
    for (i = 0; i < *numRows; i++) {
        if (c < *(*rowSizes + i) && d < *(*rowSizes + i)) {
            int temp = *(*(*matrix + i) + c);
            *(*(*matrix + i) + c) = *(*(*matrix + i) + d);
            *(*(*matrix + i) + d) = temp;
        }
    }
}

void funcDFR (int*** matrix, int* numRows, int** rowSizes) {
    if (*numRows > 0) deleteRow(matrix, numRows, rowSizes, 0);
}

void funcDLR (int*** matrix, int* numRows, int** rowSizes) {
    if (*numRows > 0) deleteRow(matrix, numRows, rowSizes, *numRows-1);
}

void funcDFC (int ***matrix, int* numRows, int** rowSizes) {
    int i = 0;
    while (i < *numRows) {
        deleteElement(&(*(*matrix + i)), &(*(*rowSizes + i)), 0);
        
        if ((*(*rowSizes + i)) == 0) deleteRow(matrix, numRows, rowSizes, i);
        else i++;
    }
}

void funcDLC (int ***matrix, int* numRows, int** rowSizes) {
    int i = 0;
    while (i < *numRows) {
        deleteElement(&(*(*matrix + i)), &(*(*rowSizes + i)), *(*rowSizes + i));
        if (*(*rowSizes + i) == 0) {
            deleteRow(matrix, numRows, rowSizes, i);
        } else i++;
    }
}

void funcRMR (int ***matrix, int* numRows, int** rowSizes) {
    int r; scanf("%d", &r);
    if (r < *numRows) {
        deleteRow(matrix, numRows, rowSizes, r);
    }
}

void funcRMC(int ***matrix, int* numRows, int** rowSizes) {
    int c; scanf("%d", &c);
    deleteColumn(matrix, numRows, rowSizes, c);
}


void funcRMB(int ***matrix, int* numRows, int** rowSizes) {
    int r, h, c, w;
    scanf("%d %d %d %d", &r, &h, &c, &w);
    deleteBlock(matrix, numRows, rowSizes, r, h, c, w);
}


void funcISB(int ***matrix, int* numRows, int** rowSizes) {
    int r, c, h, w;
    scanf("%d %d %d %d", &r, &c, &h, &w);
    int** block = NULL;
    int* blockSizes = NULL;
    int blockRows = 0;
    int i = 0;
    while (i < h) {
        fillBlock(&block, &blockRows, &blockSizes, w);
        i++;
    }
    
    addBlock(matrix, numRows, rowSizes, r, c, blockRows, w, block);
}

void funcWRF(int*** matrix, int* numRows, int** rowSizes) {
    char *filename = (char*) malloc(16 * sizeof(char));
    scanf("%s", filename);
    
    FILE* fp = fopen(filename, "wb");
    fprintf(fp, "%d\n", *numRows);
    
    int i;
    for (i = 0; i < *numRows; i++) {
        unsigned short rowSize = (unsigned short)(*(*rowSizes + i));
        unsigned char* sizeBytes = (unsigned char*)malloc(2 * sizeof(unsigned char));
        *sizeBytes = (rowSize >> 8) & 0xFF;
        *(sizeBytes + 1) = rowSize & 0xFF;
        fwrite(sizeBytes, sizeof(unsigned char), 2, fp);
        free(sizeBytes);
        
        int j;
        for (j = 0; j < rowSize; j++) {
            int value = *(*(*matrix + i) + j);
            unsigned char* valueBytes = (unsigned char*)malloc(4 * sizeof(unsigned char));
            *valueBytes = (value >> 24) & 0xFF;
            *(valueBytes + 1) = (value >> 16) & 0xFF;
            *(valueBytes + 2) = (value >> 8) & 0xFF;
            *(valueBytes + 3) = value & 0xFF;
            fwrite(valueBytes, sizeof(unsigned char), 4, fp);
            free(valueBytes);
        }
    }
    
    fclose(fp);
    free(filename);
}


void funcRDF(int ***matrix, int* numRows, int** rowSizes) {
    char *filename = (char*) malloc(16 * sizeof(char));
    scanf("%s", filename);
    
    FILE* fp = fopen(filename, "rb");
    
    fscanf(fp, "%d\n", numRows);
    
    *matrix = (int**)malloc(*numRows * sizeof(int*));
    *rowSizes = (int*)malloc(*numRows * sizeof(int));
    
    int i;
    for (i = 0; i < *numRows; i++) {
        unsigned char* sizeBytes = (unsigned char*)malloc(2 * sizeof(unsigned char));
        fread(sizeBytes, sizeof(unsigned char), 2, fp);
        unsigned short rowSize = (*(sizeBytes) << 8) | *(sizeBytes + 1);
        *(*rowSizes + i) = rowSize;
        free(sizeBytes);
        
        *(*matrix + i) = (int*)malloc(rowSize * sizeof(int));
        
        int j;
        for (j = 0; j < rowSize; j++) {
            unsigned char* valueBytes = (unsigned char*)malloc(4 * sizeof(unsigned char));
            fread(valueBytes, sizeof(unsigned char), 4, fp);
            *(*(*matrix + i) + j) = (*(valueBytes) << 24) |
            (*(valueBytes + 1) << 16) |
            (*(valueBytes + 2) << 8) |
            *(valueBytes + 3);
            free(valueBytes);
        }
    }
    
    fclose(fp);
    free(filename);
}

void funcPRT (int*** matrix, int* numRows,  int** rowSizes) {
    printf("%i\n", *numRows);
    int i;
    for (i = 0; i < *numRows; i++) {
        printf("%i", *(*rowSizes + i));
        int j;
        for (j = 0; j < *(*rowSizes + i); j++) {
            printf(" %i", *(*(*matrix + i) + j));
        }
        printf("\n");
    }
}

int main(void) {
    int** matrix = NULL;
    int* rowSizes = NULL;
    int numRows = 0;
    
    char* command = malloc(4); scanf("%3s", command);
    
    while (strcmp(command, "END") != 0) {
        
        if (strcmp(command, "AFR") == 0) {
            funcAFR(&matrix, &numRows, &rowSizes);
        } else if (strcmp(command, "ALR") == 0) {
            funcALR(&matrix, &numRows, &rowSizes);
        } else if (strcmp(command, "AFC") == 0) {
            funcAFC(&matrix, &numRows, &rowSizes);
        } else if (strcmp(command, "ALC") == 0) {
            funcALC(&matrix, &numRows, &rowSizes);
        } else if (strcmp(command, "IBR") == 0) {
            funcIBR(&matrix, &numRows, &rowSizes);
        } else if (strcmp(command, "IAR") == 0) {
            funcIAR(&matrix, &numRows, &rowSizes);
        } else if (strcmp(command, "IBC") == 0) {
            funcIBC(&matrix, &numRows, &rowSizes);
        } else if (strcmp(command, "IAC") == 0) {
            funcIAC(&matrix, &numRows, &rowSizes);
        } else if (strcmp(command, "SWR") == 0) {
            funcSWR(&matrix, &numRows, &rowSizes);
        } else if (strcmp(command, "SWC") == 0) {
            funcSWC(&matrix, &numRows, &rowSizes);
        } else if (strcmp(command, "DFR") == 0) {
            funcDFR(&matrix, &numRows, &rowSizes);
        } else if (strcmp(command, "DLR") == 0) {
            funcDLR(&matrix, &numRows, &rowSizes);
        } else if (strcmp(command, "DFC") == 0) {
            funcDFC(&matrix, &numRows, &rowSizes);
        } else if (strcmp(command, "DLC") == 0) {
            funcDLC(&matrix, &numRows, &rowSizes);
        } else if (strcmp(command, "RMR") == 0) {
            funcRMR(&matrix, &numRows, &rowSizes);
        } else if (strcmp(command, "RMC") == 0) {
            funcRMC(&matrix, &numRows, &rowSizes);
        } else if (strcmp(command, "RMB") == 0) {
            funcRMB(&matrix, &numRows, &rowSizes);
        } else if (strcmp(command, "ISB") == 0) {
            funcISB(&matrix, &numRows, &rowSizes);
        } else if (strcmp(command, "WRF") == 0) {
            funcWRF(&matrix, &numRows, &rowSizes);
        } else if (strcmp(command, "RDF") == 0) {
            funcRDF(&matrix, &numRows, &rowSizes);
        } else if (strcmp(command, "PRT") == 0) {
            funcPRT(&matrix, &numRows, &rowSizes);
        }
        
        scanf("%3s", command);
    }
    
    int i;
    for (i = 0; i < numRows; i++) free(*(matrix + i));
    free(matrix);
    free(rowSizes);
    free(command);
    
    return 0;
}
