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