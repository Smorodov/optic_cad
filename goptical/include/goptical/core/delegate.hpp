/* -*- c++ -*-

   C++ delegate classes

   This file is part of the dpp library of C++ template classes

   doc: http://diaxen.ssji.net/dpp/index.html
   repo: https://www.ssji.net/svn/projets/trunk/libdpp

   This program is free software: you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public License
   as published by the Free Software Foundation, either version 3 of
   the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this program.  If not, see
   <http://www.gnu.org/licenses/>.

   (c) 2008-2011 Alexandre Becoulet <alexandre.becoulet@free.fr>

*/

#ifndef DPP_DELEGATE_HH_
#define DPP_DELEGATE_HH_

#include <iostream>

/** @file @module{Delegates} */

namespace dpp
{

#ifndef _DPP_DR106
	/** @internal Workaround for c++ DR 106, strip reference */
	template <class X>
	struct _dr106
	{
		typedef X type;
	};

	/** @internal */
	template <class X>
	struct _dr106<X &>
	{
		typedef X type;
	};

	/** @internal */
# define _DPP_DR106(x) typename _dr106<x>::type
#endif

	//////////////////////////////////////////////////////////////////////
	//	delegate base class
	//////////////////////////////////////////////////////////////////////

	/**
	   @short Delegates base class
	   @main
	   @module{Delegates}
	   @header dpp/delegate

	   All other classes in the @ref +Delegates module inherit from this
	   class. This enables passing delegates pointers and references to
	   functions in a generic and interchangeable manner.

	   Actual implementations for different parameters count are located
	   in class specializations.

	   Maximum number of arguments is defined by the @ref
	   #DPP_DELEGATE_ARGC macro.
	*/
	template <typename prototype>
	class delegate
	{
	};

#ifndef DPP_DELEGATE_ARGC
	/** @This defines maximum number of arguments handled by delegate
	    classes. It can be defined before inclusion of the header so
	    that class specialization declarations take place to handle up
	    to 8 arguments. The default value is 4. */
# define DPP_DELEGATE_ARGC 4
#endif

#define _DPP_DELEGATE(n)				\
	/** @module{Delegates} */				\
	template <typename R _DPP_DELEGATE_TARGS(n)>		\
	class delegate < R (_DPP_DELEGATE_PARGS(n)) >		\
	{							\
			virtual R call (_DPP_DELEGATE_CARGS(n)) const = 0;	\
			\
		public:						\
			_DPP_DELEGATE_TDEFS(n); /* args typedefs */		\
			virtual bool valid() const = 0;			\
			virtual ~delegate() {}				\
			\
			R operator() (_DPP_DELEGATE_CARGS(n)) const		\
			{							\
				return call (_DPP_DELEGATE_IARGS(n));		\
			}							\
			\
	};

	//////////////////////////////////////////////////////////////////////
	//	function pointer delegate class
	//////////////////////////////////////////////////////////////////////

	/**
	   @short Function pointer delegate class
	   @main
	   @module{Delegates}
	   @header dpp/delegate

	   This delegate class embeds a pointer to a global or static member
	   function.

	   Actual implementations for different parameters count are located
	   in class specializations.

	   Maximum number of handled arguments is controlled by the @ref
	   #DPP_DELEGATE_ARGC macro.

	   Usage example:
	   @example test/test_delegate.cc:func1
	   @example test/test_delegate.cc:func2

	   @see delegate_member
	   @see delegate_member_this
	*/
	template <typename prototype>
	class delegate_func : public delegate<prototype>
	{
	};

#define _DPP_DELEGATE_FUNC(n)						\
	/** @module{Delegates} */						\
	template <typename R _DPP_DELEGATE_TARGS(n)>				\
	class delegate_func < R (_DPP_DELEGATE_PARGS(n)) >			\
		: public delegate< R (_DPP_DELEGATE_PARGS(n)) >			\
	{									\
			typedef R prototype (_DPP_DELEGATE_PARGS(n));			\
			\
		public:								\
			delegate_func()							\
				: _func(0)							\
			{									\
			}									\
			\
			delegate_func(prototype *p)						\
				: _func(p)							\
			{									\
			}									\
			\
			bool valid() const							\
			{									\
				return _func;							\
			}									\
			\
			R operator()(_DPP_DELEGATE_CARGS(n)) const				\
			{									\
				return delegate_func::call (_DPP_DELEGATE_IARGS(n));		\
			}									\
			\
		private:								\
			\
			R call (_DPP_DELEGATE_CARGS(n)) const				\
			{									\
				return _func (_DPP_DELEGATE_IARGS(n));				\
			}									\
			\
			prototype *_func;							\
	};

	//////////////////////////////////////////////////////////////////////
	//	member function pointer delegate classes
	//////////////////////////////////////////////////////////////////////

	/**
	   @short Member function pointer delegate class
	   @header dpp/delegate
	   @main

	   This delegate class embeds a pointer to an object and take a
	   member function to call as template argument.

	   Actual implementations for different parameters count are located
	   in class specializations.

	   Maximum number of handled arguments is controlled by the @ref
	   #DPP_DELEGATE_ARGC macro.

	   Usage example:
	   @example test/test_delegate.cc:member1
	   @example test/test_delegate.cc:member2

	   Delegate with @tt const member function type is only supported by
	   gcc 4.4 and clang compilers.

	   @see delegate_member_this
	   @see delegate_func
	*/
	template <class O, typename prototype, prototype O::*F>
	class delegate_member : public delegate<prototype>
	{
	};

#define _DPP_DELEGATE_MEMBER_(n, cst)					\
	/** @module{Delegates} */						\
	template <class O, typename R _DPP_DELEGATE_TARGS(n),			\
	R (O::*F)(_DPP_DELEGATE_PARGS(n)) cst >			\
	class delegate_member < O, R (_DPP_DELEGATE_PARGS(n)) cst, F >	\
		: public delegate< R (_DPP_DELEGATE_PARGS(n)) >			\
	{									\
		public:								\
			\
			delegate_member()							\
				: _obj(0)								\
			{									\
			}									\
			\
			delegate_member(O &obj)						\
				: _obj(&obj)							\
			{									\
			}									\
			\
			bool valid() const							\
			{									\
				return _obj;							\
			}									\
			\
			R operator()(_DPP_DELEGATE_CARGS(n)) const				\
			{									\
				return delegate_member::call(_DPP_DELEGATE_IARGS(n));		\
			}									\
			\
		private:								\
			R call (_DPP_DELEGATE_CARGS(n)) const				\
			{									\
				return (_obj->*F)(_DPP_DELEGATE_IARGS(n));			\
			}									\
			\
			O *_obj;								\
	};

#if ((__GNUC__ == 4 && __GNUC_MINOR__ >= 4) || (__GNUC__ > 4)) && !defined(__INTEL_COMPILER)
# define _DPP_DELEGATE_MEMBER(n)		\
	_DPP_DELEGATE_MEMBER_(n,)                     \
	_DPP_DELEGATE_MEMBER_(n, const)
#else
# define _DPP_DELEGATE_MEMBER(n)		\
	_DPP_DELEGATE_MEMBER_(n,)
#endif

	/** @internal contains typedef with prototype without first argument */
	template <typename prototype>
	struct delegate_member_this_pm1
	{
	};

	/** @internal */
	template <typename A>
	struct _delegate_member_this_ptr
	{
		static A & get(A &a)
		{
			return a;
		}
	};

	/** @internal */
	template <typename A>
	struct _delegate_member_this_ptr<A *>
	{
		static A & get(A *a)
		{
			return *a;
		}
	};

	/** @internal */
	template <typename A>
	struct _delegate_member_this_type
	{
		typedef A t;
	};
	/** @internal */
	template <typename A>
	struct _delegate_member_this_type<A *>
	{
		typedef A t;
	};
	/** @internal */
	template <typename A>
	struct _delegate_member_this_type<A &>
	{
		typedef A t;
	};

	/**
	   @short Member function pointer delegate class
	   @header dpp/delegate
	   @prototype template <typename prototype, prototype_without_1st_arg O::*F>
	   @main

	   This delegate takes a member function to call as template
	   argument and invoke this function on object passed as first
	   delegate argument. Object argument may be a reference or a pointer.

	   Actual implementations for different parameters count are located
	   in class specializations.

	   Maximum number of handled arguments is controlled by the @ref
	   #DPP_DELEGATE_ARGC macro.

	   Usage example:
	   @example test/test_delegate.cc:member1
	   Use with reference argument:
	   @example test/test_delegate.cc:member_arg
	   Use with pointer argument:
	   @example test/test_delegate.cc:member_arg2

	   Delegate with @tt const member function type is only supported by
	   gcc 4.4 and clang compilers.

	   @see delegate_member
	   @see delegate_func
	 */
	template <typename prototype, typename delegate_member_this_pm1<prototype>::p
	(_delegate_member_this_type<typename delegate_member_this_pm1<prototype>::a0_t>::t::*F)>
	class delegate_member_this : public delegate<prototype>
	{
	};


#define _DPP_DELEGATE_MEMBER_THIS_(n, cst)				\
	\
	/** @internal @module{Delegates} */					\
	template <typename R _DPP_DELEGATE_TARGS(n) >				\
	struct delegate_member_this_pm1 < R (_DPP_DELEGATE_PARGS(n)) cst >	\
	{									\
	                                    typedef A0 a0_t;							\
	                                    typedef R p(_DPP_DELEGATE_PARGS_NOT0(n)) cst;			\
	};									\
	\
	/** @module{Delegates} */						\
	template <typename R _DPP_DELEGATE_TARGS(n),				\
	R (_delegate_member_this_type<A0>::t::*F)			\
	(_DPP_DELEGATE_PARGS_NOT0(n)) cst >			\
	class delegate_member_this < R (_DPP_DELEGATE_PARGS(n)) cst, F >	\
		: public delegate< R (_DPP_DELEGATE_PARGS(n)) >			\
	{									\
		public:								\
			\
			bool valid() const							\
			{									\
				return true;							\
			}									\
			\
			R operator()(_DPP_DELEGATE_CARGS(n)) const				\
			{									\
				return delegate_member_this::call(_DPP_DELEGATE_IARGS(n));		\
			}									\
			\
		private:								\
			R call (_DPP_DELEGATE_CARGS(n)) const				\
			{									\
				return (_delegate_member_this_ptr<A0>::get(a0)			\
				        .*F)(_DPP_DELEGATE_IARGS_NOT0(n));			\
			}									\
	};

#if ((__GNUC__ == 4 && __GNUC_MINOR__ >= 4) || (__GNUC__ > 4)) && !defined(__INTEL_COMPILER)
#define _DPP_DELEGATE_MEMBER_THIS(n)                    \
	_DPP_DELEGATE_MEMBER_THIS_(n,)			\
	_DPP_DELEGATE_MEMBER_THIS_(n, const)
#else
#define _DPP_DELEGATE_MEMBER_THIS(n)                    \
	_DPP_DELEGATE_MEMBER_THIS_(n,)
#endif

	//////////////////////////////////////////////////////////////////////
	//	delegate bind class
	//////////////////////////////////////////////////////////////////////

	/** @module{Delegates}
	    Specify delegate argument positions. */
	enum delegate_args_mask_e
	{
	    arg1st = 1,
	    arg2nd = 2,
	    arg3rd = 4,
	    arg4th = 8,
	    arg5th = 16,
	    arg6th = 32,
	    arg7th = 64,
	    arg8th = 128
	};

	/**
	   @short Parameter bind delegate class
	   @main
	   @module{Delegates}
	   @header dpp/delegate

	   This delegate class can be used to bind some parameters of an
	   other delegate to fixed values.

	   Actual implementations for different parameters configurations
	   are located in class specializations.

	   Maximum number of handled arguments is controlled by the @ref
	   #DPP_DELEGATE_ARGC macro.

	   Usage example:
	   @example test/test_delegate.cc:bind1
	   @example test/test_delegate.cc:bind2

	   @see delegate_args_mask_e
	*/
	template <typename base, typename prototype, int args_mask>
	class delegate_bind : public delegate<prototype>
	{
	};

#define _DPP_DELEGATE_BIND(args_mask, n, m, tdefs, ...)			\
	/** @module{Delegates} @hidden */					\
	template <typename base, typename R _DPP_DELEGATE_TARGS(n)>		\
	class delegate_bind < base, R (_DPP_DELEGATE_PARGS(n)), args_mask >	\
		: public delegate< R (_DPP_DELEGATE_PARGS(n)) >			\
	{									\
			typedef R prototype(_DPP_DELEGATE_PARGS(n));			\
			tdefs;								\
			\
		public:								\
			delegate_bind(const base &b _DPP_DELEGATE_BCARGS(m))		\
				: _base(b) _DPP_DELEGATE_BCSTR(m)					\
			{								\
			}								\
			\
			bool valid() const							\
			{									\
				return _base.valid();						\
			}									\
			\
			R operator()(_DPP_DELEGATE_CARGS(n)) const				\
			{									\
				return delegate_bind::call(_DPP_DELEGATE_IARGS(n));		\
			}									\
			\
		private:								\
			\
			R call(_DPP_DELEGATE_CARGS(n)) const				\
			{									\
				return _base(__VA_ARGS__);					\
			}									\
			\
			const base &_base;							\
			_DPP_DELEGATE_BFIELD(m);						\
	};

	//////////////////////////////////////////////////////////////////////
	//	template specializations for multiple parameters configurations
	//////////////////////////////////////////////////////////////////////

#define _DPP_DELEGATE_CM ,
#define _DPP_DELEGATE_SC ;
#define _DPP_DELEGATE_SP

#define _DPP_DELEGATE_N0(sep, _1, _2, _3, _4, _5, _6, _7, _8)

#define _DPP_DELEGATE_N1(sep, _1, _2, _3, _4, _5, _6, _7, _8) _1
#define _DPP_DELEGATE_N1_M1(...) _DPP_DELEGATE_N0(__VA_ARGS__)

#define _DPP_DELEGATE_N2(sep, _1, _2, _3, _4, _5, _6, _7, _8)	\
	_1 _DPP_DELEGATE_##sep _2
#define _DPP_DELEGATE_N2_M1(...) _DPP_DELEGATE_N1(__VA_ARGS__)

#define _DPP_DELEGATE_N3(sep, _1, _2, _3, _4, _5, _6, _7, _8)	\
	_1 _DPP_DELEGATE_##sep _2 _DPP_DELEGATE_##sep _3
#define _DPP_DELEGATE_N3_M1(...) _DPP_DELEGATE_N2(__VA_ARGS__)

#define _DPP_DELEGATE_N4(sep, _1, _2, _3, _4, _5, _6, _7, _8)	\
	_1 _DPP_DELEGATE_##sep _2 _DPP_DELEGATE_##sep			\
	_3 _DPP_DELEGATE_##sep _4
#define _DPP_DELEGATE_N4_M1(...) _DPP_DELEGATE_N3(__VA_ARGS__)

#define _DPP_DELEGATE_N5(sep, _1, _2, _3, _4, _5, _6, _7, _8)		\
	_1 _DPP_DELEGATE_##sep _2 _DPP_DELEGATE_##sep _3 _DPP_DELEGATE_##sep	\
	_4 _DPP_DELEGATE_##sep _5
#define _DPP_DELEGATE_N5_M1(...) _DPP_DELEGATE_N4(__VA_ARGS__)

#define _DPP_DELEGATE_N6(sep, _1, _2, _3, _4, _5, _6, _7, _8)		\
	_1 _DPP_DELEGATE_##sep _2 _DPP_DELEGATE_##sep _3 _DPP_DELEGATE_##sep	\
	_4 _DPP_DELEGATE_##sep _5 _DPP_DELEGATE_##sep _6
#define _DPP_DELEGATE_N6_M1(...) _DPP_DELEGATE_N5(__VA_ARGS__)

#define _DPP_DELEGATE_N7(sep, _1, _2, _3, _4, _5, _6, _7, _8)		\
	_1 _DPP_DELEGATE_##sep _2 _DPP_DELEGATE_##sep _3 _DPP_DELEGATE_##sep	\
	_4 _DPP_DELEGATE_##sep _5 _DPP_DELEGATE_##sep _6 _DPP_DELEGATE_##sep _7
#define _DPP_DELEGATE_N7_M1(...) _DPP_DELEGATE_N6(__VA_ARGS__)

#define _DPP_DELEGATE_N8(sep, _1, _2, _3, _4, _5, _6, _7, _8)		\
	_1 _DPP_DELEGATE_##sep _2 _DPP_DELEGATE_##sep _3 _DPP_DELEGATE_##sep	\
	_4 _DPP_DELEGATE_##sep _5 _DPP_DELEGATE_##sep _6 _DPP_DELEGATE_##sep	\
	_7 _DPP_DELEGATE_##sep _8
#define _DPP_DELEGATE_N8_M1(...) _DPP_DELEGATE_N7(__VA_ARGS__)

#define _DPP_DELEGATE_PARGS(n)					\
	_DPP_DELEGATE_N##n(CM, A0, A1, A2, A3, A4, A5, A6, A7)

#define _DPP_DELEGATE_PARGS_NOT0(n)				\
	_DPP_DELEGATE_N##n##_M1(CM, A1, A2, A3, A4, A5, A6, A7, )

#define _DPP_DELEGATE_IARGS(n)					\
	_DPP_DELEGATE_N##n(CM, a0, a1, a2, a3, a4, a5, a6, a7)

#define _DPP_DELEGATE_IARGS_NOT0(n)				\
	_DPP_DELEGATE_N##n##_M1(CM, a1, a2, a3, a4, a5, a6, a7, )

#define _DPP_DELEGATE_CARGS(n)				\
	_DPP_DELEGATE_N##n(CM, A0 a0, A1 a1, A2 a2, A3 a3,	\
	                   A4 a4, A5 a5, A6 a6, A7 a7)

