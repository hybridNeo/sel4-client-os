#include <stdio.h>
#include <assert.h>
#include <sel4/sel4.h>
#include <string.h>

#define TEE_EP_CPTR 0x3 
#define START_TA_CMD 1001
#define CALL_FUNC_CMD 1002
void init();
int start_ta(char *ta_name);
void call_func_ta(int ta_num);