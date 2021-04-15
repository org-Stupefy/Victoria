#pragma once

#include <string>
#include "Victoria/Scene/Entity.h"
#include <imgui/imgui.h>
#include <glm/glm.hpp>

namespace Victoria::UI
{
	void BeginViewport(const char* name);
	void EndViewport();

	bool BeginTreeNode(const char* name, bool defaultOpen = true);
	void EndTreeNode();

	void BeginDockspace();
	void EndDockspace();

	bool ToolTip(char* label);
	bool ColorButton(const char* label, const ImVec4& color);
	bool Image(void* imageID, const glm::vec2& viewportDimensions);
	bool ImageButton(void* imageID, glm::vec2 buttonSize);
	bool Text(const char* label, const char* value, float columnWidth = 100.0f);
	bool TextWithoutLabel(std::string* source);

	bool Checkbox(const char* label, bool* boolean, float columnWidth = 100.0f);
	bool Int(const char* label, int* value, float columnWidth = 100.0f);
	bool Float(const char* label, float* value, float columnWidth = 100.0f);
	bool Float2(const char* label, glm::vec2& value, float resetValue = 0.0f, float columnWidth = 100.0f);
	bool Float3(const char* label, glm::vec3& values, float resetValue = 0.0f, float columnWidth = 100.0f);
	bool Float4(const char* label, glm::vec4& value, float resetValue = 0.0f, float columnWidth = 100.0f);
	bool Color4(const char* label, glm::vec4& value, float columnWidth = 100.0f);
	bool Color3(const char* label, glm::vec3& value, float columnWidth = 100.0f);
	bool Dropdown(const char* label, const char** options, int32_t optionCount, int32_t* selected);
	bool Slider(const char* label, int& value, int min, int max);
	bool ToggleButton(const char* label, bool* boolToModify);

	bool BufferingBar(const char* label, float value, const ImVec2& size_arg, const ImU32& bg_col, const ImU32& fg_col);
	bool Spinner(const char* label, float radius, int thickness);
	ImVec4 GetStandardColorImVec4();
	glm::vec4 GetStandardColorGLMVec4();
	

}

