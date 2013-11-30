my_bool image_check_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
char *image_check(UDF_INIT *initid, UDF_ARGS *args, char *result, unsigned long *length, char *is_null, char *error);
void image_check_deinit(UDF_INIT *initid);

my_bool image_move_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
char *image_move(UDF_INIT *initid, UDF_ARGS *args, char *result, unsigned long *length, char *is_null, char *error);
void image_move_deinit(UDF_INIT *initid);

my_bool image_remove_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
char *image_remove(UDF_INIT *initid, UDF_ARGS *args, char *result, unsigned long *length, char *is_null, char *error);
void image_remove_deinit(UDF_INIT *initid);

my_bool image_rename_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
char *image_rename(UDF_INIT *initid, UDF_ARGS *args, char *result, unsigned long *length, char *is_null, char *error);
void image_rename_deinit(UDF_INIT *initid);

my_bool image_crc32_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
char *image_crc32(UDF_INIT *initid, UDF_ARGS *args, char *result, unsigned long *length, char *is_null, char *error);
void image_crc32_deinit(UDF_INIT *initid);
/*
my_bool image_md5sum_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
char *image_md5sum(UDF_INIT *initid, UDF_ARGS *args, char *result, unsigned long *length, char *is_null, char *error);
void image_md5sum_deinit(UDF_INIT *initid);
*/
char * readfile(char * path)  
{  
    FILE * file;  
    char * data;  
	int *length;
  
    file = fopen(path, "rb");  
    if (file == NULL)  
    {  
        return NULL;  
    }  
    fseek(file, 0, SEEK_END);  
    *length = ftell(file);  
    data = (char *)malloc((*length + 1) * sizeof(char));  
    rewind(file);  
    *length = fread(data, 1, *length, file);  
    //data[*length] = '\0';  
    fclose(file);  
    return data;  
}  