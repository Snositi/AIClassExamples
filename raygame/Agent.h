#pragma once
#include "Actor.h"
#include <vector>

class Behavior;

class Agent : public Actor
{
public:
	Agent();
    ~Agent();
    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="icon">The symbol that will appear when drawn</param>
    /// <param name = "maxForce"> The largest the magnitude of the force vector can be</param>
    Agent(float x, float y, float collisionRadius, char icon, float maxSpeed, float maxForce);

    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="icon">The symbol that will appear when drawn</param>
    /// <param name = "maxForce"> The largest the magnitude of the force vector can be</param>
    Agent(float x, float y, float collisionRadius, Sprite* sprite, float maxSpeed, float maxForce);

    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="icon">The symbol that will appear when drawn</param>
    /// <param name = "maxForce"> The largest the magnitude of the force vector can be</param>
    Agent(float x, float y, float collisionRadius, const char* spriteFilePath, float maxSpeed, float maxForce);

    void update(float deltatime) override;
    void draw() override;

    float getMaxForce() { return m_maxForce; }
    void setMaxForce(float maxForce) { m_maxForce = maxForce; }
    
    //Add the given force to the total force that is being applied to the agent.
    void addForce(MathLibrary::Vector2 force);
    void addBehavior(Behavior* behavior);
private:
	MathLibrary::Vector2 m_force;
	float m_maxForce;
	std::vector<Behavior*> m_behaviors;
};

