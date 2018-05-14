/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2015 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: krakjoe                                                      |
  +----------------------------------------------------------------------+
*/

/* $Id$ */
#ifndef HAVE_INSPECTOR_FRAME_H
#define HAVE_INSPECTOR_FRAME_H

extern zend_class_entry *php_inspector_frame_ce;

typedef struct _php_inspector_frame_op_t {
	zend_free_op f;
	zval *p;
} php_inspector_frame_op_t;

typedef struct _php_inspector_frame_t {
	zend_execute_data *frame;
	zval scope;
	zval opline;
	php_inspector_frame_op_t op1;
	php_inspector_frame_op_t op2;
	php_inspector_frame_op_t rv;
	zend_object std;
} php_inspector_frame_t;

#define php_inspector_frame_fetch_from(o) ((php_inspector_frame_t*) (((char*)o) - XtOffsetOf(php_inspector_frame_t, std)))
#define php_inspector_frame_fetch(z) php_inspector_frame_fetch_from(Z_OBJ_P(z))
#define php_inspector_frame_this() php_inspector_frame_fetch(getThis())

PHP_MINIT_FUNCTION(inspector_frame);

void php_inspector_frame_construct(zval *object, zend_execute_data *execute_data);
#endif