#include "SceneObject.h"

SceneObject::SceneObject(Mesh* mesh, OBJ* obj, Texture2D* texture)
{
	_mesh = mesh;
	_obj = obj;
}

SceneObject::~SceneObject()
{
}

void SceneObject::Update()
{
}

void SceneObject::Draw()
{
}
