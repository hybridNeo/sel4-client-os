/*
 *  @Author : Rahul Mahadev (hybridNeo)
 *  client os and client program
 */
#include "tee_client_api.h"

#define CMD_TA_INC 1
#define CMD_TA_ENC 2
#define CMD_TA_DEC 3
#define TA_NAME "hello-4-app"
int main(int argc, char **argv) {
	// init();
	int ta_num = start_ta(TA_NAME);
	char arr[32] = "6bc1bee22e409f96e93d7e117393172a"; //String to be encrypted
	char res[32];
	arr[32] = '\0';
	//first call
	printf("client-os: Calling TA to encrypt string %s  \n",arr);
	call_func_ta(ta_num,CMD_TA_ENC,10,arr,sizeof(char) *32,res);
	res[32] = '\0';
	printf("client-os: String encrypted to %s \n\n",res);
	char res_2[32] = {0};
	//second call
	printf("client-os: Calling TA to decrypt string %s  \n",res);
	call_func_ta(ta_num,CMD_TA_DEC,10,res,sizeof(char) *32,res_2);
	res_2[32] = '\0';
	printf("client-os: String decrypted to %s \n\n",res_2);
	//third call
	printf("client-os: Calling TA to increment number \n");
	int res_val = call_func_ta(ta_num,CMD_TA_INC,5,arr,sizeof(char) *12,NULL);
	printf("client-os: Number incremented from %d to %d \n",5,res_val );
	while(1){

	}
	return 0;
}

