#pragma once

//C system headers

//C++ system headers

//Other libraries headers
#include "../imgui/imgui.h"
//Own components headers
#include "filebrowser/imfilebrowser.h"
//Forward declarations

namespace Assets{
	void Init(ImGui::FileBrowser& fileDialog);
};

