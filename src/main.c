/*
 *  @Author : Rahul Mahadev (hybridNeo)
 *  client os and client program
 */
#include "tee_client_api.h"

#define CMD_TA_INC 1
#define CMD_TA_ENC 2
#define TA_NAME "hello-4-app"
int main(int argc, char **argv) {
   	// init();
   	int ta_num = start_ta(TA_NAME);
   	char arr[12] = "hello world"; //String to be encrypted
   	char res[12];
   	printf("client-os: Calling TA to encrypt string \n");
   	call_func_ta(ta_num,CMD_TA_ENC,10,arr,sizeof(char) *12,res);
	printf("client-os: String encrypted from %s to %s \n\n",arr,res);
   	printf("client-os: Calling TA to increment number \n");
   	int res_val = call_func_ta(ta_num,CMD_TA_INC,5,arr,sizeof(char) *12,NULL);
   	printf("client-os: Number incremented from %d to %d \n",5,res_val );
    while(1){

    }
    return 0;
}

