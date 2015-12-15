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

#if !defined(__E_ERR__)
#define	     __E_ERR__

//------------------------------------------------------------------;
//
//------------------------------------------------------------------;

struct c_err {

   public :

                      c_err       ();
      virtual        ~c_err       ();

      int             m_set       ( const char *l_err, c_err *l_e );
      int             m_get       ( const char *l_err );

   protected :

      char*           l_buffer [l_max_data][l_max_bit];
      int             l_index;

    
};

#endif	/* !defined(__E_ERR__) */
