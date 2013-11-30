mysql-image-plugin
==================

Build
-----
	gcc -O3  -g  -I/usr/include/mysql -I/usr/include/sys  -fPIC -shared -o image.so image.c
	sudo mv image.so /usr/lib/mysql/plugin/
	
Setup
-----
	mysql> create function image_check returns string soname 'image.so';
	Query OK, 0 rows affected (0.44 sec)

Test
----
	mysql> select image_check('/www/images/logo.png');
	
Plugin
------
	drop function image_check;
	drop function image_remove;
	drop function image_rename;
	drop function image_crc32;
	drop function image_md5sum;
	
	create function image_check returns string soname 'image.so';
	create function image_remove returns string soname 'image.so';
	create function image_rename returns string soname 'image.so';
	create function image_crc32 returns string soname 'image.so';
	create function image_md5sum returns string soname 'image.so';

	select image_check('/tmp/filename');
	select image_remove('/tmp/filename');
	select image_rename('/tmp/aa','/tmp/bb');
	select image_crc32('/tmp/test.jpg');
	select image_md5sum('/tmp/test');