#define _DPP_DELEGATE_TDEFS(n)					\
	_DPP_DELEGATE_N##n(SC, typedef A0 a0_t, typedef A1 a1_t,	\
	                   typedef A2 a2_t, typedef A3 a3_t,		\
	                   typedef A4 a4_t, typedef A5 a5_t,		\
	                   typedef A6 a6_t, typedef A7 a7_t) ;

#define _DPP_DELEGATE_TDEFS(n)					\
	_DPP_DELEGATE_N##n(SC, typedef A0 a0_t, typedef A1 a1_t,	\
	                   typedef A2 a2_t, typedef A3 a3_t,		\
	                   typedef A4 a4_t, typedef A5 a5_t,		\
	                   typedef A6 a6_t, typedef A7 a7_t) ;

#define _DPP_DELEGATE_TARGS(n)				    \
	_DPP_DELEGATE_N##n(SP,_DPP_DELEGATE_CM,,,,,,,)            \
	_DPP_DELEGATE_N##n(CM, typename A0, typename A1,	    \
	                   typename A2, typename A3,		    \
	                   typename A4, typename A5,		    \
	                   typename A6, typename A7)

#define _DPP_DELEGATE_BCARGS(n)				\
	_DPP_DELEGATE_N##n(SP,_DPP_DELEGATE_CM,,,,,,,)		\
	_DPP_DELEGATE_N##n(CM, B0 a0, B1 a1, B2 a2, B3 a3,	\
	                   B4 a4, B5 a5, B6 a6, B7 a7)

#define _DPP_DELEGATE_BCSTR(n)					\
	_DPP_DELEGATE_N##n(SP,_DPP_DELEGATE_CM,,,,,,,)		\
	_DPP_DELEGATE_N##n(CM, _a0(a0), _a1(a1), _a2(a2), _a3(a3),	\
	                   _a4(a4), _a5(a5), _a6(a6), _a7(a7))

#define _DPP_DELEGATE_BFIELD(n)					\
	_DPP_DELEGATE_N##n(SC, B0 _a0, B1 _a1, B2 _a2, B3 _a3,	\
	                   B4 _a4, B5 _a5, B6 _a6, B7 _a7)

#define _DPP_DELEGATE_BTDEFS_(n, _1a, _2a, _3a, _4a, \
                              _5a, _6a, _7a, _8a, ...) \
