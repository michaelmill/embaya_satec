#include <stdio.h>
#include <memory.h>

//------------------------------------------------------------------;
//  libstr: mid.
//------------------------------------------------------------------;

char* mid(char* s,
          int   b,
          int   e) {
   int i = 0,
       c = 0;

   char* buf;
   buf = (char *)calloc(strlen(s), sizeof(char)); 

   if (e <= 0) {
      return(NULL);  
   }else if (e > strlen(s)) {
      e = strlen(s);
   }

   for(i = b; i < e; i++, c++) {
      if (i < e - 2) {
         buf[c] = s[i];
         //printf ("(%s - %i)\n", buf, i);
      }else{
         return(buf);
      }
   }

   return(buf);
}

//------------------------------------------------------------------;
//
//------------------------------------------------------------------;

enum l_definition {

   l_max_bit    = 1,
   l_max_nibble = 4,
   l_max_name   = 64,
   l_max_data   = 256,
   l_max_stack  = 512,
   l_max_buffer = 64000,
   l_max_string = 1024,
   l_max_config = 3, // configuration file depth.
};

struct c_satec_conf {

      char*           l_items  [l_max_data];
      char*           l_list   [l_max_data];

      char*           l_database_name;
      char*           l_database_statement;    
};
