#pragma once
#include "Mesh.h"

class PrimitiveCreator{
    public:
        static Mesh CreatePlane();
        static Mesh CreateTriangle();
        static Mesh CreateCube();
        static Mesh CreatePyramid();
        static Mesh CreateCircle(int segments=12,float radius=0.5f);
        static Mesh CreateSphere(int segments=12,float radius=0.5f);
        static Mesh CreateCone(int segments=12,float radius=0.5f);
        static Mesh CreatePrism();
        static Mesh CreateCylinder(int segments=12,float radius=0.5f);
};