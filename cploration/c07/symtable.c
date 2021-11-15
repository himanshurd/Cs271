#include "symtable.h"
#include <stdio.h>
struct Symbol* hashArray[SYMBOL_TABLE_SIZE];
struct Symbol* item;


void display_table() {
   int i = 0;
	
   for(i = 0; i<SYMBOL_TABLE_SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf(" (%s,%d)",hashArray[i]->name,hashArray[i]->address);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}

unsigned int hashCode(char *str)  {
  unsigned int hash = 5381;
  int c;
  while ((c = *str++))
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  return hash % SYMBOL_TABLE_SIZE;
}

struct Symbol *find(char *str) {
   //get the hash 
   int hashIndex = hashCode(str);  
	
   //move in array until an empty 
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->name == str)
         return hashArray[hashIndex]; 
			
      ++hashIndex;
		
      hashIndex %= SYMBOL_TABLE_SIZE;
   }        
	
   return NULL;        
}

void insert(char *key, hack_addr data) {

  struct Symbol *item = (struct Symbol*) malloc(sizeof(struct Symbol));
   item->address = data;  
   item->name = key;

   int hashIndex = hashCode(key);

   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->name != NULL) {

      ++hashIndex;
	
      hashIndex %= SYMBOL_TABLE_SIZE;
   }
	
   hashArray[hashIndex] = item;
}
