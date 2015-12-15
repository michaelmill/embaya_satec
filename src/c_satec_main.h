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

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h>       // clock_t, clock, CLOCKS_PER_SEC
#include <math.h>       // sqrt 

#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <unistd.h>    // write 
#include <pthread.h>   // for threading , link with lpthread

#include <sqlite3.h>

//---------------------------------------------------------------------------;
//
//---------------------------------------------------------------------------;

int cint(char *s) {
   return atoi (s);
}

//------------------------------------------------------------------;
//  libstr: array string length / 0
//------------------------------------------------------------------;

int __len (char* s[]) {
   int i = 0;
   while (s[i] != 0) {
      i++;
   }
   return i;
}

//---------------------------------------------------------------------------;
//
//---------------------------------------------------------------------------;

struct c_satec_main {

     int j;

};
