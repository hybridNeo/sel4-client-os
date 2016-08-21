/*
 *  @Author : Rahul Mahadev (hybridNeo)
 *  client os and client program
 */
#include "tee_client_api.h"
#include <autoconf.h>

#include <stdio.h>
#include <assert.h>

#include <sel4/sel4.h>

#include <simple/simple.h>
#include <simple-default/simple-default.h>

#include <vka/object.h>

#include <allocman/allocman.h>
#include <allocman/bootstrap.h>
#include <allocman/vka.h>



#include <sel4utils/vspace.h>
#include <sel4utils/mapping.h>
#include <sel4utils/process.h>
#include <vspace/vspace.h>
#define CMD_TA_INC 1
#define CMD_TA_ENC 2
#define CMD_TA_DEC 3
#define TA_NAME "hello-4-app"



void sel4_print(char* str){
	while((str != NULL)&&(*str != 0)){
		seL4_DebugPutChar(*str);
		str++;
	}
}



int main(int argc, char **argv) {

	
	// init();
	sel4_print("client-os:sel4 print\n");
	int ta_num = start_ta(TA_NAME);
	char arr[32] = "be2d8a571e03ac9c9eb76fac45af8e51"; //String to be encrypted
	char res[32];
	arr[32] = '\0';
	//first call
	sel4_print("client-os: Calling TA to encrypt string ");
	sel4_print(arr);
	sel4_print("\n");
	call_func_ta(ta_num,CMD_TA_ENC,10,arr,sizeof(char) *32,res);
	res[32] = '\0';
	sel4_print("client-os: String encrypted to ");
	sel4_print(res);
	sel4_print("\n\n");
	char res_2[32] = {0};
	//second call
	sel4_print("client-os: Calling TA to decrypt string ");
	sel4_print(res);
	sel4_print("\n");
	call_func_ta(ta_num,CMD_TA_DEC,10,res,sizeof(char) *32,res_2);
	res_2[32] = '\0';
	sel4_print("client-os: String decrypted to ");
	sel4_print(res_2);
	sel4_print("\n\n");
	//third call
	sel4_print("client-os: Calling TA to increment number \n");
	int res_val = call_func_ta(ta_num,CMD_TA_INC,5,arr,sizeof(char) *12,NULL);
	sel4_print("client-os: Number incremented from ");seL4_DebugPutChar(5+'0');
	sel4_print(" to ");
	seL4_DebugPutChar('0'+res_val);	
	
	while(1){

	}
	return 0;
}

