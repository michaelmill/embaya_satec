/* -----------------------------------------------------------------;
 * $source   : / $
 * $revision : 1.0 $
 * $author   : wyr@null.co.za $
 * $date     : 2015/12/14 15:07:00 SAST $
 * $desc     : $
 * $log      : $
 *
 * -----------------------------------------------------------------;
 */

//--------------------------------------------------------------------------;
//
//--------------------------------------------------------------------------;

static int m_function_callback (void  *l_not_used, 
                                int    argc, 
                                char **argv, 
                                char **l_column_name) {

   int i;

   for ( i = 0; i < argc; i++) {
      printf("%s = %s\n", l_column_name[i], argv[i] ? argv[i] : "NULL");
   }

   printf("\n");

   return 0;
}

//---------------------------------------------------------------------------;
//
//---------------------------------------------------------------------------;

int m_satec_database_exec (char* l_database_name,
                           char* l_database_statement) {

   sqlite3 *l_database;
   char    *l_error_message = 0;
   int      l_result;

 //if( argc != 3 ) {
    //fprintf (stderr, "usage : %s DATABASE SQL-STATEMENT\n", argv[0]);
    //exit    (1);
 //}

   l_result = sqlite3_open(l_database_name, &l_database);

   if( l_result ) {
      fprintf       (stderr, "Can't open database : %s\n", sqlite3_errmsg(l_database));
      sqlite3_close (l_database);
      exit          (1);
   }
   l_result = sqlite3_exec(l_database, l_database_statement, m_function_callback, 0, &l_error_message);

   if( l_result != SQLITE_OK ) {
      fprintf       (stderr, "SQL error : %s\n", l_error_message);
      sqlite3_free  (l_error_message);
   }
   sqlite3_close(l_database);

   return 0;
}
