#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <cmath>
#include <utility>

#include "Enemy/Enemy.hpp"
#include "Engine/GameEngine.hpp"
#include "Engine/Group.hpp"
#include "Engine/IObject.hpp"
#include "Engine/IScene.hpp"
#include "Engine/Point.hpp"
#include "Scene/PlayScene.hpp"
#include "Tool.hpp"

PlayScene *Tool::getPlayScene() {
    return dynamic_cast<PlayScene *>(Engine::GameEngine::GetInstance().GetActiveScene());
}

Tool::Tool(std::string imgTool, float x, float y) : Sprite(imgTool, x, y){}

void Tool::Update(float deltaTime) {
    Sprite::Update(deltaTime);
    PlayScene *scene = getPlayScene();
    // if (Target) {
    //     Engine::Point diff = Target->Position - Position;
    //     if (diff.Magnitude() > CollisionRadius) {
    //         Target->lockedTurrets.erase(lockedTurretIterator);
    //         Target = nullptr;
    //         lockedTurretIterator = std::list<Turret *>::iterator();
    //     }
    // }
    // if (!Target) {
    //     // Lock first seen target.
    //     // Can be improved by Spatial Hash, Quad Tree, ...
    //     // However simply loop through all enemies is enough for this program.
    //     for (auto &it : scene->EnemyGroup->GetObjects()) {
    //         Engine::Point diff = it->Position - Position;
    //         if (diff.Magnitude() <= CollisionRadius) {
    //             Target = dynamic_cast<Enemy *>(it);
    //             Target->lockedTurrets.push_back(this);
    //             lockedTurretIterator = std::prev(Target->lockedTurrets.end());
    //             break;
    //         }
    //     }
    // }
    // if (Target) {
    //     Engine::Point originRotation = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    //     Engine::Point targetRotation = (Target->Position - Position).Normalize();
    //     float maxRotateRadian = rotateRadian * deltaTime;
    //     float cosTheta = originRotation.Dot(targetRotation);
    //     // Might have floating-point precision error.
    //     if (cosTheta > 1) cosTheta = 1;
    //     else if (cosTheta < -1) cosTheta = -1;
    //     float radian = acos(cosTheta);
    //     Engine::Point rotation;
    //     if (abs(radian) <= maxRotateRadian)
    //         rotation = targetRotation;
    //     else
    //         rotation = ((abs(radian) - maxRotateRadian) * originRotation + maxRotateRadian * targetRotation) / radian;
    //     // Add 90 degrees (PI/2 radian), since we assume the image is oriented upward.
    //     Rotation = atan2(rotation.y, rotation.x) + ALLEGRO_PI / 2;
    //     // Shoot reload.
    //     reload -= deltaTime;
    //     if (reload <= 0) {
    //         // shoot.
    //         reload = coolDown;
    //         CreateBullet();
    //     }
    // }
}

void Tool::Draw() const {
    if (Preview) {
        al_draw_filled_circle(Position.x, Position.y, CollisionRadius, al_map_rgba(0, 255, 0, 50));
    }
    Sprite::Draw();
}