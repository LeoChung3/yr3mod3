/** \file collidable.hpp */
#pragma once
#include <glm/glm.hpp>

/** \class OBBCollider
*	\brief Properties of an oriented bounding box collider
*/
class OBBCollider
{
public:
	/** Constructor which takes half extents and actor idx */
	OBBCollider(const glm::vec3& he, size_t actorIndex) : halfExtents(he), actorIdx(actorIndex) {}
	glm::vec3 halfExtents{ glm::vec3(0.f) }; //!< Half extents of the collider i.e. half height, width and depth
	size_t actorIdx; //!< Index of actor which collider is attached to
};

/** \class SphereCollider
*	\brief Properties of an sphere collider
*/
class SphereCollider
{
public:
	/** Constructor which takes radii and actor idx */
	SphereCollider(float rad, size_t actorIndex) : radius(rad), actorIdx(actorIndex) {}
	float radius{ 0.f }; //!< Radius of sphere
	size_t actorIdx; //!< Index of actor which collider is attached to
};

/** \class Collidable
*	\brief Things which can collide with other colliable things
*/

class Collidable
{
public:
	/** Set the OBB collider */
	void setOBB(const glm::vec3& halfExtents, size_t actorIdx) { oBBCollider = OBBCollider(halfExtents, actorIdx); hasOBB = true;}
	/** Set the ellisoid collider */
	void setEllipsoid(float radius, size_t actorIdx) {sphereCollider = SphereCollider(radius, actorIdx); hasSphere = true;}
	bool hasOBB{ false }; //!< Is there an OBB?
	bool hasSphere{ false }; //!< Is there an Sphere?
	OBBCollider oBBCollider{ glm::vec3(0.f), 0}; //!< OBB Coliider
	SphereCollider sphereCollider{ 0.f, 0 }; //!< Sphere Collider
private:


};