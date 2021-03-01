#pragma once

#include "vcpch.h"
#include <glm/glm.hpp>

namespace Victoria
{
    class Sphere
    {
    public:
        Sphere();
        Sphere(int precision);
        int getNumVertices();
        int getNumIndices();
        std::vector<int> getIndices();
        std::vector<glm::vec3> getVertices();
        std::vector<glm::vec2> getTexCoords();
        std::vector<glm::vec3> getNormals();

    private:
        int numVertices;
        int numIndices;
        std::vector<int> indices;
        std::vector<glm::vec3> vertices;
        std::vector<glm::vec2> texCoords;
        std::vector<glm::vec3> normals;
        void init(int);
        float toRadians(float degrees);
    };
} 

//TODO: Reference taken from Computer Graphics Programming in OpenGL with C++ {Page 136}
