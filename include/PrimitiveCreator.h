#pragma once
#include "Mesh.h"

/**
 * @brief Creates primitive meshes for the engine.
 * 
 * Supports all meshes of primitive shapes and some more advanced.
 */
class PrimitiveCreator{
    public:
        /**
         * @brief Constructor is disable because class is static.
         */
        PrimitiveCreator()=delete;

        /**
         * @brief Creates a plane.
         * 
         * @returns The mesh of a plane.
         */
        static Mesh CreatePlane();

        /**
         * @brief Creates a triangle.
         * 
         * @returns The mesh of a triangle.
         */
        static Mesh CreateTriangle();

        /**
         * @brief Creates a cube.
         * 
         * @returns The mesh of a cube.
         */
        static Mesh CreateCube();

        /**
         * @brief Creates a pyramid.
         * 
         * @returns The mesh of a pyramid.
         */
        static Mesh CreatePyramid();

        /**
         * @brief Creates a circle.
         * 
         * @param segments The number of point along the circumference.
         * @param radius The radius of the circle.
         * @returns The mesh of a circle.
         */
        static Mesh CreateCircle(int segments=12,float radius=0.5f);

        /**
         * @brief Creates a sphere.
         * 
         * @param sectors The number of point along the circumference.
         * @param stacks The number of points from top to bottom.
         * @param radius The radius of the sphere.
         * @returns The mesh of a sphere.
         */
        static Mesh CreateSphere(int sectors=12,int stacks=12,float radius=0.5f);

        /**
         * @brief Creates a cone.
         * 
         * @param segments The number of point along the circumference of the bottom circle.
         * @param radius The radius of the bottm circle.
         * @returns The mesh of a cone.
         */
        static Mesh CreateCone(int segments=12,float radius=0.5f);

        /**
         * @brief Creates a prism.
         * 
         * @returns The mesh of a prism.
         */
        static Mesh CreatePrism();

        /**
         * @brief Creates a cylinderr.
         * 
         * @param segments The number of point along the circumference of each circle.
         * @param radius The radius of each circle.
         * @returns The mesh of a cylinder.
         */
        static Mesh CreateCylinder(int segments=12,float radius=0.5f);
};