//#ifndef CHLU_API
//#define CHLU_API
#include "chlu_API_trace.h"
//#endif

ml_sample::ml_sample() :
	FuncTime(0),
	param_count(0),
	power(0),
	graphic_clock(0),
	mem_clock(0),
	SM_clock(0),
	system_time(0)
{
	strcpy(FunctionName,"NULL/0");
}

ml_sample::~ml_sample() {

}

api_param::api_param(): _char(0),
_byte(0),
_short(0),
_int(0),
_ushort(0),
_float(0),
_double(0),
_int_64(0),
_uint64(0)
{
	strcpy(_data_type, "NULL");
}

api_param::~api_param(){}

void api_param::init_api_param() {
	_char = 0;
	_byte = 0;
	_short = 0;
	_int = 0;
	_ushort = 0;
	_float = 0;
	_double = 0;
	_int_64 = 0;
	_uint64 = 0;
	strcpy(_data_type, "NULL");
}

void api_param::set_value(GLchar data) { _char = data; }
void api_param::set_value(GLbyte data) { _byte = data; }
void api_param::set_value(GLshort data) {_short = data; }
void api_param::set_value(GLint data) { _int = data; }
void api_param::set_value(GLuint data) { _uint = data; }
void api_param::set_value(GLushort data) { _ushort = data; }
void api_param::set_value(GLfloat data) { _float = data; }
void api_param::set_value(GLdouble data) { _double = data; }
void api_param::set_value(GLint64 data) { _int_64 = data; }
void api_param::set_value(GLuint64 data) { _uint64 = data; }

GLchar api_param::get_char() { return _char; }
GLbyte api_param::get_byte() { return _byte; }
GLshort api_param::get_short() { return _short; }
GLint api_param::get_int() { return _int; }
GLuint api_param::get_uint() { return _uint; }
GLushort api_param::get_ushort() { return _ushort; }
GLfloat api_param::get_float() { return _float; }
GLdouble api_param::get_double() { return _double; }
GLint64 api_param::get_int64() { return _int_64; }
GLuint64 api_param::get_uint64() { return _uint64; }

void api_param::set_type(string type_name) { strcpy(_data_type,type_name.c_str()); }
string api_param::get_type() { string ret_str; ret_str = _data_type; return ret_str; }
