#include <iostream>
#include <memory>

class Entity {
public:
  Entity() { std::cout << "Created Entity!\n"; }

  ~Entity() { std::cout << "Destroyed Entity!\n"; }
};

int main() {
  {
    std::cout << "Enter unique_ptr scope.\n";
    std::unique_ptr<Entity> uniqueEntity = std::make_unique<Entity>();
    std::cout << "Exit unique_ptr scope.\n";
  }

  {
    std::cout << "Enter the first layer of the shared_ptr scope.\n";
    std::shared_ptr<Entity> e1;
    {
      std::cout << "Enter the second layer of the shared_ptr scope.\n";
      std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
      e1 = sharedEntity;
      std::cout << "Exit the second layer of the shared_ptr scope.\n";
    }
    std::cout << "Exit the first layer of the shared_ptr scope.\n";
  }

  {
    std::cout << "Enter weak_ptr scope.\n";
    std::weak_ptr<Entity> weakEntity;
    {
      std::cout << "Enter shared_ptr scope.\n";
      std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
      weakEntity = sharedEntity;
      std::cout << "Exit shared_ptr scope.\n";
    }
    std::cout << "Exit weak_ptr scope.\n";
  }

  return 0;
}
