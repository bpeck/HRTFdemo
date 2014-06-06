#ifndef __GRID_H__
#define __GRID_H__

class Grid {

    public:
        Grid(float x, float y, float w, float l, int numHcells, int numVcells);
        
        struct VertexData {
            float x;
            float y;
            float z;
            float s;
            float t;
            float face;
            VertexData() :
                x(0.0),
                y(0.0),
                z(0.0),
                s(0.0),
                t(0.0),
                face(0.0)
            {}
            VertexData(float mx, float my, float mz, float ms, float mt, float mface) :
                x(mx),
                y(my),
                z(mz),
                s(ms),
                t(mt),
                face(mface)
            {}
        };
        
        VertexData* data;
        unsigned int numVertices;
        
        void render();

        ~Grid();
};

#endif // GRID_H
