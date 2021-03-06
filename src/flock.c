/*
 * Copyright (c) 1991, 1992 Paul Kranenburg <pk@cs.few.eur.nl>
 * Copyright (c) 1993 Branko Lankester <branko@hacktic.nl>
 * Copyright (c) 1993, 1994, 1995, 1996 Rick Sladkey <jrs@world.std.com>
 * Copyright (c) 1996-1999 Wichert Akkerman <wichert@cistron.nl>
 * Copyright (c) 1999-2021 The strace developers.
 * All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include "defs.h"
#include <sys/file.h>

#include "xlat/flockcmds.h"

SYS_FUNC(flock)
{
	printfd(tcp, tcp->u_arg[0]);
	tprints(", ");
	printflags(flockcmds, tcp->u_arg[1], "LOCK_???");

	return RVAL_DECODED;
}
