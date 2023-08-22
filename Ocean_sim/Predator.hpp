#pragma once
#include "IEntity.hpp"
#include "Ocean.hpp"
#include <memory>
#include "EmptyEntity.hpp"

class Ocean;

class Predator : public EmptyEntity
{
private:
	int time_to_live = 15;
	int coord_x, coord_y;
	int PredatorPriority = static_cast<int>(PredatorPriority::PredatorPriority);
	int PreyPriority = static_cast<int>(PreyPriority::PreyPriority);

public:
	virtual ~Predator(){}
	Predator(){}
	Predator(int x, int y) : coord_x(x), coord_y(y){}

	virtual void move_along_the_route(std::vector<std::vector<std::shared_ptr<EmptyEntity>>>& OceanGrid, PriorityEntityTuple& new_position) override;
	virtual void move_obj(std::vector<std::vector<std::shared_ptr<EmptyEntity>>>& OceanGrid) override;
	
	virtual int get_priority_predator() const noexcept { return PredatorPriority; }
	virtual int get_priority_prey() const noexcept { return PreyPriority; }
	virtual char GetSymbol() const noexcept override { return '$'; }
};