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

#if !defined(__E_CONF__)
#define	     __E_CONF__

//------------------------------------------------------------------;
//
//------------------------------------------------------------------;

struct c_conf {

   public :

                      c_conf      ();
      virtual        ~c_conf      ();

      int             m_test      ();
      int             m_read      ( const char *f, c_conf *l_c );
      char           *m_find      ( char *l_key, c_conf *l_c );
      int             m_init      ( c_conf *l_c );

   protected :

      char*           l_items  [l_max_data];
      char*           l_list   [l_max_data];

    
};

#endif	/* !defined(__E_CONF__) */
