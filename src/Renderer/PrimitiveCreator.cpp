#include "PrimitiveCreator.h"
#include <cmath>
#include <glm/gtc/constants.hpp>
#include <glm/glm.hpp>

Mesh PrimitiveCreator::CreatePlane(){
    std::vector<float> vertices = {
             -0.5f,  0.0f, 0.5f, //0
             0.5f, 0.0f, 0.5f, //1
            0.5f, 0.0f, -0.5f, //2
            -0.5f,  0.0f, -0.5f  //3
        };

    std::vector<unsigned int> indices = {
            0, 1, 3, 
            1, 2, 3 
        };
    
    VertexBufferLayout layout;
    layout.Push<float>(3);
    
    return Mesh(vertices,indices,layout);
};

Mesh PrimitiveCreator::CreateTriangle(){
    std::vector<float> vertices = {
            -0.5f,  -0.5f, 0.0f, //bottom L
            0.5f, -0.5f, 0.0f, //bottom R
            0.0f, 0.5f, 0.0f //top
        };

    std::vector<unsigned int> indices = {
            0, 1, 2 
        };
    
    VertexBufferLayout layout;
    layout.Push<float>(3);
    
    return Mesh(vertices,indices,layout);
};

Mesh PrimitiveCreator::CreateCube(){
    std::vector<float> vertices = {

            //front
            -0.5f,  -0.5f, 0.5f, //bottom L
            0.5f, -0.5f, 0.5f, //bottom R
            -0.5f, 0.5f, 0.5f, //top L
            0.5f,  0.5f, 0.5f,  //top R
            //back
            -0.5f,  -0.5f, -0.5f, //bottom L
            0.5f, -0.5f, -0.5f, //bottom R
            -0.5f, 0.5f, -0.5f, //top L
            0.5f,  0.5f, -0.5f,  //top R
            //left
            -0.5f,  -0.5f, -0.5f, //bottom L
            -0.5f, -0.5f, 0.5f, //bottom R
            -0.5f, 0.5f, -0.5f, //top L
            -0.5f,  0.5f, 0.5f,  //top R
            //right
            0.5f,  -0.5f, -0.5f, //bottom L 12
            0.5f, -0.5f, 0.5f, //bottom R 13
            0.5f, 0.5f, -0.5f, //top L 14
            0.5f,  0.5f, 0.5f,  //top R 15
            //top
            -0.5f,  0.5f, 0.5f, //bottom L
            0.5f, 0.5f, 0.5f, //bottom R
            -0.5f, 0.5f, -0.5f, //top L
            0.5f,  0.5f, -0.5f,  //top R
            //bottom
            -0.5f,  -0.5f, 0.5f, //bottom L
            0.5f, -0.5f, 0.5f, //bottom R
            -0.5f, -0.5f, -0.5f, //top L
            0.5f,  -0.5f, -0.5f,  //top R
        };

    std::vector<unsigned int> indices = {
        //front
        0, 1, 3,
        2, 0, 3,
        //back
        4, 6, 5,
        6, 7, 5,
        //left
        8, 9, 11,
        10, 8, 11,
        //right
        12, 14, 13,
        14, 15, 13,
        //top
        16, 17, 19,
        16, 19, 18,
        //bottom
        20, 22, 21,
        22, 23, 21
    };

    VertexBufferLayout layout;
    layout.Push<float>(3);

    return Mesh(vertices, indices, layout);
};

Mesh PrimitiveCreator::CreatePyramid(){
    std::vector<float> vertices = {
            //bottom
            -0.5f,  -0.5f, 0.5f, //0
            0.5f, -0.5f, 0.5f, //1
            0.5f, -0.5f, -0.5f, //2
            -0.5f,  -0.5f, -0.5f,  //3
            //top
            0.0f,0.5f,0.0f //4
        };

    std::vector<unsigned int> indices = {
            0, 3, 1, 
            1, 3, 2,
            0,1,4,
            1,2,4,
            2,3,4,
            0,4,3
        };
    
    VertexBufferLayout layout;
    layout.Push<float>(3);
    
    return Mesh(vertices,indices,layout);
};

Mesh PrimitiveCreator::CreatePrism(){
    std::vector<float> vertices = {
        //front triangle
            -0.5f,  -0.5f, 0.5f, //bottom L
            0.5f, -0.5f, 0.5f, //bottom R
            0.0f, 0.5f, 0.5f, //top
        //back triangle
            -0.5f,  -0.5f, -0.5f, //bottom L
            0.5f, -0.5f, -0.5f, //bottom R
            0.0f, 0.5f, -0.5f, //top
        };

    std::vector<unsigned int> indices = {
            0, 1, 2,
            3,5,4,
            0,2,3,
            3,2,5,
            1,5,2,
            1,4,5,
            0, 3, 1,
            1, 3, 4
        };
    
    VertexBufferLayout layout;
    layout.Push<float>(3);
    
    return Mesh(vertices,indices,layout);
};

