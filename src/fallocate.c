/*
 * Copyright (c) 2014-2021 The strace developers.
 * All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include "defs.h"
#include <linux/falloc.h>
#include "xlat/falloc_flags.h"

SYS_FUNC(fallocate)
{
	int argn;

	/* fd */
	printfd(tcp, tcp->u_arg[0]);
	tprints(", ");

	/* mode */
	printflags(falloc_flags, tcp->u_arg[1], "FALLOC_FL_???");
	tprints(", ");

	/* offset */
	argn = printllval(tcp, "%lld, ", 2);

	/* len */
	printllval(tcp, "%lld", argn);

	return RVAL_DECODED;
}
