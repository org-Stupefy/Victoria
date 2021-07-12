-- Victoria Dependencies

--VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Victoria/thirdparty/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Victoria/thirdparty/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Victoria/thirdparty/imgui"
IncludeDir["glm"] = "%{wks.location}/Victoria/thirdparty/glm"
IncludeDir["stb_image"] = "%{wks.location}/Victoria/thirdparty/stb_image"
IncludeDir["entt"] = "%{wks.location}/Victoria/thirdparty/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Victoria/thirdparty/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "%{wks.location}/Victoria/thirdparty/ImGuizmo"
IncludeDir["assimp"] = "%{wks.location}/Victoria/thirdparty/assimp/include"
IncludeDir["VulkanSDK"] = "%{wks.location}/Victoria/thirdparty/VulkanSDK/include"

LibraryDir = {}