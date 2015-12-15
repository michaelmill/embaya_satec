/* -----------------------------------------------------------------;
 * $source   : c:/ $
 * $revision : 1.0 $
 * $author   : root@null.co.za $
 * $date     : 2004/12/18 15:03:00 $
 * $desc     : $
 * $log      : $
 *
 * -----------------------------------------------------------------;
 */

//------------------------------------------------------------------;
//
//------------------------------------------------------------------;

c_conf::c_conf ( void ) {

   return;
}

//------------------------------------------------------------------;
// TODO : dealloc for members globally - ?
//------------------------------------------------------------------;

c_conf::~c_conf ( void ) {

   delete [] e_conf;

   return;
}

//------------------------------------------------------------------;
//
//------------------------------------------------------------------;

char* c_conf::m_find ( char   *l_key,
                       c_conf *l_c ) {

   for (int i=0; i <__len(l_c->l_items); i++) {
      if (strcmp(l_c->l_items[i], l_key) == 0) {
         return mid (l_c->l_list[i], strlen(l_key)+1, strlen(l_c->l_list[i]));
      }
   }
   return null;
}

//------------------------------------------------------------------;
//
//------------------------------------------------------------------;

int c_conf::m_read ( const char *f, 
                     c_conf     *l_c ) {

   FILE *l_file   = fopen (f, "r");

   char s [255];
   char *h;
   int  c = 0;

   if ( l_file == NULL ) {
      e_err->m_set ("[error : (m_read)] [statement : (l_file_not_found_error)]", e_err);
      // TODO : print error return on exit?
      exit (0);
      return -1;
   }
	
   while (1) {
      int r = fscanf (l_file, "%s", &s);
      if (r == EOF) break;

      l_c->l_list[c] = (char*) malloc (sizeof(s));
      sprintf ( l_c->l_list[c], "%s", s );
      c++;
   }

   fclose(l_file);

   return 0;
}

//------------------------------------------------------------------;
//
//------------------------------------------------------------------;

int c_conf::m_init ( c_conf *l_c ) {

   l_c->l_items [0] = "name";
   l_c->l_items [1] = "width";
   l_c->l_items [2] = "height";
   l_c->l_items [3] = "bpp";
   l_c->l_items [4] = "full";
   l_c->l_items [5] = '\0';

   m_read ("cfg\\e.cfg", e_conf);

   return 1;
}

