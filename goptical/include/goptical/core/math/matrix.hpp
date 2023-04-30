/*

      This file is part of the Goptical Core library.

      The Goptical library is free software; you can redistribute it
      and/or modify it under the terms of the GNU General Public
      License as published by the Free Software Foundation; either
      version 3 of the License, or (at your option) any later version.

      The Goptical library is distributed in the hope that it will be
      useful, but WITHOUT ANY WARRANTY; without even the implied
      warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
      See the GNU General Public License for more details.

      You should have received a copy of the GNU General Public
      License along with the Goptical library; if not, write to the
      Free Software Foundation, Inc., 59 Temple Place, Suite 330,
      Boston, MA 02111-1307 USA

      Copyright (C) 2010-2011 Free Software Foundation, Inc
      Author: Alexandre Becoulet

*/

#ifndef GOPTICAL_MATH_MATRIX_HH_
#define GOPTICAL_MATH_MATRIX_HH_

#include <ostream>

#include "goptical/core/common.hpp"

namespace goptical
{

	namespace math
	{

		/**
		   @short NxN square matrix class.
		   @header goptical/core/math/Matrix
		   @module {Core}
		 */
		template <int N> struct Matrix
		{
				/** Get value at x row and y column */
				inline double value (int x, int y) const;
				/** Get modifiable reference to value at x row and y column */
				inline double &value (int x, int y);

				/** Set whole matrix to specified value. */
				inline Matrix &set (double value = 0);
				/** Set whole matrix column to specified value. */
				inline Matrix &set_col (int col, double value);
				/** Set whole matrix row to specified value. */
				inline Matrix &set_row (int row, double value);
				/** Set matrix diagonal to specified value. */
				inline Matrix &set_diag (double value = 1);
				/** Set matrix column to specified vector. */
				inline Matrix &set_col (int col, const Vector<N> &v);
				/** Set matrix row to specified vector. */
				inline Matrix &set_row (int row, const Vector<N> &v);
				/** Set matrix diagonal to specified value. */
				inline Matrix &set_diag (const Vector<N> &v);
				/** Setup an identity matrix. */
				inline Matrix &set_id ();

				/** Add matrix */
				inline Matrix operator+ (const Matrix &m) const;
				/** Subtract matrix */
				inline Matrix operator- (const Matrix &m) const;
				/** Scale matrix */
				inline Matrix operator* (double scale) const;
				/** Scale matrix */
				inline Matrix operator/ (double scale) const;
				/** Multiply matrix */
				inline Matrix operator* (const Matrix &m) const;
				/** Multiply matrix with vector. See Vector class for
				    vector/matrix multiplication. */
				inline Vector<N> operator* (const Vector<N> &v) const;

				/** compute matrix determinant */
				inline double determinant () const;

				/** replace matrix by the transposed matrix */
				void transpose (Matrix &result) const;
				/** replace matrix by the inverse matrix */
				void inverse (Matrix &result) const;
				/** replace matrix by the adjugate matrix */
				void adjugate (Matrix &result) const;

				/** Get the transposed matrix */
				inline Matrix transpose () const;
				/** Get the inverse matrix */
				inline Matrix inverse () const;
				/** Get the adjugate matrix */
				inline Matrix adjugate () const;

			protected:
				double _val[/* row */ N][/* col */ N];
		};

		template <int N>
		std::ostream &operator<< (std::ostream &o, const Matrix<N> &m);
		template <int N>
		double
		Matrix<N>::value (int x, int y) const
		{
			return _val[x][y];
		}

		template <int N>
		double &
		Matrix<N>::value (int x, int y)
		{
			return _val[x][y];
		}

		template <int N>
		Matrix<N> &
		Matrix<N>::set (double value)
		{
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
				{
					_val[i][j] = value;
				}
			return *this;
		}

		template <int N>
		Matrix<N> &
		Matrix<N>::set_col (int col, double value)
		{
			for (int i = 0; i < N; i++)
			{
				_val[i][col] = value;
			}
			return *this;
		}

		template <int N>
		Matrix<N> &
		Matrix<N>::set_row (int row, double value)
		{
			for (int i = 0; i < N; i++)
			{
				_val[row][i] = value;
			}
			return *this;
		}

		template <int N>
		Matrix<N> &
		Matrix<N>::set_diag (double value)
		{
			for (int i = 0; i < N; i++)
			{
				_val[i][i] = value;
			}
			return *this;
		}

		template <int N>
		Matrix<N> &
		Matrix<N>::set_col (int col, const Vector<N> &v)
		{
			for (int i = 0; i < N; i++)
			{
				_val[i][col] = v[i];
			}
			return *this;
		}

		template <int N>
		Matrix<N> &
		Matrix<N>::set_row (int row, const Vector<N> &v)
		{
			for (int i = 0; i < N; i++)
			{
				_val[row][i] = v[i];
			}
			return *this;
		}

		template <int N>
		Matrix<N> &
		Matrix<N>::set_diag (const Vector<N> &v)
		{
			for (int i = 0; i < N; i++)
			{
				_val[i][i] = v[i];
			}
			return *this;
		}

		template <int N>
		Matrix<N> &
		Matrix<N>::set_id ()
		{
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
				{
					_val[i][j] = i == j ? 1.0 : 0.0;
				}
			return *this;
		}

		template <int N>
		Matrix<N>
		Matrix<N>::operator+ (const Matrix &m) const
		{
			Matrix<N> r;
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
				{
					r._val[i][j] = _val[i][j] + m._val[i][j];
				}
			return r;
		}

		template <int N>
		Matrix<N>
		Matrix<N>::operator- (const Matrix &m) const
		{
			Matrix<N> r;
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
				{
					r._val[i][j] = _val[i][j] - m._val[i][j];
				}
			return r;
		}

		template <int N>
		Matrix<N>
		Matrix<N>::operator* (double scale) const
		{
			Matrix<N> r;
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
				{
					r._val[i][j] = _val[i][j] * scale;
				}
			return r;
		}

		template <int N>
		Matrix<N>
		Matrix<N>::operator/ (double scale) const
		{
			Matrix<N> r;
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
				{
					r._val[i][j] = _val[i][j] / scale;
				}
			return r;
		}

		template <int N>
		Matrix<N>
		Matrix<N>::operator* (const Matrix<N> &m) const
		{
			Matrix<N> r;
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
				{
					double s = 0;
					for (int k = 0; k < N; k++)
					{
						s += _val[i][k] * m._val[k][j];
					}
					r._val[i][j] = s;
				}
			return r;
		}

		template <int N>
		Vector<N>
		Matrix<N>::operator* (const Vector<N> &v) const
		{
			Vector<N> r;
			for (int i = 0; i < N; i++)
			{
				double s = 0;
				for (int k = 0; k < N; k++)
				{
					s += _val[i][k] * v[k];
				}
				r[i] = s;
			}
			return r;
		}

		template <int N>
		Matrix<N>
		Matrix<N>::transpose () const
		{
			Matrix<N> r;
			transpose (r);
			return r;
		}

		template <int N>
		Matrix<N>
		Matrix<N>::inverse () const
		{
			Matrix<N> r;
			inverse (r);
			return r;
		}

		template <int N>
		Matrix<N>
		Matrix<N>::adjugate () const
		{
			Matrix<N> r;
			adjugate (r);
			return r;
		}
	}
}

#endif
