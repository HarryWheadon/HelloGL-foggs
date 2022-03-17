#include "HelloGL.h"
#include "MeshLoader.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	InitGL(argc, argv);
	InitObjects();
	glutMainLoop();
}

void HelloGL::InitObjects()
{

	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");
	Mesh* pyramidMesh = MeshLoader::Load((char*)"pyramid.txt");



	Texture2D* texture = new Texture2D();
	texture->Load((char*)"penguins.raw", 512, 12);

	camera = new Camera();

	for (int i = 0; i < 500; i++)
	{
		objects[i] = new Cube(cubeMesh,texture,((rand() % 400) / 10.0f) - 20.0f, ((rand() % 250) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}


	for (int i = 500; i < 1000; i++)
	{
		objects[i] = new Pyramid(pyramidMesh, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}

	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	rotation = 0.0f;
}

void HelloGL::InitGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitDisplayMode(GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGL Program");
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glMatrixMode(GL_PROJECTION);
	// Set the viewport to be the entire window
	glViewport(0, 0, 800, 800);
	// Set the correct perspective.
	gluPerspective(45, 1, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //this clears the scene
	for (int i = 0; i < 1000; i++)
	{
		objects[i]->Draw();
	}
	glFlush(); //flushes the scene drawn to the graphics card
	glutSwapBuffers();
}

void HelloGL::Update()
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	for (int i = 0; i < 1000; i++)
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
}

HelloGL::~HelloGL(void)
{
	delete camera;
}

