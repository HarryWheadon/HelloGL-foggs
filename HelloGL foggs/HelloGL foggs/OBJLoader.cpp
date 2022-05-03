#include "OBJLoader.h"
#include <iostream>
#include<fstream>
using namespace std;

namespace OBJLoader
{

    OBJMesh* OBJLoader::Load(char* path)
{
        string line = nullptr;
        vector<string> lines;

    OBJMesh* mesh = new OBJMesh();


    std::ifstream inFile;
    inFile.open(path);

    if (!inFile.good())
    {
        std::cerr << "Can't open texture file " << path << std::endl;
        return nullptr;
    }

    while (!inFile .eof()) {
        getline(inFile, line);
        lines.push_back(line);
    }

    for (string& line : lines) {
        float x, y, z, u, v;
        if (line[0] == 'v') {
            if (line[1] == ' ') {
                sscanf(line.c_str(), "v %f %f %f", &x, &y, &z);
             a >> mesh->Vertices.x;
                mesh->Vertices[].y;
                mesh->Vertices[].z;
            }
            else if (line[1] == 't') {
                sscanf(line.c_str(), "vt %f %f", &u, &v);
                mesh->TexCoords[].u;
                mesh->TexCoords[].v;
            }
            else if (line[1] == 'n') {
                sscanf(line.c_str(), "vn %f %f %f", &x, &y, &z);
                mesh->Normals[].x;
                mesh->Normals[].y;
                mesh->Normals[].z;
            }
        }
        else if (line[0] == 'f') {
            int v0, v1, v2, t0, t1, t2, n;
            sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d", &v0, &t0, &n, &v1, &t1, &n, &v2, &t2, &n);


            inFile.close();

            return mesh;
        }
    }
};