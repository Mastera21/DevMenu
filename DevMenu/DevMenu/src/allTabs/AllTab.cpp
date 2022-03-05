#include "../header/allTabs/AllTab.h"

//C system headers

//C++ system headers
#include <sstream>
#include <iostream>
//Other libraries headers
#include "../imgui/imguipp.h"
#include "icons/icons.h"
//Own components headers
 
void AllTab::Init() {
	ImGui::BeginChild("##All selection", ImVec2(ImGui::GetWindowSize().x - 90, ImGui::GetWindowSize().y - 130), true);

	//background color
	ImGui::PushStyleColor(ImGuiCol_FrameBg, IM_COL32(50, 50, 50, 255));

	static std::vector<std::string> resources = {
			"Spawn Items",
			"Revive Player",
			"Vehicle",
			"Teleport",
			"Weather/Time",
			"Ban ID",
			"Give Item",
	};
	SearchField(resources);

	ImGui::PopStyleColor();

	ImGui::EndChild();
}
void AllTab::SearchField(const std::vector<std::string>& resources) {
	ImGuiTextFilter filter;
	filter.Draw(ICON_FA_SEARCH " Search", ImGui::GetWindowSize().x - 16);
	bool checkBox = true;

	//Searching for files
	if (ImGui::ListBoxHeader("##ListBox", ImVec2(imguipp::getx(), imguipp::gety() - 5))) {
		for (const auto& i : resources) {
			if (filter.PassFilter(i.c_str())) {
				std::string nameFile = i.c_str();
				if(ImGui::TreeNode(nameFile.c_str())){
					//Buttons color
					ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(ImColor(72, 122, 138)));
					if (nameFile == "Spawn Items") {
						std::string name = "";
						int idPlayer = 0;

						if (ImGui::BeginChild("Items", ImVec2(ImGui::GetWindowSize().x - 50, 260), true)) {
							{
								ImGui::Text("Enter Name:");
								ImGui::Spacing();
								static char str1[128] = "";
								if (ImGui::InputTextWithHint(" ", "Type here", str1, IM_ARRAYSIZE(str1))) {
									//Handle input:
									std::stringstream iss(str1);
									iss >> name;

									//TODO Implement logic:

								}
							}
							ImGui::Separator();
							ImGui::Spacing();
							{
								ImGui::Text("Enter ID:");
								static char str2[8] = "";
								if (ImGui::InputTextWithHint("  ", "Type here", str2, IM_ARRAYSIZE(str2))) {
									//Handle input:
									std::stringstream iss(str2);
									iss >> idPlayer;


									//TODO Implement logic:
								}
							}
							ImGui::Separator();
							ImGui::Spacing();
							{
								ImGui::Text("Enter count:");
								static int i0 = 0;
								if (ImGui::InputInt("", &i0)) {
									//TODO Implement logic:
								}
							}
							ImGui::Separator();
							ImGui::Spacing();
							{
								if (ImGui::Button("Execute", ImVec2(80, 30))) {
									//TODO Implement logic:
								}
							}
							ImGui::EndChild();
						}
					}else if (nameFile == "Revive Player") {
						int idPlayer = 0;
						if (ImGui::BeginChild("RevPlayer", ImVec2(ImGui::GetWindowSize().x - 50, 120), true)) {
							{
								ImGui::Text("Enter ID:");
								static char str2[8] = "";
								if (ImGui::InputTextWithHint("  ", "Type here", str2, IM_ARRAYSIZE(str2))) {
									std::stringstream iss(str2);
									iss >> idPlayer;
									//TODO Implement logic:
								}
							}
							ImGui::Separator();
							ImGui::Spacing();
							{
								if (ImGui::Button("Execute", ImVec2(80, 30))) {
									//TODO Implement logic:
								}
							}
							ImGui::EndChild();
						}
					}else if (nameFile == "Vehicle") {
						std::string name = "";
						std::string model = "";

						if (ImGui::BeginChild("Vehicle", ImVec2(ImGui::GetWindowSize().x - 50, 290), true)) {
							{
								ImGui::Text("Enter brand name:");
								ImGui::Spacing();
								static char str1[128] = "";
								if (ImGui::InputTextWithHint(" ", "Type here", str1, IM_ARRAYSIZE(str1))) {
									//Handle input:
									std::stringstream iss(str1);
									iss >> name;

									//TODO Implement logic:
								}
							}
							ImGui::Separator();
							ImGui::Spacing();
							{
								ImGui::Text("Enter model name:");
								ImGui::Spacing();
								static char str1[128] = "";
								if (ImGui::InputTextWithHint("", "Type here", str1, IM_ARRAYSIZE(str1))) {
									//Handle input:
									std::stringstream iss(str1);
									iss >> model;

									//TODO Implement logic:
								}
							}
							ImGui::Separator();
							ImGui::Spacing();
							{
								ImGui::Checkbox("Repaire", &checkBox);
								if (checkBox) {
									//TODO Implement logic:
									checkBox = false;
								}
							}
							ImGui::Separator();
							ImGui::Spacing();
							{
								!ImGui::Checkbox("Spawn", &checkBox);

								//TODO Implement logic:
							}
							ImGui::Separator();
							ImGui::Spacing();
							{
								if (ImGui::Button("Execute", ImVec2(80, 30))) {
									//TODO Implement logic:
								}
							}
							ImGui::EndChild();
						}
					}else if (nameFile == "Teleport") {
						std::string s = "";

						if (ImGui::BeginChild("Teleport", ImVec2(ImGui::GetWindowSize().x - 50, 190), true)) {
							{
								ImGui::Text("Enter Name:");
								static char str2[128] = "";
								if (ImGui::InputTextWithHint("  ", "Type here", str2, IM_ARRAYSIZE(str2))) {
									//Handle input:
									std::stringstream iss(str2);
									iss >> s;

									//TODO Implement logic:
								}
							}
							ImGui::Separator();
							ImGui::Spacing();
							{
								ImGui::Text("Enter coordinates:");
								static char str2[12] = "";
								std::string input = "";
								if (ImGui::InputTextWithHint(" ", "Enter coordinates with symbol '.' bettween 3 numbers", str2, IM_ARRAYSIZE(str2))) {
									//Handle input:
									std::stringstream iss(str2);
									iss >> input;

									//TODO Implement logic:


								}
							}
							ImGui::Separator();
							ImGui::Spacing();
							{
								if (ImGui::Button("Execute", ImVec2(80, 30))) {
									//TODO Implement logic:
								}
							}
							ImGui::EndChild();
						}
					}else if (nameFile == "Weather/Time") {
						std::string s = "";

						if (ImGui::BeginChild("Weather/Time", ImVec2(ImGui::GetWindowSize().x - 50, 235), true)) {
							{
								ImGui::Text("Time:");
								static char str1[6] = "";
								if (ImGui::InputTextWithHint(" ", "Type here", str1, IM_ARRAYSIZE(str1))) {
									std::stringstream iss(str1);
									iss >> s;

									//TODO Implement logic:
								}
							}
							ImGui::Separator();
							ImGui::Spacing();
							{
								static const char* items[]{ " ","Heavy Fog", "Very Sunny", "Mostly Clear", "Little Cloudy", "Murky Skies" };
								static int selectedItem = 0;
								ImGui::Text("Weather:");
								ImGui::Combo("", &selectedItem, items, IM_ARRAYSIZE(items));
							}
							ImGui::Separator();
							ImGui::Spacing();
							{
								ImGui::Checkbox("Blackout", &checkBox);
								if (checkBox) {
									//TODO Implement logic:
								}
							}
							ImGui::Separator();
							ImGui::Spacing();
							{
								if (ImGui::Button("Execute", ImVec2(80, 30))) {
									//TODO Implement logic:
								}
							}
							ImGui::EndChild();
						}
					}else if (nameFile == "Ban ID") {
						int idPlayer = 0;
						if (ImGui::BeginChild("BanID", ImVec2(ImGui::GetWindowSize().x - 50, 120), true)) {
							//ID text bar
							{
								ImGui::Text("Enter ID:");
								static char str2[8] = "";
								if (ImGui::InputTextWithHint("  ", "Type here", str2, IM_ARRAYSIZE(str2))) {
									std::stringstream iss(str2);
									iss >> idPlayer;

									//TODO Implement logic:
								}
							}
							ImGui::Separator();
							ImGui::Spacing();
							{
								if (ImGui::Button("Execute", ImVec2(80, 30))) {
									//TODO Implement logic:
								}
							}
							ImGui::EndChild();
						}
					}else if (nameFile == "Give Item") {
						std::vector<std::string>vec = { "M4" };
						std::string s = "";

						if (ImGui::BeginChild("GiveItem", ImVec2(ImGui::GetWindowSize().x - 50, 190), true)) {
							{
								ImGui::Text("Enter item name:");
								ImGui::Spacing();
								static char str1[128] = "";
								if (ImGui::InputTextWithHint("", "Type here", str1, IM_ARRAYSIZE(str1))) {
									//Read for input:
									std::stringstream iss(str1);
									iss >> s;

									//TODO Implement logic:

								}
							}
							ImGui::Separator();
							ImGui::Spacing();
							{
								ImGui::Text("Enter target id");
								static char str2[8] = "";
								if (ImGui::InputTextWithHint("  ", "Type here", str2, IM_ARRAYSIZE(str2))) {
									std::stringstream iss(str2);
									iss >> s;

									//TODO Implement logic:
								}
							}
							ImGui::Separator();
							ImGui::Spacing();
							{
								if (ImGui::Button("Execute", ImVec2(80, 30))) {

									//TODO Implement logic:

								}
							}
							ImGui::EndChild();
						}
					}
					ImGui::PopStyleColor();
					ImGui::TreePop();
				}
			}
		}
		ImGui::ListBoxFooter();
	}
}
