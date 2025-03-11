/*
 * In this file, you will write the structures and functions needed to
 * implement a priority queue.  Feel free to implement any helper functions
 * you need in this file to implement a priority queue.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name: Ejner Nielsen
 * Email: nielseej@oregonstate.edu 
 */

#include <stdlib.h>

#include "pq.h"
#include "dynarray.h"

/*
 * This is the structure that represents a priority queue.  You must define
 * this struct to contain the data needed to implement a priority queue.
 */
struct pq{
        struct dynarray* dynarray;
//  void **elements;  // dynamic array of elements
//    int *priorities;  // dynamic array of priorities corresponding to elements
//    int size;         // current number of elements in the priority queue
//    int capacity;     // maximum capacity of the priority queue
};

struct pq_elements{
        void* value;
        int priority;
};
/*
 * This function should allocate and initialize an empty priority queue and
 * return a pointer to it.
 */


// Helper function to swap two elements in the heap
void swap_elements(struct pq* pq, int index1, int index2) {

        void* second_index = dynarray_get(pq->dynarray, index2);
        void* first_index = dynarray_get(pq->dynarray, index1);

        dynarray_set(pq->dynarray, index1, second_index);
        dynarray_set(pq->dynarray, index2, first_index);

//      void *temp_value = pq->elements[index1];
//    pq->elements[index1] = pq->elements[index2];
//    pq->elements[index2] = temp_value;

//    int temp_priority = pq->priorities[index1];
//    pq->priorities[index1] = pq->priorities[index2];
//    pq->priorities[index2] = temp_priority;
}



// Resize the heap array (from dynarray functions)
//void resize_heap(struct pq* pq, int new_capacity) {
    // Resize both elements and priorities arrays
//    pq->elements = dynarray_resize(pq->elements, new_capacity);
//    pq->priorities = dynarray_resize(pq->priorities, new_capacity);
//    pq->capacity = new_capacity;
//}

struct pq* pq_create() {
        /*
         * FIXME:
         */
    struct pq* p_q = malloc(sizeof(struct pq));

    p_q->dynarray = dynarray_create();  // Create an empty dynamic array



    return p_q;


}


/*
 * This function should free the memory allocated to a given priority queue.
 * Note that this function SHOULD NOT free the individual elements stored in
 * the priority queue.  That is the responsibility of the caller.
 *
 * Params:
 *   pq - the priority queue to be destroyed.  May not be NULL.
 */
void pq_free(struct pq* pq) {
        /*
         * FIXME:
         */
        if (pq != NULL) { // free if priority queue is not empty
                dynarray_free(pq->dynarray);

                free(pq);
        }

//      return;
}


/*
 * This function should return 1 if the specified priority queue is empty and
 * 0 otherwise.
 *
 * Params:
 *   pq - the priority queue whose emptiness is to be checked.  May not be
 *     NULL.
 *
 * Return:
 *   Should return 1 if pq is empty and 0 otherwise.
 */
int pq_isempty(struct pq* pq) {
        /*
         * FIXME:
         */
        if(dynarray_size(pq->dynarray) == 0){
                return 1;
        }
        return 0;
//return pq == NULL || pq->size == 0;

}


/*
 * This function should insert a given element into a priority queue with a
 * specified priority value.  Note that in this implementation, LOWER priority
 * values are assigned to elements with HIGHER priority.  In other words, the
 * element in the priority queue with the LOWEST priority value should be the
 * FIRST one returned.
 *
 * Params:
 *   pq - the priority queue into which to insert an element.  May not be
 *     NULL.
 *   value - the value to be inserted into pq.
 *   priority - the priority value to be assigned to the newly-inserted
 *     element.  Note that in this implementation, LOWER priority values
 *     should correspond to elements with HIGHER priority.  In other words,
 *     the element in the priority queue with the LOWEST priority value should
 *     be the FIRST one returned.
 */
void pq_insert(struct pq* pq, void* value, int priority) {
        /*
         * FIXME:
         */
    struct pq_elements* new_element = malloc(sizeof(struct pq_elements));
                        new_element->value = value;
                        new_element->priority = priority;
        dynarray_insert(pq->dynarray, new_element);
        int first_index = dynarray_size(pq->dynarray) - 1;
        //percolate
        while(first_index != 0){
        int parent_index = ((first_index -1) / 2);
    struct pq_elements* parent = dynarray_get(pq->dynarray, parent_index);
    struct pq_elements* child = dynarray_get(pq->dynarray, first_index);
        //swaps when the parent is greater
        if(parent->priority > child->priority){
        swap_elements(pq, first_index, parent_index);
        first_index = parent_index;
        } else {
        break;
        }
        }
//      return;
        }






/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_first(struct pq* pq) {
        /*
         * FIXME:
         */
    struct pq_elements* first_element = dynarray_get(pq->dynarray, 0);
    return first_element->value;

}


/*
 * This function should return the priority value of the first item in a
 * priority queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a priority value.  May not be
 *     NULL or empty.
 *
 * Return:
 *   Should return the priority value of the first item in pq, i.e. the item
 *   with LOWEST priority value.
 */
int pq_first_priority(struct pq* pq) {
        /*
         * FIXME:
         */
    struct pq_elements* first_element = dynarray_get(pq->dynarray, 0);
    return first_element->priority;

}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value, and then remove that item
 * from the queue.
 *
 * Params:
 *   pq - the priority queue from which to remove a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */

void* pq_remove_first(struct pq* pq) {

    // Remove the root (first element)
    struct pq_elements* remove = dynarray_get(pq->dynarray, 0);
    void* value = remove->value;
    free(remove);

    // Swap the root with the last element in the heap
    int size = dynarray_size(pq->dynarray);
    swap_elements(pq, 0, size - 1);

    // Remove the last element (which is now the root)
    dynarray_remove(pq->dynarray, size - 1);

    // Percolate down to restore heap property
    int index = 0;
    while (index < dynarray_size(pq->dynarray)) {
        int left_index = 2 * index + 1;  // Left child index
        int right_index = 2 * index + 2; // Right child index
        int smallest = index;

        // Check if left child exists and is smaller than current
        if (left_index < dynarray_size(pq->dynarray)) {
            struct pq_elements* left_child = dynarray_get(pq->dynarray, left_index);
            struct pq_elements* current_parent = dynarray_get(pq->dynarray, index);
            if (left_child->priority < current_parent->priority) {
                smallest = left_index;
            }
        }

        // Check if right child exists and is smaller than current
        if (right_index < dynarray_size(pq->dynarray)) {
            struct pq_elements* right_child = dynarray_get(pq->dynarray, right_index);
            struct pq_elements* current_parent = dynarray_get(pq->dynarray, index);
            if (right_child->priority < ((struct pq_elements*)dynarray_get(pq->dynarray, smallest))->priority) {
           // if (right_child->priority < dynarray_get(pq->dynarray, smallest)->priority) {
                smallest = right_index;
            }
        }

        // If smallest is not the current index, swap
        if (smallest != index) {
            swap_elements(pq, index, smallest);
            index = smallest;
        } else {
            break;
        }
    }

    return value;
}
