#include <stdio.h>
#include <string.h>
#include "mongoose.h"
#include "rpic-lib.h"
#include "rpic-web.h"

/*****************************************************************************/

#include <time.h>

static char* rpi_car_dev_time()
{
    static char data [30];
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    sprintf(data, "%04d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);    
    
    return data;
}

/*****************************************************************************/

static const char* rpic_web_reply =
    "HTTP/1.1 200 OK\r\n"
    "Cache: no-cache\r\n"
    "Content-Type: text/plain\r\n"
    "Content-Length: %d\r\n"
    "\r\n";

static void rpic_web_send_data(struct mg_connection *conn, const char* data)
{
    mg_printf(conn, rpic_web_reply, strlen(data));
    mg_write(conn, data, strlen(data));
}

static int rpic_web_check_command(struct mg_connection *conn, const char* command)
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
        else if (strcmp(command, rpic_commands[RPIC_CMD_VER]) == 0) {
            const char* data = rpi_car_dev_version();        
            if (data != NULL) {
                rpic_web_send_data(conn, data);
            }
            return RPIC_CMD_VER;
        }
        else if (strcmp(command, rpic_commands[RPIC_CMD_TIME]) == 0) {
            const char* data = rpi_car_dev_time();        
            if (data != NULL) {
                rpic_web_send_data(conn, data);
            }
            return RPIC_CMD_TIME;
        }
    }
    return RPIC_CMD_VOID;
}

static void *callback(enum mg_event event,
                      struct mg_connection *conn)
{
    const struct mg_request_info *ri = mg_get_request_info(conn);
    
    if (event == MG_NEW_REQUEST) {
        if (rpic_web_check_command(conn, ri->query_string) != RPIC_CMD_VOID) {
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