_DPP_DELEGATE_N##n(SC,					\
                   typedef typename base::a##_1a##_t B0,			\
                   typedef typename base::a##_2a##_t B1,			\
                   typedef typename base::a##_3a##_t B2,			\
                   typedef typename base::a##_4a##_t B3,			\
                   typedef typename base::a##_5a##_t B4,			\
                   typedef typename base::a##_6a##_t B5,			\
                   typedef typename base::a##_7a##_t B6,			\
                   typedef typename base::a##_8a##_t B7)
	/*
	#define _DPP_DELEGATE_BTDEFS(n, ...) _DPP_DELEGATE_BTDEFS_(n, __VA_ARGS__,,,,,,,,,)

	#if DPP_DELEGATE_ARGC >= 0
	_DPP_DELEGATE(0)
	_DPP_DELEGATE_FUNC(0)
	_DPP_DELEGATE_MEMBER(0)
	#endif

	#if DPP_DELEGATE_ARGC >= 1
	_DPP_DELEGATE(1)
	_DPP_DELEGATE_FUNC(1)
	_DPP_DELEGATE_MEMBER(1)
	_DPP_DELEGATE_MEMBER_THIS(1)
	_DPP_DELEGATE_BIND(1, 0, 1, _DPP_DELEGATE_BTDEFS(1, 0), _a0);
	#endif

	#if DPP_DELEGATE_ARGC >= 2
	_DPP_DELEGATE(2)
	_DPP_DELEGATE_FUNC(2)
	_DPP_DELEGATE_MEMBER(2)
	_DPP_DELEGATE_MEMBER_THIS(2)
	_DPP_DELEGATE_BIND(1, 1, 1, _DPP_DELEGATE_BTDEFS(1, 0), _a0, a0);
	_DPP_DELEGATE_BIND(2, 1, 1, _DPP_DELEGATE_BTDEFS(1, 1), a0, _a0);
	_DPP_DELEGATE_BIND(3, 0, 2, _DPP_DELEGATE_BTDEFS(2, 0, 1), _a0, _a1);
	#endif

	#if DPP_DELEGATE_ARGC >= 3
	_DPP_DELEGATE(3)
	_DPP_DELEGATE_FUNC(3)
	_DPP_DELEGATE_MEMBER(3)
	_DPP_DELEGATE_MEMBER_THIS(3)
	_DPP_DELEGATE_BIND(1, 2, 1, _DPP_DELEGATE_BTDEFS(1, 0), _a0, a0, a1);
	_DPP_DELEGATE_BIND(2, 2, 1, _DPP_DELEGATE_BTDEFS(1, 1), a0, _a0, a1);
	_DPP_DELEGATE_BIND(3, 1, 2, _DPP_DELEGATE_BTDEFS(2, 0, 1), _a0, _a1, a0);
	_DPP_DELEGATE_BIND(4, 2, 1, _DPP_DELEGATE_BTDEFS(1, 2), a0, a1, _a0);
	_DPP_DELEGATE_BIND(5, 1, 2, _DPP_DELEGATE_BTDEFS(2, 0, 2), _a0, a0, _a1);
	_DPP_DELEGATE_BIND(6, 1, 2, _DPP_DELEGATE_BTDEFS(2, 1, 2), a0, _a0, _a1);
	_DPP_DELEGATE_BIND(7, 0, 3, _DPP_DELEGATE_BTDEFS(3, 0, 1, 2), _a0, _a1, _a2);
	#endif

	#if DPP_DELEGATE_ARGC >= 4
	_DPP_DELEGATE(4)
	_DPP_DELEGATE_FUNC(4)
	_DPP_DELEGATE_MEMBER(4)
	_DPP_DELEGATE_MEMBER_THIS(4)
	_DPP_DELEGATE_BIND(1, 3, 1, _DPP_DELEGATE_BTDEFS(1, 0), _a0, a0, a1, a2);
	_DPP_DELEGATE_BIND(2, 3, 1, _DPP_DELEGATE_BTDEFS(1, 1), a0, _a0, a1, a2);
	_DPP_DELEGATE_BIND(3, 2, 2, _DPP_DELEGATE_BTDEFS(2, 0, 1), _a0, _a1, a0, a1);
	_DPP_DELEGATE_BIND(4, 3, 1, _DPP_DELEGATE_BTDEFS(1, 2), a0, a1, _a0, a2);
	_DPP_DELEGATE_BIND(5, 2, 2, _DPP_DELEGATE_BTDEFS(2, 0, 2), _a0, a0, _a1, a1);
	_DPP_DELEGATE_BIND(6, 2, 2, _DPP_DELEGATE_BTDEFS(2, 1, 2), a0, _a0, _a1, a1);
	_DPP_DELEGATE_BIND(7, 1, 3, _DPP_DELEGATE_BTDEFS(3, 0, 1, 2), _a0, _a1, _a2, a0);
	_DPP_DELEGATE_BIND(8, 3, 1, _DPP_DELEGATE_BTDEFS(1, 3), a0, a1, a2, _a0);
	_DPP_DELEGATE_BIND(9, 2, 2, _DPP_DELEGATE_BTDEFS(2, 0, 3), _a0, a0, a1, _a1);
	_DPP_DELEGATE_BIND(10, 2, 2, _DPP_DELEGATE_BTDEFS(2, 1, 3), a0, _a0, a1, _a1);
	_DPP_DELEGATE_BIND(11, 1, 3, _DPP_DELEGATE_BTDEFS(3, 0, 1, 3), _a0, _a1, a0, _a2);
	_DPP_DELEGATE_BIND(12, 2, 2, _DPP_DELEGATE_BTDEFS(2, 2, 3), a0, a1, _a0, _a1);
	_DPP_DELEGATE_BIND(13, 1, 3, _DPP_DELEGATE_BTDEFS(3, 0, 2, 3), _a0, a0, _a1, _a2);
	_DPP_DELEGATE_BIND(14, 1, 3, _DPP_DELEGATE_BTDEFS(3, 1, 2, 3), a0, _a0, _a1, _a2);
	_DPP_DELEGATE_BIND(15, 0, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 2, 3), _a0, _a1, _a2, _a3);
	#endif

	#if DPP_DELEGATE_ARGC >= 5 // mkdoc:skip
	_DPP_DELEGATE(5)
	_DPP_DELEGATE_FUNC(5)
	_DPP_DELEGATE_MEMBER(5)
	_DPP_DELEGATE_MEMBER_THIS(5)
	_DPP_DELEGATE_BIND(1, 4, 1, _DPP_DELEGATE_BTDEFS(1, 0), _a0, a0, a1, a2, a3);
	_DPP_DELEGATE_BIND(2, 4, 1, _DPP_DELEGATE_BTDEFS(1, 1), a0, _a0, a1, a2, a3);
	_DPP_DELEGATE_BIND(3, 3, 2, _DPP_DELEGATE_BTDEFS(2, 0, 1), _a0, _a1, a0, a1, a2);
	_DPP_DELEGATE_BIND(4, 4, 1, _DPP_DELEGATE_BTDEFS(1, 2), a0, a1, _a0, a2, a3);
	_DPP_DELEGATE_BIND(5, 3, 2, _DPP_DELEGATE_BTDEFS(2, 0, 2), _a0, a0, _a1, a1, a2);
	_DPP_DELEGATE_BIND(6, 3, 2, _DPP_DELEGATE_BTDEFS(2, 1, 2), a0, _a0, _a1, a1, a2);
	_DPP_DELEGATE_BIND(7, 2, 3, _DPP_DELEGATE_BTDEFS(3, 0, 1, 2), _a0, _a1, _a2, a0, a1);
	_DPP_DELEGATE_BIND(8, 4, 1, _DPP_DELEGATE_BTDEFS(1, 3), a0, a1, a2, _a0, a3);
	_DPP_DELEGATE_BIND(9, 3, 2, _DPP_DELEGATE_BTDEFS(2, 0, 3), _a0, a0, a1, _a1, a2);
	_DPP_DELEGATE_BIND(10, 3, 2, _DPP_DELEGATE_BTDEFS(2, 1, 3), a0, _a0, a1, _a1, a2);
	_DPP_DELEGATE_BIND(11, 2, 3, _DPP_DELEGATE_BTDEFS(3, 0, 1, 3), _a0, _a1, a0, _a2, a1);
	_DPP_DELEGATE_BIND(12, 3, 2, _DPP_DELEGATE_BTDEFS(2, 2, 3), a0, a1, _a0, _a1, a2);
	_DPP_DELEGATE_BIND(13, 2, 3, _DPP_DELEGATE_BTDEFS(3, 0, 2, 3), _a0, a0, _a1, _a2, a1);
	_DPP_DELEGATE_BIND(14, 2, 3, _DPP_DELEGATE_BTDEFS(3, 1, 2, 3), a0, _a0, _a1, _a2, a1);
	_DPP_DELEGATE_BIND(15, 1, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 2, 3), _a0, _a1, _a2, _a3, a0);
	_DPP_DELEGATE_BIND(16, 4, 1, _DPP_DELEGATE_BTDEFS(1, 4), a0, a1, a2, a3, _a0);
	_DPP_DELEGATE_BIND(17, 3, 2, _DPP_DELEGATE_BTDEFS(2, 0, 4), _a0, a0, a1, a2, _a1);
	_DPP_DELEGATE_BIND(18, 3, 2, _DPP_DELEGATE_BTDEFS(2, 1, 4), a0, _a0, a1, a2, _a1);
	_DPP_DELEGATE_BIND(19, 2, 3, _DPP_DELEGATE_BTDEFS(3, 0, 1, 4), _a0, _a1, a0, a1, _a2);
	_DPP_DELEGATE_BIND(20, 3, 2, _DPP_DELEGATE_BTDEFS(2, 2, 4), a0, a1, _a0, a2, _a1);
	_DPP_DELEGATE_BIND(21, 2, 3, _DPP_DELEGATE_BTDEFS(3, 0, 2, 4), _a0, a0, _a1, a1, _a2);
	_DPP_DELEGATE_BIND(22, 2, 3, _DPP_DELEGATE_BTDEFS(3, 1, 2, 4), a0, _a0, _a1, a1, _a2);
	_DPP_DELEGATE_BIND(23, 1, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 2, 4), _a0, _a1, _a2, a0, _a3);
	_DPP_DELEGATE_BIND(24, 3, 2, _DPP_DELEGATE_BTDEFS(2, 3, 4), a0, a1, a2, _a0, _a1);
	_DPP_DELEGATE_BIND(25, 2, 3, _DPP_DELEGATE_BTDEFS(3, 0, 3, 4), _a0, a0, a1, _a1, _a2);
	_DPP_DELEGATE_BIND(26, 2, 3, _DPP_DELEGATE_BTDEFS(3, 1, 3, 4), a0, _a0, a1, _a1, _a2);
	_DPP_DELEGATE_BIND(27, 1, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 3, 4), _a0, _a1, a0, _a2, _a3);
	_DPP_DELEGATE_BIND(28, 2, 3, _DPP_DELEGATE_BTDEFS(3, 2, 3, 4), a0, a1, _a0, _a1, _a2);
	_DPP_DELEGATE_BIND(29, 1, 4, _DPP_DELEGATE_BTDEFS(4, 0, 2, 3, 4), _a0, a0, _a1, _a2, _a3);
	_DPP_DELEGATE_BIND(30, 1, 4, _DPP_DELEGATE_BTDEFS(4, 1, 2, 3, 4), a0, _a0, _a1, _a2, _a3);
	_DPP_DELEGATE_BIND(31, 0, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 2, 3, 4), _a0, _a1, _a2, _a3, _a4);
	#endif

	#if DPP_DELEGATE_ARGC >= 6 // mkdoc:skip
	_DPP_DELEGATE(6)
	_DPP_DELEGATE_FUNC(6)
	_DPP_DELEGATE_MEMBER(6)
	_DPP_DELEGATE_MEMBER_THIS(6)
	_DPP_DELEGATE_BIND(1, 5, 1, _DPP_DELEGATE_BTDEFS(1, 0), _a0, a0, a1, a2, a3, a4);
	_DPP_DELEGATE_BIND(2, 5, 1, _DPP_DELEGATE_BTDEFS(1, 1), a0, _a0, a1, a2, a3, a4);
	_DPP_DELEGATE_BIND(3, 4, 2, _DPP_DELEGATE_BTDEFS(2, 0, 1), _a0, _a1, a0, a1, a2, a3);
	_DPP_DELEGATE_BIND(4, 5, 1, _DPP_DELEGATE_BTDEFS(1, 2), a0, a1, _a0, a2, a3, a4);
	_DPP_DELEGATE_BIND(5, 4, 2, _DPP_DELEGATE_BTDEFS(2, 0, 2), _a0, a0, _a1, a1, a2, a3);
	_DPP_DELEGATE_BIND(6, 4, 2, _DPP_DELEGATE_BTDEFS(2, 1, 2), a0, _a0, _a1, a1, a2, a3);
	_DPP_DELEGATE_BIND(7, 3, 3, _DPP_DELEGATE_BTDEFS(3, 0, 1, 2), _a0, _a1, _a2, a0, a1, a2);
	_DPP_DELEGATE_BIND(8, 5, 1, _DPP_DELEGATE_BTDEFS(1, 3), a0, a1, a2, _a0, a3, a4);
	_DPP_DELEGATE_BIND(9, 4, 2, _DPP_DELEGATE_BTDEFS(2, 0, 3), _a0, a0, a1, _a1, a2, a3);
	_DPP_DELEGATE_BIND(10, 4, 2, _DPP_DELEGATE_BTDEFS(2, 1, 3), a0, _a0, a1, _a1, a2, a3);
	_DPP_DELEGATE_BIND(11, 3, 3, _DPP_DELEGATE_BTDEFS(3, 0, 1, 3), _a0, _a1, a0, _a2, a1, a2);
	_DPP_DELEGATE_BIND(12, 4, 2, _DPP_DELEGATE_BTDEFS(2, 2, 3), a0, a1, _a0, _a1, a2, a3);
	_DPP_DELEGATE_BIND(13, 3, 3, _DPP_DELEGATE_BTDEFS(3, 0, 2, 3), _a0, a0, _a1, _a2, a1, a2);
	_DPP_DELEGATE_BIND(14, 3, 3, _DPP_DELEGATE_BTDEFS(3, 1, 2, 3), a0, _a0, _a1, _a2, a1, a2);
	_DPP_DELEGATE_BIND(15, 2, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 2, 3), _a0, _a1, _a2, _a3, a0, a1);
	_DPP_DELEGATE_BIND(16, 5, 1, _DPP_DELEGATE_BTDEFS(1, 4), a0, a1, a2, a3, _a0, a4);
	_DPP_DELEGATE_BIND(17, 4, 2, _DPP_DELEGATE_BTDEFS(2, 0, 4), _a0, a0, a1, a2, _a1, a3);
	_DPP_DELEGATE_BIND(18, 4, 2, _DPP_DELEGATE_BTDEFS(2, 1, 4), a0, _a0, a1, a2, _a1, a3);
	_DPP_DELEGATE_BIND(19, 3, 3, _DPP_DELEGATE_BTDEFS(3, 0, 1, 4), _a0, _a1, a0, a1, _a2, a2);
	_DPP_DELEGATE_BIND(20, 4, 2, _DPP_DELEGATE_BTDEFS(2, 2, 4), a0, a1, _a0, a2, _a1, a3);
	_DPP_DELEGATE_BIND(21, 3, 3, _DPP_DELEGATE_BTDEFS(3, 0, 2, 4), _a0, a0, _a1, a1, _a2, a2);
	_DPP_DELEGATE_BIND(22, 3, 3, _DPP_DELEGATE_BTDEFS(3, 1, 2, 4), a0, _a0, _a1, a1, _a2, a2);
	_DPP_DELEGATE_BIND(23, 2, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 2, 4), _a0, _a1, _a2, a0, _a3, a1);
	_DPP_DELEGATE_BIND(24, 4, 2, _DPP_DELEGATE_BTDEFS(2, 3, 4), a0, a1, a2, _a0, _a1, a3);
	_DPP_DELEGATE_BIND(25, 3, 3, _DPP_DELEGATE_BTDEFS(3, 0, 3, 4), _a0, a0, a1, _a1, _a2, a2);
	_DPP_DELEGATE_BIND(26, 3, 3, _DPP_DELEGATE_BTDEFS(3, 1, 3, 4), a0, _a0, a1, _a1, _a2, a2);
	_DPP_DELEGATE_BIND(27, 2, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 3, 4), _a0, _a1, a0, _a2, _a3, a1);
	_DPP_DELEGATE_BIND(28, 3, 3, _DPP_DELEGATE_BTDEFS(3, 2, 3, 4), a0, a1, _a0, _a1, _a2, a2);
	_DPP_DELEGATE_BIND(29, 2, 4, _DPP_DELEGATE_BTDEFS(4, 0, 2, 3, 4), _a0, a0, _a1, _a2, _a3, a1);
	_DPP_DELEGATE_BIND(30, 2, 4, _DPP_DELEGATE_BTDEFS(4, 1, 2, 3, 4), a0, _a0, _a1, _a2, _a3, a1);
	_DPP_DELEGATE_BIND(31, 1, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 2, 3, 4), _a0, _a1, _a2, _a3, _a4, a0);
	_DPP_DELEGATE_BIND(32, 5, 1, _DPP_DELEGATE_BTDEFS(1, 5), a0, a1, a2, a3, a4, _a0);
	_DPP_DELEGATE_BIND(33, 4, 2, _DPP_DELEGATE_BTDEFS(2, 0, 5), _a0, a0, a1, a2, a3, _a1);
	_DPP_DELEGATE_BIND(34, 4, 2, _DPP_DELEGATE_BTDEFS(2, 1, 5), a0, _a0, a1, a2, a3, _a1);
	_DPP_DELEGATE_BIND(35, 3, 3, _DPP_DELEGATE_BTDEFS(3, 0, 1, 5), _a0, _a1, a0, a1, a2, _a2);
	_DPP_DELEGATE_BIND(36, 4, 2, _DPP_DELEGATE_BTDEFS(2, 2, 5), a0, a1, _a0, a2, a3, _a1);
	_DPP_DELEGATE_BIND(37, 3, 3, _DPP_DELEGATE_BTDEFS(3, 0, 2, 5), _a0, a0, _a1, a1, a2, _a2);
	_DPP_DELEGATE_BIND(38, 3, 3, _DPP_DELEGATE_BTDEFS(3, 1, 2, 5), a0, _a0, _a1, a1, a2, _a2);
	_DPP_DELEGATE_BIND(39, 2, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 2, 5), _a0, _a1, _a2, a0, a1, _a3);
	_DPP_DELEGATE_BIND(40, 4, 2, _DPP_DELEGATE_BTDEFS(2, 3, 5), a0, a1, a2, _a0, a3, _a1);
	_DPP_DELEGATE_BIND(41, 3, 3, _DPP_DELEGATE_BTDEFS(3, 0, 3, 5), _a0, a0, a1, _a1, a2, _a2);
	_DPP_DELEGATE_BIND(42, 3, 3, _DPP_DELEGATE_BTDEFS(3, 1, 3, 5), a0, _a0, a1, _a1, a2, _a2);
	_DPP_DELEGATE_BIND(43, 2, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 3, 5), _a0, _a1, a0, _a2, a1, _a3);
	_DPP_DELEGATE_BIND(44, 3, 3, _DPP_DELEGATE_BTDEFS(3, 2, 3, 5), a0, a1, _a0, _a1, a2, _a2);
	_DPP_DELEGATE_BIND(45, 2, 4, _DPP_DELEGATE_BTDEFS(4, 0, 2, 3, 5), _a0, a0, _a1, _a2, a1, _a3);
	_DPP_DELEGATE_BIND(46, 2, 4, _DPP_DELEGATE_BTDEFS(4, 1, 2, 3, 5), a0, _a0, _a1, _a2, a1, _a3);
	_DPP_DELEGATE_BIND(47, 1, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 2, 3, 5), _a0, _a1, _a2, _a3, a0, _a4);
	_DPP_DELEGATE_BIND(48, 4, 2, _DPP_DELEGATE_BTDEFS(2, 4, 5), a0, a1, a2, a3, _a0, _a1);
	_DPP_DELEGATE_BIND(49, 3, 3, _DPP_DELEGATE_BTDEFS(3, 0, 4, 5), _a0, a0, a1, a2, _a1, _a2);
	_DPP_DELEGATE_BIND(50, 3, 3, _DPP_DELEGATE_BTDEFS(3, 1, 4, 5), a0, _a0, a1, a2, _a1, _a2);
	_DPP_DELEGATE_BIND(51, 2, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 4, 5), _a0, _a1, a0, a1, _a2, _a3);
	_DPP_DELEGATE_BIND(52, 3, 3, _DPP_DELEGATE_BTDEFS(3, 2, 4, 5), a0, a1, _a0, a2, _a1, _a2);
	_DPP_DELEGATE_BIND(53, 2, 4, _DPP_DELEGATE_BTDEFS(4, 0, 2, 4, 5), _a0, a0, _a1, a1, _a2, _a3);
	_DPP_DELEGATE_BIND(54, 2, 4, _DPP_DELEGATE_BTDEFS(4, 1, 2, 4, 5), a0, _a0, _a1, a1, _a2, _a3);
	_DPP_DELEGATE_BIND(55, 1, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 2, 4, 5), _a0, _a1, _a2, a0, _a3, _a4);
	_DPP_DELEGATE_BIND(56, 3, 3, _DPP_DELEGATE_BTDEFS(3, 3, 4, 5), a0, a1, a2, _a0, _a1, _a2);
	_DPP_DELEGATE_BIND(57, 2, 4, _DPP_DELEGATE_BTDEFS(4, 0, 3, 4, 5), _a0, a0, a1, _a1, _a2, _a3);
	_DPP_DELEGATE_BIND(58, 2, 4, _DPP_DELEGATE_BTDEFS(4, 1, 3, 4, 5), a0, _a0, a1, _a1, _a2, _a3);
	_DPP_DELEGATE_BIND(59, 1, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 3, 4, 5), _a0, _a1, a0, _a2, _a3, _a4);
	_DPP_DELEGATE_BIND(60, 2, 4, _DPP_DELEGATE_BTDEFS(4, 2, 3, 4, 5), a0, a1, _a0, _a1, _a2, _a3);
	_DPP_DELEGATE_BIND(61, 1, 5, _DPP_DELEGATE_BTDEFS(5, 0, 2, 3, 4, 5), _a0, a0, _a1, _a2, _a3, _a4);
	_DPP_DELEGATE_BIND(62, 1, 5, _DPP_DELEGATE_BTDEFS(5, 1, 2, 3, 4, 5), a0, _a0, _a1, _a2, _a3, _a4);
	_DPP_DELEGATE_BIND(63, 0, 6, _DPP_DELEGATE_BTDEFS(6, 0, 1, 2, 3, 4, 5), _a0, _a1, _a2, _a3, _a4, _a5);
	#endif

	#if DPP_DELEGATE_ARGC >= 7 // mkdoc:skip
	_DPP_DELEGATE(7)
	_DPP_DELEGATE_FUNC(7)
	_DPP_DELEGATE_MEMBER(7)
	_DPP_DELEGATE_MEMBER_THIS(7)
	_DPP_DELEGATE_BIND(1, 6, 1, _DPP_DELEGATE_BTDEFS(1, 0), _a0, a0, a1, a2, a3, a4, a5);
	_DPP_DELEGATE_BIND(2, 6, 1, _DPP_DELEGATE_BTDEFS(1, 1), a0, _a0, a1, a2, a3, a4, a5);
	_DPP_DELEGATE_BIND(3, 5, 2, _DPP_DELEGATE_BTDEFS(2, 0, 1), _a0, _a1, a0, a1, a2, a3, a4);
	_DPP_DELEGATE_BIND(4, 6, 1, _DPP_DELEGATE_BTDEFS(1, 2), a0, a1, _a0, a2, a3, a4, a5);
	_DPP_DELEGATE_BIND(5, 5, 2, _DPP_DELEGATE_BTDEFS(2, 0, 2), _a0, a0, _a1, a1, a2, a3, a4);
	_DPP_DELEGATE_BIND(6, 5, 2, _DPP_DELEGATE_BTDEFS(2, 1, 2), a0, _a0, _a1, a1, a2, a3, a4);
	_DPP_DELEGATE_BIND(7, 4, 3, _DPP_DELEGATE_BTDEFS(3, 0, 1, 2), _a0, _a1, _a2, a0, a1, a2, a3);
	_DPP_DELEGATE_BIND(8, 6, 1, _DPP_DELEGATE_BTDEFS(1, 3), a0, a1, a2, _a0, a3, a4, a5);
	_DPP_DELEGATE_BIND(9, 5, 2, _DPP_DELEGATE_BTDEFS(2, 0, 3), _a0, a0, a1, _a1, a2, a3, a4);
	_DPP_DELEGATE_BIND(10, 5, 2, _DPP_DELEGATE_BTDEFS(2, 1, 3), a0, _a0, a1, _a1, a2, a3, a4);
	_DPP_DELEGATE_BIND(11, 4, 3, _DPP_DELEGATE_BTDEFS(3, 0, 1, 3), _a0, _a1, a0, _a2, a1, a2, a3);
	_DPP_DELEGATE_BIND(12, 5, 2, _DPP_DELEGATE_BTDEFS(2, 2, 3), a0, a1, _a0, _a1, a2, a3, a4);
	_DPP_DELEGATE_BIND(13, 4, 3, _DPP_DELEGATE_BTDEFS(3, 0, 2, 3), _a0, a0, _a1, _a2, a1, a2, a3);
	_DPP_DELEGATE_BIND(14, 4, 3, _DPP_DELEGATE_BTDEFS(3, 1, 2, 3), a0, _a0, _a1, _a2, a1, a2, a3);
	_DPP_DELEGATE_BIND(15, 3, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 2, 3), _a0, _a1, _a2, _a3, a0, a1, a2);
	_DPP_DELEGATE_BIND(16, 6, 1, _DPP_DELEGATE_BTDEFS(1, 4), a0, a1, a2, a3, _a0, a4, a5);
	_DPP_DELEGATE_BIND(17, 5, 2, _DPP_DELEGATE_BTDEFS(2, 0, 4), _a0, a0, a1, a2, _a1, a3, a4);
	_DPP_DELEGATE_BIND(18, 5, 2, _DPP_DELEGATE_BTDEFS(2, 1, 4), a0, _a0, a1, a2, _a1, a3, a4);
	_DPP_DELEGATE_BIND(19, 4, 3, _DPP_DELEGATE_BTDEFS(3, 0, 1, 4), _a0, _a1, a0, a1, _a2, a2, a3);
	_DPP_DELEGATE_BIND(20, 5, 2, _DPP_DELEGATE_BTDEFS(2, 2, 4), a0, a1, _a0, a2, _a1, a3, a4);
	_DPP_DELEGATE_BIND(21, 4, 3, _DPP_DELEGATE_BTDEFS(3, 0, 2, 4), _a0, a0, _a1, a1, _a2, a2, a3);
	_DPP_DELEGATE_BIND(22, 4, 3, _DPP_DELEGATE_BTDEFS(3, 1, 2, 4), a0, _a0, _a1, a1, _a2, a2, a3);
	_DPP_DELEGATE_BIND(23, 3, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 2, 4), _a0, _a1, _a2, a0, _a3, a1, a2);
	_DPP_DELEGATE_BIND(24, 5, 2, _DPP_DELEGATE_BTDEFS(2, 3, 4), a0, a1, a2, _a0, _a1, a3, a4);
	_DPP_DELEGATE_BIND(25, 4, 3, _DPP_DELEGATE_BTDEFS(3, 0, 3, 4), _a0, a0, a1, _a1, _a2, a2, a3);
	_DPP_DELEGATE_BIND(26, 4, 3, _DPP_DELEGATE_BTDEFS(3, 1, 3, 4), a0, _a0, a1, _a1, _a2, a2, a3);
	_DPP_DELEGATE_BIND(27, 3, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 3, 4), _a0, _a1, a0, _a2, _a3, a1, a2);
	_DPP_DELEGATE_BIND(28, 4, 3, _DPP_DELEGATE_BTDEFS(3, 2, 3, 4), a0, a1, _a0, _a1, _a2, a2, a3);
	_DPP_DELEGATE_BIND(29, 3, 4, _DPP_DELEGATE_BTDEFS(4, 0, 2, 3, 4), _a0, a0, _a1, _a2, _a3, a1, a2);
	_DPP_DELEGATE_BIND(30, 3, 4, _DPP_DELEGATE_BTDEFS(4, 1, 2, 3, 4), a0, _a0, _a1, _a2, _a3, a1, a2);
	_DPP_DELEGATE_BIND(31, 2, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 2, 3, 4), _a0, _a1, _a2, _a3, _a4, a0, a1);
	_DPP_DELEGATE_BIND(32, 6, 1, _DPP_DELEGATE_BTDEFS(1, 5), a0, a1, a2, a3, a4, _a0, a5);
	_DPP_DELEGATE_BIND(33, 5, 2, _DPP_DELEGATE_BTDEFS(2, 0, 5), _a0, a0, a1, a2, a3, _a1, a4);
	_DPP_DELEGATE_BIND(34, 5, 2, _DPP_DELEGATE_BTDEFS(2, 1, 5), a0, _a0, a1, a2, a3, _a1, a4);
	_DPP_DELEGATE_BIND(35, 4, 3, _DPP_DELEGATE_BTDEFS(3, 0, 1, 5), _a0, _a1, a0, a1, a2, _a2, a3);
	_DPP_DELEGATE_BIND(36, 5, 2, _DPP_DELEGATE_BTDEFS(2, 2, 5), a0, a1, _a0, a2, a3, _a1, a4);
	_DPP_DELEGATE_BIND(37, 4, 3, _DPP_DELEGATE_BTDEFS(3, 0, 2, 5), _a0, a0, _a1, a1, a2, _a2, a3);
	_DPP_DELEGATE_BIND(38, 4, 3, _DPP_DELEGATE_BTDEFS(3, 1, 2, 5), a0, _a0, _a1, a1, a2, _a2, a3);
	_DPP_DELEGATE_BIND(39, 3, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 2, 5), _a0, _a1, _a2, a0, a1, _a3, a2);
	_DPP_DELEGATE_BIND(40, 5, 2, _DPP_DELEGATE_BTDEFS(2, 3, 5), a0, a1, a2, _a0, a3, _a1, a4);
	_DPP_DELEGATE_BIND(41, 4, 3, _DPP_DELEGATE_BTDEFS(3, 0, 3, 5), _a0, a0, a1, _a1, a2, _a2, a3);
	_DPP_DELEGATE_BIND(42, 4, 3, _DPP_DELEGATE_BTDEFS(3, 1, 3, 5), a0, _a0, a1, _a1, a2, _a2, a3);
	_DPP_DELEGATE_BIND(43, 3, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 3, 5), _a0, _a1, a0, _a2, a1, _a3, a2);
	_DPP_DELEGATE_BIND(44, 4, 3, _DPP_DELEGATE_BTDEFS(3, 2, 3, 5), a0, a1, _a0, _a1, a2, _a2, a3);
	_DPP_DELEGATE_BIND(45, 3, 4, _DPP_DELEGATE_BTDEFS(4, 0, 2, 3, 5), _a0, a0, _a1, _a2, a1, _a3, a2);
	_DPP_DELEGATE_BIND(46, 3, 4, _DPP_DELEGATE_BTDEFS(4, 1, 2, 3, 5), a0, _a0, _a1, _a2, a1, _a3, a2);
	_DPP_DELEGATE_BIND(47, 2, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 2, 3, 5), _a0, _a1, _a2, _a3, a0, _a4, a1);
	_DPP_DELEGATE_BIND(48, 5, 2, _DPP_DELEGATE_BTDEFS(2, 4, 5), a0, a1, a2, a3, _a0, _a1, a4);
	_DPP_DELEGATE_BIND(49, 4, 3, _DPP_DELEGATE_BTDEFS(3, 0, 4, 5), _a0, a0, a1, a2, _a1, _a2, a3);
	_DPP_DELEGATE_BIND(50, 4, 3, _DPP_DELEGATE_BTDEFS(3, 1, 4, 5), a0, _a0, a1, a2, _a1, _a2, a3);
	_DPP_DELEGATE_BIND(51, 3, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 4, 5), _a0, _a1, a0, a1, _a2, _a3, a2);
	_DPP_DELEGATE_BIND(52, 4, 3, _DPP_DELEGATE_BTDEFS(3, 2, 4, 5), a0, a1, _a0, a2, _a1, _a2, a3);
	_DPP_DELEGATE_BIND(53, 3, 4, _DPP_DELEGATE_BTDEFS(4, 0, 2, 4, 5), _a0, a0, _a1, a1, _a2, _a3, a2);
	_DPP_DELEGATE_BIND(54, 3, 4, _DPP_DELEGATE_BTDEFS(4, 1, 2, 4, 5), a0, _a0, _a1, a1, _a2, _a3, a2);
	_DPP_DELEGATE_BIND(55, 2, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 2, 4, 5), _a0, _a1, _a2, a0, _a3, _a4, a1);
	_DPP_DELEGATE_BIND(56, 4, 3, _DPP_DELEGATE_BTDEFS(3, 3, 4, 5), a0, a1, a2, _a0, _a1, _a2, a3);
	_DPP_DELEGATE_BIND(57, 3, 4, _DPP_DELEGATE_BTDEFS(4, 0, 3, 4, 5), _a0, a0, a1, _a1, _a2, _a3, a2);
	_DPP_DELEGATE_BIND(58, 3, 4, _DPP_DELEGATE_BTDEFS(4, 1, 3, 4, 5), a0, _a0, a1, _a1, _a2, _a3, a2);
	_DPP_DELEGATE_BIND(59, 2, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 3, 4, 5), _a0, _a1, a0, _a2, _a3, _a4, a1);
	_DPP_DELEGATE_BIND(60, 3, 4, _DPP_DELEGATE_BTDEFS(4, 2, 3, 4, 5), a0, a1, _a0, _a1, _a2, _a3, a2);
	_DPP_DELEGATE_BIND(61, 2, 5, _DPP_DELEGATE_BTDEFS(5, 0, 2, 3, 4, 5), _a0, a0, _a1, _a2, _a3, _a4, a1);
	_DPP_DELEGATE_BIND(62, 2, 5, _DPP_DELEGATE_BTDEFS(5, 1, 2, 3, 4, 5), a0, _a0, _a1, _a2, _a3, _a4, a1);
	_DPP_DELEGATE_BIND(63, 1, 6, _DPP_DELEGATE_BTDEFS(6, 0, 1, 2, 3, 4, 5), _a0, _a1, _a2, _a3, _a4, _a5, a0);
	_DPP_DELEGATE_BIND(64, 6, 1, _DPP_DELEGATE_BTDEFS(1, 6), a0, a1, a2, a3, a4, a5, _a0);
	_DPP_DELEGATE_BIND(65, 5, 2, _DPP_DELEGATE_BTDEFS(2, 0, 6), _a0, a0, a1, a2, a3, a4, _a1);
	_DPP_DELEGATE_BIND(66, 5, 2, _DPP_DELEGATE_BTDEFS(2, 1, 6), a0, _a0, a1, a2, a3, a4, _a1);
	_DPP_DELEGATE_BIND(67, 4, 3, _DPP_DELEGATE_BTDEFS(3, 0, 1, 6), _a0, _a1, a0, a1, a2, a3, _a2);
	_DPP_DELEGATE_BIND(68, 5, 2, _DPP_DELEGATE_BTDEFS(2, 2, 6), a0, a1, _a0, a2, a3, a4, _a1);
	_DPP_DELEGATE_BIND(69, 4, 3, _DPP_DELEGATE_BTDEFS(3, 0, 2, 6), _a0, a0, _a1, a1, a2, a3, _a2);
	_DPP_DELEGATE_BIND(70, 4, 3, _DPP_DELEGATE_BTDEFS(3, 1, 2, 6), a0, _a0, _a1, a1, a2, a3, _a2);
	_DPP_DELEGATE_BIND(71, 3, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 2, 6), _a0, _a1, _a2, a0, a1, a2, _a3);
	_DPP_DELEGATE_BIND(72, 5, 2, _DPP_DELEGATE_BTDEFS(2, 3, 6), a0, a1, a2, _a0, a3, a4, _a1);
	_DPP_DELEGATE_BIND(73, 4, 3, _DPP_DELEGATE_BTDEFS(3, 0, 3, 6), _a0, a0, a1, _a1, a2, a3, _a2);
	_DPP_DELEGATE_BIND(74, 4, 3, _DPP_DELEGATE_BTDEFS(3, 1, 3, 6), a0, _a0, a1, _a1, a2, a3, _a2);
	_DPP_DELEGATE_BIND(75, 3, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 3, 6), _a0, _a1, a0, _a2, a1, a2, _a3);
	_DPP_DELEGATE_BIND(76, 4, 3, _DPP_DELEGATE_BTDEFS(3, 2, 3, 6), a0, a1, _a0, _a1, a2, a3, _a2);
	_DPP_DELEGATE_BIND(77, 3, 4, _DPP_DELEGATE_BTDEFS(4, 0, 2, 3, 6), _a0, a0, _a1, _a2, a1, a2, _a3);
	_DPP_DELEGATE_BIND(78, 3, 4, _DPP_DELEGATE_BTDEFS(4, 1, 2, 3, 6), a0, _a0, _a1, _a2, a1, a2, _a3);
	_DPP_DELEGATE_BIND(79, 2, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 2, 3, 6), _a0, _a1, _a2, _a3, a0, a1, _a4);
	_DPP_DELEGATE_BIND(80, 5, 2, _DPP_DELEGATE_BTDEFS(2, 4, 6), a0, a1, a2, a3, _a0, a4, _a1);
	_DPP_DELEGATE_BIND(81, 4, 3, _DPP_DELEGATE_BTDEFS(3, 0, 4, 6), _a0, a0, a1, a2, _a1, a3, _a2);
	_DPP_DELEGATE_BIND(82, 4, 3, _DPP_DELEGATE_BTDEFS(3, 1, 4, 6), a0, _a0, a1, a2, _a1, a3, _a2);
	_DPP_DELEGATE_BIND(83, 3, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 4, 6), _a0, _a1, a0, a1, _a2, a2, _a3);
	_DPP_DELEGATE_BIND(84, 4, 3, _DPP_DELEGATE_BTDEFS(3, 2, 4, 6), a0, a1, _a0, a2, _a1, a3, _a2);
	_DPP_DELEGATE_BIND(85, 3, 4, _DPP_DELEGATE_BTDEFS(4, 0, 2, 4, 6), _a0, a0, _a1, a1, _a2, a2, _a3);
	_DPP_DELEGATE_BIND(86, 3, 4, _DPP_DELEGATE_BTDEFS(4, 1, 2, 4, 6), a0, _a0, _a1, a1, _a2, a2, _a3);
	_DPP_DELEGATE_BIND(87, 2, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 2, 4, 6), _a0, _a1, _a2, a0, _a3, a1, _a4);
	_DPP_DELEGATE_BIND(88, 4, 3, _DPP_DELEGATE_BTDEFS(3, 3, 4, 6), a0, a1, a2, _a0, _a1, a3, _a2);
	_DPP_DELEGATE_BIND(89, 3, 4, _DPP_DELEGATE_BTDEFS(4, 0, 3, 4, 6), _a0, a0, a1, _a1, _a2, a2, _a3);
	_DPP_DELEGATE_BIND(90, 3, 4, _DPP_DELEGATE_BTDEFS(4, 1, 3, 4, 6), a0, _a0, a1, _a1, _a2, a2, _a3);
	_DPP_DELEGATE_BIND(91, 2, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 3, 4, 6), _a0, _a1, a0, _a2, _a3, a1, _a4);
	_DPP_DELEGATE_BIND(92, 3, 4, _DPP_DELEGATE_BTDEFS(4, 2, 3, 4, 6), a0, a1, _a0, _a1, _a2, a2, _a3);
	_DPP_DELEGATE_BIND(93, 2, 5, _DPP_DELEGATE_BTDEFS(5, 0, 2, 3, 4, 6), _a0, a0, _a1, _a2, _a3, a1, _a4);
	_DPP_DELEGATE_BIND(94, 2, 5, _DPP_DELEGATE_BTDEFS(5, 1, 2, 3, 4, 6), a0, _a0, _a1, _a2, _a3, a1, _a4);
	_DPP_DELEGATE_BIND(95, 1, 6, _DPP_DELEGATE_BTDEFS(6, 0, 1, 2, 3, 4, 6), _a0, _a1, _a2, _a3, _a4, a0, _a5);
	_DPP_DELEGATE_BIND(96, 5, 2, _DPP_DELEGATE_BTDEFS(2, 5, 6), a0, a1, a2, a3, a4, _a0, _a1);
	_DPP_DELEGATE_BIND(97, 4, 3, _DPP_DELEGATE_BTDEFS(3, 0, 5, 6), _a0, a0, a1, a2, a3, _a1, _a2);
	_DPP_DELEGATE_BIND(98, 4, 3, _DPP_DELEGATE_BTDEFS(3, 1, 5, 6), a0, _a0, a1, a2, a3, _a1, _a2);
	_DPP_DELEGATE_BIND(99, 3, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 5, 6), _a0, _a1, a0, a1, a2, _a2, _a3);
	_DPP_DELEGATE_BIND(100, 4, 3, _DPP_DELEGATE_BTDEFS(3, 2, 5, 6), a0, a1, _a0, a2, a3, _a1, _a2);
	_DPP_DELEGATE_BIND(101, 3, 4, _DPP_DELEGATE_BTDEFS(4, 0, 2, 5, 6), _a0, a0, _a1, a1, a2, _a2, _a3);
	_DPP_DELEGATE_BIND(102, 3, 4, _DPP_DELEGATE_BTDEFS(4, 1, 2, 5, 6), a0, _a0, _a1, a1, a2, _a2, _a3);
	_DPP_DELEGATE_BIND(103, 2, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 2, 5, 6), _a0, _a1, _a2, a0, a1, _a3, _a4);
	_DPP_DELEGATE_BIND(104, 4, 3, _DPP_DELEGATE_BTDEFS(3, 3, 5, 6), a0, a1, a2, _a0, a3, _a1, _a2);
	_DPP_DELEGATE_BIND(105, 3, 4, _DPP_DELEGATE_BTDEFS(4, 0, 3, 5, 6), _a0, a0, a1, _a1, a2, _a2, _a3);
	_DPP_DELEGATE_BIND(106, 3, 4, _DPP_DELEGATE_BTDEFS(4, 1, 3, 5, 6), a0, _a0, a1, _a1, a2, _a2, _a3);
	_DPP_DELEGATE_BIND(107, 2, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 3, 5, 6), _a0, _a1, a0, _a2, a1, _a3, _a4);
	_DPP_DELEGATE_BIND(108, 3, 4, _DPP_DELEGATE_BTDEFS(4, 2, 3, 5, 6), a0, a1, _a0, _a1, a2, _a2, _a3);
	_DPP_DELEGATE_BIND(109, 2, 5, _DPP_DELEGATE_BTDEFS(5, 0, 2, 3, 5, 6), _a0, a0, _a1, _a2, a1, _a3, _a4);
	_DPP_DELEGATE_BIND(110, 2, 5, _DPP_DELEGATE_BTDEFS(5, 1, 2, 3, 5, 6), a0, _a0, _a1, _a2, a1, _a3, _a4);
	_DPP_DELEGATE_BIND(111, 1, 6, _DPP_DELEGATE_BTDEFS(6, 0, 1, 2, 3, 5, 6), _a0, _a1, _a2, _a3, a0, _a4, _a5);
	_DPP_DELEGATE_BIND(112, 4, 3, _DPP_DELEGATE_BTDEFS(3, 4, 5, 6), a0, a1, a2, a3, _a0, _a1, _a2);
	_DPP_DELEGATE_BIND(113, 3, 4, _DPP_DELEGATE_BTDEFS(4, 0, 4, 5, 6), _a0, a0, a1, a2, _a1, _a2, _a3);
	_DPP_DELEGATE_BIND(114, 3, 4, _DPP_DELEGATE_BTDEFS(4, 1, 4, 5, 6), a0, _a0, a1, a2, _a1, _a2, _a3);
	_DPP_DELEGATE_BIND(115, 2, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 4, 5, 6), _a0, _a1, a0, a1, _a2, _a3, _a4);
	_DPP_DELEGATE_BIND(116, 3, 4, _DPP_DELEGATE_BTDEFS(4, 2, 4, 5, 6), a0, a1, _a0, a2, _a1, _a2, _a3);
	_DPP_DELEGATE_BIND(117, 2, 5, _DPP_DELEGATE_BTDEFS(5, 0, 2, 4, 5, 6), _a0, a0, _a1, a1, _a2, _a3, _a4);
	_DPP_DELEGATE_BIND(118, 2, 5, _DPP_DELEGATE_BTDEFS(5, 1, 2, 4, 5, 6), a0, _a0, _a1, a1, _a2, _a3, _a4);
	_DPP_DELEGATE_BIND(119, 1, 6, _DPP_DELEGATE_BTDEFS(6, 0, 1, 2, 4, 5, 6), _a0, _a1, _a2, a0, _a3, _a4, _a5);
	_DPP_DELEGATE_BIND(120, 3, 4, _DPP_DELEGATE_BTDEFS(4, 3, 4, 5, 6), a0, a1, a2, _a0, _a1, _a2, _a3);
	_DPP_DELEGATE_BIND(121, 2, 5, _DPP_DELEGATE_BTDEFS(5, 0, 3, 4, 5, 6), _a0, a0, a1, _a1, _a2, _a3, _a4);
	_DPP_DELEGATE_BIND(122, 2, 5, _DPP_DELEGATE_BTDEFS(5, 1, 3, 4, 5, 6), a0, _a0, a1, _a1, _a2, _a3, _a4);
	_DPP_DELEGATE_BIND(123, 1, 6, _DPP_DELEGATE_BTDEFS(6, 0, 1, 3, 4, 5, 6), _a0, _a1, a0, _a2, _a3, _a4, _a5);
	_DPP_DELEGATE_BIND(124, 2, 5, _DPP_DELEGATE_BTDEFS(5, 2, 3, 4, 5, 6), a0, a1, _a0, _a1, _a2, _a3, _a4);
	_DPP_DELEGATE_BIND(125, 1, 6, _DPP_DELEGATE_BTDEFS(6, 0, 2, 3, 4, 5, 6), _a0, a0, _a1, _a2, _a3, _a4, _a5);
	_DPP_DELEGATE_BIND(126, 1, 6, _DPP_DELEGATE_BTDEFS(6, 1, 2, 3, 4, 5, 6), a0, _a0, _a1, _a2, _a3, _a4, _a5);
	_DPP_DELEGATE_BIND(127, 0, 7, _DPP_DELEGATE_BTDEFS(7, 0, 1, 2, 3, 4, 5, 6), _a0, _a1, _a2, _a3, _a4, _a5, _a6);
	#endif
	*/
