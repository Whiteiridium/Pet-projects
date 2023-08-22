#pragma once
#include "IEntity.hpp"
#include "EmptyEntity.hpp"

class Food : public EmptyEntity
{
private:
	int Predator_Priority = static_cast<int>(PredatorPriority::FoodPriority);
	int Prey_priority = static_cast<int>(PreyPriority::FoodPriority);
	int coord_x, coord_y;

public:
	virtual ~Food() {};
	Food(){}
	Food(int x, int y) : coord_x(x), coord_y(y) {}

	virtual int get_priority_predator() const noexcept { return Predator_Priority; }
	virtual int get_priority_prey() const noexcept { return Prey_priority; }
	virtual void move_along_the_route(std::vector<std::vector<std::shared_ptr<EmptyEntity>>>& OceanGrid, PriorityEntityTuple& new_position) override {};
	virtual void move_obj(std::vector<std::vector<std::shared_ptr<EmptyEntity>>>& OceanGrid) override {};
	char GetSymbol() const noexcept override { return '#'; }
};