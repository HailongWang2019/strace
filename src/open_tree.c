/*
 * Copyright (c) 2019-2021 Dmitry V. Levin <ldv@strace.io>
 * All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include "defs.h"
#include <linux/mount.h>
#include "kernel_fcntl.h"
#include <linux/fcntl.h>
#include "xlat/open_tree_flags.h"

SYS_FUNC(open_tree)
{
	print_dirfd(tcp, tcp->u_arg[0]);
	tprints(", ");
	printpath(tcp, tcp->u_arg[1]);
	tprints(", ");
	printflags(open_tree_flags, tcp->u_arg[2], "OPEN_TREE_???");
	return RVAL_DECODED | RVAL_FD;
}
