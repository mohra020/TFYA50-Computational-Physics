#ifndef VERLET_LIST_H
#define VERLET_LIST_H

#include "atom.h"

class verlet_list{
private:
	float verlet_skin;
public:
	/* Empty constructor initialises everythin to NULL ( = 0) */
	verlet_list();
	verlet_list(float r);

	/* The data of the atom */
	atom *data;
	/* The neighbours in the verlet list */
	/* This is a linked list containing all atoms within the verlet skin */
	verlet_list *next;

	/* adds an atom to the verlet list, if it is within the cutoff distance */
	/* TODO: Proper distance calculations - periodic boundary conditions	*/
	/*		 Proper cutoff distance, currently it is hard coded as 500		*/
	void add_atom(verlet_list atom);

	/* Clear the verlet list, needs to be done before updating the verlet list */
	/* Removes all neighbours, leaving only the current atom				*/
	void clear_verlet_list();

	void set_verlet_skin(float r);
};
#endif /* VERLET_LIST_H */