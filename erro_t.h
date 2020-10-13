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
 *   a2gs   | 13/10/2020 | A better interface
 *          |            |
 */

#ifndef __ERRO_T_H__
#define __ERRO_T_H__


/* *** INCLUDES *** */
#include <string.h>


/* *** DEFINES *** */
#define ERRO_T_STR_SIZE (250)

/* Clear de erro_t variable */
#define ERRO_T_GET(__erro_t_) (__erro_t_.errno)

/* Return the erro's number defined by someone into a erro_t variable */
#define ERRO_T_GET_MESSAGE(__erro_t_) (__erro_t_.errstr)

/* Return the erro's message defined by someone into a erro_t variable */
#define ERRO_T_CLEAR(__erro_t_){                                                      \
                               	__erro_t_.errno = 0;                                 \
                               	memset(__erro_t_.errstr, '\0', ERRO_T_STR_SIZE + 1); \
                               }

/* Define a erro into a erro_t variable
 * __erro_t_         - erro_t variable
 * __erro_t_no_      - error number
 * __erro_t_str_     - error message
 * __erro_t_strSize_ - Size of __errstr_ in bytes (max size can be ERRO_T_STR_SIZE)
 */
#define ERRO_T_SET(__erro_t_,                                                                         \
                   __erro_t_no_,                                                                      \
                   __erro_t_str_,                                                                     \
                   __erro_t_strSz_){                                                                  \
                                   	size_t __erro_t_MaxSz_ = (((ERRO_T_STR_SIZE < __erro_t_strSz_) || \
                                   	                           (__erro_t_strSz_ == 0)) ?              \
                                   	                          ERRO_T_STR_SIZE : __erro_t_strSz_);     \
                                   	__erro_t_.errno = __erro_t_no_;                                   \
                                   	memcpy(__erro_t_.errstr, __erro_t_str_, __erro_t_MaxSz_ );        \
                                   	__erro_t_.errstr[__erro_t_MaxSz_] = '\0';                         \
                                   }


/* *** DATA TYPES *** */
typedef struct _erro_t{
	int errno;
	char errstr[ERRO_T_STR_SIZE + 1];
}erro_t;


/* *** INTERFACES / PROTOTYPES *** */


/* *** EXAMPLE *** */
#if 0
#include <erro_t.h>
#include <stdio.h>
#include <string.h>

erro_t f1(void)
{
   erro_t e;
   char *msg = "erro yakyakyak";

   ERRO_T_CLEAR(e);
   ERRO_T_SET(e, 13, msg, 0);

   return(e);
}

erro_t f2(void)
{
   erro_t e;
   char *msg = "erro blablabla";

   ERRO_T_CLEAR(e);
   ERRO_T_SET(e, 8, msg, strlen(msg));

   return(e);
}

int main(int argc, char *argv[])
{
   erro_t e;

   e = f1();
   printf("[%d][%s]\n", ERRO_T_GET(e), ERRO_T_GET_MESSAGE(e));

   e = f2();
   printf("[%d][%s]\n", ERRO_T_GET(e), ERRO_T_GET_MESSAGE(e));
}
#endif

#endif
