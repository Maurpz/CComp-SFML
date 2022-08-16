#include "Collisionable.h"

bool Collisionable::isCollisionable(Collisionable& obj) const
{
    return getBounds().intersects(obj.getBounds());
}