#if DPP_DELEGATE_ARGC >= 8 // mkdoc:skip
	_DPP_DELEGATE(8)
	_DPP_DELEGATE_FUNC(8)
	_DPP_DELEGATE_MEMBER(8)
	_DPP_DELEGATE_MEMBER_THIS(8)
	_DPP_DELEGATE_BIND(1, 7, 1, _DPP_DELEGATE_BTDEFS(1, 0), _a0, a0, a1, a2, a3, a4, a5, a6);
	_DPP_DELEGATE_BIND(2, 7, 1, _DPP_DELEGATE_BTDEFS(1, 1), a0, _a0, a1, a2, a3, a4, a5, a6);
	_DPP_DELEGATE_BIND(3, 6, 2, _DPP_DELEGATE_BTDEFS(2, 0, 1), _a0, _a1, a0, a1, a2, a3, a4, a5);
	_DPP_DELEGATE_BIND(4, 7, 1, _DPP_DELEGATE_BTDEFS(1, 2), a0, a1, _a0, a2, a3, a4, a5, a6);
	_DPP_DELEGATE_BIND(5, 6, 2, _DPP_DELEGATE_BTDEFS(2, 0, 2), _a0, a0, _a1, a1, a2, a3, a4, a5);
	_DPP_DELEGATE_BIND(6, 6, 2, _DPP_DELEGATE_BTDEFS(2, 1, 2), a0, _a0, _a1, a1, a2, a3, a4, a5);
	_DPP_DELEGATE_BIND(7, 5, 3, _DPP_DELEGATE_BTDEFS(3, 0, 1, 2), _a0, _a1, _a2, a0, a1, a2, a3, a4);
	_DPP_DELEGATE_BIND(8, 7, 1, _DPP_DELEGATE_BTDEFS(1, 3), a0, a1, a2, _a0, a3, a4, a5, a6);
	_DPP_DELEGATE_BIND(9, 6, 2, _DPP_DELEGATE_BTDEFS(2, 0, 3), _a0, a0, a1, _a1, a2, a3, a4, a5);
	_DPP_DELEGATE_BIND(10, 6, 2, _DPP_DELEGATE_BTDEFS(2, 1, 3), a0, _a0, a1, _a1, a2, a3, a4, a5);
	_DPP_DELEGATE_BIND(11, 5, 3, _DPP_DELEGATE_BTDEFS(3, 0, 1, 3), _a0, _a1, a0, _a2, a1, a2, a3, a4);
	_DPP_DELEGATE_BIND(12, 6, 2, _DPP_DELEGATE_BTDEFS(2, 2, 3), a0, a1, _a0, _a1, a2, a3, a4, a5);
	_DPP_DELEGATE_BIND(13, 5, 3, _DPP_DELEGATE_BTDEFS(3, 0, 2, 3), _a0, a0, _a1, _a2, a1, a2, a3, a4);
	_DPP_DELEGATE_BIND(14, 5, 3, _DPP_DELEGATE_BTDEFS(3, 1, 2, 3), a0, _a0, _a1, _a2, a1, a2, a3, a4);
	_DPP_DELEGATE_BIND(15, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 2, 3), _a0, _a1, _a2, _a3, a0, a1, a2, a3);
	_DPP_DELEGATE_BIND(16, 7, 1, _DPP_DELEGATE_BTDEFS(1, 4), a0, a1, a2, a3, _a0, a4, a5, a6);
	_DPP_DELEGATE_BIND(17, 6, 2, _DPP_DELEGATE_BTDEFS(2, 0, 4), _a0, a0, a1, a2, _a1, a3, a4, a5);
	_DPP_DELEGATE_BIND(18, 6, 2, _DPP_DELEGATE_BTDEFS(2, 1, 4), a0, _a0, a1, a2, _a1, a3, a4, a5);
	_DPP_DELEGATE_BIND(19, 5, 3, _DPP_DELEGATE_BTDEFS(3, 0, 1, 4), _a0, _a1, a0, a1, _a2, a2, a3, a4);
	_DPP_DELEGATE_BIND(20, 6, 2, _DPP_DELEGATE_BTDEFS(2, 2, 4), a0, a1, _a0, a2, _a1, a3, a4, a5);
	_DPP_DELEGATE_BIND(21, 5, 3, _DPP_DELEGATE_BTDEFS(3, 0, 2, 4), _a0, a0, _a1, a1, _a2, a2, a3, a4);
	_DPP_DELEGATE_BIND(22, 5, 3, _DPP_DELEGATE_BTDEFS(3, 1, 2, 4), a0, _a0, _a1, a1, _a2, a2, a3, a4);
	_DPP_DELEGATE_BIND(23, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 2, 4), _a0, _a1, _a2, a0, _a3, a1, a2, a3);
	_DPP_DELEGATE_BIND(24, 6, 2, _DPP_DELEGATE_BTDEFS(2, 3, 4), a0, a1, a2, _a0, _a1, a3, a4, a5);
	_DPP_DELEGATE_BIND(25, 5, 3, _DPP_DELEGATE_BTDEFS(3, 0, 3, 4), _a0, a0, a1, _a1, _a2, a2, a3, a4);
	_DPP_DELEGATE_BIND(26, 5, 3, _DPP_DELEGATE_BTDEFS(3, 1, 3, 4), a0, _a0, a1, _a1, _a2, a2, a3, a4);
	_DPP_DELEGATE_BIND(27, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 3, 4), _a0, _a1, a0, _a2, _a3, a1, a2, a3);
	_DPP_DELEGATE_BIND(28, 5, 3, _DPP_DELEGATE_BTDEFS(3, 2, 3, 4), a0, a1, _a0, _a1, _a2, a2, a3, a4);
	_DPP_DELEGATE_BIND(29, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 2, 3, 4), _a0, a0, _a1, _a2, _a3, a1, a2, a3);
	_DPP_DELEGATE_BIND(30, 4, 4, _DPP_DELEGATE_BTDEFS(4, 1, 2, 3, 4), a0, _a0, _a1, _a2, _a3, a1, a2, a3);
	_DPP_DELEGATE_BIND(31, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 2, 3, 4), _a0, _a1, _a2, _a3, _a4, a0, a1, a2);
	_DPP_DELEGATE_BIND(32, 7, 1, _DPP_DELEGATE_BTDEFS(1, 5), a0, a1, a2, a3, a4, _a0, a5, a6);
	_DPP_DELEGATE_BIND(33, 6, 2, _DPP_DELEGATE_BTDEFS(2, 0, 5), _a0, a0, a1, a2, a3, _a1, a4, a5);
	_DPP_DELEGATE_BIND(34, 6, 2, _DPP_DELEGATE_BTDEFS(2, 1, 5), a0, _a0, a1, a2, a3, _a1, a4, a5);
	_DPP_DELEGATE_BIND(35, 5, 3, _DPP_DELEGATE_BTDEFS(3, 0, 1, 5), _a0, _a1, a0, a1, a2, _a2, a3, a4);
	_DPP_DELEGATE_BIND(36, 6, 2, _DPP_DELEGATE_BTDEFS(2, 2, 5), a0, a1, _a0, a2, a3, _a1, a4, a5);
	_DPP_DELEGATE_BIND(37, 5, 3, _DPP_DELEGATE_BTDEFS(3, 0, 2, 5), _a0, a0, _a1, a1, a2, _a2, a3, a4);
	_DPP_DELEGATE_BIND(38, 5, 3, _DPP_DELEGATE_BTDEFS(3, 1, 2, 5), a0, _a0, _a1, a1, a2, _a2, a3, a4);
	_DPP_DELEGATE_BIND(39, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 2, 5), _a0, _a1, _a2, a0, a1, _a3, a2, a3);
	_DPP_DELEGATE_BIND(40, 6, 2, _DPP_DELEGATE_BTDEFS(2, 3, 5), a0, a1, a2, _a0, a3, _a1, a4, a5);
	_DPP_DELEGATE_BIND(41, 5, 3, _DPP_DELEGATE_BTDEFS(3, 0, 3, 5), _a0, a0, a1, _a1, a2, _a2, a3, a4);
	_DPP_DELEGATE_BIND(42, 5, 3, _DPP_DELEGATE_BTDEFS(3, 1, 3, 5), a0, _a0, a1, _a1, a2, _a2, a3, a4);
	_DPP_DELEGATE_BIND(43, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 3, 5), _a0, _a1, a0, _a2, a1, _a3, a2, a3);
	_DPP_DELEGATE_BIND(44, 5, 3, _DPP_DELEGATE_BTDEFS(3, 2, 3, 5), a0, a1, _a0, _a1, a2, _a2, a3, a4);
	_DPP_DELEGATE_BIND(45, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 2, 3, 5), _a0, a0, _a1, _a2, a1, _a3, a2, a3);
	_DPP_DELEGATE_BIND(46, 4, 4, _DPP_DELEGATE_BTDEFS(4, 1, 2, 3, 5), a0, _a0, _a1, _a2, a1, _a3, a2, a3);
	_DPP_DELEGATE_BIND(47, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 2, 3, 5), _a0, _a1, _a2, _a3, a0, _a4, a1, a2);
	_DPP_DELEGATE_BIND(48, 6, 2, _DPP_DELEGATE_BTDEFS(2, 4, 5), a0, a1, a2, a3, _a0, _a1, a4, a5);
	_DPP_DELEGATE_BIND(49, 5, 3, _DPP_DELEGATE_BTDEFS(3, 0, 4, 5), _a0, a0, a1, a2, _a1, _a2, a3, a4);
	_DPP_DELEGATE_BIND(50, 5, 3, _DPP_DELEGATE_BTDEFS(3, 1, 4, 5), a0, _a0, a1, a2, _a1, _a2, a3, a4);
	_DPP_DELEGATE_BIND(51, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 4, 5), _a0, _a1, a0, a1, _a2, _a3, a2, a3);
	_DPP_DELEGATE_BIND(52, 5, 3, _DPP_DELEGATE_BTDEFS(3, 2, 4, 5), a0, a1, _a0, a2, _a1, _a2, a3, a4);
	_DPP_DELEGATE_BIND(53, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 2, 4, 5), _a0, a0, _a1, a1, _a2, _a3, a2, a3);
	_DPP_DELEGATE_BIND(54, 4, 4, _DPP_DELEGATE_BTDEFS(4, 1, 2, 4, 5), a0, _a0, _a1, a1, _a2, _a3, a2, a3);
	_DPP_DELEGATE_BIND(55, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 2, 4, 5), _a0, _a1, _a2, a0, _a3, _a4, a1, a2);
	_DPP_DELEGATE_BIND(56, 5, 3, _DPP_DELEGATE_BTDEFS(3, 3, 4, 5), a0, a1, a2, _a0, _a1, _a2, a3, a4);
	_DPP_DELEGATE_BIND(57, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 3, 4, 5), _a0, a0, a1, _a1, _a2, _a3, a2, a3);
	_DPP_DELEGATE_BIND(58, 4, 4, _DPP_DELEGATE_BTDEFS(4, 1, 3, 4, 5), a0, _a0, a1, _a1, _a2, _a3, a2, a3);
	_DPP_DELEGATE_BIND(59, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 3, 4, 5), _a0, _a1, a0, _a2, _a3, _a4, a1, a2);
	_DPP_DELEGATE_BIND(60, 4, 4, _DPP_DELEGATE_BTDEFS(4, 2, 3, 4, 5), a0, a1, _a0, _a1, _a2, _a3, a2, a3);
	_DPP_DELEGATE_BIND(61, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 2, 3, 4, 5), _a0, a0, _a1, _a2, _a3, _a4, a1, a2);
	_DPP_DELEGATE_BIND(62, 3, 5, _DPP_DELEGATE_BTDEFS(5, 1, 2, 3, 4, 5), a0, _a0, _a1, _a2, _a3, _a4, a1, a2);
	_DPP_DELEGATE_BIND(63, 2, 6, _DPP_DELEGATE_BTDEFS(6, 0, 1, 2, 3, 4, 5), _a0, _a1, _a2, _a3, _a4, _a5, a0, a1);
	_DPP_DELEGATE_BIND(64, 7, 1, _DPP_DELEGATE_BTDEFS(1, 6), a0, a1, a2, a3, a4, a5, _a0, a6);
	_DPP_DELEGATE_BIND(65, 6, 2, _DPP_DELEGATE_BTDEFS(2, 0, 6), _a0, a0, a1, a2, a3, a4, _a1, a5);
	_DPP_DELEGATE_BIND(66, 6, 2, _DPP_DELEGATE_BTDEFS(2, 1, 6), a0, _a0, a1, a2, a3, a4, _a1, a5);
	_DPP_DELEGATE_BIND(67, 5, 3, _DPP_DELEGATE_BTDEFS(3, 0, 1, 6), _a0, _a1, a0, a1, a2, a3, _a2, a4);
	_DPP_DELEGATE_BIND(68, 6, 2, _DPP_DELEGATE_BTDEFS(2, 2, 6), a0, a1, _a0, a2, a3, a4, _a1, a5);
	_DPP_DELEGATE_BIND(69, 5, 3, _DPP_DELEGATE_BTDEFS(3, 0, 2, 6), _a0, a0, _a1, a1, a2, a3, _a2, a4);
	_DPP_DELEGATE_BIND(70, 5, 3, _DPP_DELEGATE_BTDEFS(3, 1, 2, 6), a0, _a0, _a1, a1, a2, a3, _a2, a4);
	_DPP_DELEGATE_BIND(71, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 2, 6), _a0, _a1, _a2, a0, a1, a2, _a3, a3);
	_DPP_DELEGATE_BIND(72, 6, 2, _DPP_DELEGATE_BTDEFS(2, 3, 6), a0, a1, a2, _a0, a3, a4, _a1, a5);
	_DPP_DELEGATE_BIND(73, 5, 3, _DPP_DELEGATE_BTDEFS(3, 0, 3, 6), _a0, a0, a1, _a1, a2, a3, _a2, a4);
	_DPP_DELEGATE_BIND(74, 5, 3, _DPP_DELEGATE_BTDEFS(3, 1, 3, 6), a0, _a0, a1, _a1, a2, a3, _a2, a4);
	_DPP_DELEGATE_BIND(75, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 3, 6), _a0, _a1, a0, _a2, a1, a2, _a3, a3);
	_DPP_DELEGATE_BIND(76, 5, 3, _DPP_DELEGATE_BTDEFS(3, 2, 3, 6), a0, a1, _a0, _a1, a2, a3, _a2, a4);
	_DPP_DELEGATE_BIND(77, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 2, 3, 6), _a0, a0, _a1, _a2, a1, a2, _a3, a3);
	_DPP_DELEGATE_BIND(78, 4, 4, _DPP_DELEGATE_BTDEFS(4, 1, 2, 3, 6), a0, _a0, _a1, _a2, a1, a2, _a3, a3);
	_DPP_DELEGATE_BIND(79, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 2, 3, 6), _a0, _a1, _a2, _a3, a0, a1, _a4, a2);
	_DPP_DELEGATE_BIND(80, 6, 2, _DPP_DELEGATE_BTDEFS(2, 4, 6), a0, a1, a2, a3, _a0, a4, _a1, a5);
	_DPP_DELEGATE_BIND(81, 5, 3, _DPP_DELEGATE_BTDEFS(3, 0, 4, 6), _a0, a0, a1, a2, _a1, a3, _a2, a4);
	_DPP_DELEGATE_BIND(82, 5, 3, _DPP_DELEGATE_BTDEFS(3, 1, 4, 6), a0, _a0, a1, a2, _a1, a3, _a2, a4);
	_DPP_DELEGATE_BIND(83, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 4, 6), _a0, _a1, a0, a1, _a2, a2, _a3, a3);
	_DPP_DELEGATE_BIND(84, 5, 3, _DPP_DELEGATE_BTDEFS(3, 2, 4, 6), a0, a1, _a0, a2, _a1, a3, _a2, a4);
	_DPP_DELEGATE_BIND(85, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 2, 4, 6), _a0, a0, _a1, a1, _a2, a2, _a3, a3);
	_DPP_DELEGATE_BIND(86, 4, 4, _DPP_DELEGATE_BTDEFS(4, 1, 2, 4, 6), a0, _a0, _a1, a1, _a2, a2, _a3, a3);
	_DPP_DELEGATE_BIND(87, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 2, 4, 6), _a0, _a1, _a2, a0, _a3, a1, _a4, a2);
	_DPP_DELEGATE_BIND(88, 5, 3, _DPP_DELEGATE_BTDEFS(3, 3, 4, 6), a0, a1, a2, _a0, _a1, a3, _a2, a4);
	_DPP_DELEGATE_BIND(89, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 3, 4, 6), _a0, a0, a1, _a1, _a2, a2, _a3, a3);
	_DPP_DELEGATE_BIND(90, 4, 4, _DPP_DELEGATE_BTDEFS(4, 1, 3, 4, 6), a0, _a0, a1, _a1, _a2, a2, _a3, a3);
	_DPP_DELEGATE_BIND(91, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 3, 4, 6), _a0, _a1, a0, _a2, _a3, a1, _a4, a2);
	_DPP_DELEGATE_BIND(92, 4, 4, _DPP_DELEGATE_BTDEFS(4, 2, 3, 4, 6), a0, a1, _a0, _a1, _a2, a2, _a3, a3);
	_DPP_DELEGATE_BIND(93, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 2, 3, 4, 6), _a0, a0, _a1, _a2, _a3, a1, _a4, a2);
	_DPP_DELEGATE_BIND(94, 3, 5, _DPP_DELEGATE_BTDEFS(5, 1, 2, 3, 4, 6), a0, _a0, _a1, _a2, _a3, a1, _a4, a2);
	_DPP_DELEGATE_BIND(95, 2, 6, _DPP_DELEGATE_BTDEFS(6, 0, 1, 2, 3, 4, 6), _a0, _a1, _a2, _a3, _a4, a0, _a5, a1);
	_DPP_DELEGATE_BIND(96, 6, 2, _DPP_DELEGATE_BTDEFS(2, 5, 6), a0, a1, a2, a3, a4, _a0, _a1, a5);
	_DPP_DELEGATE_BIND(97, 5, 3, _DPP_DELEGATE_BTDEFS(3, 0, 5, 6), _a0, a0, a1, a2, a3, _a1, _a2, a4);
	_DPP_DELEGATE_BIND(98, 5, 3, _DPP_DELEGATE_BTDEFS(3, 1, 5, 6), a0, _a0, a1, a2, a3, _a1, _a2, a4);
	_DPP_DELEGATE_BIND(99, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 5, 6), _a0, _a1, a0, a1, a2, _a2, _a3, a3);
	_DPP_DELEGATE_BIND(100, 5, 3, _DPP_DELEGATE_BTDEFS(3, 2, 5, 6), a0, a1, _a0, a2, a3, _a1, _a2, a4);
	_DPP_DELEGATE_BIND(101, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 2, 5, 6), _a0, a0, _a1, a1, a2, _a2, _a3, a3);
	_DPP_DELEGATE_BIND(102, 4, 4, _DPP_DELEGATE_BTDEFS(4, 1, 2, 5, 6), a0, _a0, _a1, a1, a2, _a2, _a3, a3);
	_DPP_DELEGATE_BIND(103, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 2, 5, 6), _a0, _a1, _a2, a0, a1, _a3, _a4, a2);
	_DPP_DELEGATE_BIND(104, 5, 3, _DPP_DELEGATE_BTDEFS(3, 3, 5, 6), a0, a1, a2, _a0, a3, _a1, _a2, a4);
	_DPP_DELEGATE_BIND(105, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 3, 5, 6), _a0, a0, a1, _a1, a2, _a2, _a3, a3);
	_DPP_DELEGATE_BIND(106, 4, 4, _DPP_DELEGATE_BTDEFS(4, 1, 3, 5, 6), a0, _a0, a1, _a1, a2, _a2, _a3, a3);
	_DPP_DELEGATE_BIND(107, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 3, 5, 6), _a0, _a1, a0, _a2, a1, _a3, _a4, a2);
	_DPP_DELEGATE_BIND(108, 4, 4, _DPP_DELEGATE_BTDEFS(4, 2, 3, 5, 6), a0, a1, _a0, _a1, a2, _a2, _a3, a3);
	_DPP_DELEGATE_BIND(109, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 2, 3, 5, 6), _a0, a0, _a1, _a2, a1, _a3, _a4, a2);
	_DPP_DELEGATE_BIND(110, 3, 5, _DPP_DELEGATE_BTDEFS(5, 1, 2, 3, 5, 6), a0, _a0, _a1, _a2, a1, _a3, _a4, a2);
	_DPP_DELEGATE_BIND(111, 2, 6, _DPP_DELEGATE_BTDEFS(6, 0, 1, 2, 3, 5, 6), _a0, _a1, _a2, _a3, a0, _a4, _a5, a1);
	_DPP_DELEGATE_BIND(112, 5, 3, _DPP_DELEGATE_BTDEFS(3, 4, 5, 6), a0, a1, a2, a3, _a0, _a1, _a2, a4);
	_DPP_DELEGATE_BIND(113, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 4, 5, 6), _a0, a0, a1, a2, _a1, _a2, _a3, a3);
	_DPP_DELEGATE_BIND(114, 4, 4, _DPP_DELEGATE_BTDEFS(4, 1, 4, 5, 6), a0, _a0, a1, a2, _a1, _a2, _a3, a3);
	_DPP_DELEGATE_BIND(115, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 4, 5, 6), _a0, _a1, a0, a1, _a2, _a3, _a4, a2);
	_DPP_DELEGATE_BIND(116, 4, 4, _DPP_DELEGATE_BTDEFS(4, 2, 4, 5, 6), a0, a1, _a0, a2, _a1, _a2, _a3, a3);
	_DPP_DELEGATE_BIND(117, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 2, 4, 5, 6), _a0, a0, _a1, a1, _a2, _a3, _a4, a2);
	_DPP_DELEGATE_BIND(118, 3, 5, _DPP_DELEGATE_BTDEFS(5, 1, 2, 4, 5, 6), a0, _a0, _a1, a1, _a2, _a3, _a4, a2);
	_DPP_DELEGATE_BIND(119, 2, 6, _DPP_DELEGATE_BTDEFS(6, 0, 1, 2, 4, 5, 6), _a0, _a1, _a2, a0, _a3, _a4, _a5, a1);
	_DPP_DELEGATE_BIND(120, 4, 4, _DPP_DELEGATE_BTDEFS(4, 3, 4, 5, 6), a0, a1, a2, _a0, _a1, _a2, _a3, a3);
	_DPP_DELEGATE_BIND(121, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 3, 4, 5, 6), _a0, a0, a1, _a1, _a2, _a3, _a4, a2);
	_DPP_DELEGATE_BIND(122, 3, 5, _DPP_DELEGATE_BTDEFS(5, 1, 3, 4, 5, 6), a0, _a0, a1, _a1, _a2, _a3, _a4, a2);
	_DPP_DELEGATE_BIND(123, 2, 6, _DPP_DELEGATE_BTDEFS(6, 0, 1, 3, 4, 5, 6), _a0, _a1, a0, _a2, _a3, _a4, _a5, a1);
	_DPP_DELEGATE_BIND(124, 3, 5, _DPP_DELEGATE_BTDEFS(5, 2, 3, 4, 5, 6), a0, a1, _a0, _a1, _a2, _a3, _a4, a2);
	_DPP_DELEGATE_BIND(125, 2, 6, _DPP_DELEGATE_BTDEFS(6, 0, 2, 3, 4, 5, 6), _a0, a0, _a1, _a2, _a3, _a4, _a5, a1);
	_DPP_DELEGATE_BIND(126, 2, 6, _DPP_DELEGATE_BTDEFS(6, 1, 2, 3, 4, 5, 6), a0, _a0, _a1, _a2, _a3, _a4, _a5, a1);
	_DPP_DELEGATE_BIND(127, 1, 7, _DPP_DELEGATE_BTDEFS(7, 0, 1, 2, 3, 4, 5, 6), _a0, _a1, _a2, _a3, _a4, _a5, _a6, a0);
	_DPP_DELEGATE_BIND(128, 7, 1, _DPP_DELEGATE_BTDEFS(1, 7), a0, a1, a2, a3, a4, a5, a6, _a0);
	_DPP_DELEGATE_BIND(129, 6, 2, _DPP_DELEGATE_BTDEFS(2, 0, 7), _a0, a0, a1, a2, a3, a4, a5, _a1);
	_DPP_DELEGATE_BIND(130, 6, 2, _DPP_DELEGATE_BTDEFS(2, 1, 7), a0, _a0, a1, a2, a3, a4, a5, _a1);
	_DPP_DELEGATE_BIND(131, 5, 3, _DPP_DELEGATE_BTDEFS(3, 0, 1, 7), _a0, _a1, a0, a1, a2, a3, a4, _a2);
	_DPP_DELEGATE_BIND(132, 6, 2, _DPP_DELEGATE_BTDEFS(2, 2, 7), a0, a1, _a0, a2, a3, a4, a5, _a1);
	_DPP_DELEGATE_BIND(133, 5, 3, _DPP_DELEGATE_BTDEFS(3, 0, 2, 7), _a0, a0, _a1, a1, a2, a3, a4, _a2);
	_DPP_DELEGATE_BIND(134, 5, 3, _DPP_DELEGATE_BTDEFS(3, 1, 2, 7), a0, _a0, _a1, a1, a2, a3, a4, _a2);
	_DPP_DELEGATE_BIND(135, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 2, 7), _a0, _a1, _a2, a0, a1, a2, a3, _a3);
	_DPP_DELEGATE_BIND(136, 6, 2, _DPP_DELEGATE_BTDEFS(2, 3, 7), a0, a1, a2, _a0, a3, a4, a5, _a1);
	_DPP_DELEGATE_BIND(137, 5, 3, _DPP_DELEGATE_BTDEFS(3, 0, 3, 7), _a0, a0, a1, _a1, a2, a3, a4, _a2);
	_DPP_DELEGATE_BIND(138, 5, 3, _DPP_DELEGATE_BTDEFS(3, 1, 3, 7), a0, _a0, a1, _a1, a2, a3, a4, _a2);
	_DPP_DELEGATE_BIND(139, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 3, 7), _a0, _a1, a0, _a2, a1, a2, a3, _a3);
	_DPP_DELEGATE_BIND(140, 5, 3, _DPP_DELEGATE_BTDEFS(3, 2, 3, 7), a0, a1, _a0, _a1, a2, a3, a4, _a2);
	_DPP_DELEGATE_BIND(141, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 2, 3, 7), _a0, a0, _a1, _a2, a1, a2, a3, _a3);
	_DPP_DELEGATE_BIND(142, 4, 4, _DPP_DELEGATE_BTDEFS(4, 1, 2, 3, 7), a0, _a0, _a1, _a2, a1, a2, a3, _a3);
	_DPP_DELEGATE_BIND(143, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 2, 3, 7), _a0, _a1, _a2, _a3, a0, a1, a2, _a4);
	_DPP_DELEGATE_BIND(144, 6, 2, _DPP_DELEGATE_BTDEFS(2, 4, 7), a0, a1, a2, a3, _a0, a4, a5, _a1);
	_DPP_DELEGATE_BIND(145, 5, 3, _DPP_DELEGATE_BTDEFS(3, 0, 4, 7), _a0, a0, a1, a2, _a1, a3, a4, _a2);
	_DPP_DELEGATE_BIND(146, 5, 3, _DPP_DELEGATE_BTDEFS(3, 1, 4, 7), a0, _a0, a1, a2, _a1, a3, a4, _a2);
	_DPP_DELEGATE_BIND(147, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 4, 7), _a0, _a1, a0, a1, _a2, a2, a3, _a3);
	_DPP_DELEGATE_BIND(148, 5, 3, _DPP_DELEGATE_BTDEFS(3, 2, 4, 7), a0, a1, _a0, a2, _a1, a3, a4, _a2);
	_DPP_DELEGATE_BIND(149, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 2, 4, 7), _a0, a0, _a1, a1, _a2, a2, a3, _a3);
	_DPP_DELEGATE_BIND(150, 4, 4, _DPP_DELEGATE_BTDEFS(4, 1, 2, 4, 7), a0, _a0, _a1, a1, _a2, a2, a3, _a3);
	_DPP_DELEGATE_BIND(151, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 2, 4, 7), _a0, _a1, _a2, a0, _a3, a1, a2, _a4);
	_DPP_DELEGATE_BIND(152, 5, 3, _DPP_DELEGATE_BTDEFS(3, 3, 4, 7), a0, a1, a2, _a0, _a1, a3, a4, _a2);
	_DPP_DELEGATE_BIND(153, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 3, 4, 7), _a0, a0, a1, _a1, _a2, a2, a3, _a3);
	_DPP_DELEGATE_BIND(154, 4, 4, _DPP_DELEGATE_BTDEFS(4, 1, 3, 4, 7), a0, _a0, a1, _a1, _a2, a2, a3, _a3);
	_DPP_DELEGATE_BIND(155, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 3, 4, 7), _a0, _a1, a0, _a2, _a3, a1, a2, _a4);
	_DPP_DELEGATE_BIND(156, 4, 4, _DPP_DELEGATE_BTDEFS(4, 2, 3, 4, 7), a0, a1, _a0, _a1, _a2, a2, a3, _a3);
	_DPP_DELEGATE_BIND(157, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 2, 3, 4, 7), _a0, a0, _a1, _a2, _a3, a1, a2, _a4);
	_DPP_DELEGATE_BIND(158, 3, 5, _DPP_DELEGATE_BTDEFS(5, 1, 2, 3, 4, 7), a0, _a0, _a1, _a2, _a3, a1, a2, _a4);
	_DPP_DELEGATE_BIND(159, 2, 6, _DPP_DELEGATE_BTDEFS(6, 0, 1, 2, 3, 4, 7), _a0, _a1, _a2, _a3, _a4, a0, a1, _a5);
	_DPP_DELEGATE_BIND(160, 6, 2, _DPP_DELEGATE_BTDEFS(2, 5, 7), a0, a1, a2, a3, a4, _a0, a5, _a1);
	_DPP_DELEGATE_BIND(161, 5, 3, _DPP_DELEGATE_BTDEFS(3, 0, 5, 7), _a0, a0, a1, a2, a3, _a1, a4, _a2);
	_DPP_DELEGATE_BIND(162, 5, 3, _DPP_DELEGATE_BTDEFS(3, 1, 5, 7), a0, _a0, a1, a2, a3, _a1, a4, _a2);
	_DPP_DELEGATE_BIND(163, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 5, 7), _a0, _a1, a0, a1, a2, _a2, a3, _a3);
	_DPP_DELEGATE_BIND(164, 5, 3, _DPP_DELEGATE_BTDEFS(3, 2, 5, 7), a0, a1, _a0, a2, a3, _a1, a4, _a2);
	_DPP_DELEGATE_BIND(165, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 2, 5, 7), _a0, a0, _a1, a1, a2, _a2, a3, _a3);
	_DPP_DELEGATE_BIND(166, 4, 4, _DPP_DELEGATE_BTDEFS(4, 1, 2, 5, 7), a0, _a0, _a1, a1, a2, _a2, a3, _a3);
	_DPP_DELEGATE_BIND(167, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 2, 5, 7), _a0, _a1, _a2, a0, a1, _a3, a2, _a4);
	_DPP_DELEGATE_BIND(168, 5, 3, _DPP_DELEGATE_BTDEFS(3, 3, 5, 7), a0, a1, a2, _a0, a3, _a1, a4, _a2);
	_DPP_DELEGATE_BIND(169, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 3, 5, 7), _a0, a0, a1, _a1, a2, _a2, a3, _a3);
	_DPP_DELEGATE_BIND(170, 4, 4, _DPP_DELEGATE_BTDEFS(4, 1, 3, 5, 7), a0, _a0, a1, _a1, a2, _a2, a3, _a3);
	_DPP_DELEGATE_BIND(171, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 3, 5, 7), _a0, _a1, a0, _a2, a1, _a3, a2, _a4);
	_DPP_DELEGATE_BIND(172, 4, 4, _DPP_DELEGATE_BTDEFS(4, 2, 3, 5, 7), a0, a1, _a0, _a1, a2, _a2, a3, _a3);
	_DPP_DELEGATE_BIND(173, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 2, 3, 5, 7), _a0, a0, _a1, _a2, a1, _a3, a2, _a4);
	_DPP_DELEGATE_BIND(174, 3, 5, _DPP_DELEGATE_BTDEFS(5, 1, 2, 3, 5, 7), a0, _a0, _a1, _a2, a1, _a3, a2, _a4);
	_DPP_DELEGATE_BIND(175, 2, 6, _DPP_DELEGATE_BTDEFS(6, 0, 1, 2, 3, 5, 7), _a0, _a1, _a2, _a3, a0, _a4, a1, _a5);
	_DPP_DELEGATE_BIND(176, 5, 3, _DPP_DELEGATE_BTDEFS(3, 4, 5, 7), a0, a1, a2, a3, _a0, _a1, a4, _a2);
	_DPP_DELEGATE_BIND(177, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 4, 5, 7), _a0, a0, a1, a2, _a1, _a2, a3, _a3);
	_DPP_DELEGATE_BIND(178, 4, 4, _DPP_DELEGATE_BTDEFS(4, 1, 4, 5, 7), a0, _a0, a1, a2, _a1, _a2, a3, _a3);
	_DPP_DELEGATE_BIND(179, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 4, 5, 7), _a0, _a1, a0, a1, _a2, _a3, a2, _a4);
	_DPP_DELEGATE_BIND(180, 4, 4, _DPP_DELEGATE_BTDEFS(4, 2, 4, 5, 7), a0, a1, _a0, a2, _a1, _a2, a3, _a3);
	_DPP_DELEGATE_BIND(181, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 2, 4, 5, 7), _a0, a0, _a1, a1, _a2, _a3, a2, _a4);
	_DPP_DELEGATE_BIND(182, 3, 5, _DPP_DELEGATE_BTDEFS(5, 1, 2, 4, 5, 7), a0, _a0, _a1, a1, _a2, _a3, a2, _a4);
	_DPP_DELEGATE_BIND(183, 2, 6, _DPP_DELEGATE_BTDEFS(6, 0, 1, 2, 4, 5, 7), _a0, _a1, _a2, a0, _a3, _a4, a1, _a5);
	_DPP_DELEGATE_BIND(184, 4, 4, _DPP_DELEGATE_BTDEFS(4, 3, 4, 5, 7), a0, a1, a2, _a0, _a1, _a2, a3, _a3);
	_DPP_DELEGATE_BIND(185, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 3, 4, 5, 7), _a0, a0, a1, _a1, _a2, _a3, a2, _a4);
	_DPP_DELEGATE_BIND(186, 3, 5, _DPP_DELEGATE_BTDEFS(5, 1, 3, 4, 5, 7), a0, _a0, a1, _a1, _a2, _a3, a2, _a4);
	_DPP_DELEGATE_BIND(187, 2, 6, _DPP_DELEGATE_BTDEFS(6, 0, 1, 3, 4, 5, 7), _a0, _a1, a0, _a2, _a3, _a4, a1, _a5);
	_DPP_DELEGATE_BIND(188, 3, 5, _DPP_DELEGATE_BTDEFS(5, 2, 3, 4, 5, 7), a0, a1, _a0, _a1, _a2, _a3, a2, _a4);
	_DPP_DELEGATE_BIND(189, 2, 6, _DPP_DELEGATE_BTDEFS(6, 0, 2, 3, 4, 5, 7), _a0, a0, _a1, _a2, _a3, _a4, a1, _a5);
	_DPP_DELEGATE_BIND(190, 2, 6, _DPP_DELEGATE_BTDEFS(6, 1, 2, 3, 4, 5, 7), a0, _a0, _a1, _a2, _a3, _a4, a1, _a5);
	_DPP_DELEGATE_BIND(191, 1, 7, _DPP_DELEGATE_BTDEFS(7, 0, 1, 2, 3, 4, 5, 7), _a0, _a1, _a2, _a3, _a4, _a5, a0, _a6);
	_DPP_DELEGATE_BIND(192, 6, 2, _DPP_DELEGATE_BTDEFS(2, 6, 7), a0, a1, a2, a3, a4, a5, _a0, _a1);
	_DPP_DELEGATE_BIND(193, 5, 3, _DPP_DELEGATE_BTDEFS(3, 0, 6, 7), _a0, a0, a1, a2, a3, a4, _a1, _a2);
	_DPP_DELEGATE_BIND(194, 5, 3, _DPP_DELEGATE_BTDEFS(3, 1, 6, 7), a0, _a0, a1, a2, a3, a4, _a1, _a2);
	_DPP_DELEGATE_BIND(195, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 1, 6, 7), _a0, _a1, a0, a1, a2, a3, _a2, _a3);
	_DPP_DELEGATE_BIND(196, 5, 3, _DPP_DELEGATE_BTDEFS(3, 2, 6, 7), a0, a1, _a0, a2, a3, a4, _a1, _a2);
	_DPP_DELEGATE_BIND(197, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 2, 6, 7), _a0, a0, _a1, a1, a2, a3, _a2, _a3);
	_DPP_DELEGATE_BIND(198, 4, 4, _DPP_DELEGATE_BTDEFS(4, 1, 2, 6, 7), a0, _a0, _a1, a1, a2, a3, _a2, _a3);
	_DPP_DELEGATE_BIND(199, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 2, 6, 7), _a0, _a1, _a2, a0, a1, a2, _a3, _a4);
	_DPP_DELEGATE_BIND(200, 5, 3, _DPP_DELEGATE_BTDEFS(3, 3, 6, 7), a0, a1, a2, _a0, a3, a4, _a1, _a2);
	_DPP_DELEGATE_BIND(201, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 3, 6, 7), _a0, a0, a1, _a1, a2, a3, _a2, _a3);
	_DPP_DELEGATE_BIND(202, 4, 4, _DPP_DELEGATE_BTDEFS(4, 1, 3, 6, 7), a0, _a0, a1, _a1, a2, a3, _a2, _a3);
	_DPP_DELEGATE_BIND(203, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 3, 6, 7), _a0, _a1, a0, _a2, a1, a2, _a3, _a4);
	_DPP_DELEGATE_BIND(204, 4, 4, _DPP_DELEGATE_BTDEFS(4, 2, 3, 6, 7), a0, a1, _a0, _a1, a2, a3, _a2, _a3);
	_DPP_DELEGATE_BIND(205, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 2, 3, 6, 7), _a0, a0, _a1, _a2, a1, a2, _a3, _a4);
	_DPP_DELEGATE_BIND(206, 3, 5, _DPP_DELEGATE_BTDEFS(5, 1, 2, 3, 6, 7), a0, _a0, _a1, _a2, a1, a2, _a3, _a4);
	_DPP_DELEGATE_BIND(207, 2, 6, _DPP_DELEGATE_BTDEFS(6, 0, 1, 2, 3, 6, 7), _a0, _a1, _a2, _a3, a0, a1, _a4, _a5);
	_DPP_DELEGATE_BIND(208, 5, 3, _DPP_DELEGATE_BTDEFS(3, 4, 6, 7), a0, a1, a2, a3, _a0, a4, _a1, _a2);
	_DPP_DELEGATE_BIND(209, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 4, 6, 7), _a0, a0, a1, a2, _a1, a3, _a2, _a3);
	_DPP_DELEGATE_BIND(210, 4, 4, _DPP_DELEGATE_BTDEFS(4, 1, 4, 6, 7), a0, _a0, a1, a2, _a1, a3, _a2, _a3);
	_DPP_DELEGATE_BIND(211, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 4, 6, 7), _a0, _a1, a0, a1, _a2, a2, _a3, _a4);
	_DPP_DELEGATE_BIND(212, 4, 4, _DPP_DELEGATE_BTDEFS(4, 2, 4, 6, 7), a0, a1, _a0, a2, _a1, a3, _a2, _a3);
	_DPP_DELEGATE_BIND(213, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 2, 4, 6, 7), _a0, a0, _a1, a1, _a2, a2, _a3, _a4);
	_DPP_DELEGATE_BIND(214, 3, 5, _DPP_DELEGATE_BTDEFS(5, 1, 2, 4, 6, 7), a0, _a0, _a1, a1, _a2, a2, _a3, _a4);
	_DPP_DELEGATE_BIND(215, 2, 6, _DPP_DELEGATE_BTDEFS(6, 0, 1, 2, 4, 6, 7), _a0, _a1, _a2, a0, _a3, a1, _a4, _a5);
	_DPP_DELEGATE_BIND(216, 4, 4, _DPP_DELEGATE_BTDEFS(4, 3, 4, 6, 7), a0, a1, a2, _a0, _a1, a3, _a2, _a3);
	_DPP_DELEGATE_BIND(217, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 3, 4, 6, 7), _a0, a0, a1, _a1, _a2, a2, _a3, _a4);
	_DPP_DELEGATE_BIND(218, 3, 5, _DPP_DELEGATE_BTDEFS(5, 1, 3, 4, 6, 7), a0, _a0, a1, _a1, _a2, a2, _a3, _a4);
	_DPP_DELEGATE_BIND(219, 2, 6, _DPP_DELEGATE_BTDEFS(6, 0, 1, 3, 4, 6, 7), _a0, _a1, a0, _a2, _a3, a1, _a4, _a5);
	_DPP_DELEGATE_BIND(220, 3, 5, _DPP_DELEGATE_BTDEFS(5, 2, 3, 4, 6, 7), a0, a1, _a0, _a1, _a2, a2, _a3, _a4);
	_DPP_DELEGATE_BIND(221, 2, 6, _DPP_DELEGATE_BTDEFS(6, 0, 2, 3, 4, 6, 7), _a0, a0, _a1, _a2, _a3, a1, _a4, _a5);
	_DPP_DELEGATE_BIND(222, 2, 6, _DPP_DELEGATE_BTDEFS(6, 1, 2, 3, 4, 6, 7), a0, _a0, _a1, _a2, _a3, a1, _a4, _a5);
	_DPP_DELEGATE_BIND(223, 1, 7, _DPP_DELEGATE_BTDEFS(7, 0, 1, 2, 3, 4, 6, 7), _a0, _a1, _a2, _a3, _a4, a0, _a5, _a6);
	_DPP_DELEGATE_BIND(224, 5, 3, _DPP_DELEGATE_BTDEFS(3, 5, 6, 7), a0, a1, a2, a3, a4, _a0, _a1, _a2);
	_DPP_DELEGATE_BIND(225, 4, 4, _DPP_DELEGATE_BTDEFS(4, 0, 5, 6, 7), _a0, a0, a1, a2, a3, _a1, _a2, _a3);
	_DPP_DELEGATE_BIND(226, 4, 4, _DPP_DELEGATE_BTDEFS(4, 1, 5, 6, 7), a0, _a0, a1, a2, a3, _a1, _a2, _a3);
	_DPP_DELEGATE_BIND(227, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 1, 5, 6, 7), _a0, _a1, a0, a1, a2, _a2, _a3, _a4);
	_DPP_DELEGATE_BIND(228, 4, 4, _DPP_DELEGATE_BTDEFS(4, 2, 5, 6, 7), a0, a1, _a0, a2, a3, _a1, _a2, _a3);
	_DPP_DELEGATE_BIND(229, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 2, 5, 6, 7), _a0, a0, _a1, a1, a2, _a2, _a3, _a4);
	_DPP_DELEGATE_BIND(230, 3, 5, _DPP_DELEGATE_BTDEFS(5, 1, 2, 5, 6, 7), a0, _a0, _a1, a1, a2, _a2, _a3, _a4);
	_DPP_DELEGATE_BIND(231, 2, 6, _DPP_DELEGATE_BTDEFS(6, 0, 1, 2, 5, 6, 7), _a0, _a1, _a2, a0, a1, _a3, _a4, _a5);
	_DPP_DELEGATE_BIND(232, 4, 4, _DPP_DELEGATE_BTDEFS(4, 3, 5, 6, 7), a0, a1, a2, _a0, a3, _a1, _a2, _a3);
	_DPP_DELEGATE_BIND(233, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 3, 5, 6, 7), _a0, a0, a1, _a1, a2, _a2, _a3, _a4);
	_DPP_DELEGATE_BIND(234, 3, 5, _DPP_DELEGATE_BTDEFS(5, 1, 3, 5, 6, 7), a0, _a0, a1, _a1, a2, _a2, _a3, _a4);
	_DPP_DELEGATE_BIND(235, 2, 6, _DPP_DELEGATE_BTDEFS(6, 0, 1, 3, 5, 6, 7), _a0, _a1, a0, _a2, a1, _a3, _a4, _a5);
	_DPP_DELEGATE_BIND(236, 3, 5, _DPP_DELEGATE_BTDEFS(5, 2, 3, 5, 6, 7), a0, a1, _a0, _a1, a2, _a2, _a3, _a4);
	_DPP_DELEGATE_BIND(237, 2, 6, _DPP_DELEGATE_BTDEFS(6, 0, 2, 3, 5, 6, 7), _a0, a0, _a1, _a2, a1, _a3, _a4, _a5);
	_DPP_DELEGATE_BIND(238, 2, 6, _DPP_DELEGATE_BTDEFS(6, 1, 2, 3, 5, 6, 7), a0, _a0, _a1, _a2, a1, _a3, _a4, _a5);
	_DPP_DELEGATE_BIND(239, 1, 7, _DPP_DELEGATE_BTDEFS(7, 0, 1, 2, 3, 5, 6, 7), _a0, _a1, _a2, _a3, a0, _a4, _a5, _a6);
	_DPP_DELEGATE_BIND(240, 4, 4, _DPP_DELEGATE_BTDEFS(4, 4, 5, 6, 7), a0, a1, a2, a3, _a0, _a1, _a2, _a3);
	_DPP_DELEGATE_BIND(241, 3, 5, _DPP_DELEGATE_BTDEFS(5, 0, 4, 5, 6, 7), _a0, a0, a1, a2, _a1, _a2, _a3, _a4);
	_DPP_DELEGATE_BIND(242, 3, 5, _DPP_DELEGATE_BTDEFS(5, 1, 4, 5, 6, 7), a0, _a0, a1, a2, _a1, _a2, _a3, _a4);
	_DPP_DELEGATE_BIND(243, 2, 6, _DPP_DELEGATE_BTDEFS(6, 0, 1, 4, 5, 6, 7), _a0, _a1, a0, a1, _a2, _a3, _a4, _a5);
	_DPP_DELEGATE_BIND(244, 3, 5, _DPP_DELEGATE_BTDEFS(5, 2, 4, 5, 6, 7), a0, a1, _a0, a2, _a1, _a2, _a3, _a4);
	_DPP_DELEGATE_BIND(245, 2, 6, _DPP_DELEGATE_BTDEFS(6, 0, 2, 4, 5, 6, 7), _a0, a0, _a1, a1, _a2, _a3, _a4, _a5);
	_DPP_DELEGATE_BIND(246, 2, 6, _DPP_DELEGATE_BTDEFS(6, 1, 2, 4, 5, 6, 7), a0, _a0, _a1, a1, _a2, _a3, _a4, _a5);
	_DPP_DELEGATE_BIND(247, 1, 7, _DPP_DELEGATE_BTDEFS(7, 0, 1, 2, 4, 5, 6, 7), _a0, _a1, _a2, a0, _a3, _a4, _a5, _a6);
	_DPP_DELEGATE_BIND(248, 3, 5, _DPP_DELEGATE_BTDEFS(5, 3, 4, 5, 6, 7), a0, a1, a2, _a0, _a1, _a2, _a3, _a4);
	_DPP_DELEGATE_BIND(249, 2, 6, _DPP_DELEGATE_BTDEFS(6, 0, 3, 4, 5, 6, 7), _a0, a0, a1, _a1, _a2, _a3, _a4, _a5);
	_DPP_DELEGATE_BIND(250, 2, 6, _DPP_DELEGATE_BTDEFS(6, 1, 3, 4, 5, 6, 7), a0, _a0, a1, _a1, _a2, _a3, _a4, _a5);
	_DPP_DELEGATE_BIND(251, 1, 7, _DPP_DELEGATE_BTDEFS(7, 0, 1, 3, 4, 5, 6, 7), _a0, _a1, a0, _a2, _a3, _a4, _a5, _a6);
	_DPP_DELEGATE_BIND(252, 2, 6, _DPP_DELEGATE_BTDEFS(6, 2, 3, 4, 5, 6, 7), a0, a1, _a0, _a1, _a2, _a3, _a4, _a5);
	_DPP_DELEGATE_BIND(253, 1, 7, _DPP_DELEGATE_BTDEFS(7, 0, 2, 3, 4, 5, 6, 7), _a0, a0, _a1, _a2, _a3, _a4, _a5, _a6);
	_DPP_DELEGATE_BIND(254, 1, 7, _DPP_DELEGATE_BTDEFS(7, 1, 2, 3, 4, 5, 6, 7), a0, _a0, _a1, _a2, _a3, _a4, _a5, _a6);
	_DPP_DELEGATE_BIND(255, 0, 8, _DPP_DELEGATE_BTDEFS(8, 0, 1, 2, 3, 4, 5, 6, 7), _a0, _a1, _a2, _a3, _a4, _a5, _a6, _a7);
