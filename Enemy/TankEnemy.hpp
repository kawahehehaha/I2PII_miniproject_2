#ifndef TANKENEMY_HPP
#define TANKENEMY_HPP
#include "Enemy.hpp"
#include "Engine/Sprite.hpp"

class TankEnemy : public Enemy
{
private:
    Sprite head;
    float targetRotation;

public:
    TankEnemy(int x, int y);
    void Draw() const override;
    void Update(float deltaTime) override;
    Enemy *Clone() const override;
};
#endif // TANKENEMY_HPP
