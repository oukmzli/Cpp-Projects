#include <iostream>
#include <cstdarg>

#define MAX_SIZE 30

typedef char OBJECT_TYPE[MAX_SIZE];

struct NODE{
NODE* prev;
OBJECT_TYPE info;
NODE* next;
};

// inserts
void Insert(NODE**, OBJECT_TYPE);
void Insert(OBJECT_TYPE, NODE**);
void Insert(NODE**, NODE*, OBJECT_TYPE);
void Insert(NODE*, OBJECT_TYPE);

// display
void Display(NODE*);

// removes
void Remove(NODE**);
void Remove(NODE*);
void Remove(NODE**, NODE*);
void Remove(NODE*, NODE**);

// clear
void ClearList(NODE**);

// files
void PrintListToFile(NODE*, FILE*);
NODE** ReadListFromFile(int, FILE*);
