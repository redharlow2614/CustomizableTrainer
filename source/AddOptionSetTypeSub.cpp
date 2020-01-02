#include "pch.h"
#include "AddOptionSetTypeSub.h"

AddOptionSetTypeSub::AddOptionSetTypeSub(MenuController* menuController, bool hideSubmenu, bool hideAction)
	: FixedSubmenu(menuController)
{
	this->hideSubmenu = hideSubmenu;
	this->hideAction = hideAction;
}

// MARK: Draw

void AddOptionSetTypeSub::Draw()
{
	Submenu::Draw();

	DrawTitle("Type");
	if (!hideSubmenu)
		DrawAction("Submenu", [this]() {
			onTypeSet(MenuOptionType::Sub); 
			menuController->GoToLastSub();
		});

	if (!hideAction)
		DrawAction("Action", [this]() {
			onTypeSet(MenuOptionType::Action);
			menuController->GoToLastSub();
		});

	DrawAction("Toggle", [this]() {
		onTypeSet(MenuOptionType::Toggle);
		menuController->GoToLastSub();
	});

	DrawAction("Number", [this]() {
		onTypeSet(MenuOptionType::Number);
		menuController->GoToLastSub();
	});

	DrawAction("Text", [this]() {
		onTypeSet(MenuOptionType::Text);
		menuController->GoToLastSub();
	});
}
