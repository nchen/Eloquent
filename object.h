/*
 * object.h
 *
 *  Created on: 2013年7月18日
 *      Author: liutos
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include <stdio.h>

#include "type.h"

/* OBJECT_H_ */
lisp_object_t *the_dot_symbol;
lisp_object_t *the_false;
lisp_object_t *the_true;
lt *gensym_counter;
lisp_object_t *null_env;
lisp_object_t *the_empty_list;
lisp_object_t *standard_in;
lisp_object_t *standard_out;
lisp_object_t *symbol_list;
lisp_object_t *the_undef;

struct lisp_object_t lt_types[VECTOR + 1];

extern int is_pointer(lt *);
extern int isexception(lt *);
extern int isfloat(lt *);
extern int isfunction(lt *);
extern int isinput_file(lt *);
extern int ismacro(lt *);
extern int isopcode(lt *);
extern int isoutput_file(lt *);
extern int ispair(lt *);
extern int isprimitive(lt *);
extern int isstring(lt *);
extern int issymbol(lt *);
extern int istype(lt *);
extern int isvector(lt *);
extern int ischar(lt *);
extern int isfixnum(lt *);
extern int isdot(lt *);
extern int iseof(lt *);
extern int isnull(lt *);
extern int isfalse(lt *);
extern int is_true_object(lt *);
extern int isundef(lt *);
extern int isclose(lt *);
extern int isboolean(lt *);
extern int is_signaled(lt *);
extern int isnumber(lt *);
extern int type_of(lt *);
extern lt *make_false(void);
extern lt *make_true(void);
extern lt *make_empty_list(void);
extern lt *make_eof(void);
extern lt *make_undef(void);
extern lt *make_close(void);
extern lt *make_character(char);
extern lt *make_fixnum(int);
extern lt *make_exception(char *, int, lt *);
extern lt *make_float(float);
extern lt *make_function(lt *env, lt *args, lt *code);
extern lt *make_input_file(FILE *);
extern lt *make_macro(lt *, lt *);
extern lt *make_output_file(FILE *);
extern lt *make_pair(lt *, lt *);
extern lt *make_primitive(int, void *, char *, int);
extern lt *make_retaddr(lt *code, lt *env, int need, int nvals, int pc, int throw_flag, int sp);
extern string_builder_t *make_str_builder(void);
extern lt *make_string(char *);
extern lt *make_symbol(char *);
extern lt *make_type(enum TYPE, char *);
extern lt *make_vector(int);
extern lt *make_op_args(lt *);
extern lt *make_op_argsd(lt *);
extern lt *make_op_call(lt *);
extern lt *make_op_checkex(void);
extern lt *make_op_chktype(lt *, lt *, lt *);
extern lt *make_op_const(lt *);
extern lt *make_op_decl(lt *);
extern lt *make_op_fjump(lt *);
extern lt *make_op_fn(lt *);
extern lt *make_op_gset(lt *);
extern lt *make_op_gvar(lt *);
extern lt *make_op_jump(lt *);
extern lt *make_op_lset(lt *i, lt *j, lt *symbol);
extern lt *make_op_lvar(lt *i, lt *j, lt *symbol);
extern lt *make_op_macro(lt *);
extern lt *make_op_mvcall(void);
extern lt *make_op_need(void);
extern lt *make_op_pop(void);
extern lt *make_op_prim(lt *);
extern lt *make_op_return(void);
extern lt *make_op_values(lt *);
extern lt *make_op_catch();

extern lt *find_or_create_symbol(char *);

extern lt *lt_exception_tag(lt *);
extern lt *lt_type_name(lt *);

extern void init_global_variable(void);

/* tagging system
 *   bits end in  00:  pointer
 *                01:  fixnum
 *              0110:  char
 *              1110:  other immediate object (null_list, true, false, eof, undef, close)
 */
#define CHAR_BITS 4
#define CHAR_MASK 15
#define CHAR_TAG 6
#define FIXNUM_BITS 2
#define FIXNUM_MASK 3
#define FIXNUM_TAG 1
#define IMMEDIATE_BITS 4
#define IMMEDIATE_MASK 15
#define IMMEDIATE_TAG 14
#define POINTER_MASK 3
#define POINTER_TAG 0

#define S(name) (find_or_create_symbol(name))

#endif
