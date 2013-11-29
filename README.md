mysql-image-plugin
==================

Build
-----
	gcc -I/usr/include/mysql -I./ -fPIC -shared -o mysql_image.so image.c
	sudo mv mysql_image.so /usr/lib/mysql/plugin/
	
Setup
-----
	mysql> create function image_check returns string soname 'mysql_image.so';
	Query OK, 0 rows affected (0.44 sec)

Test
----
	mysql> select image_check('/www/images/logo.png');
	
Plugin
------
	drop function image_check;
	drop function image_remove;
	drop function image_rename;
	
	create function image_check returns string soname 'mysql_image.so';
	create function image_remove returns string soname 'mysql_image.so';
	create function image_rename returns string soname 'mysql_image.so';

	select image_check('/tmp/filename');
	select image_remove('/tmp/filename');
	select image_rename('/tmp/aa','/tmp/bb');