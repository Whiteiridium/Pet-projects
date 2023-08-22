#include "Ocean.hpp"
#include "Prey.hpp"
#include "Food.hpp"
#include "Obstacle.hpp"
#include "Predator.hpp"
#include <queue>
#include <tuple>

void Predator::move_along_the_route(std::vector<std::vector<std::shared_ptr<EmptyEntity>>>& OceanGrid, PriorityEntityTuple& new_position)
{
    if (time_to_live)
    {
        --time_to_live;
        auto new_coords = std::get<2>(new_position);
        int last_x = this->coord_x;
        int last_y = this->coord_y;       

        OceanGrid[new_coords.first][new_coords.second].reset();

        this->coord_x = new_coords.first;
        this->coord_y = new_coords.second;      

        OceanGrid[new_coords.first][new_coords.second] = std::move(OceanGrid[last_x][last_y]);
        OceanGrid[last_x][last_y] = std::make_shared<EmptyEntity>(last_x, last_y);
    }
    else OceanGrid[coord_x][coord_y] = std::make_shared<EmptyEntity>(coord_x, coord_y);
}

void Predator::move_obj(std::vector<std::vector<std::shared_ptr<EmptyEntity>>>& OceanGrid)
{
    std::priority_queue<PriorityEntityTuple> route;
    //std::priority_queue<std::pair<int, std::shared_ptr<EmptyEntity>>> route;

    if (coord_y + 1 < OceanGrid[0].size()) {
        int x = coord_x;
        int y = coord_y + 1;
        auto new_coords = std::make_pair(x, y);
        int priority = OceanGrid[x][y]->get_priority_predator();
        std::shared_ptr<EmptyEntity> entity = OceanGrid[x][y];
        route.push(std::make_tuple(priority, entity, new_coords));
    }

    if (coord_y - 1 >= 0) {
        int x = coord_x;
        int y = coord_y - 1;
        auto new_coords = std::make_pair(x, y);
        int priority = OceanGrid[x][y]->get_priority_predator();
        std::shared_ptr<EmptyEntity> entity = OceanGrid[x][y];
        route.push(std::make_tuple(priority, entity, new_coords));
    }

    if (coord_x + 1 < OceanGrid.size()) {
        int x = coord_x + 1;
        int y = coord_y;
        auto new_coords = std::make_pair(x, y);
        int priority = OceanGrid[x][y]->get_priority_predator();
        std::shared_ptr<EmptyEntity> entity = OceanGrid[x][y];
        route.push(std::make_tuple(priority, entity, new_coords));
    }

    if (coord_x - 1 >= 0) {
        int x = coord_x - 1;
        int y = coord_y;
        auto new_coords = std::make_pair(x, y);
        int priority = OceanGrid[x][y]->get_priority_predator();
        std::shared_ptr<EmptyEntity> entity = OceanGrid[x][y];
        route.push(std::make_tuple(priority, entity, new_coords));;
    }

    if (!route.empty()) {
        auto high_priority_route = route.top();
        move_along_the_route(OceanGrid, high_priority_route);
    }
}
