#include <stdio.h>
#include <unistd.h>
#include <ubus.h>

int main(int argc, char **argv){

    // connect to Ubus
    struct ubus_context * ctx = ubus_connect();
    if (!ctx){
        fprintf(stderrm, "failed connecting to Ubus");
        return -1;
    }
    
    // create msg we'll be sending
    struct blob_buf b;
    blob_buf_init(&b, 0);

    if( ! blobmsg_add_json_from_string(&b, "{\"msg\": \"Hello World!\" }")){
        fprintf(stderrm, "failed creating msg");
        return -1;
    }

    // send msg in loop
    while (true){
        if(ubus_send_event(ctx, "test_event", b.head)){
            fprintf(stderrm, "failed ending event");
        }
        sleep(2);
    }
}
