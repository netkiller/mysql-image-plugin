/*
Homepage: http://netkiller.github.io/
Author: netkiller<netkiller@msn.com>
*/

#include <mysql.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "images.h"

/* ------------------------ image_check ----------------------------- */

my_bool image_check_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{

  if (args->arg_count != 1)
  {
    strncpy(message,
            "two arguments must be supplied: image_check('<data>').",
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
    data = "image_check";
    *length = strlen(data);
    return ((char *)data);

}

void image_check_deinit(UDF_INIT *initid)
{
  return;
}

/* ------------------------ image_move ----------------------------- */

my_bool image_move_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{

  if (args->arg_count != 1)
  {
    strncpy(message,
            "two arguments must be supplied: image_move('<data>').",
            MYSQL_ERRMSG_SIZE);
    return 1;
  }

  get_safenet_env();
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

    get_safenet_env();
    return 0;
}

char *image_remove(UDF_INIT *initid, UDF_ARGS *args,
                __attribute__ ((unused)) char *result,
               unsigned long *length,
                __attribute__ ((unused)) char *is_null,
                __attribute__ ((unused)) char *error)
{

  char *config;
  //asprintf(&config, "SAFENET_URL=%s, SAFENET_KEY=%s", safe_url, safe_key);
  config = "image_remove";
  *length = strlen(config);
  return ((char *)config);
}

void image_remove_deinit(UDF_INIT *initid)
{
   return;
}
