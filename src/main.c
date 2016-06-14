/*
 *  @Author : Rahul Mahadev (hybridNeo)
 *  client os 
 */
#include <stdio.h>
#include <assert.h>
#include <sel4/sel4.h>
#define EP_CPTR 0x3 

/* constants */
int main(int argc, char **argv) {
    printf("client-os: client os has started\n");
    seL4_Word sender_badge;
	seL4_MessageInfo_t tag;
	seL4_Word msg,func_id;
	printf("client-os:receiver...........\n");
	tag = seL4_Recv(EP_CPTR,&sender_badge);
	msg = seL4_GetMR(0);
	printf("client-os: msg = %d \n",msg );
	seL4_SetMR(0,3221);
	seL4_ReplyRecv(EP_CPTR,tag,&sender_badge);	
    while(1){

    }
    return 0;
}