#endif

#if DPP_DELEGATE_ARGC > 8
# error DPP_DELEGATE_ARGC > 8 not supported
#endif

	//////////////////////////////////////////////////////////////////////
	//	container push delegate class
	//////////////////////////////////////////////////////////////////////

	template <class X, int id, bool smart, class ItemBase>
	class linked_list;

	/**
	   @internal
	   @module{Delegates}
	*/
	template <class Container>
	struct delegate_push_types
	{
		typedef typename Container::const_reference arg;
	};

	/**
	   @internal
	   @module{Delegates}
	*/
	template <class X, int id, bool smart, class ItemBase>
	struct delegate_push_types <linked_list<X, id, smart, ItemBase> >
	{
		typedef _DPP_DR106(X) & arg;
	};

	/**
	   @internal
	   @module{Delegates}
	*/
	template <class A0, class PushArg>
	struct delegate_push_ptr
	{
		typedef PushArg arg;
		static _DPP_DR106(PushArg) & get(_DPP_DR106(A0) &a0)
		{
			return a0;
		}
	};

	/**
	   @internal
	   @module{Delegates}
	*/
	template <class A0, class PushArg>
	struct delegate_push_ptr<A0, PushArg* const &>
	{
		typedef PushArg * const & arg;
		static PushArg * get(_DPP_DR106(A0) &a0)
		{
			return &a0;
		}
	};

	/**
	   @short Container push delegate class
	   @main
	   @module{Delegates}
	   @header dpp/delegate
	   @prototype template <typename Container, typename A0 = [...], void (Container::*PushFunc)([...]) = &Container::push_back>

	   This delegate class push items on container on invocation.

	   @param Container Container type
	   @param A0 Type of single argument of delegate prototype
	   @param PushArg Type of container push function argument
	   @param Push Container push member function, default is @tt push_back

	   Usage example:
	   @example test/test_delegate.cc:push|push1
	   Usage with value argument type instead of reference:
	   @example test/test_delegate.cc:push|push2
	   Usage with container @tt push_front function:
	   @example test/test_delegate.cc:push|push3
	   Usage with pointers container:
	   @example test/test_delegate.cc:push4
	*/
	template <typename Container,
	         typename A0 = typename delegate_push_types<Container>::arg,
	         void (Container::*PushFunc)(
	             typename delegate_push_ptr<A0,
	             typename delegate_push_types<Container>::arg>::arg
	         ) = &Container::push_back>
	class delegate_push
		: public delegate< void (A0) >
	{
		public:

			delegate_push()
				: _cont(0)
			{
			}

			delegate_push(Container &cont)
				: _cont(&cont)
			{
			}

			void operator()(A0 a0) const
			{
				return delegate_push::call(a0);
			}

			bool valid() const
			{
				return _cont;
			}

		private:
			void call(A0 a0) const
			{
				(_cont->*PushFunc)(delegate_push_ptr<A0, typename delegate_push_types<Container>::arg>::get(a0));
			}

			Container *_cont;
	};

	//////////////////////////////////////////////////////////////////////
	//	container iterator delegate class
	//////////////////////////////////////////////////////////////////////

	/**
	   @internal
	   @module{Delegates}
	*/
	template <class C> struct delegate_iterate_types
	{
		typedef typename C::iterator iterator;
		typedef typename C::value_type & reference;
	};

	/**
	   @internal
	   @module{Delegates}
	*/
	template <class C> struct delegate_iterate_types <const C>
	{
		typedef typename C::const_iterator iterator;
		typedef const typename C::value_type & reference;
	};

	/**
	   @short Container traversal delegate class
	   @main
	   @module{Delegates}
	   @header dpp/delegate

	   This delegate class can be used to returns each item present in
	   associated container.

	   @param Container Container type
	   @param R Return type of delegate prototype

	   Usage example:
	   @example test/test_delegate.cc:push|iter1
	*/
	template <typename Container,
	         typename R = typename delegate_iterate_types<Container>::reference>
	class delegate_iterate
		: public delegate< R () >
	{
		public:

			typedef typename delegate_iterate_types<Container>::iterator iterator;

			delegate_iterate(Container &cont)
				: _i(cont.begin()),
				  _end(cont.end())
			{
			}

			delegate_iterate(const iterator &begin, const iterator &end)
				: _i(begin),
				  _end(end)
			{
			}

			/** Test if container end has been reached. */
			bool valid() const
			{
				return _i != _end;
			}

			R operator()() const
			{
				return delegate_iterate::call();
			}

		private:
			R call() const
			{
				delegate_iterate *_this = const_cast<delegate_iterate*>(this);
				return *_this->_i++;
			}

			iterator _i;
			iterator _end;
	};

	//////////////////////////////////////////////////////////////////////
	//	container output delegate class
	//////////////////////////////////////////////////////////////////////

	/**
	   @short Standard stream output delegate class
	   @main
	   @module{Delegates}
	   @header dpp/delegate

	   This delegate class can be used to write to a @ref std::ostream
	   stream on invocation.

	   A separator string which is output after each value may be
	   specified.

	   @param Container Container type
	   @param A0 Type of single argument of delegate prototype

	   Usage example:
	   @example test/test_delegate.cc:ostream
	*/
	template <typename A0>
	class delegate_ostream
		: public delegate< void (A0) >
	{
		public:

			delegate_ostream()
				: _out(0)
			{
			}

			delegate_ostream(std::ostream &out, const char *sep = "")
				: _out(&out),
				  _sep(sep)
			{
			}

			/** @This returns @ref std::ostream::good function result on stream. */
			bool valid() const
			{
				return _out && _out->good();
			}

			void operator()(A0 a0) const
			{
				return delegate_ostream::call(a0);
			}

		private:
			void call(A0 a0) const
			{
				*_out << a0 << _sep;
			}

			std::ostream *_out;
			const char *_sep;
	};


	//////////////////////////////////////////////////////////////////////
	//	container input delegate class
	//////////////////////////////////////////////////////////////////////

	/**
	   @short Standard stream input delegate class
	   @main
	   @module{Delegates}
	   @header dpp/delegate

	   This delegate class can be used to read from a @ref std::istream
	   stream on invocation.

	   Usage example:
	   @example test/test_delegate.cc:istream
	*/
	template <typename R>
	class delegate_istream
		: public delegate< R () >
	{
		public:

			delegate_istream(std::istream &in)
				: _in(&in)
			{
			}

			/** @This returns @ref std::istream::good function result on stream. */
			bool valid() const
			{
				return _in && _in->good();
			}

			R operator()() const
			{
				return delegate_istream::call();
			}

		private:
			R call() const
			{
				R r;
				*_in >> r;
				return r;
			}

			std::istream *_in;
	};


	//////////////////////////////////////////////////////////////////////
	//	user delegate class definition macros
	//////////////////////////////////////////////////////////////////////

