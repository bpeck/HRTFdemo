#include "Grid.h"

Grid::Grid(float x, float y, float w, float l, int numHcells, int numVcells) {    
    // we make two copies of the data, because we have separate face ids
    data = new VertexData[6 * (numVcells * numHcells)];
    
    float vDelta = l / static_cast<float>(numVcells);
    float hDelta = w / static_cast<float>(numHcells);
    
    // vertex index
    int v_idx = 0;
    // face index
    float f_idx = 0;
    for (int v=0; v < numVcells; v++) {
        for (int h=0; h < numHcells; h++) {
            float vX = x + static_cast<float>(h) * hDelta;
            float vY = y + static_cast<float>(v) * vDelta;
            float vZ = 0.0;
            // TRIANGLE 1
            VertexData v1(vX, vY, vZ, 0.0, 0.0, f_idx);
            VertexData v2(vX, vY+vDelta, vZ, 0.0, 1.0, f_idx);
            VertexData v3(vX+hDelta, vY+vDelta, vZ, 1.0, 1.0, f_idx);
            // TRIANGLE 2
            VertexData v4 = v1;
            VertexData v5 = v3;
            VertexData v6(vX+hDelta, vY, vZ, 1.0, 0.0, f_idx);
            
            data[v_idx++] = v1;
            data[v_idx++] = v2;
            data[v_idx++] = v3;
            data[v_idx++] = v4;
            data[v_idx++] = v5;
            data[v_idx++] = v6;
            
            f_idx++;
        }
    }
    
    numVertices = v_idx;
}

Grid::~Grid() {
    delete[] static_cast<VertexData*>(data);
}
