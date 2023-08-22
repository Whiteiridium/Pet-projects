#pragma once
#include <vector>
#include "EmptyEntity.hpp"
#include "IEntity.hpp"
#include "Predator.hpp"
#include <memory>
#include <random>
#include <set>

class Predator;

class Ocean
{
private:
	static const int ocean_width = 100, ocean_height = 100;
	int m_num_of_predators, m_num_of_preys, m_num_of_obstacles, m_num_of_food;

public:
	friend class Predator;
	

	Ocean(){}

	void set_amount_of_creatures(int predators = 10, int preys = 10, int obstacles = 20, int food = 20);

	template<typename EntityCreator>																							// To create entities and place them on the map
	void generate_entities(std::vector<std::vector<std::shared_ptr<EmptyEntity>>>& OceanGrid, std::mt19937& gen, EntityCreator&& createEntity) const noexcept ;  																			    // Functions to generate objects and fill map

	void init(std::vector<std::vector<std::shared_ptr<EmptyEntity>>>& OceanGrid) const noexcept;
	void render(std::vector<std::vector<std::shared_ptr<EmptyEntity>>>& OceanGrid) const noexcept;

	static int get_ocean_height()  noexcept { return ocean_height; }
	static int get_ocean_width()  noexcept { return ocean_width; }
}; 