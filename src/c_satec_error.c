//------------------------------------------------------------------;
//
//------------------------------------------------------------------;

int m_set ( const char *l_err,
            c_err      *l_e ) {

   l_e->l_buffer[l_index][0] = (char*) malloc (sizeof(l_e->l_buffer[l_index][0]));

   sprintf (l_e->l_buffer[l_index][0], "%s\n", l_err);

   printf  ("%s\n", l_e->l_buffer[l_index][0]);

   l_e->l_index++;

   return 1;
}
