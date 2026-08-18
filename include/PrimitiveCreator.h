#pragma once
#include "Mesh.h"

class PrimitiveCreator{
    public:
        static Mesh CreateSquare();
        static Mesh CreateTriangle();
        static Mesh CreateCube();
};