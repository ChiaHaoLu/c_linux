#ifndef CHLU_TRACE_H
#define CHLU_TRACE_H
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <typeinfo>
#include "GLDefines.h"

using namespace std;

class api_param
{
public:
	api_param();
	~api_param();
	void init_api_param();

	template <typename T> void set_value(T);

	GLchar get_char();
	GLbyte get_byte();
	GLshort get_short();
	GLint get_int();
	GLuint get_uint();
	GLushort get_ushort();
	GLfloat get_float();
	GLdouble get_double();
	GLint64 get_int64();
	GLuint64 get_uint64();

	void set_type(string);
	string get_type();
private:
	GLchar _char;
	GLbyte _byte;
	GLshort _short;
	GLint _int;
	GLuint _uint;
	GLushort _ushort;
	GLfloat _float;
	GLdouble _double;
	GLint64 _int_64;
	GLuint64 _uint64;
	char _data_type[10];
};

class ml_sample {
public:
	ml_sample();
	~ml_sample();
	char FunctionName[50];
	int FuncTime;
	unsigned int param_count;
	api_param ParamValue[10];

	unsigned int power;
	unsigned int graphic_clock;
	unsigned int mem_clock;
	unsigned int SM_clock;
	unsigned int system_time;
};
#define BUF_SIZE 256
#include "chlu_API_trace.hpp"
#endif
