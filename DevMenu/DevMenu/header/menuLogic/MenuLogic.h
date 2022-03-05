#pragma once
//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "filebrowser/imfilebrowser.h"
//Forward declarations

class MenuLogic {
public:
	MenuLogic(const MenuLogic&) = delete;

	static MenuLogic& Get() {
		static MenuLogic instance;
		return instance;
	}

	static void Style(ImGuiStyle& style) {
		Get().IStyle(style);
	}
	static void Render(ImGui::FileBrowser& fileDialog) {
		Get().IRender(fileDialog);
	}
private:
	MenuLogic() = default;

	void IStyle(ImGuiStyle& style);
	void IRender(ImGui::FileBrowser& fileDialog);
};