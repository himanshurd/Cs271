#include "symtable.h"
#include <stdio.h>

struct Symbol* hashArray[SYMBOL_TABLE_SIZE] = { NULL };
struct Symbol* item;

void symtable_display_table() {
   int i = 0;
	
   for(i = 0; i<SYMBOL_TABLE_SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf(" (%s,%d)",hashArray[i]->name,hashArray[i]->address);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}

unsigned int hashCode(char * key)  {
  unsigned int hash = 5381;
  int c;
  while ((c = *key++))
    hash = ((hash << 5) + hash) + c;
  return hash % SYMBOL_TABLE_SIZE;
}


struct Symbol *symtable_find(char * key) {
   int hashIndex = hashCode(key);  
   while(hashArray[hashIndex] != NULL) {
      if(hashArray[hashIndex]->name == key) 
         return hashArray[hashIndex]; 
			
      
      ++hashIndex;
		
      
      hashIndex %= SYMBOL_TABLE_SIZE;
   }        
   return NULL;        
}

void symtable_insert(char* key, hack_addr addr) {

  struct Symbol *item = (struct Symbol*) malloc(sizeof(struct Symbol));
   item->address = addr;  
   item->name = key;

   
   int hashIndex = hashCode(key);

  
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->name != NULL) {
      
      ++hashIndex;
		
      
      hashIndex %= SYMBOL_TABLE_SIZE;
   }
    hashArray[hashIndex] = item;
}
