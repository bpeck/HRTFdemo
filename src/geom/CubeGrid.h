#ifndef __CUBEGRID_H__
#define __CUBEGRID_H__

class CubeGrid {

    public:
        CubeGrid(float x, float y, float z, float w, float l, float h,
            int numXcells, int numYcells, int numZcells);
        
        struct VertexData {
            float x;
            float y;
            float z;
            float nx;
            float ny;
            float nz;
            float s;
            float t;
            float cube_id;
            VertexData() :
                x(0.0),
                y(0.0),
                z(0.0),
                nx(0.0),
                ny(0.0),
                nz(0.0),
                s(0.0),
                t(0.0),
                cube_id(0.0)
            {}
            VertexData(float mx, float my, float mz, float mnx, float mny, float mnz,
                float ms, float mt, float mcube_id) :
                x(mx),
                y(my),
                z(mz),
                nx(mnx),
                ny(mny),
                nz(mnz),
                s(ms),
                t(mt),
                cube_id(mcube_id)
            {}
        };
        
        VertexData* data;
        unsigned int numVertices;
        
        void render();

        ~CubeGrid();
};

#endif // CUBEGRID_H
