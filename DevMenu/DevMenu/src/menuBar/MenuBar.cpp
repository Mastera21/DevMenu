#include "../header/menuBar/MenuBar.h"

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

void MenuBar::IRender(ImVec4& clear_color, ImGuiStyle& style, bool& enabled) {
    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("Files")) {
            if (ImGui::MenuItem("Save")) {
                //Save changes.
                //TODO
            }
            if (ImGui::BeginMenu("Options")) {
                if (ImGui::MenuItem("Color Window")) {
                    _colorButtonSelected = true;
                }
                ImGui::EndMenu();
            }
            if (ImGui::MenuItem("Quit")) {
                enabled = false;
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
    if (_colorButtonSelected) {
        !ImGui::Begin("Color", &_colorButtonSelected);
        if (ImGui::ColorEdit3("Background Color", (float*)&clear_color)) {
            style.Colors[ImGuiCol_WindowBg] = ImColor(clear_color);
        }
        ImGui::End();
    }
}
