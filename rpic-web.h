#ifndef __RPIC_WEB_H__
#define __RPIC_WEB_H__

#define RPIC_COMMANDS 7

static char* rpic_commands [RPIC_COMMANDS] = {
    "rpic_fwrd",
    "rpic_bkwd",
    "rpic_stop",
    "rpic_left",
    "rpic_rght",
    "rpic_dcl",
    "rpic_acl"
};

#define RPIC_CMD_VOID -1
#define RPIC_CMD_FWRD 0
#define RPIC_CMD_BKWD 1
#define RPIC_CMD_STOP 2
#define RPIC_CMD_LEFT 3
#define RPIC_CMD_RGHT 4
#define RPIC_CMD_DCL  5
#define RPIC_CMD_ACL  6

#endif /* __RPIC_WEB_H__ */
