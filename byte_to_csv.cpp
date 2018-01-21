#include <stdio.h>
#include <iostream>
#include <typeinfo>
#ifndef CHLU_API
#define CHLU_API
#include "chlu_API_trace.h"
#endif

#define train_text(x) "train_"#x".csv"

using namespace std;
FILE *rptr,*wptr;

int main(){
	int num_count = 0;
	void *data;
	rptr = fopen("ml_samples.txt","rb");
	wptr = fopen("train.csv","w");
	ml_sample ml_sample;
	while(fread(&ml_sample,sizeof(ml_sample),1,rptr)!=NULL){
		if (num_count == 1){
			fprintf(wptr,"power,");
			for (int i=0;i<ml_sample.param_count;i++)
				fprintf(wptr,"%s,",ml_sample.ParamValue[i].get_type().c_str());
			fprintf(wptr,"graphic_clock,mem_clock");
				
		}
		num_count++;
	}
		cout << "count:"<<num_count<<endl;
	cout << "train_text: " << train_text(1) << endl;
	cout << "train_text: " << train_text(2) << endl;
	return 0;
}
