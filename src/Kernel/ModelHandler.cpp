#include "Kernel/ModelHandler.hpp"

namespace Sarah
{
namespace Kernel
{

// Constructeur et destructeur
ModelHandler::ModelHandler():
    gConfig(),
	m_loadedMesh(nullptr),
	m_generalClock()
{
    
}

ModelHandler::ModelHandler(GeneralConfig & p_gConfig):
    gConfig(p_gConfig),
	m_loadedMesh(nullptr),
	m_generalClock()
{
    
}

ModelHandler::~ModelHandler()
{

}

//Fonctions spécifiques
bool ModelHandler::Init()
{

    GLfloat * triangle = new GLfloat[21];

    triangle[0] = -50;
    triangle[1] = -50;
    triangle[2] = -50;
    triangle[3] = 0;
    triangle[4] = 0;
    triangle[5] = 1;
    triangle[6] = 1;

    triangle[7] = -50;
    triangle[8] =  50;
    triangle[9] = -50;
    triangle[10] = 0;
    triangle[11] = 0;
    triangle[12] = 1;
    triangle[13] = 1;

    triangle[14] = -50;
    triangle[15] = -50;
    triangle[16] =  50;
    triangle[17] = 0;
    triangle[18] = 0;
    triangle[19] = 1;
    triangle[20] = 1;

    return Load(triangle);
}

bool ModelHandler::Load(GLfloat * p_toLoadMesh)
{
	m_loadedMesh = p_toLoadMesh;

	// Enable position and color vertex components
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 7 * sizeof(GLfloat), m_loadedMesh);
    glColorPointer(4, GL_FLOAT, 7 * sizeof(GLfloat), m_loadedMesh + 3);

    // Disable normal and texture coordinates vertex components
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	return true;
}

}
}