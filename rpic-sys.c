/******************************************************************************
 *  Copyright (C) 2013, Leonid Zolotarev
 *
 *  Licensed under the terms of the BSD license, see file COPYING
 *  for details.
 *
 *  Raspberry Pi Car System Library
 *
 *  Source file for the rpic-sys
 *
 *****************************************************************************/

#include <sys/sysinfo.h>
#include <stdio.h>
#include <time.h>

#include "rpic-sys.h"

/*****************************************************************************/

#define RPIC_BUFF_SIZE 256

char* rpi_sys_time()
{
    static char data [RPIC_BUFF_SIZE];
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    sprintf(data, "%04d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900,
            tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);    
    
    return data;
}

char* rpi_sys_uptime()
{
    static char data [RPIC_BUFF_SIZE];

    int days =0;
    int hours = 0;
    int mins = 0;

    struct sysinfo sys_info;

    if(sysinfo(&sys_info) != 0) {
        perror("sysinfo");
    }

    days = sys_info.uptime / 86400;
    hours = (sys_info.uptime / 3600) - (days * 24);
    mins = (sys_info.uptime / 60) - (days * 1440) - (hours * 60);

    sprintf(data, "%d days %02d hours %02d minutes %02ld seconds",
            days, hours, mins, sys_info.uptime % 60);    
    
    return data;
}

/*****************************************************************************/


