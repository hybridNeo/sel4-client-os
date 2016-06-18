/*
 *  @Author : Rahul Mahadev (hybridNeo)
 *  client os 
 */
#include "tee_client_api.h"

#define TA_NAME "hello-4-app"
int main(int argc, char **argv) {
   	// init();
   	int ta_num = start_ta(TA_NAME);
   	call_func_ta(ta_num);
    while(1){

    }
    return 0;
}

