#pragma once
#include <vector>
#include <memory>

class EmptyEntity;

enum class PredatorPriority {
    BaseCellPriority = 2,
    FoodPriority = 1,
    ObstaclePriority = 0,
    PredatorPriority = 3,
    PreyPriority = 4
};

enum class PreyPriority {
    BaseCellPriority = 3,
    FoodPriority = 4,
    ObstaclePriority = 1,
    PredatorPriority = 0,
    PreyPriority = 0
};

using PriorityEntityTuple = std::tuple<int, std::shared_ptr<EmptyEntity>, std::pair<int, int>>;

class IEntity {
protected:
    int predatorPriority = static_cast<int>(PredatorPriority::BaseCellPriority);
    int preyPriority = static_cast<int>(PreyPriority::BaseCellPriority);

public:
    virtual ~IEntity() {}

    virtual void move_along_the_route(std::vector<std::vector<std::shared_ptr<EmptyEntity>>>& OceanGrid, PriorityEntityTuple& new_position) = 0;

    virtual void move_obj(std::vector<std::vector<std::shared_ptr<EmptyEntity>>>& OceanGrid) = 0;
    virtual int get_priority_predator() const noexcept { return predatorPriority; }
    virtual int get_priority_prey() const noexcept { return preyPriority; }

    virtual char GetSymbol() const noexcept = 0;
};
