/* Andre Augusto Giannotti Scota (a2gs)               
 * andre.scota@gmail.com
 *
 * A function error type
 *
 * MIT License
 *
 */

/* <file name>
 * <File description>
 *
 *  Who     | When       | What
 *  --------+------------+----------------------------
 *   a2gs   | 01/01/2002 | Creation
 *          |            |
 */

#ifndef __A2GS_TOOLBOX_ERRO_H__
#define __A2GS_TOOLBOX_ERRO_H__


/* *** INCLUDES *** */
#include <string.h>


/* *** DEFINES *** */
#define A2GS_TOOLBOX_ERRO_STR_SIZE 250

/* Clear de erro_t variable */
#define A2GS_TOOLBOX_GET_ERRO(__err_)       (__err_.errno)

/* Return the erro's number defined by someone into a erro_t variable */
#define A2GS_TOOLBOX_GET_ERROSTRING(__err_) (__err_.errstr)

/* Return the erro's message defined by someone into a erro_t variable */
#define A2GS_TOOLBOX_CLEAR_ERRO(__err_){                                                             \
                                       	__err_.errno = 0;                                            \
                                       	memset(__err_.errstr, '\0', A2GS_TOOLBOX_ERRO_STR_SIZE + 1); \
                                       }

/* Define a erro into a erro_t variable
 * __err_        - erro_t variable
 * __errno_      - error number
 * __errstr_     - error message
 * __errstrSize_ - Size of __errstr_ in bytes (max size can be A2GS_TOOLBOX_ERRO_STR_SIZE)
 */
#define A2GS_TOOLBOX_SET_ERRO(__err_, __errno_, __errstr_, __errstrSize_){                                                                       \
                              	__err_.errno = __errno_;                                                                                         \
                              	memcpy(__err_.errstr, __errstr_,                                                                                 \
                              	(A2GS_TOOLBOX_ERRO_STR_SIZE < __errstrSize_ ? A2GS_TOOLBOX_ERRO_STR_SIZE : __errstrSize_));                      \
                              	__err_.errstr[(A2GS_TOOLBOX_ERRO_STR_SIZE < __errstrSize_ ? A2GS_TOOLBOX_ERRO_STR_SIZE : __errstrSize_)] = '\0'; \
                              }


/* *** DATA TYPES *** */
typedef struct _erro_t{
	int errno;
	char errstr[A2GS_TOOLBOX_ERRO_STR_SIZE + 1];
}erro_t;


/* *** INTERFACES / PROTOTYPES *** */


/* *** EXAMPLE *** */
#if 0
erro_t f()
{
   erro_t e;
   char *msg = "erro 13 yakyakyak";

   A2GS_TOOLBOX_CLEAR_ERRO(e);

   A2GS_TOOLBOX_SET_ERRO(e, 13, msg, strlen(msg));

   return(e);
}

int main(int argc, char *argv[])
{
   erro_t e;
   e = f();
   printf("[%d][%s]\n", A2GS_TOOLBOX_GET_ERRO(e), A2GS_TOOLBOX_GET_ERROSTRING(e));
}
#endif

#endif
