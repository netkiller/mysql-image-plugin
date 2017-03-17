mysql-image-plugin
==================

[![Join the chat at https://gitter.im/netkiller/mysql-image-plugin](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/netkiller/mysql-image-plugin?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

Build
-----
	cd /usr/local/src/
	git clone https://github.com/netkiller/mysql-image-plugin.git
 	cd mysql-image-plugin/
 	yum install cmake

	cmake .
	make && make install
	
	or
	
	gcc -O3  -g  -I/usr/include/mysql -I/usr/include/sys  -fPIC -shared -o libimage.so image.c
	sudo mv libimage.so /usr/lib/mysql/plugin/
	
Setup
-----
	mysql> create function image_check returns string soname 'libimage.so';
	Query OK, 0 rows affected (0.44 sec)

Test
----
	mysql> select image_check('/www/images/logo.png');
	
Plugin
------

### Install
	
	create function image_check returns string soname 'libimage.so';
	create function image_remove returns string soname 'libimage.so';
	create function image_rename returns string soname 'libimage.so';
	create function image_crc32 returns string soname 'libimage.so';
	create function image_move returns string soname 'libimage.so';

### Uninstall

	drop function image_check;
	drop function image_remove;
	drop function image_rename;
	drop function image_crc32;
	drop function image_move;

Example 
-------	
	select image_check('/path/filename.ext');
	select image_remove('/path/filename.ext');
	select image_rename('/path/oldfile.ext','/path/newfile.ext');
	select image_crc32('/path/filename.ext');
	select image_move('/path/filename.ext','/path/to/newfile.ext');

# Donations

We accept PayPal through:

https://www.paypal.me/netkiller

Wechat (微信) / Alipay (支付宝) 打赏:

http://www.netkiller.cn/home/donations.html

[![Bitdeli Badge](https://d2weczhvl823v0.cloudfront.net/netkiller/mysql-image-plugin/trend.png)](https://bitdeli.com/free "Bitdeli Badge")

