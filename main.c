
#include "dict.h"

#define BIGSTR 1000

int main(int argc, char* argv[])
{
   char str[BIGSTR];
   dict* x = dict_init(400000);
   
   // read file1
   // add every new word in dictionary

   // read file2
   // check words in file2 exists in dictionary
   // if the incoming word does not exist in dictionary, add it in dictionary
   
   dict_free(x);
   return EXIT_SUCCESS;
}
