#include <stdio.h>
#include <string.h>
#include "mongoose.h"
#include "rpic-lib.h"
#include "rpic-web.h"

static int rpic_web_check_command(const char* command)
{
    if (command != NULL) {
             if (strcmp(command, rpic_commands[RPIC_CMD_FWRD]) == 0) {
            rpi_car_forward();
            return RPIC_CMD_FWRD;
        }
        else if (strcmp(command, rpic_commands[RPIC_CMD_BKWD]) == 0) {
            rpi_car_backward();
            return RPIC_CMD_BKWD;
        }
        else if (strcmp(command, rpic_commands[RPIC_CMD_STOP]) == 0) {
            rpi_car_stop();
            return RPIC_CMD_STOP;
        }
        else if (strcmp(command, rpic_commands[RPIC_CMD_LEFT]) == 0) {
            rpi_car_left();
            return RPIC_CMD_LEFT;
        }
        else if (strcmp(command, rpic_commands[RPIC_CMD_RGHT]) == 0) {
            rpi_car_right();
            return RPIC_CMD_RGHT;
        }
        else if (strcmp(command, rpic_commands[RPIC_CMD_DCL]) == 0) {
            rpi_car_deccelerate();
            return RPIC_CMD_DCL;
        }
        else if (strcmp(command, rpic_commands[RPIC_CMD_ACL]) == 0) {
            rpi_car_accelerate();
            return RPIC_CMD_ACL;
        }
    }
    return RPIC_CMD_VOID;
}

static void *callback(enum mg_event event,
                      struct mg_connection *conn)
{
    const struct mg_request_info *ri = mg_get_request_info(conn);
    
    if (event == MG_NEW_REQUEST) {
        if (rpic_web_check_command(ri->query_string) != RPIC_CMD_VOID) {
            printf("Received supported command from HTTP: %s\n", ri->query_string);
            return "";
        }
    }
    return NULL;
}

int main()
{
    struct mg_context *ctx;
    const char *options[] = {
        "listening_ports", "3001",
        "document_root", "rpicweb",
        NULL
    };
  
	int dev = rpi_car_dev_open();

    ctx = mg_start(&callback, NULL, options);
    getchar();  // Wait until user hits "enter"
    mg_stop(ctx);

    rpi_car_dev_close(dev);
    
    return 0;
}
