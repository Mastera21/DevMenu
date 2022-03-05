#pragma once

//C system headers

//C++ system headers

//Other libraries headers
#include "../imgui/imgui.h"
//Own components headers

//Forward declarations

class MenuBar{
public:
	MenuBar(const MenuBar&) = delete;

	static MenuBar& Get() {
		static MenuBar instance;
		return instance;
	}
	static void Render(ImVec4& clear_color, ImGuiStyle& style, bool& enabled) {
		Get().IRender(clear_color, style, enabled);
	}
private:
	MenuBar() {}

	void IRender(ImVec4& clear_color, ImGuiStyle& style, bool& enabled);

	bool _colorButtonSelected = false;
};

