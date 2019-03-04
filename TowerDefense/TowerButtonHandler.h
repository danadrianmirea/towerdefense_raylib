#pragma once
#include "TowerButton.h"
#include "Towerspot.h"

class TowerButtonHandler
{
public:
	static TowerButtonHandler& GetInstance() 
	{
		static TowerButtonHandler instance;
		return instance;
	}
	TowerButtonHandler(TowerButtonHandler const&) = delete;
	void operator=(TowerButtonHandler const&) = delete;
	void AddButton(TowerButton& button);
	void ShowButtons(Towerspot& spot);
	void HideButtons();
	void BuildTower();
private:
	TowerButtonHandler() { currentSpot = NULL; };
	std::list<TowerButton*> towerButtons;
	Towerspot* currentSpot;
};

