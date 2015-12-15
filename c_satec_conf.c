/* -----------------------------------------------------------------;
 * $source   : / $
 * $revision : 1.0 $
 * $author   : wyr@null.co.za $
 * $date     : 2015/12/14 12:13:00 SAST $
 * $desc     : $
 * $log      : $
 *
 * -----------------------------------------------------------------;
 */

//------------------------------------------------------------------;
//
//------------------------------------------------------------------;

char* m_satec_conf_find ( char                *l_key,
                          struct c_satec_conf *l_c ) {

   int i = 0;

   for (i = 0; i <__len(l_c->l_items); i++) {
      if (strcmp(l_c->l_items[i], l_key) == 0) {

         //printf     ("(%s)", mid (l_c->l_list[i], strlen(l_key) + 1, strlen(l_c->l_list[i])));

         return mid (l_c->l_list[i], strlen(l_key) + 1, strlen(l_c->l_list[i]));
      }
  }

   return '\0';
}

//------------------------------------------------------------------;
//
//------------------------------------------------------------------;

void handle_line(char *line) {
  printf("%s", line);
}

int m_satec_conf_read ( const char          *f_loc, 
                        struct c_satec_conf *l_c ) {

   int   size = 1024, pos;
   int   c;
   int   count = 0;
   char *buffer = (char *)malloc(size);

   FILE *f = fopen(f_loc, "r");

   if(f) {
      do { // read all lines in file
         pos = 0;
         do{ // read one line
            c = fgetc(f);
            if(c != EOF) buffer[pos++] = (char)c;
            if(pos >= size - 1) { // increase buffer length - leave room for 0
               size *=2;
               buffer = (char*)realloc(buffer, size);
            }
         }while(c != EOF && c != '\n');
         buffer[pos] = 0;
         l_c->l_list[count] = (char*) malloc (size);
         sprintf (l_c->l_list[count], "%s", buffer);

         count++;

      } while(c != EOF); 
      fclose(f);           
   }
   free(buffer);
   return EXIT_SUCCESS;
}

//------------------------------------------------------------------;
//
//------------------------------------------------------------------;

int m_satec_conf_configure ( struct c_satec_conf *l_c ) {

   l_c->l_items [0] = "database_name";
   l_c->l_items [1] = "database_statement";
   l_c->l_items [2] = '\0';

   m_satec_conf_read ("cfg/e.cfg", l_c);

   return 1;
}
