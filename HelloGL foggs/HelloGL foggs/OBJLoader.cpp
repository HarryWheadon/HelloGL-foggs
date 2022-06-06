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
        std::vector< Vertex> temp_vertices;
        std::vector< TexCoord> temp_texCoord;
        std::vector< Vector3> temp_normals;

        FILE* file;
        fopen_s(&file, path, "r");

        if(file != NULL){

        while (1) {
            char lineHeader[128];
            // read the first word of the line
            int res = fscanf_s(file, "%s", lineHeader, 100);

            if (res == EOF)
                break; // loops until the end of the file

            // else : parse lineHeader
            else if (strcmp(lineHeader, "v") == 0) {
                Vertex vertex;
                fscanf_s(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
                temp_vertices.push_back(vertex);
               /* cout << "v" << "  " << vertex.x << " " << vertex.y << " " << vertex.z;
                cout << endl;*/
            }

            else if (strcmp(lineHeader, "vt") == 0) {
                TexCoord uv;
                fscanf_s(file, "%f %f\n", &uv.u, &uv.v);
                temp_texCoord.push_back(uv);
                /*cout << "vt" << "  " << uv.u << " " << uv.v;
                cout << endl;*/
            }

            else if (strcmp(lineHeader, "vn") == 0) {
                Vector3 normal;
                fscanf_s(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
                temp_normals.push_back(normal);
                /*cout << "vn" << "  " << normal.x << " " << normal.y << " " << normal.z;
                cout << endl;*/
            }

            else if (strcmp(lineHeader, "f") == 0) {
                string vertex1, vertex2, vertex3;
                unsigned int  vertexIndex[4], texIndex[4], normalIndex[4];
                fscanf_s(file, "%d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &texIndex[0], &normalIndex[0], &vertexIndex[1], &texIndex[1], &normalIndex[1], &vertexIndex[2], &texIndex[2], &normalIndex[2], &vertexIndex[3], &texIndex[3], &normalIndex[3]);
               /* cout << "f" << "  " << vertexIndex[0] << " / " << texIndex[1] << " / " << normalIndex[0] << "  " << vertexIndex[1] << " / " << texIndex[1] << " / " << normalIndex[1] << "  " << vertexIndex[2] << " / " << texIndex[2] << " / " << normalIndex[2] << "  " << vertexIndex[3] << " / " << texIndex[3] << " / " << normalIndex[3];
                cout << endl;*/
                vertexIndices.push_back(vertexIndex[0]);
                vertexIndices.push_back(vertexIndex[1]);
                vertexIndices.push_back(vertexIndex[2]);
                    vertexIndices.push_back(vertexIndex[3]);
                texIndices.push_back(texIndex[0]);
                texIndices.push_back(texIndex[1]);
                texIndices.push_back(texIndex[2]);
                texIndices.push_back(texIndex[3]);
                normalIndices.push_back(normalIndex[0]);
                normalIndices.push_back(normalIndex[1]);
                normalIndices.push_back(normalIndex[2]);
                normalIndices.push_back(normalIndex[3]);
            }
        }
        
        for (unsigned int i = 0; i < vertexIndices.size(); i++) {
            unsigned int vertexIndex = vertexIndices[i];
            Vertex vertex = temp_vertices[vertexIndex - 1];
           OBJMesh->vertices.push_back(vertex);
        }

        for (unsigned int i = 0; i < texIndices.size(); i++) {
            unsigned int texIndex = texIndices[i];
            TexCoord tex = temp_texCoord[texIndex - 1];
            OBJMesh->texCoord.push_back(tex);
        }

        for (unsigned int i = 0; i < normalIndices.size(); i++) {
           unsigned int normalIndex = normalIndices[i];
           Vector3 normal = temp_normals[normalIndex - 1];
           OBJMesh->normals.push_back(normal);
        }
        return OBJMesh;

    }
    }
}