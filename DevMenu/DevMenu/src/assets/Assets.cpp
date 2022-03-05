#include "../header/assets/Assets.h"
//C system headers

//C++ system headers

//Other libraries headers
#include "icons/icons.h"

//Own components headers

void Assets::Init(ImGui::FileBrowser& fileDialog) {

	ImGui::BeginChild("##AssetsTab", ImVec2(ImGui::GetWindowSize().x - 90, ImGui::GetWindowSize().y - 130), true);

	//TODO: Implement specific logic for your game.

	if (ImGui::CollapsingHeader("Utility")) {
		ImGui::Text("Implement logic:");
	}
	if (ImGui::CollapsingHeader("Materials")) {
		ImGui::Text("Implement logic:");
	}
	if (ImGui::CollapsingHeader("Items")) {
		if(ImGui::TreeNode("Guns")) {
			ImGui::Text("Implement logic:");

			ImGui::TreePop();
		}
	}

	ImGui::SetCursorPosY(ImGui::GetWindowHeight() - 45);
	if(ImGui::Button(ICON_FA_FOLDER_OPEN " Open Files ..", ImVec2(205, 34))) {
		fileDialog.Open();
	}

	ImGui::EndChild();

}
