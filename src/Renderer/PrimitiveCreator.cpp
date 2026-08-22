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
            -0.5f,  0.0f, 0.0f, //bottom L
            0.5f, 0.0f, 0.0f, //bottom R
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
            0.5f,  -0.5f, -0.5f, //bottom L
            0.5f, -0.5f, 0.5f, //bottom R
            0.5f, 0.5f, -0.5f, //top L
            0.5f,  0.5f, 0.5f,  //top R
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
        13, 15, 14,
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
            -0.5f,  0.0f, 0.5f, //0
            0.5f, 0.0f, 0.5f, //1
            0.5f, 0.0f, -0.5f, //2
            -0.5f,  0.0f, -0.5f,  //3
            //top
            0.0f,1.0f,0.0f //4
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
            -0.5f,  0.0f, 0.5f, //bottom L
            0.5f, 0.0f, 0.5f, //bottom R
            0.0f, 1.0f, 0.5f, //top
        //back triangle
            -0.5f,  0.0f, -0.5f, //bottom L
            0.5f, 0.0f, -0.5f, //bottom R
            0.0f, 1.0f, -0.5f, //top
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
    for(int i=0; i<segments; i++){
        float x=radius*std::sin(angle*i);
        float y=-radius*std::cos(angle*i);
        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(0);
    }

    for(int i=0; i<segments; i++){
        unsigned int current=i+1;
        unsigned int next=((i+1)%segments)+1;

        indices.push_back(0);
        indices.push_back(next);
        indices.push_back(current);
    }

    VertexBufferLayout layout;
    layout.Push<float>(3);

    return Mesh(vertices,indices,layout);
};

/*
Mesh PrimitiveCreator::CreateSphere(){
 
};
*/
Mesh PrimitiveCreator::CreateCone(int segments,float radius){
    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    //center
    vertices.push_back(0);
    vertices.push_back(0);
    vertices.push_back(0);


    float angle=glm::pi<float>()*2.0f/segments;
    for(int i=0; i<segments; i++){
        float x=radius*std::sin(angle*i);
        float y=-radius*std::cos(angle*i);
        vertices.push_back(x);
        vertices.push_back(0);
        vertices.push_back(y);
    }

    //top
    vertices.push_back(0);
    vertices.push_back(1);
    vertices.push_back(0);

    //bottom
    for(int i=0; i<segments; i++){
        unsigned int current=i+1;
        unsigned int next=((i+1)%segments)+1;

        indices.push_back(0);
        indices.push_back(current);
        indices.push_back(next);
    }

    //sides
    for(int i=0; i<segments; i++){
        unsigned int current=i+1;
        unsigned int next=((i+1)%segments)+1;

        indices.push_back(current);
        indices.push_back(segments+1);
        indices.push_back(next);//top
    }

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
        float x=radius*std::sin(angle*i);
        float y=-radius*std::cos(angle*i);
        vertices.push_back(x);
        vertices.push_back(-0.5f);
        vertices.push_back(y);
    }

    for(int i=0; i<segments; i++){
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
        float x=radius*std::sin(angle*i);
        float y=-radius*std::cos(angle*i);
        vertices.push_back(x);
        vertices.push_back(0.5f);
        vertices.push_back(y);
    }

    
    for(int i=0; i<segments; i++){
        unsigned int current=i+1;
        unsigned int next=((i+1)%segments)+1;

        indices.push_back(offset);
        indices.push_back(next+offset);
        indices.push_back(current+offset);
    }

    //sides
    for(int i=0; i<segments; i++){
        glm::vec3 triangle1,triangle2;
        unsigned int current=i+1;
        unsigned int next=((i+1)%segments)+1;
        triangle1={current,current+offset,next};
        triangle2={next,current+offset,next+offset};
        indices.push_back(triangle1.x);
        indices.push_back(triangle1.y);
        indices.push_back(triangle1.z);
        indices.push_back(triangle2.x);
        indices.push_back(triangle2.y);
        indices.push_back(triangle2.z);
    }

    VertexBufferLayout layout;
    layout.Push<float>(3);

    return Mesh(vertices,indices,layout);
};

