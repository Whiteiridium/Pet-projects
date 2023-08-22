#include <iostream>
#include "Ocean.hpp"
#include "Predator.hpp"

int main()
{
	std::vector<std::vector<std::shared_ptr<EmptyEntity>>> OceanGrid(Ocean::get_ocean_height(), std::vector<std::shared_ptr<EmptyEntity>>(Ocean::get_ocean_width()));
	Ocean ocean;
	ocean.set_amount_of_creatures();
	ocean.init(OceanGrid);
	ocean.render(OceanGrid);

	return EXIT_SUCCESS;
}