//#pragma once
//
//struct IShader
//{
//    static TGAColor sample2D(const TGAImage& img, const vec2& uvf)
//    {
//        return img.get(uvf[0] * img.width(), uvf[1] * img.height());
//    }
//
//    virtual bool fragment(const vec3 bar, TGAColor& color) const = 0;
//};
//
//struct Shader : IShader
//{
//    const Model& model;
//    vec3 uniform_l;       // light direction in view coordinates
//    mat<3, 2> varying_uv;  // triangle uv coordinates, written by the vertex shader, read by the fragment shader
//    mat<3, 3> varying_nrm; // normal per vertex to be interpolated by FS
//    mat<3, 3> view_tri;    // triangle in view coordinates
//
//    Shader(const vec3 l, const Model& m) : model(m)
//    {
//        uniform_l = normalized((ModelView * vec4{ l.x, l.y, l.z, 0. }).xyz()); // transform the light vector to view coordinates
//    }
//
//    virtual void vertex(const int iface, const int nthvert, vec4& gl_Position)
//    {
//        vec3 n = model.normal(iface, nthvert);
//        vec3 v = model.vert(iface, nthvert);
//        gl_Position = ModelView * vec4{ v.x, v.y, v.z, 1. };
//        varying_uv[nthvert] = model.uv(iface, nthvert);
//        varying_nrm[nthvert] = (ModelView.invert_transpose() * vec4 { n.x, n.y, n.z, 0. }).xyz();
//        view_tri[nthvert] = gl_Position.xyz();
//        gl_Position = Projection * gl_Position;
//    }
//
//    virtual bool fragment(const vec3 bar, TGAColor& gl_FragColor) const
//    {
//        vec3 bn = normalized(bar * varying_nrm); // per-vertex normal interpolation
//        vec2 uv = bar * varying_uv;              // tex coord interpolation
//
//        mat<3, 3> AI = mat<3, 3>{ {view_tri[1] - view_tri[0], view_tri[2] - view_tri[0], bn} }.invert(); // for the math refer to the tangent space normal mapping lecture
//        vec3 i = AI * vec3{ varying_uv[1].x - varying_uv[0].x, varying_uv[2].x - varying_uv[0].x, 0 };   // https://github.com/ssloy/tinyrenderer/wiki/Lesson-6bis-tangent-space-normal-mapping
//        vec3 j = AI * vec3{ varying_uv[1].y - varying_uv[0].y, varying_uv[2].y - varying_uv[0].y, 0 };
//        mat<3, 3> B = mat<3, 3>{ { normalized(i), normalized(j), bn } }.transpose();
//
//        vec3 n = normalized(B * model.normal(uv));          // transform the normal from the texture to the tangent space
//        vec3 r = normalized(n * (n * uniform_l) * 2 - uniform_l); // reflected light direction, specular mapping is described here: https://github.com/ssloy/tinyrenderer/wiki/Lesson-6-Shaders-for-the-software-renderer
//        double diff = std::max(0., n * uniform_l);                                       // diffuse light intensity
//        double spec = std::pow(std::max(-r.z, 0.), 5 + sample2D(model.specular(), uv)[0]); // specular intensity, note that the camera lies on the z-axis (in view), therefore simple -r.z
//
//        TGAColor c = sample2D(model.diffuse(), uv);
//        for (int i : {0, 1, 2})
//            gl_FragColor[i] = std::min<int>(10 + c[i] * (diff + spec), 255); // (a bit of ambient light, diff + spec), clamp the result
//        return false; // do not discard the pixel
//    }
//};
