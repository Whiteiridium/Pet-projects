#pragma once
#include "IEntity.hpp"

class EmptyEntity : public IEntity
{
private:
    int coord_x, coord_y;

protected:
	int predatorPriority = static_cast<int>(PredatorPriority::BaseCellPriority);
	int preyPriority = static_cast<int>(PreyPriority::BaseCellPriority);

public:
    virtual ~EmptyEntity(){}

    EmptyEntity() {}
    EmptyEntity(int x, int y) : coord_x(x), coord_y(y) {}

    virtual void move_along_the_route(std::vector<std::vector<std::shared_ptr<EmptyEntity>>>& OceanGrid, PriorityEntityTuple& new_position) {}

    virtual void move_obj(std::vector<std::vector<std::shared_ptr<EmptyEntity>>>& OceanGrid) {};
    virtual int get_priority_predator() const noexcept { return predatorPriority; }
    virtual int get_priority_prey() const noexcept { return preyPriority; }

    virtual char GetSymbol() const noexcept { return '-'; };
};