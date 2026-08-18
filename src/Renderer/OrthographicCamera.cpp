#include "OrthographicCamera.h"
#include <glm/gtc/matrix_transform.hpp>

OrthographicCamera::OrthographicCamera(float left,float right,float botom,float top){
    m_ProjMatrix=glm::ortho(left, right, botom, top, -1.0f, 1.0f);
}