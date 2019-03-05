#pragma once
#include "GameEntity.h"
#include "Behaviour.h"

class Tower : public GameEntity
{
public:
	enum TowerType { ARCHER, MAGIC };
public:
	Tower(Texture2D& image, Vector2 coordinates = { 0., 0. }, float rotation = 0., float scale = 1., float range = 0, float delay = 0, int baseDamage = 0)
		:GameEntity(image, coordinates, rotation, scale)
	{
		Behaviour::GetInstance().Register(*this);//register for update and draw calls
		this->range = range;
		this->delay = delay;
		this->baseDamage = baseDamage;
		level = 1;
	}
	~Tower() 
	{
		Behaviour::GetInstance().Unregister(*this);
	};
	Tower::TowerType GetTowerType();
	float GetRange();
	float GetDelay();
	int GetDamage();
	void LevelUpgrade();
private:
	TowerType towerType;
	float range;
	float delay;
	int baseDamage;
	int level;
};

