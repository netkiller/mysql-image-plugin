/*
Homepage: http://netkiller.github.io/
Author: netkiller<netkiller@msn.com>
*/
#include <stdlib.h>
#include <stdio.h>
#include <mysql.h>
#include <string.h>
#include <io.h>

#include "image.h"

/* ------------------------ image_check ----------------------------- */

my_bool image_check_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{

  if (args->arg_count != 1)
  {
    strncpy(message,
            "two arguments must be supplied: image_check('<filename>').",
            MYSQL_ERRMSG_SIZE);
    return 1;
  }
  args->arg_type[0]= STRING_RESULT;

  return 0;
}

char *image_check(UDF_INIT *initid, UDF_ARGS *args,
                __attribute__ ((unused)) char *result,
               unsigned long *length,
                __attribute__ ((unused)) char *is_null,
                __attribute__ ((unused)) char *error)
{

    char *data;
	if (!access(args->args[0],0) )
        data = "ture";
    else
		data = "false";

    *length = strlen(data);
    return ((char *)data);

}

void image_check_deinit(UDF_INIT *initid)
{
  return;
}

/* ------------------------ image_rename ----------------------------- */

my_bool image_rename_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{

  if (args->arg_count != 2)
  {
    strcpy(message,
            "two arguments must be supplied: image_move('<file1>','<file2>').");
    return 1;
  }

  args->arg_type[0]= STRING_RESULT;

  return 0;
}

char *image_rename(UDF_INIT *initid, UDF_ARGS *args,
                __attribute__ ((unused)) char *result,
               unsigned long *length,
                __attribute__ ((unused)) char *is_null,
                __attribute__ ((unused)) char *error)
{

    char *data;
	int errno;
	errno = rename(args->args[0], args->args[1]);
	if( errno == 0 )
		data = "true";
	else
		//asprintf(&data, "ARG0=%s, ARG1=%d", args->args[0], errno);
		data = "false";
		
    *length = strlen(data);
    return ((char *)data);

}

void image_rename_deinit(UDF_INIT *initid)
{
  return;
}

/* ------------------------ image_move ----------------------------- */

my_bool image_move_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{

  if (args->arg_count != 1)
  {
    strncpy(message,
            "two arguments must be supplied: image_move('<filename>').",
            MYSQL_ERRMSG_SIZE);
    return 1;
  }

  args->arg_type[0]= STRING_RESULT;

  return 0;
}

char *image_move(UDF_INIT *initid, UDF_ARGS *args,
                __attribute__ ((unused)) char *result,
               unsigned long *length,
                __attribute__ ((unused)) char *is_null,
                __attribute__ ((unused)) char *error)
{

    char *data;
    data = "image_move";
    *length = strlen(data);
    return ((char *)data);

}

void image_move_deinit(UDF_INIT *initid)
{
  return;
}

/* ------------------------ image_remove ----------------------------- */

my_bool image_remove_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
  if (args->arg_count != 1)
  {
    strncpy(message,
            "two arguments must be supplied: image_remove('<filename>').",
            MYSQL_ERRMSG_SIZE);
    return 1;
  }

  args->arg_type[0]= STRING_RESULT;
    return 0;
}

char *image_remove(UDF_INIT *initid, UDF_ARGS *args,
                __attribute__ ((unused)) char *result,
               unsigned long *length,
                __attribute__ ((unused)) char *is_null,
                __attribute__ ((unused)) char *error)
{

	char *status;
  //asprintf(&status, "SAFENET_URL=%s, SAFENET_KEY=%s", safe_url, safe_key);
	if( !remove( args->args[0] ) )
		status = "true";
	else
		status = "false";
  
	*length = strlen(status);
	return ((char *)status);
}

void image_remove_deinit(UDF_INIT *initid)
{
   return;
}
