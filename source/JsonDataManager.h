#pragma once
#include "pch.h"


class JSONDataManager {
public:
	JSONDataManager();
	void Load();
	std::map<string, SubmenuData> GetLayoutAsMap();
	void UpdateMenuSettings();
	std::vector<Hotkey> GetHotkeysAsVector();
	void SaveLayoutFromMap(std::map<string, SubmenuData> submenuDataMap);
	void SaveMenuSettings(bool showSavedMessage = false);
	void SaveHotkeys(std::vector<Hotkey> hotkeys);
private:
	json LoadJSONFile(string path);
	string ReadFile(string path);
	void WriteFile(string path, string content);
	json layoutData;
	json settingsData;
};