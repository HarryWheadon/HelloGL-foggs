#include "HelloGL.h"
#include "MeshLoader.h"
#include <iostream>

HelloGL::HelloGL(int argc, char* argv[])
{
	InitLighting();
	InitGL(argc, argv);
	InitObjects();
	glutMainLoop();
}

void HelloGL::InitObjects()
{

	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");
	//Mesh* pyramidMesh = MeshLoader::Load((char*)"pyramid.txt");



	Texture2D* texture = new Texture2D();
	texture->Load((char*)"penguins.raw", 512, 512);

	Texture2D* textureStar = new Texture2D();
	textureStar->Load((char*)"stars.raw", 512, 512);

	camera = new Camera();

	for (int i = 0; i < OBJECTCOUNT; i++)
	{
		objects[i] = new Cube(cubeMesh,texture,((rand() % 400) / 10.0f) - 20.0f, ((rand() % 250) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}

		objects[OBJECTCOUNT] = new Cube(cubeMesh, textureStar, ((rand() % 400) / 10.0f) -20.0f, 30, -(rand() % 1000) / 10.0f);
	
	/*for (int i = 500; i < 1000; i++)
	{
		objects[i] = new Pyramid(pyramidMesh, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}*/

	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	rotation = 0.0f;
}

void HelloGL::InitLighting()
{
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = 1.0;
	_lightPosition->w = 0.0;

	_lightData = new Lighting();
	_lightData->Ambient.x = 0.2;
	_lightData->Ambient.y = 0.2;
	_lightData->Ambient.z = 0.2;
	_lightData->Ambient.w = 1.0;
	_lightData->Diffuse.x = 0.8;
	_lightData->Diffuse.y = 0.8;
	_lightData->Diffuse.z = 0.8;
	_lightData->Diffuse.w = 1.0;
	_lightData->Specular.x = 0.2;
	_lightData->Specular.y = 0.2;
	_lightData->Specular.z = 0.2;
	_lightData->Specular.w = 1.0;

}


void HelloGL::InitGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(500, 100);
	glutCreateWindow("Simple OpenGL Program");
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glMatrixMode(GL_PROJECTION);
	// Set the viewport to be the entire window
	glViewport(0, 0, 800, 800);
	// Set the correct perspective.
	gluPerspective(45, 1, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}

void HelloGL::DrawString(const char* text, Vector3* position, Color* color)
{
	glPushMatrix();
	glTranslatef(position->x, position->y, position->z);
	glRasterPos2f(0.0f, 0.0f);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char*)text);
	//std::cout << position->x << " " << position->y << " " << position->z << std::endl;
	glPopMatrix();
}

void HelloGL::Display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //this clears the scene

	for (int i = 0; i < (OBJECTCOUNT+1); i++)
	{
		objects[i]->Draw();
	}

	Vector3 v = { -0.4f, 0.7f, -3.0f };
	Color c = { 1.0f, 1.0f, 1.0f };
	DrawString(" joe biden", &v, &c);

	glFlush(); //flushes the scene drawn to the graphics card

	glutSwapBuffers();
}

void HelloGL::Update()
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->Diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->Specular.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));
	for (int i = 0; i < (OBJECTCOUNT+1); i++)
	{
		objects[i]->Update();
	}
	glutPostRedisplay();
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
		camera->eye.x += 1.0f;
	if (key == 'a')
		camera->eye.x -= 1.0f;
	if (key == 'w')
		camera->eye.z -= 1.0f;
	if (key == 's')
		camera->eye.z += 1.0f;
	if (key == 't')
		camera->eye.y += 1.0f;
	if (key == 'g')
		camera->eye.y -= 1.0f;
}

HelloGL::~HelloGL(void)
{
	delete camera;
}

