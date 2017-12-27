/* ***********************************************************
*                                                            *
*   Copyright (C) Microsoft Corporation. All rights reserved.*
*                                                            *
************************************************************ */

#include <common.h>
#include <command.h>

int do_wdt2_disable(cmd_tbl_t *cmdtp, int flag, int argc, char *const argv[])
{
    u32 reg;
    if (argc != 2)
        return CMD_RET_USAGE;
    if (argv[1][0] == '0')
    {
        reg = *((volatile ulong *)0x1e78502c);
	reg &= 0xFFFFFFFE;
        *((volatile ulong *)0x1e78502c) = reg;
    }
    else
         return CMD_RET_USAGE;

	return 0;
}

/**************************************************/
U_BOOT_CMD(wdt2, 2, 0, do_wdt2_disable,
	   "Disable WDT2", "0");
