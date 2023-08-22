#include "Ocean.hpp"
#include <set>
#include "Obstacle.hpp"
#include <memory>
#include "Prey.hpp"
#include "Food.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <random>

std::set<std::pair<int, int>> occupiedCoordinates;                                            // Structure to hold unique coordinates
template<typename EntityCreator>
void Ocean::generate_entities(std::vector<std::vector<std::shared_ptr<EmptyEntity>>>& OceanGrid, std::mt19937& gen, EntityCreator&& createEntity) const noexcept
{
    std::uniform_int_distribution<int> distribution(0, ocean_width - 1); // Adjust the range correctly
    while (true)
    {
        int rand_x = distribution(gen);
        int rand_y = distribution(gen);
        std::pair<int, int> coord = std::make_pair(rand_x, rand_y);

        if (occupiedCoordinates.find(coord) == occupiedCoordinates.end())
        {
            occupiedCoordinates.insert(coord);
            OceanGrid[rand_x][rand_y] = createEntity(rand_x, rand_y);
            break;
        }
    }
}

void Ocean::set_amount_of_creatures(int predators, int preys, int obstacles, int food)
{
    m_num_of_predators = predators;
    m_num_of_preys = preys;
    m_num_of_obstacles = obstacles;
    m_num_of_food = food;
}

void Ocean::init(std::vector<std::vector<std::shared_ptr<EmptyEntity>>>& OceanGrid) const noexcept
{
    std::random_device rd;
    std::mt19937 gen(rd());
    int num_of_empty_cells = ocean_height * ocean_width - (m_num_of_obstacles + m_num_of_obstacles + m_num_of_preys + m_num_of_predators);

    for (int i = 0; i < m_num_of_predators; ++i)
    {
        generate_entities(OceanGrid, gen, [&](int x, int y) {
            return std::make_shared<Predator>(x, y);
            });
    }       

    for (int i = 0; i < m_num_of_preys; ++i)
        generate_entities(OceanGrid, gen, [&](int x, int y) {
        return std::make_shared<Prey>(x, y);
            });

    for (int i = 0; i < m_num_of_obstacles; ++i)
    {
        generate_entities(OceanGrid, gen, [&](int x, int y) {
            return std::make_unique<Obstacle>(x, y);
            });
    }
   
    for (int i = 0; i < m_num_of_obstacles; ++i)
    {
        generate_entities(OceanGrid, gen, [&](int x, int y) {
            return std::make_unique<Food>(x, y);
            });
    }  

    for (int i = 0; i < num_of_empty_cells; ++i)
    {
        generate_entities(OceanGrid, gen, [&](int x, int y) {
            return std::make_shared<EmptyEntity>(x, y);
            });
    }
}


void Ocean::render(std::vector<std::vector<std::shared_ptr<EmptyEntity>>>& OceanGrid) const noexcept
{
    do
    {
        for (int i = 0; i < ocean_height; ++i)
            for (int j = 0; j < ocean_width; j++)
                std::cout << OceanGrid[i][j]->GetSymbol();

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));                     
    
        for (int i = 0; i < ocean_height; ++i)
            for (int j = 0; j < ocean_width; j++)
                 OceanGrid[i][j]->move_obj(OceanGrid);

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));                      

        system("cls");

        if (m_num_of_predators || m_num_of_preys)
            std::cout << "Simulation is over" << std::endl;
    } while (m_num_of_predators || m_num_of_preys);

}
