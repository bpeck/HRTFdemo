#include "CubeGrid.h"

CubeGrid::CubeGrid(float x, float y, float z, float w, float l, float h,
    int numXcells, int numYcells, int numZcells) {    
    
    // 3 verts per tri, 2 tris per face, 6 faces per cube
    data = new VertexData[3*2*6 * (numXcells * numYcells * numZcells)];
    
    float xDelta = l / static_cast<float>(numXcells);
    float yDelta = w / static_cast<float>(numYcells);
    float zDelta = h / static_cast<float>(numZcells);
    
    // vertex index
    int v_idx = 0;
    // cube index
    float cube_idx = 0.0f;
    for (int ix=0; ix < numXcells; ix++) {
        for (int iy=0; iy < numYcells; iy++) {
            for (int iz=0; iz < numZcells; iz++) {
                float vX = x + static_cast<float>(ix) * xDelta;
                float vY = y + static_cast<float>(iy) * yDelta;
                float vZ = z + static_cast<float>(iz) * zDelta;
                
                // Define primary vertices of the cube
                VertexData v1(vX, vY, vZ, 0.0, 0.0, -1.0, 0.0, 0.0, cube_idx);
                VertexData v2(vX+xDelta, vY, vZ, 0.0, 0.0, -1.0, 1.0, 0.0, cube_idx);
                VertexData v3(vX+xDelta, vY+yDelta, vZ, 0.0, 0.0, -1.0, 1.0, 1.0, cube_idx);
                VertexData v4(vX, vY+yDelta, vZ, 0.0, 0.0, -1.0, 0.0, 1.0, cube_idx);
                VertexData v5(vX, vY, vZ+zDelta, 0.0, 0.0, 1.0, 0.0, 0.0, cube_idx);
                VertexData v6(vX+xDelta, vY, vZ+zDelta, 0.0, 0.0, 1.0, 1.0, 0.0, cube_idx);
                VertexData v7(vX+xDelta, vY+yDelta, vZ+zDelta, 0.0, 0.0, 1.0, 1.0, 1.0, cube_idx);
                VertexData v8(vX, vY+yDelta, vZ+zDelta, 0.0, 0.0, 1.0, 0.0, 1.0, cube_idx);
                
                // BACK FACE
                data[v_idx++] = v1;
                data[v_idx++] = v4;
                data[v_idx++] = v2;
                data[v_idx++] = v2;
                data[v_idx++] = v4;
                data[v_idx++] = v3;
                
                // FRONT FACE
                data[v_idx++] = v5;
                data[v_idx++] = v6;
                data[v_idx++] = v8;
                data[v_idx++] = v6;
                data[v_idx++] = v7;
                data[v_idx++] = v8;
                
                // LEFT FACE
                data[v_idx++] = v1;
                data[v_idx++] = v5;
                data[v_idx++] = v4;
                data[v_idx++] = v5;
                data[v_idx++] = v8;
                data[v_idx++] = v4;
                
                // RIGHT FACE
                data[v_idx++] = v6;
                data[v_idx++] = v2;
                data[v_idx++] = v7;
                data[v_idx++] = v2;
                data[v_idx++] = v3;
                data[v_idx++] = v7;
                
                // TOP FACE
                data[v_idx++] = v7;
                data[v_idx++] = v3;
                data[v_idx++] = v8;
                data[v_idx++] = v8;
                data[v_idx++] = v3;
                data[v_idx++] = v4;
                
                // BOTTOM FACE
                data[v_idx++] = v5;
                data[v_idx++] = v1;
                data[v_idx++] = v6;
                data[v_idx++] = v6;
                data[v_idx++] = v1;
                data[v_idx++] = v2;
                
                cube_idx += 1.0f;
            }
        }
    }
    
    numVertices = v_idx;
}

CubeGrid::~CubeGrid() {
    delete[] static_cast<VertexData*>(data);
}
