//#pragma once
//
//#include "geometry.h"
//
//namespace Michael
//{
//    class Triangle
//    {
//    public:
//        vec4 points[3]; 
//        vec3 point_colors[3];
//        vec2 tex_coords[3];
//        vec3 point_normals[3];
//
//        Triangle();
//
//        vec4 a() const { return points[0]; }
//        vec4 b() const { return points[1]; }
//        vec4 c() const { return points[2]; }
//
//        void setVertex(int ind, vec4 point);
//        void setNormal(int ind, vec3 n);
//        void setColor(int ind, float r, float g, float b); /*set i-th vertex color*/
//
//        void setNormals(const std::array<Vector3f, 3>& normals);
//        void setColors(const std::array<Vector3f, 3>& colors);
//        void setTexCoord(int ind, Vector2f uv);
//        //std::array<Vector4f, 3> toVector4() const;
//    };
//
//}
