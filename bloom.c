#include "specific.h"

/* The maximum number of words we will want to input.
   Approx : Hashtable will be (e.g.) 20 times this size
*/
dict* dict_init(unsigned int maxwords)
{

   dict* d = (dict*) malloc(1, sizeof(dict));

   // hidden initialising a bit array

   return d;
}

/* Add string to dictionary
   Approx : Multiple hashes (e.g. 11) are computed and corresponding
            Boolean flags set in the Bloom hashtable. 
*/
bool dict_add(dict* x,  const char* s)
{
   if(x==NULL || s==NULL || strcmp(s, "")==0){
      return false;
   }

   // generates hash numbers
   unsigned long* hashes;
   hashes = _hashes(x->size, s);

   // marks in bit array
   for(int i=0; i<KHASHES; ++i){
      unsigned long num = hashes[i];
      x->arr[num%(x->size)] = true;
   }

   free(hashes);
   return true;
}

unsigned long* _hashes(unsigned int sz, const char* s)
{
   // hidden conditions

   unsigned long* hashes = ncalloc(KHASHES, sizeof(unsigned long));
   unsigned long bh = _hash(sz, s);
   int ln = strlen(s);
   // If two different strings have the same bh, then
   // we need a separate way to distiguish them when using
   // bh to generate a sequence
   
   // hidden generating

   return hashes;
}

int _hash(unsigned int sz, const char *s)
{
   // generate hash number of incoming word
}

/* Returns true if the word is already in the dictionary,
   false otherwise.
*/
bool dict_spelling(dict* x, const char* s)
{
   if(x==NULL || s==NULL || strcmp(s, "")==0){
      return false;
   }

   // hash number
   unsigned long* hashes;
   hashes = _hashes(x->size, s);

   // check each cell in boolean array
   bool is_falseMatch = false;
   for(int i=0; i<KHASHES; ++i){
      unsigned long num = hashes[i];
      if(x->arr[num%(x->size)] != true){
         is_falseMatch = true;
      }
   }

   free(hashes);

   if(is_falseMatch==false){
      return true;
   }
   return false;
}

/* Frees all space used */
void dict_free(dict* x)
{
   // hidden free space
}


void test(void)
{
   // hidden
}