Mesh PrimitiveCreator::CreateCircle(int segments,float radius){
    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    //center
    vertices.push_back(0);
    vertices.push_back(0);
    vertices.push_back(0);

    float angle=glm::pi<float>()*2.0f/segments;

    for(int i=0; i<segments; i++){//each point of the circle

        //vertices
        float x=radius*std::sin(angle*i);
        float y=-radius*std::cos(angle*i);

        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(0);

        //indices
        unsigned int current=i+1;
        unsigned int next=((i+1)%segments)+1;

        indices.push_back(0);
        indices.push_back(current);
        indices.push_back(next);
    }

    VertexBufferLayout layout;
    layout.Push<float>(3);

    return Mesh(vertices,indices,layout);
};

Mesh PrimitiveCreator::CreateCone(int segments,float radius){
    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    //center
    vertices.push_back(0);
    vertices.push_back(-0.5f);
    vertices.push_back(0);

    float angle=glm::pi<float>()*2.0f/segments;

    for(int i=0; i<segments; i++){

        //create the circle
        float x=radius*std::sin(angle*i);
        float y=-radius*std::cos(angle*i);

        vertices.push_back(x);
        vertices.push_back(-0.5f);
        vertices.push_back(y);

        //indices
        unsigned int current=i+1;
        unsigned int next=((i+1)%segments)+1;

        //connect circle
        indices.push_back(0);
        indices.push_back(current);
        indices.push_back(next);

        //connect sides
        indices.push_back(current);
        indices.push_back(segments+1);
        indices.push_back(next);
    }

    //top
    vertices.push_back(0);
    vertices.push_back(0.5f);
    vertices.push_back(0);

    VertexBufferLayout layout;
    layout.Push<float>(3);

    return Mesh(vertices,indices,layout);
};

Mesh PrimitiveCreator::CreateCylinder(int segments,float radius){
    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    float angle=glm::pi<float>()*2.0f/segments;

    //cicle 1
    vertices.push_back(0);
    vertices.push_back(-0.5f);
    vertices.push_back(0);

    for(int i=0; i<segments; i++){

        //vertices
        float x=radius*std::sin(angle*i);
        float y=-radius*std::cos(angle*i);

        vertices.push_back(x);
        vertices.push_back(-0.5f);
        vertices.push_back(y);

        //indices
        unsigned int current=i+1;
        unsigned int next=((i+1)%segments)+1;

        indices.push_back(0);
        indices.push_back(current);
        indices.push_back(next);
    }

    //circle2
    int offset=segments+1;

    vertices.push_back(0);
    vertices.push_back(0.5f);
    vertices.push_back(0);

    for(int i=0; i<segments; i++){

        //vertices
        float x=radius*std::sin(angle*i);
        float y=-radius*std::cos(angle*i);

        vertices.push_back(x);
        vertices.push_back(0.5f);
        vertices.push_back(y);

        //indices
        unsigned int current=i+1;
        unsigned int next=((i+1)%segments)+1;

        indices.push_back(offset);
        indices.push_back(next+offset);
        indices.push_back(current+offset);

        //sides
        indices.push_back(current);
        indices.push_back(current+offset);
        indices.push_back(next);
        indices.push_back(next);
        indices.push_back(current+offset);
        indices.push_back(next+offset);
    }

    VertexBufferLayout layout;
    layout.Push<float>(3);

    return Mesh(vertices,indices,layout);
};

Mesh PrimitiveCreator::CreateSphere(int sectors,int stacks,float radius){
    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    for(int i=0; i<=stacks;i++){

        float phi=glm::pi<float>()*((float)i/(float)stacks);
        float y=radius*std::cos(phi);
        float sliceRadius=radius*std::sin(phi);

        for(int j=0; j<=sectors;j++){

            float theta=2*glm::pi<float>()*((float)j/(float)sectors);
            float x=sliceRadius*std::sin(theta);
            float z=sliceRadius*std::cos(theta);
            
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);
        }
    }

    for(int i=0; i<stacks;i++){
        for(int j=0; j<sectors;j++){

            unsigned int A=(i*(sectors+1)+j);
            unsigned int B=A+1;
            unsigned int C=(i+1)*(sectors+1)+j;
            unsigned int D=C+1;

            indices.push_back(A);
            indices.push_back(C);
            indices.push_back(B);
            indices.push_back(B);
            indices.push_back(C);
            indices.push_back(D);
        }
    }

    VertexBufferLayout layout;
    layout.Push<float>(3);

    return Mesh(vertices,indices,layout);

};
