#pragma once
#include "Agent.h"
class Character : public Agent
{
public:
	Character();
	Character(float x, float y, float collisionRadius, const char* spriteFilePath,
		float health = 1, float damage = 1, float m_maxSpeed = 1, float maxForce = 1);

	virtual float getHealth() { return m_health; }
	virtual float takeDamage(float damage) { return m_health -= damage; }
	virtual float getDamage() { return m_damage; }
	virtual void setDamage(float damage) { m_damage = damage; }
private:
	float m_health;
	float m_damage;
};