#define _DPP_DELEGATE_X(a, b) a##b
#define _DPP_DELEGATE_NAME(l) _DPP_DELEGATE_X(_my_delegate, l)

	/** @This provides a convenient way to write custom delegate types.
	    @see {#DPP_DELEGATE0_OBJ, #DPP_DELEGATE1_TYPE}

	    @example test/test_delegate.cc:my0
	    @showcontent
	 */
#define DPP_DELEGATE0_TYPE(return_type, args_list, ...)	\
	class : public dpp::delegate< return_type args_list >	\
	{							\
			bool valid() const					\
			{							\
				return true;					\
			}							\
			\
			return_type call args_list const			\
			{							\
				__VA_ARGS__;					\
			}							\
	}

	/** @see {#DPP_DELEGATE0_TYPE} @showcontent */
# define DPP_DELEGATE0_OBJ(name, return_type, args_list, ...) \
	DPP_DELEGATE0_TYPE(return_type, args_list, __VA_ARGS__) name

#if DPP_DELEGATE_ARGC >= 1

	/** @see {#DPP_DELEGATE1_OBJ, #DPP_DELEGATE0_TYPE} @showcontent */
# define DPP_DELEGATE1_TYPE(return_type, args_list, data0_type, ...)	\
	class _DPP_DELEGATE_NAME(__LINE__)					\
		: public dpp::delegate< return_type args_list >			\
	{									\
		public:								\
			_DPP_DELEGATE_NAME(__LINE__)(data0_type data0)			\
				: _0(data0)							\
			{}									\
		private:								\
			bool valid() const							\
			{									\
				return true;							\
			}									\
			\
			return_type call args_list const					\
			{									\
				__VA_ARGS__;							\
			}									\
			\
			data0_type _0;							\
	}

	/** @This provides a convenient way to create custom delegate
	    objects.

	    One or more data fields can be embedded in delegate object by
	    using one of the @tt DPP_DELEGATEn_OBJ macros:

	    @example test/test_delegate.cc:my1
	    @showcontent

	    @see {#DPP_DELEGATE1_TYPE, #DPP_DELEGATEO_OBJ,
	    #DPP_DELEGATE2_OBJ, #DPP_DELEGATE3_OBJ, #DPP_DELEGATE4_OBJ}
	*/
