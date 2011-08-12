/**
 * \file Matrix.h, Contains the Matrix class.
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
#ifndef GL_MATRIX_H
#define GL_MATRIX_H

#include <boost/numeric/ublas/vector.hpp>

#include <GL/glu.h>

namespace gl {
    /**
     * \class Matrix, Represents an OpenGL matrix.
     */
    class Matrix {
        /**
         * The numeric vector type.
         */
        typedef boost::numeric::ublas::vector<float> Vector;

        public:
            /**
             * Constructs a default Matrix.
             */
            Matrix () {
                glPushMatrix ();
            };
           
            /**
             * Constructs a Matrix with the given mode.
             *
             * \param mode int, The matrix mode.
             */
            Matrix (int mode) {
                glMatrixMode (mode);
                glPushMatrix ();
            };
          
            /**
             * Destroy the Matrix.
             */
            ~Matrix () {
                glPopMatrix ();
            };
           
            /**
             * Resets the Matrix to the identity.
             *
             * \return Matrix&, A reference to this Matrix.
             */
            Matrix& reset () {
                glLoadIdentity ();
                return *this;
            };
           
            /**
             * Re-centers the Matrix at pos.
             *
             * \param pos const Vector&, The position at which to re-center the Matrix.
             *
             * \return Matrix&, A reference to this Matrix.
             */
            Matrix& translate (const Vector& pos) {
                glTranslatef (pos[0], pos[1], pos[2]);
                return *this;
            };
          
            /*
             * Rotates a Matrix.
             *
             * \param angle float, The angle of rotation.
             * \param x float, The x coordinate of the axis of rotation.
             * \param y float, The y coordinate of the axis of rotation.
             * \param z float, The z coordinate of the axis of rotation.
             *
             * \return Matrix&, A reference to this Matrix.
             */
            Matrix& rotate (float angle, float x, float y, float z) {
                glRotatef (angle, x, y, z);
                return *this;
            };
    }; //Matrix
}; //gl

#endif //GL_MATRIX_H

