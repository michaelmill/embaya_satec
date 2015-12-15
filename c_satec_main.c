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

int   m_satec_conf_configure (struct c_satec_conf *c);
int   m_satec_database_exec  (char* l_database_name, char* l_database_statement);
char* m_satec_conf_find      (char *l_key, struct c_satec_conf *l_c);
int   m_satec_log_write      (const char *text);

//---------------------------------------------------------------------------;
//
//---------------------------------------------------------------------------;

char* concat (char *s1, char *s2) {

    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);

    return result;
}

//---------------------------------------------------------------------------;
//
//---------------------------------------------------------------------------;

char *time_stamp() {

   char  *timestamp = (char *)malloc(sizeof(char) * 16);
   time_t ltime;

   ltime = time(NULL);
   struct tm *tm;
   tm    = localtime(&ltime);

   sprintf(timestamp, "%04d/%02d/%02d - %02d:%02d.%02d", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);

   return timestamp;
}

//---------------------------------------------------------------------------;
// ./e test.db "select * from company"
//---------------------------------------------------------------------------;

int main (int    argc, 
          char **argv, 
          char **envp) {

   struct c_satec_conf *c = malloc(sizeof(struct c_satec_conf));

   m_satec_conf_configure (c);

   m_satec_log_write (concat(time_stamp(), " - log : (setup basic configuration)"));

   c->l_database_name      = (char*) malloc (sizeof(c->l_database_name));
   c->l_database_statement = (char*) malloc (sizeof(c->l_database_statement));

   sprintf (c->l_database_name,      "%s", m_satec_conf_find ("database_name", c)); 
   sprintf (c->l_database_statement, "%s", m_satec_conf_find ("database_statement", c));

   m_satec_database_exec (c->l_database_name, c->l_database_statement);

   m_satec_log_write (concat(time_stamp(), " - log : (execute database)"));

}
