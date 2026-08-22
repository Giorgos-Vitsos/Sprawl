#pragma once
#include "Mesh.h"

class PrimitiveCreator{
    public:
        static Mesh CreatePlane();
        static Mesh CreateTriangle();
        static Mesh CreateCube();
        static Mesh CreatePyramid();
        static Mesh CreateCircle();
        static Mesh CreateSphere();
        static Mesh CreateCone();
        static Mesh CreatePrism();
        static Mesh CreateCylinder();
};