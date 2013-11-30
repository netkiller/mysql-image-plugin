/*
Homepage: http://netkiller.github.io/
Author: netkiller<netkiller@msn.com>
*/
#include <stdlib.h>
#include <stdio.h>
#include <mysql.h>
#include <string.h>
#include <io.h>
#include <openssl/md5.h>
#include "image.h"

/* ------------------------ image_check ----------------------------- */

my_bool image_check_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{

  if (args->arg_count != 1)
  {
    strncpy(message,
            "one arguments must be supplied: image_check('<filename>').",
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

	if( rename(args->args[0], args->args[1]) == 0 ){
		data = "true";
	}else{
		data = "false";
	}
	//asprintf(&data, "ARG0=%s, ARG1=%d", args->args[0], args->args[1]);
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

/* ------------------------ image_crc32 ----------------------------- */

my_bool image_crc32_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
  if (args->arg_count != 1)
  {
    strncpy(message,
            "one arguments must be supplied: image_crc32('<filename>').",
            MYSQL_ERRMSG_SIZE);
    return 1;
  }

  args->arg_type[0]= STRING_RESULT;
    return 0;
}

char *image_crc32(UDF_INIT *initid, UDF_ARGS *args,
                __attribute__ ((unused)) char *result,
               unsigned long *length,
                __attribute__ ((unused)) char *is_null,
                __attribute__ ((unused)) char *error)
{

	char *status;
	char *data;
	
	data = readfile( args->args[0]);
	if( data != NULL ){
		asprintf(&status, "%lu", crc32(0, (const void*)data, strlen(data)));
	}else{
		status = "false";
	}
	*length = strlen(status);
	return ((char *)status);
}

void image_crc32_deinit(UDF_INIT *initid)
{
   return;
}

/* ------------------------ image_md5sum ----------------------------- */
/*
my_bool image_md5sum_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
  if (args->arg_count != 1)
  {
    strncpy(message,
            "one arguments must be supplied: image_md5sum('<filename>').",
            MYSQL_ERRMSG_SIZE);
    return 1;
  }

  args->arg_type[0]= STRING_RESULT;
    return 0;
}

char *image_md5sum(UDF_INIT *initid, UDF_ARGS *args,
                __attribute__ ((unused)) char *result,
               unsigned long *length,
                __attribute__ ((unused)) char *is_null,
                __attribute__ ((unused)) char *error)
{

	char *status;
	char *data;
	unsigned char digest[MD5_DIGEST_LENGTH];
	char string[33];
	int i;
	data = readfile( args->args[0] );
	if( data != NULL ){
		MD5((unsigned char*)&data, strlen(data), (unsigned char*)&digest);    
		for(i = 0; i < 16; i++)
			 sprintf(&string[i*2], "%02x", (unsigned int)digest[i]);
		 
		asprintf(&status, "md5 digest: %s", string);
		//status = string;
	}else{
		status = "false";
	}
	*length = strlen(status);
	return ((char *)status);
}

void image_md5sum_deinit(UDF_INIT *initid)
{
   return;
}
*/