# define DPP_DELEGATE1_OBJ(name, return_type, args_list, data0_type, init0, ...) \
	DPP_DELEGATE1_TYPE(return_type, args_list, data0_type, __VA_ARGS__)	\
	name(init0)

#endif

#if DPP_DELEGATE_ARGC >= 2

	/** @see {#DPP_DELEGATE2_OBJ, #DPP_DELEGATE1_TYPE} */
# define DPP_DELEGATE2_TYPE(return_type, args_list, data0_type, data1_type, ...) \
	class _DPP_DELEGATE_NAME(__LINE__)					\
		: public dpp::delegate< return_type args_list >			\
	{									\
		public:								\
			_DPP_DELEGATE_NAME(__LINE__)(data0_type data0, data1_type data1)	\
				: _0(data0), _1(data1)						\
			{}									\
		private:								\
			bool valid() const							\
			{									\
				return true;							\
			}									\
			\
			return_type call args_list const					\
			{									\
				__VA_ARGS__;							\
			}									\
			\
			data0_type _0;							\
			data1_type _1;							\
	}

	/** @see {#DPP_DELEGATE2_TYPE, #DPP_DELEGATE1_OBJ} */
# define DPP_DELEGATE2_OBJ(name, return_type, args_list, data0_type, init0, data1_type, init1, ...) \
	DPP_DELEGATE2_TYPE(return_type, args_list, data0_type, data1_type, __VA_ARGS__) \
	name(init0, init1)

