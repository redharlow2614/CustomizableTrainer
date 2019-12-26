/*
	THIS FILE IS A PART OF RDR 2 SCRIPT HOOK SDK
				http://dev-c.com
			(C) Alexander Blade 2019
*/

#include "pch.h"
#include "Script.h"
#include "MenuController.h"
#include "Controls.h"
#include "Routine.h"
#include "ActionController.h"
#include "ToggleController.h"
#include "NumberController.h"
#include "HotkeyController.h"

void setup()
{
	ActionController::RegisterActions();
	ToggleController::RegisterToggles();
	NumberController::RegisterNumbers();
	HotkeyController::Setup();
	Game::RequestTextureDict("menu_textures");
	Game::RequestTextureDict("boot_flow");
}

void main()
{
	setup();
	MenuController* menu = new MenuController();
	while (true) {
		Routine::RunAll();
		menu->Tick();
		WAIT(0);
	}
}

void ScriptMain()
{
	srand(GetTickCount());
	main();
}