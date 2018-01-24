#include <stdio.h>
#include <iostream>
#include <typeinfo>
#ifndef CHLU_API
#define CHLU_API
#include "opengl_api.h"
//#include "chlu_API_trace.h"
//#include "opengl_api.h"
#endif

#define GL_TEXTURE(x) GL_TEXTURE#x

using namespace std;
FILE *rptr,*wptr,*sptr;
void write_out_param(api_param,unsigned int,unsigned int*);
void one_hot_encoding(unsigned int,unsigned int,unsigned int*);
int num_count = 0;
int main(){
	int total_count = 0;
        void *data;
        char test_name[50];
	unsigned int api_index = 0;
	unsigned int input_dim = 0;
        rptr = fopen("ml_samples.txt","rb");
        wptr = fopen("train.csv","w");
        sptr = fopen("summary.csv","w");
        ml_sample ml_sample;
        fprintf(wptr,"power\n");
        while(fread(&ml_sample,sizeof(ml_sample),1,rptr)!=NULL){
                fprintf(wptr,"%u,",ml_sample.power);

		for (int i=0;i<GL_API_num;i++)
			if (strcmp(ml_sample.FunctionName,GL_API_name[i])==0){
				api_index = i;	break;
			}
                for (int i=0;i<ml_sample.param_count;i++)
                        write_out_param(ml_sample.ParamValue[i],api_index,&input_dim);

                fprintf(wptr,"%u,%u\n",ml_sample.graphic_clock,ml_sample.mem_clock);
                //summary
                if (num_count==0){
                        strcpy(test_name,ml_sample.FunctionName);
                        num_count++;
                }
                else{
                        if (strcmp(test_name,ml_sample.FunctionName)==0)
                                num_count++;
                        else{
                                fprintf(sptr,"%s,%d",ml_sample.FunctionName,num_count);
				fprintf(sptr,",%d\n",input_dim+ml_sample.param_count);
                                strcpy(test_name,ml_sample.FunctionName);
                                num_count = 1;
				input_dim = 0;
                        }
                }
        }
	fprintf(sptr,"%s,%d\n",test_name,num_count);
                cout << "count:"<<num_count<<endl;
        //ptr = (ml_sample.ParamValue[0].get_int);
        //cout << "type: " << test->ParamValue[0].get_type() << endl;
        //cout << "get_int: " << ml_sample.ParamValue[0].get_int() << endl;
        return 0;
}

void one_hot_encoding(unsigned int api_enum,unsigned int index,unsigned int *input_dim){
	switch(index){
	case glActiveTexture:
		for (int i=0;i<32;i++)
			if (api_enum == GL_TEXTURE0+i)
				fprintf(wptr,"1,");
			else
				fprintf(wptr,"0,");
		if (num_count == 1) *input_dim+=32;
		break;
	default:
		fprintf(wptr,"%u,",api_enum);
	}
}
void write_out_param(api_param data, unsigned int index,unsigned int *input_dim){
	if (strcmp(data.get_type().c_str(),GL_type[0])==0)
		one_hot_encoding(data.get_uint(),index,input_dim);
	else if (strcmp(data.get_type().c_str(),GL_type[1])==0)
		fprintf(wptr,GL_type_format[1],data.get_char());
	else if (strcmp(data.get_type().c_str(),GL_type[2])==0)
                fprintf(wptr,GL_type_format[2],data.get_uint());
	else if (strcmp(data.get_type().c_str(),GL_type[3])==0)
                fprintf(wptr,GL_type_format[3],data.get_byte());
	else if (strcmp(data.get_type().c_str(),GL_type[4])==0)
                fprintf(wptr,GL_type_format[4],data.get_short());
	else if (strcmp(data.get_type().c_str(),GL_type[5])==0)
                fprintf(wptr,GL_type_format[5],data.get_int());
	else if (strcmp(data.get_type().c_str(),GL_type[6])==0)
                fprintf(wptr,GL_type_format[6],data.get_char());
	else if (strcmp(data.get_type().c_str(),GL_type[7])==0)
                fprintf(wptr,GL_type_format[7],data.get_ushort());
	else if (strcmp(data.get_type().c_str(),GL_type[8])==0)
                fprintf(wptr,GL_type_format[8],data.get_uint());
	else if (strcmp(data.get_type().c_str(),GL_type[9])==0)
                fprintf(wptr,GL_type_format[9],data.get_int());
	else if (strcmp(data.get_type().c_str(),GL_type[10])==0)
                fprintf(wptr,GL_type_format[10],data.get_float());
	else if (strcmp(data.get_type().c_str(),GL_type[11])==0)
                fprintf(wptr,GL_type_format[11],data.get_double());
	else if (strcmp(data.get_type().c_str(),GL_type[12])==0)
                fprintf(wptr,GL_type_format[12],data.get_uint());
	else if (strcmp(data.get_type().c_str(),GL_type[13])==0)
                fprintf(wptr,GL_type_format[13],data.get_char());
	else
		cout << "(error) not defined type and value" << endl;
}
