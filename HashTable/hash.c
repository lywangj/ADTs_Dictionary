#include "hash.h"

/* The maximum number of words we will want to input.
   Exact : Hashtable will be twice this size
*/
dict* dict_init(unsigned int maxwords)
{
   dict* d = (dict*) malloc(1, sizeof(dict));

   // hidden initialising a hash table

   return d;
}

/* Add string to dictionary
   Exact : A deep-copy is stored in the hashtable only if the word
           has not already been added to the table.
*/
bool dict_add(dict* x,  const char* s)
{
   if(x==NULL || s==NULL || strcmp(s, "")==0){
      return false;
   }

   // generate hash number
   int hash_numb = _hash(x->size, s);

   // create a newnode with word
   // insert to dict
   // if collision, calloc new space for links

   // set a new node
   node* n;
   n = _allocateData(s);

   // add a new node at the beginning of the list
   n->next = x->hashtable[hash_numb];
   x->hashtable[hash_numb] = n;

   return true;
}

node* _allocateData(const char* s)
{
   if(s==NULL || strcmp(s, "")==0){
      on_error("Invalid input word is found.");
   }

   node* p = (node*) ncalloc(1, sizeof(node));
   p->word= (char*) ncalloc(strlen(s)+1, sizeof(char));
   strcpy(p->word, s);
   p->next = NULL;
   return p;
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
   
   // generate hash number
   int hash_numb = _hash(x->size, s);
   
   if(x->hashtable[hash_numb]==NULL){
      return false;
   }

   // set a new pointer in node list
   node* p;
   p = NULL;

   // add a new node at the beginning of the list
   p = x->hashtable[hash_numb];
   
   if(_inList(p, s)){
      return true;
   }
   return false;
}

bool _inList(node* n, const char* s)
{
   if(n==NULL || s==NULL){
      return false;
   }
   do{
      if(strcmp(n->word, s)==0){
         return true;
      }
      n = n->next;
   }while(n!=NULL);
   return false;
}

/* Frees all space used */
void dict_free(dict* x)
{
   // hidden free space
}

void test(void)
{
   // hidden;
}
