#include "vcpch.h"
#include "Sphere.h"

namespace Victoria
{
    Sphere::Sphere()
    {
        init(48);
    }
    Sphere::Sphere(int precision)
    {
        init(precision);
    }
    float Sphere::toRadians(float degrees)
    {
        return (degrees * 3.14159f) / 180.0f;
    }
    void Sphere::init(int precision)
    {
        numVertices = (precision + 1) * (precision + 1);
        numIndices = precision * precision * 6;
        for (int i = 0; i < numVertices; i++)
        {
            vertices.push_back(glm::vec3());
        }
        for (int i = 0; i < numVertices; i++)
        {
            texCoords.push_back(glm::vec2());
        }
        for (int i = 0; i < numVertices; i++)
        {
            normals.push_back(glm::vec3());
        }
        for (int i = 0; i < numIndices; i++)
        {
            indices.push_back(0);
        }
        for (int i = 0; i <= precision; i++)
        {
            for (int j = 0; j <= precision; j++)
            {
                float y = (float)cos(toRadians(180.0f - i * 180.0f / precision));
                float x = -(float)cos(toRadians(j * 360.0f / precision)) * (float)abs(cos(asin(y)));
                float z = (float)sin(toRadians(j * 360.0f / precision)) * (float)abs(cos(asin(y)));
                vertices[i * (precision + 1) + j] = glm::vec3(x, y, z);
                texCoords[i * (precision + 1) + j] = glm::vec2(((float)j / precision), ((float)i / precision));
                normals[i * (precision + 1) + j] = glm::vec3(x, y, z);
            }
        }
        for (int i = 0; i < precision; i++)
        {
            for (int j = 0; j < precision; j++)
            {
                indices[6 * (i * precision + j) + 0] = i * (precision + 1) + j;
                indices[6 * (i * precision + j) + 1] = i * (precision + 1) + j + 1;
                indices[6 * (i * precision + j) + 2] = (i + 1) * (precision + 1) + j;
                indices[6 * (i * precision + j) + 3] = i * (precision + 1) + j + 1;
                indices[6 * (i * precision + j) + 4] = (i + 1) * (precision + 1) + j + 1;
                indices[6 * (i * precision + j) + 5] = (i + 1) * (precision + 1) + j;
            }
        }
    }
    int Sphere::getNumVertices()
    {
        return numVertices;
    }
    int Sphere::getNumIndices()
    {
        return numIndices;
    }
    std::vector<int> Sphere::getIndices()
    {
        return indices;
    }
    std::vector<glm::vec3> Sphere::getVertices()
    {
        return vertices;
    }
    std::vector<glm::vec2> Sphere::getTexCoords()
    {
        return texCoords;
    }
    std::vector<glm::vec3> Sphere::getNormals()
    {
        return normals;
    }
} // namespace Victoria

//TODO: Reference taken from Computer Graphics Programming in OpenGL with C++ {Page 136}