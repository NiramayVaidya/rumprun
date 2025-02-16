/*-
 * Copyright (c) 2015 Antti Kantee.  All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _RUMPRUN_BASE_RUMPRUN_H_
#define _RUMPRUN_BASE_RUMPRUN_H_

typedef int mainlike_fn(int, char *[]);
mainlike_fn main;

struct rumprun_boot_config {
    char * cmdline;
    int tmpfs_num_MiB;
};

void	rumprun_boot(struct rumprun_boot_config *);
// void	rumprun_boot(char *);

void *	rumprun(int, mainlike_fn, int, char *[]);
int	rumprun_wait(void *);
void *	rumprun_get_finished(void);

void	rumprun_reboot(void) __attribute__((noreturn));

/* XXX: this prototype shouldn't be here (if it should exist at all) */
void	rumprun_daemon(void);

extern int rumprun_cold;

#endif /* _RUMPRUN_BASE_RUMPRUN_H_ */
