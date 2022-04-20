#include "../dict.h"

#define SCALEFACTOR 2

struct node {
   char* word;
   struct node* next;
};
typedef struct node node;

struct dict {
   struct node** hashtable;
   int size;
};


int _hash(unsigned int sz, const char *s);
node* _allocateData(const char* s);
bool _inList(node* n, const char* s);
void test(void);
