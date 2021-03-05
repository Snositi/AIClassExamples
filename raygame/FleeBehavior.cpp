#include "FleeBehavior.h"
#include "Agent.h"
#include "Actor.h"

FleeBehavior::FleeBehavior()
{
	m_target = nullptr;
	m_fleeForce = 1;
}

FleeBehavior::FleeBehavior(Actor* target, float seekForce)
{
	m_target = target;
	m_fleeForce = seekForce;
}

MathLibrary::Vector2 FleeBehavior::calculateForce(Agent* agent)
{
	//Find the direction to move in
	MathLibrary::Vector2 direction = MathLibrary::Vector2::normalize(agent->getWorldPosition() - m_target->getWorldPosition());
	//Scale the direction vector by the seekForce
	MathLibrary::Vector2 desiredVelocity = direction * m_fleeForce;
	//Subtract current velocity from desired velocity to find steering force
	MathLibrary::Vector2 steeringForce = desiredVelocity - agent->getVelocity();
	return  steeringForce;
}

void FleeBehavior::update(Agent* agent, float deltaTime)
{
	if (agent)
		agent->addForce(calculateForce(agent));
}