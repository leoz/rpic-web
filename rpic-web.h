/******************************************************************************
 *  Copyright (C) 2012 - 2013, Leonid Zolotarev
 *
 *  Licensed under the terms of the BSD license, see file COPYING
 *  for details.
 *
 *  Raspberry Pi Car Controller
 *
 *  Header file for the rpic-web
 *
 *****************************************************************************/

#ifndef __RPIC_WEB_H__
#define __RPIC_WEB_H__

#define RPIC_COMMANDS 10

static char* rpic_commands [RPIC_COMMANDS] = {
    "rpic_fwrd",
    "rpic_bkwd",
    "rpic_stop",
    "rpic_left",
    "rpic_rght",
    "rpic_dcl",
    "rpic_acl",
    "rpic_ver",
    "rpic_time",
    "rpic_uptime"
};

#define RPIC_CMD_VOID -1
#define RPIC_CMD_FWRD 0
#define RPIC_CMD_BKWD 1
#define RPIC_CMD_STOP 2
#define RPIC_CMD_LEFT 3
#define RPIC_CMD_RGHT 4
#define RPIC_CMD_DCL  5
#define RPIC_CMD_ACL  6
#define RPIC_CMD_VER  7
#define RPIC_CMD_TIME 8
#define RPIC_CMD_UPTIME 9

#endif /* __RPIC_WEB_H__ */
