#include "tee_client_api.h"
void init(){
	printf("client-os: client os has started\n");
    seL4_Word sender_badge;
	seL4_MessageInfo_t tag;
	seL4_Word msg,func_id;
	printf("client-os:receiver...........\n");
	tag = seL4_Recv(TEE_EP_CPTR,&sender_badge);
	msg = seL4_GetMR(0);
	printf("client-os: msg = %d \n",msg );
	seL4_SetMR(0,3221);
	seL4_ReplyRecv(TEE_EP_CPTR,tag,&sender_badge);	
	
	
}

int start_ta(char *ta_name){
	seL4_Word msg;
	int arg_len = strlen(ta_name);
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(0, 0, 0, 2+arg_len);
	seL4_SetTag(tag);    
	seL4_SetMR(0, START_TA_CMD);
	printf("client-os: Calling TEE-CONTAINER \n");
	seL4_Word *ptr = (seL4_Word*)ta_name;
	for(int i=0;i < arg_len;++i){
		seL4_SetMR(i+2,*ptr);
		ptr++;
	}
	ptr = ta_name;
	seL4_SetMR(1,arg_len);
	seL4_Call(TEE_EP_CPTR,tag);
	msg = seL4_GetMR(0);
	return msg;
}


void call_func_ta(int ta_num,int func_id,int simp_arg){
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(0, 0, 0, 4);
	seL4_SetTag(tag);    
	seL4_SetMR(0, CALL_FUNC_CMD);
	seL4_SetMR(1, ta_num);
	seL4_SetMR(2,func_id);
	seL4_SetMR(3,simp_arg);
	seL4_Call(TEE_EP_CPTR,tag);
	

}