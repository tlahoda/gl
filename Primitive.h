/**
 * \file Primitive.h, Contains various primitive classes.
 *
 * Copyright (C) 2005 Thomas P. Lahoda
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#ifndef GL_PRIMITIVE_H
#define GL_PRIMITIVE_H

#include <boost/mpl/aux_/config/static_constant.hpp>

#include <GL/glu.h>

namespace gl {
    /**
     * @struct Quads, Represents quads.
     */
    struct Quads {
        /**
         * The value of the OpenGL primitive.
         */
        BOOST_STATIC_CONSTANT (int, value = GL_QUADS);
    }; //Quads

    /**
     * @struct QuadStrip, Represents a quad strip.
     */
    struct QuadStrip {
        /**
         * The value of the OpenGL primitive.
         */
        BOOST_STATIC_CONSTANT (int, value = GL_QUAD_STRIP);
    }; //QuadStrip

    /**
     * @struct Tringles, Represents triangles.
     */
    struct Triangles {
        /**
         * The value of the OpenGL primitive.
         */
        BOOST_STATIC_CONSTANT (int, value = GL_TRIANGLES);
    }; //Triangles

    /**
     * @struct TriangleStrip, Represents a triangle strip.
     */
    struct TriangleStrip {
        /**
         * The value of the OpenGL primitive.
         */
        BOOST_STATIC_CONSTANT (int, value = GL_TRIANGLE_STRIP);
    }; //TriangleStrip

    /**
     * @struct TriangleFan, Represents a triangle fan.
     */
    struct TriangleFan {
        /**
         * The value of the OpenGL primitive.
         */
        BOOST_STATIC_CONSTANT (int, value = GL_TRIANGLE_FAN);
    }; //TriangleFan

    /**
     * @struct Lines, Represents a line.
     */
    struct Lines {
        /**
         * The value of the OpenGL primitive.
         */
        BOOST_STATIC_CONSTANT (int, value = GL_LINES);
    }; //Lines

    /**
     * @struct LineStrip, Represents a line strip.
     */
    struct LineStrip {
        /**
         * The value of the OpenGL primitive.
         */
        BOOST_STATIC_CONSTANT (int, value = GL_LINE_STRIP);
    }; //LineStrip

    /**
     * @struct LineLoop, Represents a line loop.
     */
    struct LineLoop {
        /**
         * The value of the OpenGL primitive.
         */
        BOOST_STATIC_CONSTANT (int, value = GL_LINE_LOOP);
    }; //LineLoop

    /**
     * @struct Points, Represents points.
     */
    struct Points {
        /**
         * The value of the OpenGL primitive.
         */
        BOOST_STATIC_CONSTANT (int, value = GL_POINTS);
    }; //Points

    /**
     * @struct Polygon, Represents a polygon.
     */
    struct Polygon {
        /**
         * The value of the OpenGL primitive.
         */
        BOOST_STATIC_CONSTANT (int, value = GL_POLYGON);
    }; //Polygon

    /**
     * @class Primitive, Represents an OpenGL primitive..
     *
     * \tparam Type, The type of the Primitive.
     */
    template<class Type>
    class Primitive {
        public:
           /**
            * Constructs a Primitive.
            */
           Primitive () {
               glBegin (Type::value);
           };

           /**
            * Destroys the Primitive.
            */
           ~Primitive () {
               glEnd ();
           };
    }; //Primitive
}; //gl

#endif //GL_PRIMITIVE_H

