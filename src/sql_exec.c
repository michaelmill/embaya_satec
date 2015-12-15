/* -----------------------------------------------------------------;
 * $source   : ~/src/db/sql_lite/sql_exec $
 * $revision : 1.0 $
 * $author   : wyrvern@null.co.za, SQLite (http://www.sqlite.org/quickstart.html) $
 * $date     : 2011/07/16 21:18:00 $
 * $desc     : $
 * $log      : $
 * -----------------------------------------------------------------;
 */

#include <stdio.h>
#include <sqlite3.h>

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

//--------------------------------------------------------------------------;
//
//--------------------------------------------------------------------------;


int main (int    argc, 
          char **argv, 
          char **envp) {

	sqlite3 *l_database;
	char    *l_error_message = 0;
	int      l_result;

	if( argc != 3 ) {
		fprintf (stderr, "usage : %s DATABASE SQL-STATEMENT\n", argv[0]);
		exit    (1);
	}

	l_result = sqlite3_open(argv[1], &l_database);

	if( l_result ) {
		fprintf       (stderr, "Can't open database : %s\n", sqlite3_errmsg(l_database));
		sqlite3_close (l_database);
		exit          (1);
	}

	l_result = sqlite3_exec(l_database, argv[2], m_function_callback, 0, &l_error_message);

	if( l_result != SQLITE_OK ) {
		fprintf       (stderr, "SQL error : %s\n", l_error_message);
		sqlite3_free  (l_error_message);
	}
	sqlite3_close(l_database);

	return 0;
}

