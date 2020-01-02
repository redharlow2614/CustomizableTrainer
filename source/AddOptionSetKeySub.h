#pragma once
#include "pch.h"
#include "FixedSubmenu.h"

class AddOptionSetKeySub :
	public FixedSubmenu
{
public:
	AddOptionSetKeySub(MenuOptionType optionType, MenuController* menuController, bool hideGetterOnlyOptions = false);

	std::function<void(string key)> onKeySet;
protected:
	void Draw() override;
	void OnKeySelect(string key);
	void CreateDisplayKeys();

	std::vector<string> keys;
	std::vector<string> displayKeys;
	MenuOptionType optionType;
	bool hideGetterOnlyOptions;
};

