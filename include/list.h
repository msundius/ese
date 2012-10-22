/** ***************************************************************************
 * @File: list.h
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
/* Lists */
#define list_init(head) do {   \
	(head)->next = (head); \
	(head)->prev = (head); \
}while (False)
#define list_add_head list_add_after
#define list_add_tail list_add_before
#define list_add_after(head, elem) do { \
	(elem)->next = (head)->next;    \
	(elem)->prev = (head);          \
	((head)->next)->prev = (elem);  \
	(head)->next = (elem);          \
}while (False)
#define list_add_before(head, elem) do { \
	(elem)->next = (head);           \
	(elem)->prev = (head)->prev;     \
	((head)->prev)->next = (elem);   \
	(head)->prev = (elem);           \
}while (False)

/* Locked Lists */
#define llist_lock(head) pthread_mutext_lock(&head->lock)
#define llist_unlock(head) pthread_mutext_unlock(&head->lock)
#define llist_init(head) do {             \
	list_init(head);                  \
	pthread_mutext_init(&head->lock); \
}while(False)
#define llist_add_head llist_add_after
#define llist_add_tail llist_add_before
#define list_add_after(head, elem) do { \
	llist_lock(head);               \
	list_add_after(head, elem);     \
	llist_unlock(head);             \
} while(False)
#define list_add_before(head, elem) do { \
	llist_lock(head);                \
	list_add_before(head, elem);     \
	llist_unlock(head);              \
} while(False)

/* Queues */
#define que_lock llist_lock
#define que_unlock llist_unlock

#define fifo_enque(head, elem) do { \
	llist_lock(head);           \
	list_add_after(head, elem); \
        sem_post(&head->event);     \
	llist_unlock(head);         \
} while(False)
	
#define fifo_deque(head, elem)      \
	llist_lock(head);           \
        sem_wait(&head->event);     \
	list_add_after(head, elem); \
	llist_unlock(head);         \
} while(False)
}


/** 
 * Types
 **/
typedef struct list_s {
	list_t *next;
	list_t *prev;
} list_t;

typedef struct llist_s {
	list_t *next;
	list_t *prev;
} llist_t;

typedef struct queue_s {
	list_t *next;
	list_t *prev;
	pthread_mutext_t lock
	sem_t event;
} queue_t;

/** 
 * Prototypes
 **/

#endif /* _list_h_ */
