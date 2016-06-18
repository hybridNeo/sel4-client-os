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

void start_ta(){
	seL4_Word msg;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(0, 0, 0, 1);
	seL4_SetTag(tag);    
	seL4_SetMR(0, 9111);
	printf("client-os: Calling \n");
	seL4_Call(TEE_EP_CPTR,tag);
	msg = seL4_GetMR(0);
	printf("client-os: returned value is %d \n",msg );	
}

