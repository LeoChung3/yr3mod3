/** \file physics */
#pragma once

#include "rendering/scene.hpp"
#include "gameObjects/collidable.hpp"

namespace Physics
{
	float DistanceOBBToPoint(Scene* scene, const OBBCollider& obb, const glm::vec3& point); //!< Distance between an OBB and a point
	float DistanceOBBToSphere(Scene* scene, const OBBCollider& obb, const SphereCollider& sphere); //!< Distance between an OBB and a sphere
}
