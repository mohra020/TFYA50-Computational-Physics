#include "world.h"
#include "verlet_list.h"
#include <iostream>


int main()
{
	world test(5);
	test.bulk[0].data->pos = vector_3d(1.0, 0.0, 0.0);
	test.bulk[1].data->pos = vector_3d(0.0, 1.0, 0.0);
	test.bulk[2].data->pos = vector_3d(0.0, 0.0, 1.0);
	test.bulk[3].data->pos = vector_3d(1.0, 0.0, 1.0);

	test.bulk[0].data->acc = vector_3d(25.0, 0.0, 1.0);
	test.bulk[1].data->vel = vector_3d(3.0, 0.0, 0.0);
	test.bulk[2].data->vel = vector_3d(1.0, 0.4, 1.2);
	test.bulk[3].data->vel = vector_3d(1.0, 1.0, 0.0);
	test.bulk[4].data->vel = vector_3d(0.1, 0.3, 0.3);


	test.update_verlet_lists();

	/* Move system to next time step */

	for(unsigned int i = 0; i < test.N; i++){
		std::cout << "Old position of particle " << i << ": (" << test.bulk[i].data->pos.x << ", " << test.bulk[i].data->pos.y << ", " << test.bulk[i].data->pos.z << ",)" << std::endl;
		std::cout << "Old velocity of particle " << i << ": (" << test.bulk[i].data->vel.x << ", " << test.bulk[i].data->vel.y << ", " << test.bulk[i].data->vel.z << ",)" << std::endl;
		test.verlet_integrator.verlet_integration_position(test.bulk[i]);
		std::cout << "New position of particle " << i << ": (" << test.bulk[i].data->pos.x << ", " << test.bulk[i].data->pos.y << ", " << test.bulk[i].data->pos.z << ",)" << std::endl;
	}
	std::cout << std::endl;
	for(unsigned int i = 0; i < test.N; i++){
		test.verlet_integrator.verlet_integration_velocity(test.bulk[i]);
		std::cout << "New velocity of particle " << i << ": (" << test.bulk[i].data->vel.x << ", " << test.bulk[i].data->vel.y << ", " << test.bulk[i].data->vel.z << ",)" << std::endl;
	}

	for(unsigned int i = 0; i < test.N; i++){
		test.bulk[i].clear_verlet_list();
	}

/*
	world w(5, 5, 5, 1);
	
	std::cout << w.atoms[1].pos.x;
	
*/

	world w(3, 3, 3, 1);
	std::cout << w.N << std::endl;
	for(int i=0; i<w.N; i++){
		std::cout << w.atoms[i].pos.x << "\t" << w.atoms[i].pos.y << "\t" << w.atoms[i].pos.z << "   (" << i+1 << ")" << std::endl;
	}
	int temp;
	std::cin >> temp;

	return 0;
}
