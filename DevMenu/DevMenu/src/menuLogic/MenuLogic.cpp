#include "../header/menuLogic/MenuLogic.h"
//C system headers

//C++ system headers

//Other libraries headers
#include "../imgui/imguipp.h"

//Own components headers
#include "tabs.h"
#include "icons/icons.h"

#include "alltabs/AllTab.h"
#include "assets/Assets.h"

void MenuLogic::IRender(ImGui::FileBrowser& fileDialog){
	
	ImGui::Columns(2);
	ImGui::SetColumnOffset(1, 75);

	//left side
	{
		static ImVec4 activeButton = imguipp::to_vec4(41, 40, 41, 255);
		static ImVec4 inactiveButton = imguipp::to_vec4(31, 30, 31, 255);

		ImGui::SetCursorPosY(ImGui::GetWindowHeight() - 100);
		//buttons 
		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 4 ? activeButton : inactiveButton);
		if (ImGui::Button(ICON_FA_BOOK "", ImVec2(60, 41))) {
			Settings::Tab = 4;
		}
		ImGui::PopStyleColor();
		ImGui::Spacing();
		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 5 ? activeButton : inactiveButton);
		if (ImGui::Button(ICON_FA_BUG "", ImVec2(60, 41))) {
			Settings::Tab = 5;
		}
		ImGui::PopStyleColor();
	}

	ImGui::NextColumn();

	//right side
	{
		static ImVec4 activeButton = imguipp::to_vec4(41, 40, 41, 255);
		static ImVec4 inactiveButton = imguipp::to_vec4(31, 30, 31, 255);

		//buttons 
		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 1 ? activeButton : inactiveButton);
		if (ImGui::Button(ICON_FA_BOOK " All", ImVec2(170 - 15, 41))) {
			Settings::Tab = 1;
		}
		ImGui::PopStyleColor();
		ImGui::SameLine();
		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 2 ? activeButton : inactiveButton);
		if (ImGui::Button(ICON_FA_ARCHIVE " Assets", ImVec2(170 - 15, 41))) {
			Settings::Tab = 2;
		}
		ImGui::PopStyleColor();
		ImGui::SameLine();
		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 3 ? activeButton : inactiveButton);
		if (ImGui::Button(/*ICON_FA_ANGLE_DOUBLE_RIGHT*/ "User", ImVec2(170 - 15, 41))) {
			Settings::Tab = 3;
		}
		ImGui::PopStyleColor();
		//ImGui::Spacing();

		//(Optional)
		//Add more logic if you want:

		//Menu tab 
		if (Settings::Tab == 1) {
			AllTab::Init();
		}else if (Settings::Tab == 2) {
			Assets::Init(fileDialog);
		}else if (Settings::Tab == 3) {
			ImGui::Text("Implement logic for user");
			//TODO Implement logic:
		}else if (Settings::Tab == 4) {
			ImGui::Text("Implement logic for book");
			//TODO Implement logic:
		}else if (Settings::Tab == 5) {
			ImGui::Text("Implement logic for debug");
			//TODO Implement logic:
		}
	}
}

void MenuLogic::IStyle(ImGuiStyle& style){

	////size window
	style.WindowBorderSize = 0;
	style.WindowTitleAlign = ImVec2(0.5, 0.5);
	style.WindowMinSize = ImVec2(900, 400);
	style.WindowBorderSize = 2.0f;

	//This is for arrow on left side window to disable
	//style.WindowMenuButtonPosition = ImGuiDir_None;

	style.FramePadding = ImVec2(8, 6);
		 
	//window bg color
	//style.Colors[ImGuiCol_WindowBg] = ImColor(63, 91, 97, 255);
		 
	//tite color
	style.Colors[ImGuiCol_TitleBg] = ImColor(255, 101, 53, 255);
	style.Colors[ImGuiCol_TitleBgActive] = ImColor(72, 122, 138, 255);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(0, 0, 0, 130);
		 
	//button color
	style.Colors[ImGuiCol_Button] = ImColor(31, 30, 31, 255);
	style.Colors[ImGuiCol_ButtonActive]= ImColor(51, 50, 51, 255);
	style.Colors[ImGuiCol_ButtonHovered] = ImColor(51, 50, 51, 255);
		 
	//line color
	style.Colors[ImGuiCol_Separator] = ImColor(70, 70, 70, 255);
	style.Colors[ImGuiCol_SeparatorActive] = ImColor(70, 70, 70, 255);
	style.Colors[ImGuiCol_SeparatorHovered] = ImColor(76, 76, 76, 255);
		 
	//Seach bar color
	style.Colors[ImGuiCol_FrameBg] = ImColor(37, 36, 37, 255);
	style.Colors[ImGuiCol_FrameBgActive] = ImColor(37, 36, 37, 255);
	style.Colors[ImGuiCol_FrameBgHovered] = ImColor(37, 36, 37, 255);
		 
	//Hovering color
	style.Colors[ImGuiCol_Header] = ImColor(0, 0, 0, 255);
	style.Colors[ImGuiCol_HeaderActive] = ImColor(0, 0, 0, 0);
	style.Colors[ImGuiCol_HeaderHovered] = ImColor(36, 82, 102, 2555);

	//Child field color
	style.Colors[ImGuiCol_ChildBg] = ImColor(41, 40, 41, 255);
}
