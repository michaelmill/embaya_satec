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

//---------------------------------------------------------------------------;
// ./e test.db "select * from company"
//---------------------------------------------------------------------------;

int main (int    argc, 
          char **argv, 
          char **envp) {

   struct c_satec_conf *c = malloc(sizeof(struct c_satec_conf));

   m_satec_conf_configure (c);

   c->l_database_name      = (char*) malloc (sizeof(c->l_database_name));
   c->l_database_statement = (char*) malloc (sizeof(c->l_database_statement));

   sprintf (c->l_database_name,      "%s", m_satec_conf_find ("database_name", c));
   sprintf (c->l_database_statement, "%s", m_satec_conf_find ("database_statement", c));

   m_satec_database_exec (c->l_database_name, c->l_database_statement);
}
