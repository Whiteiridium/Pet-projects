#pragma once
#include "EmptyEntity.hpp"
#include "IEntity.hpp"

class Obstacle : public EmptyEntity
{
private:
	int PredatorPriority = static_cast<int>(PredatorPriority::ObstaclePriority);
	int PreyPriority = static_cast<int>(PreyPriority::ObstaclePriority);
	int coord_x, coord_y;

public:
	virtual ~Obstacle() {};
	Obstacle(){}
	Obstacle(int x, int y) : coord_x(x), coord_y(y){}

	virtual char GetSymbol() const noexcept override { return '#'; }
	virtual void move_along_the_route(std::vector<std::vector<std::shared_ptr<EmptyEntity>>>& OceanGrid, PriorityEntityTuple& new_position) override {};
	virtual void move_obj(std::vector<std::vector<std::shared_ptr<EmptyEntity>>>& OceanGrid) override {};
	virtual int get_priority_predator() const noexcept { return PredatorPriority; }
	virtual int get_priority_prey() const noexcept { return PreyPriority; }
};