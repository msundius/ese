/** ***************************************************************************
 * @File: dpc.h
 * @Author: C Michael Sundius
 * @Organization: Solico Group LLC
 * @Date: 11/16/2012
 *
 * @Copyright (c) 2012, Nov 16
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * 
 * Redistributions in binary form must reproduce the above copyright notice, 
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * Neither the name of the Solico Group LLC nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
 * THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * @section Description:
 * This file provides macros and API for the manipulation of a doubly linked
 * list.
 *
 ** ***************************************************************************/


#ifndef _list_h_
#define _list_h_

/** 
 * Headers
 **/
#include "common.h"

/** 
 * Macros
 **/

/** 
 * Types
 **/

/* DPC Structure */
typedef struct dpc_s {
	uint_t magic;
	pthread_t thread;
	uint_t disable;
	buffer_pool_t *bp_p;
	fifo_t job_que;
} dpc_t;

/* Job Structure */
typdef struct dpc_job_s {
	list_t elem;
	uint_t magic;
} dpc_job_t;


/** 
 * Prototypes
 **/

#endif /* _list_h_ */
