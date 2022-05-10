#include "OBJLoader.h"
#include <iostream>
#include<fstream>
using namespace std;

namespace OBJLoader
{
    OBJ* OBJLoader::Load(char* path)
    {
        OBJ* OBJMesh = new OBJ();

        std::vector< unsigned int > vertexIndices, texIndices, normalIndices;
        std::vector< Vertex > temp_vertices;
        std::vector< TexCoord > temp_texCoord;
        std::vector< Vector3 > temp_normals;

        FILE* file;
        fopen_s(&file, path, "r");

        if (file == NULL) {
            printf("Impossible to open the file !\n");
        }

        if(file != NULL){

        while (1) {
            char lineHeader[128];
            // read the first word of the line
            int res = fscanf_s(file, "%s", lineHeader);
            if (res == EOF)
                break; // EOF = End Of File. Quit the loop.

<<<<<<< Updated upstream
    for (string& line : lines) {
        float x, y, z, u, v;
        if (line[0] == 'v') {
            if (line[1] == ' ') {
                sscanf(line.c_str(), "v %f %f %f", &x, &y, &z);
             x >> mesh->Vertices.x;
                mesh->Vertices[].y;
                mesh->Vertices[].z;
=======
            // else : parse lineHeader
            else if (strcmp(lineHeader, "v") == 0) {
                Vertex vertex;
                fscanf_s(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
                temp_vertices.push_back(vertex);
            }
            else if (strcmp(lineHeader, "vt") == 0) {
                TexCoord uv;
                fscanf_s(file, "%f %f\n", &uv.u, &uv.v);
                temp_texCoord.push_back(uv);
>>>>>>> Stashed changes
            }
            else if (strcmp(lineHeader, "vn") == 0) {
                Vector3 normal;
                fscanf_s(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
                temp_normals.push_back(normal);
            }
            else if (strcmp(lineHeader, "f") == 0) {
                string vertex1, vertex2, vertex3;
                unsigned int  vertexIndex[3], texIndex[3], normalIndex[3];
                int matches = fscanf_s(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &texIndex[0], &normalIndex[0], &vertexIndex[1], &texIndex[1], &normalIndex[1], &vertexIndex[2], &texIndex[2], &normalIndex[2]);
                if (matches != 9) {
                    printf("File can't be read by our simple parser : ( Try exporting with other options\n");
                }
                vertexIndices.push_back(vertexIndex[0]);
                vertexIndices.push_back(vertexIndex[1]);
                vertexIndices.push_back(vertexIndex[2]);
                texIndices.push_back(texIndex[0]);
                texIndices.push_back(texIndex[1]);
                texIndices.push_back(texIndex[2]);
                normalIndices.push_back(normalIndex[0]);
                normalIndices.push_back(normalIndex[1]);
                normalIndices.push_back(normalIndex[2]);
            }
        }
        for (unsigned int i = 0; i < vertexIndices.size(); i++) {
            unsigned int vertexIndex = vertexIndices[i];
           OBJMesh->vertices.push_back(temp_vertices[vertexIndex - 1]);
        }

        for (unsigned int i = 0; i < texIndices.size(); i++) {
            unsigned int texIndex = texIndices[i];
            OBJMesh->texCoord.push_back(temp_texCoord[texIndex - 1]);
        }

        for (unsigned int i = 0; i < normalIndices.size(); i++) {
           unsigned int normalIndex = normalIndices[i];
           OBJMesh->normals.push_back(temp_normals[normalIndex - 1]);
        }
        return OBJMesh;
    }
    }
}