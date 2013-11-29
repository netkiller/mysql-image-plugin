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
