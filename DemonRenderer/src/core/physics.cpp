/** \file physics.cpp */

#include "core/physics.hpp"

namespace Physics
{
	/* Implementation is based Real - Time Collision Detection by Christer Ericson pp 133
	*  Calculate the closest point on or inside the OBB.
	*  Distance is calculate from that.
	*/
	float DistanceOBBToPoint(Scene* scene, const OBBCollider& obb, const glm::vec3& point)
	{
		auto& obbActor = scene->m_actors.at(obb.actorIdx);

		// ClosestPoint is the closest point inside or on the interior of the OBB
		glm::vec3 closestPoint = obbActor.translation; // Set closest point to actor position
		glm::vec3 centre = point - obbActor.translation; // Move the problem so actor is at world centre

		// Get axis of OBB
		glm::vec3 OBBRight = { obbActor.transform[0][0], obbActor.transform[0][1], obbActor.transform[0][2] };
		glm::vec3 OBBUp = { obbActor.transform[1][0], obbActor.transform[1][1], obbActor.transform[1][2] };
		glm::vec3 OBBForward = { -obbActor.transform[2][0], -obbActor.transform[2][1], -obbActor.transform[2][2] };

		// Project along each axis, moving closest point as we go

		// Project along X
		float distX = glm::dot(centre, OBBRight);
		// Clamp to OBB half extents
		distX = std::clamp(distX, -obb.halfExtents.x, obb.halfExtents.x);
		// Move closest point
		closestPoint += OBBRight * distX;

		// Project along Y
		float distY = glm::dot(centre, OBBUp);
		// Clamp to OBB half extents
		distY = std::clamp(distY, -obb.halfExtents.y, obb.halfExtents.y);
		// Move closest point
		closestPoint += OBBUp * distY;

		// Project along Z
		float distZ = glm::dot(centre, OBBForward);
		// Clamp to OBB half extents
		distZ = std::clamp(distZ, -obb.halfExtents.z, obb.halfExtents.z);
		// Move closest point
		closestPoint += OBBUp * distZ;

		// Find the distance squared
		float distanceSquared = glm::dot(closestPoint - point, closestPoint - point);

		return sqrtf(distanceSquared);
	}
	float DistanceOBBToSphere(Scene* scene, const OBBCollider& obb, const SphereCollider& sphere)
	{
		auto& sphereCentre = scene->m_actors.at(sphere.actorIdx).translation;
		return DistanceOBBToPoint(scene, obb, sphereCentre) - sphere.radius;
	}
}