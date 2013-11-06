#include "world.h"

#ifndef NULL
#define NULL 0
#endif

world::world()
{
	N = 0;
	atoms = NULL;
	bulk = NULL;
}



world::world(unsigned int n)
{
	N = n;

	/* Create all the atoms */
	/* Currently all atoms are placed in origin, with velocity and acceleration equal to zero */
	atoms = new atom[n];

	/* Create the list of verlet lists */
	bulk = new verlet_list[n];

	/* Link each cell in the array of verlet lists to the corresponding atom */
	for(int i = 0; i < n; i++){
		bulk[i].data = &atoms[i];
	}
}

void world::update_verlet_lists()
{
	for(int i = 0; i < this->N; i++){
		for(int j = i + 1; j < this->N; j++){
			this->bulk[i].add_atom(this->bulk[j]);
			this->bulk[j].add_atom(this->bulk[i]);
		}
	}
}