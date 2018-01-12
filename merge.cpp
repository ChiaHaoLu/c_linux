#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(){
	FILE *api_rptr,*p_rptr,*wptr;
	p_rptr = fopen("nvml_power.txt","r");
	api_rptr = fopen("api.txt","r");
	wptr = fopen("ml_sample.txt","w");
	short str_lenght = 50;
	string buffer(str_lenght,'\0');
	while(fread(&buffer[0],sizeof(string),1,p_rptr)!=NULL)
		cout << buffer.c_str() << endl;
	return 0;
}
