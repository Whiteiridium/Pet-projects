#pragma once
#include "IEntity.hpp"
#include "EmptyEntity.hpp"

class Prey : public EmptyEntity
{
private:
	int PredatorPriority = static_cast<int>(PredatorPriority::PredatorPriority);
	int PreyPriority = static_cast<int>(PreyPriority::PreyPriority);
	int time_to_live = 20;
	int coord_x, coord_y;

public:
	virtual ~Prey(){}
	Prey(){}
	Prey(int x, int y) : coord_x(x), coord_y(y) {}

	virtual void move_along_the_route(std::vector<std::vector<std::shared_ptr<EmptyEntity>>>& OceanGrid, PriorityEntityTuple& new_position) override;
	virtual void move_obj(std::vector<std::vector<std::shared_ptr<EmptyEntity>>>& OceanGrid) override;

	virtual int get_priority_predator() const noexcept override { return PredatorPriority; };
	virtual int get_priority_prey() const noexcept override { return PreyPriority; };
	virtual char GetSymbol() const noexcept override { return '&'; }
};