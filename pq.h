/*
 * This file contains the definition of the interface for the priority queue
 * you'll implement.  You can find descriptions of the priority queue functions,
 * including their parameters and their return values, in pq.c.
 *
 * You should not modify this file.
 */

#ifndef __PQ_H
#define __PQ_H

/*
 * Structure used to represent a priority queue.
 */
struct pq;



/*
 * Helper function to swap two elements in the priority queue.
 * This is used for maintaining the heap property during insertions and removals.
 */
void swap_elements(struct pq* pq, int index1, int index2);
struct pq* pq_create();
void pq_free(struct pq* pq);
int pq_isempty(struct pq* pq);
void pq_insert(struct pq* pq, void* value, int priority);
void* pq_first(struct pq* pq);
int pq_first_priority(struct pq* pq);
void* pq_remove_first(struct pq* pq);

#endif
