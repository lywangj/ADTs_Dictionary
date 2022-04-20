#include "../dict.h"
#include <time.h>
#include <ctype.h>

#define SCALEFACTOR 20
#define KHASHES 11

struct dict {
   bool* arr;
   int size;
};

unsigned long* _hashes(unsigned int sz, const char* s);
int _hash(unsigned int sz, const char *s);
void test(void);