#endif

#if DPP_DELEGATE_ARGC >= 3

	/** @see {#DPP_DELEGATE3_OBJ, #DPP_DELEGATE1_TYPE} */
# define DPP_DELEGATE3_TYPE(return_type, args_list, data0_type, data1_type, data2_type, ...) \
	class _DPP_DELEGATE_NAME(__LINE__)					\
		: public dpp::delegate< return_type args_list >			\
	{									\
		public:								\
			_DPP_DELEGATE_NAME(__LINE__)(data0_type data0, data1_type data1, data2_type data2) \
				: _0(data0), _1(data1), _2(data2)					\
			{}									\
		private:								\
			bool valid() const							\
			{									\
				return true;							\
			}									\
			\
			return_type call args_list const					\
			{									\
				__VA_ARGS__;							\
			}									\
			\
			data0_type _0;							\
			data1_type _1;							\
			data2_type _2;							\
	}

	/** @see {#DPP_DELEGATE3_TYPE, #DPP_DELEGATE1_OBJ} */
# define DPP_DELEGATE3_OBJ(name, return_type, args_list, data0_type, init0, data1_type, init1, data2_type, init2, ...)  \
	DPP_DELEGATE3_TYPE(return_type, args_list, data0_type, data1_type, data2_type, __VA_ARGS__)  \
	name(init0, init1, init2)

#endif

#if DPP_DELEGATE_ARGC >= 4

	/** @see {#DPP_DELEGATE4_OBJ, #DPP_DELEGATE1_TYPE} */
# define DPP_DELEGATE4_TYPE(return_type, args_list, data0_type, data1_type, data2_type, data3_type, ...) \
	class _DPP_DELEGATE_NAME(__LINE__)					\
		: public dpp::delegate< return_type args_list >			\
	{									\
		public:								\
			_DPP_DELEGATE_NAME(__LINE__)(data0_type data0, data1_type data1, data2_type data2, data3_type data3) \
				: _0(data0), _1(data1), _2(data2), _3(data3)			\
			{}									\
		private:								\
			bool valid() const							\
			{									\
				return true;							\
			}									\
			\
			return_type call args_list const					\
			{									\
				__VA_ARGS__;							\
			}									\
			\
			data0_type _0;							\
			data1_type _1;							\
			data2_type _2;							\
			data3_type _3;							\
	}

	/** @see {#DPP_DELEGATE4_TYPE, #DPP_DELEGATE1_OBJ} */
# define DPP_DELEGATE4_OBJ(name, return_type, args_list, data0_type, init0, data1_type, init1, data2_type, init2, data3_type, init3, ...)  \
	DPP_DELEGATE4_TYPE(return_type, args_list, data0_type, data1_type, data2_type, data3_type, __VA_ARGS__)  \
	name(init0, init1, init2, init3)

#endif

#if DPP_DELEGATE_ARGC >= 5 // mkdoc:skip

	/** @see {#DPP_DELEGATE5_OBJ, #DPP_DELEGATE1_TYPE} */
# define DPP_DELEGATE5_TYPE(return_type, args_list, data0_type, data1_type, data2_type, data3_type, data4_type, ...) \
	class _DPP_DELEGATE_NAME(__LINE__)					\
		: public dpp::delegate< return_type args_list >			\
	{									\
		public:								\
			_DPP_DELEGATE_NAME(__LINE__)(data0_type data0, data1_type data1, data2_type data2, data3_type data3, data4_type data4) \
				: _0(data0), _1(data1), _2(data2), _3(data3), _4(data4)		\
			{}									\
		private:								\
			bool valid() const							\
			{									\
				return true;							\
			}									\
			\
			return_type call args_list const					\
			{									\
				__VA_ARGS__;							\
			}									\
			\
			data0_type _0;							\
			data1_type _1;							\
			data2_type _2;							\
			data3_type _3;							\
			data4_type _4;							\
	}

	/** @see {#DPP_DELEGATE5_TYPE, #DPP_DELEGATE1_OBJ} */
# define DPP_DELEGATE5_OBJ(name, return_type, args_list, data0_type, init0, data1_type, init1, data2_type, init2, data3_type, init3, data4_type, init4, ...)  \
	DPP_DELEGATE5_TYPE(return_type, args_list, data0_type, data1_type, data2_type, data3_type, data4_type, __VA_ARGS__)  \
	name(init0, init1, init2, init3, init4)

#endif

#if DPP_DELEGATE_ARGC >= 6 // mkdoc:skip

	/** @see {#DPP_DELEGATE6_OBJ, #DPP_DELEGATE1_TYPE} */
# define DPP_DELEGATE6_TYPE(return_type, args_list, data0_type, data1_type, data2_type, data3_type, data4_type, data5_type, ...) \
	class _DPP_DELEGATE_NAME(__LINE__)					\
		: public dpp::delegate< return_type args_list >			\
	{									\
		public:								\
			_DPP_DELEGATE_NAME(__LINE__)(data0_type data0, data1_type data1, data2_type data2, data3_type data3, data4_type data4, data5_type data5) \
				: _0(data0), _1(data1), _2(data2), _3(data3), _4(data4), _5(data5) \
			{}									\
		private:								\
			bool valid() const							\
			{									\
				return true;							\
			}									\
			\
			return_type call args_list const					\
			{									\
				__VA_ARGS__;							\
			}									\
			\
			data0_type _0;							\
			data1_type _1;							\
			data2_type _2;							\
			data3_type _3;							\
			data4_type _4;							\
			data5_type _5;							\
	}

	/** @see {#DPP_DELEGATE6_TYPE, #DPP_DELEGATE1_OBJ} */
# define DPP_DELEGATE6_OBJ(name, return_type, args_list, data0_type, init0, data1_type, init1, data2_type, init2, data3_type, init3, data4_type, init4, data5_type, init5, ...)  \
	DPP_DELEGATE6_TYPE(return_type, args_list, data0_type, data1_type, data2_type, data3_type, data4_type, data5_type, __VA_ARGS__)  \
	name(init0, init1, init2, init3, init4, init5)

#endif

#if DPP_DELEGATE_ARGC >= 7 // mkdoc:skip

	/** @see {#DPP_DELEGATE7_OBJ, #DPP_DELEGATE1_TYPE} */
# define DPP_DELEGATE7_TYPE(return_type, args_list, data0_type, data1_type, data2_type, data3_type, data4_type, data5_type, data6_type, ...) \
	class _DPP_DELEGATE_NAME(__LINE__)					\
		: public dpp::delegate< return_type args_list >			\
	{									\
		public:								\
			_DPP_DELEGATE_NAME(__LINE__)(data0_type data0, data1_type data1, data2_type data2, data3_type data3, data4_type data4, data5_type data5, data6_type data6) \
				: _0(data0), _1(data1), _2(data2), _3(data3), _4(data4), _5(data5), _6(data6) \
			{}									\
		private:								\
			bool valid() const							\
			{									\
				return true;							\
			}									\
			\
			return_type call args_list const					\
			{									\
				__VA_ARGS__;							\
			}									\
			\
			data0_type _0;							\
			data1_type _1;							\
			data2_type _2;							\
			data3_type _3;							\
			data4_type _4;							\
			data5_type _5;							\
			data6_type _6;							\
	}

	/** @see {#DPP_DELEGATE7_TYPE, #DPP_DELEGATE1_OBJ} */
# define DPP_DELEGATE7_OBJ(name, return_type, args_list, data0_type, init0, data1_type, init1, data2_type, init2, data3_type, init3, data4_type, init4, data5_type, init5, data6_type, init6, ...)  \
	DPP_DELEGATE7_TYPE(return_type, args_list, data0_type, data1_type, data2_type, data3_type, data4_type, data5_type, data6_type, __VA_ARGS__)  \
	name(init0, init1, init2, init3, init4, init5, init6)

#endif

#if DPP_DELEGATE_ARGC >= 8 // mkdoc:skip

	/** @see {#DPP_DELEGATE8_OBJ, #DPP_DELEGATE1_TYPE} */
# define DPP_DELEGATE8_TYPE(return_type, args_list, data0_type, data1_type, data2_type, data3_type, data4_type, data5_type, data6_type, data7_type, ...) \
	class _DPP_DELEGATE_NAME(__LINE__)					\
		: public dpp::delegate< return_type args_list >			\
	{									\
		public:								\
			_DPP_DELEGATE_NAME(__LINE__)(data0_type data0, data1_type data1, data2_type data2, data3_type data3, data4_type data4, data5_type data5, data6_type data6, data7_type data7) \
				: _0(data0), _1(data1), _2(data2), _3(data3), _4(data4), _5(data5), _6(data6), _7(data7) \
			{}									\
		private:								\
			bool valid() const							\
			{									\
				return true;							\
			}									\
			\
			return_type call args_list const					\
			{									\
				__VA_ARGS__;							\
			}									\
			\
			data0_type _0;							\
			data1_type _1;							\
			data2_type _2;							\
			data3_type _3;							\
			data4_type _4;							\
			data5_type _5;							\
			data6_type _6;							\
			data7_type _7;							\
	}

	/** @see {#DPP_DELEGATE8_TYPE, #DPP_DELEGATE1_OBJ} */
# define DPP_DELEGATE8_OBJ(name, return_type, args_list, data0_type, init0, data1_type, init1, data2_type, init2, data3_type, init3, data4_type, init4, data5_type, init5, data6_type, init6, data7_type, init7, ...)  \
	DPP_DELEGATE8_TYPE(return_type, args_list, data0_type, data1_type, data2_type, data3_type, data4_type, data5_type, data6_type, data7_type, __VA_ARGS__)  \
	name(init0, init1, init2, init3, init4, init5, init6, init7)

#endif

}

#endif

