#include "MeshLoader.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace MeshLoader
{

    Mesh* MeshLoader::Load(char* path)
    {
        Mesh* mesh = new Mesh();

        ifstream inFile;

        inFile.open(path);

        if (!inFile.good())
        {
            cerr << "Can't open texture file " << path << endl;
            return nullptr;
        }

        inFile >> mesh->VertexCount;

        if (mesh->VertexCount > 0)
        {
            mesh->Vertices = new Vertex[mesh->VertexCount];

            for (int i = 0; i < mesh->VertexCount; i++)
            {
                inFile >> mesh->Vertices[i].x;
                inFile >> mesh->Vertices[i].y;
                inFile >> mesh->Vertices[i].z;
            }
        }

        inFile >> mesh->ColorCount;

        if (mesh->ColorCount > 0)
        {
            mesh->Colors = new Color[mesh->ColorCount];

            for (int i = 0; i < mesh->ColorCount; i++)
            {
                inFile >> mesh->Colors[i].r;
                inFile >> mesh->Colors[i].g;
                inFile >> mesh->Colors[i].b;
            }
        }

        inFile >> mesh->TexCoordCount;

        if (mesh->TexCoordCount > 0)
        {
            mesh->TexCoords = new TexCoord[mesh->TexCoordCount];

            for (int i = 0; i < mesh->TexCoordCount; i++)
            {
                inFile >> mesh->TexCoords[i].u;
                inFile >> mesh->TexCoords[i].v;
            }
        }

        inFile >> mesh->IndexCount;

        if (mesh->IndexCount > 0)
        {
            mesh->Indices = new GLushort[mesh->IndexCount];

            for (int i = 0; i < mesh->IndexCount; i++)
            {
                inFile >> mesh->Indices[i];
            }
        }

        inFile.close();

        return mesh;
    }
}