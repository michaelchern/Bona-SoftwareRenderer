#pragma once

#include "../util/geometry.h"
#include "../util/tgaimage.h"

namespace Michael
{
    class InputAssembler
    {
    public:
        using Ptr = std::shared_ptr<InputAssembler>;
        static Ptr create(const std::string filename)
        {
            return std::make_shared<InputAssembler>(filename);
        }

        InputAssembler(const std::string filename);
        ~InputAssembler();
        int nverts() const;
        int nfaces() const;
        vec3 vert(const int i) const;
        vec3 vert(const int iface, const int nthvert) const;
        vec3 normal(const int iface, const int nthvert) const;
        vec3 normal(const vec2& uv) const;
        vec2 uv(const int iface, const int nthvert) const;
        const TGAImage& diffuse() const;
        const TGAImage& specular() const;

    public:
        std::vector<vec3> verts = {};
        std::vector<vec3> norms = {};
        std::vector<vec2> tex = {};
        std::vector<int> facet_vrt = {};
        std::vector<int> facet_nrm = {};
        std::vector<int> facet_tex = {};
        TGAImage diffusemap = {};
        TGAImage normalmap = {};
        TGAImage specularmap = {};
    };
}
