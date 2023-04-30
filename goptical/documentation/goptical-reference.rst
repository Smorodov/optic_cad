This manual is for GNU <goptical/core.  Copyright (C) 2010-2011 Free Software
Foundation, Inc.

     Copyright (C) 2010-2011 Free Software Foundation, Inc. Permission
     is granted to copy, distribute and/or modify this document under
     the terms of the GNU Free Documentation License, Version 1.3 or
     any later version published by the Free Software Foundation; with
     no Invariant Sections, no Front-Cover Texts, and no Back-Cover
     Texts. A copy of the license is included in the section entitled
     "GNU Free Documentation License".

     Author: Alexandre Becoulet

4 API documentation
*******************

* Menu:

* Modules::
* Namespaces list::
* Classes list::
* Main classes::

4.1 Modules
===========

Name                   Description
-------------------------------------------------------------------------- 
Core                   <goptical/core core classes
Design                 Parametrizable optical designs classes

4.2 Namespaces list
===================

Name                   Description
-------------------------------------------------------------------------- 
analysis               Optical systems analysis tools
curve                  Surface curvature models
data                   Numerical data interpolation and plotting
Design                 Design module classes
io                     data input/output and graphical rendering
light                  Physical properties of light
material               material models for optical components
math                   mathematical tools and functions
shape                  2d shapes used for surface contours
sys                    Optical system and components
trace                  Ray tracer and light propagation

4.3 Classes list
================

Name                        Description
-------------------------------------------------------------------------- 
analysis::focus             Best focus point analysis
analysis::RayFan            RayFan diagram analysis
analysis::spot              spot diagram analysis
curve::Array                Enable definition of curve as square and
                            hexagonal array of an other curve
curve::Base                 Base class for surface curvature models
curve::Composer             Enable definition of curve as composition of
                            other curves
curve::Composer::Attributes curve::Composer base curve attributes.
curve::Conic                General purpose conic curve model
curve::Flat                 Flat curve
curve::Foucault             Define surface curve from Foucault test data.
curve::Grid                 Define surface curve from interpolated grid
                            data set.
curve::Parabola             Parabola curve model
curve::Polynomial           Even and odd polynomial curve implementation.
curve::Sphere               Spherical curve model
curve::Spline               rotationally symmetric spline curve
                            implementation
curve::Zernike              Define surface curve from Zernike polynomials
curve::ConicBase            Base class for conic family of curves
curve::curveRoc             Base class for curves with a radius of
                            curvature
curve::rotational           Base class for rotationally symmetric curves.
data::DiscreteSet           1d numerical data set with interpolation
data::Grid                  2d numerical data set with interpolation.
data::Plot                  data plots container
data::Plotdata              data set plot
data::SampleSet             1d fixed interval numerical data set with
                            interpolation
data::Set                   Base class for numerical data sets.
data::Set1d                 Base class for 1d y = f(x) numerical data set
Design::telescope::CassegrainCassegrain telescopes model
Design::telescope::Newton   Newton telescope optical design
Design::telescope::telescopeBase class for telescope optical designs
Error                       Base class used for <goptical/core exceptions.
io::ImportOslo              Oslo files loader
io::ImportZemax             Zemax files loader (experimental)
io::Renderer                Base class for rendering drivers
io::RendererDxf             DXF rendering driver base (experimental)
io::RendererGd              GD rendering driver
io::RendererOpengl          OpenGL rendering driver
io::renderer_pl_plot          Plplot rendering driver
io::renderer_svg             SVG file rendering driver
io::RendererX11             X11 rendering driver
io::RendererX3d             X3d rendering driver (experimental)
io::Export                  File export class interface
io::Import                  File import class interface
io::RendererAxes            RendererAxes rendering descriptor
io::renderer_viewport        Base class for viewport based rendering
                            drivers
io::rgb                     RGB color descriptor
light::Ray                  Describe a ray of light
light::SpectralLine         Describe a spectral line
material::Abbe              Abbe model for optical glass material
material::Air               Air optical material model
material::Base              Optical material base class.
material::Catalog           Hold a glass material catalog
material::Conrady           Conrady model for optical glass material
material::DispersionTable   Interpolated refractive index data set model
material::Herzberger        Herzberger model for optical glass material
material::Metal             Metal optical material model.
material::Mil               Mil glass code material model
material::mirror            Simple mirror optical material model.
material::Schott            Schott model for optical glass material
material::Sellmeier         Sellmeier model for optical glass material
material::SellmeierMod      Modified sellmeier model for optical glass
                            material
material::Vacuum            Vacuum optical material model
material::Dielectric        Dielectric optical material model base class.
material::Proxy             Optical material proxy class.
material::Solid             Solid optical material base class.
math::Matrix                NxN square matrix class.
math::Quaternion            Quaternion class.
math::Transform<3>          3d linear and affine transformation class.
math::Transform<2>          2d linear and affine transformation class.
math::Triangle              N dimension triangle class
math::Triangle<3>           3d triangle class
math::vector                N dimension vector class
math::vector<3, T>          3d vector class
math::vector<2, T>          2d vector class
math::vectorPair            vector pair class
math::vectorPair<2>         vector pair class
math::vectorPair<3>         vector pair class
shape::Base                 Base class for contour 2d shapes
shape::Composer             Enable definition of shape as composition ot
                            other shapes (experimental)
shape::Composer::Attributes Enable definition of shape as composition ot
                            other shapes (experimental)
shape::disk                 disk shape
shape::Ellipse              Ellipse shape
shape::EllipticalRing       Elliptical ring shape
shape::Infinite             Borderless shape
shape::Polygon              Polygon shape
shape::Rectangle            Rectangle and square shape
shape::RegularPolygon       Regular Polygon shape
shape::Ring                 Ring shape
sys::Group                  Optical elements group element
sys::image                  image plane optical element
sys::Lens                   Lens optical element
sys::mirror                 Reflecting optical surface element
sys::OpticalSurface         Optical surface element
sys::source_point            Point light source
sys::SourceRays             Custom rays light source
sys::system                 Optical system
sys::Container              Base class for system and Group
sys::Element                Optical element base class
sys::Source                 Base class for light sources
sys::Stop                   Aperture stop element
sys::Surface                Base class for surfaces
trace::distribution         Ray distribution pattern descriptor
trace::params               light propagation parameters descriptor
trace::Result               Store light propagation result
trace::sequence             Defines light propagation elemets order for
                            sequential light propagation
trace::tracer               light propagation algorithms
trace::Ray                  Propagated light ray class

4.4 Main classes
================

sys namespace
-------------

Name                   Description
-------------------------------------------------------------------------- 
Group                  Optical elements group element
image                  image plane optical element
Lens                   Lens optical element
mirror                 Reflecting optical surface element
OpticalSurface         Optical surface element
source_point            Point light source
SourceRays             Custom rays light source
system                 Optical system

trace namespace
---------------

Name                   Description
-------------------------------------------------------------------------- 
distribution           Ray distribution pattern descriptor
params                 light propagation parameters descriptor
Result                 Store light propagation result
sequence               Defines light propagation elemets order for
                       sequential light propagation
tracer                 light propagation algorithms

material namespace
------------------

Name                   Description
-------------------------------------------------------------------------- 
Abbe                   Abbe model for optical glass material
Air                    Air optical material model
Base                   Optical material base class.
Catalog                Hold a glass material catalog
Conrady                Conrady model for optical glass material
DispersionTable        Interpolated refractive index data set model
Herzberger             Herzberger model for optical glass material
Metal                  Metal optical material model.
Mil                    Mil glass code material model
mirror                 Simple mirror optical material model.
Schott                 Schott model for optical glass material
Sellmeier              Sellmeier model for optical glass material
SellmeierMod           Modified sellmeier model for optical glass
                       material
Vacuum                 Vacuum optical material model

io namespace
------------

Name                   Description
-------------------------------------------------------------------------- 
ImportOslo             Oslo files loader
ImportZemax            Zemax files loader (experimental)
Renderer               Base class for rendering drivers
RendererDxf            DXF rendering driver base (experimental)
RendererGd             GD rendering driver
RendererOpengl         OpenGL rendering driver
renderer_pl_plot         Plplot rendering driver
renderer_svg            SVG file rendering driver
RendererX11            X11 rendering driver
RendererX3d            X3d rendering driver (experimental)

data namespace
--------------

Name                   Description
-------------------------------------------------------------------------- 
DiscreteSet            1d numerical data set with interpolation
Grid                   2d numerical data set with interpolation.
Plot                   data plots container
Plotdata               data set plot
SampleSet              1d fixed interval numerical data set with
                       interpolation

math namespace
--------------

Name                   Description
-------------------------------------------------------------------------- 
vector2                
vector3                
vectorPair3            

shape namespace
---------------

Name                   Description
-------------------------------------------------------------------------- 
Base                   Base class for contour 2d shapes
Composer               Enable definition of shape as composition ot
                       other shapes (experimental)
disk                   disk shape
Ellipse                Ellipse shape
EllipticalRing         Elliptical ring shape
Infinite               Borderless shape
Polygon                Polygon shape
Rectangle              Rectangle and square shape
RegularPolygon         Regular Polygon shape
Ring                   Ring shape

light namespace
---------------

Name                   Description
-------------------------------------------------------------------------- 
Ray                    Describe a ray of light

curve namespace
---------------

Name                   Description
-------------------------------------------------------------------------- 
Array                  Enable definition of curve as square and
                       hexagonal array of an other curve
Base                   Base class for surface curvature models
Composer               Enable definition of curve as composition of
                       other curves
Conic                  General purpose conic curve model
Flat                   Flat curve
Foucault               Define surface curve from Foucault test data.
Grid                   Define surface curve from interpolated grid data
                       set.
Parabola               Parabola curve model
Polynomial             Even and odd polynomial curve implementation.
Sphere                 Spherical curve model
Spline                 rotationally symmetric spline curve implementation
Zernike                Define surface curve from Zernike polynomials

analysis namespace
------------------

Name                   Description
-------------------------------------------------------------------------- 
focus                  Best focus point analysis
RayFan                 RayFan diagram analysis
spot                   spot diagram analysis

::Core module reference
=======================

Description
-----------

Classes from this module are located in the `<goptical/core-core' subpackage
(`<goptical/core' library).

Members
-------

Namespaces
..........

   * <goptical/core::analysis

   * <goptical/core::curve

   * <goptical/core::data

   * <goptical/core::io

   * <goptical/core::light

   * <goptical/core::material

   * <goptical/core::math

   * <goptical/core::shape

   * <goptical/core::sys

   * <goptical/core::trace

Types
.....

   * template class Abbe

   * template class Air

   * class Array

   * class Base

   * class Base

   * class Base

   * class Catalog

   * class Composer

   * class Composer

   * class Conic

   * class Conrady

   * class DiscreteSet

   * class disk

   * class DispersionTable

   * class distribution

   * class Ellipse

   * class EllipticalRing

   * class Flat

   * class focus

   * class Foucault

   * class Grid

   * class Grid

   * class Group

   * class Herzberger

   * class image

   * class ImportOslo

   * class ImportZemax

   * class Infinite

   * class Lens

   * class Metal

   * class Mil

   * class mirror

   * class mirror

   * class OpticalSurface

   * class Parabola

   * class params

   * class Plot

   * class Plotdata

   * class Polygon

   * class Polynomial

   * class Ray

   * class RayFan

   * class Rectangle

   * class RegularPolygon

   * class Renderer

   * class RendererDxf

   * class RendererGd

   * class RendererOpengl

   * class renderer_pl_plot

   * class renderer_svg

   * class RendererX11

   * class RendererX3d

   * class Result

   * class Ring

   * class SampleSet

   * class Schott

   * class Sellmeier

   * template class SellmeierMod

   * class sequence

   * class source_point

   * class SourceRays

   * class Sphere

   * class Spline

   * class spot

   * class system

   * class tracer

   * class Vacuum

   * typedef _ [...] _ vector2

   * typedef _ [...] _ vector3

   * typedef _ [...] _ vectorPair3

   * class Zernike

   * typedef _ [...] _ AbbeVd

   * typedef _ [...] _ AbbeVe

   * typedef _ [...] _ AirBirch94

   * typedef _ [...] _ AirKohlrausch68

   * class Attributes

   * class Attributes

   * class ConicBase

   * class Container

   * class curveRoc

   * class Dielectric

   * class Element

   * class Error

   * class Export

   * typedef _ [...] _ Handbook1

   * typedef _ [...] _ Handbook2

   * class Import

   * template struct Matrix

   * typedef _ [...] _ Matrix3x3

   * class Proxy

   * class Quaternion

   * class Ray

   * class RendererAxes

   * class renderer_viewport

   * struct rgb

   * class rotational

   * typedef _ [...] _ SellmeierMod2

   * class Set

   * class Set1d

   * class Solid

   * class Source

   * class SpectralLine

   * class Stop

   * class Surface

   * template class Transform<2>

   * template class Transform<3>

   * typedef _ [...] _ Transform2

   * typedef _ [...] _ Transform3

   * template struct Triangle

   * template struct Triangle<3>

   * template struct vector

   * template struct vector<2, T>

   * template struct vector<3, T>

   * template struct vectorPair

   * template struct vectorPair<2>

   * template struct vectorPair<3>

   * typedef _ [...] _ vectorPair2

   * typedef _ [...] _ range_t

   * typedef _ [...] _ rays_queue_t

Functions
.........

   * double degree2rad(double x)

   * void get_rotation_matrix(<goptical/core::math::Matrix<2> &m, unsigned
     int axis, double rangle)

   * void get_rotation_matrix(<goptical/core::math::Matrix<3> &m, unsigned
     int axis, double rangle)

   * double lp_floor(double x, double n)

   * double lp_mod(double x, double n)

   * template std::ostream & operator<<(std::ostream &o, const
     <goptical/core::math::vectorBase<N, T> &v)

   * template std::ostream & operator<<(std::ostream &o, const
     <goptical/core::math::vectorPairBase<N> &l)

   * template std::ostream & operator<<(std::ostream &o, const
     <goptical/core::math::Matrix<N> &m)

   * std::ostream & operator<<(std::ostream &o, const
     <goptical/core::math::Quaternion &q)

   * template std::ostream & operator<<(std::ostream &o, const
     <goptical/core::math::TransformBase<N> &t)

   * std::ostream & operator<<(std::ostream &o, const
     <goptical/core::sys::Element &e)

   * template std::ostream & operator<<(std::ostream &o, const
     <goptical/core::math::Triangle<N> &l)

   * std::ostream & operator<<(std::ostream &o, const
     <goptical/core::trace::sequence &s)

   * std::ostream & operator<<(std::ostream &o, const
     <goptical/core::sys::Container &v)

   * std::ostream & operator<<(std::ostream &o, const
     <goptical/core::data::Set &s)

   * double rad2degree(double x)

   * double square(double x)

Constants
.........

   * const dpp::const_ref<goptical/core::material::Base> none

   * const <goptical/core::io::rgb rgb_black

   * const <goptical/core::io::rgb rgb_blue

   * const <goptical/core::io::rgb rgb_cyan

   * const <goptical/core::io::rgb rgb_gray

   * const <goptical/core::io::rgb rgb_green

   * const <goptical/core::io::rgb rgb_magenta

   * const <goptical/core::io::rgb rgb_red

   * const <goptical/core::io::rgb rgb_table[]

   * const size_t rgb_table_size

   * const <goptical/core::io::rgb rgb_white

   * const <goptical/core::io::rgb rgb_yellow

   * const <goptical/core::material::AirBirch94 std_air

   * const <goptical/core::math::vector2 vector2_0

   * const <goptical/core::math::vector2 vector2_01

   * const <goptical/core::math::vector2 vector2_1

   * const <goptical/core::math::vector2 vector2_10

   * const <goptical/core::math::vectorPair<2> vector2_pair_00

   * const <goptical/core::math::vectorPair<2> vector2_pair_01

   * const <goptical/core::math::vector3 vector3_0

   * const <goptical/core::math::vector3 vector3_001

   * const <goptical/core::math::vector3 vector3_010

   * const <goptical/core::math::vector3 vector3_1

   * const <goptical/core::math::vector3 vector3_100

   * const <goptical/core::math::vectorPair<3> vector3_pair_00

   * const <goptical/core::math::vectorPair<3> vector3_pair_01

Variables
.........

   * <goptical/core::material::AirBirch94 air

   * <goptical/core::curve::Flat flat

   * <goptical/core::shape::Infinite infinite

   * <goptical/core::material::mirror mirror

   * <goptical/core::material::Vacuum vacuum

::Design module reference
=========================

Description
-----------

This module contains various optical design models.

   Classes from this module are located in the `<goptical/core-design'
subpackage (`<goptical/core_design' library).

Members
-------

Namespace
.........

   * <goptical/core::Design

Types
.....

   * template class Cassegrain

   * class Newton

   * class telescope

<goptical/core namespace reference
============================

Description
-----------

<goptical/core library namespace

Members
-------

Namespaces
..........

   * analysis

   * curve

   * data

   * Design

   * io

   * light

   * material

   * math

   * shape

   * sys

   * trace

Type
....

   * class Error

analysis namespace reference
============================

Description
-----------

Optical systems analysis tools

Members
-------

Types
.....

   * class focus

   * class RayFan

   * class spot

analysis::focus class reference
===============================

Declaration
-----------

     #include <goptical/core/analysis/focus>

     namespace goptical {
       namespace analysis {
         class focus;
       };
     };

   This class is a member of the analysis namespace.

Description
-----------

This class is designed to find the best point of focus of an optical
system.

Members
-------

See also the full member list (*note
analysis_focus_class_full_member_list::) section for this class.

Functions
.........

   * focus(sys::system &system)

   * const math::vectorPair3 & get_best_focus()

   * trace::tracer & get_tracer()

   * const trace::tracer & get_tracer() const

   * virtual void invalidate()

   * void set_image(sys::image *image)

Members detail
--------------

focus(sys::system &system)
..........................

No documentation available

const math::vectorPair3 & get_best_focus()
..........................................

Get best point of focus in system global coordinates.

virtual void invalidate()
.........................

This virtual function implements the `invalidate (*note _31::)' pure
function declared in the `Pointimage' base abstract class.

   Documentation inherited from base class:

   invalidate current analysis data

analysis::focus class full member list
======================================

Functions
---------

   * focus(sys::system &system)

   * const math::vectorPair3 & get_best_focus()

   * trace::tracer & get_tracer()

   * const trace::tracer & get_tracer() const

   * virtual void invalidate()

   * void set_image(sys::image *image)

analysis::RayFan class reference
================================

Declaration
-----------

     #include <goptical/core/analysis/RayFan>

     namespace goptical {
       namespace analysis {
         class RayFan;
       };
     };

   This class is a member of the analysis namespace.

Description
-----------

This class is designed to compute various ray fan plots.

   See also Performing a ray fan analysis (*note Performing a ray fan
analysis::) section and Plotting ray fans (*note Plotting ray fans::)
section.

Members
-------

See also the full member list (*note
analysis_RayFan_class_full_member_list::) section for this class.

Types
.....

   * enum rayfan_plane_e

   * enum rayfan_plot_type_e

Functions
.........

   * RayFan(const sys::system &system, rayfan_plane_e plane = _[...]_)

   * trace::distribution & get_distribution()

   * ref<data::Plot> get_plot(rayfan_plot_type_e x, rayfan_plot_type_e
     y)

   * void invalidate()

   * void set_aberration_plane(rayfan_plane_e plane)

   * void set_entrance_surface(const sys::Surface &s)

   * void set_longitudinal_reference(const math::vectorPair3 &ref)

   * void set_plane(rayfan_plane_e plane)

   * void set_target_surface(const sys::Surface &s)

Members detail
--------------

RayFan(const sys::system &system, rayfan_plane_e plane = TangentialAberration)
..............................................................................

No documentation available

trace::distribution & get_distribution()
........................................

Get internal distribution object

ref <data::Plot> get_plot(rayfan_plot_type_e x, rayfan_plot_type_e y)
.....................................................................

Get aberration plot, requested x value is plotted against requested y
value.

void invalidate()
.................

Invalidate current analysis data and raytrace again on next plot request

enum rayfan_plane_e
...................

Specify aberration analysis plane on target surface

Identifier             Description
-------------------------------------------------------------------------- 
SagittalAberration     
TangentialAberration   

enum rayfan_plot_type_e
.......................

Specify ray aberration values to plot. Angle and Distance aberrations
values are considered in selected aberration plane. Entrance Height and
Angle are considered in selected distribution plane.

Identifier             Description
-------------------------------------------------------------------------- 
EntranceHeight          Normalized ray height (radial distance) on
                       entrance pupil
EntranceAngle           Angle of ray on entrance pupil
TransverseDistance      Distance on the surface from the intercept of
                       the chief ray
LongitudinalDistance    Distance along the chief ray from the surface to
                       the measured ray.
imageAngle              Angle of ray striking the target surface
ExitAngle               Angle of ray leaving (generated by) the target
                       surface
OpticalPathDiff         Optical path difference in waves

void set_aberration_plane(rayfan_plane_e plane)
...............................................

Aberrations are considered in the given plane on the target surface.
Default is to use the same plane as entrance pupil ray distribution
plane.

void set_entrance_surface(const sys::Surface &s)
................................................

Specify entrance pupil surface to use for analysis, query system for
entrance pupil if none defined here.

void set_longitudinal_reference(const math::vectorPair3 &ref)
.............................................................

Set longitudinal reference ray (local to target surface). Longitudinal
aberration computes distance between each rays and target surface plane
along this reference vector. Default value is along the Z axis.

void set_plane(rayfan_plane_e plane)
....................................

Set entrance pupil ray distribution plane.

void set_target_surface(const sys::Surface &s)
..............................................

Specify target surface (image or exit pupil) to use for analysis, query
system for image surface if none defined here.

analysis::RayFan class full member list
=======================================

Types
-----

   * enum rayfan_plane_e

   * enum rayfan_plot_type_e

Functions
---------

   * RayFan(const sys::system &system, rayfan_plane_e plane = _[...]_)

   * trace::distribution & get_distribution()

   * ref<data::Plot> get_plot(rayfan_plot_type_e x, rayfan_plot_type_e
     y)

   * void invalidate()

   * void set_aberration_plane(rayfan_plane_e plane)

   * void set_entrance_surface(const sys::Surface &s)

   * void set_longitudinal_reference(const math::vectorPair3 &ref)

   * void set_plane(rayfan_plane_e plane)

   * void set_target_surface(const sys::Surface &s)

analysis::spot class reference
==============================

Declaration
-----------

     #include <goptical/core/analysis/spot>

     namespace goptical {
       namespace analysis {
         class spot;
       };
     };

   This class is a member of the analysis namespace.

Description
-----------

This class is designed to plot spot diagram and perform related
analysis.

   See also Plotting spot diagram (*note Plotting spot diagram::)
section and Using the new model in optical design (*note Using the new
model in optical design::) section.

Members
-------

See also the full member list (*note
analysis_spot_class_full_member_list::) section for this class.

Functions
.........

   * spot(sys::system &system)

   * void draw_diagram(io::renderer_viewport &renderer, bool
     centroid_origin = _[...]_)

   * void draw_spot(io::renderer_viewport &renderer)

   * math::vector3 get_center()

   * const math::vector3 & get_centroid()

   * io::RendererAxes & get_diagram_axes()

   * double get_encircled_intensity(double radius)

   * ref<data::Plot> get_encircled_intensity_plot(int zones = _[...]_)

   * double get_max_radius()

   * double get_rms_radius()

   * double get_total_intensity()

   * trace::tracer & get_tracer()

   * const trace::tracer & get_tracer() const

   * virtual void invalidate()

   * void set_image(sys::image *image)

   * void set_useful_radius(double radius)

Members detail
--------------

spot(sys::system &system)
.........................

No documentation available

void draw_diagram(io::renderer_viewport &renderer, bool centroid_origin = true)
..............................................................................

draw the spot diagram

void draw_spot(io::renderer_viewport &renderer)
..............................................

draw the rays intersection points only

math::vector3 get_center()
..........................

Get spot window center

const math::vector3 & get_centroid()
....................................

Get spot centroid

io::RendererAxes & get_diagram_axes()
.....................................

Get a reference to axes object rendered with spot diagram.
io::RendererAxes (*note io_RendererAxes_class_reference::) coordinates
are updated on ray trace.

double get_encircled_intensity(double radius)
.............................................

Get amount of light intensity which falls in given radius from spot
center

ref <data::Plot> get_encircled_intensity_plot(int zones = 100)
..............................................................

Get encircled energy plot

double get_max_radius()
.......................

Get spot maximum radius

double get_rms_radius()
.......................

Get spot root mean square radius

double get_total_intensity()
............................

Get amount of light intensity in the whole spot

virtual void invalidate()
.........................

This virtual function implements the `invalidate (*note _31::)' pure
function declared in the `Pointimage' base abstract class.

   Documentation inherited from base class:

   invalidate current analysis data

void set_useful_radius(double radius)
.....................................

Set radius used for diagram drawing and encircled plots. Updated with
spot max radius on ray trace

analysis::spot class full member list
=====================================

Functions
---------

   * spot(sys::system &system)

   * void draw_diagram(io::renderer_viewport &renderer, bool
     centroid_origin = _[...]_)

   * void draw_spot(io::renderer_viewport &renderer)

   * math::vector3 get_center()

   * const math::vector3 & get_centroid()

   * io::RendererAxes & get_diagram_axes()

   * double get_encircled_intensity(double radius)

   * ref<data::Plot> get_encircled_intensity_plot(int zones = _[...]_)

   * double get_max_radius()

   * double get_rms_radius()

   * double get_total_intensity()

   * trace::tracer & get_tracer()

   * const trace::tracer & get_tracer() const

   * virtual void invalidate()

   * void set_image(sys::image *image)

   * void set_useful_radius(double radius)

analysis::Pointimage internal class members
===========================================

Pointimage(sys::system &system)
-------------------------------

No documentation available

virtual ~Pointimage()
---------------------

No documentation available

trace::tracer & get_tracer()
----------------------------

return tracer object used for ray tracing. This will invalidate current
analysis data

const trace::tracer & get_tracer() const
----------------------------------------

return tracer object used for ray tracing

virtual void invalidate() = 0;
------------------------------

invalidate current analysis data

void set_image(sys::image *image)
---------------------------------

set image which collect rays for analysis

curve namespace reference
=========================

Description
-----------

Surface curvature models

Members
-------

Types
.....

   * class Array

   * class Base

   * class Composer

   * class Conic

   * class Flat

   * class Foucault

   * class Grid

   * class Parabola

   * class Polynomial

   * class Sphere

   * class Spline

   * class Zernike

   * class ConicBase

   * class curveRoc

   * class rotational

Variable
........

   * Flat flat

Members detail
--------------

Flat flat
.........

Preallocated flat curve object

curve::Array class reference
============================

Declaration
-----------

     #include <goptical/core/curve/Array>

     namespace goptical {
       namespace curve {
         class Array;
       };
     };

   This class is a member of the curve namespace.

Inheritance
-----------

Description
-----------

This class provides a way to build an array of an other curve. It can
be used to design lenses array.

Members
-------

See also the full member list (*note
curve_Array_class_full_member_list::) section for this class.

Inherited members
.................

   * 5 members inherited from Base (*note curve_Base_class_reference::)

Type
....

   * enum pattern_e

Functions
.........

   * Array(const const_ref<Base> &curve, double pitch, pattern_e p =
     _[...]_)

   * virtual void derivative(const math::vector2 &xy, math::vector2
     &dxdy) const

   * virtual double sagitta(const math::vector2 &xy) const

Members detail
--------------

Array(const  const_ref <Base> &curve, double pitch, pattern_e p = Square)
.........................................................................

No documentation available

virtual void derivative(const math::vector2 &xy, math::vector2 &dxdy) const
...........................................................................

This virtual function overrides the `derivative (*note _39::)' virtual
function defined in the `Base (*note curve_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get curve x and y derivative (gradient) at specified point

enum pattern_e
..............

Specify tessellation pattern used by Array (*note
curve_Array_class_reference::) class

Identifier             Description
-------------------------------------------------------------------------- 
Square                 
SquareCenter           
Hexagonal              

virtual double sagitta(const math::vector2 &xy) const
.....................................................

This virtual function implements the `sagitta (*note _42::)' pure
function declared in the `Base (*note curve_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get curve sagitta at specified point

curve::Array class full member list
===================================

Type
----

   * enum pattern_e

Functions
---------

   * Array(const const_ref<Base> &curve, double pitch, pattern_e p =
     _[...]_)

   * virtual void derivative(const math::vector2 &xy, math::vector2
     &dxdy) const

   * virtual bool intersect(math::vector3 &point, const
     math::vectorPair3 &ray) const

   * virtual void normal(math::vector3 &normal, const math::vector3
     &point) const

   * virtual double sagitta(const math::vector2 &xy) const

curve::Base class reference
===========================

Declaration
-----------

     #include <goptical/core/curve/Base>

     namespace goptical {
       namespace curve {
         class Base;
       };
     };

   This class is a member of the curve namespace.

   This abstract class contains pure virtuals.

Inheritance
-----------

Description
-----------

This class defines an interface for surface curvature implementations.
Curvature is defined as a surface curve in three dimensional space. It
is mainly used by the sys::Surface (*note
sys_Surface_class_reference::) class to describe optical surface
curvature.

   It provides access to sagitta (z) and gradient data on any curved
surface point (x, y). Ability to find point of intersection between a
given 3d ray and the curve is also provided.

   See also A custom surface curve model (*note A custom surface curve
model::) section.

Members
-------

See also the full member list (*note
curve_Base_class_full_member_list::) section for this class.

Functions
.........

   * virtual ~Base()

   * virtual void derivative(const math::vector2 &xy, math::vector2
     &dxdy) const

   * virtual bool intersect(math::vector3 &point, const
     math::vectorPair3 &ray) const

   * virtual void normal(math::vector3 &normal, const math::vector3
     &point) const

   * virtual double sagitta(const math::vector2 &xy) const = 0;

Members detail
--------------

virtual ~Base()
...............

No documentation available

virtual void derivative(const math::vector2 &xy, math::vector2 &dxdy) const
...........................................................................

Get curve x and y derivative (gradient) at specified point

virtual bool intersect(math::vector3 &point, const math::vectorPair3 &ray) const
................................................................................

Get intersection point between curve and 3d ray. Return false if no
intersection occurred

virtual void normal(math::vector3 &normal, const math::vector3 &point) const
............................................................................

Get normal to curve surface at specified point

virtual double sagitta(const math::vector2 &xy) const = 0;
..........................................................

Get curve sagitta at specified point

curve::Base class full member list
==================================

Functions
---------

   * virtual ~Base()

   * virtual void derivative(const math::vector2 &xy, math::vector2
     &dxdy) const

   * virtual bool intersect(math::vector3 &point, const
     math::vectorPair3 &ray) const

   * virtual void normal(math::vector3 &normal, const math::vector3
     &point) const

   * virtual double sagitta(const math::vector2 &xy) const = 0;

curve::Composer class reference
===============================

Declaration
-----------

     #include <goptical/core/curve/Composer>

     namespace goptical {
       namespace curve {
         class Composer;
       };
     };

   This class is a member of the curve namespace.

Inheritance
-----------

Description
-----------

This class allows definition of a surface curve using the sum of
several base curves. Each base curve involved can be translated,
rotated and scaled individually.

Members
-------

See also the full member list (*note
curve_Composer_class_full_member_list::) section for this class.

Inherited members
.................

   * 5 members inherited from Base (*note curve_Base_class_reference::)

Type
....

   * class Attributes

Functions
.........

   * Composer()

   * Attributes & add_curve(const const_ref<Base> &curve)

   * virtual void derivative(const math::vector2 &xy, math::vector2
     &dxdy) const

   * virtual double sagitta(const math::vector2 &xy) const

Members detail
--------------

Composer()
..........

No documentation available

Attributes & add_curve(const  const_ref <Base> &curve)
......................................................

Add a base curve to use for composition. The returned
Composer::Attributes object may be used to apply base curve
transformations.

virtual void derivative(const math::vector2 &xy, math::vector2 &dxdy) const
...........................................................................

This virtual function overrides the `derivative (*note _39::)' virtual
function defined in the `Base (*note curve_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get curve x and y derivative (gradient) at specified point

virtual double sagitta(const math::vector2 &xy) const
.....................................................

This virtual function implements the `sagitta (*note _42::)' pure
function declared in the `Base (*note curve_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get curve sagitta at specified point

curve::Composer class full member list
======================================

Type
----

   * class Attributes

Functions
---------

   * Composer()

   * Attributes & add_curve(const const_ref<Base> &curve)

   * virtual void derivative(const math::vector2 &xy, math::vector2
     &dxdy) const

   * virtual bool intersect(math::vector3 &point, const
     math::vectorPair3 &ray) const

   * virtual void normal(math::vector3 &normal, const math::vector3
     &point) const

   * virtual double sagitta(const math::vector2 &xy) const

curve::Composer::Attributes class reference
===========================================

Declaration
-----------

     #include <goptical/core/curve/Composer>

     namespace goptical {
       namespace curve {
         class Composer {
           class Attributes;
         };
       };
     };

   This class is a member of the Composer class.

Description
-----------

This class enables access to Composer base curve transformations.
Sagitta (z) scaling and (x, y) affine transforms (translation,
rotation, scaling) can be applied as needed in any order.

Members
-------

See also the full member list (*note
curve_Composer_Attributes_class_full_member_list::) section for this
class.

Functions
.........

   * Attributes & rotate(double dangle)

   * Attributes & xy_scale(const math::vector2 &factor)

   * Attributes & xy_translate(const math::vector2 &offset)

   * Attributes & z_offset(double zoffset)

   * Attributes & z_scale(double zfactor)

Members detail
--------------

Attributes & rotate(double dangle)
..................................

Apply rotation affine transform. Angle is in degree.

Attributes & xy_scale(const math::vector2 &factor)
..................................................

Apply scaling affine transform using scale factors (xscale, yscale)

Attributes & xy_translate(const math::vector2 &offset)
......................................................

Apply translation transform

Attributes & z_offset(double zoffset)
.....................................

Apply sagitta (z) offset. default is 0

Attributes & z_scale(double zfactor)
....................................

Apply sagitta (z) scale factor. default is 1

curve::Composer::Attributes class full member list
==================================================

Functions
---------

   * Attributes & rotate(double dangle)

   * Attributes & xy_scale(const math::vector2 &factor)

   * Attributes & xy_translate(const math::vector2 &offset)

   * Attributes & z_offset(double zoffset)

   * Attributes & z_scale(double zfactor)

curve::Conic class reference
============================

Declaration
-----------

     #include <goptical/core/curve/Conic>

     namespace goptical {
       namespace curve {
         class Conic;
       };
     };

   This class is a member of the curve namespace.

Inheritance
-----------

Description
-----------

This class models a rotationally symmetric conic curves with given
radius of curvature and deformation coefficient. The later can be
provided either as Schwarzschild constant or Eccentricity value.

   Fitting can be used to find best fit conic of an other rotationally
symmetric curve either with fixed or free deformation parameter.

   Sphere (*note curve_Sphere_class_reference::) and Parabola (*note
curve_Parabola_class_reference::) offer optimized implementations for
common special cases.

Members
-------

See also the full member list (*note
curve_Conic_class_full_member_list::) section for this class.

Inherited members
.................

   * 13 members inherited from ConicBase (*note
     curve_ConicBase_class_reference::)

Functions
.........

   * Conic(double roc, double sc)

   * virtual double derivative(double r) const

   * double fit(const rotational &curve, double radius, unsigned int
     count)

   * virtual bool intersect(math::vector3 &point, const
     math::vectorPair3 &ray) const

   * virtual double sagitta(double r) const

   * void set_eccentricity(double e)

   * void set_schwarzschild(double sc)

Members detail
--------------

Conic(double roc, double sc)
............................

Creates a conic curve with given radius of curvature and Schwarzschild
constant

virtual double derivative(double r) const
.........................................

This virtual function implements the `derivative (*note _130::)' pure
function declared in the `ConicBase (*note
curve_ConicBase_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get curve derivative at specified distance from origin.

   * r: distance from curve origin (0, 0)

double fit(const rotational &curve, double radius, unsigned int count)
......................................................................

Adjust radius of curvature _and_ deformation to best fit given curve

   Parameters list:

   * curve: curve to fit

   * radius: Maximum radius used to get sample points

   * count: Number of sample points to use

virtual bool intersect(math::vector3 &point, const math::vectorPair3 &ray) const
................................................................................

This virtual function implements the `intersect (*note _134::)' pure
function declared in the `ConicBase (*note
curve_ConicBase_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get intersection point between curve and 3d ray. Return false if no
intersection occurred

virtual double sagitta(double r) const
......................................

This virtual function implements the `sagitta (*note _135::)' pure
function declared in the `ConicBase (*note
curve_ConicBase_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get curve sagitta at specified distance from origin.

   * r: distance from curve origin (0, 0)

void set_eccentricity(double e)
...............................

Set eccentricity

void set_schwarzschild(double sc)
.................................

Set Schwarzschild constant

curve::Conic class full member list
===================================

Functions
---------

   * Conic(double roc, double sc)

   * virtual void derivative(const math::vector2 &xy, math::vector2
     &dxdy) const

   * virtual double derivative(double r) const

   * double fit(const rotational &curve, double radius, unsigned int
     count)

   * double fit_roc(const rotational &c, double radius, unsigned int
     count)

   * double get_eccentricity() const

   * double get_roc() const

   * virtual void get_sample(unsigned int index, double &r, double &z)
     const

   * virtual unsigned int get_sample_count() const

   * double get_schwarzschild() const

   * virtual bool intersect(math::vector3 &point, const
     math::vectorPair3 &ray) const

   * virtual void normal(math::vector3 &normal, const math::vector3
     &point) const

   * virtual double sagitta(const math::vector2 &xy) const

   * virtual double sagitta(double r) const

   * void set_eccentricity(double e)

   * void set_roc(double roc)

   * void set_schwarzschild(double sc)

curve::Flat class reference
===========================

Declaration
-----------

     #include <goptical/core/curve/Flat>

     namespace goptical {
       namespace curve {
         class Flat;
       };
     };

   This class is a member of the curve namespace.

Inheritance
-----------

Description
-----------

The global variable flat (*note _33::) provides an instance of this
class.

Members
-------

See also the full member list (*note
curve_Flat_class_full_member_list::) section for this class.

Inherited members
.................

   * 9 members inherited from rotational (*note
     curve_rotational_class_reference::)

Functions
.........

   * Flat()

   * virtual double derivative(double r) const

   * virtual bool intersect(math::vector3 &point, const
     math::vectorPair3 &ray) const

   * virtual void normal(math::vector3 &normal, const math::vector3
     &point) const

   * virtual double sagitta(double r) const

Members detail
--------------

Flat()
......

Creates a flat curve

virtual double derivative(double r) const
.........................................

This virtual function overrides the `derivative (*note _139::)' virtual
function defined in the `rotational (*note
curve_rotational_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get curve derivative at specified distance from origin.

   * r: distance from curve origin (0, 0)

virtual bool intersect(math::vector3 &point, const math::vectorPair3 &ray) const
................................................................................

This virtual function overrides the `intersect (*note _40::)' virtual
function defined in the `Base (*note curve_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get intersection point between curve and 3d ray. Return false if no
intersection occurred

virtual void normal(math::vector3 &normal, const math::vector3 &point) const
............................................................................

This virtual function overrides the `normal (*note _143::)' virtual
function defined in the `rotational (*note
curve_rotational_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get normal to curve surface at specified point

virtual double sagitta(double r) const
......................................

This virtual function implements the `sagitta (*note _144::)' pure
function declared in the `rotational (*note
curve_rotational_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get curve sagitta at specified distance from origin.

   * r: distance from curve origin (0, 0)

curve::Flat class full member list
==================================

Functions
---------

   * Flat()

   * virtual void derivative(const math::vector2 &xy, math::vector2
     &dxdy) const

   * virtual double derivative(double r) const

   * virtual void get_sample(unsigned int index, double &r, double &z)
     const

   * virtual unsigned int get_sample_count() const

   * virtual bool intersect(math::vector3 &point, const
     math::vectorPair3 &ray) const

   * virtual void normal(math::vector3 &normal, const math::vector3
     &point) const

   * virtual double sagitta(const math::vector2 &xy) const

   * virtual double sagitta(double r) const

curve::Foucault class reference
===============================

Declaration
-----------

     #include <goptical/core/curve/Foucault>

     namespace goptical {
       namespace curve {
         class Foucault;
       };
     };

   This class is a member of the curve namespace.

Inheritance
-----------

Description
-----------

This class allows definition of a rotationally symmetric curve from a
set of Foucault test data. Fixed and moving light sources are supported.

   curve fitting can be used to find Foucault test readings from any
other rotationally symmetric curve.

   Foucault test data are reduced using numerical integration of a
differential equation to compute sagitta from slopes.

   Foucault data reduction algorithm based on "ATM mirror mathematics"
http://home.earthlink.net/~burrjaw/atm/atm_math.lwp/atm_math.htm

   Couder mask theory and formulas developed by Nils Olof Carlin
http://www.atmsite.org/contrib/Carlin/couder/

Members
-------

See also the full member list (*note
curve_Foucault_class_full_member_list::) section for this class.

Inherited members
.................

   * 2 members inherited from curveRoc (*note
     curve_curveRoc_class_reference::)

   * 9 members inherited from rotational (*note
     curve_rotational_class_reference::)

Functions
.........

   * Foucault(double roc)

   * ~Foucault()

   * unsigned int add_couder_zones(double hole_radius, unsigned int
     count = _[...]_, std::vector<double> *edge = _[...]_)

   * void add_reading(double zone_radius, double knife_offset = _[...]_)

   * unsigned int add_uniform_zones(double hole_radius, unsigned int
     count)

   * void clear()

   * virtual double derivative(double r) const

   * void fit(const rotational &c)

   * double get_radius() const

   * const std::pair<double, double> get_reading(unsigned int
     zone_number) const

   * unsigned int get_zones_count() const

   * virtual double sagitta(double r) const

   * void set_fixed_source(double source_to_surface)

   * void set_knife_offset(unsigned int zone_number, double
     knife_offset)

   * void set_moving_source(double source_offset = _[...]_)

   * void set_ode_stepsize(double step)

   * void set_radius(double radius)

Members detail
--------------

Foucault(double roc)
....................

Create an empty foucault curve with no reading with the given radius of
curvature

~Foucault()
...........

No documentation available

unsigned int add_couder_zones(double hole_radius, unsigned int count = 0, std:: vector <double> *edge = 0)
..........................................................................................................

Clear current zones and add zones readings to locations suited for
testing with a couder mask (as described on Nils Olof Carlin page).
Zone count may be guessed if zero, provided that radius has been
properly set before. Knife edge reading (offset from radius of
curvature) is set to 0 for all zones.

   * edge: Couder zones edges will be saved here if != NULL.

   The return value is Zone count

void add_reading(double zone_radius, double knife_offset = 0.0)
...............................................................

Define a new zone at given zone radius and update knife edge reading
(offset from radius of curvature)

unsigned int add_uniform_zones(double hole_radius, unsigned int count)
......................................................................

Clear current zones and add equally spaced zones readings. Knife edge
reading (offset from radius of curvature) is set to 0 for all zones.

   The return value is New zones count

void clear()
............

Clear all readings and zones

virtual double derivative(double r) const
.........................................

This virtual function overrides the `derivative (*note _139::)' virtual
function defined in the `rotational (*note
curve_rotational_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get curve derivative at specified distance from origin.

   * r: distance from curve origin (0, 0)

void fit(const rotational &c)
.............................

Switch to moving source test and update knife edge readings of
previously defined zone to fit provided rotationally symmetric curve.
This means simulating a foucault test of the given curve using existing
zones.

double get_radius() const
.........................

Get surface radius.

const std:: pair <double, double> get_reading(unsigned int zone_number) const
.............................................................................

Get reading data for a given zone number.

   The return value is std::pair with zone radius and knife offset

unsigned int get_zones_count() const
....................................

Get currently defined zones/readings count

virtual double sagitta(double r) const
......................................

This virtual function implements the `sagitta (*note _144::)' pure
function declared in the `rotational (*note
curve_rotational_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get curve sagitta at specified distance from origin.

   * r: distance from curve origin (0, 0)

void set_fixed_source(double source_to_surface)
...............................................

Set fixed light source foucault test. This clear all readings and zones.

   * source_to_surface: Distance between surface and light source along
     the optical axis.

void set_knife_offset(unsigned int zone_number, double knife_offset)
....................................................................

Set knife edge reading of a previously defined zone

void set_moving_source(double source_offset = 0.0)
..................................................

Set moving light source foucault test. This clear all readings and
zones.

   * source_offset: Distance between knife edge and light source along
     optical axis.

void set_ode_stepsize(double step)
..................................

Set surface integration (ODE) algorithm step size, default is 1mm

void set_radius(double radius)
..............................

Set surface radius. Effective surface radius must be known to let the
surface integration algorithm run up to a given limit. Sagitta and
gradient values above the define radius won't be accurate.

   Radius is adjusted to max zone radius + 10% when adding readings.

curve::Foucault class full member list
======================================

Functions
---------

   * Foucault(double roc)

   * ~Foucault()

   * unsigned int add_couder_zones(double hole_radius, unsigned int
     count = _[...]_, std::vector<double> *edge = _[...]_)

   * void add_reading(double zone_radius, double knife_offset = _[...]_)

   * unsigned int add_uniform_zones(double hole_radius, unsigned int
     count)

   * void clear()

   * virtual void derivative(const math::vector2 &xy, math::vector2
     &dxdy) const

   * virtual double derivative(double r) const

   * void fit(const rotational &c)

   * double get_radius() const

   * const std::pair<double, double> get_reading(unsigned int
     zone_number) const

   * double get_roc() const

   * virtual void get_sample(unsigned int index, double &r, double &z)
     const

   * virtual unsigned int get_sample_count() const

   * unsigned int get_zones_count() const

   * virtual bool intersect(math::vector3 &point, const
     math::vectorPair3 &ray) const

   * virtual void normal(math::vector3 &normal, const math::vector3
     &point) const

   * virtual double sagitta(const math::vector2 &xy) const

   * virtual double sagitta(double r) const

   * void set_fixed_source(double source_to_surface)

   * void set_knife_offset(unsigned int zone_number, double
     knife_offset)

   * void set_moving_source(double source_offset = _[...]_)

   * void set_ode_stepsize(double step)

   * void set_radius(double radius)

   * void set_roc(double roc)

curve::Grid class reference
===========================

Declaration
-----------

     #include <goptical/core/curve/Grid>

     namespace goptical {
       namespace curve {
         class Grid;
       };
     };

   This class is a member of the curve namespace.

Inheritance
-----------

Description
-----------

This class use the data::Grid (*note data_Grid_class_reference::) 2d
data set container to define a 3d non-symmetric curve. Several data
interpolation algorithms are available allowing use of data::Bicubic
(*note _146::) spline interpolation with or without prescribed
derivative/gradient data.  .

   The Spline (*note curve_Spline_class_reference::) curve model is
preferred when dealing with rotationally symmetric curves (*note
curve_rotational_class_reference::).

   See also data::Grid (*note data_Grid_class_reference::) class.

Members
-------

See also the full member list (*note
curve_Grid_class_full_member_list::) section for this class.

Inherited members
.................

   * 5 members inherited from Base (*note curve_Base_class_reference::)

Functions
.........

   * Grid(unsigned int n, double radius)

   * ~Grid()

   * virtual void derivative(const math::vector2 &xy, math::vector2
     &dxdy) const

   * void fit(const Base &c)

   * const data::Grid & get_data() const

   * data::Grid & get_data()

   * virtual double sagitta(const math::vector2 &xy) const

Members detail
--------------

Grid(unsigned int n, double radius)
...................................

Creates a grid curve with n*n sample points defined over the given
radius.

~Grid()
.......

No documentation available

virtual void derivative(const math::vector2 &xy, math::vector2 &dxdy) const
...........................................................................

This virtual function overrides the `derivative (*note _39::)' virtual
function defined in the `Base (*note curve_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get curve x and y derivative (gradient) at specified point

void fit(const Base &c)
.......................

Set grid values to best fit an other curve. Gradient data will be
extracted only if the interpolation have been set to data::BicubicDeriv
previously

const data::Grid & get_data() const
...................................

Get embedded sagitta/gradient data container

data::Grid & get_data()
.......................

Get embedded sagitta/gradient data container

virtual double sagitta(const math::vector2 &xy) const
.....................................................

This virtual function implements the `sagitta (*note _42::)' pure
function declared in the `Base (*note curve_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get curve sagitta at specified point

curve::Grid class full member list
==================================

Functions
---------

   * Grid(unsigned int n, double radius)

   * ~Grid()

   * virtual void derivative(const math::vector2 &xy, math::vector2
     &dxdy) const

   * void fit(const Base &c)

   * const data::Grid & get_data() const

   * data::Grid & get_data()

   * virtual bool intersect(math::vector3 &point, const
     math::vectorPair3 &ray) const

   * virtual void normal(math::vector3 &normal, const math::vector3
     &point) const

   * virtual double sagitta(const math::vector2 &xy) const

curve::Parabola class reference
===============================

Declaration
-----------

     #include <goptical/core/curve/Parabola>

     namespace goptical {
       namespace curve {
         class Parabola;
       };
     };

   This class is a member of the curve namespace.

Inheritance
-----------

Description
-----------

This class provides an efficient parabola curve implementation.

Members
-------

See also the full member list (*note
curve_Parabola_class_full_member_list::) section for this class.

Inherited members
.................

   * 13 members inherited from ConicBase (*note
     curve_ConicBase_class_reference::)

Functions
.........

   * Parabola(double roc)

   * virtual double derivative(double r) const

   * virtual bool intersect(math::vector3 &point, const
     math::vectorPair3 &ray) const

   * virtual double sagitta(double r) const

Members detail
--------------

Parabola(double roc)
....................

Creates a parabola curve with given radius of curvature

virtual double derivative(double r) const
.........................................

This virtual function implements the `derivative (*note _130::)' pure
function declared in the `ConicBase (*note
curve_ConicBase_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get curve derivative at specified distance from origin.

   * r: distance from curve origin (0, 0)

virtual bool intersect(math::vector3 &point, const math::vectorPair3 &ray) const
................................................................................

This virtual function implements the `intersect (*note _134::)' pure
function declared in the `ConicBase (*note
curve_ConicBase_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get intersection point between curve and 3d ray. Return false if no
intersection occurred

virtual double sagitta(double r) const
......................................

This virtual function implements the `sagitta (*note _135::)' pure
function declared in the `ConicBase (*note
curve_ConicBase_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get curve sagitta at specified distance from origin.

   * r: distance from curve origin (0, 0)

curve::Parabola class full member list
======================================

Functions
---------

   * Parabola(double roc)

   * virtual void derivative(const math::vector2 &xy, math::vector2
     &dxdy) const

   * virtual double derivative(double r) const

   * double fit_roc(const rotational &c, double radius, unsigned int
     count)

   * double get_eccentricity() const

   * double get_roc() const

   * virtual void get_sample(unsigned int index, double &r, double &z)
     const

   * virtual unsigned int get_sample_count() const

   * double get_schwarzschild() const

   * virtual bool intersect(math::vector3 &point, const
     math::vectorPair3 &ray) const

   * virtual void normal(math::vector3 &normal, const math::vector3
     &point) const

   * virtual double sagitta(const math::vector2 &xy) const

   * virtual double sagitta(double r) const

   * void set_roc(double roc)

curve::Polynomial class reference
=================================

Declaration
-----------

     #include <goptical/core/curve/Polynomial>

     namespace goptical {
       namespace curve {
         class Polynomial;
       };
     };

   This class is a member of the curve namespace.

Inheritance
-----------

Description
-----------

This class allow definition of rotationally symmetric high order
polynomial curves. Unlimited number of terms can be used.

Members
-------

See also the full member list (*note
curve_Polynomial_class_full_member_list::) section for this class.

Inherited members
.................

   * 9 members inherited from rotational (*note
     curve_rotational_class_reference::)

Functions
.........

   * Polynomial()

   * Polynomial(unsigned int first_term, unsigned int last_term, ...)

   * virtual double derivative(double r) const

   * virtual double sagitta(double r) const

   * void set(unsigned int first_term, unsigned int last_term, ...)

   * void set_even(unsigned int first_term, unsigned int last_term, ...)

   * void set_first_term(unsigned int n)

   * void set_last_term(unsigned int n)

   * void set_odd(unsigned int first_term, unsigned int last_term, ...)

   * void set_term_factor(unsigned int n, double c)

Members detail
--------------

Polynomial()
............

Create a new zero polynomial

Polynomial(unsigned int first_term, unsigned int last_term, ...)
................................................................

Create a new polynomial with given order and coefficients. Same syntax
as set() function.

virtual double derivative(double r) const
.........................................

This virtual function overrides the `derivative (*note _139::)' virtual
function defined in the `rotational (*note
curve_rotational_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get curve derivative at specified distance from origin.

   * r: distance from curve origin (0, 0)

virtual double sagitta(double r) const
......................................

This virtual function implements the `sagitta (*note _144::)' pure
function declared in the `rotational (*note
curve_rotational_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get curve sagitta at specified distance from origin.

   * r: distance from curve origin (0, 0)

void set(unsigned int first_term, unsigned int last_term, ...)
..............................................................

Set polynomial order and coefficients.

   * first_term: order of first (lowest) term.

   * last_term: order of last (highest) term.

   * ...: list of coefficient starting at lowest term

void set_even(unsigned int first_term, unsigned int last_term, ...)
...................................................................

Set even polynomial order and coefficients.

   * first_term: order of first (lowest) term, must be even.

   * last_term: order of last (highest) term, must be even.

   * ...: list of even coefficient starting at lowest term

void set_first_term(unsigned int n)
...................................

Set order of first (lowest) term. Polynomial may be truncated or
extended with 0 coefficients.

void set_last_term(unsigned int n)
..................................

Set order of last (highest) term. Polynomial may be truncated or
extended with 0 coefficients.

void set_odd(unsigned int first_term, unsigned int last_term, ...)
..................................................................

Set odd polynomial order and coefficients.

   * first_term: order of first (lowest) term, must be odd.

   * last_term: order of last (highest) term, must be odd.

   * ...: list of odd coefficient starting at lowest term

void set_term_factor(unsigned int n, double c)
..............................................

Adjust coefficient of a single term. Adujst polynomial length as
needed, setting additional coefficients to 0.

curve::Polynomial class full member list
========================================

Functions
---------

   * Polynomial()

   * Polynomial(unsigned int first_term, unsigned int last_term, ...)

   * virtual void derivative(const math::vector2 &xy, math::vector2
     &dxdy) const

   * virtual double derivative(double r) const

   * virtual void get_sample(unsigned int index, double &r, double &z)
     const

   * virtual unsigned int get_sample_count() const

   * virtual bool intersect(math::vector3 &point, const
     math::vectorPair3 &ray) const

   * virtual void normal(math::vector3 &normal, const math::vector3
     &point) const

   * virtual double sagitta(const math::vector2 &xy) const

   * virtual double sagitta(double r) const

   * void set(unsigned int first_term, unsigned int last_term, ...)

   * void set_even(unsigned int first_term, unsigned int last_term, ...)

   * void set_first_term(unsigned int n)

   * void set_last_term(unsigned int n)

   * void set_odd(unsigned int first_term, unsigned int last_term, ...)

   * void set_term_factor(unsigned int n, double c)

curve::Sphere class reference
=============================

Declaration
-----------

     #include <goptical/core/curve/Sphere>

     namespace goptical {
       namespace curve {
         class Sphere;
       };
     };

   This class is a member of the curve namespace.

Inheritance
-----------

Description
-----------

This class provides an efficient spherical curve implementation.

Members
-------

See also the full member list (*note
curve_Sphere_class_full_member_list::) section for this class.

Inherited members
.................

   * 13 members inherited from ConicBase (*note
     curve_ConicBase_class_reference::)

Functions
.........

   * Sphere(double roc)

   * virtual double derivative(double r) const

   * virtual bool intersect(math::vector3 &point, const
     math::vectorPair3 &ray) const

   * virtual void normal(math::vector3 &normal, const math::vector3
     &point) const

   * virtual double sagitta(double r) const

Members detail
--------------

Sphere(double roc)
..................

Creates a spherical curve with given radius of curvature

virtual double derivative(double r) const
.........................................

This virtual function implements the `derivative (*note _130::)' pure
function declared in the `ConicBase (*note
curve_ConicBase_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get curve derivative at specified distance from origin.

   * r: distance from curve origin (0, 0)

virtual bool intersect(math::vector3 &point, const math::vectorPair3 &ray) const
................................................................................

This virtual function implements the `intersect (*note _134::)' pure
function declared in the `ConicBase (*note
curve_ConicBase_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get intersection point between curve and 3d ray. Return false if no
intersection occurred

virtual void normal(math::vector3 &normal, const math::vector3 &point) const
............................................................................

This virtual function overrides the `normal (*note _143::)' virtual
function defined in the `rotational (*note
curve_rotational_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get normal to curve surface at specified point

virtual double sagitta(double r) const
......................................

This virtual function implements the `sagitta (*note _135::)' pure
function declared in the `ConicBase (*note
curve_ConicBase_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get curve sagitta at specified distance from origin.

   * r: distance from curve origin (0, 0)

curve::Sphere class full member list
====================================

Functions
---------

   * Sphere(double roc)

   * virtual void derivative(const math::vector2 &xy, math::vector2
     &dxdy) const

   * virtual double derivative(double r) const

   * double fit_roc(const rotational &c, double radius, unsigned int
     count)

   * double get_eccentricity() const

   * double get_roc() const

   * virtual void get_sample(unsigned int index, double &r, double &z)
     const

   * virtual unsigned int get_sample_count() const

   * double get_schwarzschild() const

   * virtual bool intersect(math::vector3 &point, const
     math::vectorPair3 &ray) const

   * virtual void normal(math::vector3 &normal, const math::vector3
     &point) const

   * virtual double sagitta(const math::vector2 &xy) const

   * virtual double sagitta(double r) const

   * void set_roc(double roc)

curve::Spline class reference
=============================

Declaration
-----------

     #include <goptical/core/curve/Spline>

     namespace goptical {
       namespace curve {
         class Spline;
       };
     };

   This class is a member of the curve namespace.

Inheritance
-----------

Description
-----------

This class uses a 1d discrete data set to define a rotationally
symmetric sagitta/gradient curve. Several data interpolations algorithm
are available allowing use of Smooth Cubic spline interpolation with or
without prescribed derivative/gradient data.

   See also data::DiscreteSet (*note
data_DiscreteSet_class_reference::) class.

Members
-------

See also the full member list (*note
curve_Spline_class_full_member_list::) section for this class.

Inherited members
.................

   * 9 members inherited from rotational (*note
     curve_rotational_class_reference::)

Functions
.........

   * Spline()

   * ~Spline()

   * virtual double derivative(double r) const

   * void fit(const rotational &c, double radius, unsigned int points)

   * const data::DiscreteSet & get_data() const

   * data::DiscreteSet & get_data()

   * virtual double sagitta(double r) const

Members detail
--------------

Spline()
........

Create an empty spline curve with no defined point

~Spline()
.........

No documentation available

virtual double derivative(double r) const
.........................................

This virtual function overrides the `derivative (*note _139::)' virtual
function defined in the `rotational (*note
curve_rotational_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get curve derivative at specified distance from origin.

   * r: distance from curve origin (0, 0)

void fit(const rotational &c, double radius, unsigned int points)
.................................................................

Clear all points and fit to an other rotationally symmetric curve.

   * c: curve to fit

   * radius: Maximum radius where curve is defined

   * points: Number of sample points

const data::DiscreteSet & get_data() const
..........................................

Get sagitta/derivative data container

data::DiscreteSet & get_data()
..............................

get sagitta/derivative data container

virtual double sagitta(double r) const
......................................

This virtual function implements the `sagitta (*note _144::)' pure
function declared in the `rotational (*note
curve_rotational_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get curve sagitta at specified distance from origin.

   * r: distance from curve origin (0, 0)

curve::Spline class full member list
====================================

Functions
---------

   * Spline()

   * ~Spline()

   * virtual void derivative(const math::vector2 &xy, math::vector2
     &dxdy) const

   * virtual double derivative(double r) const

   * void fit(const rotational &c, double radius, unsigned int points)

   * const data::DiscreteSet & get_data() const

   * data::DiscreteSet & get_data()

   * virtual void get_sample(unsigned int index, double &r, double &z)
     const

   * virtual unsigned int get_sample_count() const

   * virtual bool intersect(math::vector3 &point, const
     math::vectorPair3 &ray) const

   * virtual void normal(math::vector3 &normal, const math::vector3
     &point) const

   * virtual double sagitta(const math::vector2 &xy) const

   * virtual double sagitta(double r) const

curve::Zernike class reference
==============================

Declaration
-----------

     #include <goptical/core/curve/Zernike>

     namespace goptical {
       namespace curve {
         class Zernike;
       };
     };

   This class is a member of the curve namespace.

Inheritance
-----------

Description
-----------

This class enables use of zernikes polynomials to define a surface
curve. Zernikes terms can be enabled and disabled individually.

   Fitting can be used to get best fit Zernike polynomials coefficients
of an other curve.

   This implementation uses Zernike polynomials set as described in ISO
standard 10110-5.

   Based on Zernikes pages by James C Wyant and Michael Koch.
http://www.optics.arizona.edu/jcwyant/Zernikes/ZernikePolynomials.htm
and  http://www.astro-electronic.de/faq2.htm

Members
-------

See also the full member list (*note
curve_Zernike_class_full_member_list::) section for this class.

Inherited members
.................

   * 5 members inherited from Base (*note curve_Base_class_reference::)

Functions
.........

   * Zernike(double radius, double unit_scale = _[...]_)

   * Zernike(double radius, double coefs[], unsigned int coefs_count,
     double unit_scale = _[...]_)

   * virtual void derivative(const math::vector2 &xy, math::vector2
     &dxdy) const

   * double fit(const Base &c, const trace::distribution &d = _[...]_)

   * double get_coefficient(unsigned int n) const

   * double get_radius() const

   * bool get_term_state(unsigned int n)

   * virtual double sagitta(const math::vector2 &xy) const

   * void set_coefficient(unsigned int n, double c)

   * void set_coefficients_scale(double s)

   * void set_coefficients_threshold(double t)

   * void set_radius(double radius)

   * void set_term_state(unsigned int n, bool enabled)

Static functions
................

   * static double zernike_poly(unsigned int n, const math::vector2 &xy)

   * static void zernike_poly_d(unsigned int n, const math::vector2
     &xy, math::vector2 &dxdy)

Constant
........

   * static const unsigned int term_count

Members detail
--------------

Zernike(double radius, double unit_scale = 1.0)
...............................................

Create a Zernike curve defined over the given circle radius.

   * radius: Zernike circle radius

   * unit_scale: Sagitta scale factor used to change units globally

Zernike(double radius, double coefs[], unsigned int coefs_count, double unit_scale = 1.0)
.........................................................................................

Create a Zernike curve defined over the given circle radius and
initialize coefficients from table.

   * radius: Zernike circle radius

   * coefs: Table of Zernike coefficients starting with z0 (piston)

   * coefs_count: Number of coefficients available in the table

   * unit_scale: Sagitta scale factor used to change units globally

virtual void derivative(const math::vector2 &xy, math::vector2 &dxdy) const
...........................................................................

This virtual function overrides the `derivative (*note _39::)' virtual
function defined in the `Base (*note curve_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get curve x and y derivative (gradient) at specified point

double fit(const Base &c, const trace::distribution &d = default_dist)
......................................................................

Compute all zernike coefficient to best fit the given curve. RMS
difference is returned. The specified distribution is used to choose
sampling points on curve. Terms state is adjusted according to current
threshold

double get_coefficient(unsigned int n) const
............................................

Get coefficient associated with zernike term n

double get_radius() const
.........................

Get Zernike circle radius

bool get_term_state(unsigned int n)
...................................

Get current term enable state

virtual double sagitta(const math::vector2 &xy) const
.....................................................

This virtual function implements the `sagitta (*note _42::)' pure
function declared in the `Base (*note curve_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get curve sagitta at specified point

void set_coefficient(unsigned int n, double c)
..............................................

Set coefficient associated with zernike term n and enable term
according to current threshold. See set_coefficients_threshold()

void set_coefficients_scale(double s)
.....................................

Set coefficients unit scale factor. default is 1 (1 mm).

void set_coefficients_threshold(double t)
.........................................

Set new coefficient threshold and adjust all term states
(enabled/disabled) depending on new threshold. Term with coefficient
absolute value below the specified threshold will be disabled.
Disabling useless terms improve performance. Default threshold is
10^-10.

void set_radius(double radius)
..............................

Set Zernike circle radius

void set_term_state(unsigned int n, bool enabled)
.................................................

This functions must be used to enable/disable a zernike term without
changing its coefficient

static const unsigned int term_count
....................................

Number of implemented zernike polynomials

static double zernike_poly(unsigned int n, const math::vector2 &xy)
...................................................................

Evaluate zernike polynomial n

static void zernike_poly_d(unsigned int n, const math::vector2 &xy, math::vector2 &dxdy)
........................................................................................

Evaluate x and y derivatives of zernike polynomial n

curve::Zernike class full member list
=====================================

Functions
---------

   * Zernike(double radius, double unit_scale = _[...]_)

   * Zernike(double radius, double coefs[], unsigned int coefs_count,
     double unit_scale = _[...]_)

   * virtual void derivative(const math::vector2 &xy, math::vector2
     &dxdy) const

   * double fit(const Base &c, const trace::distribution &d = _[...]_)

   * double get_coefficient(unsigned int n) const

   * double get_radius() const

   * bool get_term_state(unsigned int n)

   * virtual bool intersect(math::vector3 &point, const
     math::vectorPair3 &ray) const

   * virtual void normal(math::vector3 &normal, const math::vector3
     &point) const

   * virtual double sagitta(const math::vector2 &xy) const

   * void set_coefficient(unsigned int n, double c)

   * void set_coefficients_scale(double s)

   * void set_coefficients_threshold(double t)

   * void set_radius(double radius)

   * void set_term_state(unsigned int n, bool enabled)

Static functions
----------------

   * static double zernike_poly(unsigned int n, const math::vector2 &xy)

   * static void zernike_poly_d(unsigned int n, const math::vector2
     &xy, math::vector2 &dxdy)

Constant
--------

   * static const unsigned int term_count

curve::ConicBase class reference
================================

Declaration
-----------

     #include <goptical/core/curve/ConicBase>

     namespace goptical {
       namespace curve {
         class ConicBase;
       };
     };

   This class is a member of the curve namespace.

   This abstract class contains pure virtuals.

Inheritance
-----------

Description
-----------

This base class defines common properties of rotationally symmetric
conic curves. These curves are all defined by a radius of curvature and
deformation coefficient.

   Fitting can be used to find best fit conic of an other rotationally
symmetric curve either with fixed or free deformation parameter.

Members
-------

See also the full member list (*note
curve_ConicBase_class_full_member_list::) section for this class.

Inherited members
.................

   * 2 members inherited from curveRoc (*note
     curve_curveRoc_class_reference::)

   * 9 members inherited from rotational (*note
     curve_rotational_class_reference::)

Functions
.........

   * virtual double derivative(double r) const = 0;

   * double fit_roc(const rotational &c, double radius, unsigned int
     count)

   * double get_eccentricity() const

   * double get_schwarzschild() const

   * virtual bool intersect(math::vector3 &point, const
     math::vectorPair3 &ray) const = 0;

   * virtual double sagitta(double r) const = 0;

Members detail
--------------

virtual double derivative(double r) const = 0;
..............................................

This pure virtual function shadows the `derivative (*note _139::)'
virtual function defined in the `rotational (*note
curve_rotational_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get curve derivative at specified distance from origin.

   * r: distance from curve origin (0, 0)

double fit_roc(const rotational &c, double radius, unsigned int count)
......................................................................

Adjust radius of curvature to best fit given curve. Deformation Won't
be changed by this function. See Conic::fit() to adjust deformation too.

   Parameters list:

   * curve: curve to fit

   * radius: Maximum radius used to get sample points

   * count: Number of sample points to use

double get_eccentricity() const
...............................

get eccentricity

double get_schwarzschild() const
................................

get Schwarzschild constant

virtual bool intersect(math::vector3 &point, const math::vectorPair3 &ray) const = 0;
.....................................................................................

This pure virtual function shadows the `intersect (*note _40::)'
virtual function defined in the `Base (*note
curve_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get intersection point between curve and 3d ray. Return false if no
intersection occurred

virtual double sagitta(double r) const = 0;
...........................................

This pure virtual function shadows the `sagitta (*note _144::)' pure
virtual function defined in the `rotational (*note
curve_rotational_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get curve sagitta at specified distance from origin.

   * r: distance from curve origin (0, 0)

curve::ConicBase class full member list
=======================================

Functions
---------

   * virtual void derivative(const math::vector2 &xy, math::vector2
     &dxdy) const

   * virtual double derivative(double r) const = 0;

   * double fit_roc(const rotational &c, double radius, unsigned int
     count)

   * double get_eccentricity() const

   * double get_roc() const

   * virtual void get_sample(unsigned int index, double &r, double &z)
     const

   * virtual unsigned int get_sample_count() const

   * double get_schwarzschild() const

   * virtual bool intersect(math::vector3 &point, const
     math::vectorPair3 &ray) const = 0;

   * virtual void normal(math::vector3 &normal, const math::vector3
     &point) const

   * virtual double sagitta(const math::vector2 &xy) const

   * virtual double sagitta(double r) const = 0;

   * void set_roc(double roc)

curve::curveRoc class reference
===============================

Declaration
-----------

     #include <goptical/core/curve/curveRoc>

     namespace goptical {
       namespace curve {
         class curveRoc;
       };
     };

   This class is a member of the curve namespace.

Inheritance
-----------

Description
-----------

Base class for curves with a radius of curvature

Members
-------

See also the full member list (*note
curve_curveRoc_class_full_member_list::) section for this class.

Functions
.........

   * double get_roc() const

   * void set_roc(double roc)

Members detail
--------------

double get_roc() const
......................

Get the radius of curvature

void set_roc(double roc)
........................

Set the radius of curvature

curve::curveRoc class full member list
======================================

Functions
---------

   * double get_roc() const

   * void set_roc(double roc)

curve::rotational class reference
=================================

Declaration
-----------

     #include <goptical/core/curve/rotational>

     namespace goptical {
       namespace curve {
         class rotational;
       };
     };

   This class is a member of the curve namespace.

   This abstract class contains pure virtuals.

Inheritance
-----------

Description
-----------

This class defines rotationally symmetric curve interface and provide
default implementation as generic non symmetric curve.

Members
-------

See also the full member list (*note
curve_rotational_class_full_member_list::) section for this class.

Inherited members
.................

   * 5 members inherited from Base (*note curve_Base_class_reference::)

Functions
.........

   * rotational()

   * virtual double derivative(double r) const

   * virtual void derivative(const math::vector2 &xy, math::vector2
     &dxdy) const

   * virtual void get_sample(unsigned int index, double &r, double &z)
     const

   * virtual unsigned int get_sample_count() const

   * virtual void normal(math::vector3 &normal, const math::vector3
     &point) const

   * virtual double sagitta(double r) const = 0;

   * virtual double sagitta(const math::vector2 &xy) const

Members detail
--------------

rotational()
............

No documentation available

virtual double derivative(double r) const
.........................................

Get curve derivative at specified distance from origin.

   * r: distance from curve origin (0, 0)

virtual void derivative(const math::vector2 &xy, math::vector2 &dxdy) const
...........................................................................

This virtual function overrides the `derivative (*note _39::)' virtual
function defined in the `Base (*note curve_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get curve x and y derivative (gradient) at specified point

virtual void get_sample(unsigned int index, double &r, double &z) const
.......................................................................

Get a sample point on curve. (0,0) is not included.

virtual unsigned int get_sample_count() const
.............................................

Get number of available sample points. Samples points may be used by
curve fitting algorithms and are choosen to avoid using interpolated
points. return 0 when not applicable.

virtual void normal(math::vector3 &normal, const math::vector3 &point) const
............................................................................

This virtual function overrides the `normal (*note _41::)' virtual
function defined in the `Base (*note curve_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get normal to curve surface at specified point

virtual double sagitta(double r) const = 0;
...........................................

Get curve sagitta at specified distance from origin.

   * r: distance from curve origin (0, 0)

virtual double sagitta(const math::vector2 &xy) const
.....................................................

This virtual function implements the `sagitta (*note _42::)' pure
function declared in the `Base (*note curve_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get curve sagitta at specified point

curve::rotational class full member list
========================================

Functions
---------

   * rotational()

   * virtual double derivative(double r) const

   * virtual void derivative(const math::vector2 &xy, math::vector2
     &dxdy) const

   * virtual void get_sample(unsigned int index, double &r, double &z)
     const

   * virtual unsigned int get_sample_count() const

   * virtual bool intersect(math::vector3 &point, const
     math::vectorPair3 &ray) const

   * virtual void normal(math::vector3 &normal, const math::vector3
     &point) const

   * virtual double sagitta(double r) const = 0;

   * virtual double sagitta(const math::vector2 &xy) const

data namespace reference
========================

Description
-----------

Numerical data interpolation and plotting

Members
-------

Types
.....

   * class DiscreteSet

   * class Grid

   * class Plot

   * class Plotdata

   * class SampleSet

   * enum Interpolation

   * enum PlotStyleMask

   * class Set

   * class Set1d

Functions
.........

   * PlotStyleMask operator&(PlotStyleMask a, PlotStyleMask b)

   * std::ostream & operator<<(std::ostream &o, const Set &s)

   * PlotStyleMask operator|(PlotStyleMask a, PlotStyleMask b)

   * PlotStyleMask operator~(PlotStyleMask a)

Members detail
--------------

enum Interpolation
..................

Specifies data interpolation methods. Availability depends on data
container used.

Identifier             Description
-------------------------------------------------------------------------- 
Nearest                 1d and 2d nearest interpolation
Linear                  1d linear and 2d bilinear interpolations
Quadratic               1d quadratic interpolation
CubicSimple             1d cubic piecewise interpolation. It has
                       continuous piecewise first derivative,
                       non-continuous piecewise linear second
                       derivative. Use segments slope as first
                       derivative. Less accurate than other cubic
                       interpolants but requires less computation on
                       data set change.
Cubic                   1d cubic piecewise interpolation. It has smooth
                       first derivative and continuous piecewise linear
                       second derivative. Derivatives for first and last
                       entries are based on first and last segments
                       slope. It uses linear extrapolation (continuous
                       but non-smooth first derivative on both ends).
Cubic2                  Same interpolation as Cubic, with quadratic
                       extrapolation (continous and smooth first
                       derivative on both ends).
CubicDerivInit          Same as Cubic with first derivative prescribed
                       for first and last entries only.
Cubic2DerivInit         Same as Cubic2 with first derivative prescribed
                       for first and last entries only.
CubicDeriv              1d cubic piecewise interpolation. First
                       derivatives must be provided for all entries. It
                       uses linear extrapolation.
Cubic2Deriv             1d cubic piecewise interpolation. First
                       derivatives must be provided for all entries. It
                       uses quadratic extrapolation.
Bicubic                 2d bicubic interpolation. Use smooth first
                       derivative and continuous piecewise linear second
                       derivative. Use 1d cubic curve to extract
                       gradients (smooth first derivative and continuous
                       piecewise linear second derivative). This is the
                       best 2d interpolation when derivatives are
                       non-prescribed.
BicubicDiff             2d bicubic interpolation. Use numerical
                       differencing to extract gradients. Less accurate
                       than Bicubic (*note _146::) but requires less
                       computation on data set change.
BicubicDeriv            2d bicubic interpolation. x and y gradients must
                       be provided. This is the best 2d interpolation
                       when derivatives values are available.

enum PlotStyleMask
..................

Specifies available styles for 2d and 3d plot data rendering

Identifier             Description
-------------------------------------------------------------------------- 
LinePlot                Draw lines between knots
PointPlot               Draw points for each knot
InterpolatePlot         Draw a smooth curve
ValuePlot               Print ploted values near knots
Filled                  Draw filled 3d surface

PlotStyleMask operator&(PlotStyleMask a, PlotStyleMask b)
.........................................................

Bitwise and operation for use on PlotStyleMask (*note _147::) enum.

std:: ostream  & operator<<(std:: ostream  &o, const Set &s)
............................................................

No documentation available

PlotStyleMask operator|(PlotStyleMask a, PlotStyleMask b)
.........................................................

Bitwise or operation for use on PlotStyleMask (*note _147::) enum.

PlotStyleMask operator~(PlotStyleMask a)
........................................

Bitwise not operation for use on PlotStyleMask (*note _147::) enum.

data::DiscreteSet class reference
=================================

Declaration
-----------

     #include <goptical/core/data/DiscreteSet>

     namespace goptical {
       namespace data {
         class DiscreteSet;
       };
     };

   This class is a member of the data namespace.

Inheritance
-----------

Description
-----------

This class provides a numerical data container where value pairs can be
defined at arbitrary positions (x, y).

   Severals interpolation algorithms are available to guess values
between defined knots, see Interpolation (*note _146::).

   See also SampleSet (*note data_SampleSet_class_reference::) class.

Members
-------

See also the full member list (*note
data_DiscreteSet_class_full_member_list::) section for this class.

Inherited members
.................

   * 19 members inherited from Set1d (*note
     data_Set1d_class_reference::)

Functions
.........

   * DiscreteSet()

   * void add_data(double x, double y, double yp = _[...]_)

   * void clear()

   * virtual unsigned int get_count() const

   * double get_d_value(unsigned int x) const

   * double & get_d_value(unsigned int x)

   * virtual math::range_t get_x_range() const

   * virtual double get_x_value(unsigned int x) const

   * virtual double get_y_value(unsigned int x) const

   * virtual double & get_y_value(unsigned int x)

   * virtual double interpolate(const double x) const

   * virtual double interpolate(const double x, unsigned int deriv)
     const

   * void reserve(size_t n)

   * virtual void set_interpolation(Interpolation i)

Members detail
--------------

DiscreteSet()
.............

No documentation available

data::DiscreteSet class full member list
========================================

Functions
---------

   * DiscreteSet()

   * void add_data(double x, double y, double yp = _[...]_)

   * void clear()

   * virtual unsigned int get_count(unsigned int dim) const

   * virtual unsigned int get_count() const

   * double get_d_value(unsigned int x) const

   * double & get_d_value(unsigned int x)

   * virtual unsigned int get_dimensions() const

   * Interpolation get_interpolation()

   * unsigned int get_version() const

   * virtual math::range_t get_x_range(unsigned int dimension) const

   * virtual math::range_t get_x_range() const

   * virtual double get_x_value(unsigned int n, unsigned int dim) const

   * virtual double get_x_value(unsigned int x) const

   * virtual math::range_t get_y_range() const

   * virtual double get_y_value(const unsigned int x[]) const

   * virtual double get_y_value(unsigned int x) const

   * virtual double & get_y_value(unsigned int x)

   * virtual double interpolate(const double x[]) const

   * virtual double interpolate(const double x[], unsigned int deriv,
     unsigned int dimension) const

   * virtual double interpolate(const double x) const

   * virtual double interpolate(const double x, unsigned int deriv)
     const

   * void reserve(size_t n)

   * virtual void set_interpolation(Interpolation i)

data::Grid class reference
==========================

Declaration
-----------

     #include <goptical/core/data/Grid>

     namespace goptical {
       namespace data {
         class Grid;
       };
     };

   This class is a member of the data namespace.

Inheritance
-----------

Description
-----------

This class provides a numerical data container where data value can be
defined for each point of a 2d rectangular grid. The grid is defined by
grid samples count (n1, n2), a 2d origin vector and 2 steps values.

   Severals interpolation algorithms are available to guess values
between grid defined knots, see Interpolation (*note _146::).

Members
-------

See also the full member list (*note
data_Grid_class_full_member_list::) section for this class.

Inherited members
.................

   * 12 members inherited from Set (*note data_Set_class_reference::)

Functions
.........

   * Grid(unsigned int n1, unsigned int n2, const math::vector2 &origin
     = _[...]_, const math::vector2 &step = _[...]_)

   * ~Grid()

   * virtual unsigned int get_count(unsigned int dimension) const

   * const math::vector2 & get_d_value(unsigned int n1, unsigned int
     n2) const

   * math::vector2 & get_d_value(unsigned int n1, unsigned int n2)

   * virtual unsigned int get_dimensions() const

   * const math::vector2 & get_nearest_d(const math::vector2 &v) const

   * math::vector2 & get_nearest_d(const math::vector2 &v)

   * double get_nearest_y(const math::vector2 &v) const

   * double & get_nearest_y(const math::vector2 &v)

   * const math::vector2 & get_origin() const

   * const math::vector2 & get_step() const

   * virtual math::range_t get_x_range(unsigned int dimension) const

   * virtual double get_x_value(unsigned int x, unsigned int dimension)
     const

   * math::vector2 get_x_value_i(unsigned int n1, unsigned int n2) const

   * double get_y_value(unsigned int n1, unsigned int n2) const

   * double & get_y_value(unsigned int n1, unsigned int n2)

   * virtual double get_y_value(const unsigned int n[]) const

   * double interpolate(const math::vector2 &v) const

   * virtual double interpolate(const double x[]) const

   * virtual double interpolate(const double x[], unsigned int deriv,
     unsigned int dimension) const

   * math::vector2 interpolate_deriv(const math::vector2 &v) const

   * void resize(unsigned int n1, unsigned int n2)

   * void set_all_d(const math::vector2 &deriv = _[...]_)

   * void set_all_y(double y = _[...]_)

   * virtual void set_interpolation(Interpolation i)

   * void set_metrics(const math::vector2 &origin, const math::vector2
     &step)

Members detail
--------------

Grid(unsigned int n1, unsigned int n2, const math::vector2 &origin = math::vector2(0,0), const math::vector2 &step = math::vector2(1,1))
........................................................................................................................................

Create a Grid object with given sample counts and metrics.

   * n1: Number of samples along the first dimension axis.

   * n2: Number of samples along the second dimension axis.

   * origin: Grid origin point

   * step: Step values for each grid dimensions

~Grid()
.......

No documentation available

virtual unsigned int get_count(unsigned int dimension) const
............................................................

This virtual function implements the `get_count (*note _223::)' pure
function declared in the `Set (*note data_Set_class_reference::)' base
abstract class.

   Documentation inherited from base class:

   Get total number of data stored for dimension n in data set

const math::vector2 & get_d_value(unsigned int n1, unsigned int n2) const
.........................................................................

Get 1st derivative/gradient vector at sample point index (n1, n2). Only
available when data::BicubicDeriv interpolation is selected.

math::vector2 & get_d_value(unsigned int n1, unsigned int n2)
.............................................................

Get modifiable reference to 1st derivative/gradient vector at sample
point index (n1, n2). Only available when data::BicubicDeriv
interpolation is selected.

virtual unsigned int get_dimensions() const
...........................................

This virtual function implements the `get_dimensions (*note _224::)'
pure function declared in the `Set (*note data_Set_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get total number of dimensions

const math::vector2 & get_nearest_d(const math::vector2 &v) const
.................................................................

Get 1st derivative/gradient vector stored at nearest sample point from
2d vector on grid. Only available when data::BicubicDeriv interpolation
is selected.

math::vector2 & get_nearest_d(const math::vector2 &v)
.....................................................

Get modifiable reference to 1st derivative/gradient vector stored at
nearest sample point from 2d vector on grid. Only available when
data::BicubicDeriv interpolation is selected.

double get_nearest_y(const math::vector2 &v) const
..................................................

Get value stored at nearest sample point from 2d vector on grid

double & get_nearest_y(const math::vector2 &v)
..............................................

Get modifiable reference to value stored at nearest sample point from
2d vector on grid

const math::vector2 & get_origin() const
........................................

Get origin vector

const math::vector2 & get_step() const
......................................

Get step values vector

virtual math::range_t get_x_range(unsigned int dimension) const
...............................................................

This virtual function implements the `get_x_range (*note _227::)' pure
function declared in the `Set (*note data_Set_class_reference::)' base
abstract class.

   Documentation inherited from base class:

   Get minimal and maximal x values on dimension n found in data set

virtual double get_x_value(unsigned int x, unsigned int dimension) const
........................................................................

This virtual function implements the `get_x_value (*note _228::)' pure
function declared in the `Set (*note data_Set_class_reference::)' base
abstract class.

   Documentation inherited from base class:

   Get data stored at position n on dimension dim in data set

math::vector2 get_x_value_i(unsigned int n1, unsigned int n2) const
...................................................................

Get 2d vector on grid of the sample point at index (n1, n2)

double get_y_value(unsigned int n1, unsigned int n2) const
..........................................................

Get value stored at sample point index (n1, n2)

double & get_y_value(unsigned int n1, unsigned int n2)
......................................................

Get modifiable reference to value stored at sample point index (n1, n2)

virtual double get_y_value(const unsigned int n[]) const
........................................................

This virtual function implements the `get_y_value (*note _230::)' pure
function declared in the `Set (*note data_Set_class_reference::)' base
abstract class.

   Documentation inherited from base class:

   Get y data stored at position (x0, x1, ...) in data set

double interpolate(const math::vector2 &v) const
................................................

Interpolate data at given 2d vector point on grid using currently
selected interpolation algorithm

virtual double interpolate(const double x[]) const
..................................................

This virtual function implements the `interpolate (*note _231::)' pure
function declared in the `Set (*note data_Set_class_reference::)' base
abstract class.

   Documentation inherited from base class:

   Interpolate y value corresponding to given x value(s) in data set.

virtual double interpolate(const double x[], unsigned int deriv, unsigned int dimension) const
..............................................................................................

This virtual function implements the `interpolate (*note _232::)' pure
function declared in the `Set (*note data_Set_class_reference::)' base
abstract class.

   Documentation inherited from base class:

   Interpolate y value corresponding to given x value in data set. data
may be differentiated several times along the requested dimension.

   * deriv: Differentiation count, 0 means y value, 1 means 1st
     derivative...

   * dim: Differentiation dimension

math::vector2 interpolate_deriv(const math::vector2 &v) const
.............................................................

Interpolate gradient at given 2d vector point on grid using currently
selected interpolation algorithm

void resize(unsigned int n1, unsigned int n2)
.............................................

Change grid size by defining new sample counts for each dimensions

void set_all_d(const math::vector2 &deriv = math::vector2(0,0))
...............................................................

Change all grid points stored gradient. Only available when
data::BicubicDeriv interpolation is selected.

void set_all_y(double y = 0.0)
..............................

Change all grid points stored values

virtual void set_interpolation(Interpolation i)
...............................................

This virtual function implements the `set_interpolation (*note _233::)'
pure function declared in the `Set (*note data_Set_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Select interpolation method

void set_metrics(const math::vector2 &origin, const math::vector2 &step)
........................................................................

Set grid origin 2d vector and step values

data::Grid class full member list
=================================

Functions
---------

   * Grid(unsigned int n1, unsigned int n2, const math::vector2 &origin
     = _[...]_, const math::vector2 &step = _[...]_)

   * ~Grid()

   * virtual unsigned int get_count(unsigned int dimension) const

   * const math::vector2 & get_d_value(unsigned int n1, unsigned int
     n2) const

   * math::vector2 & get_d_value(unsigned int n1, unsigned int n2)

   * virtual unsigned int get_dimensions() const

   * Interpolation get_interpolation()

   * const math::vector2 & get_nearest_d(const math::vector2 &v) const

   * math::vector2 & get_nearest_d(const math::vector2 &v)

   * double get_nearest_y(const math::vector2 &v) const

   * double & get_nearest_y(const math::vector2 &v)

   * const math::vector2 & get_origin() const

   * const math::vector2 & get_step() const

   * unsigned int get_version() const

   * virtual math::range_t get_x_range(unsigned int dimension) const

   * virtual double get_x_value(unsigned int x, unsigned int dimension)
     const

   * math::vector2 get_x_value_i(unsigned int n1, unsigned int n2) const

   * virtual math::range_t get_y_range() const

   * double get_y_value(unsigned int n1, unsigned int n2) const

   * double & get_y_value(unsigned int n1, unsigned int n2)

   * virtual double get_y_value(const unsigned int n[]) const

   * double interpolate(const math::vector2 &v) const

   * virtual double interpolate(const double x[]) const

   * virtual double interpolate(const double x[], unsigned int deriv,
     unsigned int dimension) const

   * math::vector2 interpolate_deriv(const math::vector2 &v) const

   * void resize(unsigned int n1, unsigned int n2)

   * void set_all_d(const math::vector2 &deriv = _[...]_)

   * void set_all_y(double y = _[...]_)

   * virtual void set_interpolation(Interpolation i)

   * void set_metrics(const math::vector2 &origin, const math::vector2
     &step)

data::Plot class reference
==========================

Declaration
-----------

     #include <goptical/core/data/Plot>

     namespace goptical {
       namespace data {
         class Plot;
       };
     };

   This class is a member of the data namespace.

Inheritance
-----------

Description
-----------

This class is used to describe a data plot. It contains a list of
Plotdata (*note data_Plotdata_class_reference::) objects and describes
some plot properties (title, range, ...).

   Plots can be built from data sets or obtained directly from various
analysis functions. They can be rendered on a io::renderer_viewport
(*note io_renderer_viewport_class_reference::) object with the draw
(*note _183::) function.

Members
-------

See also the full member list (*note
data_Plot_class_full_member_list::) section for this class.

Functions
.........

   * Plot()

   * Plotdata & add_plot_data(const Set &data, const io::rgb &color =
     _[...]_, const std::string &label = _[...]_, PlotStyleMask style =
     _[...]_)

   * void add_plot_data(Plotdata &data)

   * void draw(io::renderer_viewport &r)

   * void erase_plot_data()

   * void fit_axes_range()

   * io::RendererAxes & get_axes()

   * const io::RendererAxes & get_axes() const

   * unsigned int get_dimensions() const

   * unsigned int get_plot_count() const

   * Plotdata & get_plot_data(unsigned int index)

   * const Plotdata & get_plot_data(unsigned int index) const

   * const std::string & get_title() const

   * math::range_t get_x_data_range(unsigned int dimension = _[...]_)
     const

   * bool get_xy_swap() const

   * math::range_t get_y_data_range() const

   * void set_color(const io::rgb &color)

   * void set_different_colors()

   * void set_style(PlotStyleMask style)

   * void set_title(const std::string &title)

   * void set_xy_swap(bool doswap)

Members detail
--------------

Plot()
......

Create a new empty plot

Plotdata & add_plot_data(const Set &data, const io::rgb &color = io::rgb_red, const std:: string  &label = "data", PlotStyleMask style = InterpolatePlot|PointPlot)
...................................................................................................................................................................

Create and add plot data from specified data set.

void add_plot_data(Plotdata &data)
..................................

Add plot data

void draw(io::renderer_viewport &r)
..................................

draw

void erase_plot_data()
......................

Discard all plot data set

void fit_axes_range()
.....................

Set axis position to dataset range

io::RendererAxes & get_axes()
.............................

Get plot axes object

const io::RendererAxes & get_axes() const
.........................................

Get plot axes object

unsigned int get_dimensions() const
...................................

Get data sets dimensions, return 0 if inconsistent

unsigned int get_plot_count() const
...................................

Get plot data set count

Plotdata & get_plot_data(unsigned int index)
............................................

Get plot data set at given index

const Plotdata & get_plot_data(unsigned int index) const
........................................................

Get plot data set at given index

const std:: string  & get_title() const
.......................................

Get plot main title

math::range_t get_x_data_range(unsigned int dimension = 0) const
................................................................

Get range of x data in sets

bool get_xy_swap() const
........................

Get x and y axis swap state for 2d plots

math::range_t get_y_data_range() const
......................................

Get range of y data in sets

void set_color(const io::rgb &color)
....................................

Set color for all plots

void set_different_colors()
...........................

Automatically choose different colors for each plot

void set_style(PlotStyleMask style)
...................................

Set plot style for all plot

void set_title(const std:: string  &title)
..........................................

Set plot main title

void set_xy_swap(bool doswap)
.............................

Swap x and y axis for 2d plots

data::Plot class full member list
=================================

Functions
---------

   * Plot()

   * Plotdata & add_plot_data(const Set &data, const io::rgb &color =
     _[...]_, const std::string &label = _[...]_, PlotStyleMask style =
     _[...]_)

   * void add_plot_data(Plotdata &data)

   * void draw(io::renderer_viewport &r)

   * void erase_plot_data()

   * void fit_axes_range()

   * io::RendererAxes & get_axes()

   * const io::RendererAxes & get_axes() const

   * unsigned int get_dimensions() const

   * unsigned int get_plot_count() const

   * Plotdata & get_plot_data(unsigned int index)

   * const Plotdata & get_plot_data(unsigned int index) const

   * const std::string & get_title() const

   * math::range_t get_x_data_range(unsigned int dimension = _[...]_)
     const

   * bool get_xy_swap() const

   * math::range_t get_y_data_range() const

   * void set_color(const io::rgb &color)

   * void set_different_colors()

   * void set_style(PlotStyleMask style)

   * void set_title(const std::string &title)

   * void set_xy_swap(bool doswap)

data::Plotdata class reference
==============================

Declaration
-----------

     #include <goptical/core/data/Plotdata>

     namespace goptical {
       namespace data {
         class Plotdata;
       };
     };

   This class is a member of the data namespace.

Description
-----------

This class is used to describe a data set as part of a data plot. It
contains a pointer to the data set and plotting informations (title,
color, ...)

Members
-------

See also the full member list (*note
data_Plotdata_class_full_member_list::) section for this class.

Functions
.........

   * Plotdata(const const_ref<Set> &s)

   * void disable_style(PlotStyleMask style)

   * void enable_style(PlotStyleMask style)

   * const io::rgb & get_color() const

   * const std::string & get_label() const

   * const Set & get_set() const

   * PlotStyleMask get_style() const

   * void set_color(const io::rgb &color)

   * void set_label(const std::string &title)

   * void set_style(PlotStyleMask style)

Members detail
--------------

Plotdata(const  const_ref <Set> &s)
...................................

Create a new data plot descriptor which describe the specified dataset.

void disable_style(PlotStyleMask style)
.......................................

Disable a plotting style

void enable_style(PlotStyleMask style)
......................................

Enable a plotting style

const io::rgb & get_color() const
.................................

Set data set plotting color

const std:: string  & get_label() const
.......................................

Get data set plotting label

const Set & get_set() const
...........................

Get the described data set

PlotStyleMask get_style() const
...............................

Get the plotting style mask

void set_color(const io::rgb &color)
....................................

Set data set plotting color

void set_label(const std:: string  &title)
..........................................

Set data set plotting label

void set_style(PlotStyleMask style)
...................................

Set the plotting style mask

data::Plotdata class full member list
=====================================

Functions
---------

   * Plotdata(const const_ref<Set> &s)

   * void disable_style(PlotStyleMask style)

   * void enable_style(PlotStyleMask style)

   * const io::rgb & get_color() const

   * const std::string & get_label() const

   * const Set & get_set() const

   * PlotStyleMask get_style() const

   * void set_color(const io::rgb &color)

   * void set_label(const std::string &title)

   * void set_style(PlotStyleMask style)

data::SampleSet class reference
===============================

Declaration
-----------

     #include <goptical/core/data/SampleSet>

     namespace goptical {
       namespace data {
         class SampleSet;
       };
     };

   This class is a member of the data namespace.

Inheritance
-----------

Description
-----------

This class provides a numerical data container where sample values (y)
are defined for uniformly distributed (x) values.

   Severals interpolation algorithms are available to guess values
between defined knots, see Interpolation (*note _146::).

   See also DiscreteSet (*note data_DiscreteSet_class_reference::)
class.

Members
-------

See also the full member list (*note
data_SampleSet_class_full_member_list::) section for this class.

Inherited members
.................

   * 19 members inherited from Set1d (*note
     data_Set1d_class_reference::)

Functions
.........

   * SampleSet()

   * void clear()

   * virtual unsigned int get_count() const

   * double get_d_value(unsigned int x) const

   * double & get_d_value(unsigned int x)

   * double get_origin() const

   * double get_step() const

   * virtual math::range_t get_x_range() const

   * virtual double get_x_value(unsigned int x) const

   * virtual double get_y_value(unsigned int x) const

   * virtual double & get_y_value(unsigned int x)

   * virtual double interpolate(const double x) const

   * virtual double interpolate(const double x, unsigned int deriv)
     const

   * void resize(unsigned int n)

   * virtual void set_interpolation(Interpolation i)

   * void set_metrics(double origin, double step)

   * void set_value(unsigned int x, double y, double d = _[...]_)

   * void set_value_near(double x, double y, double d = _[...]_)

Members detail
--------------

SampleSet()
...........

No documentation available

data::SampleSet class full member list
======================================

Functions
---------

   * SampleSet()

   * void clear()

   * virtual unsigned int get_count(unsigned int dim) const

   * virtual unsigned int get_count() const

   * double get_d_value(unsigned int x) const

   * double & get_d_value(unsigned int x)

   * virtual unsigned int get_dimensions() const

   * Interpolation get_interpolation()

   * double get_origin() const

   * double get_step() const

   * unsigned int get_version() const

   * virtual math::range_t get_x_range(unsigned int dimension) const

   * virtual math::range_t get_x_range() const

   * virtual double get_x_value(unsigned int n, unsigned int dim) const

   * virtual double get_x_value(unsigned int x) const

   * virtual math::range_t get_y_range() const

   * virtual double get_y_value(const unsigned int x[]) const

   * virtual double get_y_value(unsigned int x) const

   * virtual double & get_y_value(unsigned int x)

   * virtual double interpolate(const double x[]) const

   * virtual double interpolate(const double x[], unsigned int deriv,
     unsigned int dimension) const

   * virtual double interpolate(const double x) const

   * virtual double interpolate(const double x, unsigned int deriv)
     const

   * void resize(unsigned int n)

   * virtual void set_interpolation(Interpolation i)

   * void set_metrics(double origin, double step)

   * void set_value(unsigned int x, double y, double d = _[...]_)

   * void set_value_near(double x, double y, double d = _[...]_)

data::Interpolate1d<data::DiscreteSetBase> internal class members
=================================================================

Interpolate1d()
---------------

No documentation available

virtual double interpolate(const double x) const
------------------------------------------------

This virtual function implements the `interpolate (*note _245::)' pure
function declared in the `Set1d (*note data_Set1d_class_reference::)'
base abstract class.

virtual double interpolate(const double x, unsigned int deriv) const
--------------------------------------------------------------------

This virtual function implements the `interpolate (*note _246::)' pure
function declared in the `Set1d (*note data_Set1d_class_reference::)'
base abstract class.

virtual void set_interpolation(Interpolation i)
-----------------------------------------------

This virtual function implements the `set_interpolation (*note _233::)'
pure function declared in the `Set (*note data_Set_class_reference::)'
base abstract class.

~Interpolate1d()
----------------

No documentation available

data::Interpolate1d<data::SampleSetBase> internal class members
===============================================================

Interpolate1d()
---------------

No documentation available

virtual double interpolate(const double x) const
------------------------------------------------

This virtual function implements the `interpolate (*note _245::)' pure
function declared in the `Set1d (*note data_Set1d_class_reference::)'
base abstract class.

virtual double interpolate(const double x, unsigned int deriv) const
--------------------------------------------------------------------

This virtual function implements the `interpolate (*note _246::)' pure
function declared in the `Set1d (*note data_Set1d_class_reference::)'
base abstract class.

virtual void set_interpolation(Interpolation i)
-----------------------------------------------

This virtual function implements the `set_interpolation (*note _233::)'
pure function declared in the `Set (*note data_Set_class_reference::)'
base abstract class.

~Interpolate1d()
----------------

No documentation available

data::Set class reference
=========================

Declaration
-----------

     #include <goptical/core/data/Set>

     namespace goptical {
       namespace data {
         class Set;
       };
     };

   This class is a member of the data namespace.

   This abstract class contains pure virtuals.

Inheritance
-----------

Description
-----------

This class is a base class for all numerical data sets implementations.
It defines an interface to access data in a way independent from data
storage and dimensions count.

   Each data set implementation may define a alternative specific
interface to access their data.

   Here x is seen as value used to access the container. Containers
with more than one dimension will require x0, x1, ..., xn known
parameters to access the stored y value.

Members
-------

See also the full member list (*note data_Set_class_full_member_list::)
section for this class.

Functions
.........

   * virtual ~Set()

   * virtual unsigned int get_count(unsigned int dim = _[...]_) const =
     0;

   * virtual unsigned int get_dimensions() const = 0;

   * Interpolation get_interpolation()

   * unsigned int get_version() const

   * virtual math::range_t get_x_range(unsigned int dim = _[...]_)
     const = 0;

   * virtual double get_x_value(unsigned int n, unsigned int dim =
     _[...]_) const = 0;

   * virtual math::range_t get_y_range() const

   * virtual double get_y_value(const unsigned int x[]) const = 0;

   * virtual double interpolate(const double x[]) const = 0;

   * virtual double interpolate(const double x[], unsigned int deriv,
     unsigned int dim) const = 0;

   * virtual void set_interpolation(Interpolation i) = 0;

Members detail
--------------

virtual ~Set()
..............

No documentation available

virtual unsigned int get_count(unsigned int dim = 0) const = 0;
...............................................................

Get total number of data stored for dimension n in data set

virtual unsigned int get_dimensions() const = 0;
................................................

Get total number of dimensions

Interpolation get_interpolation()
.................................

Get current interpolation method

unsigned int get_version() const
................................

Return version number which is incremented on each data set change/clear

virtual math::range_t get_x_range(unsigned int dim = 0) const = 0;
..................................................................

Get minimal and maximal x values on dimension n found in data set

virtual double get_x_value(unsigned int n, unsigned int dim = 0) const = 0;
...........................................................................

Get data stored at position n on dimension dim in data set

virtual math::range_t get_y_range() const
.........................................

Get minimal and maximal y values found in data set

virtual double get_y_value(const unsigned int x[]) const = 0;
.............................................................

Get y data stored at position (x0, x1, ...) in data set

virtual double interpolate(const double x[]) const = 0;
.......................................................

Interpolate y value corresponding to given x value(s) in data set.

virtual double interpolate(const double x[], unsigned int deriv, unsigned int dim) const = 0;
.............................................................................................

Interpolate y value corresponding to given x value in data set. data
may be differentiated several times along the requested dimension.

   * deriv: Differentiation count, 0 means y value, 1 means 1st
     derivative...

   * dim: Differentiation dimension

virtual void set_interpolation(Interpolation i) = 0;
....................................................

Select interpolation method

data::Set class full member list
================================

Functions
---------

   * virtual ~Set()

   * virtual unsigned int get_count(unsigned int dim = _[...]_) const =
     0;

   * virtual unsigned int get_dimensions() const = 0;

   * Interpolation get_interpolation()

   * unsigned int get_version() const

   * virtual math::range_t get_x_range(unsigned int dim = _[...]_)
     const = 0;

   * virtual double get_x_value(unsigned int n, unsigned int dim =
     _[...]_) const = 0;

   * virtual math::range_t get_y_range() const

   * virtual double get_y_value(const unsigned int x[]) const = 0;

   * virtual double interpolate(const double x[]) const = 0;

   * virtual double interpolate(const double x[], unsigned int deriv,
     unsigned int dim) const = 0;

   * virtual void set_interpolation(Interpolation i) = 0;

data::Set1d class reference
===========================

Declaration
-----------

     #include <goptical/core/data/Set1d>

     namespace goptical {
       namespace data {
         class Set1d;
       };
     };

   This class is a member of the data namespace.

   This abstract class contains pure virtuals.

Inheritance
-----------

Description
-----------

Base class for 1d y = f(x) numerical data set

Members
-------

See also the full member list (*note
data_Set1d_class_full_member_list::) section for this class.

Inherited members
.................

   * 12 members inherited from Set (*note data_Set_class_reference::)

Functions
.........

   * virtual ~Set1d()

   * virtual unsigned int get_count() const = 0;

   * virtual unsigned int get_count(unsigned int dim) const

   * virtual unsigned int get_dimensions() const

   * virtual math::range_t get_x_range() const = 0;

   * virtual math::range_t get_x_range(unsigned int dimension) const

   * virtual double get_x_value(unsigned int n) const = 0;

   * virtual double get_x_value(unsigned int n, unsigned int dim) const

   * virtual double get_y_value(unsigned int n) const = 0;

   * virtual double & get_y_value(unsigned int n) = 0;

   * virtual double get_y_value(const unsigned int x[]) const

   * virtual double interpolate(const double x) const = 0;

   * virtual double interpolate(const double x, unsigned int deriv)
     const = 0;

   * virtual double interpolate(const double x[]) const

   * virtual double interpolate(const double x[], unsigned int deriv,
     unsigned int dimension) const

Members detail
--------------

virtual ~Set1d()
................

No documentation available

virtual unsigned int get_count() const = 0;
...........................................

Get total number of data stored in data set

virtual unsigned int get_count(unsigned int dim) const
......................................................

This virtual function implements the `get_count (*note _223::)' pure
function declared in the `Set (*note data_Set_class_reference::)' base
abstract class.

   Documentation inherited from base class:

   Get total number of data stored for dimension n in data set

virtual unsigned int get_dimensions() const
...........................................

This virtual function implements the `get_dimensions (*note _224::)'
pure function declared in the `Set (*note data_Set_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get total number of dimensions

virtual math::range_t get_x_range() const = 0;
..............................................

Get minimal and maximal x values on found in data set

virtual math::range_t get_x_range(unsigned int dimension) const
...............................................................

This virtual function implements the `get_x_range (*note _227::)' pure
function declared in the `Set (*note data_Set_class_reference::)' base
abstract class.

   Documentation inherited from base class:

   Get minimal and maximal x values on dimension n found in data set

virtual double get_x_value(unsigned int n) const = 0;
.....................................................

Get x data at index n in data set

virtual double get_x_value(unsigned int n, unsigned int dim) const
..................................................................

This virtual function implements the `get_x_value (*note _228::)' pure
function declared in the `Set (*note data_Set_class_reference::)' base
abstract class.

   Documentation inherited from base class:

   Get data stored at position n on dimension dim in data set

virtual double get_y_value(unsigned int n) const = 0;
.....................................................

Get y data stored at index n in data set

virtual double & get_y_value(unsigned int n) = 0;
.................................................

Get modifiable reference to y data stored at index n in data set

virtual double get_y_value(const unsigned int x[]) const
........................................................

This virtual function implements the `get_y_value (*note _230::)' pure
function declared in the `Set (*note data_Set_class_reference::)' base
abstract class.

   Documentation inherited from base class:

   Get y data stored at position (x0, x1, ...) in data set

virtual double interpolate(const double x) const = 0;
.....................................................

Interpolate y value corresponding to given x value in data set.

virtual double interpolate(const double x, unsigned int deriv) const = 0;
.........................................................................

Interpolate y value corresponding to given x value in data set. data
may be differentiated several times.

   * deriv: Differentiation count, 0 means y value, 1 means 1st
     derivative...

virtual double interpolate(const double x[]) const
..................................................

This virtual function implements the `interpolate (*note _231::)' pure
function declared in the `Set (*note data_Set_class_reference::)' base
abstract class.

   Documentation inherited from base class:

   Interpolate y value corresponding to given x value(s) in data set.

virtual double interpolate(const double x[], unsigned int deriv, unsigned int dimension) const
..............................................................................................

This virtual function implements the `interpolate (*note _232::)' pure
function declared in the `Set (*note data_Set_class_reference::)' base
abstract class.

   Documentation inherited from base class:

   Interpolate y value corresponding to given x value in data set. data
may be differentiated several times along the requested dimension.

   * deriv: Differentiation count, 0 means y value, 1 means 1st
     derivative...

   * dim: Differentiation dimension

data::Set1d class full member list
==================================

Functions
---------

   * virtual ~Set1d()

   * virtual unsigned int get_count() const = 0;

   * virtual unsigned int get_count(unsigned int dim) const

   * virtual unsigned int get_dimensions() const

   * Interpolation get_interpolation()

   * unsigned int get_version() const

   * virtual math::range_t get_x_range() const = 0;

   * virtual math::range_t get_x_range(unsigned int dimension) const

   * virtual double get_x_value(unsigned int n) const = 0;

   * virtual double get_x_value(unsigned int n, unsigned int dim) const

   * virtual math::range_t get_y_range() const

   * virtual double get_y_value(unsigned int n) const = 0;

   * virtual double & get_y_value(unsigned int n) = 0;

   * virtual double get_y_value(const unsigned int x[]) const

   * virtual double interpolate(const double x) const = 0;

   * virtual double interpolate(const double x, unsigned int deriv)
     const = 0;

   * virtual double interpolate(const double x[]) const

   * virtual double interpolate(const double x[], unsigned int deriv,
     unsigned int dimension) const

   * virtual void set_interpolation(Interpolation i) = 0;

data::DiscreteSetBase internal class members
============================================

DiscreteSetBase()
-----------------

No documentation available

~DiscreteSetBase()
------------------

No documentation available

void add_data(double x, double y, double yp = 0.0)
--------------------------------------------------

Insert data pair in data set. If a pair with the same x value exists,
it will be replaced by the new value. Derivative value may be provided
as well.

void clear()
------------

Clear all data

virtual unsigned int get_count() const
--------------------------------------

This virtual function implements the `get_count (*note _235::)' pure
function declared in the `Set1d (*note data_Set1d_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get total number of data stored in data set

double get_d_value(unsigned int x) const
----------------------------------------

Get stored derivative value at index x

double & get_d_value(unsigned int x)
------------------------------------

Get modifiable reference to stored derivative value at index x

virtual math::range_t get_x_range() const
-----------------------------------------

This virtual function implements the `get_x_range (*note _238::)' pure
function declared in the `Set1d (*note data_Set1d_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get minimal and maximal x values on found in data set

virtual double get_x_value(unsigned int x) const
------------------------------------------------

This virtual function implements the `get_x_value (*note _240::)' pure
function declared in the `Set1d (*note data_Set1d_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get x data at index n in data set

virtual double get_y_value(unsigned int x) const
------------------------------------------------

This virtual function implements the `get_y_value (*note _242::)' pure
function declared in the `Set1d (*note data_Set1d_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get y data stored at index n in data set

virtual double & get_y_value(unsigned int x)
--------------------------------------------

This virtual function implements the `get_y_value (*note _243::)' pure
function declared in the `Set1d (*note data_Set1d_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get modifiable reference to y data stored at index n in data set

void reserve( size_t  n)
------------------------

Reserve data entries

data::Interpolate1d internal class members
==========================================

Interpolate1d()
---------------

No documentation available

~Interpolate1d()
----------------

No documentation available

double interpolate(const double x) const
----------------------------------------

No documentation available

double interpolate(const double x, unsigned int deriv) const
------------------------------------------------------------

No documentation available

void set_interpolation(Interpolation i)
---------------------------------------

No documentation available

data::SampleSetBase internal class members
==========================================

SampleSetBase()
---------------

No documentation available

~SampleSetBase()
----------------

No documentation available

void clear()
------------

Clear all data

virtual unsigned int get_count() const
--------------------------------------

This virtual function implements the `get_count (*note _235::)' pure
function declared in the `Set1d (*note data_Set1d_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get total number of data stored in data set

double get_d_value(unsigned int x) const
----------------------------------------

Get stored derivative value at index x

double & get_d_value(unsigned int x)
------------------------------------

Get modifiable reference to stored derivative value at index x

double get_origin() const
-------------------------

Get x value of first sample

double get_step() const
-----------------------

Get step size between consecutive x values

virtual math::range_t get_x_range() const
-----------------------------------------

This virtual function implements the `get_x_range (*note _238::)' pure
function declared in the `Set1d (*note data_Set1d_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get minimal and maximal x values on found in data set

virtual double get_x_value(unsigned int x) const
------------------------------------------------

This virtual function implements the `get_x_value (*note _240::)' pure
function declared in the `Set1d (*note data_Set1d_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get x data at index n in data set

virtual double get_y_value(unsigned int x) const
------------------------------------------------

This virtual function implements the `get_y_value (*note _242::)' pure
function declared in the `Set1d (*note data_Set1d_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get y data stored at index n in data set

virtual double & get_y_value(unsigned int x)
--------------------------------------------

This virtual function implements the `get_y_value (*note _243::)' pure
function declared in the `Set1d (*note data_Set1d_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get modifiable reference to y data stored at index n in data set

void resize(unsigned int n)
---------------------------

Set number of samples

void set_metrics(double origin, double step)
--------------------------------------------

Set x origin and step values

void set_value(unsigned int x, double y, double d = 0.0)
--------------------------------------------------------

Set y value and its derivative at index x

void set_value_near(double x, double y, double d = 0.0)
-------------------------------------------------------

Set y value and its derivative at nearest x value

Design namespace reference
==========================

Description
-----------

Design module classes

Members
-------

Namespace
.........

   * telescope

Design::telescope namespace reference
=====================================

Description
-----------

telescope designs

Members
-------

Types
.....

   * template class Cassegrain

   * enum CassegrainType

   * class Newton

   * class telescope

Members detail
--------------

enum CassegrainType
...................

Specify Cassegrain telescope type

Identifier             Description
-------------------------------------------------------------------------- 
ClassicalCassegrain    
RitcheyChretien        
DallKirkham            
PressmannCamichel      

Design::telescope::Cassegrain class reference
=============================================

Declaration
-----------

     #include <goptical/core/Design/telescope/Cassegrain>

     namespace goptical {
       namespace Design {
         namespace telescope {
           template <CassegrainType type> class Cassegrain;
         };
       };
     };

   This class is a member of the telescope namespace.

Inheritance
-----------

Description
-----------

This class is a group of optical elements forming a Cassegrain
telescope. Optical elements are adjusted as needed from prescribed
telescope parameters.

   The CassegrainType (*note _282::) enum specifies type of Cassegrain
telescope.

Members
-------

See also the full member list (*note
Design_telescope_Cassegrain_class_full_member_list::) section for this
class.

Inherited members
.................

   * 60 members inherited from telescope (*note
     Design_telescope_telescope_class_reference::)

Functions
.........

   * Cassegrain(const math::vectorPair3 &p, double focal, double
     diameter, double magnification = _[...]_, double bwd = _[...]_,
     double field_angle = _[...]_)

   * virtual double get_bwd() const

   * virtual double get_diameter() const

   * virtual double get_field_angle() const

   * virtual double get_focal() const

   * virtual math::vectorPair3 get_focal_plane() const

   * double get_magnification() const

   * double get_mirrors_separation() const

   * const sys::mirror & get_primary() const

   * sys::mirror & get_primary()

   * double get_primary_conic() const

   * const sys::mirror & get_secondary() const

   * sys::mirror & get_secondary()

   * double get_secondary_conic() const

   * double get_secondary_diameter() const

   * virtual double get_unvignetted_image_diameter() const

   * virtual void set_bwd(double e)

   * virtual void set_diameter(double d1)

   * virtual void set_field_angle(double fa)

   * virtual void set_focal(double f)

   * void set_magnification(double m)

   * void set_secondary_diameter(double d2)

Members detail
--------------

Cassegrain(const math::vectorPair3 &p, double focal, double diameter, double magnification = 3., double bwd = 100, double field_angle = 1.)
...........................................................................................................................................

No documentation available

virtual double get_bwd() const
..............................

This virtual function implements the `get_bwd (*note _325::)' pure
function declared in the `telescope (*note
Design_telescope_telescope_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get telescope back working distance

virtual double get_diameter() const
...................................

This virtual function implements the `get_diameter (*note _326::)' pure
function declared in the `telescope (*note
Design_telescope_telescope_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get telescope primary mirror diameter

virtual double get_field_angle() const
......................................

This virtual function implements the `get_field_angle (*note _327::)'
pure function declared in the `telescope (*note
Design_telescope_telescope_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get telescope field angle

virtual double get_focal() const
................................

This virtual function implements the `get_focal (*note _328::)' pure
function declared in the `telescope (*note
Design_telescope_telescope_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get telescope focal length

virtual math::vectorPair3 get_focal_plane() const
.................................................

This virtual function implements the `get_focal_plane (*note _329::)'
pure function declared in the `telescope (*note
Design_telescope_telescope_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get telescope focal plane in parent coordinate system

double get_magnification() const
................................

Get telescope secondary mirror magnification

double get_mirrors_separation() const
.....................................

Get distance between mirrors

const sys::mirror & get_primary() const
.......................................

Get telescope primary mirror component

sys::mirror & get_primary()
...........................

Get telescope primary mirror component

double get_primary_conic() const
................................

Get primary mirror schwarzschild constant

const sys::mirror & get_secondary() const
.........................................

Get telescope secondary mirror component

sys::mirror & get_secondary()
.............................

Get telescope secondary mirror component

double get_secondary_conic() const
..................................

Get secondary mirror schwarzschild constant

double get_secondary_diameter() const
.....................................

Get telescope secondary mirror diameter

virtual double get_unvignetted_image_diameter() const
.....................................................

This virtual function implements the `get_unvignetted_image_diameter
(*note _330::)' pure function declared in the `telescope (*note
Design_telescope_telescope_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get diameter of unvignetted image on focal plane

virtual void set_bwd(double e)
..............................

This virtual function implements the `set_bwd (*note _331::)' pure
function declared in the `telescope (*note
Design_telescope_telescope_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Set telescope back working distance

virtual void set_diameter(double d1)
....................................

This virtual function implements the `set_diameter (*note _332::)' pure
function declared in the `telescope (*note
Design_telescope_telescope_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Set telescope primary mirror diameter

virtual void set_field_angle(double fa)
.......................................

This virtual function implements the `set_field_angle (*note _333::)'
pure function declared in the `telescope (*note
Design_telescope_telescope_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Set telescope field angle

virtual void set_focal(double f)
................................

This virtual function implements the `set_focal (*note _334::)' pure
function declared in the `telescope (*note
Design_telescope_telescope_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Set telescope focal length

void set_magnification(double m)
................................

Set telescope secondary mirror magnification

void set_secondary_diameter(double d2)
......................................

Set telescope secondary mirror diameter

Design::telescope::Cassegrain class full member list
====================================================

Types
-----

   * typedef _ [...] _ element_list_t

   * typedef _ [...] _ mod_delegate_t

   * typedef _ [...] _ put_delegate_t

Functions
---------

   * Cassegrain(const math::vectorPair3 &p, double focal, double
     diameter, double magnification = _[...]_, double bwd = _[...]_,
     double field_angle = _[...]_)

   * void add(const ref<sys::Element> &e)

   * template bool contains(const X *x) const

   * void draw_2d(io::Renderer &r) const

   * void draw_2d_fit(io::renderer_viewport &r, bool keep_aspect =
     _[...]_) const

   * void draw_3d(io::Renderer &r) const

   * void draw_3d_fit(io::renderer_viewport &r, double z_offset =
     _[...]_) const

   * template void enable_single(const X &e)

   * template X * find() const

   * virtual math::vectorPair3 get_bounding_box() const

   * virtual double get_bwd() const

   * virtual double get_diameter() const

   * math::vector3 get_direction(const sys::Element &e) const

   * math::vector3 get_direction() const

   * const sys::Container::element_list_t & get_element_list() const

   * template void get_elements(const delegate<void(const X&)> &d) const

   * template void get_elements(const delegate<void(X&)> &d)

   * virtual double get_field_angle() const

   * virtual double get_focal() const

   * virtual math::vectorPair3 get_focal_plane() const

   * const math::Transform<3> & get_global_transform() const

   * math::vector3 get_local_direction() const

   * math::vectorPair3 get_local_plane() const

   * const math::vector3 & get_local_position() const

   * const math::Transform<3> & get_local_transform() const

   * double get_magnification() const

   * double get_mirrors_separation() const

   * sys::Group * get_parent() const

   * math::vectorPair3 get_plane() const

   * math::vectorPair3 get_plane(const sys::Element &e) const

   * math::vector3 get_position(const sys::Element &e) const

   * math::vector3 get_position() const

   * const sys::mirror & get_primary() const

   * sys::mirror & get_primary()

   * double get_primary_conic() const

   * const sys::mirror & get_secondary() const

   * sys::mirror & get_secondary()

   * double get_secondary_conic() const

   * double get_secondary_diameter() const

   * sys::system * get_system() const

   * const math::Transform<3> & get_transform() const

   * const math::Transform<3> & get_transform_from(const sys::Element
     &e) const

   * const math::Transform<3> & get_transform_from(const sys::Element
     *e) const

   * const math::Transform<3> & get_transform_to(const sys::Element &e)
     const

   * const math::Transform<3> & get_transform_to(const sys::Element *e)
     const

   * virtual double get_unvignetted_image_diameter() const

   * unsigned int get_version() const

   * unsigned int id() const

   * bool is_enabled() const

   * virtual void print(std::ostream &o) const

   * template void process_rays(trace::Result &result,
     trace::rays_queue_t *input) const

   * void remove(sys::Element &e)

   * void rotate(double x, double y, double z)

   * virtual void set_bwd(double e)

   * virtual void set_diameter(double d1)

   * void set_direction(const math::vector3 &v)

   * void set_enable_state(bool enabled)

   * virtual void set_field_angle(double fa)

   * virtual void set_focal(double f)

   * void set_local_direction(const math::vector3 &v)

   * void set_local_plane(const math::vectorPair3 &p)

   * void set_local_position(const math::vector3 &v)

   * void set_magnification(double m)

   * void set_plane(const math::vectorPair3 &p)

   * void set_position(const math::vector3 &v)

   * void set_secondary_diameter(double d2)

   * void set_transform(const math::Transform<3> &t)

   * void update_version()

Design::telescope::Newton class reference
=========================================

Declaration
-----------

     #include <goptical/core/Design/telescope/Newton>

     namespace goptical {
       namespace Design {
         namespace telescope {
           class Newton;
         };
       };
     };

   This class is a member of the telescope namespace.

Inheritance
-----------

Description
-----------

This class is a group of optical elements forming a Newton telescope.
Optical elements are adjusted as needed from prescribed telescope
parameters.

   See also A newton telescope with corrector (*note A newton telescope
with corrector::) section.

Members
-------

See also the full member list (*note
Design_telescope_Newton_class_full_member_list::) section for this
class.

Inherited members
.................

   * 60 members inherited from telescope (*note
     Design_telescope_telescope_class_reference::)

Functions
.........

   * Newton(const math::vectorPair3 &p, double focal, double diameter,
     double bwd = _[...]_, double field_angle = _[...]_)

   * virtual double get_bwd() const

   * virtual double get_diameter() const

   * virtual double get_field_angle() const

   * virtual double get_focal() const

   * virtual math::vectorPair3 get_focal_plane() const

   * sys::mirror & get_primary()

   * const sys::mirror & get_primary() const

   * sys::mirror & get_secondary()

   * const sys::mirror & get_secondary() const

   * double get_secondary_major_axis() const

   * double get_secondary_minor_axis() const

   * double get_secondary_offset() const

   * virtual double get_unvignetted_image_diameter() const

   * virtual void set_bwd(double bwd)

   * virtual void set_diameter(double diameter)

   * virtual void set_field_angle(double fa)

   * virtual void set_focal(double focal)

   * void set_secondary_minor_axis(double diameter)

Members detail
--------------

Newton(const math::vectorPair3 &p, double focal, double diameter, double bwd = 100, double field_angle = 1.)
............................................................................................................

No documentation available

virtual double get_bwd() const
..............................

This virtual function implements the `get_bwd (*note _325::)' pure
function declared in the `telescope (*note
Design_telescope_telescope_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get telescope back working distance

virtual double get_diameter() const
...................................

This virtual function implements the `get_diameter (*note _326::)' pure
function declared in the `telescope (*note
Design_telescope_telescope_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get telescope primary mirror diameter

virtual double get_field_angle() const
......................................

This virtual function implements the `get_field_angle (*note _327::)'
pure function declared in the `telescope (*note
Design_telescope_telescope_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get telescope field angle

virtual double get_focal() const
................................

This virtual function implements the `get_focal (*note _328::)' pure
function declared in the `telescope (*note
Design_telescope_telescope_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get telescope focal length

virtual math::vectorPair3 get_focal_plane() const
.................................................

This virtual function implements the `get_focal_plane (*note _329::)'
pure function declared in the `telescope (*note
Design_telescope_telescope_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get telescope focal plane in parent coordinate system

sys::mirror & get_primary()
...........................

Get telescope primary mirror component

const sys::mirror & get_primary() const
.......................................

Get telescope primary mirror component

sys::mirror & get_secondary()
.............................

Get telescope secondary mirror component

const sys::mirror & get_secondary() const
.........................................

Get telescope secondary mirror component

double get_secondary_major_axis() const
.......................................

Get secondary mirror major axis length

double get_secondary_minor_axis() const
.......................................

Get secondary mirror minor axis length

double get_secondary_offset() const
...................................

Get secondary mirror offset

virtual double get_unvignetted_image_diameter() const
.....................................................

This virtual function implements the `get_unvignetted_image_diameter
(*note _330::)' pure function declared in the `telescope (*note
Design_telescope_telescope_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get diameter of unvignetted image on focal plane

virtual void set_bwd(double bwd)
................................

This virtual function implements the `set_bwd (*note _331::)' pure
function declared in the `telescope (*note
Design_telescope_telescope_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Set telescope back working distance

virtual void set_diameter(double diameter)
..........................................

This virtual function implements the `set_diameter (*note _332::)' pure
function declared in the `telescope (*note
Design_telescope_telescope_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Set telescope primary mirror diameter

virtual void set_field_angle(double fa)
.......................................

This virtual function implements the `set_field_angle (*note _333::)'
pure function declared in the `telescope (*note
Design_telescope_telescope_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Set telescope field angle

virtual void set_focal(double focal)
....................................

This virtual function implements the `set_focal (*note _334::)' pure
function declared in the `telescope (*note
Design_telescope_telescope_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Set telescope focal length

void set_secondary_minor_axis(double diameter)
..............................................

Set telescope secondary mirror diameter

Design::telescope::Newton class full member list
================================================

Types
-----

   * typedef _ [...] _ element_list_t

   * typedef _ [...] _ mod_delegate_t

   * typedef _ [...] _ put_delegate_t

Functions
---------

   * Newton(const math::vectorPair3 &p, double focal, double diameter,
     double bwd = _[...]_, double field_angle = _[...]_)

   * void add(const ref<sys::Element> &e)

   * template bool contains(const X *x) const

   * void draw_2d(io::Renderer &r) const

   * void draw_2d_fit(io::renderer_viewport &r, bool keep_aspect =
     _[...]_) const

   * void draw_3d(io::Renderer &r) const

   * void draw_3d_fit(io::renderer_viewport &r, double z_offset =
     _[...]_) const

   * template void enable_single(const X &e)

   * template X * find() const

   * virtual math::vectorPair3 get_bounding_box() const

   * virtual double get_bwd() const

   * virtual double get_diameter() const

   * math::vector3 get_direction(const sys::Element &e) const

   * math::vector3 get_direction() const

   * const sys::Container::element_list_t & get_element_list() const

   * template void get_elements(const delegate<void(const X&)> &d) const

   * template void get_elements(const delegate<void(X&)> &d)

   * virtual double get_field_angle() const

   * virtual double get_focal() const

   * virtual math::vectorPair3 get_focal_plane() const

   * const math::Transform<3> & get_global_transform() const

   * math::vector3 get_local_direction() const

   * math::vectorPair3 get_local_plane() const

   * const math::vector3 & get_local_position() const

   * const math::Transform<3> & get_local_transform() const

   * sys::Group * get_parent() const

   * math::vectorPair3 get_plane() const

   * math::vectorPair3 get_plane(const sys::Element &e) const

   * math::vector3 get_position(const sys::Element &e) const

   * math::vector3 get_position() const

   * sys::mirror & get_primary()

   * const sys::mirror & get_primary() const

   * sys::mirror & get_secondary()

   * const sys::mirror & get_secondary() const

   * double get_secondary_major_axis() const

   * double get_secondary_minor_axis() const

   * double get_secondary_offset() const

   * sys::system * get_system() const

   * const math::Transform<3> & get_transform() const

   * const math::Transform<3> & get_transform_from(const sys::Element
     &e) const

   * const math::Transform<3> & get_transform_from(const sys::Element
     *e) const

   * const math::Transform<3> & get_transform_to(const sys::Element &e)
     const

   * const math::Transform<3> & get_transform_to(const sys::Element *e)
     const

   * virtual double get_unvignetted_image_diameter() const

   * unsigned int get_version() const

   * unsigned int id() const

   * bool is_enabled() const

   * virtual void print(std::ostream &o) const

   * template void process_rays(trace::Result &result,
     trace::rays_queue_t *input) const

   * void remove(sys::Element &e)

   * void rotate(double x, double y, double z)

   * virtual void set_bwd(double bwd)

   * virtual void set_diameter(double diameter)

   * void set_direction(const math::vector3 &v)

   * void set_enable_state(bool enabled)

   * virtual void set_field_angle(double fa)

   * virtual void set_focal(double focal)

   * void set_local_direction(const math::vector3 &v)

   * void set_local_plane(const math::vectorPair3 &p)

   * void set_local_position(const math::vector3 &v)

   * void set_plane(const math::vectorPair3 &p)

   * void set_position(const math::vector3 &v)

   * void set_secondary_minor_axis(double diameter)

   * void set_transform(const math::Transform<3> &t)

   * void update_version()

Design::telescope::telescope class reference
============================================

Declaration
-----------

     #include <goptical/core/Design/telescope/telescope>

     namespace goptical {
       namespace Design {
         namespace telescope {
           class telescope;
         };
       };
     };

   This class is a member of the telescope namespace.

   This abstract class contains pure virtuals.

Inheritance
-----------

Description
-----------

Base class for telescope optical designs

Members
-------

See also the full member list (*note
Design_telescope_telescope_class_full_member_list::) section for this
class.

Inherited members
.................

   * 51 members inherited from sys::Group (*note
     sys_Group_class_reference::)

Functions
.........

   * telescope(const math::vectorPair3 &p)

   * virtual double get_bwd() const = 0;

   * virtual double get_diameter() const = 0;

   * virtual double get_field_angle() const = 0;

   * virtual double get_focal() const = 0;

   * virtual math::vectorPair3 get_focal_plane() const = 0;

   * virtual double get_unvignetted_image_diameter() const = 0;

   * virtual void set_bwd(double bwd) = 0;

   * virtual void set_diameter(double diameter) = 0;

   * virtual void set_field_angle(double bwd) = 0;

   * virtual void set_focal(double focal) = 0;

Members detail
--------------

telescope(const math::vectorPair3 &p)
.....................................

No documentation available

virtual double get_bwd() const = 0;
...................................

Get telescope back working distance

virtual double get_diameter() const = 0;
........................................

Get telescope primary mirror diameter

virtual double get_field_angle() const = 0;
...........................................

Get telescope field angle

virtual double get_focal() const = 0;
.....................................

Get telescope focal length

virtual math::vectorPair3 get_focal_plane() const = 0;
......................................................

Get telescope focal plane in parent coordinate system

virtual double get_unvignetted_image_diameter() const = 0;
..........................................................

Get diameter of unvignetted image on focal plane

virtual void set_bwd(double bwd) = 0;
.....................................

Set telescope back working distance

virtual void set_diameter(double diameter) = 0;
...............................................

Set telescope primary mirror diameter

virtual void set_field_angle(double bwd) = 0;
.............................................

Set telescope field angle

virtual void set_focal(double focal) = 0;
.........................................

Set telescope focal length

Design::telescope::telescope class full member list
===================================================

Types
-----

   * typedef _ [...] _ element_list_t

   * typedef _ [...] _ mod_delegate_t

   * typedef _ [...] _ put_delegate_t

Functions
---------

   * telescope(const math::vectorPair3 &p)

   * void add(const ref<sys::Element> &e)

   * template bool contains(const X *x) const

   * void draw_2d(io::Renderer &r) const

   * void draw_2d_fit(io::renderer_viewport &r, bool keep_aspect =
     _[...]_) const

   * void draw_3d(io::Renderer &r) const

   * void draw_3d_fit(io::renderer_viewport &r, double z_offset =
     _[...]_) const

   * template void enable_single(const X &e)

   * template X * find() const

   * virtual math::vectorPair3 get_bounding_box() const

   * virtual double get_bwd() const = 0;

   * virtual double get_diameter() const = 0;

   * math::vector3 get_direction(const sys::Element &e) const

   * math::vector3 get_direction() const

   * const sys::Container::element_list_t & get_element_list() const

   * template void get_elements(const delegate<void(const X&)> &d) const

   * template void get_elements(const delegate<void(X&)> &d)

   * virtual double get_field_angle() const = 0;

   * virtual double get_focal() const = 0;

   * virtual math::vectorPair3 get_focal_plane() const = 0;

   * const math::Transform<3> & get_global_transform() const

   * math::vector3 get_local_direction() const

   * math::vectorPair3 get_local_plane() const

   * const math::vector3 & get_local_position() const

   * const math::Transform<3> & get_local_transform() const

   * sys::Group * get_parent() const

   * math::vectorPair3 get_plane() const

   * math::vectorPair3 get_plane(const sys::Element &e) const

   * math::vector3 get_position(const sys::Element &e) const

   * math::vector3 get_position() const

   * sys::system * get_system() const

   * const math::Transform<3> & get_transform() const

   * const math::Transform<3> & get_transform_from(const sys::Element
     &e) const

   * const math::Transform<3> & get_transform_from(const sys::Element
     *e) const

   * const math::Transform<3> & get_transform_to(const sys::Element &e)
     const

   * const math::Transform<3> & get_transform_to(const sys::Element *e)
     const

   * virtual double get_unvignetted_image_diameter() const = 0;

   * unsigned int get_version() const

   * unsigned int id() const

   * bool is_enabled() const

   * virtual void print(std::ostream &o) const

   * template void process_rays(trace::Result &result,
     trace::rays_queue_t *input) const

   * void remove(sys::Element &e)

   * void rotate(double x, double y, double z)

   * virtual void set_bwd(double bwd) = 0;

   * virtual void set_diameter(double diameter) = 0;

   * void set_direction(const math::vector3 &v)

   * void set_enable_state(bool enabled)

   * virtual void set_field_angle(double bwd) = 0;

   * virtual void set_focal(double focal) = 0;

   * void set_local_direction(const math::vector3 &v)

   * void set_local_plane(const math::vectorPair3 &p)

   * void set_local_position(const math::vector3 &v)

   * void set_plane(const math::vectorPair3 &p)

   * void set_position(const math::vector3 &v)

   * void set_transform(const math::Transform<3> &t)

   * void update_version()

Error class reference
=====================

Declaration
-----------

     #include <goptical/core/Error>

     namespace goptical {
       class Error;
     };

   This class is a member of the <goptical/core namespace.

Inheritance
-----------

Description
-----------

Base class used for <goptical/core exceptions.

Members
-------

See also the full member list (*note Error_class_full_member_list::)
section for this class.

Function
........

   * Error(const std::string &msg = _[...]_)

Members detail
--------------

Error(const std:: string  &msg = "")
....................................

No documentation available

Error class full member list
============================

Function
--------

   * Error(const std::string &msg = _[...]_)

io namespace reference
======================

Description
-----------

data input/output and graphical rendering

Members
-------

Types
.....

   * class ImportOslo

   * class ImportZemax

   * class Renderer

   * class RendererDxf

   * class RendererGd

   * class RendererOpengl

   * class renderer_pl_plot

   * class renderer_svg

   * class RendererX11

   * class RendererX3d

   * class Export

   * class Import

   * enum IntensityMode

   * enum PointStyle

   * enum RayColorMode

   * class RendererAxes

   * class renderer_viewport

   * struct rgb

   * enum Style

   * enum TextAlignMask

Functions
.........

   * TextAlignMask operator&(TextAlignMask a, TextAlignMask b)

   * TextAlignMask operator|(TextAlignMask a, TextAlignMask b)

   * TextAlignMask operator~(TextAlignMask a)

Constants
.........

   * const rgb rgb_black

   * const rgb rgb_blue

   * const rgb rgb_cyan

   * const rgb rgb_gray

   * const rgb rgb_green

   * const rgb rgb_magenta

   * const rgb rgb_red

   * const rgb rgb_table[]

   * const size_t rgb_table_size

   * const rgb rgb_white

   * const rgb rgb_yellow

Members detail
--------------

enum IntensityMode
..................

Specifies light ray intensity rendering mode

Identifier             Description
-------------------------------------------------------------------------- 
IntensityIgnore         light ray intensity is ignored, no blending is
                       performed while rendering ray
IntensityShade          light ray intensity is used to blend rendered ray
IntensityLogShade       light ray intensity logarithm is used to blend
                       rendered ray. This enable faint rays to remain
                       visible.

enum PointStyle
...............

Identifier             Description
-------------------------------------------------------------------------- 
PointStyleDot          
PointStyleCross        
PointStyleRound        
PointStyleSquare       
PointStyleTriangle     

enum RayColorMode
.................

Specifies light ray color rendering

Identifier             Description
-------------------------------------------------------------------------- 
RayColorWavelen         Compute ray color from its wavelength
RayColorFixed           Use fixed ray color

enum Style
..........

Specifies rendering elements which can have modified colors and style

Identifier             Description
-------------------------------------------------------------------------- 
StyleBackground        
StyleForeground        
StyleRay               
StyleSurface           
StyleGlass             
StyleLast              

enum TextAlignMask
..................

Specifies rendered text alignment

Identifier             Description
-------------------------------------------------------------------------- 
TextAlignCenter         Vertically centered
TextAlignLeft          
TextAlignRight         
TextAlignTop           
TextAlignBottom        
TextAlignMiddle         Horizontally centered

TextAlignMask operator&(TextAlignMask a, TextAlignMask b)
.........................................................

Bitwise and operation for use on TextAlignMask (*note _340::) enum.

TextAlignMask operator|(TextAlignMask a, TextAlignMask b)
.........................................................

Bitwise or operation for use on TextAlignMask (*note _340::) enum.

TextAlignMask operator~(TextAlignMask a)
........................................

Bitwise not operation for use on TextAlignMask (*note _340::) enum.

const rgb rgb_black
...................

No documentation available

const rgb rgb_blue
..................

No documentation available

const rgb rgb_cyan
..................

No documentation available

const rgb rgb_gray
..................

No documentation available

const rgb rgb_green
...................

No documentation available

const rgb rgb_magenta
.....................

No documentation available

const rgb rgb_red
.................

No documentation available

const rgb rgb_table[]
.....................

This table contains some common colors.

   See also rgb_table_size (*note _352::) variable.

const  size_t  rgb_table_size = 9
.................................

This constant specifies the number of entries in rgb_table (*note
_351::).

const rgb rgb_white
...................

No documentation available

const rgb rgb_yellow
....................

No documentation available

io::ImportOslo class reference
==============================

Declaration
-----------

     #include <goptical/core/io/ImportOslo>

     namespace goptical {
       namespace io {
         class ImportOslo;
       };
     };

   This class is a member of the io namespace.

Description
-----------

This class implements an Oslo glass catalog loader.

Members
-------

See also the full member list (*note
io_ImportOslo_class_full_member_list::) section for this class.

Static function
...............

   * static material::Catalog & import_catalog(const std::string
     &filename)

Members detail
--------------

static material::Catalog & import_catalog(const std:: string  &filename)
........................................................................

import Oslo glass catalog file (.glc)

io::ImportOslo class full member list
=====================================

Static function
---------------

   * static material::Catalog & import_catalog(const std::string
     &filename)

io::ImportZemax class reference
===============================

Declaration
-----------

This class is flagged as experimental.

     #include <goptical/core/io/ImportZemax>

     namespace goptical {
       namespace io {
         class ImportZemax;
       };
     };

   This class is a member of the io namespace.

Description
-----------

This class implements a zemax optical design file and glass catalog
loader.

Members
-------

See also the full member list (*note
io_ImportZemax_class_full_member_list::) section for this class.

Functions
.........

   * ref<material::Catalog> get_catalog(const std::string &name)

   * ref<material::Catalog> import_catalog(const std::string &name)

   * ref<material::Catalog> import_catalog(const std::string &path,
     const std::string &name)

   * ref<material::Catalog> import_catalog_file(const std::string &path)

   * ref<sys::system> import_design(const std::string &filename)

   * ref<material::Dielectric> import_table_glass(const std::string
     &filename)

   * void set_catalog_path(const std::string &path)

Members detail
--------------

ref <material::Catalog> get_catalog(const std:: string  &name)
..............................................................

This function is flagged as experimental.

   Get already imported catalog

ref <material::Catalog> import_catalog(const std:: string  &name)
.................................................................

This function is flagged as experimental.

   Import Zemax ascii glass catalog, guess filename from default path
and name

ref <material::Catalog> import_catalog(const std:: string  &path, const std:: string  &name)
............................................................................................

This function is flagged as experimental.

   Import Zemax ascii glass catalog file (`.agf)'

ref <material::Catalog> import_catalog_file(const std:: string  &path)
......................................................................

This function is flagged as experimental.

   Import Zemax ascii glass catalog file (`.agf).' Guess catalog name
from file name

ref <sys::system> import_design(const std:: string  &filename)
..............................................................

This function is flagged as experimental.

ref <material::Dielectric> import_table_glass(const std:: string  &filename)
............................................................................

This function is flagged as experimental.

   Import Zemax table glass material file (`.ztg)'

void set_catalog_path(const std:: string  &path)
................................................

This function is flagged as experimental.

   Set glass catalogs default path

io::ImportZemax class full member list
======================================

Functions
---------

   * ref<material::Catalog> get_catalog(const std::string &name)

   * ref<material::Catalog> import_catalog(const std::string &name)

   * ref<material::Catalog> import_catalog(const std::string &path,
     const std::string &name)

   * ref<material::Catalog> import_catalog_file(const std::string &path)

   * ref<sys::system> import_design(const std::string &filename)

   * ref<material::Dielectric> import_table_glass(const std::string
     &filename)

   * void set_catalog_path(const std::string &path)

io::Renderer class reference
============================

Declaration
-----------

     #include <goptical/core/io/Renderer>

     namespace goptical {
       namespace io {
         class Renderer;
       };
     };

   This class is a member of the io namespace.

   This abstract class contains pure virtuals.

Inheritance
-----------

Description
-----------

This class define the interface for graphical rendering drivers and
provide a default implementation for some functions.

Members
-------

See also the full member list (*note
io_Renderer_class_full_member_list::) section for this class.

Functions
.........

   * Renderer()

   * virtual ~Renderer()

   * double get_feature_size() const

   * const rgb & get_style_color(Style s) const

   * const rgb & rgb_background() const

   * const rgb & rgb_foreground() const

   * void set_feature_size(double feature_size)

   * void set_ray_color_mode(RayColorMode m)

   * void set_ray_intensity_mode(IntensityMode m)

   * void set_style_color(Style s, const rgb &rgb)

Members detail
--------------

Renderer()
..........

No documentation available

virtual ~Renderer()
...................

No documentation available

double get_feature_size() const
...............................

Get size of lines and triangles used to render curved shapes..

   See also set_feature_size (*note _369::) function.

const rgb & get_style_color(Style s) const
..........................................

Get rgb color from style specifier

const rgb & rgb_background() const
..................................

Get foreground rgb color

const rgb & rgb_foreground() const
..................................

Get foreground rgb color

void set_feature_size(double feature_size)
..........................................

Set size of lines and triangles used to render curved shapes..

   See also get_feature_size (*note _365::) function.

void set_ray_color_mode(RayColorMode m)
.......................................

Set color mode for light ray drawing. Default is RayColorWavelen (*note
_338::).

void set_ray_intensity_mode(IntensityMode m)
............................................

Set light ray intensity display mode

void set_style_color(Style s, const rgb &rgb)
.............................................

Set rgb color for given style specifier.

   Some drivers do not support changing background color after
initialization.

io::Renderer class full member list
===================================

Functions
---------

   * Renderer()

   * virtual ~Renderer()

   * double get_feature_size() const

   * const rgb & get_style_color(Style s) const

   * const rgb & rgb_background() const

   * const rgb & rgb_foreground() const

   * void set_feature_size(double feature_size)

   * void set_ray_color_mode(RayColorMode m)

   * void set_ray_intensity_mode(IntensityMode m)

   * void set_style_color(Style s, const rgb &rgb)

io::RendererDxf class reference
===============================

Declaration
-----------

This class is flagged as experimental.

     #include <goptical/core/io/RendererDxf>

     namespace goptical {
       namespace io {
         class RendererDxf;
       };
     };

   This class is a member of the io namespace.

Inheritance
-----------

Description
-----------

This class implements a 2d and 3d Dxf CAD format output driver. It
requires the  Dime  library to compile.

Members
-------

See also the full member list (*note
io_RendererDxf_class_full_member_list::) section for this class.

Inherited members
.................

   * 10 members inherited from Renderer (*note
     io_Renderer_class_reference::)

Functions
.........

   * RendererDxf()

   * RendererDxf(const char *filename)

   * ~RendererDxf()

   * unsigned int add_layer(std::string name)

   * void use_layer(unsigned int id)

   * void write(const std::string &filename)

Members detail
--------------

RendererDxf()
.............

This constructor is flagged as experimental.

   Create a DXF renderer

RendererDxf(const char *filename)
.................................

This constructor is flagged as experimental.

   Create a DXF renderer, output will be written to given filename when
the renderer is destroyed.

~RendererDxf()
..............

This destructor is flagged as experimental.

unsigned int add_layer(std:: string  name)
..........................................

This function is flagged as experimental.

   Add a new layer in dxf file and return its index

void use_layer(unsigned int id)
...............................

This function is flagged as experimental.

   Set current layer

void write(const std:: string  &filename)
.........................................

This function is flagged as experimental.

   Save output to a DXF file

io::RendererDxf class full member list
======================================

Functions
---------

   * RendererDxf()

   * RendererDxf(const char *filename)

   * ~RendererDxf()

   * unsigned int add_layer(std::string name)

   * double get_feature_size() const

   * const rgb & get_style_color(Style s) const

   * const rgb & rgb_background() const

   * const rgb & rgb_foreground() const

   * void set_feature_size(double feature_size)

   * void set_ray_color_mode(RayColorMode m)

   * void set_ray_intensity_mode(IntensityMode m)

   * void set_style_color(Style s, const rgb &rgb)

   * void use_layer(unsigned int id)

   * void write(const std::string &filename)

io::RendererGd class reference
==============================

Declaration
-----------

     #include <goptical/core/io/RendererGd>

     namespace goptical {
       namespace io {
         class RendererGd;
       };
     };

   This class is a member of the io namespace.

Inheritance
-----------

Description
-----------

This class implements a Gd graphic output driver. It needs the gd
library to compile.

Members
-------

See also the full member list (*note
io_RendererGd_class_full_member_list::) section for this class.

Inherited members
.................

   * 31 members inherited from renderer_viewport (*note
     io_renderer_viewport_class_reference::)

Functions
.........

   * RendererGd(gdimagePtr im, const rgb &background = _[...]_,
     gdFontPtr font = _[...]_, const char *TFfontlist = _[...]_)

   * RendererGd(const char *filename, unsigned int width = _[...]_,
     unsigned int height = _[...]_, const rgb &background = _[...]_,
     const char *TFfontlist = _[...]_)

   * RendererGd(unsigned int width = _[...]_, unsigned int height =
     _[...]_, const rgb &background = _[...]_, const char *TFfontlist =
     _[...]_)

   * ~RendererGd()

   * virtual void clear()

   * void set_brush_thickness(unsigned int t)

   * void write(const std::string &filename)

Members detail
--------------

RendererGd(gdimagePtr im, const rgb &background = rgb_white, gdFontPtr font = 0, const char *TFfontlist = 0)
............................................................................................................

Create a new gd renderer using specified gd resources

RendererGd(const char *filename, unsigned int width = 800, unsigned int height = 600, const rgb &background = rgb_white, const char *TFfontlist = 0)
....................................................................................................................................................

Create a new gd renderer with given resolution, png output will be
written to file on renderer destruction.

RendererGd(unsigned int width = 800, unsigned int height = 600, const rgb &background = rgb_white, const char *TFfontlist = 0)
..............................................................................................................................

Create a new gd renderer with given resolution

~RendererGd()
.............

No documentation available

virtual void clear()
....................

This virtual function overrides the `clear' virtual function defined in
the `renderer_viewport (*note io_renderer_viewport_class_reference::)'
base abstract class for internal purposes.

   Clear current image buffer

void set_brush_thickness(unsigned int t)
........................................

No documentation available

void write(const std:: string  &filename)
.........................................

Write image to file in png format

io::RendererGd class full member list
=====================================

Functions
---------

   * RendererGd(gdimagePtr im, const rgb &background = _[...]_,
     gdFontPtr font = _[...]_, const char *TFfontlist = _[...]_)

   * RendererGd(const char *filename, unsigned int width = _[...]_,
     unsigned int height = _[...]_, const rgb &background = _[...]_,
     const char *TFfontlist = _[...]_)

   * RendererGd(unsigned int width = _[...]_, unsigned int height =
     _[...]_, const rgb &background = _[...]_, const char *TFfontlist =
     _[...]_)

   * ~RendererGd()

   * virtual void clear()

   * virtual void draw_pages_grid(const rgb &rgb = _[...]_)

   * double get_feature_size() const

   * double get_fov() const

   * const rgb & get_style_color(Style s) const

   * const math::vectorPair2 & get_window() const

   * const rgb & rgb_background() const

   * const rgb & rgb_foreground() const

   * void set_brush_thickness(unsigned int t)

   * void set_camera_direction(const math::vector3 &dir)

   * void set_camera_position(const math::vector3 &pos)

   * void set_feature_size(double feature_size)

   * void set_fov(double fov)

   * void set_margin(double left, double bottom, double right, double
     top)

   * void set_margin(double width, double height)

   * void set_margin_output(double left, double bottom, double right,
     double top)

   * void set_margin_output(double width, double height)

   * void set_margin_ratio(double left, double bottom, double right,
     double top)

   * void set_margin_ratio(double width, double height)

   * void set_numeric_format(std::ios_base::fmtflags format, unsigned
     int precision)

   * virtual void set_page(unsigned int page)

   * virtual void set_page_layout(unsigned int cols, unsigned int rows)

   * void set_ray_color_mode(RayColorMode m)

   * void set_ray_intensity_mode(IntensityMode m)

   * void set_style_color(Style s, const rgb &rgb)

   * virtual void set_window(const math::vector2 &center, const
     math::vector2 &size, bool keep_aspect = _[...]_)

   * void set_window(const math::vectorPair2 &window, bool keep_aspect
     = _[...]_)

   * void set_window(const math::vector2 &center, double radius, bool
     keep_aspect = _[...]_)

   * void write(const std::string &filename)

io::RendererOpengl class reference
==================================

Declaration
-----------

     #include <goptical/core/io/RendererOpengl>

     namespace goptical {
       namespace io {
         class RendererOpengl;
       };
     };

   This class is a member of the io namespace.

Inheritance
-----------

Description
-----------

This class implements an Opengl graphic output driver. It needs the
opengl library to compile.

Members
-------

See also the full member list (*note
io_RendererOpengl_class_full_member_list::) section for this class.

Inherited members
.................

   * 31 members inherited from renderer_viewport (*note
     io_renderer_viewport_class_reference::)

Functions
.........

   * RendererOpengl(double near, double far, double width = _[...]_,
     double height = _[...]_, const rgb &background = _[...]_)

   * void set_z_range(double near, double far)

Static functions
................

   * static void apply_transform(const math::Transform<3> &t)

   * static void get_transform(GLenum name, math::Transform<3> &t)

   * static void glColor(const rgb &rgb)

   * static void glNormal(const math::vector3 &v)

   * static void glVertex(const math::vector2 &v)

   * static void glVertex(const math::vector3 &v)

Members detail
--------------

RendererOpengl(double near, double far, double width = 800, double height = 600, const rgb &background = rgb_black)
...................................................................................................................

No documentation available

static void apply_transform(const math::Transform<3> &t)
........................................................

No documentation available

static void get_transform(GLenum name, math::Transform<3> &t)
.............................................................

No documentation available

static void glColor(const rgb &rgb)
...................................

No documentation available

static void glNormal(const math::vector3 &v)
............................................

No documentation available

static void glVertex(const math::vector2 &v)
............................................

No documentation available

static void glVertex(const math::vector3 &v)
............................................

No documentation available

void set_z_range(double near, double far)
.........................................

No documentation available

io::RendererOpengl class full member list
=========================================

Functions
---------

   * RendererOpengl(double near, double far, double width = _[...]_,
     double height = _[...]_, const rgb &background = _[...]_)

   * virtual void draw_pages_grid(const rgb &rgb = _[...]_)

   * double get_feature_size() const

   * double get_fov() const

   * const rgb & get_style_color(Style s) const

   * const math::vectorPair2 & get_window() const

   * const rgb & rgb_background() const

   * const rgb & rgb_foreground() const

   * void set_camera_direction(const math::vector3 &dir)

   * void set_camera_position(const math::vector3 &pos)

   * void set_feature_size(double feature_size)

   * void set_fov(double fov)

   * void set_margin(double left, double bottom, double right, double
     top)

   * void set_margin(double width, double height)

   * void set_margin_output(double left, double bottom, double right,
     double top)

   * void set_margin_output(double width, double height)

   * void set_margin_ratio(double left, double bottom, double right,
     double top)

   * void set_margin_ratio(double width, double height)

   * void set_numeric_format(std::ios_base::fmtflags format, unsigned
     int precision)

   * virtual void set_page(unsigned int page)

   * virtual void set_page_layout(unsigned int cols, unsigned int rows)

   * void set_ray_color_mode(RayColorMode m)

   * void set_ray_intensity_mode(IntensityMode m)

   * void set_style_color(Style s, const rgb &rgb)

   * virtual void set_window(const math::vector2 &center, const
     math::vector2 &size, bool keep_aspect = _[...]_)

   * void set_window(const math::vectorPair2 &window, bool keep_aspect
     = _[...]_)

   * void set_window(const math::vector2 &center, double radius, bool
     keep_aspect = _[...]_)

   * void set_z_range(double near, double far)

Static functions
----------------

   * static void apply_transform(const math::Transform<3> &t)

   * static void get_transform(GLenum name, math::Transform<3> &t)

   * static void glColor(const rgb &rgb)

   * static void glNormal(const math::vector3 &v)

   * static void glVertex(const math::vector2 &v)

   * static void glVertex(const math::vector3 &v)

io::renderer_pl_plot class reference
==================================

Declaration
-----------

     #include <goptical/core/io/renderer_pl_plot>

     namespace goptical {
       namespace io {
         class renderer_pl_plot;
       };
     };

   This class is a member of the io namespace.

Inheritance
-----------

Description
-----------

This class implements a Plplot graphic output driver. It needs the
plplot library to compile.

Members
-------

See also the full member list (*note
io_renderer_pl_plot_class_full_member_list::) section for this class.

Inherited members
.................

   * 31 members inherited from renderer_viewport (*note
     io_renderer_viewport_class_reference::)

Functions
.........

   * renderer_pl_plot(plstream *pls)

   * renderer_pl_plot(const char *device, const char *filename, unsigned
     int width = _[...]_, unsigned int height = _[...]_, const rgb
     &background = _[...]_)

   * ~renderer_pl_plot()

   * plstream * get_pls()

   * virtual void set_page(unsigned int page)

   * virtual void set_page_layout(unsigned int cols, unsigned int rows)

Members detail
--------------

renderer_pl_plot(plstream *pls)
.............................

Initialize renderer from existing plplot context

renderer_pl_plot(const char *device, const char *filename, unsigned int width = 800, unsigned int height = 600, const rgb &background = rgb_white)
................................................................................................................................................

Create a plplot renderer with specified output size

~renderer_pl_plot()
.................

No documentation available

plstream * get_pls()
....................

get plplot context object

virtual void set_page(unsigned int page)
........................................

This virtual function overrides the `set_page (*note _475::)' virtual
function defined in the `renderer_viewport (*note
io_renderer_viewport_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Select current page when multiple pages layout is in use.

   See also set_page_layout (*note _476::) function.

virtual void set_page_layout(unsigned int cols, unsigned int rows)
..................................................................

This virtual function overrides the `set_page_layout (*note _476::)'
virtual function defined in the `renderer_viewport (*note
io_renderer_viewport_class_reference::)' base abstract class.

   Documentation inherited from base class:

   This function can be used to setup a pages grid. Current output page
must be selected with set_page (*note _475::).

io::renderer_pl_plot class full member list
=========================================

Functions
---------

   * renderer_pl_plot(plstream *pls)

   * renderer_pl_plot(const char *device, const char *filename, unsigned
     int width = _[...]_, unsigned int height = _[...]_, const rgb
     &background = _[...]_)

   * ~renderer_pl_plot()

   * virtual void draw_pages_grid(const rgb &rgb = _[...]_)

   * double get_feature_size() const

   * double get_fov() const

   * plstream * get_pls()

   * const rgb & get_style_color(Style s) const

   * const math::vectorPair2 & get_window() const

   * const rgb & rgb_background() const

   * const rgb & rgb_foreground() const

   * void set_camera_direction(const math::vector3 &dir)

   * void set_camera_position(const math::vector3 &pos)

   * void set_feature_size(double feature_size)

   * void set_fov(double fov)

   * void set_margin(double left, double bottom, double right, double
     top)

   * void set_margin(double width, double height)

   * void set_margin_output(double left, double bottom, double right,
     double top)

   * void set_margin_output(double width, double height)

   * void set_margin_ratio(double left, double bottom, double right,
     double top)

   * void set_margin_ratio(double width, double height)

   * void set_numeric_format(std::ios_base::fmtflags format, unsigned
     int precision)

   * virtual void set_page(unsigned int page)

   * virtual void set_page_layout(unsigned int cols, unsigned int rows)

   * void set_ray_color_mode(RayColorMode m)

   * void set_ray_intensity_mode(IntensityMode m)

   * void set_style_color(Style s, const rgb &rgb)

   * virtual void set_window(const math::vector2 &center, const
     math::vector2 &size, bool keep_aspect = _[...]_)

   * void set_window(const math::vectorPair2 &window, bool keep_aspect
     = _[...]_)

   * void set_window(const math::vector2 &center, double radius, bool
     keep_aspect = _[...]_)

io::renderer_svg class reference
===============================

Declaration
-----------

     #include <goptical/core/io/renderer_svg>

     namespace goptical {
       namespace io {
         class renderer_svg;
       };
     };

   This class is a member of the io namespace.

Inheritance
-----------

Description
-----------

This class implements a SVG graphic output driver.

Members
-------

See also the full member list (*note
io_renderer_svg_class_full_member_list::) section for this class.

Inherited members
.................

   * 31 members inherited from renderer_viewport (*note
     io_renderer_viewport_class_reference::)

Functions
.........

   * renderer_svg(double width = _[...]_, double height = _[...]_, const
     rgb &background = _[...]_)

   * renderer_svg(const char *filename, double width = _[...]_, double
     height = _[...]_, const rgb &background = _[...]_)

   * ~renderer_svg()

   * void write(std::ostream &s)

Members detail
--------------

renderer_svg(double width = 800, double height = 600, const rgb &background = rgb_white)
.......................................................................................

Create a new svg renderer with given resolution. The write (*note
_403::) function must be used to write svg to output stream.

renderer_svg(const char *filename, double width = 800, double height = 600, const rgb &background = rgb_white)
.............................................................................................................

Create a new svg renderer with given resolution and viewport window.
Svg output will be written to given filename when the renderer object
is destroyed.

~renderer_svg()
..............

No documentation available

void write(std:: ostream  &s)
.............................

Write svg output to given stream.

io::renderer_svg class full member list
======================================

Functions
---------

   * renderer_svg(double width = _[...]_, double height = _[...]_, const
     rgb &background = _[...]_)

   * renderer_svg(const char *filename, double width = _[...]_, double
     height = _[...]_, const rgb &background = _[...]_)

   * ~renderer_svg()

   * virtual void draw_pages_grid(const rgb &rgb = _[...]_)

   * double get_feature_size() const

   * double get_fov() const

   * const rgb & get_style_color(Style s) const

   * const math::vectorPair2 & get_window() const

   * const rgb & rgb_background() const

   * const rgb & rgb_foreground() const

   * virtual void set_2d_size(double width, double height)

   * void set_camera_direction(const math::vector3 &dir)

   * void set_camera_position(const math::vector3 &pos)

   * void set_feature_size(double feature_size)

   * void set_fov(double fov)

   * void set_margin(double left, double bottom, double right, double
     top)

   * void set_margin(double width, double height)

   * void set_margin_output(double left, double bottom, double right,
     double top)

   * void set_margin_output(double width, double height)

   * void set_margin_ratio(double left, double bottom, double right,
     double top)

   * void set_margin_ratio(double width, double height)

   * void set_numeric_format(std::ios_base::fmtflags format, unsigned
     int precision)

   * virtual void set_page(unsigned int page)

   * virtual void set_page_layout(unsigned int cols, unsigned int rows)

   * void set_ray_color_mode(RayColorMode m)

   * void set_ray_intensity_mode(IntensityMode m)

   * void set_style_color(Style s, const rgb &rgb)

   * virtual void set_window(const math::vector2 &center, const
     math::vector2 &size, bool keep_aspect = _[...]_)

   * void set_window(const math::vectorPair2 &window, bool keep_aspect
     = _[...]_)

   * void set_window(const math::vector2 &center, double radius, bool
     keep_aspect = _[...]_)

   * void write(std::ostream &s)

io::RendererX11 class reference
===============================

Declaration
-----------

     #include <goptical/core/io/RendererX11>

     namespace goptical {
       namespace io {
         class RendererX11;
       };
     };

   This class is a member of the io namespace.

Inheritance
-----------

Description
-----------

This class implements a X11 graphic output driver.

Members
-------

See also the full member list (*note
io_RendererX11_class_full_member_list::) section for this class.

Inherited members
.................

   * 31 members inherited from renderer_viewport (*note
     io_renderer_viewport_class_reference::)

Functions
.........

   * RendererX11(unsigned int width = _[...]_, unsigned int height =
     _[...]_, const rgb &background = _[...]_, Display *disp = _[...]_,
     int src = _[...]_, Window win = _[...]_, GC gc = _[...]_)

   * ~RendererX11()

   * Display * get_disp() const

   * GC get_gc() const

   * int get_scr() const

   * Window get_win() const

Members detail
--------------

RendererX11(unsigned int width = 800, unsigned int height = 600, const rgb &background = rgb_white, Display *disp = 0, int src = -1, Window win = -1, GC gc = 0)
................................................................................................................................................................

No documentation available

~RendererX11()
..............

No documentation available

Display * get_disp() const
..........................

Get X11 display.

   See also set_disp.

GC get_gc() const
.................

Get X11 graphics context.

   See also set_gc.

int get_scr() const
...................

Get X11 screen.

   See also set_scr.

Window get_win() const
......................

Get X11 window.

   See also set_win.

io::RendererX11 class full member list
======================================

Functions
---------

   * RendererX11(unsigned int width = _[...]_, unsigned int height =
     _[...]_, const rgb &background = _[...]_, Display *disp = _[...]_,
     int src = _[...]_, Window win = _[...]_, GC gc = _[...]_)

   * ~RendererX11()

   * virtual void draw_pages_grid(const rgb &rgb = _[...]_)

   * Display * get_disp() const

   * double get_feature_size() const

   * double get_fov() const

   * GC get_gc() const

   * int get_scr() const

   * const rgb & get_style_color(Style s) const

   * Window get_win() const

   * const math::vectorPair2 & get_window() const

   * const rgb & rgb_background() const

   * const rgb & rgb_foreground() const

   * virtual void set_2d_size(double width, double height)

   * void set_camera_direction(const math::vector3 &dir)

   * void set_camera_position(const math::vector3 &pos)

   * void set_feature_size(double feature_size)

   * void set_fov(double fov)

   * void set_margin(double left, double bottom, double right, double
     top)

   * void set_margin(double width, double height)

   * void set_margin_output(double left, double bottom, double right,
     double top)

   * void set_margin_output(double width, double height)

   * void set_margin_ratio(double left, double bottom, double right,
     double top)

   * void set_margin_ratio(double width, double height)

   * void set_numeric_format(std::ios_base::fmtflags format, unsigned
     int precision)

   * virtual void set_page(unsigned int page)

   * virtual void set_page_layout(unsigned int cols, unsigned int rows)

   * void set_ray_color_mode(RayColorMode m)

   * void set_ray_intensity_mode(IntensityMode m)

   * void set_style_color(Style s, const rgb &rgb)

   * virtual void set_window(const math::vector2 &center, const
     math::vector2 &size, bool keep_aspect = _[...]_)

   * void set_window(const math::vectorPair2 &window, bool keep_aspect
     = _[...]_)

   * void set_window(const math::vector2 &center, double radius, bool
     keep_aspect = _[...]_)

io::RendererX3d class reference
===============================

Declaration
-----------

This class is flagged as experimental.

     #include <goptical/core/io/RendererX3d>

     namespace goptical {
       namespace io {
         class RendererX3d;
       };
     };

   This class is a member of the io namespace.

Inheritance
-----------

Description
-----------

This class implements an  X3d  graphic output driver.

Members
-------

See also the full member list (*note
io_RendererX3d_class_full_member_list::) section for this class.

Inherited members
.................

   * 10 members inherited from Renderer (*note
     io_Renderer_class_reference::)

Functions
.........

   * RendererX3d(const rgb &background = _[...]_)

   * RendererX3d(const char *filename, const rgb &background = _[...]_)

   * ~RendererX3d()

   * void clear()

   * void flush()

   * void write(std::ostream &s)

Members detail
--------------

RendererX3d(const rgb &background = rgb_white)
..............................................

This constructor is flagged as experimental.

   Create a new X3d renderer. The write (*note _415::) function must be
used to write x3d to output stream.

RendererX3d(const char *filename, const rgb &background = rgb_white)
....................................................................

This constructor is flagged as experimental.

   Create a new X3d renderer. X3d output will be written to given
filename when the renderer object is destroyed.

~RendererX3d()
..............

This destructor is flagged as experimental.

void clear()
............

This function is flagged as experimental.

void flush()
............

This function is flagged as experimental.

void write(std:: ostream  &s)
.............................

This function is flagged as experimental.

   Write svg output to given stream.

io::RendererX3d class full member list
======================================

Functions
---------

   * RendererX3d(const rgb &background = _[...]_)

   * RendererX3d(const char *filename, const rgb &background = _[...]_)

   * ~RendererX3d()

   * void clear()

   * void flush()

   * double get_feature_size() const

   * const rgb & get_style_color(Style s) const

   * const rgb & rgb_background() const

   * const rgb & rgb_foreground() const

   * void set_feature_size(double feature_size)

   * void set_ray_color_mode(RayColorMode m)

   * void set_ray_intensity_mode(IntensityMode m)

   * void set_style_color(Style s, const rgb &rgb)

   * void write(std::ostream &s)

io::Export class reference
==========================

Declaration
-----------

     #include <goptical/core/io/Export>

     namespace goptical {
       namespace io {
         class Export;
       };
     };

   This class is a member of the io namespace.

   This abstract class contains pure virtuals.

Description
-----------

File export class interface

Members
-------

See also the full member list (*note
io_Export_class_full_member_list::) section for this class.

Functions
.........

   * virtual void export_catalog(const material::Catalog &catalog,
     const std::string &filename) = 0;

   * virtual void export_design(const sys::system &sys, const
     std::string &filename) = 0;

Members detail
--------------

virtual void export_catalog(const material::Catalog &catalog, const std:: string  &filename) = 0;
.................................................................................................

Export material catalog to file

virtual void export_design(const sys::system &sys, const std:: string  &filename) = 0;
......................................................................................

Export optical design to file

io::Export class full member list
=================================

Functions
---------

   * virtual void export_catalog(const material::Catalog &catalog,
     const std::string &filename) = 0;

   * virtual void export_design(const sys::system &sys, const
     std::string &filename) = 0;

io::Import class reference
==========================

Declaration
-----------

     #include <goptical/core/io/Import>

     namespace goptical {
       namespace io {
         class Import;
       };
     };

   This class is a member of the io namespace.

   This abstract class contains pure virtuals.

Description
-----------

File import class interface

Members
-------

See also the full member list (*note
io_Import_class_full_member_list::) section for this class.

Functions
.........

   * virtual material::Catalog & import_catalog(const std::string
     &filename) = 0;

   * virtual Set & import_dataset(const std::string &filename) = 0;

   * virtual sys::system & import_design(const std::string &filename) =
     0;

Members detail
--------------

virtual material::Catalog & import_catalog(const std:: string  &filename) = 0;
..............................................................................

Import material catalog from file

virtual Set & import_dataset(const std:: string  &filename) = 0;
................................................................

Import dataset from file

virtual sys::system & import_design(const std:: string  &filename) = 0;
.......................................................................

Import optical design from file

io::Import class full member list
=================================

Functions
---------

   * virtual material::Catalog & import_catalog(const std::string
     &filename) = 0;

   * virtual Set & import_dataset(const std::string &filename) = 0;

   * virtual sys::system & import_design(const std::string &filename) =
     0;

io::RendererAxes class reference
================================

Declaration
-----------

     #include <goptical/core/io/RendererAxes>

     namespace goptical {
       namespace io {
         class RendererAxes;
       };
     };

   This class is a member of the io namespace.

Description
-----------

This class describe how axes must be rendered on graphical output.

Members
-------

See also the full member list (*note
io_RendererAxes_class_full_member_list::) section for this class.

Type
....

   * enum AxisMask

Functions
.........

   * RendererAxes()

   * const std::string & get_label(unsigned int axis) const

   * const math::vector3 & get_origin() const

   * const math::vector3 & get_position() const

   * bool get_show_axes(unsigned int axis) const

   * bool get_show_frame() const

   * bool get_show_grid() const

   * bool get_show_tics(unsigned int axis) const

   * bool get_show_values(unsigned int axis) const

   * double get_tics_step(int index, const math::range_t &r) const

   * void set_label(const std::string &label, AxisMask a = _[...]_)

   * void set_origin(const math::vector3 &origin)

   * void set_position(const math::vector3 &position)

   * void set_range(const math::range_t &r, AxisMask a = _[...]_)

   * void set_show_axes(bool show = _[...]_, AxisMask a = _[...]_)

   * void set_show_frame(bool show = _[...]_)

   * void set_show_grid(bool show = _[...]_)

   * void set_show_tics(bool show = _[...]_, AxisMask a = _[...]_)

   * void set_show_values(bool show = _[...]_, AxisMask a = _[...]_)

   * void set_tics_base(unsigned int min_count = _[...]_, double base =
     _[...]_, AxisMask a = _[...]_)

   * void set_tics_count(unsigned int count, AxisMask a = _[...]_)

   * void set_tics_step(double step, AxisMask a = _[...]_)

   * void set_unit(const std::string &unit, bool pow10_scale = _[...]_,
     bool si_prefix = _[...]_, int si_pow10 = _[...]_, AxisMask a =
     _[...]_)

Members detail
--------------

RendererAxes()
..............

No documentation available

enum AxisMask
.............

Specify axes

Identifier             Description
-------------------------------------------------------------------------- 
X                      
Y                      
Z                      
XY                     
YZ                     
XZ                     
XYZ                    

const std:: string  & get_label(unsigned int axis) const
........................................................

Get axis label

const math::vector3 & get_origin() const
........................................

This function returns axes tics values origin.

const math::vector3 & get_position() const
..........................................

This function returns axis position

bool get_show_axes(unsigned int axis) const
...........................................

See set_show_axes (*note _436::) function.

bool get_show_frame() const
...........................

See set_show_frame (*note _437::) function.

bool get_show_grid() const
..........................

See set_show_grid (*note _438::) function.

bool get_show_tics(unsigned int axis) const
...........................................

See set_show_tics (*note _439::) function.

bool get_show_values(unsigned int axis) const
.............................................

See set_show_values (*note _440::) function.

double get_tics_step(int index, const math::range_t &r) const
.............................................................

get distance between axis tics

void set_label(const std:: string  &label, AxisMask a = XYZ)
............................................................

This function set axis label

void set_origin(const math::vector3 &origin)
............................................

This function sets axis tics values origin.

void set_position(const math::vector3 &position)
................................................

This function returns axis position

void set_range(const math::range_t &r, AxisMask a = XYZ)
........................................................

Set value range for given axis. Default range is [0,0] which means
automatic range.

void set_show_axes(bool show = true, AxisMask a = XYZ)
......................................................

This function sets axes visibility.

void set_show_frame(bool show = true)
.....................................

This function sets frame visibility.

void set_show_grid(bool show = true)
....................................

This function sets grid visibility. Grid points use tic step.

void set_show_tics(bool show = true, AxisMask a = XYZ)
......................................................

This function sets tics visibility. Tics are located on axes and frame.

   See also set_show_axes (*note _436::) function and set_show_frame
(*note _437::) function.

void set_show_values(bool show = true, AxisMask a = XYZ)
........................................................

This function sets tics value visibility. When frame is visible, tics
value is located on frame tics instead of axes tics.

   See also set_show_axes (*note _436::) function and set_show_frame
(*note _437::) function.

void set_tics_base(unsigned int min_count = 5, double base = 10.0, AxisMask a = XYZ)
....................................................................................

This function sets distance between axis tics to best fit power of
specified base divided by sufficient factor of 2 and 5 to have at least
`min_count' tics.

   See also set_tics_step (*note _443::) function and set_tics_count
(*note _442::) function.

void set_tics_count(unsigned int count, AxisMask a = XYZ)
.........................................................

This function sets tics count.

   See also set_tics_step (*note _443::) function and set_tics_base
(*note _441::) function.

void set_tics_step(double step, AxisMask a = XYZ)
.................................................

This function sets distance between axis tics to specified value.

   See also set_tics_count (*note _442::) function and set_tics_base
(*note _441::) function.

void set_unit(const std:: string  &unit, bool pow10_scale = true, bool si_prefix = true, int si_pow10 = 0, AxisMask a = XYZ)
............................................................................................................................

This function sets axis unit.

   When `pow10_scale' is set, value will be scaled to shorten their
length and appropriate power of 10 factor will be displayed in axis
label.

   If `si_prefix' is set, SI letter decimal prefix is used and the
`pow10' parameter can be used to scale base unit by power of ten
(useful when input data use scaled SI base unit).

io::RendererAxes class full member list
=======================================

Type
----

   * enum AxisMask

Functions
---------

   * RendererAxes()

   * const std::string & get_label(unsigned int axis) const

   * const math::vector3 & get_origin() const

   * const math::vector3 & get_position() const

   * bool get_show_axes(unsigned int axis) const

   * bool get_show_frame() const

   * bool get_show_grid() const

   * bool get_show_tics(unsigned int axis) const

   * bool get_show_values(unsigned int axis) const

   * double get_tics_step(int index, const math::range_t &r) const

   * void set_label(const std::string &label, AxisMask a = _[...]_)

   * void set_origin(const math::vector3 &origin)

   * void set_position(const math::vector3 &position)

   * void set_range(const math::range_t &r, AxisMask a = _[...]_)

   * void set_show_axes(bool show = _[...]_, AxisMask a = _[...]_)

   * void set_show_frame(bool show = _[...]_)

   * void set_show_grid(bool show = _[...]_)

   * void set_show_tics(bool show = _[...]_, AxisMask a = _[...]_)

   * void set_show_values(bool show = _[...]_, AxisMask a = _[...]_)

   * void set_tics_base(unsigned int min_count = _[...]_, double base =
     _[...]_, AxisMask a = _[...]_)

   * void set_tics_count(unsigned int count, AxisMask a = _[...]_)

   * void set_tics_step(double step, AxisMask a = _[...]_)

   * void set_unit(const std::string &unit, bool pow10_scale = _[...]_,
     bool si_prefix = _[...]_, int si_pow10 = _[...]_, AxisMask a =
     _[...]_)

io::RendererAxes::Axis internal struct members
==============================================

Axis()
------

No documentation available

bool _axis
----------

No documentation available

unsigned int _count
-------------------

No documentation available

std:: string  _label
--------------------

No documentation available

int _pow10
----------

No documentation available

bool _pow10_scale
-----------------

No documentation available

math::range_t _range
--------------------

No documentation available

bool _si_prefix
---------------

No documentation available

double _step_base
-----------------

No documentation available

step_mode_e _step_mode
----------------------

No documentation available

bool _tics
----------

No documentation available

std:: string  _unit
-------------------

No documentation available

bool _values
------------

No documentation available

io::renderer_viewport class reference
====================================

Declaration
-----------

     #include <goptical/core/io/renderer_viewport>

     namespace goptical {
       namespace io {
         class renderer_viewport;
       };
     };

   This class is a member of the io namespace.

   This abstract class contains pure virtuals.

Inheritance
-----------

Description
-----------

This class defines an interface for rendering drivers which rely on
viewport windows, scaling and 2d projection operations. It's designed
to be used as a base class for such renderers; this mainly includes
pixel based output renderers.

   Renderers which write output in vector format in world coordinates
directly do not need this class as base.

Members
-------

See also the full member list (*note
io_renderer_viewport_class_full_member_list::) section for this class.

Inherited members
.................

   * 10 members inherited from Renderer (*note
     io_Renderer_class_reference::)

Functions
.........

   * renderer_viewport()

   * virtual void draw_pages_grid(const rgb &rgb = _[...]_)

   * virtual math::Transform<3> get_camera_transform() const = 0;

   * double get_fov() const

   * const math::vectorPair2 & get_window() const

   * virtual void set_2d_size(double width, double height)

   * void set_camera_direction(const math::vector3 &dir)

   * void set_camera_position(const math::vector3 &pos)

   * virtual void set_camera_transform(const math::Transform<3> &t) = 0;

   * void set_fov(double fov)

   * void set_margin(double left, double bottom, double right, double
     top)

   * void set_margin(double width, double height)

   * void set_margin_output(double left, double bottom, double right,
     double top)

   * void set_margin_output(double width, double height)

   * void set_margin_ratio(double left, double bottom, double right,
     double top)

   * void set_margin_ratio(double width, double height)

   * void set_numeric_format(std::ios_base::fmtflags format, unsigned
     int precision)

   * virtual void set_page(unsigned int page)

   * virtual void set_page_layout(unsigned int cols, unsigned int rows)

   * virtual void set_perspective() = 0;

   * virtual void set_window(const math::vector2 &center, const
     math::vector2 &size, bool keep_aspect = _[...]_)

   * void set_window(const math::vectorPair2 &window, bool keep_aspect
     = _[...]_)

   * void set_window(const math::vector2 &center, double radius, bool
     keep_aspect = _[...]_)

Members detail
--------------

renderer_viewport()
..................

No documentation available

virtual void draw_pages_grid(const rgb &rgb = rgb_gray)
.......................................................

Draw separations between pages, output window must have been setup
before.

virtual math::Transform<3> get_camera_transform() const = 0;
............................................................

Get reference to 3d camera transform

double get_fov() const
......................

Get field of view in degrees.

   See also set_fov (*note _467::) function.

const math::vectorPair2 & get_window() const
............................................

Get current viewport window

virtual void set_2d_size(double width, double height)
.....................................................

Update 2d output size, not all drivers support this

void set_camera_direction(const math::vector3 &dir)
...................................................

Set 3d camera rotation from direction vector

void set_camera_position(const math::vector3 &pos)
..................................................

Set 3d camera rotation from direction vector

virtual void set_camera_transform(const math::Transform<3> &t) = 0;
...................................................................

Get modifiable reference to 3d camera transform

void set_fov(double fov)
........................

Set field of view in degrees.

   See also get_fov (*note _461::) function.

void set_margin(double left, double bottom, double right, double top)
.....................................................................

Set amount of 2d margin space for set_window (*note _478::) operation
in world coordinates units.

void set_margin(double width, double height)
............................................

See set_margin (*note _468::) function.

void set_margin_output(double left, double bottom, double right, double top)
............................................................................

Set amount of 2d margin space for set_window (*note _478::) operation
in output size units (usually pixels).

void set_margin_output(double width, double height)
...................................................

See set_margin_output (*note _470::) function.

void set_margin_ratio(double left, double bottom, double right, double top)
...........................................................................

Set amount of 2d margin space for set_window (*note _478::) operation
as ratio of window.

void set_margin_ratio(double width, double height)
..................................................

See set_margin_ratio (*note _472::) function.

void set_numeric_format(std::ios_base:: fmtflags  format, unsigned int precision)
.................................................................................

Set format used to print numeric values

virtual void set_page(unsigned int page)
........................................

Select current page when multiple pages layout is in use.

   See also set_page_layout (*note _476::) function.

virtual void set_page_layout(unsigned int cols, unsigned int rows)
..................................................................

This function can be used to setup a pages grid. Current output page
must be selected with set_page (*note _475::).

virtual void set_perspective() = 0;
...................................

Set 3d perspective projection mode. This function reset the viewport
window to (-1,1).

   See also set_window (*note _478::) function and set_fov (*note
_467::) function.

virtual void set_window(const math::vector2 &center, const math::vector2 &size, bool keep_aspect = true)
........................................................................................................

Set 2d viewport window. This function set 3d projection to orthographic.

void set_window(const math::vectorPair2 &window, bool keep_aspect = true)
.........................................................................

Set 2d viewport window. This function set 3d projection to orthographic.

void set_window(const math::vector2 &center, double radius, bool keep_aspect = true)
....................................................................................

Set 2d viewport window. This function set 3d projection to orthographic.

io::renderer_viewport class full member list
===========================================

Functions
---------

   * renderer_viewport()

   * virtual void draw_pages_grid(const rgb &rgb = _[...]_)

   * virtual math::Transform<3> get_camera_transform() const = 0;

   * double get_feature_size() const

   * double get_fov() const

   * const rgb & get_style_color(Style s) const

   * const math::vectorPair2 & get_window() const

   * const rgb & rgb_background() const

   * const rgb & rgb_foreground() const

   * virtual void set_2d_size(double width, double height)

   * void set_camera_direction(const math::vector3 &dir)

   * void set_camera_position(const math::vector3 &pos)

   * virtual void set_camera_transform(const math::Transform<3> &t) = 0;

   * void set_feature_size(double feature_size)

   * void set_fov(double fov)

   * void set_margin(double left, double bottom, double right, double
     top)

   * void set_margin(double width, double height)

   * void set_margin_output(double left, double bottom, double right,
     double top)

   * void set_margin_output(double width, double height)

   * void set_margin_ratio(double left, double bottom, double right,
     double top)

   * void set_margin_ratio(double width, double height)

   * void set_numeric_format(std::ios_base::fmtflags format, unsigned
     int precision)

   * virtual void set_page(unsigned int page)

   * virtual void set_page_layout(unsigned int cols, unsigned int rows)

   * virtual void set_perspective() = 0;

   * void set_ray_color_mode(RayColorMode m)

   * void set_ray_intensity_mode(IntensityMode m)

   * void set_style_color(Style s, const rgb &rgb)

   * virtual void set_window(const math::vector2 &center, const
     math::vector2 &size, bool keep_aspect = _[...]_)

   * void set_window(const math::vectorPair2 &window, bool keep_aspect
     = _[...]_)

   * void set_window(const math::vector2 &center, double radius, bool
     keep_aspect = _[...]_)

io::rgb struct reference
========================

Declaration
-----------

     #include <goptical/core/io/rgb>

     namespace goptical {
       namespace io {
         struct rgb;
       };
     };

   This struct is a member of the io namespace.

Description
-----------

RGB color descriptor

Members
-------

See also the full member list (*note io_rgb_struct_full_member_list::)
section for this struct.

Functions
.........

   * rgb()

   * rgb(float red, float green, float blue, float alpha = _[...]_)

   * bool operator<(const rgb &rgb) const

   * rgb operator~() const

Fields
......

   * float a

   * float b

   * float g

   * float r

Members detail
--------------

rgb()
.....

No documentation available

rgb(float red, float green, float blue, float alpha = 1.0)
..........................................................

No documentation available

float a
.......

No documentation available

float b
.......

No documentation available

float g
.......

No documentation available

bool operator<(const rgb &rgb) const
....................................

No documentation available

rgb operator~() const
.....................

No documentation available

float r
.......

No documentation available

io::rgb struct full member list
===============================

Functions
---------

   * rgb()

   * rgb(float red, float green, float blue, float alpha = _[...]_)

   * bool operator<(const rgb &rgb) const

   * rgb operator~() const

Fields
------

   * float a

   * float b

   * float g

   * float r

light namespace reference
=========================

Description
-----------

Physical properties of light

Members
-------

Types
.....

   * class Ray

   * class SpectralLine

light::Ray class reference
==========================

Declaration
-----------

     #include <goptical/core/light/Ray>

     namespace goptical {
       namespace light {
         class Ray;
       };
     };

   This class is a member of the light namespace.

Inheritance
-----------

Description
-----------

This class is used to describe a ray of light. It contains geometrical
and physical informations about a light ray.

Members
-------

See also the full member list (*note
light_Ray_class_full_member_list::) section for this class.

Inherited members
.................

   * 34 members inherited from math::vectorPair (*note
     math_vectorPair_3_struct_reference::)<3>

Functions
.........

   * Ray()

   * Ray(const math::vectorPair3 &ray, double intensity = _[...]_,
     double wavelen = _[...]_)

   * double get_intensity() const

   * double get_wavelen() const

   * void set_intensity(double intensity)

   * void set_wavelen(double wavelen)

Members detail
--------------

Ray()
.....

No documentation available

Ray(const math::vectorPair3 &ray, double intensity = 1, double wavelen = 550)
.............................................................................

Create a ray of light with specified properties

double get_intensity() const
............................

Get light ray intensity

double get_wavelen() const
..........................

Set light ray wavelen

void set_intensity(double intensity)
....................................

Set light ray intensity

void set_wavelen(double wavelen)
................................

Get light ray wavelen

light::Ray class full member list
=================================

Functions
---------

   * Ray()

   * Ray(const math::vectorPair3 &ray, double intensity = _[...]_,
     double wavelen = _[...]_)

   * math::vector<N> & direction()

   * const math::vector<N> & direction() const

   * double get_intensity() const

   * double get_wavelen() const

   * math::vector<3> ln_ln_clst_pt(const math::vectorPair<3> &line)
     const

   * double ln_ln_clst_pt_scale(const math::vectorPair<3> &line) const

   * math::vector<N> ln_pt_clst_pt(const math::vector<N> &point) const

   * double ln_pt_clst_pt_scale(const math::vector<N> &point) const

   * math::vector<N> & normal()

   * const math::vector<N> & normal() const

   * math::vectorPairBase<3> operator*(double factor)

   * const math::vectorPairBase<3> & operator+=(const
     math::vectorPairBase<3> &p)

   * const math::vector<N> & operator[](int n) const

   * math::vector<N> & operator[](int n)

   * math::vector<N> & origin()

   * const math::vector<N> & origin() const

   * math::vector<3> pl_ln_intersect(const math::vectorPair<3> &line)
     const

   * double pl_ln_intersect_scale(const math::vectorPair<3> &line) const

   * math::vector<N> seg_pt_clst_pt(const math::vector<N> &point) const

   * double seg_pt_clst_pt_scale(const math::vector<N> &point) const

   * void set_intensity(double intensity)

   * void set_wavelen(double wavelen)

   * double x0() const

   * double & x0()

   * double x1() const

   * double & x1()

   * double y0() const

   * double & y0()

   * double y1() const

   * double & y1()

   * double z0() const

   * double & z0()

   * double z1() const

   * double & z1()

light::SpectralLine class reference
===================================

Declaration
-----------

     #include <goptical/core/light/SpectralLine>

     namespace goptical {
       namespace light {
         class SpectralLine;
       };
     };

   This class is a member of the light namespace.

Description
-----------

This class can be used to describe a spectral line. It contains
constants for wave length of standard rays

Members
-------

See also the full member list (*note
light_SpectralLine_class_full_member_list::) section for this class.

Functions
.........

   * SpectralLine(double wavelen, double intensity = _[...]_)

   * io::rgb get_color() const

   * double get_intensity() const

   * double get_wavelen() const

Static function
...............

   * static io::rgb get_wavelen_color(double wl)

Constants
.........

   * static const double C

   * static const double C_

   * static const double D

   * static const double F

   * static const double F_

   * static const double blue

   * static const double d

   * static const double e

   * static const double g

   * static const double green

   * static const double h

   * static const double i

   * static const double r

   * static const double red

   * static const double s

   * static const double t

Members detail
--------------

SpectralLine(double wavelen, double intensity = 1.0)
....................................................

Create a spectral line with specified wavelen and intensity.

static const double C
.....................

red hydrogen line at 656.2725nm

static const double C_
......................

red cadmium line at 643.8469nm

static const double D
.....................

yellow sodium line at 589.2938nm

static const double F
.....................

blue hydrogen line at 486.1327nm

static const double F_
......................

blue cadmium line at 479.9914nm

static const double blue
........................

blue colored line at 440nm

static const double d
.....................

yellow helium line at 587.5618nm

static const double e
.....................

green mercury line at 546.074nm

static const double g
.....................

blue mercury line at 435.8343nm

io::rgb get_color() const
.........................

get rgb color associated spectral line, ignore intensity

double get_intensity() const
............................

get spectral line intensity

double get_wavelen() const
..........................

get spectral line wavelen

static io::rgb get_wavelen_color(double wl)
...........................................

get rgb color associated with wavelen

static const double green
.........................

green colored line at 510nm

static const double h
.....................

violet mercury line at 404.6561nm

static const double i
.....................

ultraviolet mercury line at 365.0146nm

static const double r
.....................

red helium line at 706.5188nm

static const double red
.......................

red colored line at 645nm

static const double s
.....................

infrared cesium line at 852.11nm

static const double t
.....................

infrared mercury line at 1013.98nm

light::SpectralLine class full member list
==========================================

Functions
---------

   * SpectralLine(double wavelen, double intensity = _[...]_)

   * io::rgb get_color() const

   * double get_intensity() const

   * double get_wavelen() const

Static function
---------------

   * static io::rgb get_wavelen_color(double wl)

Constants
---------

   * static const double C

   * static const double C_

   * static const double D

   * static const double F

   * static const double F_

   * static const double blue

   * static const double d

   * static const double e

   * static const double g

   * static const double green

   * static const double h

   * static const double i

   * static const double r

   * static const double red

   * static const double s

   * static const double t

material namespace reference
============================

Description
-----------

material models for optical components

Members
-------

Types
.....

   * template class Abbe

   * template class Air

   * class Base

   * class Catalog

   * class Conrady

   * class DispersionTable

   * class Herzberger

   * class Metal

   * class Mil

   * class mirror

   * class Schott

   * class Sellmeier

   * template class SellmeierMod

   * class Vacuum

   * enum AbbeFormula

   * typedef _ [...] _ AbbeVd

   * typedef _ [...] _ AbbeVe

   * typedef _ [...] _ AirBirch94

   * enum AirFormula

   * typedef _ [...] _ AirKohlrausch68

   * class Dielectric

   * typedef _ [...] _ Handbook1

   * typedef _ [...] _ Handbook2

   * class Proxy

   * typedef _ [...] _ SellmeierMod2

   * enum SellmeierModFormula

   * class Solid

Constants
.........

   * const const_ref<Base> none

   * const AirBirch94 std_air

Variables
.........

   * AirBirch94 air

   * mirror mirror

   * Vacuum vacuum

Members detail
--------------

enum AbbeFormula
................

Specify Abbe number type used by the Abbe (*note
material_Abbe_class_reference::) class

Identifier             Description
-------------------------------------------------------------------------- 
AbbeVdFormula           Abbe number of Fraunhofer _d_ line
AbbeVeFormula           Abbe number of Fraunhofer _e_ line

typedef Abbe<AbbeVdFormula> AbbeVd
..................................

See Abbe (*note material_Abbe_class_reference::) class.

typedef Abbe<AbbeVeFormula> AbbeVe
..................................

See Abbe (*note material_Abbe_class_reference::) class.

typedef Air<AirBirch94Formula> AirBirch94
.........................................

See Air (*note material_Air_class_reference::) class.

enum AirFormula
...............

Specify air refractive index model used by Air (*note
material_Air_class_reference::) class.

Identifier             Description
-------------------------------------------------------------------------- 
AirBirch94Formula       Birch, Metrologia, 1994, 31, 315
AirKohlrausch68Formula  F. Kohlrausch, Praktische Physik, 1968, 1, 408

typedef Air<AirKohlrausch68Formula> AirKohlrausch68
...................................................

See Air (*note material_Air_class_reference::) class.

typedef SellmeierMod<Handbook1Formula> Handbook1
................................................

See SellmeierMod (*note material_SellmeierMod_class_reference::) class.

typedef SellmeierMod<Handbook2Formula> Handbook2
................................................

See SellmeierMod (*note material_SellmeierMod_class_reference::) class.

typedef SellmeierMod<SellmeierMod2Formula> SellmeierMod2
........................................................

See SellmeierMod (*note material_SellmeierMod_class_reference::) class.

enum SellmeierModFormula
........................

Specify Sellmeier variation used by the SellmeierMod (*note
material_SellmeierMod_class_reference::) class

Identifier             Description
-------------------------------------------------------------------------- 
SellmeierMod2Formula   
Handbook1Formula       
Handbook2Formula       

AirBirch94 air
..............

A global instance of AirBirch94 (*note _519::) material.

mirror mirror
.............

A global instance of material::mirror material.

const  const_ref <Base> none
............................

material null pointer

const AirBirch94 std_air
........................

A global read only instance of AirBirch94 (*note _519::) material with
standard parameters.

Vacuum vacuum
.............

A global instance of material::Vacuum material.

material::Abbe class reference
==============================

Declaration
-----------

     #include <goptical/core/material/Abbe>

     namespace goptical {
       namespace material {
         template <enum AbbeFormula m> class Abbe;
       };
     };

   This class is a member of the material namespace.

Inheritance
-----------

Description
-----------

This class models optical properties of glass materials using known
refractive index value,  Abbe number  and partial dispersion deviation
(dpgF).

   AbbeVd (*note _517::) and AbbeVe (*note _518::) template instances
are available for _d_ and _e_ line definitions of Abbe number.

   The following formula is used to determine refractive index at any
wavelen in visible spectrum:

   n_\lambda = n_d + \frac\left( n_d-1\right)v_d\times\left(
c_1+a\times c_0 +                \fracc_3+a\times c_2\lambda +
\fracc_5+a\times c_4\lambda^2 +                \fracc_7+a\times
c_6\lambda^3 \right)

   with  a = a_1\times v_d+a_0+\Delta P_g,F  and  \lambda  the
micrometer wavelength.

   _a0_ and _a1_ values are given in Schott "_TIE-29: Refractive Index
and Dispersion_" technical information document.

   _c0_ to _c7_ values were determined using least square fitting on
indexes obtained using Sellmeier data from 118 glass materials from the
Schott catalog for 360 wavelengths between 390nm and 750nm. Two
different coefficients sets are used for _nd/vd_ and _ne/ve_ pairs.

   Mean error is less than 0.00002 from Sellmeier indexes and largest
error found across fitted glasses and wavelengths is 0.0008. When dpgF
is set to 0, mean error becomes 0.0001 and largest error is close to
0.006.

Members
-------

See also the full member list (*note
material_Abbe_class_full_member_list::) section for this class.

Inherited members
.................

   * 36 members inherited from Dielectric (*note
     material_Dielectric_class_reference::)

Functions
.........

   * Abbe(double n, double v, double dpgF = _[...]_)

   * virtual double get_measurement_index(double wavelen) const

Members detail
--------------

Abbe(double n, double v, double dpgF = 0.)
..........................................

Create an abbe glass model

virtual double get_measurement_index(double wavelen) const
..........................................................

This virtual function implements the `get_measurement_index (*note
_617::)' pure function declared in the `Dielectric (*note
material_Dielectric_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get material relative refractive index in measurment medium at
specified wavelen in _nm._

material::Abbe class full member list
=====================================

Functions
---------

   * Abbe(double n, double v, double dpgF = _[...]_)

   * void clear_internal_transmittance()

   * void disable_temperature_coeff()

   * double get_abbe_vd() const

   * double get_abbe_ve() const

   * virtual io::rgb get_color() const

   * double get_density() const

   * virtual double get_extinction_coef(double wavelen) const

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * double get_internal_transmittance(double wavelen) const

   * virtual double get_measurement_index(double wavelen) const

   * virtual double get_normal_reflectance(const Base *from, double
     wavelen) const

   * virtual double get_normal_transmittance(const Base *from, double
     wavelen) const

   * double get_partial_dispersion(double wavelen1, double wavelen2)
     const

   * double get_poisson_ratio() const

   * double get_principal_dispersion() const

   * double get_refractive_index(double wavelen, const Base &env) const

   * virtual double get_refractive_index(double wavelen) const

   * virtual double get_temperature() const

   * double get_thermal_conductivity() const

   * double get_thermal_expansion() const

   * data::DiscreteSet & get_transmittance_dataset()

   * double get_young_modulus() const

   * virtual bool is_opaque() const

   * virtual bool is_reflecting() const

   * void set_density(double density)

   * void set_internal_transmittance(double wavelen, double thickness,
     double transmittance)

   * void set_measurement_medium(const const_ref<Base> &medium)

   * void set_poisson_ratio(double poisson_ratio)

   * void set_temperature(double temp)

   * void set_temperature_dndt(double dndt)

   * void set_temperature_schott(double d0, double d1, double d2,
     double e0, double e1, double wl_tk)

   * void set_thermal_conductivity(double thermal_conductivity)

   * void set_thermal_expansion(double thermal_expansion)

   * void set_wavelen_range(double low, double high)

   * void set_young_modulus(double young_modulus)

material::Air class reference
=============================

Declaration
-----------

     #include <goptical/core/material/Air>

     namespace goptical {
       namespace material {
         template <enum AirFormula M> class Air;
       };
     };

   This class is a member of the material namespace.

Inheritance
-----------

Description
-----------

This class models optical properties of air. Refractive index of air
depends on temperature and pressure.

   This class provides different formulas:

   * AirBirch94 (*note _519::) : described in "_Birch, Metrologia,
     1994, 31, 315_".

   * AirKohlrausch68 (*note _521::) : described in "_F. Kohlrausch,
     Praktische Physik, 1968, 1, 408_".


   Global variables air (*note _526::) and std_air (*note _529::) are
available with default parameters and Birch model.

Members
-------

See also the full member list (*note
material_Air_class_full_member_list::) section for this class.

Inherited members
.................

   * 14 members inherited from Base (*note
     material_Base_class_reference::)

Functions
.........

   * Air(double pressure = _[...]_)

   * virtual double get_extinction_coef(double wavelen) const

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * double get_pressure() const

   * virtual double get_refractive_index(double wavelen) const

   * virtual bool is_opaque() const

   * virtual bool is_reflecting() const

   * void set_pressure(double pressure)

Constant
........

   * static const double std_pressure

Members detail
--------------

Air(double pressure = std_pressure)
...................................

Create a new air material model with 101325 Pa pressure.

virtual double get_extinction_coef(double wavelen) const
........................................................

This virtual function overrides the `get_extinction_coef (*note
_545::)' virtual function defined in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get extinction coefficient. Subclasses _must_ provide this function
or the get_internal_transmittance() function.

virtual double get_internal_transmittance(double wavelen, double thickness) const
.................................................................................

This virtual function overrides the `get_internal_transmittance (*note
_546::)' virtual function defined in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get material internal transmittance for thickness in mm. Subclasses
_must_ provide this function or the get_extinction_coef() function.

double get_pressure() const
...........................

Get relative air pressure in _Pa_.

   See also set_pressure (*note _540::) function and std_pressure
(*note _541::) variable.

virtual double get_refractive_index(double wavelen) const
.........................................................

This virtual function implements the `get_refractive_index (*note
_550::)' pure function declared in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get material absolute refractive index at specified wavelen in _nm._

virtual bool is_opaque() const
..............................

This virtual function implements the `is_opaque (*note _553::)' pure
function declared in the `Base (*note material_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Return true if material must be considered opaque for ray tracing

virtual bool is_reflecting() const
..................................

This virtual function implements the `is_reflecting (*note _554::)'
pure function declared in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Return true if material may reflect most of the light and must be
considered as a mirror when ignoring ray intensity computation during
ray tracing.

void set_pressure(double pressure)
..................................

Set relative air pressure in _Pa_.

   See also get_pressure (*note _536::) function and std_pressure
(*note _541::) variable.

static const double std_pressure
................................

Standard air pressure is 101325 _Pa_

material::Air class full member list
====================================

Functions
---------

   * Air(double pressure = _[...]_)

   * virtual io::rgb get_color() const

   * virtual double get_extinction_coef(double wavelen) const

   * double get_internal_transmittance(double wavelen) const

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * virtual double get_normal_reflectance(const Base *from, double
     wavelen) const

   * virtual double get_normal_transmittance(const Base *from, double
     wavelen) const

   * double get_pressure() const

   * double get_refractive_index(double wavelen, const Base &env) const

   * virtual double get_refractive_index(double wavelen) const

   * virtual double get_temperature() const

   * virtual bool is_opaque() const

   * virtual bool is_reflecting() const

   * void set_pressure(double pressure)

   * void set_temperature(double temp)

Constant
--------

   * static const double std_pressure

material::Base class reference
==============================

Declaration
-----------

     #include <goptical/core/material/Base>

     namespace goptical {
       namespace material {
         class Base;
       };
     };

   This class is a member of the material namespace.

   This abstract class contains pure virtuals.

Inheritance
-----------

Description
-----------

This class is the base class for all material classes. It desrcibes
physical properties of materials which interact with light.

Members
-------

See also the full member list (*note
material_Base_class_full_member_list::) section for this class.

Functions
.........

   * Base()

   * virtual ~Base()

   * virtual io::rgb get_color() const

   * virtual double get_extinction_coef(double wavelen) const

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * double get_internal_transmittance(double wavelen) const

   * virtual double get_normal_reflectance(const Base *from, double
     wavelen) const

   * virtual double get_normal_transmittance(const Base *from, double
     wavelen) const

   * virtual double get_refractive_index(double wavelen) const = 0;

   * double get_refractive_index(double wavelen, const Base &env) const

   * virtual double get_temperature() const

   * virtual bool is_opaque() const = 0;

   * virtual bool is_reflecting() const = 0;

   * void set_temperature(double temp)

Members detail
--------------

Base()
......

material base constuctor. Set material temperature to 20.

virtual ~Base()
...............

No documentation available

virtual io::rgb get_color() const
.................................

Get material color and alpha

virtual double get_extinction_coef(double wavelen) const
........................................................

Get extinction coefficient. Subclasses _must_ provide this function or
the get_internal_transmittance() function.

virtual double get_internal_transmittance(double wavelen, double thickness) const
.................................................................................

Get material internal transmittance for thickness in mm. Subclasses
_must_ provide this function or the get_extinction_coef() function.

double get_internal_transmittance(double wavelen) const
.......................................................

Get material internal transmittance for 1mm thickness.

virtual double get_normal_reflectance(const Base *from, double wavelen) const
.............................................................................

Get reflectance at normal incidence

virtual double get_normal_transmittance(const Base *from, double wavelen) const
...............................................................................

Get transmittance at normal incidence

virtual double get_refractive_index(double wavelen) const = 0;
..............................................................

Get material absolute refractive index at specified wavelen in _nm._

double get_refractive_index(double wavelen, const Base &env) const
..................................................................

Get material relative refractive index in given medium at specified
wavelen in _nm._

virtual double get_temperature() const
......................................

Get material temperature in celcius

virtual bool is_opaque() const = 0;
...................................

Return true if material must be considered opaque for ray tracing

virtual bool is_reflecting() const = 0;
.......................................

Return true if material may reflect most of the light and must be
considered as a mirror when ignoring ray intensity computation during
ray tracing.

void set_temperature(double temp)
.................................

Set material temperature in celcius

material::Base class full member list
=====================================

Functions
---------

   * Base()

   * virtual ~Base()

   * virtual io::rgb get_color() const

   * virtual double get_extinction_coef(double wavelen) const

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * double get_internal_transmittance(double wavelen) const

   * virtual double get_normal_reflectance(const Base *from, double
     wavelen) const

   * virtual double get_normal_transmittance(const Base *from, double
     wavelen) const

   * virtual double get_refractive_index(double wavelen) const = 0;

   * double get_refractive_index(double wavelen, const Base &env) const

   * virtual double get_temperature() const

   * virtual bool is_opaque() const = 0;

   * virtual bool is_reflecting() const = 0;

   * void set_temperature(double temp)

material::Catalog class reference
=================================

Declaration
-----------

     #include <goptical/core/material/Catalog>

     namespace goptical {
       namespace material {
         class Catalog;
       };
     };

   This class is a member of the material namespace.

Inheritance
-----------

Description
-----------

Hold a glass material catalog

Members
-------

See also the full member list (*note
material_Catalog_class_full_member_list::) section for this class.

Functions
.........

   * Catalog(const std::string &name = _[...]_)

   * void add_material(const std::string &material_name, const
     const_ref<Base> &material)

   * void del_material(const std::string &material_name)

   * const Base & get_material(const std::string &material_name)

   * const std::string & get_name() const

   * void set_name(const std::string &name)

Members detail
--------------

Catalog(const std:: string  &name = "")
.......................................

Create a catalog with given name

void add_material(const std:: string  &material_name, const  const_ref <Base> &material)
........................................................................................

Add a material to catalog. material object will be deleted on catalog
destruction if owner is set.

void del_material(const std:: string  &material_name)
.....................................................

Remove a material from catalog

const Base & get_material(const std:: string  &material_name)
.............................................................

Get material with given name

const std:: string  & get_name() const
......................................

Get catalog name

void set_name(const std:: string  &name)
........................................

Set catalog name

material::Catalog class full member list
========================================

Functions
---------

   * Catalog(const std::string &name = _[...]_)

   * void add_material(const std::string &material_name, const
     const_ref<Base> &material)

   * void del_material(const std::string &material_name)

   * const Base & get_material(const std::string &material_name)

   * const std::string & get_name() const

   * void set_name(const std::string &name)

material::Conrady class reference
=================================

Declaration
-----------

     #include <goptical/core/material/Conrady>

     namespace goptical {
       namespace material {
         class Conrady;
       };
     };

   This class is a member of the material namespace.

Inheritance
-----------

Description
-----------

This class models optical properties of dielectric materials with
conrady refractive index dispersion formula.

   Refractive index formula is:

   n_\lambda = A + \fracB\lambda + \fracC\lambda^3.5

   with  \lambda  the micrometer wavelength.

Members
-------

See also the full member list (*note
material_Conrady_class_full_member_list::) section for this class.

Inherited members
.................

   * 36 members inherited from Dielectric (*note
     material_Dielectric_class_reference::)

Functions
.........

   * Conrady()

   * Conrady(double A, double B, double C)

   * virtual double get_measurement_index(double wavelen) const

   * void set_coefficients(double A, double B, double C)

Members detail
--------------

Conrady()
.........

Create an empty conrady model

Conrady(double A, double B, double C)
.....................................

Create an conrady model with given coefficients

virtual double get_measurement_index(double wavelen) const
..........................................................

This virtual function implements the `get_measurement_index (*note
_617::)' pure function declared in the `Dielectric (*note
material_Dielectric_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get material relative refractive index in measurment medium at
specified wavelen in _nm._

void set_coefficients(double A, double B, double C)
...................................................

Change conrady constant term

material::Conrady class full member list
========================================

Functions
---------

   * Conrady()

   * Conrady(double A, double B, double C)

   * void clear_internal_transmittance()

   * void disable_temperature_coeff()

   * double get_abbe_vd() const

   * double get_abbe_ve() const

   * virtual io::rgb get_color() const

   * double get_density() const

   * virtual double get_extinction_coef(double wavelen) const

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * double get_internal_transmittance(double wavelen) const

   * virtual double get_measurement_index(double wavelen) const

   * virtual double get_normal_reflectance(const Base *from, double
     wavelen) const

   * virtual double get_normal_transmittance(const Base *from, double
     wavelen) const

   * double get_partial_dispersion(double wavelen1, double wavelen2)
     const

   * double get_poisson_ratio() const

   * double get_principal_dispersion() const

   * double get_refractive_index(double wavelen, const Base &env) const

   * virtual double get_refractive_index(double wavelen) const

   * virtual double get_temperature() const

   * double get_thermal_conductivity() const

   * double get_thermal_expansion() const

   * data::DiscreteSet & get_transmittance_dataset()

   * double get_young_modulus() const

   * virtual bool is_opaque() const

   * virtual bool is_reflecting() const

   * void set_coefficients(double A, double B, double C)

   * void set_density(double density)

   * void set_internal_transmittance(double wavelen, double thickness,
     double transmittance)

   * void set_measurement_medium(const const_ref<Base> &medium)

   * void set_poisson_ratio(double poisson_ratio)

   * void set_temperature(double temp)

   * void set_temperature_dndt(double dndt)

   * void set_temperature_schott(double d0, double d1, double d2,
     double e0, double e1, double wl_tk)

   * void set_thermal_conductivity(double thermal_conductivity)

   * void set_thermal_expansion(double thermal_expansion)

   * void set_wavelen_range(double low, double high)

   * void set_young_modulus(double young_modulus)

material::DispersionTable class reference
=========================================

Declaration
-----------

     #include <goptical/core/material/DispersionTable>

     namespace goptical {
       namespace material {
         class DispersionTable;
       };
     };

   This class is a member of the material namespace.

Inheritance
-----------

Description
-----------

This class models refractive index of optical material using user
provided data table.

   Known refractive index values are stored and interpolated by a
data::DiscreteSet (*note data_DiscreteSet_class_reference::) object.
Default interpolation is data::Cubic (*note _146::).

Members
-------

See also the full member list (*note
material_DispersionTable_class_full_member_list::) section for this
class.

Inherited members
.................

   * 36 members inherited from Dielectric (*note
     material_Dielectric_class_reference::)

Functions
.........

   * DispersionTable()

   * void clear_refractive_index_table()

   * virtual double get_measurement_index(double wavelen) const

   * data::DiscreteSet & get_refractive_index_dataset()

   * void set_refractive_index(double wavelen, double index)

Members detail
--------------

DispersionTable()
.................

No documentation available

void clear_refractive_index_table()
...................................

Clear all refractive index data

virtual double get_measurement_index(double wavelen) const
..........................................................

This virtual function implements the `get_measurement_index (*note
_617::)' pure function declared in the `Dielectric (*note
material_Dielectric_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get material relative refractive index in measurment medium at
specified wavelen in _nm._

data::DiscreteSet & get_refractive_index_dataset()
..................................................

Get refractive index dataset object

void set_refractive_index(double wavelen, double index)
.......................................................

Add refractive index data

material::DispersionTable class full member list
================================================

Functions
---------

   * DispersionTable()

   * void clear_internal_transmittance()

   * void clear_refractive_index_table()

   * void disable_temperature_coeff()

   * double get_abbe_vd() const

   * double get_abbe_ve() const

   * virtual io::rgb get_color() const

   * double get_density() const

   * virtual double get_extinction_coef(double wavelen) const

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * double get_internal_transmittance(double wavelen) const

   * virtual double get_measurement_index(double wavelen) const

   * virtual double get_normal_reflectance(const Base *from, double
     wavelen) const

   * virtual double get_normal_transmittance(const Base *from, double
     wavelen) const

   * double get_partial_dispersion(double wavelen1, double wavelen2)
     const

   * double get_poisson_ratio() const

   * double get_principal_dispersion() const

   * double get_refractive_index(double wavelen, const Base &env) const

   * virtual double get_refractive_index(double wavelen) const

   * data::DiscreteSet & get_refractive_index_dataset()

   * virtual double get_temperature() const

   * double get_thermal_conductivity() const

   * double get_thermal_expansion() const

   * data::DiscreteSet & get_transmittance_dataset()

   * double get_young_modulus() const

   * virtual bool is_opaque() const

   * virtual bool is_reflecting() const

   * void set_density(double density)

   * void set_internal_transmittance(double wavelen, double thickness,
     double transmittance)

   * void set_measurement_medium(const const_ref<Base> &medium)

   * void set_poisson_ratio(double poisson_ratio)

   * void set_refractive_index(double wavelen, double index)

   * void set_temperature(double temp)

   * void set_temperature_dndt(double dndt)

   * void set_temperature_schott(double d0, double d1, double d2,
     double e0, double e1, double wl_tk)

   * void set_thermal_conductivity(double thermal_conductivity)

   * void set_thermal_expansion(double thermal_expansion)

   * void set_wavelen_range(double low, double high)

   * void set_young_modulus(double young_modulus)

material::Herzberger class reference
====================================

Declaration
-----------

     #include <goptical/core/material/Herzberger>

     namespace goptical {
       namespace material {
         class Herzberger;
       };
     };

   This class is a member of the material namespace.

Inheritance
-----------

Description
-----------

This class models optical properties of dielectric materials with
Herzberger refractive index dispersion formula:

   n_\lambda = A + B\times\lambda^2 + C\times\lambda^4 +
D\times\lambda^6                + \fracE\lambda^2-0.028 +
\fracF\left(\lambda^2-0.028\right)^2

   with  \lambda  the micrometer wavelength.

Members
-------

See also the full member list (*note
material_Herzberger_class_full_member_list::) section for this class.

Inherited members
.................

   * 36 members inherited from Dielectric (*note
     material_Dielectric_class_reference::)

Functions
.........

   * Herzberger()

   * Herzberger(double A, double B, double C, double D, double E,
     double F)

   * virtual double get_measurement_index(double wavelen) const

   * void set_coefficients(double A, double B, double C, double D,
     double E, double F)

Members detail
--------------

Herzberger()
............

Create an empty herzberger model

Herzberger(double A, double B, double C, double D, double E, double F)
......................................................................

Create an herzberger model with given coefficients

virtual double get_measurement_index(double wavelen) const
..........................................................

This virtual function implements the `get_measurement_index (*note
_617::)' pure function declared in the `Dielectric (*note
material_Dielectric_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get material relative refractive index in measurment medium at
specified wavelen in _nm._

void set_coefficients(double A, double B, double C, double D, double E, double F)
.................................................................................

Change herzberger constant term

material::Herzberger class full member list
===========================================

Functions
---------

   * Herzberger()

   * Herzberger(double A, double B, double C, double D, double E,
     double F)

   * void clear_internal_transmittance()

   * void disable_temperature_coeff()

   * double get_abbe_vd() const

   * double get_abbe_ve() const

   * virtual io::rgb get_color() const

   * double get_density() const

   * virtual double get_extinction_coef(double wavelen) const

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * double get_internal_transmittance(double wavelen) const

   * virtual double get_measurement_index(double wavelen) const

   * virtual double get_normal_reflectance(const Base *from, double
     wavelen) const

   * virtual double get_normal_transmittance(const Base *from, double
     wavelen) const

   * double get_partial_dispersion(double wavelen1, double wavelen2)
     const

   * double get_poisson_ratio() const

   * double get_principal_dispersion() const

   * double get_refractive_index(double wavelen, const Base &env) const

   * virtual double get_refractive_index(double wavelen) const

   * virtual double get_temperature() const

   * double get_thermal_conductivity() const

   * double get_thermal_expansion() const

   * data::DiscreteSet & get_transmittance_dataset()

   * double get_young_modulus() const

   * virtual bool is_opaque() const

   * virtual bool is_reflecting() const

   * void set_coefficients(double A, double B, double C, double D,
     double E, double F)

   * void set_density(double density)

   * void set_internal_transmittance(double wavelen, double thickness,
     double transmittance)

   * void set_measurement_medium(const const_ref<Base> &medium)

   * void set_poisson_ratio(double poisson_ratio)

   * void set_temperature(double temp)

   * void set_temperature_dndt(double dndt)

   * void set_temperature_schott(double d0, double d1, double d2,
     double e0, double e1, double wl_tk)

   * void set_thermal_conductivity(double thermal_conductivity)

   * void set_thermal_expansion(double thermal_expansion)

   * void set_wavelen_range(double low, double high)

   * void set_young_modulus(double young_modulus)

material::Metal class reference
===============================

Declaration
-----------

     #include <goptical/core/material/Metal>

     namespace goptical {
       namespace material {
         class Metal;
       };
     };

   This class is a member of the material namespace.

Inheritance
-----------

Description
-----------

This class models optical properties of metal materials. Extinction and
refractive index are stored as interpolated data sets.

Members
-------

See also the full member list (*note
material_Metal_class_full_member_list::) section for this class.

Inherited members
.................

   * 23 members inherited from Solid (*note
     material_Solid_class_reference::)

Functions
.........

   * Metal()

   * double get_absolute_refractive_index(double wavelen) const

   * virtual double get_extinction_coef(double wavelen) const

   * data::DiscreteSet & get_extinction_coef_dataset()

   * virtual double get_refractive_index(double wavelen) const

   * data::DiscreteSet & get_refractive_index_dataset()

   * virtual bool is_opaque() const

   * virtual bool is_reflecting() const

Members detail
--------------

Metal()
.......

No documentation available

double get_absolute_refractive_index(double wavelen) const
..........................................................

No documentation available

virtual double get_extinction_coef(double wavelen) const
........................................................

This virtual function overrides the `get_extinction_coef (*note
_545::)' virtual function defined in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get extinction coefficient. Subclasses _must_ provide this function
or the get_internal_transmittance() function.

data::DiscreteSet & get_extinction_coef_dataset()
.................................................

Get extinction dataset object

virtual double get_refractive_index(double wavelen) const
.........................................................

This virtual function implements the `get_refractive_index (*note
_550::)' pure function declared in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get material absolute refractive index at specified wavelen in _nm._

data::DiscreteSet & get_refractive_index_dataset()
..................................................

Get refractive index dataset object

virtual bool is_opaque() const
..............................

This virtual function implements the `is_opaque (*note _553::)' pure
function declared in the `Base (*note material_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Return true if material must be considered opaque for ray tracing

virtual bool is_reflecting() const
..................................

This virtual function implements the `is_reflecting (*note _554::)'
pure function declared in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Return true if material may reflect most of the light and must be
considered as a mirror when ignoring ray intensity computation during
ray tracing.

material::Metal class full member list
======================================

Functions
---------

   * Metal()

   * double get_absolute_refractive_index(double wavelen) const

   * virtual io::rgb get_color() const

   * double get_density() const

   * virtual double get_extinction_coef(double wavelen) const

   * data::DiscreteSet & get_extinction_coef_dataset()

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * double get_internal_transmittance(double wavelen) const

   * virtual double get_normal_reflectance(const Base *from, double
     wavelen) const

   * virtual double get_normal_transmittance(const Base *from, double
     wavelen) const

   * double get_poisson_ratio() const

   * double get_refractive_index(double wavelen, const Base &env) const

   * virtual double get_refractive_index(double wavelen) const

   * data::DiscreteSet & get_refractive_index_dataset()

   * virtual double get_temperature() const

   * double get_thermal_conductivity() const

   * double get_thermal_expansion() const

   * double get_young_modulus() const

   * virtual bool is_opaque() const

   * virtual bool is_reflecting() const

   * void set_density(double density)

   * void set_poisson_ratio(double poisson_ratio)

   * void set_temperature(double temp)

   * void set_thermal_conductivity(double thermal_conductivity)

   * void set_thermal_expansion(double thermal_expansion)

   * void set_young_modulus(double young_modulus)

material::Mil class reference
=============================

Declaration
-----------

     #include <goptical/core/material/Mil>

     namespace goptical {
       namespace material {
         class Mil;
       };
     };

   This class is a member of the material namespace.

Inheritance
-----------

Description
-----------

This class is able to extract _nd_ index and _vd_ Abbe number values
from glass code in order to model mil glass material. Glass code format
is described in "_MIL-G-174B_" standard.

   See also Abbe (*note material_Abbe_class_reference::) class.

Members
-------

See also the full member list (*note
material_Mil_class_full_member_list::) section for this class.

Inherited members
.................

   * 36 members inherited from Abbe (*note
     material_Abbe_class_reference::)<AbbeVdFormula>

Function
........

   * Mil(unsigned int code)

Members detail
--------------

Mil(unsigned int code)
......................

Create a glass model based on glass code with "_nnnnvvv_" format.

material::Mil class full member list
====================================

Functions
---------

   * Mil(unsigned int code)

   * void clear_internal_transmittance()

   * void disable_temperature_coeff()

   * double get_abbe_vd() const

   * double get_abbe_ve() const

   * virtual io::rgb get_color() const

   * double get_density() const

   * virtual double get_extinction_coef(double wavelen) const

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * double get_internal_transmittance(double wavelen) const

   * virtual double get_measurement_index(double wavelen) const

   * virtual double get_normal_reflectance(const Base *from, double
     wavelen) const

   * virtual double get_normal_transmittance(const Base *from, double
     wavelen) const

   * double get_partial_dispersion(double wavelen1, double wavelen2)
     const

   * double get_poisson_ratio() const

   * double get_principal_dispersion() const

   * double get_refractive_index(double wavelen, const Base &env) const

   * virtual double get_refractive_index(double wavelen) const

   * virtual double get_temperature() const

   * double get_thermal_conductivity() const

   * double get_thermal_expansion() const

   * data::DiscreteSet & get_transmittance_dataset()

   * double get_young_modulus() const

   * virtual bool is_opaque() const

   * virtual bool is_reflecting() const

   * void set_density(double density)

   * void set_internal_transmittance(double wavelen, double thickness,
     double transmittance)

   * void set_measurement_medium(const const_ref<Base> &medium)

   * void set_poisson_ratio(double poisson_ratio)

   * void set_temperature(double temp)

   * void set_temperature_dndt(double dndt)

   * void set_temperature_schott(double d0, double d1, double d2,
     double e0, double e1, double wl_tk)

   * void set_thermal_conductivity(double thermal_conductivity)

   * void set_thermal_expansion(double thermal_expansion)

   * void set_wavelen_range(double low, double high)

   * void set_young_modulus(double young_modulus)

material::mirror class reference
================================

Declaration
-----------

     #include <goptical/core/material/mirror>

     namespace goptical {
       namespace material {
         class mirror;
       };
     };

   This class is a member of the material namespace.

Inheritance
-----------

Description
-----------

This class models optical properties of a perfect reflecting material.

   A global mirror (*note _527::) variable is available.

Members
-------

See also the full member list (*note
material_mirror_class_full_member_list::) section for this class.

Inherited members
.................

   * 14 members inherited from Base (*note
     material_Base_class_reference::)

Functions
.........

   * mirror()

   * virtual double get_extinction_coef(double wavelen) const

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * virtual double get_refractive_index(double wavelen) const

   * virtual bool is_opaque() const

   * virtual bool is_reflecting() const

Members detail
--------------

mirror()
........

No documentation available

virtual double get_extinction_coef(double wavelen) const
........................................................

This virtual function overrides the `get_extinction_coef (*note
_545::)' virtual function defined in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get extinction coefficient. Subclasses _must_ provide this function
or the get_internal_transmittance() function.

virtual double get_internal_transmittance(double wavelen, double thickness) const
.................................................................................

This virtual function overrides the `get_internal_transmittance (*note
_546::)' virtual function defined in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get material internal transmittance for thickness in mm. Subclasses
_must_ provide this function or the get_extinction_coef() function.

virtual double get_refractive_index(double wavelen) const
.........................................................

This virtual function implements the `get_refractive_index (*note
_550::)' pure function declared in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get material absolute refractive index at specified wavelen in _nm._

virtual bool is_opaque() const
..............................

This virtual function implements the `is_opaque (*note _553::)' pure
function declared in the `Base (*note material_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Return true if material must be considered opaque for ray tracing

virtual bool is_reflecting() const
..................................

This virtual function implements the `is_reflecting (*note _554::)'
pure function declared in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Return true if material may reflect most of the light and must be
considered as a mirror when ignoring ray intensity computation during
ray tracing.

material::mirror class full member list
=======================================

Functions
---------

   * mirror()

   * virtual io::rgb get_color() const

   * virtual double get_extinction_coef(double wavelen) const

   * double get_internal_transmittance(double wavelen) const

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * virtual double get_normal_reflectance(const Base *from, double
     wavelen) const

   * virtual double get_normal_transmittance(const Base *from, double
     wavelen) const

   * double get_refractive_index(double wavelen, const Base &env) const

   * virtual double get_refractive_index(double wavelen) const

   * virtual double get_temperature() const

   * virtual bool is_opaque() const

   * virtual bool is_reflecting() const

   * void set_temperature(double temp)

material::Schott class reference
================================

Declaration
-----------

     #include <goptical/core/material/Schott>

     namespace goptical {
       namespace material {
         class Schott;
       };
     };

   This class is a member of the material namespace.

Inheritance
-----------

Description
-----------

This class models optical properties of dielectric materials with
Schott refractive index dispersion formula:

   n_\lambda = \sqrt \sum\limits_i A_i\times\lambda^2i

   with  \lambda  the micrometer wavelength.

Members
-------

See also the full member list (*note
material_Schott_class_full_member_list::) section for this class.

Inherited members
.................

   * 36 members inherited from Dielectric (*note
     material_Dielectric_class_reference::)

Functions
.........

   * Schott()

   * Schott(double A, double B, double C, double D, double E, double F)

   * void set_term(int term, double K)

   * void set_terms_range(int first, int last)

Members detail
--------------

Schott()
........

Create an empty schott model

Schott(double A, double B, double C, double D, double E, double F)
..................................................................

Create a schott model with [-8,2] exponents range:

   n_\lambda = \sqrt A + B\times\lambda^2 + \fracC\lambda^2
     + \fracD\lambda^4 + \fracE\lambda^6 + \fracF\lambda^8

void set_term(int term, double K)
.................................

Set term coefficient, `term' must be a multiple of 2.

void set_terms_range(int first, int last)
.........................................

Set exponents range, must be multiples of 2

material::Schott class full member list
=======================================

Functions
---------

   * Schott()

   * Schott(double A, double B, double C, double D, double E, double F)

   * void clear_internal_transmittance()

   * void disable_temperature_coeff()

   * double get_abbe_vd() const

   * double get_abbe_ve() const

   * virtual io::rgb get_color() const

   * double get_density() const

   * virtual double get_extinction_coef(double wavelen) const

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * double get_internal_transmittance(double wavelen) const

   * virtual double get_normal_reflectance(const Base *from, double
     wavelen) const

   * virtual double get_normal_transmittance(const Base *from, double
     wavelen) const

   * double get_partial_dispersion(double wavelen1, double wavelen2)
     const

   * double get_poisson_ratio() const

   * double get_principal_dispersion() const

   * double get_refractive_index(double wavelen, const Base &env) const

   * virtual double get_refractive_index(double wavelen) const

   * virtual double get_temperature() const

   * double get_thermal_conductivity() const

   * double get_thermal_expansion() const

   * data::DiscreteSet & get_transmittance_dataset()

   * double get_young_modulus() const

   * virtual bool is_opaque() const

   * virtual bool is_reflecting() const

   * void set_density(double density)

   * void set_internal_transmittance(double wavelen, double thickness,
     double transmittance)

   * void set_measurement_medium(const const_ref<Base> &medium)

   * void set_poisson_ratio(double poisson_ratio)

   * void set_temperature(double temp)

   * void set_temperature_dndt(double dndt)

   * void set_temperature_schott(double d0, double d1, double d2,
     double e0, double e1, double wl_tk)

   * void set_term(int term, double K)

   * void set_terms_range(int first, int last)

   * void set_thermal_conductivity(double thermal_conductivity)

   * void set_thermal_expansion(double thermal_expansion)

   * void set_wavelen_range(double low, double high)

   * void set_young_modulus(double young_modulus)

material::Sellmeier class reference
===================================

Declaration
-----------

     #include <goptical/core/material/Sellmeier>

     namespace goptical {
       namespace material {
         class Sellmeier;
       };
     };

   This class is a member of the material namespace.

Inheritance
-----------

Description
-----------

This class models optical properties of dielectric materials using
Sellmeier  refractive index dispersion formula:

   n_\lambda = \sqrt A + \sum\limits_i^ \fracB_i \times
\lambda^2\lambda^2 - C_i

   with  \lambda  the micrometer wavelength.

   See also SellmeierMod (*note
material_SellmeierMod_class_reference::) class.

Members
-------

See also the full member list (*note
material_Sellmeier_class_full_member_list::) section for this class.

Inherited members
.................

   * 36 members inherited from Dielectric (*note
     material_Dielectric_class_reference::)

Functions
.........

   * Sellmeier()

   * Sellmeier(double K1, double L1, double K2, double L2, double K3,
     double L3)

   * virtual double get_measurement_index(double wavelen) const

   * void set_contant_term(double A)

   * void set_term(unsigned int i, double B, double C)

   * void set_terms_count(unsigned int c)

Members detail
--------------

Sellmeier()
...........

Create an empty sellmeier model

Sellmeier(double K1, double L1, double K2, double L2, double K3, double L3)
...........................................................................

Create an 3rd order sellmeier model with given coefficients and 1.0
constant

virtual double get_measurement_index(double wavelen) const
..........................................................

This virtual function implements the `get_measurement_index (*note
_617::)' pure function declared in the `Dielectric (*note
material_Dielectric_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get material relative refractive index in measurment medium at
specified wavelen in _nm._

void set_contant_term(double A)
...............................

Change sellmeier constant term

void set_term(unsigned int i, double B, double C)
.................................................

Set term coefficients

void set_terms_count(unsigned int c)
....................................

Set terms count

material::Sellmeier class full member list
==========================================

Functions
---------

   * Sellmeier()

   * Sellmeier(double K1, double L1, double K2, double L2, double K3,
     double L3)

   * void clear_internal_transmittance()

   * void disable_temperature_coeff()

   * double get_abbe_vd() const

   * double get_abbe_ve() const

   * virtual io::rgb get_color() const

   * double get_density() const

   * virtual double get_extinction_coef(double wavelen) const

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * double get_internal_transmittance(double wavelen) const

   * virtual double get_measurement_index(double wavelen) const

   * virtual double get_normal_reflectance(const Base *from, double
     wavelen) const

   * virtual double get_normal_transmittance(const Base *from, double
     wavelen) const

   * double get_partial_dispersion(double wavelen1, double wavelen2)
     const

   * double get_poisson_ratio() const

   * double get_principal_dispersion() const

   * double get_refractive_index(double wavelen, const Base &env) const

   * virtual double get_refractive_index(double wavelen) const

   * virtual double get_temperature() const

   * double get_thermal_conductivity() const

   * double get_thermal_expansion() const

   * data::DiscreteSet & get_transmittance_dataset()

   * double get_young_modulus() const

   * virtual bool is_opaque() const

   * virtual bool is_reflecting() const

   * void set_contant_term(double A)

   * void set_density(double density)

   * void set_internal_transmittance(double wavelen, double thickness,
     double transmittance)

   * void set_measurement_medium(const const_ref<Base> &medium)

   * void set_poisson_ratio(double poisson_ratio)

   * void set_temperature(double temp)

   * void set_temperature_dndt(double dndt)

   * void set_temperature_schott(double d0, double d1, double d2,
     double e0, double e1, double wl_tk)

   * void set_term(unsigned int i, double B, double C)

   * void set_terms_count(unsigned int c)

   * void set_thermal_conductivity(double thermal_conductivity)

   * void set_thermal_expansion(double thermal_expansion)

   * void set_wavelen_range(double low, double high)

   * void set_young_modulus(double young_modulus)

material::SellmeierMod class reference
======================================

Declaration
-----------

     #include <goptical/core/material/SellmeierMod>

     namespace goptical {
       namespace material {
         template <enum SellmeierModFormula m> class SellmeierMod;
       };
     };

   This class is a member of the material namespace.

Inheritance
-----------

Description
-----------

This class models optical properties of dielectric materials with
various modified Sellmeier formulas:

   * SellmeierMod2 (*note _524::) :  n_\lambda = \sqrtA +
     \fracB\times\lambda^2\lambda^2 - C^2
       + \fracD\lambda^2 - E^2

   * Handbook1 (*note _522::) :  n_\lambda = \sqrtA + B\times\lambda^2
     + \fracC\lambda^2-D

   * Handbook2 (*note _523::) :  n_\lambda = \sqrtA + B\times\lambda^2
     + \fracC\times\lambda^2\lambda^2-D


   with  \lambda  the micrometer wavelength.

   See also Sellmeier (*note material_Sellmeier_class_reference::)
class.

Members
-------

See also the full member list (*note
material_SellmeierMod_class_full_member_list::) section for this class.

Inherited members
.................

   * 36 members inherited from Dielectric (*note
     material_Dielectric_class_reference::)

Functions
.........

   * SellmeierMod()

   * SellmeierMod(double A, double B, double C, double D, double E =
     _[...]_)

   * virtual double get_measurement_index(double wavelen) const

   * void set_coefficients(double A, double B, double C, double D,
     double E = _[...]_)

Members detail
--------------

SellmeierMod()
..............

Create an empty modified sellmeier model

SellmeierMod(double A, double B, double C, double D, double E = 0.0)
....................................................................

Create a modified sellmeier model with given coefficients

virtual double get_measurement_index(double wavelen) const
..........................................................

This virtual function implements the `get_measurement_index (*note
_617::)' pure function declared in the `Dielectric (*note
material_Dielectric_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get material relative refractive index in measurment medium at
specified wavelen in _nm._

void set_coefficients(double A, double B, double C, double D, double E = 0.0)
.............................................................................

Change coefficients

material::SellmeierMod class full member list
=============================================

Functions
---------

   * SellmeierMod()

   * SellmeierMod(double A, double B, double C, double D, double E =
     _[...]_)

   * void clear_internal_transmittance()

   * void disable_temperature_coeff()

   * double get_abbe_vd() const

   * double get_abbe_ve() const

   * virtual io::rgb get_color() const

   * double get_density() const

   * virtual double get_extinction_coef(double wavelen) const

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * double get_internal_transmittance(double wavelen) const

   * virtual double get_measurement_index(double wavelen) const

   * virtual double get_normal_reflectance(const Base *from, double
     wavelen) const

   * virtual double get_normal_transmittance(const Base *from, double
     wavelen) const

   * double get_partial_dispersion(double wavelen1, double wavelen2)
     const

   * double get_poisson_ratio() const

   * double get_principal_dispersion() const

   * double get_refractive_index(double wavelen, const Base &env) const

   * virtual double get_refractive_index(double wavelen) const

   * virtual double get_temperature() const

   * double get_thermal_conductivity() const

   * double get_thermal_expansion() const

   * data::DiscreteSet & get_transmittance_dataset()

   * double get_young_modulus() const

   * virtual bool is_opaque() const

   * virtual bool is_reflecting() const

   * void set_coefficients(double A, double B, double C, double D,
     double E = _[...]_)

   * void set_density(double density)

   * void set_internal_transmittance(double wavelen, double thickness,
     double transmittance)

   * void set_measurement_medium(const const_ref<Base> &medium)

   * void set_poisson_ratio(double poisson_ratio)

   * void set_temperature(double temp)

   * void set_temperature_dndt(double dndt)

   * void set_temperature_schott(double d0, double d1, double d2,
     double e0, double e1, double wl_tk)

   * void set_thermal_conductivity(double thermal_conductivity)

   * void set_thermal_expansion(double thermal_expansion)

   * void set_wavelen_range(double low, double high)

   * void set_young_modulus(double young_modulus)

material::Vacuum class reference
================================

Declaration
-----------

     #include <goptical/core/material/Vacuum>

     namespace goptical {
       namespace material {
         class Vacuum;
       };
     };

   This class is a member of the material namespace.

Inheritance
-----------

Description
-----------

This class models optical properties of vacuum. A global variable
vacuum (*note _530::) is available.

Members
-------

See also the full member list (*note
material_Vacuum_class_full_member_list::) section for this class.

Inherited members
.................

   * 14 members inherited from Base (*note
     material_Base_class_reference::)

Functions
.........

   * Vacuum()

   * virtual double get_extinction_coef(double wavelen) const

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * virtual double get_refractive_index(double wavelen) const

   * virtual bool is_opaque() const

   * virtual bool is_reflecting() const

Members detail
--------------

Vacuum()
........

No documentation available

virtual double get_extinction_coef(double wavelen) const
........................................................

This virtual function overrides the `get_extinction_coef (*note
_545::)' virtual function defined in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get extinction coefficient. Subclasses _must_ provide this function
or the get_internal_transmittance() function.

virtual double get_internal_transmittance(double wavelen, double thickness) const
.................................................................................

This virtual function overrides the `get_internal_transmittance (*note
_546::)' virtual function defined in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get material internal transmittance for thickness in mm. Subclasses
_must_ provide this function or the get_extinction_coef() function.

virtual double get_refractive_index(double wavelen) const
.........................................................

This virtual function implements the `get_refractive_index (*note
_550::)' pure function declared in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get material absolute refractive index at specified wavelen in _nm._

virtual bool is_opaque() const
..............................

This virtual function implements the `is_opaque (*note _553::)' pure
function declared in the `Base (*note material_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Return true if material must be considered opaque for ray tracing

virtual bool is_reflecting() const
..................................

This virtual function implements the `is_reflecting (*note _554::)'
pure function declared in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Return true if material may reflect most of the light and must be
considered as a mirror when ignoring ray intensity computation during
ray tracing.

material::Vacuum class full member list
=======================================

Functions
---------

   * Vacuum()

   * virtual io::rgb get_color() const

   * virtual double get_extinction_coef(double wavelen) const

   * double get_internal_transmittance(double wavelen) const

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * virtual double get_normal_reflectance(const Base *from, double
     wavelen) const

   * virtual double get_normal_transmittance(const Base *from, double
     wavelen) const

   * double get_refractive_index(double wavelen, const Base &env) const

   * virtual double get_refractive_index(double wavelen) const

   * virtual double get_temperature() const

   * virtual bool is_opaque() const

   * virtual bool is_reflecting() const

   * void set_temperature(double temp)

material::Dielectric class reference
====================================

Declaration
-----------

     #include <goptical/core/material/Dielectric>

     namespace goptical {
       namespace material {
         class Dielectric;
       };
     };

   This class is a member of the material namespace.

   This abstract class contains pure virtuals.

Inheritance
-----------

Description
-----------

This class models optical properties of dielectric materials.
Transmittance values are stored in an data::Set (*note
data_Set_class_reference::) object with data::Cubic (*note _146::)
interpolation enabled.

   Child class has to implement the get_measurement_index (*note
_617::) function which must return relative refractive index as
measured in medium material set by set_measurement_medium (*note
_625::) function. Default measurement medium is std_air (*note _529::).

   The relative refractive index together with the absolute refractive
index of measurement medium are used to compute absolute refractive
index of dielectric material at reference temperature. This is the
value returned by the get_refractive_index (*note _620::) function when
no temperature model is in use.

   Temperature coeffiecients can be defined to take current material
temperature into account when computing absolute refractive index:

   * The set_temperature_dndt (*note _626::) function enables use of
     refractive index temperature deviation factor.

   * The set_temperature_schott (*note _627::) function enables Schott
     temperature model as described in Schott "_TIE-19: Temperature
     Coefficient of the Refractive Index_" technical information
     document. It uses the following formula:

     n_t = \fracn^2-1.02\times n \times \Delta t
     \times \left( \frac\Delta t\times E_1+E_0\lambda^2-\lambda_tk^2 +
                    D_2\times \Delta t^2+D_1\times \Delta t+D_0 \right)

     with  \Delta t = t - t_ref  and  \lambda  the micrometer
     wavelength.


Members
-------

See also the full member list (*note
material_Dielectric_class_full_member_list::) section for this class.

Inherited members
.................

   * 23 members inherited from Solid (*note
     material_Solid_class_reference::)

Functions
.........

   * Dielectric()

   * void clear_internal_transmittance()

   * void disable_temperature_coeff()

   * double get_abbe_vd() const

   * double get_abbe_ve() const

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * double get_internal_transmittance(double wavelen) const

   * virtual double get_measurement_index(double wavelen) const = 0;

   * double get_partial_dispersion(double wavelen1, double wavelen2)
     const

   * double get_principal_dispersion() const

   * virtual double get_refractive_index(double wavelen) const

   * data::DiscreteSet & get_transmittance_dataset()

   * virtual bool is_opaque() const

   * virtual bool is_reflecting() const

   * void set_internal_transmittance(double wavelen, double thickness,
     double transmittance)

   * void set_measurement_medium(const const_ref<Base> &medium)

   * void set_temperature_dndt(double dndt)

   * void set_temperature_schott(double d0, double d1, double d2,
     double e0, double e1, double wl_tk)

   * void set_wavelen_range(double low, double high)

Members detail
--------------

Dielectric()
............

No documentation available

void clear_internal_transmittance()
...................................

Clear all transmittance data. Returned transmittance value is always
1.0 when the data set is empty.

   See also get_transmittance_dataset (*note _621::) function.

void disable_temperature_coeff()
................................

Disable use of temperature coefficients

double get_abbe_vd() const
..........................

Compute glass Abbe number from refractive index model. Use d spectral
line. Wavelen is in _nm_

double get_abbe_ve() const
..........................

Compute glass Abbe number from refractive index model. Use d spectral
line. Wavelen is in _nm_

virtual double get_internal_transmittance(double wavelen, double thickness) const
.................................................................................

This virtual function overrides the `get_internal_transmittance (*note
_546::)' virtual function defined in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get material internal transmittance for thickness in mm. Subclasses
_must_ provide this function or the get_extinction_coef() function.

double get_internal_transmittance(double wavelen) const
.......................................................

This function shadows the `get_internal_transmittance (*note _547::)'
function defined in the `Base (*note material_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get material internal transmittance for 1mm thickness.

virtual double get_measurement_index(double wavelen) const = 0;
...............................................................

Get material relative refractive index in measurment medium at
specified wavelen in _nm._

double get_partial_dispersion(double wavelen1, double wavelen2) const
.....................................................................

Compute glass partial dispersion between two wavelen in _nm_

double get_principal_dispersion() const
.......................................

Compute glass principal dispersion.

virtual double get_refractive_index(double wavelen) const
.........................................................

This virtual function implements the `get_refractive_index (*note
_550::)' pure function declared in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get material absolute refractive index at specified wavelen in _nm._

data::DiscreteSet & get_transmittance_dataset()
...............................................

Get internal tranmittance dataset object.

   See also clear_internal_transmittance (*note _611::) function.

virtual bool is_opaque() const
..............................

This virtual function implements the `is_opaque (*note _553::)' pure
function declared in the `Base (*note material_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Return true if material must be considered opaque for ray tracing

virtual bool is_reflecting() const
..................................

This virtual function implements the `is_reflecting (*note _554::)'
pure function declared in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Return true if material may reflect most of the light and must be
considered as a mirror when ignoring ray intensity computation during
ray tracing.

void set_internal_transmittance(double wavelen, double thickness, double transmittance)
.......................................................................................

Add transmittance data, wavelen in nm

void set_measurement_medium(const  const_ref <Base> &medium)
............................................................

Set glass measurement medium material.

void set_temperature_dndt(double dndt)
......................................

Set and enable dn/dt thermal coefficient.

void set_temperature_schott(double d0, double d1, double d2, double e0, double e1, double wl_tk)
................................................................................................

Set and enable Schott thermal coefficients. wl_tk in _um._

void set_wavelen_range(double low, double high)
...............................................

Set wavelen validity range in _nm_

material::Dielectric class full member list
===========================================

Functions
---------

   * Dielectric()

   * void clear_internal_transmittance()

   * void disable_temperature_coeff()

   * double get_abbe_vd() const

   * double get_abbe_ve() const

   * virtual io::rgb get_color() const

   * double get_density() const

   * virtual double get_extinction_coef(double wavelen) const

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * double get_internal_transmittance(double wavelen) const

   * virtual double get_measurement_index(double wavelen) const = 0;

   * virtual double get_normal_reflectance(const Base *from, double
     wavelen) const

   * virtual double get_normal_transmittance(const Base *from, double
     wavelen) const

   * double get_partial_dispersion(double wavelen1, double wavelen2)
     const

   * double get_poisson_ratio() const

   * double get_principal_dispersion() const

   * double get_refractive_index(double wavelen, const Base &env) const

   * virtual double get_refractive_index(double wavelen) const

   * virtual double get_temperature() const

   * double get_thermal_conductivity() const

   * double get_thermal_expansion() const

   * data::DiscreteSet & get_transmittance_dataset()

   * double get_young_modulus() const

   * virtual bool is_opaque() const

   * virtual bool is_reflecting() const

   * void set_density(double density)

   * void set_internal_transmittance(double wavelen, double thickness,
     double transmittance)

   * void set_measurement_medium(const const_ref<Base> &medium)

   * void set_poisson_ratio(double poisson_ratio)

   * void set_temperature(double temp)

   * void set_temperature_dndt(double dndt)

   * void set_temperature_schott(double d0, double d1, double d2,
     double e0, double e1, double wl_tk)

   * void set_thermal_conductivity(double thermal_conductivity)

   * void set_thermal_expansion(double thermal_expansion)

   * void set_wavelen_range(double low, double high)

   * void set_young_modulus(double young_modulus)

material::Proxy class reference
===============================

Declaration
-----------

     #include <goptical/core/material/Proxy>

     namespace goptical {
       namespace material {
         class Proxy;
       };
     };

   This class is a member of the material namespace.

Inheritance
-----------

Description
-----------

Optical material proxy class.

Members
-------

See also the full member list (*note
material_Proxy_class_full_member_list::) section for this class.

Inherited members
.................

   * 14 members inherited from Base (*note
     material_Base_class_reference::)

Functions
.........

   * Proxy(const const_ref<Base> &m)

   * virtual io::rgb get_color() const

   * virtual double get_extinction_coef(double wavelen) const

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * const Base & get_material() const

   * virtual double get_normal_reflectance(const Base *from, double
     wavelen) const

   * virtual double get_normal_transmittance(const Base *from, double
     wavelen) const

   * virtual double get_refractive_index(double wavelen) const

   * virtual double get_temperature() const

   * virtual bool is_opaque() const

   * virtual bool is_reflecting() const

   * void set_material(const const_ref<Base> &m)

Members detail
--------------

Proxy(const  const_ref <Base> &m)
.................................

No documentation available

virtual io::rgb get_color() const
.................................

This virtual function overrides the `get_color (*note _544::)' virtual
function defined in the `Base (*note material_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get material color and alpha

virtual double get_extinction_coef(double wavelen) const
........................................................

This virtual function overrides the `get_extinction_coef (*note
_545::)' virtual function defined in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get extinction coefficient. Subclasses _must_ provide this function
or the get_internal_transmittance() function.

virtual double get_internal_transmittance(double wavelen, double thickness) const
.................................................................................

This virtual function overrides the `get_internal_transmittance (*note
_546::)' virtual function defined in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get material internal transmittance for thickness in mm. Subclasses
_must_ provide this function or the get_extinction_coef() function.

const Base & get_material() const
.................................

No documentation available

virtual double get_normal_reflectance(const Base *from, double wavelen) const
.............................................................................

This virtual function overrides the `get_normal_reflectance (*note
_548::)' virtual function defined in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get reflectance at normal incidence

virtual double get_normal_transmittance(const Base *from, double wavelen) const
...............................................................................

This virtual function overrides the `get_normal_transmittance (*note
_549::)' virtual function defined in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get transmittance at normal incidence

virtual double get_refractive_index(double wavelen) const
.........................................................

This virtual function implements the `get_refractive_index (*note
_550::)' pure function declared in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get material absolute refractive index at specified wavelen in _nm._

virtual double get_temperature() const
......................................

This virtual function overrides the `get_temperature (*note _552::)'
virtual function defined in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get material temperature in celcius

virtual bool is_opaque() const
..............................

This virtual function implements the `is_opaque (*note _553::)' pure
function declared in the `Base (*note material_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Return true if material must be considered opaque for ray tracing

virtual bool is_reflecting() const
..................................

This virtual function implements the `is_reflecting (*note _554::)'
pure function declared in the `Base (*note
material_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Return true if material may reflect most of the light and must be
considered as a mirror when ignoring ray intensity computation during
ray tracing.

void set_material(const  const_ref <Base> &m)
.............................................

No documentation available

material::Proxy class full member list
======================================

Functions
---------

   * Proxy(const const_ref<Base> &m)

   * virtual io::rgb get_color() const

   * virtual double get_extinction_coef(double wavelen) const

   * double get_internal_transmittance(double wavelen) const

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * const Base & get_material() const

   * virtual double get_normal_reflectance(const Base *from, double
     wavelen) const

   * virtual double get_normal_transmittance(const Base *from, double
     wavelen) const

   * double get_refractive_index(double wavelen, const Base &env) const

   * virtual double get_refractive_index(double wavelen) const

   * virtual double get_temperature() const

   * virtual bool is_opaque() const

   * virtual bool is_reflecting() const

   * void set_material(const const_ref<Base> &m)

   * void set_temperature(double temp)

material::Solid class reference
===============================

Declaration
-----------

     #include <goptical/core/material/Solid>

     namespace goptical {
       namespace material {
         class Solid;
       };
     };

   This class is a member of the material namespace.

Inheritance
-----------

Description
-----------

This class is the base class for all solid material models.

Members
-------

See also the full member list (*note
material_Solid_class_full_member_list::) section for this class.

Inherited members
.................

   * 14 members inherited from Base (*note
     material_Base_class_reference::)

Functions
.........

   * Solid()

   * double get_density() const

   * double get_poisson_ratio() const

   * double get_thermal_conductivity() const

   * double get_thermal_expansion() const

   * double get_young_modulus() const

   * void set_density(double density)

   * void set_poisson_ratio(double poisson_ratio)

   * void set_thermal_conductivity(double thermal_conductivity)

   * void set_thermal_expansion(double thermal_expansion)

   * void set_young_modulus(double young_modulus)

Members detail
--------------

Solid()
.......

No documentation available

double get_density() const
..........................

Get material density in g/cm^3.

   See also set_density (*note _647::) function.

double get_poisson_ratio() const
................................

Get material poisson ratio.

   See also set_poisson_ratio (*note _648::) function.

double get_thermal_conductivity() const
.......................................

Get Set material thermal conductivity in W/m.K.

   See also set_thermal_conductivity (*note _649::) function.

double get_thermal_expansion() const
....................................

Get material thermal expansion coefficient.

   See also set_thermal_expansion (*note _650::) function.

double get_young_modulus() const
................................

Get material young modulus.

   See also set_young_modulus (*note _651::) function.

void set_density(double density)
................................

Set material density in g/cm^3.

   See also get_density (*note _642::) function.

void set_poisson_ratio(double poisson_ratio)
............................................

Set material poisson ratio.

   See also get_poisson_ratio (*note _643::) function.

void set_thermal_conductivity(double thermal_conductivity)
..........................................................

Set Set material thermal conductivity in W/m.K.

   See also get_thermal_conductivity (*note _644::) function.

void set_thermal_expansion(double thermal_expansion)
....................................................

Set material thermal expansion coefficient.

   See also get_thermal_expansion (*note _645::) function.

void set_young_modulus(double young_modulus)
............................................

Set material young modulus.

   See also get_young_modulus (*note _646::) function.

material::Solid class full member list
======================================

Functions
---------

   * Solid()

   * virtual io::rgb get_color() const

   * double get_density() const

   * virtual double get_extinction_coef(double wavelen) const

   * virtual double get_internal_transmittance(double wavelen, double
     thickness) const

   * double get_internal_transmittance(double wavelen) const

   * virtual double get_normal_reflectance(const Base *from, double
     wavelen) const

   * virtual double get_normal_transmittance(const Base *from, double
     wavelen) const

   * double get_poisson_ratio() const

   * virtual double get_refractive_index(double wavelen) const = 0;

   * double get_refractive_index(double wavelen, const Base &env) const

   * virtual double get_temperature() const

   * double get_thermal_conductivity() const

   * double get_thermal_expansion() const

   * double get_young_modulus() const

   * virtual bool is_opaque() const = 0;

   * virtual bool is_reflecting() const = 0;

   * void set_density(double density)

   * void set_poisson_ratio(double poisson_ratio)

   * void set_temperature(double temp)

   * void set_thermal_conductivity(double thermal_conductivity)

   * void set_thermal_expansion(double thermal_expansion)

   * void set_young_modulus(double young_modulus)

math namespace reference
========================

Description
-----------

mathematical tools and functions

Members
-------

Types
.....

   * typedef _ [...] _ vector2

   * typedef _ [...] _ vector3

   * typedef _ [...] _ vectorPair3

   * template struct Matrix

   * typedef _ [...] _ Matrix3x3

   * class Quaternion

   * template class Transform<3>

   * template class Transform<2>

   * typedef _ [...] _ Transform2

   * typedef _ [...] _ Transform3

   * template struct Triangle

   * template struct Triangle<3>

   * template struct vector

   * template struct vector<3, T>

   * template struct vector<2, T>

   * template struct vectorPair

   * template struct vectorPair<2>

   * template struct vectorPair<3>

   * typedef _ [...] _ vectorPair2

   * typedef _ [...] _ range_t

Functions
.........

   * double degree2rad(double x)

   * void get_rotation_matrix(Matrix<2> &m, unsigned int axis, double
     rangle)

   * void get_rotation_matrix(Matrix<3> &m, unsigned int axis, double
     rangle)

   * double lp_floor(double x, double n)

   * double lp_mod(double x, double n)

   * template std::ostream & operator<<(std::ostream &o, const
     vectorBase<N, T> &v)

   * template std::ostream & operator<<(std::ostream &o, const
     vectorPairBase<N> &l)

   * template std::ostream & operator<<(std::ostream &o, const
     Matrix<N> &m)

   * std::ostream & operator<<(std::ostream &o, const Quaternion &q)

   * template std::ostream & operator<<(std::ostream &o, const
     TransformBase<N> &t)

   * template std::ostream & operator<<(std::ostream &o, const
     Triangle<N> &l)

   * double rad2degree(double x)

   * double square(double x)

Constants
.........

   * const vector2 vector2_0

   * const vector2 vector2_01

   * const vector2 vector2_1

   * const vector2 vector2_10

   * const vectorPair<2> vector2_pair_00

   * const vectorPair<2> vector2_pair_01

   * const vector3 vector3_0

   * const vector3 vector3_001

   * const vector3 vector3_010

   * const vector3 vector3_1

   * const vector3 vector3_100

   * const vectorPair<3> vector3_pair_00

   * const vectorPair<3> vector3_pair_01

Members detail
--------------

typedef vector<2, double> vector2
.................................

See vector (*note math_vector_2_T_struct_reference::)<2, T> struct.

typedef vector<3, double> vector3
.................................

See vector (*note math_vector_3_T_struct_reference::)<3, T> struct.

typedef vectorPair<3> vectorPair3
.................................

See vectorPair (*note math_vectorPair_3_struct_reference::)<3> struct.

typedef Matrix<3> Matrix3x3
...........................

No documentation available

typedef Transform<2> Transform2
...............................

See Transform (*note math_Transform_2_class_reference::)<2> class.

typedef Transform<3> Transform3
...............................

See Transform (*note math_Transform_3_class_reference::)<3> class.

typedef vectorPair<2> vectorPair2
.................................

See vectorPair (*note math_vectorPair_2_struct_reference::)<2> struct.

double degree2rad(double x)
...........................

Convert from degrees to radians

void get_rotation_matrix(Matrix<2> &m, unsigned int axis, double rangle)
........................................................................

Setup a 2d rotation matrix with specified angle in radian. axis
parameter must be 0.

void get_rotation_matrix(Matrix<3> &m, unsigned int axis, double rangle)
........................................................................

Setup a 3d rotation matrix with specified angle in radian. axis
parameter can be 0, 1 or 2 for x, y and z axes.

double lp_floor(double x, double n)
...................................

No documentation available

double lp_mod(double x, double n)
.................................

No documentation available

template <int N, typename T> std:: ostream  & operator<<(std:: ostream  &o, const vectorBase<N, T> &v)
......................................................................................................

No documentation available

template <int N> std:: ostream  & operator<<(std:: ostream  &o, const vectorPairBase<N> &l)
...........................................................................................

No documentation available

template <int N> std:: ostream  & operator<<(std:: ostream  &o, const Matrix<N> &m)
...................................................................................

No documentation available

std:: ostream  & operator<<(std:: ostream  &o, const Quaternion &q)
...................................................................

No documentation available

template <int N> std:: ostream  & operator<<(std:: ostream  &o, const TransformBase<N> &t)
..........................................................................................

No documentation available

template <int N> std:: ostream  & operator<<(std:: ostream  &o, const Triangle<N> &l)
.....................................................................................

No documentation available

double rad2degree(double x)
...........................

Convert from radians to degrees

typedef std:: pair <double, double> range_t
...........................................

No documentation available

double square(double x)
.......................

Compute square

const vector2 vector2_0 = vector2(0.0,0.0)
..........................................

Commonly used vector constant

const vector2 vector2_01
........................

Commonly used vector constant

const vector2 vector2_1
.......................

Commonly used vector constant

const vector2 vector2_10
........................

Commonly used vector constant

const vectorPair<2> vector2_pair_00
...................................

No documentation available

const vectorPair<2> vector2_pair_01
...................................

No documentation available

const vector3 vector3_0
.......................

Commonly used vector constant

const vector3 vector3_001
.........................

Commonly used vector constant

const vector3 vector3_010
.........................

Commonly used vector constant

const vector3 vector3_1
.......................

Commonly used vector constant

const vector3 vector3_100
.........................

Commonly used vector constant

const vectorPair<3> vector3_pair_00
...................................

No documentation available

const vectorPair<3> vector3_pair_01
...................................

No documentation available

math::Matrix struct reference
=============================

Declaration
-----------

     #include <goptical/core/math/Matrix>

     namespace goptical {
       namespace math {
         template <int N> struct Matrix;
       };
     };

   This struct is a member of the math namespace.

Description
-----------

NxN square matrix class.

Members
-------

See also the full member list (*note
math_Matrix_struct_full_member_list::) section for this struct.

Functions
.........

   * void adjugate(Matrix &result) const

   * Matrix adjugate() const

   * double determinant() const

   * void inverse(Matrix &result) const

   * Matrix inverse() const

   * Matrix operator*(double scale) const

   * Matrix operator*(const Matrix &m) const

   * vector<N> operator*(const vector<N> &v) const

   * Matrix operator+(const Matrix &m) const

   * Matrix operator-(const Matrix &m) const

   * Matrix operator/(double scale) const

   * Matrix & set(double value = _[...]_)

   * Matrix & set_col(int col, double value)

   * Matrix & set_col(int col, const vector<N> &v)

   * Matrix & set_diag(double value = _[...]_)

   * Matrix & set_diag(const vector<N> &v)

   * Matrix & set_id()

   * Matrix & set_row(int row, double value)

   * Matrix & set_row(int row, const vector<N> &v)

   * void transpose(Matrix &result) const

   * Matrix transpose() const

   * double value(int x, int y) const

   * double & value(int x, int y)

Members detail
--------------

void adjugate(Matrix &result) const
...................................

replace matrix by the adjugate matrix

Matrix adjugate() const
.......................

Get the adjugate matrix

double determinant() const
..........................

compute matrix determinant

void inverse(Matrix &result) const
..................................

replace matrix by the inverse matrix

Matrix inverse() const
......................

Get the inverse matrix

Matrix operator*(double scale) const
....................................

Scale matrix

Matrix operator*(const Matrix &m) const
.......................................

Multiply matrix

vector<N> operator*(const vector<N> &v) const
.............................................

Multiply matrix with vector. See vector class for vector/matrix
multiplication.

Matrix operator+(const Matrix &m) const
.......................................

Add matrix

Matrix operator-(const Matrix &m) const
.......................................

Subtract matrix

Matrix operator/(double scale) const
....................................

Scale matrix

Matrix & set(double value = 0)
..............................

Set whole matrix to specified value.

Matrix & set_col(int col, double value)
.......................................

Set whole matrix column to specified value.

Matrix & set_col(int col, const vector<N> &v)
.............................................

Set matrix column to specified vector.

Matrix & set_diag(double value = 1)
...................................

Set matrix diagonal to specified value.

Matrix & set_diag(const vector<N> &v)
.....................................

Set matrix diagonal to specified value.

Matrix & set_id()
.................

Setup an identity matrix.

Matrix & set_row(int row, double value)
.......................................

Set whole matrix row to specified value.

Matrix & set_row(int row, const vector<N> &v)
.............................................

Set matrix row to specified vector.

void transpose(Matrix &result) const
....................................

replace matrix by the transposed matrix

Matrix transpose() const
........................

Get the transposed matrix

double value(int x, int y) const
................................

Get value at x row and y column

double & value(int x, int y)
............................

Get modifiable reference to value at x row and y column

math::Matrix struct full member list
====================================

Functions
---------

   * void adjugate(Matrix &result) const

   * Matrix adjugate() const

   * double determinant() const

   * void inverse(Matrix &result) const

   * Matrix inverse() const

   * Matrix operator*(double scale) const

   * Matrix operator*(const Matrix &m) const

   * vector<N> operator*(const vector<N> &v) const

   * Matrix operator+(const Matrix &m) const

   * Matrix operator-(const Matrix &m) const

   * Matrix operator/(double scale) const

   * Matrix & set(double value = _[...]_)

   * Matrix & set_col(int col, double value)

   * Matrix & set_col(int col, const vector<N> &v)

   * Matrix & set_diag(double value = _[...]_)

   * Matrix & set_diag(const vector<N> &v)

   * Matrix & set_id()

   * Matrix & set_row(int row, double value)

   * Matrix & set_row(int row, const vector<N> &v)

   * void transpose(Matrix &result) const

   * Matrix transpose() const

   * double value(int x, int y) const

   * double & value(int x, int y)

math::Quaternion class reference
================================

Declaration
-----------

     #include <goptical/core/math/Quaternion>

     namespace goptical {
       namespace math {
         class Quaternion;
       };
     };

   This class is a member of the math namespace.

Description
-----------

This class describe a quaternion object. Useful for 3d rotations.

Members
-------

See also the full member list (*note
math_Quaternion_class_full_member_list::) section for this class.

Functions
.........

   * Quaternion()

   * Quaternion(double x, double y, double z, double w)

   * Quaternion(const vector3 &a, const vector3 &b)

   * double norm() const

   * const Quaternion & normalize()

   * Quaternion operator*(const Quaternion &q) const

   * double w() const

   * double & w()

   * double x() const

   * double & x()

   * double y() const

   * double & y()

   * double z() const

   * double & z()

Static functions
................

   * static Quaternion angle(const vector3 &v, double angle)

   * static Quaternion angle_rad(const vector3 &v, double angle)

Members detail
--------------

Quaternion()
............

No documentation available

Quaternion(double x, double y, double z, double w)
..................................................

Create a Quaternion from its real values

Quaternion(const vector3 &a, const vector3 &b)
..............................................

Create a Quaternion as rotation between two unit vectors

static Quaternion angle(const vector3 &v, double angle)
.......................................................

Create a Quaternion with given rotation angle along a 3d vector

static Quaternion angle_rad(const vector3 &v, double angle)
...........................................................

Create a Quaternion with given rotation angle in radian along a 3d
vector

double norm() const
...................

Adjust vector length

const Quaternion & normalize()
..............................

Normalize vector length

Quaternion operator*(const Quaternion &q) const
...............................................

Multiply with an other quaternion

double w() const
................

Get quaterion w value

double & w()
............

Get reference to quaterion w value

double x() const
................

Get quaterion x value

double & x()
............

Get reference to quaterion x value

double y() const
................

Get quaterion y value

double & y()
............

Get reference to quaterion y value

double z() const
................

Get quaterion z value

double & z()
............

Get reference to quaterion z value

math::Quaternion class full member list
=======================================

Functions
---------

   * Quaternion()

   * Quaternion(double x, double y, double z, double w)

   * Quaternion(const vector3 &a, const vector3 &b)

   * double norm() const

   * const Quaternion & normalize()

   * Quaternion operator*(const Quaternion &q) const

   * double w() const

   * double & w()

   * double x() const

   * double & x()

   * double y() const

   * double & y()

   * double z() const

   * double & z()

Static functions
----------------

   * static Quaternion angle(const vector3 &v, double angle)

   * static Quaternion angle_rad(const vector3 &v, double angle)

math::Transform<3> class reference
==================================

Declaration
-----------

     #include <goptical/core/math/Transform>

     namespace goptical {
       namespace math {
         template <> class Transform<3>;
       };
     };

   This class is a member of the math namespace.

   This class is a specialization of Transform.

Description
-----------

This class describes linear and affine transformations in 3d space. It
contains a 3x3 transformation matrix and a 3d translation vector. It
can be used for translation and rotation in 3d.

   See also Transform3 (*note _657::) typedef.

Members
-------

See also the full member list (*note
math_Transform_3_class_full_member_list::) section for this class.

Functions
.........

   * Transform()

   * Transform(const TransformBase<3> &t)

   * Transform(const Quaternion &q, const vector3 &v)

   * TransformBase<3> & affine_rotation(unsigned int axis, double
     dangle)

   * Transform<3> & affine_rotation(const vector3 &rangles)

   * TransformBase<3> & affine_rotation_rad(unsigned int axis, double
     rangle)

   * Transform<3> & affine_rotation_rad(const vector3 &rangles)

   * TransformBase<3> & affine_scaling(const vector<N> &v)

   * TransformBase<3> & affine_scaling(double s)

   * TransformBase<3> & apply_translation(const vector<N> &v)

   * void compose(const TransformBase<N> &t)

   * const Matrix<N> & get_linear() const

   * Matrix<N> & get_linear()

   * const vector<N> & get_translation() const

   * vector<N> & get_translation()

   * TransformBase<3> inverse() const

   * void linear_reset()

   * TransformBase<3> & linear_rotation(unsigned int axis, double
     dangle)

   * Transform<3> & linear_rotation(const vector3 &dangles)

   * TransformBase<3> & linear_rotation_rad(unsigned int axis, double
     rangle)

   * Transform<3> & linear_rotation_rad(const vector3 &rangles)

   * TransformBase<3> & linear_scaling(const vector<N> &v)

   * TransformBase<3> & linear_scaling(double s)

   * void reset()

   * void set_direction(const vector3 &d)

   * void set_rotation(const Quaternion &q)

   * void set_translation(const vector<N> &v)

   * vector<N> transform(const vector<N> &v) const

   * vectorPair<N> transform_line(const vectorPair<N> &v) const

   * vector<N> transform_linear(const vector<N> &v) const

   * vectorPair<N> transform_pair(const vectorPair<N> &p) const

   * vector<N> transform_translate(const vector<N> &v) const

   * void translation_reset()

Members detail
--------------

Transform()
...........

No documentation available

Transform(const TransformBase<3> &t)
....................................

No documentation available

Transform(const Quaternion &q, const vector3 &v)
................................................

Create a transform from rotation quaternion and translation vector

Transform<3> & affine_rotation(const vector3 &rangles)
......................................................

apply rotation to current transform (degree)

Transform<3> & affine_rotation_rad(const vector3 &rangles)
..........................................................

apply rotation to current transform (radian)

Transform<3> & linear_rotation(const vector3 &dangles)
......................................................

apply rotation to current transform (degree) (does not transform
translation vector)

Transform<3> & linear_rotation_rad(const vector3 &rangles)
..........................................................

apply rotation to current transform (radian) (does not transform
translation vector)

void set_direction(const vector3 &d)
....................................

set rotation from given direction vector

void set_rotation(const Quaternion &q)
......................................

set rotation from given quaternion

math::Transform<3> class full member list
=========================================

Functions
---------

   * Transform()

   * Transform(const TransformBase<3> &t)

   * Transform(const Quaternion &q, const vector3 &v)

   * TransformBase<3> & affine_rotation(unsigned int axis, double
     dangle)

   * Transform<3> & affine_rotation(const vector3 &rangles)

   * TransformBase<3> & affine_rotation_rad(unsigned int axis, double
     rangle)

   * Transform<3> & affine_rotation_rad(const vector3 &rangles)

   * TransformBase<3> & affine_scaling(const vector<N> &v)

   * TransformBase<3> & affine_scaling(double s)

   * TransformBase<3> & apply_translation(const vector<N> &v)

   * void compose(const TransformBase<N> &t)

   * const Matrix<N> & get_linear() const

   * Matrix<N> & get_linear()

   * const vector<N> & get_translation() const

   * vector<N> & get_translation()

   * TransformBase<3> inverse() const

   * void linear_reset()

   * TransformBase<3> & linear_rotation(unsigned int axis, double
     dangle)

   * Transform<3> & linear_rotation(const vector3 &dangles)

   * TransformBase<3> & linear_rotation_rad(unsigned int axis, double
     rangle)

   * Transform<3> & linear_rotation_rad(const vector3 &rangles)

   * TransformBase<3> & linear_scaling(const vector<N> &v)

   * TransformBase<3> & linear_scaling(double s)

   * void reset()

   * void set_direction(const vector3 &d)

   * void set_rotation(const Quaternion &q)

   * void set_translation(const vector<N> &v)

   * vector<N> transform(const vector<N> &v) const

   * vectorPair<N> transform_line(const vectorPair<N> &v) const

   * vector<N> transform_linear(const vector<N> &v) const

   * vectorPair<N> transform_pair(const vectorPair<N> &p) const

   * vector<N> transform_translate(const vector<N> &v) const

   * void translation_reset()

math::Transform<2> class reference
==================================

Declaration
-----------

     #include <goptical/core/math/Transform>

     namespace goptical {
       namespace math {
         template <> class Transform<2>;
       };
     };

   This class is a member of the math namespace.

   This class is a specialization of Transform.

Description
-----------

This class describes linear and affine transformations in 2d space. It
contains a 2x2 transformation matrix and a 2d translation vector. It
can be used for translation and rotation in 2d.

   See also Transform2 (*note _656::) typedef.

Members
-------

See also the full member list (*note
math_Transform_2_class_full_member_list::) section for this class.

Functions
.........

   * Transform()

   * Transform(const TransformBase<2> &t)

   * TransformBase<2> & affine_rotation(unsigned int axis, double
     dangle)

   * TransformBase<2> & affine_rotation_rad(unsigned int axis, double
     rangle)

   * TransformBase<2> & affine_scaling(const vector<N> &v)

   * TransformBase<2> & affine_scaling(double s)

   * TransformBase<2> & apply_translation(const vector<N> &v)

   * void compose(const TransformBase<N> &t)

   * const Matrix<N> & get_linear() const

   * Matrix<N> & get_linear()

   * const vector<N> & get_translation() const

   * vector<N> & get_translation()

   * TransformBase<2> inverse() const

   * void linear_reset()

   * TransformBase<2> & linear_rotation(unsigned int axis, double
     dangle)

   * TransformBase<2> & linear_rotation_rad(unsigned int axis, double
     rangle)

   * TransformBase<2> & linear_scaling(const vector<N> &v)

   * TransformBase<2> & linear_scaling(double s)

   * void reset()

   * void set_translation(const vector<N> &v)

   * vector<N> transform(const vector<N> &v) const

   * vectorPair<N> transform_line(const vectorPair<N> &v) const

   * vector<N> transform_linear(const vector<N> &v) const

   * vectorPair<N> transform_pair(const vectorPair<N> &p) const

   * vector<N> transform_translate(const vector<N> &v) const

   * void translation_reset()

Members detail
--------------

Transform()
...........

No documentation available

Transform(const TransformBase<2> &t)
....................................

No documentation available

math::Transform<2> class full member list
=========================================

Functions
---------

   * Transform()

   * Transform(const TransformBase<2> &t)

   * TransformBase<2> & affine_rotation(unsigned int axis, double
     dangle)

   * TransformBase<2> & affine_rotation_rad(unsigned int axis, double
     rangle)

   * TransformBase<2> & affine_scaling(const vector<N> &v)

   * TransformBase<2> & affine_scaling(double s)

   * TransformBase<2> & apply_translation(const vector<N> &v)

   * void compose(const TransformBase<N> &t)

   * const Matrix<N> & get_linear() const

   * Matrix<N> & get_linear()

   * const vector<N> & get_translation() const

   * vector<N> & get_translation()

   * TransformBase<2> inverse() const

   * void linear_reset()

   * TransformBase<2> & linear_rotation(unsigned int axis, double
     dangle)

   * TransformBase<2> & linear_rotation_rad(unsigned int axis, double
     rangle)

   * TransformBase<2> & linear_scaling(const vector<N> &v)

   * TransformBase<2> & linear_scaling(double s)

   * void reset()

   * void set_translation(const vector<N> &v)

   * vector<N> transform(const vector<N> &v) const

   * vectorPair<N> transform_line(const vectorPair<N> &v) const

   * vector<N> transform_linear(const vector<N> &v) const

   * vectorPair<N> transform_pair(const vectorPair<N> &p) const

   * vector<N> transform_translate(const vector<N> &v) const

   * void translation_reset()

math::TransformBase<2> internal class members
=============================================

TransformBase()
---------------

No documentation available

TransformBase<2> & affine_rotation(unsigned int axis, double dangle)
--------------------------------------------------------------------

apply rotation to current transform (degree)

TransformBase<2> & affine_rotation_rad(unsigned int axis, double rangle)
------------------------------------------------------------------------

apply rotation to current transform (radian)

TransformBase<2> & affine_scaling(const vector<N> &v)
-----------------------------------------------------

apply scaling to current transform

TransformBase<2> & affine_scaling(double s)
-------------------------------------------

apply scaling to current transform

TransformBase<2> & apply_translation(const vector<N> &v)
--------------------------------------------------------

apply translation to current transform

void compose(const TransformBase<N> &t)
---------------------------------------

compose with t. new transform is equivalent to applying t then this
transform

const Matrix<N> & get_linear() const
------------------------------------

get linear transform matrix

Matrix<N> & get_linear()
------------------------

get linear transform matrix

const vector<N> & get_translation() const
-----------------------------------------

get translation vector

vector<N> & get_translation()
-----------------------------

get translation vector

TransformBase<2> inverse() const
--------------------------------

get inverse transformation

void linear_reset()
-------------------

reset linear transform to identity

TransformBase<2> & linear_rotation(unsigned int axis, double dangle)
--------------------------------------------------------------------

apply rotation to current transform (degree) (does not transform
translation vector)

TransformBase<2> & linear_rotation_rad(unsigned int axis, double rangle)
------------------------------------------------------------------------

apply rotation to current transform (radian) (does not transform
translation vector)

TransformBase<2> & linear_scaling(const vector<N> &v)
-----------------------------------------------------

apply linear scaling to current transform (does not transform
translation vector)

TransformBase<2> & linear_scaling(double s)
-------------------------------------------

apply scaling to current transform (does not transform translation
vector)

void reset()
------------

reset linear transform to identity and translation to zero

void set_translation(const vector<N> &v)
----------------------------------------

set current translation

vector<N> transform(const vector<N> &v) const
---------------------------------------------

apply affine transform (translation and linear) to vector

vectorPair<N> transform_line(const vectorPair<N> &v) const
----------------------------------------------------------

apply affine transform to line origin and linear to direction

vector<N> transform_linear(const vector<N> &v) const
----------------------------------------------------

apply linear transform to vector

vectorPair<N> transform_pair(const vectorPair<N> &p) const
----------------------------------------------------------

apply affine transform to both vectors in pair

vector<N> transform_translate(const vector<N> &v) const
-------------------------------------------------------

apply translation to vector

void translation_reset()
------------------------

reset translation to zero

virtual ~TransformBase()
------------------------

No documentation available

math::TransformBase<3> internal class members
=============================================

TransformBase()
---------------

No documentation available

TransformBase<3> & affine_rotation(unsigned int axis, double dangle)
--------------------------------------------------------------------

apply rotation to current transform (degree)

TransformBase<3> & affine_rotation_rad(unsigned int axis, double rangle)
------------------------------------------------------------------------

apply rotation to current transform (radian)

TransformBase<3> & affine_scaling(const vector<N> &v)
-----------------------------------------------------

apply scaling to current transform

TransformBase<3> & affine_scaling(double s)
-------------------------------------------

apply scaling to current transform

TransformBase<3> & apply_translation(const vector<N> &v)
--------------------------------------------------------

apply translation to current transform

void compose(const TransformBase<N> &t)
---------------------------------------

compose with t. new transform is equivalent to applying t then this
transform

const Matrix<N> & get_linear() const
------------------------------------

get linear transform matrix

Matrix<N> & get_linear()
------------------------

get linear transform matrix

const vector<N> & get_translation() const
-----------------------------------------

get translation vector

vector<N> & get_translation()
-----------------------------

get translation vector

TransformBase<3> inverse() const
--------------------------------

get inverse transformation

void linear_reset()
-------------------

reset linear transform to identity

TransformBase<3> & linear_rotation(unsigned int axis, double dangle)
--------------------------------------------------------------------

apply rotation to current transform (degree) (does not transform
translation vector)

TransformBase<3> & linear_rotation_rad(unsigned int axis, double rangle)
------------------------------------------------------------------------

apply rotation to current transform (radian) (does not transform
translation vector)

TransformBase<3> & linear_scaling(const vector<N> &v)
-----------------------------------------------------

apply linear scaling to current transform (does not transform
translation vector)

TransformBase<3> & linear_scaling(double s)
-------------------------------------------

apply scaling to current transform (does not transform translation
vector)

void reset()
------------

reset linear transform to identity and translation to zero

void set_translation(const vector<N> &v)
----------------------------------------

set current translation

vector<N> transform(const vector<N> &v) const
---------------------------------------------

apply affine transform (translation and linear) to vector

vectorPair<N> transform_line(const vectorPair<N> &v) const
----------------------------------------------------------

apply affine transform to line origin and linear to direction

vector<N> transform_linear(const vector<N> &v) const
----------------------------------------------------

apply linear transform to vector

vectorPair<N> transform_pair(const vectorPair<N> &p) const
----------------------------------------------------------

apply affine transform to both vectors in pair

vector<N> transform_translate(const vector<N> &v) const
-------------------------------------------------------

apply translation to vector

void translation_reset()
------------------------

reset translation to zero

virtual ~TransformBase()
------------------------

No documentation available

math::Triangle struct reference
===============================

Declaration
-----------

     #include <goptical/core/math/Triangle>

     namespace goptical {
       namespace math {
         template <int N> struct Triangle;
       };
     };

   This struct is a member of the math namespace.

Description
-----------

This class is the general purpose N dimensions triangles class.

Class specializations
---------------------

Name                   Description
-------------------------------------------------------------------------- 
Triangle<3>            3d triangle class

Members
-------

See also the full member list (*note
math_Triangle_struct_full_member_list::) section for this struct.

Type
....

   * typedef _ [...] _ put_delegate_t

Functions
.........

   * Triangle()

   * Triangle(const vector<N> &a, const vector<N> &b, const vector<N>
     &c)

   * vector<N> get_centroid() const

   * const vector<N> & operator[](int n) const

   * vector<N> & operator[](int n)

Members detail
--------------

Triangle()
..........

No documentation available

Triangle(const vector<N> &a, const vector<N> &b, const vector<N> &c)
....................................................................

Create a triangle from 3 points

typedef  delegate <void(const math::Triangle<N>&)> put_delegate_t
.................................................................

No documentation available

math::Triangle struct full member list
======================================

Type
----

   * typedef _ [...] _ put_delegate_t

Functions
---------

   * Triangle()

   * Triangle(const vector<N> &a, const vector<N> &b, const vector<N>
     &c)

   * vector<N> get_centroid() const

   * const vector<N> & operator[](int n) const

   * vector<N> & operator[](int n)

math::Triangle<3> struct reference
==================================

Declaration
-----------

     #include <goptical/core/math/Triangle>

     namespace goptical {
       namespace math {
         template <> struct Triangle<3>;
       };
     };

   This struct is a member of the math namespace.

   This struct is a specialization of Triangle (*note
math_Triangle_struct_reference::).

Description
-----------

This class is the 3d triangles class.

Members
-------

See also the full member list (*note
math_Triangle_3_struct_full_member_list::) section for this struct.

Type
....

   * typedef _ [...] _ put_delegate_t

Functions
.........

   * Triangle()

   * Triangle(const vector3 &a, const vector3 &b, const vector3 &c)

   * vector<N> get_centroid() const

   * vector3 normal() const

   * const vector<N> & operator[](int n) const

   * vector<N> & operator[](int n)

Members detail
--------------

Triangle()
..........

No documentation available

Triangle(const vector3 &a, const vector3 &b, const vector3 &c)
..............................................................

Create a triangle from 3 points

vector3 normal() const
......................

Get triangle normal

typedef  delegate <void(const math::Triangle<3>&)> put_delegate_t
.................................................................

No documentation available

math::Triangle<3> struct full member list
=========================================

Type
----

   * typedef _ [...] _ put_delegate_t

Functions
---------

   * Triangle()

   * Triangle(const vector3 &a, const vector3 &b, const vector3 &c)

   * vector<N> get_centroid() const

   * vector3 normal() const

   * const vector<N> & operator[](int n) const

   * vector<N> & operator[](int n)

math::Triangle<2> internal struct members
=========================================

Triangle()
----------

No documentation available

Triangle(const vector<N> &a, const vector<N> &b, const vector<N> &c)
--------------------------------------------------------------------

Create a triangle from 3 points

typedef  delegate <void(const math::Triangle<N>&)> put_delegate_t
-----------------------------------------------------------------

No documentation available

math::TriangleBase<N> internal struct members
=============================================

TriangleBase()
--------------

No documentation available

TriangleBase(const vector<N> &a, const vector<N> &b, const vector<N> &c)
------------------------------------------------------------------------

Create a triangle from 3 points

vector<N> get_centroid() const
------------------------------

Get triangle centroid

const vector<N> & operator[](int n) const
-----------------------------------------

Get point n of the triangle

vector<N> & operator[](int n)
-----------------------------

Get reference to point n of the triangle

math::TriangleBase<3> internal struct members
=============================================

TriangleBase()
--------------

No documentation available

TriangleBase(const vector<N> &a, const vector<N> &b, const vector<N> &c)
------------------------------------------------------------------------

Create a triangle from 3 points

vector<N> get_centroid() const
------------------------------

Get triangle centroid

const vector<N> & operator[](int n) const
-----------------------------------------

Get point n of the triangle

vector<N> & operator[](int n)
-----------------------------

Get reference to point n of the triangle

math::vector struct reference
=============================

Declaration
-----------

     #include <goptical/core/math/vector>

     namespace goptical {
       namespace math {
         template <int N, typename T = double> struct vector;
       };
     };

   This struct is a member of the math namespace.

Description
-----------

This class is the general purpose N dimensions vector class.

Class specializations
---------------------

Name                   Description
-------------------------------------------------------------------------- 
vector<3, T>           3d vector class
vector<2, T>           2d vector class

Members
-------

See also the full member list (*note
math_vector_struct_full_member_list::) section for this struct.

Functions
.........

   * vector()

   * vector(const vectorBase<N, T> &v)

   * vector(T v)

   * bool close_to(const vectorBase<N, T> &m, T error = _[...]_)

   * T len() const

   * vectorBase<N, T> magnitude(T newlen) const

   * vectorBase<N, T> mul(const vectorBase<N, T> &v) const

   * vectorBase<N, T> & neg()

   * const vectorBase<N, T> & normalize()

   * vectorBase<N, T> normalized() const

   * T operator*(const vectorBase<N, T> &v) const

   * vectorBase<N, T> operator*(T scale) const

   * vectorBase<N, T> operator*(const Matrix<N> &m)

   * const vectorBase<N, T> & operator*=(T scale)

   * vectorBase<N, T> operator+(const vectorBase<N, T> &v) const

   * const vectorBase<N, T> & operator+=(const vectorBase<N, T> &v)

   * vectorBase<N, T> operator-(const vectorBase<N, T> &v) const

   * vectorBase<N, T> operator-() const

   * const vectorBase<N, T> & operator-=(const vectorBase<N, T> &v)

   * vectorBase<N, T> operator/(T scale) const

   * vectorBase<N, T> operator/(const vectorBase<N, T> &v) const

   * const vectorBase<N, T> & operator/=(T scale)

   * bool operator==(const vectorBase<N, T> &m) const

   * T operator[](int n) const

   * T & operator[](int n)

   * template vectorBase<M, T> select(unsigned int bitmask, const
     vectorBase<M, T> &v) const

   * void set(T value)

Members detail
--------------

vector()
........

No documentation available

vector(const vectorBase<N, T> &v)
.................................

No documentation available

vector(T v)
...........

Create a 2d vector with same value for all components

math::vector struct full member list
====================================

Functions
---------

   * vector()

   * vector(const vectorBase<N, T> &v)

   * vector(T v)

   * bool close_to(const vectorBase<N, T> &m, T error = _[...]_)

   * T len() const

   * vectorBase<N, T> magnitude(T newlen) const

   * vectorBase<N, T> mul(const vectorBase<N, T> &v) const

   * vectorBase<N, T> & neg()

   * const vectorBase<N, T> & normalize()

   * vectorBase<N, T> normalized() const

   * T operator*(const vectorBase<N, T> &v) const

   * vectorBase<N, T> operator*(T scale) const

   * vectorBase<N, T> operator*(const Matrix<N> &m)

   * const vectorBase<N, T> & operator*=(T scale)

   * vectorBase<N, T> operator+(const vectorBase<N, T> &v) const

   * const vectorBase<N, T> & operator+=(const vectorBase<N, T> &v)

   * vectorBase<N, T> operator-(const vectorBase<N, T> &v) const

   * vectorBase<N, T> operator-() const

   * const vectorBase<N, T> & operator-=(const vectorBase<N, T> &v)

   * vectorBase<N, T> operator/(T scale) const

   * vectorBase<N, T> operator/(const vectorBase<N, T> &v) const

   * const vectorBase<N, T> & operator/=(T scale)

   * bool operator==(const vectorBase<N, T> &m) const

   * T operator[](int n) const

   * T & operator[](int n)

   * template vectorBase<M, T> select(unsigned int bitmask, const
     vectorBase<M, T> &v) const

   * void set(T value)

math::vector<3,T> struct reference
==================================

Declaration
-----------

     #include <goptical/core/math/vector>

     namespace goptical {
       namespace math {
         template <typename T> struct vector<3, T>;
       };
     };

   This struct is a member of the math namespace.

   This template struct is a specialization of vector (*note
math_vector_struct_reference::).

Description
-----------

This class implements 3d vectors.

   The math (*note math_namespace_reference::) namespace contains some
commonly used constant vector objects.

Members
-------

See also the full member list (*note
math_vector_3_T_struct_full_member_list::) section for this struct.

Types
.....

   * typedef _ [...] _ base

   * typedef _ [...] _ put_delegate_t

Functions
.........

   * vector()

   * vector(const vectorBase<3, T> &v)

   * template vector(const vectorBase<M, T> &v, T p)

   * vector(T v)

   * vector(T x, T y, T z)

   * bool close_to(const vectorBase<3, T> &m, T error = _[...]_)

   * vector cross_product(const vector<3, T> &v) const

   * T len() const

   * vectorBase<3, T> magnitude(T newlen) const

   * vectorBase<3, T> mul(const vectorBase<3, T> &v) const

   * vectorBase<3, T> & neg()

   * const vectorBase<3, T> & normalize()

   * vectorBase<3, T> normalized() const

   * T operator*(const vectorBase<3, T> &v) const

   * vectorBase<3, T> operator*(T scale) const

   * vectorBase<3, T> operator*(const Matrix<N> &m)

   * const vectorBase<3, T> & operator*=(T scale)

   * vectorBase<3, T> operator+(const vectorBase<3, T> &v) const

   * const vectorBase<3, T> & operator+=(const vectorBase<3, T> &v)

   * vectorBase<3, T> operator-(const vectorBase<3, T> &v) const

   * vectorBase<3, T> operator-() const

   * const vectorBase<3, T> & operator-=(const vectorBase<3, T> &v)

   * vectorBase<3, T> operator/(T scale) const

   * vectorBase<3, T> operator/(const vectorBase<3, T> &v) const

   * const vectorBase<3, T> & operator/=(T scale)

   * bool operator==(const vectorBase<3, T> &m) const

   * T operator[](int n) const

   * T & operator[](int n)

   * vector<2, T> project_xy() const

   * vector<2, T> project_zy() const

   * template vectorBase<M, T> select(unsigned int bitmask, const
     vectorBase<M, T> &v) const

   * void set(T value)

   * T & x()

   * T x() const

   * T & y()

   * T y() const

   * T & z()

   * T z() const

Members detail
--------------

vector()
........

No documentation available

vector(const vectorBase<3, T> &v)
.................................

Copy constructor

template <int M> vector(const vectorBase<M, T> &v, T p)
.......................................................

Create a 3d vector from 2d vector and given z value.

vector(T v)
...........

Create a 2d vector with same value for all components

vector(T x, T y, T z)
.....................

Create a 3d vector from x, y and z values

typedef vectorBase<3, T> base
.............................

No documentation available

vector cross_product(const vector<3, T> &v) const
.................................................

Compute vectors cross product

vector<2, T> project_xy() const
...............................

Get a 2d vector formed x and y values.

vector<2, T> project_zy() const
...............................

Get a 2d vector formed z and y values.

typedef  delegate <void(const vector<3,T>&)> put_delegate_t
...........................................................

No documentation available

T & x()
.......

Get reference to vector x value

T x() const
...........

Get vector x value

T & y()
.......

Get reference to vector y value

T y() const
...........

Get vector y value

T & z()
.......

Get reference to vector z value

T z() const
...........

Get vector z value

math::vector<3,T> struct full member list
=========================================

Types
-----

   * typedef _ [...] _ base

   * typedef _ [...] _ put_delegate_t

Functions
---------

   * vector()

   * vector(const vectorBase<3, T> &v)

   * template vector(const vectorBase<M, T> &v, T p)

   * vector(T v)

   * vector(T x, T y, T z)

   * bool close_to(const vectorBase<3, T> &m, T error = _[...]_)

   * vector cross_product(const vector<3, T> &v) const

   * T len() const

   * vectorBase<3, T> magnitude(T newlen) const

   * vectorBase<3, T> mul(const vectorBase<3, T> &v) const

   * vectorBase<3, T> & neg()

   * const vectorBase<3, T> & normalize()

   * vectorBase<3, T> normalized() const

   * T operator*(const vectorBase<3, T> &v) const

   * vectorBase<3, T> operator*(T scale) const

   * vectorBase<3, T> operator*(const Matrix<N> &m)

   * const vectorBase<3, T> & operator*=(T scale)

   * vectorBase<3, T> operator+(const vectorBase<3, T> &v) const

   * const vectorBase<3, T> & operator+=(const vectorBase<3, T> &v)

   * vectorBase<3, T> operator-(const vectorBase<3, T> &v) const

   * vectorBase<3, T> operator-() const

   * const vectorBase<3, T> & operator-=(const vectorBase<3, T> &v)

   * vectorBase<3, T> operator/(T scale) const

   * vectorBase<3, T> operator/(const vectorBase<3, T> &v) const

   * const vectorBase<3, T> & operator/=(T scale)

   * bool operator==(const vectorBase<3, T> &m) const

   * T operator[](int n) const

   * T & operator[](int n)

   * vector<2, T> project_xy() const

   * vector<2, T> project_zy() const

   * template vectorBase<M, T> select(unsigned int bitmask, const
     vectorBase<M, T> &v) const

   * void set(T value)

   * T & x()

   * T x() const

   * T & y()

   * T y() const

   * T & z()

   * T z() const

math::vector<2,T> struct reference
==================================

Declaration
-----------

     #include <goptical/core/math/vector>

     namespace goptical {
       namespace math {
         template <typename T> struct vector<2, T>;
       };
     };

   This struct is a member of the math namespace.

   This template struct is a specialization of vector (*note
math_vector_struct_reference::).

Description
-----------

This class implements 2d vectors.

   The math (*note math_namespace_reference::) namespace contains some
commonly used constant vector objects.

Members
-------

See also the full member list (*note
math_vector_2_T_struct_full_member_list::) section for this struct.

Types
.....

   * typedef _ [...] _ base

   * typedef _ [...] _ put_delegate_t

Functions
.........

   * vector()

   * vector(const vectorBase<2, T> &v)

   * template vector(const vectorBase<M, T> &v, T p)

   * vector(T v)

   * vector(T x, T y)

   * template vector(const vectorBase<N, T> &v, unsigned int c0,
     unsigned int c1)

   * bool close_to(const vectorBase<2, T> &m, T error = _[...]_)

   * T cross_product(const vector<2, T> &v) const

   * T len() const

   * vectorBase<2, T> magnitude(T newlen) const

   * vectorBase<2, T> mul(const vectorBase<2, T> &v) const

   * vectorBase<2, T> & neg()

   * const vectorBase<2, T> & normalize()

   * vectorBase<2, T> normalized() const

   * T operator*(const vectorBase<2, T> &v) const

   * vectorBase<2, T> operator*(T scale) const

   * vectorBase<2, T> operator*(const Matrix<N> &m)

   * const vectorBase<2, T> & operator*=(T scale)

   * vectorBase<2, T> operator+(const vectorBase<2, T> &v) const

   * const vectorBase<2, T> & operator+=(const vectorBase<2, T> &v)

   * vectorBase<2, T> operator-(const vectorBase<2, T> &v) const

   * vectorBase<2, T> operator-() const

   * const vectorBase<2, T> & operator-=(const vectorBase<2, T> &v)

   * vectorBase<2, T> operator/(T scale) const

   * vectorBase<2, T> operator/(const vectorBase<2, T> &v) const

   * const vectorBase<2, T> & operator/=(T scale)

   * bool operator==(const vectorBase<2, T> &m) const

   * T operator[](int n) const

   * T & operator[](int n)

   * template vectorBase<M, T> select(unsigned int bitmask, const
     vectorBase<M, T> &v) const

   * void set(T value)

   * T & x()

   * T x() const

   * T & y()

   * T y() const

Members detail
--------------

vector()
........

No documentation available

vector(const vectorBase<2, T> &v)
.................................

No documentation available

template <int M> vector(const vectorBase<M, T> &v, T p)
.......................................................

No documentation available

vector(T v)
...........

Create a 2d vector with same value for all components

vector(T x, T y)
................

Create a 2d vector from x and y z values

template <int N> vector(const vectorBase<N, T> &v, unsigned int c0, unsigned int c1)
....................................................................................

Create a 2d vector and initialize from specified components of an other
vector

typedef vectorBase<2, T> base
.............................

No documentation available

T cross_product(const vector<2, T> &v) const
............................................

No documentation available

typedef  delegate <void(const math::vector2&)> put_delegate_t
.............................................................

No documentation available

T & x()
.......

Get reference to vector x value

T x() const
...........

Get vector x value

T & y()
.......

Get reference to vector y value

T y() const
...........

Get vector y value

math::vector<2,T> struct full member list
=========================================

Types
-----

   * typedef _ [...] _ base

   * typedef _ [...] _ put_delegate_t

Functions
---------

   * vector()

   * vector(const vectorBase<2, T> &v)

   * template vector(const vectorBase<M, T> &v, T p)

   * vector(T v)

   * vector(T x, T y)

   * template vector(const vectorBase<N, T> &v, unsigned int c0,
     unsigned int c1)

   * bool close_to(const vectorBase<2, T> &m, T error = _[...]_)

   * T cross_product(const vector<2, T> &v) const

   * T len() const

   * vectorBase<2, T> magnitude(T newlen) const

   * vectorBase<2, T> mul(const vectorBase<2, T> &v) const

   * vectorBase<2, T> & neg()

   * const vectorBase<2, T> & normalize()

   * vectorBase<2, T> normalized() const

   * T operator*(const vectorBase<2, T> &v) const

   * vectorBase<2, T> operator*(T scale) const

   * vectorBase<2, T> operator*(const Matrix<N> &m)

   * const vectorBase<2, T> & operator*=(T scale)

   * vectorBase<2, T> operator+(const vectorBase<2, T> &v) const

   * const vectorBase<2, T> & operator+=(const vectorBase<2, T> &v)

   * vectorBase<2, T> operator-(const vectorBase<2, T> &v) const

   * vectorBase<2, T> operator-() const

   * const vectorBase<2, T> & operator-=(const vectorBase<2, T> &v)

   * vectorBase<2, T> operator/(T scale) const

   * vectorBase<2, T> operator/(const vectorBase<2, T> &v) const

   * const vectorBase<2, T> & operator/=(T scale)

   * bool operator==(const vectorBase<2, T> &m) const

   * T operator[](int n) const

   * T & operator[](int n)

   * template vectorBase<M, T> select(unsigned int bitmask, const
     vectorBase<M, T> &v) const

   * void set(T value)

   * T & x()

   * T x() const

   * T & y()

   * T y() const

math::vectorBase<N,math::vector::T> internal struct members
===========================================================

bool close_to(const vectorBase<N, T> &m, T error = 1 e-8)
---------------------------------------------------------

compare two almost equal vectors

T len() const
-------------

Compute vector length

vectorBase<N, T> magnitude(T newlen) const
------------------------------------------

Adjust vector length

vectorBase<N, T> mul(const vectorBase<N, T> &v) const
-----------------------------------------------------

vector values multiply

vectorBase<N, T> & neg()
------------------------

Negate vector

const vectorBase<N, T> & normalize()
------------------------------------

Normalize vector length

   See also normalized (*note _1036::) function.

vectorBase<N, T> normalized() const
-----------------------------------

Get normalized vector

   See also normalize (*note _1035::) function.

T operator*(const vectorBase<N, T> &v) const
--------------------------------------------

vector dot product

vectorBase<N, T> operator*(T scale) const
-----------------------------------------

Scale vector

vectorBase<N, T> operator*(const Matrix<N> &m)
----------------------------------------------

Multiply vector with matrix. See vector class for matrix/vector
multiplication.

const vectorBase<N, T> & operator*=(T scale)
--------------------------------------------

Multiply by a vector

vectorBase<N, T> operator+(const vectorBase<N, T> &v) const
-----------------------------------------------------------

Add two vectors

const vectorBase<N, T> & operator+=(const vectorBase<N, T> &v)
--------------------------------------------------------------

Add a vector

vectorBase<N, T> operator-(const vectorBase<N, T> &v) const
-----------------------------------------------------------

Subtract two vectors

vectorBase<N, T> operator-() const
----------------------------------

Get negated vector

const vectorBase<N, T> & operator-=(const vectorBase<N, T> &v)
--------------------------------------------------------------

Sutract a vector

vectorBase<N, T> operator/(T scale) const
-----------------------------------------

Scale vector

vectorBase<N, T> operator/(const vectorBase<N, T> &v) const
-----------------------------------------------------------

vector division

const vectorBase<N, T> & operator/=(T scale)
--------------------------------------------

Divide by a vector

bool operator==(const vectorBase<N, T> &m) const
------------------------------------------------

compare two vectors for equality

T operator[](int n) const
-------------------------

Get value at specified index

T & operator[](int n)
---------------------

Get reference to value at specified index

template <int M> vectorBase<M, T> select(unsigned int bitmask, const vectorBase<M, T> &v) const
-----------------------------------------------------------------------------------------------

Select components from two vectors. Components which have their
corresponding bit set in the mask are extracted from this vector and
other components are taken from passed vector.

void set(T value)
-----------------

Set the whole vector to the specified value

math::vectorBase<2,math::vector<2,T>::T> internal struct members
================================================================

bool close_to(const vectorBase<2, T> &m, T error = 1 e-8)
---------------------------------------------------------

compare two almost equal vectors

T len() const
-------------

Compute vector length

vectorBase<2, T> magnitude(T newlen) const
------------------------------------------

Adjust vector length

vectorBase<2, T> mul(const vectorBase<2, T> &v) const
-----------------------------------------------------

vector values multiply

vectorBase<2, T> & neg()
------------------------

Negate vector

const vectorBase<2, T> & normalize()
------------------------------------

Normalize vector length

   See also normalized (*note _1036::) function.

vectorBase<2, T> normalized() const
-----------------------------------

Get normalized vector

   See also normalize (*note _1035::) function.

T operator*(const vectorBase<2, T> &v) const
--------------------------------------------

vector dot product

vectorBase<2, T> operator*(T scale) const
-----------------------------------------

Scale vector

vectorBase<2, T> operator*(const Matrix<N> &m)
----------------------------------------------

Multiply vector with matrix. See vector class for matrix/vector
multiplication.

const vectorBase<2, T> & operator*=(T scale)
--------------------------------------------

Multiply by a vector

vectorBase<2, T> operator+(const vectorBase<2, T> &v) const
-----------------------------------------------------------

Add two vectors

const vectorBase<2, T> & operator+=(const vectorBase<2, T> &v)
--------------------------------------------------------------

Add a vector

vectorBase<2, T> operator-(const vectorBase<2, T> &v) const
-----------------------------------------------------------

Subtract two vectors

vectorBase<2, T> operator-() const
----------------------------------

Get negated vector

const vectorBase<2, T> & operator-=(const vectorBase<2, T> &v)
--------------------------------------------------------------

Sutract a vector

vectorBase<2, T> operator/(T scale) const
-----------------------------------------

Scale vector

vectorBase<2, T> operator/(const vectorBase<2, T> &v) const
-----------------------------------------------------------

vector division

const vectorBase<2, T> & operator/=(T scale)
--------------------------------------------

Divide by a vector

bool operator==(const vectorBase<2, T> &m) const
------------------------------------------------

compare two vectors for equality

T operator[](int n) const
-------------------------

Get value at specified index

T & operator[](int n)
---------------------

Get reference to value at specified index

template <int M> vectorBase<M, T> select(unsigned int bitmask, const vectorBase<M, T> &v) const
-----------------------------------------------------------------------------------------------

Select components from two vectors. Components which have their
corresponding bit set in the mask are extracted from this vector and
other components are taken from passed vector.

void set(T value)
-----------------

Set the whole vector to the specified value

math::vectorBase<3,math::vector<3,T>::T> internal struct members
================================================================

bool close_to(const vectorBase<3, T> &m, T error = 1 e-8)
---------------------------------------------------------

compare two almost equal vectors

T len() const
-------------

Compute vector length

vectorBase<3, T> magnitude(T newlen) const
------------------------------------------

Adjust vector length

vectorBase<3, T> mul(const vectorBase<3, T> &v) const
-----------------------------------------------------

vector values multiply

vectorBase<3, T> & neg()
------------------------

Negate vector

const vectorBase<3, T> & normalize()
------------------------------------

Normalize vector length

   See also normalized (*note _1036::) function.

vectorBase<3, T> normalized() const
-----------------------------------

Get normalized vector

   See also normalize (*note _1035::) function.

T operator*(const vectorBase<3, T> &v) const
--------------------------------------------

vector dot product

vectorBase<3, T> operator*(T scale) const
-----------------------------------------

Scale vector

vectorBase<3, T> operator*(const Matrix<N> &m)
----------------------------------------------

Multiply vector with matrix. See vector class for matrix/vector
multiplication.

const vectorBase<3, T> & operator*=(T scale)
--------------------------------------------

Multiply by a vector

vectorBase<3, T> operator+(const vectorBase<3, T> &v) const
-----------------------------------------------------------

Add two vectors

const vectorBase<3, T> & operator+=(const vectorBase<3, T> &v)
--------------------------------------------------------------

Add a vector

vectorBase<3, T> operator-(const vectorBase<3, T> &v) const
-----------------------------------------------------------

Subtract two vectors

vectorBase<3, T> operator-() const
----------------------------------

Get negated vector

const vectorBase<3, T> & operator-=(const vectorBase<3, T> &v)
--------------------------------------------------------------

Sutract a vector

vectorBase<3, T> operator/(T scale) const
-----------------------------------------

Scale vector

vectorBase<3, T> operator/(const vectorBase<3, T> &v) const
-----------------------------------------------------------

vector division

const vectorBase<3, T> & operator/=(T scale)
--------------------------------------------

Divide by a vector

bool operator==(const vectorBase<3, T> &m) const
------------------------------------------------

compare two vectors for equality

T operator[](int n) const
-------------------------

Get value at specified index

T & operator[](int n)
---------------------

Get reference to value at specified index

template <int M> vectorBase<M, T> select(unsigned int bitmask, const vectorBase<M, T> &v) const
-----------------------------------------------------------------------------------------------

Select components from two vectors. Components which have their
corresponding bit set in the mask are extracted from this vector and
other components are taken from passed vector.

void set(T value)
-----------------

Set the whole vector to the specified value

math::vectorPair struct reference
=================================

Declaration
-----------

     #include <goptical/core/math/vectorPair>

     namespace goptical {
       namespace math {
         template <int N> struct vectorPair;
       };
     };

   This struct is a member of the math namespace.

Description
-----------

This class hold two N dimensions vectors.

Class specializations
---------------------

Name                   Description
-------------------------------------------------------------------------- 
vectorPair<2>          vector pair class
vectorPair<3>          vector pair class

Members
-------

See also the full member list (*note
math_vectorPair_struct_full_member_list::) section for this struct.

Functions
.........

   * vectorPair()

   * vectorPair(const vectorPairBase<N> &vp)

   * vectorPair(const vector<N> &a, const vector<N> &b)

   * vector<N> & direction()

   * const vector<N> & direction() const

   * vector<N> ln_pt_clst_pt(const vector<N> &point) const

   * double ln_pt_clst_pt_scale(const vector<N> &point) const

   * vector<N> & normal()

   * const vector<N> & normal() const

   * vectorPairBase<N> operator*(double factor)

   * const vectorPairBase<N> & operator+=(const vectorPairBase<N> &p)

   * const vector<N> & operator[](int n) const

   * vector<N> & operator[](int n)

   * vector<N> & origin()

   * const vector<N> & origin() const

   * vector<N> seg_pt_clst_pt(const vector<N> &point) const

   * double seg_pt_clst_pt_scale(const vector<N> &point) const

Members detail
--------------

vectorPair()
............

No documentation available

vectorPair(const vectorPairBase<N> &vp)
.......................................

No documentation available

vectorPair(const vector<N> &a, const vector<N> &b)
..................................................

No documentation available

math::vectorPair struct full member list
========================================

Functions
---------

   * vectorPair()

   * vectorPair(const vectorPairBase<N> &vp)

   * vectorPair(const vector<N> &a, const vector<N> &b)

   * vector<N> & direction()

   * const vector<N> & direction() const

   * vector<N> ln_pt_clst_pt(const vector<N> &point) const

   * double ln_pt_clst_pt_scale(const vector<N> &point) const

   * vector<N> & normal()

   * const vector<N> & normal() const

   * vectorPairBase<N> operator*(double factor)

   * const vectorPairBase<N> & operator+=(const vectorPairBase<N> &p)

   * const vector<N> & operator[](int n) const

   * vector<N> & operator[](int n)

   * vector<N> & origin()

   * const vector<N> & origin() const

   * vector<N> seg_pt_clst_pt(const vector<N> &point) const

   * double seg_pt_clst_pt_scale(const vector<N> &point) const

math::vectorPair<2> struct reference
====================================

Declaration
-----------

     #include <goptical/core/math/vectorPair>

     namespace goptical {
       namespace math {
         template <> struct vectorPair<2>;
       };
     };

   This struct is a member of the math namespace.

   This struct is a specialization of vectorPair (*note
math_vectorPair_struct_reference::).

Description
-----------

This class hold two 2d vectors.

   See also vectorPair2 (*note _658::) typedef.

Members
-------

See also the full member list (*note
math_vectorPair_2_struct_full_member_list::) section for this struct.

Functions
.........

   * vectorPair()

   * vectorPair(const vectorPairBase<2> &vp)

   * vectorPair(const vector<2> &a, const vector<2> &b)

   * vectorPair(double ax, double ay, double bx, double by)

   * template vectorPair(const vectorPairBase<N> &v, unsigned int c0,
     unsigned int c1)

   * vector<N> & direction()

   * const vector<N> & direction() const

   * vector<2> ln_intersect_ln(const vectorPair<2> &line) const

   * double ln_intersect_ln_scale(const vectorPair<2> &line) const

   * vector<N> ln_pt_clst_pt(const vector<N> &point) const

   * double ln_pt_clst_pt_scale(const vector<N> &point) const

   * vector<N> & normal()

   * const vector<N> & normal() const

   * vectorPairBase<2> operator*(double factor)

   * const vectorPairBase<2> & operator+=(const vectorPairBase<2> &p)

   * const vector<N> & operator[](int n) const

   * vector<N> & operator[](int n)

   * vector<N> & origin()

   * const vector<N> & origin() const

   * template vector<2> seg_intersect_seg(const vectorPair<2> &segment)
     const

   * vector<N> seg_pt_clst_pt(const vector<N> &point) const

   * double seg_pt_clst_pt_scale(const vector<N> &point) const

   * double x0() const

   * double & x0()

   * double x1() const

   * double & x1()

   * double y0() const

   * double & y0()

   * double y1() const

   * double & y1()

Members detail
--------------

vectorPair()
............

No documentation available

vectorPair(const vectorPairBase<2> &vp)
.......................................

No documentation available

vectorPair(const vector<2> &a, const vector<2> &b)
..................................................

No documentation available

vectorPair(double ax, double ay, double bx, double by)
......................................................

No documentation available

template <int N> vectorPair(const vectorPairBase<N> &v, unsigned int c0, unsigned int c1)
.........................................................................................

Create a 2d vector pair and initialize vectors from specified
components of vectors from an other pair.

vector<2> ln_intersect_ln(const vectorPair<2> &line) const
..........................................................

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
line with origin and direction vectors and find the intersection point
with an other line.

   The return value is position of the intersection point. this
function throws if lines are almost parallel.

   See also ln_intersect_ln_scale (*note _921::) function.

double ln_intersect_ln_scale(const vectorPair<2> &line) const
.............................................................

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
line with origin and direction vectors and find the intersection point
with an other line.

   The return value is scale factor of the direction vector from line
origin. this function throws if lines are almost parallel.

   See also ln_intersect_ln (*note _920::) function.

template <bool infinite_1st, bool infinite_2nd> vector<2> seg_intersect_seg(const vectorPair<2> &segment) const
...............................................................................................................

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
segment with two point vectors and find the intersection point with an
other segment.

   The return value is position of the intersection point.

   The `infinite_1st' and `infinite_2nd' template parameters can be
used to disable point-in-segment tests for each segments. this template
function throws if lines are almost parallel or if intersection point
lies outside segment and associated test is enabled.

double x0() const
.................

Get vector pair component

double & x0()
.............

Get vector pair component

double x1() const
.................

Get vector pair component

double & x1()
.............

Get vector pair component

double y0() const
.................

Get vector pair component

double & y0()
.............

Get vector pair component

double y1() const
.................

Get vector pair component

double & y1()
.............

Get vector pair component

math::vectorPair<2> struct full member list
===========================================

Functions
---------

   * vectorPair()

   * vectorPair(const vectorPairBase<2> &vp)

   * vectorPair(const vector<2> &a, const vector<2> &b)

   * vectorPair(double ax, double ay, double bx, double by)

   * template vectorPair(const vectorPairBase<N> &v, unsigned int c0,
     unsigned int c1)

   * vector<N> & direction()

   * const vector<N> & direction() const

   * vector<2> ln_intersect_ln(const vectorPair<2> &line) const

   * double ln_intersect_ln_scale(const vectorPair<2> &line) const

   * vector<N> ln_pt_clst_pt(const vector<N> &point) const

   * double ln_pt_clst_pt_scale(const vector<N> &point) const

   * vector<N> & normal()

   * const vector<N> & normal() const

   * vectorPairBase<2> operator*(double factor)

   * const vectorPairBase<2> & operator+=(const vectorPairBase<2> &p)

   * const vector<N> & operator[](int n) const

   * vector<N> & operator[](int n)

   * vector<N> & origin()

   * const vector<N> & origin() const

   * template vector<2> seg_intersect_seg(const vectorPair<2> &segment)
     const

   * vector<N> seg_pt_clst_pt(const vector<N> &point) const

   * double seg_pt_clst_pt_scale(const vector<N> &point) const

   * double x0() const

   * double & x0()

   * double x1() const

   * double & x1()

   * double y0() const

   * double & y0()

   * double y1() const

   * double & y1()

math::vectorPair<3> struct reference
====================================

Declaration
-----------

     #include <goptical/core/math/vectorPair>

     namespace goptical {
       namespace math {
         template <> struct vectorPair<3>;
       };
     };

   This struct is a member of the math namespace.

   This struct is a specialization of vectorPair (*note
math_vectorPair_struct_reference::).

Inheritance
-----------

Description
-----------

This class hold two 3d vectors.

   See also vectorPair3 (*note _654::) typedef.

Members
-------

See also the full member list (*note
math_vectorPair_3_struct_full_member_list::) section for this struct.

Functions
.........

   * vectorPair()

   * vectorPair(const vectorPairBase<3> &vp)

   * vectorPair(const vector<3> &a, const vector<3> &b = _[...]_)

   * vectorPair(double ax, double ay, double az, double bx = _[...]_,
     double by = _[...]_, double bz = _[...]_)

   * vector<N> & direction()

   * const vector<N> & direction() const

   * vector<3> ln_ln_clst_pt(const vectorPair<3> &line) const

   * double ln_ln_clst_pt_scale(const vectorPair<3> &line) const

   * vector<N> ln_pt_clst_pt(const vector<N> &point) const

   * double ln_pt_clst_pt_scale(const vector<N> &point) const

   * vector<N> & normal()

   * const vector<N> & normal() const

   * vectorPairBase<3> operator*(double factor)

   * const vectorPairBase<3> & operator+=(const vectorPairBase<3> &p)

   * const vector<N> & operator[](int n) const

   * vector<N> & operator[](int n)

   * vector<N> & origin()

   * const vector<N> & origin() const

   * vector<3> pl_ln_intersect(const vectorPair<3> &line) const

   * double pl_ln_intersect_scale(const vectorPair<3> &line) const

   * vector<N> seg_pt_clst_pt(const vector<N> &point) const

   * double seg_pt_clst_pt_scale(const vector<N> &point) const

   * double x0() const

   * double & x0()

   * double x1() const

   * double & x1()

   * double y0() const

   * double & y0()

   * double y1() const

   * double & y1()

   * double z0() const

   * double & z0()

   * double z1() const

   * double & z1()

Members detail
--------------

vectorPair()
............

No documentation available

vectorPair(const vectorPairBase<3> &vp)
.......................................

No documentation available

vectorPair(const vector<3> &a, const vector<3> &b = vector3_001)
................................................................

No documentation available

vectorPair(double ax, double ay, double az, double bx = 0.0, double by = 0.0, double bz = 1.0)
..............................................................................................

No documentation available

vector<3> ln_ln_clst_pt(const vectorPair<3> &line) const
........................................................

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
line with origin and direction vectors and find the closest point on
this line to an other line.

   The return value is position of the closest point on the line. this
function throws if lines are almost parallel.

   See also ln_ln_clst_pt_scale (*note _936::) function.

double ln_ln_clst_pt_scale(const vectorPair<3> &line) const
...........................................................

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
line with origin and direction vectors and find the closest point on
this line to an other line.

   The return value is scale factor of the direction vector from
origin. this function throws if lines are almost parallel.

   See also ln_ln_clst_pt (*note _935::) function.

vector<3> pl_ln_intersect(const vectorPair<3> &line) const
..........................................................

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
plane and find intersection point with a line. Plane is defined by
origin and normal vectors and line is defined by origin and direction
vectors.

   The return value is position of the intersection point on the line.

   See also pl_ln_intersect_scale (*note _938::) function.

double pl_ln_intersect_scale(const vectorPair<3> &line) const
.............................................................

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
plane and find intersection point with a line. Plane is defined by
origin and normal vectors and line is defined by origin and direction
vectors.

   The return value is scale factor of the line direction vector from
line origin.

   See also pl_ln_intersect (*note _937::) function.

double x0() const
.................

Get vector pair component

double & x0()
.............

Get vector pair component

double x1() const
.................

Get vector pair component

double & x1()
.............

Get vector pair component

double y0() const
.................

Get vector pair component

double & y0()
.............

Get vector pair component

double y1() const
.................

Get vector pair component

double & y1()
.............

Get vector pair component

double z0() const
.................

Get vector pair component

double & z0()
.............

Get vector pair component

double z1() const
.................

Get vector pair component

double & z1()
.............

Get vector pair component

math::vectorPair<3> struct full member list
===========================================

Functions
---------

   * vectorPair()

   * vectorPair(const vectorPairBase<3> &vp)

   * vectorPair(const vector<3> &a, const vector<3> &b = _[...]_)

   * vectorPair(double ax, double ay, double az, double bx = _[...]_,
     double by = _[...]_, double bz = _[...]_)

   * vector<N> & direction()

   * const vector<N> & direction() const

   * vector<3> ln_ln_clst_pt(const vectorPair<3> &line) const

   * double ln_ln_clst_pt_scale(const vectorPair<3> &line) const

   * vector<N> ln_pt_clst_pt(const vector<N> &point) const

   * double ln_pt_clst_pt_scale(const vector<N> &point) const

   * vector<N> & normal()

   * const vector<N> & normal() const

   * vectorPairBase<3> operator*(double factor)

   * const vectorPairBase<3> & operator+=(const vectorPairBase<3> &p)

   * const vector<N> & operator[](int n) const

   * vector<N> & operator[](int n)

   * vector<N> & origin()

   * const vector<N> & origin() const

   * vector<3> pl_ln_intersect(const vectorPair<3> &line) const

   * double pl_ln_intersect_scale(const vectorPair<3> &line) const

   * vector<N> seg_pt_clst_pt(const vector<N> &point) const

   * double seg_pt_clst_pt_scale(const vector<N> &point) const

   * double x0() const

   * double & x0()

   * double x1() const

   * double & x1()

   * double y0() const

   * double & y0()

   * double y1() const

   * double & y1()

   * double z0() const

   * double & z0()

   * double z1() const

   * double & z1()

math::vectorPairBase<N> internal struct members
===============================================

vectorPairBase()
----------------

No documentation available

vectorPairBase(const vector<N> &a, const vector<N> &b)
------------------------------------------------------

No documentation available

vector<N> & direction()
-----------------------

Get reference to second vector

const vector<N> & direction() const
-----------------------------------

Get reference to second vector

vector<N> ln_pt_clst_pt(const vector<N> &point) const
-----------------------------------------------------

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
line with origin and direction vectors and find the closest point on
this line to a point.

   The return value is position of the closest point on the line.

   See also ln_pt_clst_pt_scale (*note _1059::) function.

double ln_pt_clst_pt_scale(const vector<N> &point) const
--------------------------------------------------------

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
line with origin and direction vectors and find the closest point on
this line to an other line.

   The return value is scale factor of the direction vector from origin.

   See also ln_pt_clst_pt (*note _1058::) function.

vector<N> & normal()
--------------------

Get reference to second vector

const vector<N> & normal() const
--------------------------------

Get reference to second vector

vectorPairBase<N> operator*(double factor)
------------------------------------------

No documentation available

const vectorPairBase<N> & operator+=(const vectorPairBase<N> &p)
----------------------------------------------------------------

No documentation available

const vector<N> & operator[](int n) const
-----------------------------------------

Get a reference to a vector stored in the pair

vector<N> & operator[](int n)
-----------------------------

Get a reference to a vector stored in the pair

vector<N> & origin()
--------------------

Get reference to first vector

const vector<N> & origin() const
--------------------------------

Get reference to first vector

vector<N> seg_pt_clst_pt(const vector<N> &point) const
------------------------------------------------------

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
segment with two point vectors and find the closest point on this
segment to a point in space.

   The return value is position of the closest point on segment.

   See also seg_pt_clst_pt_scale (*note _1069::) function.

double seg_pt_clst_pt_scale(const vector<N> &point) const
---------------------------------------------------------

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
segment with two point vectors and find the closest point on this
segment to a point in space.

   The return value is position on segment, value is in [0, 1] range if
on segment.

   See also seg_pt_clst_pt (*note _1068::) function.

math::vectorPairBase<2> internal struct members
===============================================

vectorPairBase()
----------------

No documentation available

vectorPairBase(const vector<N> &a, const vector<N> &b)
------------------------------------------------------

No documentation available

vector<N> & direction()
-----------------------

Get reference to second vector

const vector<N> & direction() const
-----------------------------------

Get reference to second vector

vector<N> ln_pt_clst_pt(const vector<N> &point) const
-----------------------------------------------------

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
line with origin and direction vectors and find the closest point on
this line to a point.

   The return value is position of the closest point on the line.

   See also ln_pt_clst_pt_scale (*note _1059::) function.

double ln_pt_clst_pt_scale(const vector<N> &point) const
--------------------------------------------------------

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
line with origin and direction vectors and find the closest point on
this line to an other line.

   The return value is scale factor of the direction vector from origin.

   See also ln_pt_clst_pt (*note _1058::) function.

vector<N> & normal()
--------------------

Get reference to second vector

const vector<N> & normal() const
--------------------------------

Get reference to second vector

vectorPairBase<2> operator*(double factor)
------------------------------------------

No documentation available

const vectorPairBase<2> & operator+=(const vectorPairBase<2> &p)
----------------------------------------------------------------

No documentation available

const vector<N> & operator[](int n) const
-----------------------------------------

Get a reference to a vector stored in the pair

vector<N> & operator[](int n)
-----------------------------

Get a reference to a vector stored in the pair

vector<N> & origin()
--------------------

Get reference to first vector

const vector<N> & origin() const
--------------------------------

Get reference to first vector

vector<N> seg_pt_clst_pt(const vector<N> &point) const
------------------------------------------------------

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
segment with two point vectors and find the closest point on this
segment to a point in space.

   The return value is position of the closest point on segment.

   See also seg_pt_clst_pt_scale (*note _1069::) function.

double seg_pt_clst_pt_scale(const vector<N> &point) const
---------------------------------------------------------

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
segment with two point vectors and find the closest point on this
segment to a point in space.

   The return value is position on segment, value is in [0, 1] range if
on segment.

   See also seg_pt_clst_pt (*note _1068::) function.

math::vectorPairBase<3> internal struct members
===============================================

vectorPairBase()
----------------

No documentation available

vectorPairBase(const vector<N> &a, const vector<N> &b)
------------------------------------------------------

No documentation available

vector<N> & direction()
-----------------------

Get reference to second vector

const vector<N> & direction() const
-----------------------------------

Get reference to second vector

vector<N> ln_pt_clst_pt(const vector<N> &point) const
-----------------------------------------------------

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
line with origin and direction vectors and find the closest point on
this line to a point.

   The return value is position of the closest point on the line.

   See also ln_pt_clst_pt_scale (*note _1059::) function.

double ln_pt_clst_pt_scale(const vector<N> &point) const
--------------------------------------------------------

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
line with origin and direction vectors and find the closest point on
this line to an other line.

   The return value is scale factor of the direction vector from origin.

   See also ln_pt_clst_pt (*note _1058::) function.

vector<N> & normal()
--------------------

Get reference to second vector

const vector<N> & normal() const
--------------------------------

Get reference to second vector

vectorPairBase<3> operator*(double factor)
------------------------------------------

No documentation available

const vectorPairBase<3> & operator+=(const vectorPairBase<3> &p)
----------------------------------------------------------------

No documentation available

const vector<N> & operator[](int n) const
-----------------------------------------

Get a reference to a vector stored in the pair

vector<N> & operator[](int n)
-----------------------------

Get a reference to a vector stored in the pair

vector<N> & origin()
--------------------

Get reference to first vector

const vector<N> & origin() const
--------------------------------

Get reference to first vector

vector<N> seg_pt_clst_pt(const vector<N> &point) const
------------------------------------------------------

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
segment with two point vectors and find the closest point on this
segment to a point in space.

   The return value is position of the closest point on segment.

   See also seg_pt_clst_pt_scale (*note _1069::) function.

double seg_pt_clst_pt_scale(const vector<N> &point) const
---------------------------------------------------------

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
segment with two point vectors and find the closest point on this
segment to a point in space.

   The return value is position on segment, value is in [0, 1] range if
on segment.

   See also seg_pt_clst_pt (*note _1068::) function.

math::TransformBase internal class members
==========================================

TransformBase()
---------------

No documentation available

virtual ~TransformBase()
------------------------

No documentation available

TransformBase & affine_rotation(unsigned int axis, double dangle)
-----------------------------------------------------------------

apply rotation to current transform (degree)

TransformBase & affine_rotation_rad(unsigned int axis, double rangle)
---------------------------------------------------------------------

apply rotation to current transform (radian)

TransformBase & affine_scaling(const vector<N> &v)
--------------------------------------------------

apply scaling to current transform

TransformBase & affine_scaling(double s)
----------------------------------------

apply scaling to current transform

TransformBase & apply_translation(const vector<N> &v)
-----------------------------------------------------

apply translation to current transform

void compose(const TransformBase<N> &t)
---------------------------------------

compose with t. new transform is equivalent to applying t then this
transform

const Matrix<N> & get_linear() const
------------------------------------

get linear transform matrix

Matrix<N> & get_linear()
------------------------

get linear transform matrix

const vector<N> & get_translation() const
-----------------------------------------

get translation vector

vector<N> & get_translation()
-----------------------------

get translation vector

TransformBase inverse() const
-----------------------------

get inverse transformation

void linear_reset()
-------------------

reset linear transform to identity

TransformBase & linear_rotation(unsigned int axis, double dangle)
-----------------------------------------------------------------

apply rotation to current transform (degree) (does not transform
translation vector)

TransformBase & linear_rotation_rad(unsigned int axis, double rangle)
---------------------------------------------------------------------

apply rotation to current transform (radian) (does not transform
translation vector)

TransformBase & linear_scaling(const vector<N> &v)
--------------------------------------------------

apply linear scaling to current transform (does not transform
translation vector)

TransformBase & linear_scaling(double s)
----------------------------------------

apply scaling to current transform (does not transform translation
vector)

void reset()
------------

reset linear transform to identity and translation to zero

void set_translation(const vector<N> &v)
----------------------------------------

set current translation

vector<N> transform(const vector<N> &v) const
---------------------------------------------

apply affine transform (translation and linear) to vector

vectorPair<N> transform_line(const vectorPair<N> &v) const
----------------------------------------------------------

apply affine transform to line origin and linear to direction

vector<N> transform_linear(const vector<N> &v) const
----------------------------------------------------

apply linear transform to vector

vectorPair<N> transform_pair(const vectorPair<N> &p) const
----------------------------------------------------------

apply affine transform to both vectors in pair

vector<N> transform_translate(const vector<N> &v) const
-------------------------------------------------------

apply translation to vector

void translation_reset()
------------------------

reset translation to zero

math::TriangleBase internal struct members
==========================================

TriangleBase()
--------------

No documentation available

TriangleBase(const vector<N> &a, const vector<N> &b, const vector<N> &c)
------------------------------------------------------------------------

Create a triangle from 3 points

vector<N> get_centroid() const
------------------------------

Get triangle centroid

const vector<N> & operator[](int n) const
-----------------------------------------

Get point n of the triangle

vector<N> & operator[](int n)
-----------------------------

Get reference to point n of the triangle

math::vectorBase internal struct members
========================================

bool close_to(const vectorBase &m, T error = 1 e-8)
---------------------------------------------------

compare two almost equal vectors

T len() const
-------------

Compute vector length

vectorBase magnitude(T newlen) const
------------------------------------

Adjust vector length

vectorBase mul(const vectorBase &v) const
-----------------------------------------

vector values multiply

vectorBase & neg()
------------------

Negate vector

const vectorBase & normalize()
------------------------------

Normalize vector length

   See also normalized (*note _1036::) function.

vectorBase normalized() const
-----------------------------

Get normalized vector

   See also normalize (*note _1035::) function.

T operator*(const vectorBase &v) const
--------------------------------------

vector dot product

vectorBase operator*(T scale) const
-----------------------------------

Scale vector

vectorBase operator*(const Matrix<N> &m)
----------------------------------------

Multiply vector with matrix. See vector class for matrix/vector
multiplication.

const vectorBase & operator*=(T scale)
--------------------------------------

Multiply by a vector

vectorBase operator+(const vectorBase &v) const
-----------------------------------------------

Add two vectors

const vectorBase & operator+=(const vectorBase &v)
--------------------------------------------------

Add a vector

vectorBase operator-(const vectorBase &v) const
-----------------------------------------------

Subtract two vectors

vectorBase operator-() const
----------------------------

Get negated vector

const vectorBase & operator-=(const vectorBase &v)
--------------------------------------------------

Sutract a vector

vectorBase operator/(T scale) const
-----------------------------------

Scale vector

vectorBase operator/(const vectorBase &v) const
-----------------------------------------------

vector division

const vectorBase & operator/=(T scale)
--------------------------------------

Divide by a vector

bool operator==(const vectorBase &m) const
------------------------------------------

compare two vectors for equality

T operator[](int n) const
-------------------------

Get value at specified index

T & operator[](int n)
---------------------

Get reference to value at specified index

template <int M> vectorBase<M, T> select(unsigned int bitmask, const vectorBase<M, T> &v) const
-----------------------------------------------------------------------------------------------

Select components from two vectors. Components which have their
corresponding bit set in the mask are extracted from this vector and
other components are taken from passed vector.

void set(T value)
-----------------

Set the whole vector to the specified value

math::vectorPairBase internal struct members
============================================

vectorPairBase()
----------------

No documentation available

vectorPairBase(const vector<N> &a, const vector<N> &b)
------------------------------------------------------

No documentation available

vector<N> & direction()
-----------------------

Get reference to second vector

const vector<N> & direction() const
-----------------------------------

Get reference to second vector

vector<N> ln_pt_clst_pt(const vector<N> &point) const
-----------------------------------------------------

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
line with origin and direction vectors and find the closest point on
this line to a point.

   The return value is position of the closest point on the line.

   See also ln_pt_clst_pt_scale (*note _1059::) function.

double ln_pt_clst_pt_scale(const vector<N> &point) const
--------------------------------------------------------

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
line with origin and direction vectors and find the closest point on
this line to an other line.

   The return value is scale factor of the direction vector from origin.

   See also ln_pt_clst_pt (*note _1058::) function.

vector<N> & normal()
--------------------

Get reference to second vector

const vector<N> & normal() const
--------------------------------

Get reference to second vector

vectorPairBase operator*(double factor)
---------------------------------------

No documentation available

const vectorPairBase & operator+=(const vectorPairBase &p)
----------------------------------------------------------

No documentation available

const vector<N> & operator[](int n) const
-----------------------------------------

Get a reference to a vector stored in the pair

vector<N> & operator[](int n)
-----------------------------

Get a reference to a vector stored in the pair

vector<N> & origin()
--------------------

Get reference to first vector

const vector<N> & origin() const
--------------------------------

Get reference to first vector

vector<N> seg_pt_clst_pt(const vector<N> &point) const
------------------------------------------------------

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
segment with two point vectors and find the closest point on this
segment to a point in space.

   The return value is position of the closest point on segment.

   See also seg_pt_clst_pt_scale (*note _1069::) function.

double seg_pt_clst_pt_scale(const vector<N> &point) const
---------------------------------------------------------

Consider the vectorPair (*note math_vectorPair_struct_reference::) as a
segment with two point vectors and find the closest point on this
segment to a point in space.

   The return value is position on segment, value is in [0, 1] range if
on segment.

   See also seg_pt_clst_pt (*note _1068::) function.

shape namespace reference
=========================

Description
-----------

2d shapes used for surface contours

Members
-------

Types
.....

   * class Base

   * class Composer

   * class disk

   * class Ellipse

   * class EllipticalRing

   * class Infinite

   * class Polygon

   * class Rectangle

   * class RegularPolygon

   * class Ring

Variable
........

   * Infinite infinite

Members detail
--------------

Infinite infinite
.................

No documentation available

shape::Base class reference
===========================

Declaration
-----------

     #include <goptical/core/shape/Base>

     namespace goptical {
       namespace shape {
         class Base;
       };
     };

   This class is a member of the shape namespace.

   This abstract class contains pure virtuals.

Inheritance
-----------

Description
-----------

This class defines an interface for all 2d shape implementations. It is
mainly used to describe 2d contours of optical surfaces and provides
distribution pattern for ray tracing.

Members
-------

See also the full member list (*note
shape_Base_class_full_member_list::) section for this class.

Functions
.........

   * Base()

   * virtual ~Base()

   * virtual math::vectorPair2 get_bounding_box() const = 0;

   * virtual void get_contour(unsigned int contour, const
     math::vector2::put_delegate_t &f, double resolution) const = 0;

   * virtual unsigned int get_contour_count() const = 0;

   * virtual double get_hole_radius(const math::vector2 &dir) const

   * virtual double get_outter_radius(const math::vector2 &dir) const =
     0;

   * virtual void get_pattern(const math::vector2::put_delegate_t &f,
     const trace::distribution &d, bool unobstructed = _[...]_) const

   * virtual void get_triangles(const math::Triangle<2>::put_delegate_t
     &f, double resolution) const = 0;

   * virtual bool inside(const math::vector2 &point) const = 0;

   * virtual double max_radius() const = 0;

   * virtual double min_radius() const = 0;

Members detail
--------------

Base()
......

No documentation available

virtual ~Base()
...............

No documentation available

virtual math::vectorPair2 get_bounding_box() const = 0;
.......................................................

Get shape bounding box

virtual void get_contour(unsigned int contour, const math::vector2::put_delegate_t &f, double resolution) const = 0;
....................................................................................................................

Get contour polygone points for specified contour id. First contour is
always outter edge.

   See also get_contour_count (*note _1075::) function.

virtual unsigned int get_contour_count() const = 0;
...................................................

Get number of contours polygones. This function returns value is
greater than 1 if shape has hole(s).

   See also get_contour (*note _1074::) function.

virtual double get_hole_radius(const math::vector2 &dir) const
..............................................................

Get distance between origin and nearest shape outter edge in specified
direction

virtual double get_outter_radius(const math::vector2 &dir) const = 0;
.....................................................................

Get distance between origin and farthest shape edge in specified
direction

virtual void get_pattern(const math::vector2::put_delegate_t &f, const trace::distribution &d, bool unobstructed = false) const
...............................................................................................................................

Get points distributed on shape area with given pattern

virtual void get_triangles(const math::Triangle<2>::put_delegate_t &f, double resolution) const = 0;
....................................................................................................

Get shape teselation triangles

virtual bool inside(const math::vector2 &point) const = 0;
..........................................................

Check if the (x,y) 2d point is inside 2d shape area

virtual double max_radius() const = 0;
......................................

Get distance between origin and farthest shape edge

virtual double min_radius() const = 0;
......................................

Get distance between origin and nearest shape outter edge

shape::Base class full member list
==================================

Functions
---------

   * Base()

   * virtual ~Base()

   * virtual math::vectorPair2 get_bounding_box() const = 0;

   * virtual void get_contour(unsigned int contour, const
     math::vector2::put_delegate_t &f, double resolution) const = 0;

   * virtual unsigned int get_contour_count() const = 0;

   * virtual double get_hole_radius(const math::vector2 &dir) const

   * virtual double get_outter_radius(const math::vector2 &dir) const =
     0;

   * virtual void get_pattern(const math::vector2::put_delegate_t &f,
     const trace::distribution &d, bool unobstructed = _[...]_) const

   * virtual void get_triangles(const math::Triangle<2>::put_delegate_t
     &f, double resolution) const = 0;

   * virtual bool inside(const math::vector2 &point) const = 0;

   * virtual double max_radius() const = 0;

   * virtual double min_radius() const = 0;

shape::Composer class reference
===============================

Declaration
-----------

This class is flagged as experimental.

     #include <goptical/core/shape/Composer>

     namespace goptical {
       namespace shape {
         class Composer;
       };
     };

   This class is a member of the shape namespace.

Inheritance
-----------

Description
-----------

This class allows definition of a shape by composition of other shape
models. Coordinate transforms and boolean operations can be performed
on shapes.

   This class is still experimental, 2d contour and 3d tessellation
code doesn't give propser results.

Members
-------

See also the full member list (*note
shape_Composer_class_full_member_list::) section for this class.

Inherited members
.................

   * 12 members inherited from Base (*note shape_Base_class_reference::)

Type
....

   * class Attributes

Functions
.........

   * Composer()

   * Attributes & add_shape(const const_ref<Base> &shape)

   * virtual math::vectorPair2 get_bounding_box() const

   * virtual void get_contour(unsigned int contour, const
     math::vector2::put_delegate_t &f, double resolution) const

   * virtual unsigned int get_contour_count() const

   * virtual double get_hole_radius(const math::vector2 &dir) const

   * virtual double get_outter_radius(const math::vector2 &dir) const

   * virtual void get_pattern(const math::vector2::put_delegate_t &f,
     const trace::distribution &d, bool unobstructed) const

   * virtual void get_triangles(const math::Triangle<2>::put_delegate_t
     &f, double resolution) const

   * virtual bool inside(const math::vector2 &point) const

   * virtual double max_radius() const

   * virtual double min_radius() const

   * void use_global_distribution(bool use_global)

Members detail
--------------

Composer()
..........

This constructor is flagged as experimental.

Attributes & add_shape(const  const_ref <Base> &shape)
......................................................

This function is flagged as experimental.

   Add a new shape to shape composer.

   This function returns a reference to an Attributes (*note
shape_Composer_Attributes_class_reference::) object which may be
modified to set shape transform and boolean operations.

   The composed shape is the union between all shapes added with this
function.

virtual math::vectorPair2 get_bounding_box() const
..................................................

This virtual function is flagged as experimental.

   This virtual function implements the `get_bounding_box (*note
_1073::)' pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get shape bounding box

virtual void get_contour(unsigned int contour, const math::vector2::put_delegate_t &f, double resolution) const
...............................................................................................................

This virtual function is flagged as experimental.

   This virtual function implements the `get_contour (*note _1074::)'
pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get contour polygone points for specified contour id. First contour
is always outter edge.

   See also get_contour_count (*note _1075::) function.

virtual unsigned int get_contour_count() const
..............................................

This virtual function is flagged as experimental.

   This virtual function implements the `get_contour_count (*note
_1075::)' pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get number of contours polygones. This function returns value is
greater than 1 if shape has hole(s).

   See also get_contour (*note _1074::) function.

virtual double get_hole_radius(const math::vector2 &dir) const
..............................................................

This virtual function is flagged as experimental.

   This virtual function overrides the `get_hole_radius (*note
_1076::)' virtual function defined in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get distance between origin and nearest shape outter edge in
specified direction

virtual double get_outter_radius(const math::vector2 &dir) const
................................................................

This virtual function is flagged as experimental.

   This virtual function implements the `get_outter_radius (*note
_1077::)' pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get distance between origin and farthest shape edge in specified
direction

virtual void get_pattern(const math::vector2::put_delegate_t &f, const trace::distribution &d, bool unobstructed) const
.......................................................................................................................

This virtual function is flagged as experimental.

   This virtual function overrides the `get_pattern (*note _1078::)'
virtual function defined in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get points distributed on shape area with given pattern

virtual void get_triangles(const math::Triangle<2>::put_delegate_t &f, double resolution) const
...............................................................................................

This virtual function is flagged as experimental.

   This virtual function implements the `get_triangles (*note _1079::)'
pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get shape teselation triangles

virtual bool inside(const math::vector2 &point) const
.....................................................

This virtual function is flagged as experimental.

   This virtual function implements the `inside (*note _1080::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Check if the (x,y) 2d point is inside 2d shape area

virtual double max_radius() const
.................................

This virtual function is flagged as experimental.

   This virtual function implements the `max_radius (*note _1081::)'
pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get distance between origin and farthest shape edge

virtual double min_radius() const
.................................

This virtual function is flagged as experimental.

   This virtual function implements the `min_radius (*note _1082::)'
pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get distance between origin and nearest shape outter edge

void use_global_distribution(bool use_global)
.............................................

This function is flagged as experimental.

   Set ray distribution behavior. Default is to perform individual ray
distribution on each composer shape.

   Global mode distributes rays over a circle with maximum shape
radius, it may be used to ensure ray density is the same on each shape.
Unobstructed ray tracing require global distribution too.

shape::Composer class full member list
======================================

Type
----

   * class Attributes

Functions
---------

   * Composer()

   * Attributes & add_shape(const const_ref<Base> &shape)

   * virtual math::vectorPair2 get_bounding_box() const

   * virtual void get_contour(unsigned int contour, const
     math::vector2::put_delegate_t &f, double resolution) const

   * virtual unsigned int get_contour_count() const

   * virtual double get_hole_radius(const math::vector2 &dir) const

   * virtual double get_outter_radius(const math::vector2 &dir) const

   * virtual void get_pattern(const math::vector2::put_delegate_t &f,
     const trace::distribution &d, bool unobstructed) const

   * virtual void get_triangles(const math::Triangle<2>::put_delegate_t
     &f, double resolution) const

   * virtual bool inside(const math::vector2 &point) const

   * virtual double max_radius() const

   * virtual double min_radius() const

   * void use_global_distribution(bool use_global)

shape::Composer::Attributes class reference
===========================================

Declaration
-----------

This class is flagged as experimental.

     #include <goptical/core/shape/Composer>

     namespace goptical {
       namespace shape {
         class Composer {
           class Attributes;
         };
       };
     };

   This class is a member of the Composer class.

Description
-----------

This class contains child shape transform and boolean operations for
the Composer (*note shape_Composer_class_reference::) shape class.

Members
-------

See also the full member list (*note
shape_Composer_Attributes_class_full_member_list::) section for this
class.

Functions
.........

   * Attributes & exclude(const const_ref<Base> &shape)

   * Attributes & include(const const_ref<Base> &shape)

   * Attributes & rotate(double dangle)

   * Attributes & scale(const math::vector2 &factor)

   * Attributes & translate(const math::vector2 &offset)

Members detail
--------------

Attributes & exclude(const  const_ref <Base> &shape)
....................................................

This function is flagged as experimental.

   Peform boolean 'and not' with the given shape

Attributes & include(const  const_ref <Base> &shape)
....................................................

This function is flagged as experimental.

   Peform boolean 'and' with the given shape

Attributes & rotate(double dangle)
..................................

This function is flagged as experimental.

   Apply rotation affine transform. Angle is in degree.

Attributes & scale(const math::vector2 &factor)
...............................................

This function is flagged as experimental.

   Apply scaling affine transform using scale factors (xscale, yscale)

Attributes & translate(const math::vector2 &offset)
...................................................

This function is flagged as experimental.

   Apply translation transform

shape::Composer::Attributes class full member list
==================================================

Functions
---------

   * Attributes & exclude(const const_ref<Base> &shape)

   * Attributes & include(const const_ref<Base> &shape)

   * Attributes & rotate(double dangle)

   * Attributes & scale(const math::vector2 &factor)

   * Attributes & translate(const math::vector2 &offset)

shape::disk class reference
===========================

Declaration
-----------

     #include <goptical/core/shape/disk>

     namespace goptical {
       namespace shape {
         class disk;
       };
     };

   This class is a member of the shape namespace.

Inheritance
-----------

Description
-----------

This is the most common lens shape.

Members
-------

See also the full member list (*note
shape_disk_class_full_member_list::) section for this class.

Inherited members
.................

   * 12 members inherited from Base (*note shape_Base_class_reference::)

Functions
.........

   * disk(double radius)

   * virtual void get_contour(unsigned int contour, const
     math::vector2::put_delegate_t &f, double resolution) const

   * virtual unsigned int get_contour_count() const

   * virtual void get_pattern(const math::vector2::put_delegate_t &v,
     const trace::distribution &d, bool unobstructed) const

   * double get_radius(void ) const

   * virtual void get_triangles(const math::Triangle<2>::put_delegate_t
     &f, double resolution) const

   * void set_radius(double r)

Members detail
--------------

disk(double radius)
...................

Create a new disk with given radius

shape::disk class full member list
==================================

Functions
---------

   * disk(double radius)

   * virtual void get_contour(unsigned int contour, const
     math::vector2::put_delegate_t &f, double resolution) const

   * virtual unsigned int get_contour_count() const

   * virtual double get_hole_radius(const math::vector2 &dir) const

   * virtual void get_pattern(const math::vector2::put_delegate_t &v,
     const trace::distribution &d, bool unobstructed) const

   * double get_radius(void ) const

   * virtual void get_triangles(const math::Triangle<2>::put_delegate_t
     &f, double resolution) const

   * void set_radius(double r)

shape::Ellipse class reference
==============================

Declaration
-----------

     #include <goptical/core/shape/Ellipse>

     namespace goptical {
       namespace shape {
         class Ellipse;
       };
     };

   This class is a member of the shape namespace.

Inheritance
-----------

Description
-----------

Ellipse shape

Members
-------

See also the full member list (*note
shape_Ellipse_class_full_member_list::) section for this class.

Inherited members
.................

   * 12 members inherited from Base (*note shape_Base_class_reference::)

Functions
.........

   * Ellipse(double x_radius, double y_radius)

   * virtual math::vectorPair2 get_bounding_box() const

   * virtual void get_contour(unsigned int contour, const
     math::vector2::put_delegate_t &f, double resolution) const

   * virtual unsigned int get_contour_count() const

   * virtual double get_outter_radius(const math::vector2 &dir) const

   * virtual void get_pattern(const math::vector2::put_delegate_t &v,
     const trace::distribution &d, bool unobstructed) const

   * virtual void get_triangles(const math::Triangle<2>::put_delegate_t
     &f, double resolution) const

   * double get_x_radius(void ) const

   * double get_y_radius(void ) const

   * virtual bool inside(const math::vector2 &point) const

   * virtual double max_radius() const

   * virtual double min_radius() const

   * void set_radius(double xr, double yr)

Members detail
--------------

Ellipse(double x_radius, double y_radius)
.........................................

Create a new ellipse with given radius

shape::Ellipse class full member list
=====================================

Functions
---------

   * Ellipse(double x_radius, double y_radius)

   * virtual math::vectorPair2 get_bounding_box() const

   * virtual void get_contour(unsigned int contour, const
     math::vector2::put_delegate_t &f, double resolution) const

   * virtual unsigned int get_contour_count() const

   * virtual double get_hole_radius(const math::vector2 &dir) const

   * virtual double get_outter_radius(const math::vector2 &dir) const

   * virtual void get_pattern(const math::vector2::put_delegate_t &v,
     const trace::distribution &d, bool unobstructed) const

   * virtual void get_triangles(const math::Triangle<2>::put_delegate_t
     &f, double resolution) const

   * double get_x_radius(void ) const

   * double get_y_radius(void ) const

   * virtual bool inside(const math::vector2 &point) const

   * virtual double max_radius() const

   * virtual double min_radius() const

   * void set_radius(double xr, double yr)

shape::EllipticalRing class reference
=====================================

Declaration
-----------

     #include <goptical/core/shape/EllipticalRing>

     namespace goptical {
       namespace shape {
         class EllipticalRing;
       };
     };

   This class is a member of the shape namespace.

Inheritance
-----------

Description
-----------

This is an ellipse shape with a hole in center.

Members
-------

See also the full member list (*note
shape_EllipticalRing_class_full_member_list::) section for this class.

Inherited members
.................

   * 12 members inherited from Base (*note shape_Base_class_reference::)

Functions
.........

   * EllipticalRing(double x_radius, double y_radius, double
     x_hole_radius)

   * virtual math::vectorPair2 get_bounding_box() const

   * virtual void get_contour(unsigned int contour, const
     math::vector2::put_delegate_t &f, double resolution) const

   * virtual unsigned int get_contour_count() const

   * virtual double get_hole_radius(const math::vector2 &dir) const

   * virtual double get_outter_radius(const math::vector2 &dir) const

   * virtual void get_pattern(const math::vector2::put_delegate_t &v,
     const trace::distribution &d, bool unobstructed) const

   * virtual void get_triangles(const math::Triangle<2>::put_delegate_t
     &f, double resolution) const

   * double get_x_hole_radius(void ) const

   * double get_x_radius(void ) const

   * double get_y_hole_radius(void ) const

   * double get_y_radius(void ) const

   * virtual bool inside(const math::vector2 &point) const

   * virtual double max_radius() const

   * virtual double min_radius() const

   * void set_radius(double x_radius, double y_radius, double
     x_hole_radius)

Members detail
--------------

EllipticalRing(double x_radius, double y_radius, double x_hole_radius)
......................................................................

Create a new elliptical ring with given external ring radius along the
x and y axes and hole radius along the x axis.

shape::EllipticalRing class full member list
============================================

Functions
---------

   * EllipticalRing(double x_radius, double y_radius, double
     x_hole_radius)

   * virtual math::vectorPair2 get_bounding_box() const

   * virtual void get_contour(unsigned int contour, const
     math::vector2::put_delegate_t &f, double resolution) const

   * virtual unsigned int get_contour_count() const

   * virtual double get_hole_radius(const math::vector2 &dir) const

   * virtual double get_outter_radius(const math::vector2 &dir) const

   * virtual void get_pattern(const math::vector2::put_delegate_t &v,
     const trace::distribution &d, bool unobstructed) const

   * virtual void get_triangles(const math::Triangle<2>::put_delegate_t
     &f, double resolution) const

   * double get_x_hole_radius(void ) const

   * double get_x_radius(void ) const

   * double get_y_hole_radius(void ) const

   * double get_y_radius(void ) const

   * virtual bool inside(const math::vector2 &point) const

   * virtual double max_radius() const

   * virtual double min_radius() const

   * void set_radius(double x_radius, double y_radius, double
     x_hole_radius)

shape::Infinite class reference
===============================

Declaration
-----------

     #include <goptical/core/shape/Infinite>

     namespace goptical {
       namespace shape {
         class Infinite;
       };
     };

   This class is a member of the shape namespace.

Inheritance
-----------

Description
-----------

This class implements an infinite shape with no edge. Any 2d points is
located inside the shape. It is useful to describe unbounded image
plane for instance.

   The global variable infinite (*note _1070::) provides an instance of
this class.

Members
-------

See also the full member list (*note
shape_Infinite_class_full_member_list::) section for this class.

Inherited members
.................

   * 12 members inherited from Base (*note shape_Base_class_reference::)

Functions
.........

   * Infinite()

   * virtual math::vectorPair2 get_bounding_box() const

   * virtual void get_contour(unsigned int contour, const
     math::vector2::put_delegate_t &f, double resolution) const

   * virtual unsigned int get_contour_count() const

   * virtual double get_outter_radius(const math::vector2 &dir) const

   * virtual void get_pattern(const math::vector2::put_delegate_t &v,
     const trace::distribution &d, bool unobstructed) const

   * virtual void get_triangles(const math::Triangle<2>::put_delegate_t
     &f, double resolution) const

   * virtual bool inside(const math::vector2 &point) const

   * virtual double max_radius() const

   * virtual double min_radius() const

Members detail
--------------

Infinite()
..........

Create an infinite shape

virtual math::vectorPair2 get_bounding_box() const
..................................................

This virtual function implements the `get_bounding_box (*note _1073::)'
pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get shape bounding box

virtual void get_contour(unsigned int contour, const math::vector2::put_delegate_t &f, double resolution) const
...............................................................................................................

This virtual function implements the `get_contour (*note _1074::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get contour polygone points for specified contour id. First contour
is always outter edge.

   See also get_contour_count (*note _1075::) function.

virtual unsigned int get_contour_count() const
..............................................

This virtual function implements the `get_contour_count (*note
_1075::)' pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get number of contours polygones. This function returns value is
greater than 1 if shape has hole(s).

   See also get_contour (*note _1074::) function.

virtual double get_outter_radius(const math::vector2 &dir) const
................................................................

This virtual function implements the `get_outter_radius (*note
_1077::)' pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get distance between origin and farthest shape edge in specified
direction

virtual void get_pattern(const math::vector2::put_delegate_t &v, const trace::distribution &d, bool unobstructed) const
.......................................................................................................................

This virtual function overrides the `get_pattern (*note _1078::)'
virtual function defined in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get points distributed on shape area with given pattern

virtual void get_triangles(const math::Triangle<2>::put_delegate_t &f, double resolution) const
...............................................................................................

This virtual function implements the `get_triangles (*note _1079::)'
pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get shape teselation triangles

virtual bool inside(const math::vector2 &point) const
.....................................................

This virtual function implements the `inside (*note _1080::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Check if the (x,y) 2d point is inside 2d shape area

virtual double max_radius() const
.................................

This virtual function implements the `max_radius (*note _1081::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get distance between origin and farthest shape edge

virtual double min_radius() const
.................................

This virtual function implements the `min_radius (*note _1082::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get distance between origin and nearest shape outter edge

shape::Infinite class full member list
======================================

Functions
---------

   * Infinite()

   * virtual math::vectorPair2 get_bounding_box() const

   * virtual void get_contour(unsigned int contour, const
     math::vector2::put_delegate_t &f, double resolution) const

   * virtual unsigned int get_contour_count() const

   * virtual double get_hole_radius(const math::vector2 &dir) const

   * virtual double get_outter_radius(const math::vector2 &dir) const

   * virtual void get_pattern(const math::vector2::put_delegate_t &v,
     const trace::distribution &d, bool unobstructed) const

   * virtual void get_triangles(const math::Triangle<2>::put_delegate_t
     &f, double resolution) const

   * virtual bool inside(const math::vector2 &point) const

   * virtual double max_radius() const

   * virtual double min_radius() const

shape::Polygon class reference
==============================

Declaration
-----------

     #include <goptical/core/shape/Polygon>

     namespace goptical {
       namespace shape {
         class Polygon;
       };
     };

   This class is a member of the shape namespace.

Inheritance
-----------

Description
-----------

This class implements the polygon shape.

   Triangle tessellation required for proper 3d display only works with
convex polygons yet.

   See also RegularPolygon (*note
shape_RegularPolygon_class_reference::) class.

Members
-------

See also the full member list (*note
shape_Polygon_class_full_member_list::) section for this class.

Inherited members
.................

   * 12 members inherited from Base (*note shape_Base_class_reference::)

Functions
.........

   * Polygon()

   * unsigned int add_vertex(const math::vector2 &v)

   * void delete_vertex(unsigned int id)

   * const math::vector2 & get_vertex(unsigned int id)

   * unsigned int get_vertices_count() const

   * void insert_vertex(const math::vector2 &v, unsigned int id)

Members detail
--------------

Polygon()
.........

Create a polygon with given radius and edge count

unsigned int add_vertex(const math::vector2 &v)
...............................................

No documentation available

void delete_vertex(unsigned int id)
...................................

No documentation available

const math::vector2 & get_vertex(unsigned int id)
.................................................

No documentation available

unsigned int get_vertices_count() const
.......................................

No documentation available

void insert_vertex(const math::vector2 &v, unsigned int id)
...........................................................

No documentation available

shape::Polygon class full member list
=====================================

Functions
---------

   * Polygon()

   * unsigned int add_vertex(const math::vector2 &v)

   * void delete_vertex(unsigned int id)

   * virtual double get_hole_radius(const math::vector2 &dir) const

   * virtual void get_pattern(const math::vector2::put_delegate_t &f,
     const trace::distribution &d, bool unobstructed = _[...]_) const

   * const math::vector2 & get_vertex(unsigned int id)

   * unsigned int get_vertices_count() const

   * void insert_vertex(const math::vector2 &v, unsigned int id)

shape::Rectangle class reference
================================

Declaration
-----------

     #include <goptical/core/shape/Rectangle>

     namespace goptical {
       namespace shape {
         class Rectangle;
       };
     };

   This class is a member of the shape namespace.

Inheritance
-----------

Description
-----------

Rectangle and square shape

Members
-------

See also the full member list (*note
shape_Rectangle_class_full_member_list::) section for this class.

Inherited members
.................

   * 12 members inherited from Base (*note shape_Base_class_reference::)

Functions
.........

   * Rectangle(double width, double height)

   * Rectangle(double sqsize)

   * virtual math::vectorPair2 get_bounding_box() const

   * virtual void get_contour(unsigned int contour, const
     math::vector2::put_delegate_t &f, double resolution) const

   * virtual unsigned int get_contour_count() const

   * virtual double get_outter_radius(const math::vector2 &dir) const

   * virtual void get_pattern(const math::vector2::put_delegate_t &v,
     const trace::distribution &d, bool unobstructed) const

   * virtual void get_triangles(const math::Triangle<2>::put_delegate_t
     &f, double resolution) const

   * virtual bool inside(const math::vector2 &point) const

   * virtual double max_radius() const

   * virtual double min_radius() const

Members detail
--------------

Rectangle(double width, double height)
......................................

Create a rectangle with given width and height

Rectangle(double sqsize)
........................

Create a square with given side length

virtual math::vectorPair2 get_bounding_box() const
..................................................

This virtual function implements the `get_bounding_box (*note _1073::)'
pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get shape bounding box

virtual void get_contour(unsigned int contour, const math::vector2::put_delegate_t &f, double resolution) const
...............................................................................................................

This virtual function implements the `get_contour (*note _1074::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get contour polygone points for specified contour id. First contour
is always outter edge.

   See also get_contour_count (*note _1075::) function.

virtual unsigned int get_contour_count() const
..............................................

This virtual function implements the `get_contour_count (*note
_1075::)' pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get number of contours polygones. This function returns value is
greater than 1 if shape has hole(s).

   See also get_contour (*note _1074::) function.

virtual double get_outter_radius(const math::vector2 &dir) const
................................................................

This virtual function implements the `get_outter_radius (*note
_1077::)' pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get distance between origin and farthest shape edge in specified
direction

virtual void get_pattern(const math::vector2::put_delegate_t &v, const trace::distribution &d, bool unobstructed) const
.......................................................................................................................

This virtual function overrides the `get_pattern (*note _1078::)'
virtual function defined in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get points distributed on shape area with given pattern

virtual void get_triangles(const math::Triangle<2>::put_delegate_t &f, double resolution) const
...............................................................................................

This virtual function implements the `get_triangles (*note _1079::)'
pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get shape teselation triangles

virtual bool inside(const math::vector2 &point) const
.....................................................

This virtual function implements the `inside (*note _1080::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Check if the (x,y) 2d point is inside 2d shape area

virtual double max_radius() const
.................................

This virtual function implements the `max_radius (*note _1081::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get distance between origin and farthest shape edge

virtual double min_radius() const
.................................

This virtual function implements the `min_radius (*note _1082::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get distance between origin and nearest shape outter edge

shape::Rectangle class full member list
=======================================

Functions
---------

   * Rectangle(double width, double height)

   * Rectangle(double sqsize)

   * virtual math::vectorPair2 get_bounding_box() const

   * virtual void get_contour(unsigned int contour, const
     math::vector2::put_delegate_t &f, double resolution) const

   * virtual unsigned int get_contour_count() const

   * virtual double get_hole_radius(const math::vector2 &dir) const

   * virtual double get_outter_radius(const math::vector2 &dir) const

   * virtual void get_pattern(const math::vector2::put_delegate_t &v,
     const trace::distribution &d, bool unobstructed) const

   * virtual void get_triangles(const math::Triangle<2>::put_delegate_t
     &f, double resolution) const

   * virtual bool inside(const math::vector2 &point) const

   * virtual double max_radius() const

   * virtual double min_radius() const

shape::RegularPolygon class reference
=====================================

Declaration
-----------

     #include <goptical/core/shape/RegularPolygon>

     namespace goptical {
       namespace shape {
         class RegularPolygon;
       };
     };

   This class is a member of the shape namespace.

Inheritance
-----------

Description
-----------

See Polygon (*note shape_Polygon_class_reference::) class.

Members
-------

See also the full member list (*note
shape_RegularPolygon_class_full_member_list::) section for this class.

Inherited members
.................

   * 12 members inherited from Base (*note shape_Base_class_reference::)

Functions
.........

   * RegularPolygon(double radius, unsigned int edge_cnt, double
     degree_angle = _[...]_)

   * virtual math::vectorPair2 get_bounding_box() const

   * virtual void get_contour(unsigned int contour, const
     math::vector2::put_delegate_t &f, double resolution) const

   * virtual unsigned int get_contour_count() const

   * virtual double get_outter_radius(const math::vector2 &dir) const

   * virtual void get_triangles(const math::Triangle<2>::put_delegate_t
     &f, double resolution) const

   * virtual bool inside(const math::vector2 &point) const

   * virtual double max_radius() const

   * virtual double min_radius() const

Members detail
--------------

RegularPolygon(double radius, unsigned int edge_cnt, double degree_angle = 0.)
..............................................................................

Create a regular_polygon with given radius and edge count.

virtual math::vectorPair2 get_bounding_box() const
..................................................

This virtual function implements the `get_bounding_box (*note _1073::)'
pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get shape bounding box

virtual void get_contour(unsigned int contour, const math::vector2::put_delegate_t &f, double resolution) const
...............................................................................................................

This virtual function implements the `get_contour (*note _1074::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get contour polygone points for specified contour id. First contour
is always outter edge.

   See also get_contour_count (*note _1075::) function.

virtual unsigned int get_contour_count() const
..............................................

This virtual function implements the `get_contour_count (*note
_1075::)' pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get number of contours polygones. This function returns value is
greater than 1 if shape has hole(s).

   See also get_contour (*note _1074::) function.

virtual double get_outter_radius(const math::vector2 &dir) const
................................................................

This virtual function implements the `get_outter_radius (*note
_1077::)' pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get distance between origin and farthest shape edge in specified
direction

virtual void get_triangles(const math::Triangle<2>::put_delegate_t &f, double resolution) const
...............................................................................................

This virtual function implements the `get_triangles (*note _1079::)'
pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get shape teselation triangles

virtual bool inside(const math::vector2 &point) const
.....................................................

This virtual function implements the `inside (*note _1080::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Check if the (x,y) 2d point is inside 2d shape area

virtual double max_radius() const
.................................

This virtual function implements the `max_radius (*note _1081::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get distance between origin and farthest shape edge

virtual double min_radius() const
.................................

This virtual function implements the `min_radius (*note _1082::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get distance between origin and nearest shape outter edge

shape::RegularPolygon class full member list
============================================

Functions
---------

   * RegularPolygon(double radius, unsigned int edge_cnt, double
     degree_angle = _[...]_)

   * virtual math::vectorPair2 get_bounding_box() const

   * virtual void get_contour(unsigned int contour, const
     math::vector2::put_delegate_t &f, double resolution) const

   * virtual unsigned int get_contour_count() const

   * virtual double get_hole_radius(const math::vector2 &dir) const

   * virtual double get_outter_radius(const math::vector2 &dir) const

   * virtual void get_pattern(const math::vector2::put_delegate_t &f,
     const trace::distribution &d, bool unobstructed = _[...]_) const

   * virtual void get_triangles(const math::Triangle<2>::put_delegate_t
     &f, double resolution) const

   * virtual bool inside(const math::vector2 &point) const

   * virtual double max_radius() const

   * virtual double min_radius() const

shape::Ring class reference
===========================

Declaration
-----------

     #include <goptical/core/shape/Ring>

     namespace goptical {
       namespace shape {
         class Ring;
       };
     };

   This class is a member of the shape namespace.

Inheritance
-----------

Description
-----------

This is a disk shape with a hole in center.

Members
-------

See also the full member list (*note
shape_Ring_class_full_member_list::) section for this class.

Inherited members
.................

   * 12 members inherited from Base (*note shape_Base_class_reference::)

Functions
.........

   * Ring(double radius, double hole_radius)

   * virtual math::vectorPair2 get_bounding_box() const

   * virtual void get_contour(unsigned int contour, const
     math::vector2::put_delegate_t &f, double resolution) const

   * virtual unsigned int get_contour_count() const

   * double get_hole_radius() const

   * virtual double get_hole_radius(const math::vector2 &dir) const

   * virtual double get_outter_radius(const math::vector2 &dir) const

   * virtual void get_pattern(const math::vector2::put_delegate_t &v,
     const trace::distribution &d, bool unobstructed) const

   * double get_radius() const

   * virtual void get_triangles(const math::Triangle<2>::put_delegate_t
     &f, double resolution) const

   * virtual bool inside(const math::vector2 &point) const

   * virtual double max_radius() const

   * virtual double min_radius() const

   * void set_radius(double radius, double hole_radius)

Members detail
--------------

Ring(double radius, double hole_radius)
.......................................

Create a new ring with given external radius and hole radius.

shape::Ring class full member list
==================================

Functions
---------

   * Ring(double radius, double hole_radius)

   * virtual math::vectorPair2 get_bounding_box() const

   * virtual void get_contour(unsigned int contour, const
     math::vector2::put_delegate_t &f, double resolution) const

   * virtual unsigned int get_contour_count() const

   * double get_hole_radius() const

   * virtual double get_hole_radius(const math::vector2 &dir) const

   * virtual double get_outter_radius(const math::vector2 &dir) const

   * virtual void get_pattern(const math::vector2::put_delegate_t &v,
     const trace::distribution &d, bool unobstructed) const

   * double get_radius() const

   * virtual void get_triangles(const math::Triangle<2>::put_delegate_t
     &f, double resolution) const

   * virtual bool inside(const math::vector2 &point) const

   * virtual double max_radius() const

   * virtual double min_radius() const

   * void set_radius(double radius, double hole_radius)

shape::Round<shape::diskBase,false> internal class members
==========================================================

virtual void get_contour(unsigned int contour, const math::vector2::put_delegate_t &f, double resolution) const
---------------------------------------------------------------------------------------------------------------

This virtual function implements the `get_contour (*note _1074::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get contour polygone points for specified contour id. First contour
is always outter edge.

   See also get_contour_count (*note _1075::) function.

virtual unsigned int get_contour_count() const
----------------------------------------------

This virtual function implements the `get_contour_count (*note
_1075::)' pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get number of contours polygones. This function returns value is
greater than 1 if shape has hole(s).

   See also get_contour (*note _1074::) function.

virtual void get_pattern(const math::vector2::put_delegate_t &v, const trace::distribution &d, bool unobstructed) const
-----------------------------------------------------------------------------------------------------------------------

This virtual function overrides the `get_pattern (*note _1078::)'
virtual function defined in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get points distributed on shape area with given pattern

virtual void get_triangles(const math::Triangle<2>::put_delegate_t &f, double resolution) const
-----------------------------------------------------------------------------------------------

This virtual function implements the `get_triangles (*note _1079::)'
pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get shape teselation triangles

shape::Round<shape::EllipseBase,false> internal class members
=============================================================

virtual void get_contour(unsigned int contour, const math::vector2::put_delegate_t &f, double resolution) const
---------------------------------------------------------------------------------------------------------------

This virtual function implements the `get_contour (*note _1074::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get contour polygone points for specified contour id. First contour
is always outter edge.

   See also get_contour_count (*note _1075::) function.

virtual unsigned int get_contour_count() const
----------------------------------------------

This virtual function implements the `get_contour_count (*note
_1075::)' pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get number of contours polygones. This function returns value is
greater than 1 if shape has hole(s).

   See also get_contour (*note _1074::) function.

virtual void get_pattern(const math::vector2::put_delegate_t &v, const trace::distribution &d, bool unobstructed) const
-----------------------------------------------------------------------------------------------------------------------

This virtual function overrides the `get_pattern (*note _1078::)'
virtual function defined in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get points distributed on shape area with given pattern

virtual void get_triangles(const math::Triangle<2>::put_delegate_t &f, double resolution) const
-----------------------------------------------------------------------------------------------

This virtual function implements the `get_triangles (*note _1079::)'
pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get shape teselation triangles

shape::Round<shape::EllipticalRingBase,true> internal class members
===================================================================

virtual void get_contour(unsigned int contour, const math::vector2::put_delegate_t &f, double resolution) const
---------------------------------------------------------------------------------------------------------------

This virtual function implements the `get_contour (*note _1074::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get contour polygone points for specified contour id. First contour
is always outter edge.

   See also get_contour_count (*note _1075::) function.

virtual unsigned int get_contour_count() const
----------------------------------------------

This virtual function implements the `get_contour_count (*note
_1075::)' pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get number of contours polygones. This function returns value is
greater than 1 if shape has hole(s).

   See also get_contour (*note _1074::) function.

virtual void get_pattern(const math::vector2::put_delegate_t &v, const trace::distribution &d, bool unobstructed) const
-----------------------------------------------------------------------------------------------------------------------

This virtual function overrides the `get_pattern (*note _1078::)'
virtual function defined in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get points distributed on shape area with given pattern

virtual void get_triangles(const math::Triangle<2>::put_delegate_t &f, double resolution) const
-----------------------------------------------------------------------------------------------

This virtual function implements the `get_triangles (*note _1079::)'
pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get shape teselation triangles

shape::Round<shape::RingBase,true> internal class members
=========================================================

virtual void get_contour(unsigned int contour, const math::vector2::put_delegate_t &f, double resolution) const
---------------------------------------------------------------------------------------------------------------

This virtual function implements the `get_contour (*note _1074::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get contour polygone points for specified contour id. First contour
is always outter edge.

   See also get_contour_count (*note _1075::) function.

virtual unsigned int get_contour_count() const
----------------------------------------------

This virtual function implements the `get_contour_count (*note
_1075::)' pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get number of contours polygones. This function returns value is
greater than 1 if shape has hole(s).

   See also get_contour (*note _1074::) function.

virtual void get_pattern(const math::vector2::put_delegate_t &v, const trace::distribution &d, bool unobstructed) const
-----------------------------------------------------------------------------------------------------------------------

This virtual function overrides the `get_pattern (*note _1078::)'
virtual function defined in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get points distributed on shape area with given pattern

virtual void get_triangles(const math::Triangle<2>::put_delegate_t &f, double resolution) const
-----------------------------------------------------------------------------------------------

This virtual function implements the `get_triangles (*note _1079::)'
pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get shape teselation triangles

shape::diskBase internal class members
======================================

double get_radius(void ) const
------------------------------

Get disk radius

void set_radius(double r)
-------------------------

Set disk radius

shape::EllipseBase internal class members
=========================================

virtual math::vectorPair2 get_bounding_box() const
--------------------------------------------------

This virtual function implements the `get_bounding_box (*note _1073::)'
pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get shape bounding box

virtual double get_outter_radius(const math::vector2 &dir) const
----------------------------------------------------------------

This virtual function implements the `get_outter_radius (*note
_1077::)' pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get distance between origin and farthest shape edge in specified
direction

double get_x_radius(void ) const
--------------------------------

Set ellipse radius along x axis

double get_y_radius(void ) const
--------------------------------

Set ellipse radius along y axis

virtual bool inside(const math::vector2 &point) const
-----------------------------------------------------

This virtual function implements the `inside (*note _1080::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Check if the (x,y) 2d point is inside 2d shape area

virtual double max_radius() const
---------------------------------

This virtual function implements the `max_radius (*note _1081::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get distance between origin and farthest shape edge

virtual double min_radius() const
---------------------------------

This virtual function implements the `min_radius (*note _1082::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get distance between origin and nearest shape outter edge

void set_radius(double xr, double yr)
-------------------------------------

Set ellipse radius along x and y axis

shape::EllipticalRingBase internal class members
================================================

virtual math::vectorPair2 get_bounding_box() const
--------------------------------------------------

This virtual function implements the `get_bounding_box (*note _1073::)'
pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get shape bounding box

virtual double get_hole_radius(const math::vector2 &dir) const
--------------------------------------------------------------

This virtual function overrides the `get_hole_radius (*note _1076::)'
virtual function defined in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get distance between origin and nearest shape outter edge in
specified direction

virtual double get_outter_radius(const math::vector2 &dir) const
----------------------------------------------------------------

This virtual function implements the `get_outter_radius (*note
_1077::)' pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get distance between origin and farthest shape edge in specified
direction

double get_x_hole_radius(void ) const
-------------------------------------

Get hole radius along the x axis

double get_x_radius(void ) const
--------------------------------

Get external ring radius along the x axis

double get_y_hole_radius(void ) const
-------------------------------------

Get hole radius along the y axis

double get_y_radius(void ) const
--------------------------------

Get external ring radius along the y axis

virtual bool inside(const math::vector2 &point) const
-----------------------------------------------------

This virtual function implements the `inside (*note _1080::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Check if the (x,y) 2d point is inside 2d shape area

virtual double max_radius() const
---------------------------------

This virtual function implements the `max_radius (*note _1081::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get distance between origin and farthest shape edge

virtual double min_radius() const
---------------------------------

This virtual function implements the `min_radius (*note _1082::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get distance between origin and nearest shape outter edge

void set_radius(double x_radius, double y_radius, double x_hole_radius)
-----------------------------------------------------------------------

Set external ring radius along the x and y axes and hole radius along
the x axis.

shape::RingBase internal class members
======================================

virtual math::vectorPair2 get_bounding_box() const
--------------------------------------------------

This virtual function implements the `get_bounding_box (*note _1073::)'
pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get shape bounding box

double get_hole_radius() const
------------------------------

Get hole radius

virtual double get_hole_radius(const math::vector2 &dir) const
--------------------------------------------------------------

This virtual function overrides the `get_hole_radius (*note _1076::)'
virtual function defined in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get distance between origin and nearest shape outter edge in
specified direction

virtual double get_outter_radius(const math::vector2 &dir) const
----------------------------------------------------------------

This virtual function implements the `get_outter_radius (*note
_1077::)' pure function declared in the `Base (*note
shape_Base_class_reference::)' base abstract class.

   Documentation inherited from base class:

   Get distance between origin and farthest shape edge in specified
direction

double get_radius() const
-------------------------

Get ring external radius

virtual bool inside(const math::vector2 &point) const
-----------------------------------------------------

This virtual function implements the `inside (*note _1080::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Check if the (x,y) 2d point is inside 2d shape area

virtual double max_radius() const
---------------------------------

This virtual function implements the `max_radius (*note _1081::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get distance between origin and farthest shape edge

virtual double min_radius() const
---------------------------------

This virtual function implements the `min_radius (*note _1082::)' pure
function declared in the `Base (*note shape_Base_class_reference::)'
base abstract class.

   Documentation inherited from base class:

   Get distance between origin and nearest shape outter edge

void set_radius(double radius, double hole_radius)
--------------------------------------------------

Set ring external radius and hole radius

shape::Round internal class members
===================================

void get_contour(unsigned int contour, const math::vector2::put_delegate_t &f, double resolution) const
-------------------------------------------------------------------------------------------------------

No documentation available

unsigned int get_contour_count() const
--------------------------------------

No documentation available

void get_pattern(const math::vector2::put_delegate_t &v, const trace::distribution &d, bool unobstructed) const
---------------------------------------------------------------------------------------------------------------

No documentation available

void get_triangles(const math::Triangle<2>::put_delegate_t &f, double resolution) const
---------------------------------------------------------------------------------------

No documentation available

sys namespace reference
=======================

Description
-----------

Optical system and components

Members
-------

Types
.....

   * class Group

   * class image

   * class Lens

   * class mirror

   * class OpticalSurface

   * class source_point

   * class SourceRays

   * class system

   * class Container

   * class Element

   * enum LensEdge

   * class Source

   * enum SourceInfinityMode

   * class Stop

   * class Surface

Functions
.........

   * std::ostream & operator<<(std::ostream &o, const Element &e)

   * std::ostream & operator<<(std::ostream &o, const Container &v)

Members detail
--------------

enum LensEdge
.............

Identifier             Description
-------------------------------------------------------------------------- 
StraightEdge           
SlopeEdge              

enum SourceInfinityMode
.......................

Specifies point source location mode

Identifier             Description
-------------------------------------------------------------------------- 
SourceAtFiniteDistance  In finite distance mode the point source is
                       located at specified position and all rays are
                       traced from this point.
SourceAtInfinity        In infinity mode the point source generate
                       parallel rays oriented along source direction
                       vector.

std:: ostream  & operator<<(std:: ostream  &o, const Element &e)
................................................................

No documentation available

std:: ostream  & operator<<(std:: ostream  &o, const Container &v)
..................................................................

No documentation available

sys::Group class reference
==========================

Declaration
-----------

     #include <goptical/core/sys/Group>

     namespace goptical {
       namespace sys {
         class Group;
       };
     };

   This class is a member of the sys namespace.

Inheritance
-----------

Description
-----------

This class is used to form a group of optical elements. A group is a
special kind of optical element which can contains other elements. A
group has its own local coordinate system.

   See also system hierarchy and groups (*note system hierarchy and
groups::) section.

Members
-------

See also the full member list (*note
sys_Group_class_full_member_list::) section for this class.

Inherited members
.................

   * 16 members inherited from Container (*note
     sys_Container_class_reference::)

   * 40 members inherited from Element (*note
     sys_Element_class_reference::)

Functions
.........

   * Group(const math::vectorPair3 &p)

   * virtual ~Group()

   * virtual math::vectorPair3 get_bounding_box() const

Members detail
--------------

Group(const math::vectorPair3 &p)
.................................

Create a new group at given position

virtual ~Group()
................

No documentation available

virtual math::vectorPair3 get_bounding_box() const
..................................................

This virtual function overrides the `get_bounding_box (*note _1288::)'
virtual function defined in the `Element (*note
sys_Element_class_reference::)' base class.

   Documentation inherited from base class:

   Get bounding box in local coordinates

sys::Group class full member list
=================================

Types
-----

   * typedef _ [...] _ element_list_t

   * typedef _ [...] _ mod_delegate_t

   * typedef _ [...] _ put_delegate_t

Functions
---------

   * Group(const math::vectorPair3 &p)

   * virtual ~Group()

   * void add(const ref<Element> &e)

   * template bool contains(const X *x) const

   * void draw_2d(io::Renderer &r) const

   * void draw_2d_fit(io::renderer_viewport &r, bool keep_aspect =
     _[...]_) const

   * void draw_3d(io::Renderer &r) const

   * void draw_3d_fit(io::renderer_viewport &r, double z_offset =
     _[...]_) const

   * template void enable_single(const X &e)

   * template X * find() const

   * virtual math::vectorPair3 get_bounding_box() const

   * math::vector3 get_direction(const Element &e) const

   * math::vector3 get_direction() const

   * const Container::element_list_t & get_element_list() const

   * template void get_elements(const delegate<void(const X&)> &d) const

   * template void get_elements(const delegate<void(X&)> &d)

   * const math::Transform<3> & get_global_transform() const

   * math::vector3 get_local_direction() const

   * math::vectorPair3 get_local_plane() const

   * const math::vector3 & get_local_position() const

   * const math::Transform<3> & get_local_transform() const

   * Group * get_parent() const

   * math::vectorPair3 get_plane() const

   * math::vectorPair3 get_plane(const Element &e) const

   * math::vector3 get_position(const Element &e) const

   * math::vector3 get_position() const

   * system * get_system() const

   * const math::Transform<3> & get_transform() const

   * const math::Transform<3> & get_transform_from(const Element &e)
     const

   * const math::Transform<3> & get_transform_from(const Element *e)
     const

   * const math::Transform<3> & get_transform_to(const Element &e) const

   * const math::Transform<3> & get_transform_to(const Element *e) const

   * unsigned int get_version() const

   * unsigned int id() const

   * bool is_enabled() const

   * virtual void print(std::ostream &o) const

   * template void process_rays(trace::Result &result,
     trace::rays_queue_t *input) const

   * void remove(Element &e)

   * void rotate(double x, double y, double z)

   * void set_direction(const math::vector3 &v)

   * void set_enable_state(bool enabled)

   * void set_local_direction(const math::vector3 &v)

   * void set_local_plane(const math::vectorPair3 &p)

   * void set_local_position(const math::vector3 &v)

   * void set_plane(const math::vectorPair3 &p)

   * void set_position(const math::vector3 &v)

   * void set_transform(const math::Transform<3> &t)

   * void update_version()

sys::image class reference
==========================

Declaration
-----------

     #include <goptical/core/sys/image>

     namespace goptical {
       namespace sys {
         class image;
       };
     };

   This class is a member of the sys namespace.

Inheritance
-----------

Description
-----------

image plane optical element

Members
-------

See also the full member list (*note
sys_image_class_full_member_list::) section for this class.

Inherited members
.................

   * 48 members inherited from Surface (*note
     sys_Surface_class_reference::)

Functions
.........

   * image(const math::vectorPair3 &position, const
     const_ref<curve::Base> &curve, const const_ref<shape::Base> &shape)

   * image(const math::vectorPair3 &position, double radius)

Members detail
--------------

image(const math::vectorPair3 &position, const  const_ref <curve::Base> &curve, const  const_ref <shape::Base> &shape)
......................................................................................................................

Create a new image plane at given position.

image(const math::vectorPair3 &position, double radius)
.......................................................

Create a new flat square image plane at given position with given half
width

sys::image class full member list
=================================

Types
-----

   * typedef _ [...] _ mod_delegate_t

   * typedef _ [...] _ put_delegate_t

Functions
---------

   * image(const math::vectorPair3 &position, const
     const_ref<curve::Base> &curve, const const_ref<shape::Base> &shape)

   * image(const math::vectorPair3 &position, double radius)

   * virtual math::vectorPair3 get_bounding_box() const

   * virtual io::rgb get_color(const io::Renderer &r) const

   * const curve::Base & get_curve() const

   * math::vector3 get_direction(const Element &e) const

   * math::vector3 get_direction() const

   * double get_discard_intensity() const

   * const math::Transform<3> & get_global_transform() const

   * math::vector3 get_local_direction() const

   * math::vectorPair3 get_local_plane() const

   * const math::vector3 & get_local_position() const

   * const math::Transform<3> & get_local_transform() const

   * Group * get_parent() const

   * void get_pattern(const math::vector3::put_delegate_t &f, const
     trace::distribution &d, bool unobstructed = _[...]_) const

   * math::vectorPair3 get_plane() const

   * math::vectorPair3 get_plane(const Element &e) const

   * math::vector3 get_position(const Element &e) const

   * math::vector3 get_position() const

   * const shape::Base & get_shape() const

   * system * get_system() const

   * const math::Transform<3> & get_transform() const

   * const math::Transform<3> & get_transform_from(const Element &e)
     const

   * const math::Transform<3> & get_transform_from(const Element *e)
     const

   * const math::Transform<3> & get_transform_to(const Element &e) const

   * const math::Transform<3> & get_transform_to(const Element *e) const

   * unsigned int get_version() const

   * unsigned int id() const

   * virtual bool intersect(const trace::params &params,
     math::vectorPair3 &pt, const math::vectorPair3 &ray) const

   * bool is_enabled() const

   * virtual void print(std::ostream &o) const

   * template void process_rays(trace::Result &result,
     trace::rays_queue_t *input) const

   * void rotate(double x, double y, double z)

   * void set_curve(const const_ref<curve::Base> &c)

   * void set_direction(const math::vector3 &v)

   * void set_discard_intensity(double intensity)

   * void set_enable_state(bool enabled)

   * void set_local_direction(const math::vector3 &v)

   * void set_local_plane(const math::vectorPair3 &p)

   * void set_local_position(const math::vector3 &v)

   * void set_plane(const math::vectorPair3 &p)

   * void set_position(const math::vector3 &v)

   * void set_shape(const const_ref<shape::Base> &s)

   * void set_transform(const math::Transform<3> &t)

   * template void trace_ray(trace::Result &result, trace::Ray
     &incident, const math::vectorPair3 &local, const math::vectorPair3
     &intersect) const

   * void update_version()

sys::Lens class reference
=========================

Declaration
-----------

     #include <goptical/core/sys/Lens>

     namespace goptical {
       namespace sys {
         class Lens;
       };
     };

   This class is a member of the sys namespace.

Inheritance
-----------

Description
-----------

This class is a group (*note sys_Group_class_reference::) of optical
surfaces (*note sys_OpticalSurface_class_reference::). It contains
functions to describe a lens or lens group component in a convenient
way.

   If material::none (*note _528::) is passed as material, it will be
replaced by system environement proxy (*note
material_Proxy_class_reference::) material when the optical surface
becomes part of a system (*note sys_system_class_reference::).

   See also The Lens component (*note The Lens component::) section.

Members
-------

See also the full member list (*note sys_Lens_class_full_member_list::)
section for this class.

Inherited members
.................

   * 51 members inherited from Group (*note sys_Group_class_reference::)

Functions
.........

   * Lens(const math::vectorPair3 &p, double offset = _[...]_, const
     const_ref<material::Base> &env = _[...]_)

   * Lens(const math::vectorPair3 &p, const const_ref<curve::Base>
     &curve0, const const_ref<shape::Base> &shape0, const
     const_ref<curve::Base> &curve1, const const_ref<shape::Base>
     &shape1, double thickness0, const const_ref<material::Base>
     &glass0, const const_ref<material::Base> &env = _[...]_)

   * Lens(const math::vectorPair3 &p, double roc0, double ap_radius0,
     double roc1, double ap_radius1, double thickness, const
     const_ref<material::Base> &glass0, const const_ref<material::Base>
     &env = _[...]_)

   * virtual ~Lens()

   * void add_stop(const const_ref<shape::Base> &shape, double
     thickness)

   * void add_stop(double ap_radius, double thickness)

   * unsigned int add_surface(const const_ref<curve::Base> &curve,
     const const_ref<shape::Base> &shape, double thickness = _[...]_,
     const const_ref<material::Base> &glass = _[...]_)

   * unsigned int add_surface(double roc, double ap_radius, double
     thickness = _[...]_, const const_ref<material::Base> &glass =
     _[...]_)

   * math::vectorPair3 get_exit_plane() const

   * const OpticalSurface & get_left_surface() const

   * OpticalSurface & get_left_surface()

   * const OpticalSurface & get_right_surface() const

   * OpticalSurface & get_right_surface()

   * const OpticalSurface & get_surface(unsigned int index) const

   * OpticalSurface & get_surface(unsigned int index)

   * double get_thickness(unsigned int index = _[...]_) const

   * void set_curve(const const_ref<curve::Base> &c, unsigned int index)

   * void set_glass_material(const const_ref<material::Base> &m,
     unsigned int index = _[...]_)

   * void set_left_curve(const const_ref<curve::Base> &c)

   * void set_left_material(const const_ref<material::Base> &m)

   * void set_right_curve(const const_ref<curve::Base> &c)

   * void set_right_material(const const_ref<material::Base> &m)

   * void set_shape(const const_ref<shape::Base> &s)

   * void set_shape(const const_ref<shape::Base> &s, unsigned int index)

   * void set_thickness(double thickness, unsigned int index = _[...]_)

Members detail
--------------

Lens(const math::vectorPair3 &p, double offset = 0., const  const_ref <material::Base> &env = material::none)
.............................................................................................................

Create an empty lens. Surfaces can be added with the add_surface (*note
_1206::) functions.

Lens(const math::vectorPair3 &p, const  const_ref <curve::Base> &curve0, const  const_ref <shape::Base> &shape0, const  const_ref <curve::Base> &curve1, const  const_ref <shape::Base> &shape1, double thickness0, const  const_ref <material::Base> &glass0, const  const_ref <material::Base> &env = material::none)
.......................................................................................................................................................................................................................................................................................................................

Create a lens at given position with given thickness, shapes,
curvatures and glass.

   See also add_surface (*note _1206::) function.

Lens(const math::vectorPair3 &p, double roc0, double ap_radius0, double roc1, double ap_radius1, double thickness, const  const_ref <material::Base> &glass0, const  const_ref <material::Base> &env = material::none)
......................................................................................................................................................................................................................

Create a circular lens with flat or spherical surfaces at given
position with given thickness, radius of curvature, aperture radius and
glass.

   See also add_surface (*note _1207::) function.

virtual ~Lens()
...............

No documentation available

void add_stop(const  const_ref <shape::Base> &shape, double thickness)
......................................................................

Add an aperture stop with given, shape and thickness.

void add_stop(double ap_radius, double thickness)
.................................................

Add an aperture stop with circular aperture.

   Parameters list:

   * radius: circular aperture radius.

   * thickness: distance to the next stop or exit plane. .

unsigned int add_surface(const  const_ref <curve::Base> &curve, const  const_ref <shape::Base> &shape, double thickness = 0., const  const_ref <material::Base> &glass = material::none)
........................................................................................................................................................................................

Add an optical surface with given curve, shape, thickness and material.

unsigned int add_surface(double roc, double ap_radius, double thickness = 0., const  const_ref <material::Base> &glass = material::none)
........................................................................................................................................

Add a spherical or flat optical surface with circular aperture.

   Parameters list:

   * roc: spherical radius of curvature. 0 means flat curve.

   * ap_radius: circular aperture radius.

   * thickness: distance to the next surface or exit plane. .

   * glass: material between added surface and next surface.

math::vectorPair3 get_exit_plane() const
........................................

Get plane of last surface + thickness z offset

const OpticalSurface & get_left_surface() const
...............................................

Get a reference to left optical surface element

OpticalSurface & get_left_surface()
...................................

Get a reference to left optical surface element

const OpticalSurface & get_right_surface() const
................................................

Get a reference to right optical surface element

OpticalSurface & get_right_surface()
....................................

Get a reference to right optical surface element

const OpticalSurface & get_surface(unsigned int index) const
............................................................

Get a reference to optical surface at given index

OpticalSurface & get_surface(unsigned int index)
................................................

Get a reference to optical surface at given index

double get_thickness(unsigned int index = 0) const
..................................................

Get thickness between two surfaces

void set_curve(const  const_ref <curve::Base> &c, unsigned int index)
.....................................................................

Set curve of given surface index

void set_glass_material(const  const_ref <material::Base> &m, unsigned int index = 0)
.....................................................................................

Set glass material

void set_left_curve(const  const_ref <curve::Base> &c)
......................................................

Set left curve

void set_left_material(const  const_ref <material::Base> &m)
............................................................

Set left material

void set_right_curve(const  const_ref <curve::Base> &c)
.......................................................

Set right curve

void set_right_material(const  const_ref <material::Base> &m)
.............................................................

Set left material

void set_shape(const  const_ref <shape::Base> &s)
.................................................

Set lens shape (all surfaces)

void set_shape(const  const_ref <shape::Base> &s, unsigned int index)
.....................................................................

Set lens shape of given surface index

void set_thickness(double thickness, unsigned int index = 0)
............................................................

Adjust thickness between two surfaces

sys::Lens class full member list
================================

Types
-----

   * typedef _ [...] _ element_list_t

   * typedef _ [...] _ mod_delegate_t

   * typedef _ [...] _ put_delegate_t

Functions
---------

   * Lens(const math::vectorPair3 &p, double offset = _[...]_, const
     const_ref<material::Base> &env = _[...]_)

   * Lens(const math::vectorPair3 &p, const const_ref<curve::Base>
     &curve0, const const_ref<shape::Base> &shape0, const
     const_ref<curve::Base> &curve1, const const_ref<shape::Base>
     &shape1, double thickness0, const const_ref<material::Base>
     &glass0, const const_ref<material::Base> &env = _[...]_)

   * Lens(const math::vectorPair3 &p, double roc0, double ap_radius0,
     double roc1, double ap_radius1, double thickness, const
     const_ref<material::Base> &glass0, const const_ref<material::Base>
     &env = _[...]_)

   * virtual ~Lens()

   * void add_stop(const const_ref<shape::Base> &shape, double
     thickness)

   * void add_stop(double ap_radius, double thickness)

   * unsigned int add_surface(const const_ref<curve::Base> &curve,
     const const_ref<shape::Base> &shape, double thickness = _[...]_,
     const const_ref<material::Base> &glass = _[...]_)

   * unsigned int add_surface(double roc, double ap_radius, double
     thickness = _[...]_, const const_ref<material::Base> &glass =
     _[...]_)

   * template bool contains(const X *x) const

   * void draw_2d(io::Renderer &r) const

   * void draw_2d_fit(io::renderer_viewport &r, bool keep_aspect =
     _[...]_) const

   * void draw_3d(io::Renderer &r) const

   * void draw_3d_fit(io::renderer_viewport &r, double z_offset =
     _[...]_) const

   * template void enable_single(const X &e)

   * template X * find() const

   * virtual math::vectorPair3 get_bounding_box() const

   * math::vector3 get_direction(const Element &e) const

   * math::vector3 get_direction() const

   * const Container::element_list_t & get_element_list() const

   * template void get_elements(const delegate<void(const X&)> &d) const

   * template void get_elements(const delegate<void(X&)> &d)

   * math::vectorPair3 get_exit_plane() const

   * const math::Transform<3> & get_global_transform() const

   * const OpticalSurface & get_left_surface() const

   * OpticalSurface & get_left_surface()

   * math::vector3 get_local_direction() const

   * math::vectorPair3 get_local_plane() const

   * const math::vector3 & get_local_position() const

   * const math::Transform<3> & get_local_transform() const

   * Group * get_parent() const

   * math::vectorPair3 get_plane() const

   * math::vectorPair3 get_plane(const Element &e) const

   * math::vector3 get_position(const Element &e) const

   * math::vector3 get_position() const

   * const OpticalSurface & get_right_surface() const

   * OpticalSurface & get_right_surface()

   * const OpticalSurface & get_surface(unsigned int index) const

   * OpticalSurface & get_surface(unsigned int index)

   * system * get_system() const

   * double get_thickness(unsigned int index = _[...]_) const

   * const math::Transform<3> & get_transform() const

   * const math::Transform<3> & get_transform_from(const Element &e)
     const

   * const math::Transform<3> & get_transform_from(const Element *e)
     const

   * const math::Transform<3> & get_transform_to(const Element &e) const

   * const math::Transform<3> & get_transform_to(const Element *e) const

   * unsigned int get_version() const

   * unsigned int id() const

   * bool is_enabled() const

   * virtual void print(std::ostream &o) const

   * template void process_rays(trace::Result &result,
     trace::rays_queue_t *input) const

   * void rotate(double x, double y, double z)

   * void set_curve(const const_ref<curve::Base> &c, unsigned int index)

   * void set_direction(const math::vector3 &v)

   * void set_enable_state(bool enabled)

   * void set_glass_material(const const_ref<material::Base> &m,
     unsigned int index = _[...]_)

   * void set_left_curve(const const_ref<curve::Base> &c)

   * void set_left_material(const const_ref<material::Base> &m)

   * void set_local_direction(const math::vector3 &v)

   * void set_local_plane(const math::vectorPair3 &p)

   * void set_local_position(const math::vector3 &v)

   * void set_plane(const math::vectorPair3 &p)

   * void set_position(const math::vector3 &v)

   * void set_right_curve(const const_ref<curve::Base> &c)

   * void set_right_material(const const_ref<material::Base> &m)

   * void set_shape(const const_ref<shape::Base> &s)

   * void set_shape(const const_ref<shape::Base> &s, unsigned int index)

   * void set_thickness(double thickness, unsigned int index = _[...]_)

   * void set_transform(const math::Transform<3> &t)

   * void update_version()

sys::mirror class reference
===========================

Declaration
-----------

     #include <goptical/core/sys/mirror>

     namespace goptical {
       namespace sys {
         class mirror;
       };
     };

   This class is a member of the sys namespace.

Inheritance
-----------

Description
-----------

This class provide a convenient way to describe a reflecting optical
surface. light is reflected only on 1 side of the surface.

Members
-------

See also the full member list (*note
sys_mirror_class_full_member_list::) section for this class.

Inherited members
.................

   * 51 members inherited from OpticalSurface (*note
     sys_OpticalSurface_class_reference::)

Functions
.........

   * mirror(const math::vectorPair3 &p, const const_ref<curve::Base>
     &curve, const const_ref<shape::Base> &shape, bool light_from_left
     = _[...]_, const const_ref<material::Base> &metal = _[...]_, const
     const_ref<material::Base> &env = _[...]_)

   * mirror(const math::vectorPair3 &p, const const_ref<curve::Base>
     &curve, double ap_radius, bool light_from_left = _[...]_, const
     const_ref<material::Base> &metal = _[...]_, const
     const_ref<material::Base> &env = _[...]_)

   * mirror(const math::vectorPair3 &p, double roc, double sc, double
     ap_radius, bool light_from_left = _[...]_, const
     const_ref<material::Base> &metal = _[...]_, const
     const_ref<material::Base> &env = _[...]_)

Members detail
--------------

mirror(const math::vectorPair3 &p, const  const_ref <curve::Base> &curve, const  const_ref <shape::Base> &shape, bool light_from_left = true, const  const_ref <material::Base> &metal = material::mirror, const  const_ref <material::Base> &env = material::none)
...................................................................................................................................................................................................................................................................

Create a mirror at given position with given shape and curve. Default
is to reflect light coming from left using material::mirror (*note
_527::) material.

mirror(const math::vectorPair3 &p, const  const_ref <curve::Base> &curve, double ap_radius, bool light_from_left = true, const  const_ref <material::Base> &metal = material::mirror, const  const_ref <material::Base> &env = material::none)
..............................................................................................................................................................................................................................................

Create a circular aperture mirror at given position with given curve.
Default is to reflect light coming from left using material::mirror
(*note _527::) material.

mirror(const math::vectorPair3 &p, double roc, double sc, double ap_radius, bool light_from_left = true, const  const_ref <material::Base> &metal = material::mirror, const  const_ref <material::Base> &env = material::none)
..............................................................................................................................................................................................................................

Create a conic mirror with circular aperture at given position. Default
is to reflect light coming from left using material::mirror (*note
_527::) material.

sys::mirror class full member list
==================================

Types
-----

   * typedef _ [...] _ mod_delegate_t

   * typedef _ [...] _ put_delegate_t

Functions
---------

   * mirror(const math::vectorPair3 &p, const const_ref<curve::Base>
     &curve, const const_ref<shape::Base> &shape, bool light_from_left
     = _[...]_, const const_ref<material::Base> &metal = _[...]_, const
     const_ref<material::Base> &env = _[...]_)

   * mirror(const math::vectorPair3 &p, const const_ref<curve::Base>
     &curve, double ap_radius, bool light_from_left = _[...]_, const
     const_ref<material::Base> &metal = _[...]_, const
     const_ref<material::Base> &env = _[...]_)

   * mirror(const math::vectorPair3 &p, double roc, double sc, double
     ap_radius, bool light_from_left = _[...]_, const
     const_ref<material::Base> &metal = _[...]_, const
     const_ref<material::Base> &env = _[...]_)

   * virtual math::vectorPair3 get_bounding_box() const

   * virtual io::rgb get_color(const io::Renderer &r) const

   * const curve::Base & get_curve() const

   * math::vector3 get_direction(const Element &e) const

   * math::vector3 get_direction() const

   * double get_discard_intensity() const

   * const math::Transform<3> & get_global_transform() const

   * math::vector3 get_local_direction() const

   * math::vectorPair3 get_local_plane() const

   * const math::vector3 & get_local_position() const

   * const math::Transform<3> & get_local_transform() const

   * const material::Base & get_material(unsigned int id) const

   * Group * get_parent() const

   * void get_pattern(const math::vector3::put_delegate_t &f, const
     trace::distribution &d, bool unobstructed = _[...]_) const

   * math::vectorPair3 get_plane() const

   * math::vectorPair3 get_plane(const Element &e) const

   * math::vector3 get_position(const Element &e) const

   * math::vector3 get_position() const

   * const shape::Base & get_shape() const

   * system * get_system() const

   * const math::Transform<3> & get_transform() const

   * const math::Transform<3> & get_transform_from(const Element &e)
     const

   * const math::Transform<3> & get_transform_from(const Element *e)
     const

   * const math::Transform<3> & get_transform_to(const Element &e) const

   * const math::Transform<3> & get_transform_to(const Element *e) const

   * unsigned int get_version() const

   * unsigned int id() const

   * virtual bool intersect(const trace::params &params,
     math::vectorPair3 &pt, const math::vectorPair3 &ray) const

   * bool is_enabled() const

   * template void process_rays(trace::Result &result,
     trace::rays_queue_t *input) const

   * void rotate(double x, double y, double z)

   * void set_curve(const const_ref<curve::Base> &c)

   * void set_direction(const math::vector3 &v)

   * void set_discard_intensity(double intensity)

   * void set_enable_state(bool enabled)

   * void set_local_direction(const math::vector3 &v)

   * void set_local_plane(const math::vectorPair3 &p)

   * void set_local_position(const math::vector3 &v)

   * void set_material(unsigned int index, const
     const_ref<material::Base> &m)

   * void set_plane(const math::vectorPair3 &p)

   * void set_position(const math::vector3 &v)

   * void set_shape(const const_ref<shape::Base> &s)

   * void set_transform(const math::Transform<3> &t)

   * template void trace_ray(trace::Result &result, trace::Ray
     &incident, const math::vectorPair3 &local, const math::vectorPair3
     &intersect) const

   * void update_version()

sys::OpticalSurface class reference
===================================

Declaration
-----------

     #include <goptical/core/sys/OpticalSurface>

     namespace goptical {
       namespace sys {
         class OpticalSurface;
       };
     };

   This class is a member of the sys namespace.

Inheritance
-----------

Description
-----------

This class implements optical surfaces.

   Optical surfaces are defined by material on both side of the
surface, curve and contour shape. This class handle light rays
refraction and reflection.

   If material::none (*note _528::) is passed as material, it will be
replaced by system environement proxy (*note
material_Proxy_class_reference::) material when the optical surface
becomes part of a system (*note sys_system_class_reference::).

Members
-------

See also the full member list (*note
sys_OpticalSurface_class_full_member_list::) section for this class.

Inherited members
.................

   * 48 members inherited from Surface (*note
     sys_Surface_class_reference::)

Functions
.........

   * OpticalSurface(const math::vectorPair3 &p, const
     const_ref<curve::Base> &curve, const const_ref<shape::Base>
     &shape, const const_ref<material::Base> &left, const
     const_ref<material::Base> &right)

   * OpticalSurface(const math::vectorPair3 &p, const
     const_ref<curve::Base> &curve, double ap_radius, const
     const_ref<material::Base> &left, const const_ref<material::Base>
     &right)

   * OpticalSurface(const math::vectorPair3 &p, double roc, double
     ap_radius, const const_ref<material::Base> &left, const
     const_ref<material::Base> &right)

   * virtual ~OpticalSurface()

   * virtual io::rgb get_color(const io::Renderer &r) const

   * const material::Base & get_material(unsigned int id) const

   * void set_material(unsigned int index, const
     const_ref<material::Base> &m)

Members detail
--------------

OpticalSurface(const math::vectorPair3 &p, const  const_ref <curve::Base> &curve, const  const_ref <shape::Base> &shape, const  const_ref <material::Base> &left, const  const_ref <material::Base> &right)
...........................................................................................................................................................................................................

Create an optical surface at specified location.

OpticalSurface(const math::vectorPair3 &p, const  const_ref <curve::Base> &curve, double ap_radius, const  const_ref <material::Base> &left, const  const_ref <material::Base> &right)
......................................................................................................................................................................................

Create a circular aperture optical surface at specified location.

   * ap_radius: circular aperture radius.

OpticalSurface(const math::vectorPair3 &p, double roc, double ap_radius, const  const_ref <material::Base> &left, const  const_ref <material::Base> &right)
...........................................................................................................................................................

Create a spherical optical surface with circular aperture at specified
location.

   * roc: spherical radius of curvature. 0 means flat curve.

   * ap_radius: circular aperture radius.

virtual ~OpticalSurface()
.........................

No documentation available

virtual io::rgb get_color(const io::Renderer &r) const
......................................................

This virtual function overrides the `get_color (*note _1343::)' virtual
function defined in the `Surface (*note sys_Surface_class_reference::)'
base class.

   Get surface natural color from material properties.

const material::Base & get_material(unsigned int id) const
..........................................................

Get surface left or right material

void set_material(unsigned int index, const  const_ref <material::Base> &m)
...........................................................................

Set surface left or right material

sys::OpticalSurface class full member list
==========================================

Types
-----

   * typedef _ [...] _ mod_delegate_t

   * typedef _ [...] _ put_delegate_t

Functions
---------

   * OpticalSurface(const math::vectorPair3 &p, const
     const_ref<curve::Base> &curve, const const_ref<shape::Base>
     &shape, const const_ref<material::Base> &left, const
     const_ref<material::Base> &right)

   * OpticalSurface(const math::vectorPair3 &p, const
     const_ref<curve::Base> &curve, double ap_radius, const
     const_ref<material::Base> &left, const const_ref<material::Base>
     &right)

   * OpticalSurface(const math::vectorPair3 &p, double roc, double
     ap_radius, const const_ref<material::Base> &left, const
     const_ref<material::Base> &right)

   * virtual ~OpticalSurface()

   * virtual math::vectorPair3 get_bounding_box() const

   * virtual io::rgb get_color(const io::Renderer &r) const

   * const curve::Base & get_curve() const

   * math::vector3 get_direction(const Element &e) const

   * math::vector3 get_direction() const

   * double get_discard_intensity() const

   * const math::Transform<3> & get_global_transform() const

   * math::vector3 get_local_direction() const

   * math::vectorPair3 get_local_plane() const

   * const math::vector3 & get_local_position() const

   * const math::Transform<3> & get_local_transform() const

   * const material::Base & get_material(unsigned int id) const

   * Group * get_parent() const

   * void get_pattern(const math::vector3::put_delegate_t &f, const
     trace::distribution &d, bool unobstructed = _[...]_) const

   * math::vectorPair3 get_plane() const

   * math::vectorPair3 get_plane(const Element &e) const

   * math::vector3 get_position(const Element &e) const

   * math::vector3 get_position() const

   * const shape::Base & get_shape() const

   * system * get_system() const

   * const math::Transform<3> & get_transform() const

   * const math::Transform<3> & get_transform_from(const Element &e)
     const

   * const math::Transform<3> & get_transform_from(const Element *e)
     const

   * const math::Transform<3> & get_transform_to(const Element &e) const

   * const math::Transform<3> & get_transform_to(const Element *e) const

   * unsigned int get_version() const

   * unsigned int id() const

   * virtual bool intersect(const trace::params &params,
     math::vectorPair3 &pt, const math::vectorPair3 &ray) const

   * bool is_enabled() const

   * template void process_rays(trace::Result &result,
     trace::rays_queue_t *input) const

   * void rotate(double x, double y, double z)

   * void set_curve(const const_ref<curve::Base> &c)

   * void set_direction(const math::vector3 &v)

   * void set_discard_intensity(double intensity)

   * void set_enable_state(bool enabled)

   * void set_local_direction(const math::vector3 &v)

   * void set_local_plane(const math::vectorPair3 &p)

   * void set_local_position(const math::vector3 &v)

   * void set_material(unsigned int index, const
     const_ref<material::Base> &m)

   * void set_plane(const math::vectorPair3 &p)

   * void set_position(const math::vector3 &v)

   * void set_shape(const const_ref<shape::Base> &s)

   * void set_transform(const math::Transform<3> &t)

   * template void trace_ray(trace::Result &result, trace::Ray
     &incident, const math::vectorPair3 &local, const math::vectorPair3
     &intersect) const

   * void update_version()

sys::source_point class reference
================================

Declaration
-----------

     #include <goptical/core/sys/source_point>

     namespace goptical {
       namespace sys {
         class source_point;
       };
     };

   This class is a member of the sys namespace.

Inheritance
-----------

Description
-----------

This class implement a point light source. The source can either be
infinitely far away with a direction vector, or located at a given
position but without direction.

   A ray is generated for each defined spectrum line for each
distribution pattern point on target surface.

   Default wavelen list contains a single 550nm entry.

Members
-------

See also the full member list (*note
sys_source_point_class_full_member_list::) section for this class.

Inherited members
.................

   * 48 members inherited from Source (*note
     sys_Source_class_reference::)

Functions
.........

   * source_point(SourceInfinityMode m, const math::vector3 &pos_dir)

   * void set_infinity_direction(const math::vector3 &dir)

   * void set_mode(SourceInfinityMode mode)

   * void set_position(const math::vector3 &pos)

Members detail
--------------

source_point(SourceInfinityMode m, const math::vector3 &pos_dir)
...............................................................

Create a point source with given mode. A direction vector must be
provided when source is in infinity mode. If not in infinity mode, a
position vector must be provided instead.

void set_infinity_direction(const math::vector3 &dir)
.....................................................

Set point source mode to infinity and adjust source direction vector

void set_mode(SourceInfinityMode mode)
......................................

Change current point source infinity mode

void set_position(const math::vector3 &pos)
...........................................

This function shadows the `set_position (*note _1321::)' function
defined in the `Element (*note sys_Element_class_reference::)' base
class.

   Set point source mode to positioned and adjust source position vector

sys::source_point class full member list
=======================================

Types
-----

   * typedef _ [...] _ mod_delegate_t

   * typedef _ [...] _ put_delegate_t

   * typedef _ [...] _ targets_t

Functions
---------

   * source_point(SourceInfinityMode m, const math::vector3 &pos_dir)

   * void add_spectral_line(const light::SpectralLine &l)

   * void clear_spectrum()

   * virtual void draw_2d_e(io::Renderer &r, const Element *ref) const

   * virtual void draw_3d_e(io::Renderer &r, const Element *ref) const

   * template void generate_rays(trace::Result &result, const
     Source::targets_t &entry) const

   * virtual math::vectorPair3 get_bounding_box() const

   * math::vector3 get_direction(const Element &e) const

   * math::vector3 get_direction() const

   * const math::Transform<3> & get_global_transform() const

   * math::vector3 get_local_direction() const

   * math::vectorPair3 get_local_plane() const

   * const math::vector3 & get_local_position() const

   * const math::Transform<3> & get_local_transform() const

   * double get_max_intensity() const

   * double get_min_intensity() const

   * Group * get_parent() const

   * math::vectorPair3 get_plane() const

   * math::vectorPair3 get_plane(const Element &e) const

   * math::vector3 get_position(const Element &e) const

   * math::vector3 get_position() const

   * system * get_system() const

   * const math::Transform<3> & get_transform() const

   * const math::Transform<3> & get_transform_from(const Element &e)
     const

   * const math::Transform<3> & get_transform_from(const Element *e)
     const

   * const math::Transform<3> & get_transform_to(const Element &e) const

   * const math::Transform<3> & get_transform_to(const Element *e) const

   * unsigned int get_version() const

   * unsigned int id() const

   * bool is_enabled() const

   * virtual void print(std::ostream &o) const

   * template void process_rays(trace::Result &result,
     trace::rays_queue_t *input) const

   * void rotate(double x, double y, double z)

   * void set_direction(const math::vector3 &v)

   * void set_enable_state(bool enabled)

   * void set_infinity_direction(const math::vector3 &dir)

   * void set_local_direction(const math::vector3 &v)

   * void set_local_plane(const math::vectorPair3 &p)

   * void set_local_position(const math::vector3 &v)

   * void set_material(const const_ref<material::Base> &m)

   * void set_mode(SourceInfinityMode mode)

   * void set_plane(const math::vectorPair3 &p)

   * void set_position(const math::vector3 &pos)

   * void set_spectral_line(const light::SpectralLine &l, int index =
     _[...]_)

   * void set_transform(const math::Transform<3> &t)

   * void single_spectral_line(const light::SpectralLine &l)

   * void update_version()

sys::SourceRays class reference
===============================

Declaration
-----------

     #include <goptical/core/sys/SourceRays>

     namespace goptical {
       namespace sys {
         class SourceRays;
       };
     };

   This class is a member of the sys namespace.

Inheritance
-----------

Description
-----------

This class implement a light source which generates user defined rays.

   Default wavelen list contains a single 550nm entry.

Members
-------

See also the full member list (*note
sys_SourceRays_class_full_member_list::) section for this class.

Inherited members
.................

   * 48 members inherited from Source (*note
     sys_Source_class_reference::)

Functions
.........

   * SourceRays(const math::vector3 &object = _[...]_)

   * void add_chief_rays(const system &sys)

   * void add_chief_rays(const Surface &s)

   * void add_marginal_rays(const system &sys, double entrance_height =
     _[...]_)

   * void add_marginal_rays(const Surface &s, double entrance_height =
     _[...]_)

   * void add_ray(const light::Ray &ray, const Element *ref = _[...]_)

   * void add_rays(const math::vectorPair3 &ray, const Element *ref =
     _[...]_)

   * void clear_rays()

Members detail
--------------

SourceRays(const math::vector3 &object = math::vector3_0)
.........................................................

Create a rays source. Source object position is used by some of the
`add_*' functions and may be specified.

void add_chief_rays(const system &sys)
......................................

Add chief rays to system entrance pupil for all defined wavelengths.

void add_chief_rays(const Surface &s)
.....................................

Add chief rays to specified surface for all defined wavelengths.

void add_marginal_rays(const system &sys, double entrance_height = 0.)
......................................................................

Add marginal rays to system entrance pupil for all defined wavelengths.

   See also add_marginal_rays (*note _1243::) function.

void add_marginal_rays(const Surface &s, double entrance_height = 0.)
.....................................................................

Add marginal rays to specified surface for all defined wavelengths.

   Source direction (rotation) is used to determine tangential plane.

   Entrance height is set to surface aperture radius when 0.

void add_ray(const light::Ray &ray, const Element *ref = 0)
...........................................................

Add a single light ray; rays properties are copied from specified light
ray.

   Ray origin and direction are expressed in specified `ref' element
coordinates or global coordinates if none is specified.

void add_rays(const math::vectorPair3 &ray, const Element *ref = 0)
...................................................................

Creates light rays from position and direction for all defined
wavelengths.

   Ray origin and direction are expressed in specified `ref' element
coordinates or global coordinates if none is specified.

void clear_rays()
.................

Discard all defined rays

sys::SourceRays class full member list
======================================

Types
-----

   * typedef _ [...] _ mod_delegate_t

   * typedef _ [...] _ put_delegate_t

   * typedef _ [...] _ targets_t

Functions
---------

   * SourceRays(const math::vector3 &object = _[...]_)

   * void add_chief_rays(const system &sys)

   * void add_chief_rays(const Surface &s)

   * void add_marginal_rays(const system &sys, double entrance_height =
     _[...]_)

   * void add_marginal_rays(const Surface &s, double entrance_height =
     _[...]_)

   * void add_ray(const light::Ray &ray, const Element *ref = _[...]_)

   * void add_rays(const math::vectorPair3 &ray, const Element *ref =
     _[...]_)

   * void add_spectral_line(const light::SpectralLine &l)

   * void clear_rays()

   * void clear_spectrum()

   * virtual void draw_2d_e(io::Renderer &r, const Element *ref) const

   * virtual void draw_3d_e(io::Renderer &r, const Element *ref) const

   * template void generate_rays(trace::Result &result, const
     Source::targets_t &entry) const

   * virtual math::vectorPair3 get_bounding_box() const

   * math::vector3 get_direction(const Element &e) const

   * math::vector3 get_direction() const

   * const math::Transform<3> & get_global_transform() const

   * math::vector3 get_local_direction() const

   * math::vectorPair3 get_local_plane() const

   * const math::vector3 & get_local_position() const

   * const math::Transform<3> & get_local_transform() const

   * double get_max_intensity() const

   * double get_min_intensity() const

   * Group * get_parent() const

   * math::vectorPair3 get_plane() const

   * math::vectorPair3 get_plane(const Element &e) const

   * math::vector3 get_position(const Element &e) const

   * math::vector3 get_position() const

   * system * get_system() const

   * const math::Transform<3> & get_transform() const

   * const math::Transform<3> & get_transform_from(const Element &e)
     const

   * const math::Transform<3> & get_transform_from(const Element *e)
     const

   * const math::Transform<3> & get_transform_to(const Element &e) const

   * const math::Transform<3> & get_transform_to(const Element *e) const

   * unsigned int get_version() const

   * unsigned int id() const

   * bool is_enabled() const

   * virtual void print(std::ostream &o) const

   * template void process_rays(trace::Result &result,
     trace::rays_queue_t *input) const

   * void rotate(double x, double y, double z)

   * void set_direction(const math::vector3 &v)

   * void set_enable_state(bool enabled)

   * void set_local_direction(const math::vector3 &v)

   * void set_local_plane(const math::vectorPair3 &p)

   * void set_local_position(const math::vector3 &v)

   * void set_material(const const_ref<material::Base> &m)

   * void set_plane(const math::vectorPair3 &p)

   * void set_position(const math::vector3 &v)

   * void set_spectral_line(const light::SpectralLine &l, int index =
     _[...]_)

   * void set_transform(const math::Transform<3> &t)

   * void single_spectral_line(const light::SpectralLine &l)

   * void update_version()

sys::system class reference
===========================

Declaration
-----------

     #include <goptical/core/sys/system>

     namespace goptical {
       namespace sys {
         class system;
       };
     };

   This class is a member of the sys namespace.

Inheritance
-----------

Description
-----------

This class is used to describe an optical system. Any optical element
(*note sys_Element_class_reference::) may be part of a system. This
class handle 3d transformation between elements local coordinates.

   See also Building the optical system (*note Building the optical
system::) section.

Members
-------

See also the full member list (*note
sys_system_class_full_member_list::) section for this class.

Inherited members
.................

   * 16 members inherited from Container (*note
     sys_Container_class_reference::)

Functions
.........

   * system()

   * virtual ~system()

   * Surface * colide_next(const trace::params &params,
     math::vectorPair3 &intersect, const trace::Ray &ray) const

   * Element & get_element(unsigned int index) const

   * unsigned int get_element_count() const

   * const Surface & get_entrance_pupil() const

   * const material::Base & get_environment() const

   * const Surface & get_exit_pupil() const

   * const math::Transform<3> & get_global_transform(const Element
     &from) const

   * const math::Transform<3> & get_local_transform(const Element &to)
     const

   * const trace::params & get_tracer_params() const

   * trace::params & get_tracer_params()

   * const math::Transform<3> & get_transform(const Element &from,
     const Element &to) const

   * unsigned int get_version() const

   * bool has_entrance_pupil() const

   * bool has_exit_pupil() const

   * void set_entrance_pupil(const const_ref<Surface> &entrance)

   * void set_environment(const const_ref<material::Base> &env)

   * void set_exit_pupil(const const_ref<Surface> &exit)

   * void undef_entrance_pupil()

   * void update_version()

Members detail
--------------

system()
........

Create a new empty system.

virtual ~system()
.................

No documentation available

Surface * colide_next(const trace::params &params, math::vectorPair3 &intersect, const trace::Ray &ray) const
.............................................................................................................

Find surface which colides with the given ray and update intersection
point

Element & get_element(unsigned int index) const
...............................................

Get registered element. first element has index 1

unsigned int get_element_count() const
......................................

Get the number of registered elements in the system

const Surface & get_entrance_pupil() const
..........................................

Get defined entrance pupil surface or try to guess it if none defined

const material::Base & get_environment() const
..............................................

get environment material

const Surface & get_exit_pupil() const
......................................

Get exit pupil

const math::Transform<3> & get_global_transform(const Element &from) const
..........................................................................

Get transform from element local to global coordinates

const math::Transform<3> & get_local_transform(const Element &to) const
.......................................................................

Get transform from global to element local coordinates

const trace::params & get_tracer_params() const
...............................................

Get default tracer parameters

trace::params & get_tracer_params()
...................................

Get default tracer parameters

const math::Transform<3> & get_transform(const Element &from, const Element &to) const
......................................................................................

Get transform between two elements local coordinates

unsigned int get_version() const
................................

Get system version. version is updated each time system or associated
elements properties are changed

bool has_entrance_pupil() const
...............................

Test if an entrance pupil has been defined

bool has_exit_pupil() const
...........................

Test if an exit pupil has been defined

void set_entrance_pupil(const  const_ref <Surface> &entrance)
.............................................................

Define an entrance pupil surface used to project source rays

void set_environment(const  const_ref <material::Base> &env)
............................................................

set environment material

void set_exit_pupil(const  const_ref <Surface> &exit)
.....................................................

Define an exit pupil surface

void undef_entrance_pupil()
...........................

Discard defined entrance pupil

void update_version()
.....................

Increase current system version

sys::system class full member list
==================================

Type
----

   * typedef _ [...] _ element_list_t

Functions
---------

   * system()

   * virtual ~system()

   * void add(const ref<Element> &e)

   * Surface * colide_next(const trace::params &params,
     math::vectorPair3 &intersect, const trace::Ray &ray) const

   * template bool contains(const X *x) const

   * void draw_2d(io::Renderer &r) const

   * void draw_2d_fit(io::renderer_viewport &r, bool keep_aspect =
     _[...]_) const

   * void draw_3d(io::Renderer &r) const

   * void draw_3d_fit(io::renderer_viewport &r, double z_offset =
     _[...]_) const

   * template void enable_single(const X &e)

   * template X * find() const

   * math::vectorPair3 get_bounding_box() const

   * Element & get_element(unsigned int index) const

   * unsigned int get_element_count() const

   * const Container::element_list_t & get_element_list() const

   * template void get_elements(const delegate<void(const X&)> &d) const

   * template void get_elements(const delegate<void(X&)> &d)

   * const Surface & get_entrance_pupil() const

   * const material::Base & get_environment() const

   * const Surface & get_exit_pupil() const

   * const math::Transform<3> & get_global_transform(const Element
     &from) const

   * const math::Transform<3> & get_local_transform(const Element &to)
     const

   * const trace::params & get_tracer_params() const

   * trace::params & get_tracer_params()

   * const math::Transform<3> & get_transform(const Element &from,
     const Element &to) const

   * unsigned int get_version() const

   * bool has_entrance_pupil() const

   * bool has_exit_pupil() const

   * void remove(Element &e)

   * void set_entrance_pupil(const const_ref<Surface> &entrance)

   * void set_environment(const const_ref<material::Base> &env)

   * void set_exit_pupil(const const_ref<Surface> &exit)

   * void undef_entrance_pupil()

   * void update_version()

sys::Container class reference
==============================

Declaration
-----------

     #include <goptical/core/sys/Container>

     namespace goptical {
       namespace sys {
         class Container;
       };
     };

   This class is a member of the sys namespace.

   This abstract class contains pure virtuals.

Inheritance
-----------

Description
-----------

This class base contains optical elements membership management code.
It's used as a base class for system (*note
sys_system_class_reference::) and Group (*note
sys_Group_class_reference::) classes.

Members
-------

See also the full member list (*note
sys_Container_class_full_member_list::) section for this class.

Type
....

   * typedef _ [...] _ element_list_t

Functions
.........

   * Container()

   * virtual ~Container()

   * void add(const ref<Element> &e)

   * template bool contains(const X *x) const

   * void draw_2d(io::Renderer &r) const

   * void draw_2d_fit(io::renderer_viewport &r, bool keep_aspect =
     _[...]_) const

   * void draw_3d(io::Renderer &r) const

   * void draw_3d_fit(io::renderer_viewport &r, double z_offset =
     _[...]_) const

   * template void enable_single(const X &e)

   * template X * find() const

   * math::vectorPair3 get_bounding_box() const

   * const element_list_t & get_element_list() const

   * template void get_elements(const delegate<void(const X&)> &d) const

   * template void get_elements(const delegate<void(X&)> &d)

   * void remove(Element &e)

Members detail
--------------

Container()
...........

No documentation available

virtual ~Container()
....................

No documentation available

void add(const  ref <Element> &e)
.................................

Add an element

template <typename X> bool contains(const X *x) const
.....................................................

Test if element is contained in container and subcontainers

void draw_2d(io::Renderer &r) const
...................................

Draw system 2d layout using specified renderer.

   See also draw_2d_fit (*note _1273::) function.

void draw_2d_fit(io::renderer_viewport &r, bool keep_aspect = true) const
........................................................................

Setup the renderer 2d viewport to best fit for this system or element
group.

   This function calls io::Renderer::set_window and
io::Renderer::set_feature_size (*note _369::).

void draw_3d(io::Renderer &r) const
...................................

Draw system in 3d using specified renderer.

   See also draw_3d_fit (*note _1275::) function.

void draw_3d_fit(io::renderer_viewport &r, double z_offset = 0) const
....................................................................

Move the renderer 3d camera to best fit for this system or element
group.

   This function calls io::renderer_viewport::set_camera_transform
(*note _466::) and io::Renderer::set_feature_size (*note _369::).

typedef std:: list <ref<Element> > element_list_t
.................................................

No documentation available

template <typename X> void enable_single(const X &e)
....................................................

Disable all elements of specified type which are not specified element

template <typename X> X * find() const
......................................

Find first element of type X in container and subcontainers

math::vectorPair3 get_bounding_box() const
..........................................

Get system or element group bounding box

const element_list_t & get_element_list() const
...............................................

Return a reference to container children list

template <typename X> void get_elements(const  delegate <void(const X&)> &d) const
..................................................................................

Invoke a delegate for each element of type X in container and
subcontainers

template <typename X> void get_elements(const  delegate <void(X&)> &d)
......................................................................

Invoke a modifier delegate for each element of type X in container and
subcontainers

void remove(Element &e)
.......................

Remove an element

sys::Container class full member list
=====================================

Type
----

   * typedef _ [...] _ element_list_t

Functions
---------

   * Container()

   * virtual ~Container()

   * void add(const ref<Element> &e)

   * template bool contains(const X *x) const

   * void draw_2d(io::Renderer &r) const

   * void draw_2d_fit(io::renderer_viewport &r, bool keep_aspect =
     _[...]_) const

   * void draw_3d(io::Renderer &r) const

   * void draw_3d_fit(io::renderer_viewport &r, double z_offset =
     _[...]_) const

   * template void enable_single(const X &e)

   * template X * find() const

   * math::vectorPair3 get_bounding_box() const

   * const element_list_t & get_element_list() const

   * template void get_elements(const delegate<void(const X&)> &d) const

   * template void get_elements(const delegate<void(X&)> &d)

   * void remove(Element &e)

sys::Element class reference
============================

Declaration
-----------

     #include <goptical/core/sys/Element>

     namespace goptical {
       namespace sys {
         class Element;
       };
     };

   This class is a member of the sys namespace.

Inheritance
-----------

Description
-----------

This is the base class for all optical elements.

   Instances of this class may be registered as members of the
Container (*note sys_Container_class_reference::) class. It handles
element position and transform to parent coordinates.

   This class has virtual functions which must be reimplemented to
handle incoming rays.

Members
-------

See also the full member list (*note
sys_Element_class_full_member_list::) section for this class.

Types
.....

   * typedef _ [...] _ mod_delegate_t

   * typedef _ [...] _ put_delegate_t

Functions
.........

   * Element(const math::vectorPair3 &plane)

   * virtual ~Element()

   * virtual void draw_2d_e(io::Renderer &r, const Element *ref) const

   * virtual void draw_3d_e(io::Renderer &r, const Element *ref) const

   * virtual math::vectorPair3 get_bounding_box() const

   * math::vector3 get_direction(const Element &e) const

   * math::vector3 get_direction() const

   * const math::Transform<3> & get_global_transform() const

   * math::vector3 get_local_direction() const

   * math::vectorPair3 get_local_plane() const

   * const math::vector3 & get_local_position() const

   * const math::Transform<3> & get_local_transform() const

   * Group * get_parent() const

   * math::vectorPair3 get_plane() const

   * math::vectorPair3 get_plane(const Element &e) const

   * math::vector3 get_position(const Element &e) const

   * math::vector3 get_position() const

   * system * get_system() const

   * const math::Transform<3> & get_transform() const

   * const math::Transform<3> & get_transform_from(const Element &e)
     const

   * const math::Transform<3> & get_transform_from(const Element *e)
     const

   * const math::Transform<3> & get_transform_to(const Element &e) const

   * const math::Transform<3> & get_transform_to(const Element *e) const

   * unsigned int get_version() const

   * unsigned int id() const

   * bool is_enabled() const

   * virtual void print(std::ostream &o) const

   * template void process_rays(trace::Result &result,
     trace::rays_queue_t *input) const

   * void rotate(double x, double y, double z)

   * void set_direction(const math::vector3 &v)

   * void set_enable_state(bool enabled)

   * void set_local_direction(const math::vector3 &v)

   * void set_local_plane(const math::vectorPair3 &p)

   * void set_local_position(const math::vector3 &v)

   * void set_plane(const math::vectorPair3 &p)

   * void set_position(const math::vector3 &v)

   * void set_transform(const math::Transform<3> &t)

   * void update_version()

Members detail
--------------

Element(const math::vectorPair3 &plane)
.......................................

Create a new optical element with given position and direction in
parent coordinates system.

virtual ~Element()
..................

No documentation available

virtual void draw_2d_e(io::Renderer &r, const Element *ref) const
.................................................................

Draw element 2d layout using the given renderer in given element
coordinates.

virtual void draw_3d_e(io::Renderer &r, const Element *ref) const
.................................................................

Draw element in 3d using the given renderer in given element coordinates

virtual math::vectorPair3 get_bounding_box() const
..................................................

Get bounding box in local coordinates

math::vector3 get_direction(const Element &e) const
...................................................

Get element direction in given element coordinate system

math::vector3 get_direction() const
...................................

Get element direction in system global coordinates

const math::Transform<3> & get_global_transform() const
.......................................................

Get transform from this element local to global coordinates

math::vector3 get_local_direction() const
.........................................

Get element direction in parent coordinate system

math::vectorPair3 get_local_plane() const
.........................................

Get reference plane (position and direction) in parent coordinate system

   See also get_local_direction (*note _1292::) function and
get_local_position (*note _1294::) function.

const math::vector3 & get_local_position() const
................................................

Get element position in parent local coordinate system

const math::Transform<3> & get_local_transform() const
......................................................

Get transform from global to this element local coordinates

Group * get_parent() const
..........................

Get a pointer to parent element, if any.

math::vectorPair3 get_plane() const
...................................

Get reference plane (position and direction) in system global
coordinates

   See also get_direction (*note _1289::) function and get_position
(*note _1299::) function.

math::vectorPair3 get_plane(const Element &e) const
...................................................

Get reference plane (position and direction) in given element
coordinates

   See also get_direction (*note _1289::) function and get_position
(*note _1299::) function.

math::vector3 get_position(const Element &e) const
..................................................

Get element position in given element coordinate system

math::vector3 get_position() const
..................................

Get element position in system global coordinate system

system * get_system() const
...........................

Get a pointer to system

const math::Transform<3> & get_transform() const
................................................

Get transform from this element to parent element coordinate system

const math::Transform<3> & get_transform_from(const Element &e) const
.....................................................................

Get transform from given element to this element coordinate system

const math::Transform<3> & get_transform_from(const Element *e) const
.....................................................................

Get transform from given element to this element coordinate system.
Transform from global coordinates is returned if paramter is 0.

const math::Transform<3> & get_transform_to(const Element &e) const
...................................................................

Get transform from this element to given element coordinate system

const math::Transform<3> & get_transform_to(const Element *e) const
...................................................................

Get transform from this element to given element coordinate system.
Transform to global coordinates is returned if paramter is 0.

unsigned int get_version() const
................................

Get element version. version is updated each time element or its
children properties are changed

unsigned int id() const
.......................

Get element identifer in current system

bool is_enabled() const
.......................

Return true if element must be considered

typedef  delegate <void(Element&)> mod_delegate_t
.................................................

No documentation available

virtual void print(std:: ostream  &o) const
...........................................

No documentation available

template <trace::IntensityMode m> void process_rays(trace::Result &result, trace::rays_queue_t *input) const
............................................................................................................

Batch process a list of light rays interacting with element. This
function is only used in sequential ray trace mode.

typedef  delegate <void(const Element&)> put_delegate_t
.......................................................

No documentation available

void rotate(double x, double y, double z)
.........................................

Rotate element direction. angles are in degrees

void set_direction(const math::vector3 &v)
..........................................

Set element direction in system global coordinates

void set_enable_state(bool enabled)
...................................

Set enable state

void set_local_direction(const math::vector3 &v)
................................................

Set element direction in parent coordinate system

void set_local_plane(const math::vectorPair3 &p)
................................................

Set reference plane (position and direction) in parent coordinate system

   See also set_local_direction (*note _1317::) function and
set_local_position (*note _1319::) function.

void set_local_position(const math::vector3 &v)
...............................................

Set element position in parent local coordinate system

void set_plane(const math::vectorPair3 &p)
..........................................

Set reference plane (position and direction) in system global
coordinates

   See also set_direction (*note _1315::) function and set_position
(*note _1321::) function.

void set_position(const math::vector3 &v)
.........................................

Set element position in system global coordinate system

void set_transform(const math::Transform<3> &t)
...............................................

Set transform to parant coordinate system

void update_version()
.....................

Increase current element version

sys::Element class full member list
===================================

Types
-----

   * typedef _ [...] _ mod_delegate_t

   * typedef _ [...] _ put_delegate_t

Functions
---------

   * Element(const math::vectorPair3 &plane)

   * virtual ~Element()

   * virtual void draw_2d_e(io::Renderer &r, const Element *ref) const

   * virtual void draw_3d_e(io::Renderer &r, const Element *ref) const

   * virtual math::vectorPair3 get_bounding_box() const

   * math::vector3 get_direction(const Element &e) const

   * math::vector3 get_direction() const

   * const math::Transform<3> & get_global_transform() const

   * math::vector3 get_local_direction() const

   * math::vectorPair3 get_local_plane() const

   * const math::vector3 & get_local_position() const

   * const math::Transform<3> & get_local_transform() const

   * Group * get_parent() const

   * math::vectorPair3 get_plane() const

   * math::vectorPair3 get_plane(const Element &e) const

   * math::vector3 get_position(const Element &e) const

   * math::vector3 get_position() const

   * system * get_system() const

   * const math::Transform<3> & get_transform() const

   * const math::Transform<3> & get_transform_from(const Element &e)
     const

   * const math::Transform<3> & get_transform_from(const Element *e)
     const

   * const math::Transform<3> & get_transform_to(const Element &e) const

   * const math::Transform<3> & get_transform_to(const Element *e) const

   * unsigned int get_version() const

   * unsigned int id() const

   * bool is_enabled() const

   * virtual void print(std::ostream &o) const

   * template void process_rays(trace::Result &result,
     trace::rays_queue_t *input) const

   * void rotate(double x, double y, double z)

   * void set_direction(const math::vector3 &v)

   * void set_enable_state(bool enabled)

   * void set_local_direction(const math::vector3 &v)

   * void set_local_plane(const math::vectorPair3 &p)

   * void set_local_position(const math::vector3 &v)

   * void set_plane(const math::vectorPair3 &p)

   * void set_position(const math::vector3 &v)

   * void set_transform(const math::Transform<3> &t)

   * void update_version()

sys::Source class reference
===========================

Declaration
-----------

     #include <goptical/core/sys/Source>

     namespace goptical {
       namespace sys {
         class Source;
       };
     };

   This class is a member of the sys namespace.

Inheritance
-----------

Description
-----------

This class is the base class for all light sources implementations.

Members
-------

See also the full member list (*note
sys_Source_class_full_member_list::) section for this class.

Inherited members
.................

   * 40 members inherited from Element (*note
     sys_Element_class_reference::)

Type
....

   * typedef _ [...] _ targets_t

Functions
.........

   * Source(const math::vectorPair3 &position)

   * void add_spectral_line(const light::SpectralLine &l)

   * void clear_spectrum()

   * template void generate_rays(trace::Result &result, const targets_t
     &entry) const

   * double get_max_intensity() const

   * double get_min_intensity() const

   * void set_material(const const_ref<material::Base> &m)

   * void set_spectral_line(const light::SpectralLine &l, int index =
     _[...]_)

   * void single_spectral_line(const light::SpectralLine &l)

Members detail
--------------

Source(const math::vectorPair3 &position)
.........................................

Create a source at given position.

void add_spectral_line(const light::SpectralLine &l)
....................................................

Add a new wavelen for ray generation

void clear_spectrum()
.....................

Clear wavelen list

template <trace::IntensityMode m> void generate_rays(trace::Result &result, const targets_t &entry) const
.........................................................................................................

Generate light rays from source

double get_max_intensity() const
................................

Get maximal spectral line intensity

double get_min_intensity() const
................................

Get minimal spectral line intensity

void set_material(const  const_ref <material::Base> &m)
.......................................................

Set material where light rays are generated. system environment
material is used by default.

void set_spectral_line(const light::SpectralLine &l, int index = 0)
...................................................................

Set a wavelen in list for ray generation

void single_spectral_line(const light::SpectralLine &l)
.......................................................

Clear ray wavelen list and set a single wavelen

typedef std:: vector <const sys::Element*> targets_t
....................................................

No documentation available

sys::Source class full member list
==================================

Types
-----

   * typedef _ [...] _ mod_delegate_t

   * typedef _ [...] _ put_delegate_t

   * typedef _ [...] _ targets_t

Functions
---------

   * Source(const math::vectorPair3 &position)

   * void add_spectral_line(const light::SpectralLine &l)

   * void clear_spectrum()

   * virtual void draw_2d_e(io::Renderer &r, const Element *ref) const

   * virtual void draw_3d_e(io::Renderer &r, const Element *ref) const

   * template void generate_rays(trace::Result &result, const targets_t
     &entry) const

   * virtual math::vectorPair3 get_bounding_box() const

   * math::vector3 get_direction(const Element &e) const

   * math::vector3 get_direction() const

   * const math::Transform<3> & get_global_transform() const

   * math::vector3 get_local_direction() const

   * math::vectorPair3 get_local_plane() const

   * const math::vector3 & get_local_position() const

   * const math::Transform<3> & get_local_transform() const

   * double get_max_intensity() const

   * double get_min_intensity() const

   * Group * get_parent() const

   * math::vectorPair3 get_plane() const

   * math::vectorPair3 get_plane(const Element &e) const

   * math::vector3 get_position(const Element &e) const

   * math::vector3 get_position() const

   * system * get_system() const

   * const math::Transform<3> & get_transform() const

   * const math::Transform<3> & get_transform_from(const Element &e)
     const

   * const math::Transform<3> & get_transform_from(const Element *e)
     const

   * const math::Transform<3> & get_transform_to(const Element &e) const

   * const math::Transform<3> & get_transform_to(const Element *e) const

   * unsigned int get_version() const

   * unsigned int id() const

   * bool is_enabled() const

   * virtual void print(std::ostream &o) const

   * template void process_rays(trace::Result &result,
     trace::rays_queue_t *input) const

   * void rotate(double x, double y, double z)

   * void set_direction(const math::vector3 &v)

   * void set_enable_state(bool enabled)

   * void set_local_direction(const math::vector3 &v)

   * void set_local_plane(const math::vectorPair3 &p)

   * void set_local_position(const math::vector3 &v)

   * void set_material(const const_ref<material::Base> &m)

   * void set_plane(const math::vectorPair3 &p)

   * void set_position(const math::vector3 &v)

   * void set_spectral_line(const light::SpectralLine &l, int index =
     _[...]_)

   * void set_transform(const math::Transform<3> &t)

   * void single_spectral_line(const light::SpectralLine &l)

   * void update_version()

sys::Stop class reference
=========================

Declaration
-----------

     #include <goptical/core/sys/Stop>

     namespace goptical {
       namespace sys {
         class Stop;
       };
     };

   This class is a member of the sys namespace.

Inheritance
-----------

Description
-----------

This class implements an aperture stop surface.

   This surface will block all rays which fall outside the surface
shape and inside the external radius. (All rays which pass at a
distance from the axis greater than the external radius are not
affected.)

   Rays which fall inside the surface shape may either be intercepted
and reemited or unaffected. Rays are always intercepted in sequential
raytrace mode. In non-sequential mode this can be changed with
set_intercept_reemit (*note _1339::); default is disabled.

Members
-------

See also the full member list (*note sys_Stop_class_full_member_list::)
section for this class.

Inherited members
.................

   * 48 members inherited from Surface (*note
     sys_Surface_class_reference::)

Functions
.........

   * Stop(const math::vectorPair3 &p, const const_ref<shape::Base>
     &shape)

   * Stop(const math::vectorPair3 &p, double radius)

   * double get_external_radius() const

   * bool get_intercept_reemit() const

   * void set_external_radius(double external_radius)

   * void set_intercept_reemit(bool intercept_reemit)

Members detail
--------------

Stop(const math::vectorPair3 &p, const  const_ref <shape::Base> &shape)
.......................................................................

Create an aperture stop surface. External radius is set to twice the
shape max radius.

Stop(const math::vectorPair3 &p, double radius)
...............................................

Create a circular aperture stop surface with given radius. External
radius is set to twice the shape max radius.

double get_external_radius() const
..................................

Get stop external radius. .

   See also set_external_radius (*note _1338::) function and Stop
(*note sys_Stop_class_reference::) class.

bool get_intercept_reemit() const
.................................

Get intercept and reemit enabled. .

   See also set_intercept_reemit (*note _1339::) function and Stop
(*note sys_Stop_class_reference::) class.

void set_external_radius(double external_radius)
................................................

Set stop external radius. .

   See also get_external_radius (*note _1336::) function and Stop
(*note sys_Stop_class_reference::) class.

void set_intercept_reemit(bool intercept_reemit)
................................................

Set intercept and reemit enabled. .

   See also get_intercept_reemit (*note _1337::) function and Stop
(*note sys_Stop_class_reference::) class.

sys::Stop class full member list
================================

Types
-----

   * typedef _ [...] _ mod_delegate_t

   * typedef _ [...] _ put_delegate_t

Functions
---------

   * Stop(const math::vectorPair3 &p, const const_ref<shape::Base>
     &shape)

   * Stop(const math::vectorPair3 &p, double radius)

   * virtual math::vectorPair3 get_bounding_box() const

   * virtual io::rgb get_color(const io::Renderer &r) const

   * const curve::Base & get_curve() const

   * math::vector3 get_direction(const Element &e) const

   * math::vector3 get_direction() const

   * double get_discard_intensity() const

   * double get_external_radius() const

   * const math::Transform<3> & get_global_transform() const

   * bool get_intercept_reemit() const

   * math::vector3 get_local_direction() const

   * math::vectorPair3 get_local_plane() const

   * const math::vector3 & get_local_position() const

   * const math::Transform<3> & get_local_transform() const

   * Group * get_parent() const

   * void get_pattern(const math::vector3::put_delegate_t &f, const
     trace::distribution &d, bool unobstructed = _[...]_) const

   * math::vectorPair3 get_plane() const

   * math::vectorPair3 get_plane(const Element &e) const

   * math::vector3 get_position(const Element &e) const

   * math::vector3 get_position() const

   * const shape::Base & get_shape() const

   * system * get_system() const

   * const math::Transform<3> & get_transform() const

   * const math::Transform<3> & get_transform_from(const Element &e)
     const

   * const math::Transform<3> & get_transform_from(const Element *e)
     const

   * const math::Transform<3> & get_transform_to(const Element &e) const

   * const math::Transform<3> & get_transform_to(const Element *e) const

   * unsigned int get_version() const

   * unsigned int id() const

   * bool is_enabled() const

   * virtual void print(std::ostream &o) const

   * template void process_rays(trace::Result &result,
     trace::rays_queue_t *input) const

   * void rotate(double x, double y, double z)

   * void set_curve(const const_ref<curve::Base> &c)

   * void set_direction(const math::vector3 &v)

   * void set_discard_intensity(double intensity)

   * void set_enable_state(bool enabled)

   * void set_external_radius(double external_radius)

   * void set_intercept_reemit(bool intercept_reemit)

   * void set_local_direction(const math::vector3 &v)

   * void set_local_plane(const math::vectorPair3 &p)

   * void set_local_position(const math::vector3 &v)

   * void set_plane(const math::vectorPair3 &p)

   * void set_position(const math::vector3 &v)

   * void set_shape(const const_ref<shape::Base> &s)

   * void set_transform(const math::Transform<3> &t)

   * template void trace_ray(trace::Result &result, trace::Ray
     &incident, const math::vectorPair3 &local, const math::vectorPair3
     &intersect) const

   * void update_version()

sys::Surface class reference
============================

Declaration
-----------

     #include <goptical/core/sys/Surface>

     namespace goptical {
       namespace sys {
         class Surface;
       };
     };

   This class is a member of the sys namespace.

Inheritance
-----------

Description
-----------

This is the base class for surface element. A surface element is
defined by its position, surface curve and contour shape.

   This class can handle incoming rays and is responsible for finding
rays intersection with the surface.

   Depending on ray trace intensity mode, it will potentially adjust
light absorption and then call trace_ray_simple, trace_ray_intensity or
trace_ray_polarized. These functions must be reimplemented in sub
classes, default implementations will throw.

Members
-------

See also the full member list (*note
sys_Surface_class_full_member_list::) section for this class.

Inherited members
.................

   * 40 members inherited from Element (*note
     sys_Element_class_reference::)

Functions
.........

   * Surface(const math::vectorPair3 &p, const const_ref<curve::Base>
     &curve, const const_ref<shape::Base> &shape)

   * virtual ~Surface()

   * virtual math::vectorPair3 get_bounding_box() const

   * virtual io::rgb get_color(const io::Renderer &r) const

   * const curve::Base & get_curve() const

   * double get_discard_intensity() const

   * void get_pattern(const math::vector3::put_delegate_t &f, const
     trace::distribution &d, bool unobstructed = _[...]_) const

   * const shape::Base & get_shape() const

   * virtual bool intersect(const trace::params &params,
     math::vectorPair3 &pt, const math::vectorPair3 &ray) const

   * void set_curve(const const_ref<curve::Base> &c)

   * void set_discard_intensity(double intensity)

   * void set_shape(const const_ref<shape::Base> &s)

   * template void trace_ray(trace::Result &result, trace::Ray
     &incident, const math::vectorPair3 &local, const math::vectorPair3
     &intersect) const

Members detail
--------------

Surface(const math::vectorPair3 &p, const  const_ref <curve::Base> &curve, const  const_ref <shape::Base> &shape)
.................................................................................................................

Create a surface element at given location.

virtual ~Surface()
..................

No documentation available

virtual math::vectorPair3 get_bounding_box() const
..................................................

This virtual function overrides the `get_bounding_box (*note _1288::)'
virtual function defined in the `Element (*note
sys_Element_class_reference::)' base class.

   Documentation inherited from base class:

   Get bounding box in local coordinates

virtual io::rgb get_color(const io::Renderer &r) const
......................................................

Get surface apparent color

const curve::Base & get_curve() const
.....................................

Get surface curve

double get_discard_intensity() const
....................................

Get minimal ray intensity.

void get_pattern(const math::vector3::put_delegate_t &f, const trace::distribution &d, bool unobstructed = false) const
.......................................................................................................................

Get distribution pattern points projected on the surface

const shape::Base & get_shape() const
.....................................

Get surface shape

virtual bool intersect(const trace::params &params, math::vectorPair3 &pt, const math::vectorPair3 &ray) const
..............................................................................................................

Get intersection point and normal to surface at intersection. Return
false if no intersection occured.

void set_curve(const  const_ref <curve::Base> &c)
.................................................

Set surface curve

void set_discard_intensity(double intensity)
............................................

Set minimal ray intensity. Incident rays with less intensity will be
discarded

void set_shape(const  const_ref <shape::Base> &s)
.................................................

Set surface shape

template <trace::IntensityMode m> void trace_ray(trace::Result &result, trace::Ray &incident, const math::vectorPair3 &local, const math::vectorPair3 &intersect) const
.......................................................................................................................................................................

trace a single ray through the surface

sys::Surface class full member list
===================================

Types
-----

   * typedef _ [...] _ mod_delegate_t

   * typedef _ [...] _ put_delegate_t

Functions
---------

   * Surface(const math::vectorPair3 &p, const const_ref<curve::Base>
     &curve, const const_ref<shape::Base> &shape)

   * virtual ~Surface()

   * virtual math::vectorPair3 get_bounding_box() const

   * virtual io::rgb get_color(const io::Renderer &r) const

   * const curve::Base & get_curve() const

   * math::vector3 get_direction(const Element &e) const

   * math::vector3 get_direction() const

   * double get_discard_intensity() const

   * const math::Transform<3> & get_global_transform() const

   * math::vector3 get_local_direction() const

   * math::vectorPair3 get_local_plane() const

   * const math::vector3 & get_local_position() const

   * const math::Transform<3> & get_local_transform() const

   * Group * get_parent() const

   * void get_pattern(const math::vector3::put_delegate_t &f, const
     trace::distribution &d, bool unobstructed = _[...]_) const

   * math::vectorPair3 get_plane() const

   * math::vectorPair3 get_plane(const Element &e) const

   * math::vector3 get_position(const Element &e) const

   * math::vector3 get_position() const

   * const shape::Base & get_shape() const

   * system * get_system() const

   * const math::Transform<3> & get_transform() const

   * const math::Transform<3> & get_transform_from(const Element &e)
     const

   * const math::Transform<3> & get_transform_from(const Element *e)
     const

   * const math::Transform<3> & get_transform_to(const Element &e) const

   * const math::Transform<3> & get_transform_to(const Element *e) const

   * unsigned int get_version() const

   * unsigned int id() const

   * virtual bool intersect(const trace::params &params,
     math::vectorPair3 &pt, const math::vectorPair3 &ray) const

   * bool is_enabled() const

   * virtual void print(std::ostream &o) const

   * template void process_rays(trace::Result &result,
     trace::rays_queue_t *input) const

   * void rotate(double x, double y, double z)

   * void set_curve(const const_ref<curve::Base> &c)

   * void set_direction(const math::vector3 &v)

   * void set_discard_intensity(double intensity)

   * void set_enable_state(bool enabled)

   * void set_local_direction(const math::vector3 &v)

   * void set_local_plane(const math::vectorPair3 &p)

   * void set_local_position(const math::vector3 &v)

   * void set_plane(const math::vectorPair3 &p)

   * void set_position(const math::vector3 &v)

   * void set_shape(const const_ref<shape::Base> &s)

   * void set_transform(const math::Transform<3> &t)

   * template void trace_ray(trace::Result &result, trace::Ray
     &incident, const math::vectorPair3 &local, const math::vectorPair3
     &intersect) const

   * void update_version()

trace namespace reference
=========================

Description
-----------

Ray tracer and light propagation

Members
-------

Types
.....

   * class distribution

   * class params

   * class Result

   * class sequence

   * class tracer

   * enum IntensityMode

   * enum Pattern

   * class Ray

   * typedef _ [...] _ rays_queue_t

Function
........

   * std::ostream & operator<<(std::ostream &o, const sequence &s)

Members detail
--------------

enum IntensityMode
..................

Specifies light intensity calculation mode to use by light propagation
algorithms.

Identifier             Description
-------------------------------------------------------------------------- 
Simpletrace             No Intensity calculation is performed
Intensitytrace          light intensity computation is performed without
                       taking polarization into account
Polarizedtrace          light intensity with polarization computation is
                       performed (not supported yet)

enum Pattern
............

Specifies point distribution patterns over a shape delimited surface.

 [image src="dist_patterns.png" alt="Different patterns rendered on a disk with default density" ]

Identifier             Description
-------------------------------------------------------------------------- 
DefaultDist             Preferred distribution pattern for a given shape
SagittalDist            Sagittal plane distribution (along the X axis,
                       X/Z plane)
MeridionalDist          Meridional plane distribution (along the Y axis,
                       Y/Z plane)
TangentialDist          Tangential plane distribution, same as
                       MeridionalDist (*note _1354::)
CrossDist               Sagittal and Meridional distribution combined
SquareDist              Square pattern distribution
TriangularDist          Triangular pattern distribution
HexaPolarDist           Hexapolar pattern, suitable for circular shapes
RandomDist              Random distribution

   See also distribution (*note trace_distribution_class_reference::)
class.

std:: ostream  & operator<<(std:: ostream  &o, const sequence &s)
.................................................................

No documentation available

typedef std:: deque <Ray*> rays_queue_t
.......................................

No documentation available

trace::distribution class reference
===================================

Declaration
-----------

     #include <goptical/core/trace/distribution>

     namespace goptical {
       namespace trace {
         class distribution;
       };
     };

   This class is a member of the trace namespace.

Description
-----------

This class describes distribution pattern and ray density used for
light ray distribution over surfaces during light propagation.

   Ray density is expressed as average number of rays along surface
radius.

 [image src="dist_patterns.png" alt="Different patterns rendered on a disk with default density" ]

Members
-------

See also the full member list (*note
trace_distribution_class_full_member_list::) section for this class.

Functions
.........

   * distribution(Pattern pattern = _[...]_, unsigned int
     radial_density = _[...]_, double scaling = _[...]_)

   * Pattern get_pattern() const

   * unsigned int get_radial_density() const

   * double get_scaling() const

   * void set_pattern(Pattern p)

   * void set_radial_density(unsigned int count)

   * void set_scaling(double scaling)

   * void set_uniform_pattern()

Members detail
--------------

distribution(Pattern pattern = DefaultDist, unsigned int radial_density = 5, double scaling = 0.999)
....................................................................................................

Creates a distribution pattern with specified pattern, radial ray
density and scaling.

   The scaling ratio parameter may be used to avoid distributing rays
too close to the surface edge.

Pattern get_pattern() const
...........................

Get distribution pattern

unsigned int get_radial_density() const
.......................................

Get current radial density

double get_scaling() const
..........................

get current scaling

void set_pattern(Pattern p)
...........................

Set distribution pattern

void set_radial_density(unsigned int count)
...........................................

Set average number of ray to distribute on surface radius

void set_scaling(double scaling)
................................

Set scaling, Rays are distributed on surface but are kept away from
surface edge if scaling is less than 1.0.

void set_uniform_pattern()
..........................

Ensure uniform 2d pattern suitable for spot diagram and image analysis
is selected. Change to default pattern if not.

trace::distribution class full member list
==========================================

Functions
---------

   * distribution(Pattern pattern = _[...]_, unsigned int
     radial_density = _[...]_, double scaling = _[...]_)

   * Pattern get_pattern() const

   * unsigned int get_radial_density() const

   * double get_scaling() const

   * void set_pattern(Pattern p)

   * void set_radial_density(unsigned int count)

   * void set_scaling(double scaling)

   * void set_uniform_pattern()

trace::params class reference
=============================

Declaration
-----------

     #include <goptical/core/trace/params>

     namespace goptical {
       namespace trace {
         class params;
       };
     };

   This class is a member of the trace namespace.

Description
-----------

This class is used to store light progation parameters. This includes
sequential / non-sequential mode, light intensity computation mode and
propagation mode (raytracing, diffraction, ...).

   See also Performing light propagation (*note Performing light
propagation::) section.

Members
-------

See also the full member list (*note
trace_params_class_full_member_list::) section for this class.

Functions
.........

   * params()

   * const distribution & get_default_distribution() const

   * distribution & get_default_distribution()

   * const distribution & get_distribution(const sys::Surface &s) const

   * IntensityMode get_intensity_mode() const

   * double get_lost_ray_length() const

   * unsigned int get_max_bounce() const

   * bool get_unobstructed() const

   * bool is_sequential() const

   * void reset_distribution()

   * void set_default_distribution(const distribution
     &default_distribution)

   * void set_distribution(const sys::Surface &s, const distribution
     &dist)

   * void set_intensity_mode(IntensityMode intensity_mode)

   * void set_lost_ray_length(double lost_ray_length)

   * void set_max_bounce(unsigned int max_bounce)

   * void set_nonsequential_mode()

   * void set_sequential_mode(const const_ref<sequence> &seq)

   * void set_unobstructed(bool unobstructed)

Members detail
--------------

params()
........

No documentation available

const distribution & get_default_distribution() const
.....................................................

Get default rays distribution pattern.

   See also set_default_distribution (*note _1375::) function.

distribution & get_default_distribution()
.........................................

Get default rays distribution pattern.

   See also set_default_distribution (*note _1375::) function.

const distribution & get_distribution(const sys::Surface &s) const
..................................................................

Get distribution pattern for a given surface

IntensityMode get_intensity_mode() const
........................................

Get raytracing intensity mode.

   See also set_intensity_mode (*note _1377::) function.

double get_lost_ray_length() const
..................................

Get lost ray length.

   See also set_lost_ray_length (*note _1378::) function.

unsigned int get_max_bounce() const
...................................

Get maximum ray bounce count, default is 50.

   See also set_max_bounce (*note _1379::) function.

bool get_unobstructed() const
.............................

Get unobstructed raytracing mode. Surface shapes are ignored, no rays
are stopped.

   See also set_unobstructed (*note _1382::) function.

bool is_sequential() const
..........................

Test if in sequential ray tracing mode

void reset_distribution()
.........................

Reset all surface specific distribution settings to default

void set_default_distribution(const distribution &default_distribution)
.......................................................................

Set default rays distribution pattern.

   See also get_default_distribution (*note _1366::) function.

void set_distribution(const sys::Surface &s, const distribution &dist)
......................................................................

Set distribution pattern for a given surface

void set_intensity_mode(IntensityMode intensity_mode)
.....................................................

Set raytracing intensity mode.

   See also get_intensity_mode (*note _1369::) function.

void set_lost_ray_length(double lost_ray_length)
................................................

Set lost ray length.

   See also get_lost_ray_length (*note _1370::) function.

void set_max_bounce(unsigned int max_bounce)
............................................

Set maximum ray bounce count, default is 50.

   See also get_max_bounce (*note _1371::) function.

void set_nonsequential_mode()
.............................

Set non sequential ray tracing mode (default)

void set_sequential_mode(const  const_ref <sequence> &seq)
..........................................................

Set sequential ray tracing mode

void set_unobstructed(bool unobstructed)
........................................

Set unobstructed raytracing mode. Surface shapes are ignored, no rays
are stopped.

   See also get_unobstructed (*note _1372::) function.

trace::params class full member list
====================================

Functions
---------

   * params()

   * const distribution & get_default_distribution() const

   * distribution & get_default_distribution()

   * const distribution & get_distribution(const sys::Surface &s) const

   * IntensityMode get_intensity_mode() const

   * double get_lost_ray_length() const

   * unsigned int get_max_bounce() const

   * bool get_unobstructed() const

   * bool is_sequential() const

   * void reset_distribution()

   * void set_default_distribution(const distribution
     &default_distribution)

   * void set_distribution(const sys::Surface &s, const distribution
     &dist)

   * void set_intensity_mode(IntensityMode intensity_mode)

   * void set_lost_ray_length(double lost_ray_length)

   * void set_max_bounce(unsigned int max_bounce)

   * void set_nonsequential_mode()

   * void set_sequential_mode(const const_ref<sequence> &seq)

   * void set_unobstructed(bool unobstructed)

trace::Result class reference
=============================

Declaration
-----------

     #include <goptical/core/trace/Result>

     namespace goptical {
       namespace trace {
         class Result;
       };
     };

   This class is a member of the trace namespace.

Description
-----------

This class encapsulates rays data propagation result.

   It must be properly configured before light propagation as needed by
the analysis currently being performed. All requested light propagation
informations will be store for further processing.

   All Ray (*note trace_Ray_class_reference::) object are allocated by
this class. It is able to remember which element intercepted and
generated each ray.

Members
-------

See also the full member list (*note
trace_Result_class_full_member_list::) section for this class.

Type
....

   * typedef _ [...] _ sources_t

Functions
.........

   * Result()

   * ~Result()

   * void add_generated(const sys::Element &s, Ray &ray)

   * void add_intercepted(const sys::Surface &s, Ray &ray)

   * void add_ray_wavelen(double wavelen)

   * void clear()

   * void clear_save_states()

   * void draw_2d(io::Renderer &r, bool hit_image = _[...]_, const
     sys::Element *ref = _[...]_) const

   * void draw_3d(io::Renderer &r, bool hit_image = _[...]_, const
     sys::Element *ref = _[...]_) const

   * const rays_queue_t & get_generated(const sys::Element &s) const

   * bool get_generated_save_state(const sys::Element &e)

   * const rays_queue_t & get_intercepted(const sys::Surface &s) const

   * math::vector3 get_intercepted_center(const sys::Surface &s) const

   * math::vector3 get_intercepted_centroid(const sys::Surface &s) const

   * bool get_intercepted_save_state(const sys::Element &e)

   * math::vectorPair3 get_intercepted_window(const sys::Surface &s)
     const

   * double get_max_ray_intensity() const

   * const params & get_params() const

   * const std::set<double> & get_ray_wavelen_set() const

   * const sources_t & get_source_list() const

   * Ray & new_ray()

   * Ray & new_ray(const light::Ray &r)

   * void set_generated_save_state(const sys::Element &e, bool enabled
     = _[...]_)

   * void set_intercepted_save_state(const sys::Element &e, bool
     enabled = _[...]_)

Members detail
--------------

Result()
........

Crate a new empty result object

~Result()
.........

No documentation available

void add_generated(const sys::Element &s, Ray &ray)
...................................................

Declare a new ray generation

void add_intercepted(const sys::Surface &s, Ray &ray)
.....................................................

Declare a new ray interception

void add_ray_wavelen(double wavelen)
....................................

Declare ray wavelen used for tracing

void clear()
............

Clear all result data

void clear_save_states()
........................

Set all save states to false

void draw_2d(io::Renderer &r, bool hit_image = false, const sys::Element *ref = 0) const
........................................................................................

Draw all tangential rays using specified renderer. Only rays which end
up hitting the image plane are drawn when `hit_image' is set.

void draw_3d(io::Renderer &r, bool hit_image = false, const sys::Element *ref = 0) const
........................................................................................

Draw all rays using specified renderer. Only rays which end up hitting
the image plane are drawn when `hit_image' is set.

const rays_queue_t & get_generated(const sys::Element &s) const
...............................................................

Get the list of rays generated by a given element

bool get_generated_save_state(const sys::Element &e)
....................................................

Return true if generated rays must be saved for this element

const rays_queue_t & get_intercepted(const sys::Surface &s) const
.................................................................

Get the list of rays striking a given surface

math::vector3 get_intercepted_center(const sys::Surface &s) const
.................................................................

Get center of window

math::vector3 get_intercepted_centroid(const sys::Surface &s) const
...................................................................

Get centroid of all ray intercepted on a surface

bool get_intercepted_save_state(const sys::Element &e)
......................................................

Return true if generated rays must be saved for this element

math::vectorPair3 get_intercepted_window(const sys::Surface &s) const
.....................................................................

Get window which include all ray intercepted on a surface

double get_max_ray_intensity() const
....................................

Get maximum intensity for a single ray FIXME

const params & get_params() const
.................................

Get reference to tracer parameters used

const std:: set <double> & get_ray_wavelen_set() const
......................................................

Get ray wavelen in use set

const sources_t & get_source_list() const
.........................................

Get list of sources used for ray tracing

Ray & new_ray()
...............

Allocate a new trace::Ray object from result

Ray & new_ray(const light::Ray &r)
..................................

Allocate a new trace::Ray object from result

void set_generated_save_state(const sys::Element &e, bool enabled = true)
.........................................................................

List of rays generated by this element must be saved when tracing rays

void set_intercepted_save_state(const sys::Element &e, bool enabled = true)
...........................................................................

List of rays striking this surface must be saved when tracing rays

typedef std:: vector <const sys::Source*> sources_t
...................................................

No documentation available

trace::Result class full member list
====================================

Type
----

   * typedef _ [...] _ sources_t

Functions
---------

   * Result()

   * ~Result()

   * void add_generated(const sys::Element &s, Ray &ray)

   * void add_intercepted(const sys::Surface &s, Ray &ray)

   * void add_ray_wavelen(double wavelen)

   * void clear()

   * void clear_save_states()

   * void draw_2d(io::Renderer &r, bool hit_image = _[...]_, const
     sys::Element *ref = _[...]_) const

   * void draw_3d(io::Renderer &r, bool hit_image = _[...]_, const
     sys::Element *ref = _[...]_) const

   * const rays_queue_t & get_generated(const sys::Element &s) const

   * bool get_generated_save_state(const sys::Element &e)

   * const rays_queue_t & get_intercepted(const sys::Surface &s) const

   * math::vector3 get_intercepted_center(const sys::Surface &s) const

   * math::vector3 get_intercepted_centroid(const sys::Surface &s) const

   * bool get_intercepted_save_state(const sys::Element &e)

   * math::vectorPair3 get_intercepted_window(const sys::Surface &s)
     const

   * double get_max_ray_intensity() const

   * const params & get_params() const

   * const std::set<double> & get_ray_wavelen_set() const

   * const sources_t & get_source_list() const

   * Ray & new_ray()

   * Ray & new_ray(const light::Ray &r)

   * void set_generated_save_state(const sys::Element &e, bool enabled
     = _[...]_)

   * void set_intercepted_save_state(const sys::Element &e, bool
     enabled = _[...]_)

trace::sequence class reference
===============================

Declaration
-----------

     #include <goptical/core/trace/sequence>

     namespace goptical {
       namespace trace {
         class sequence;
       };
     };

   This class is a member of the trace namespace.

Inheritance
-----------

Description
-----------

There are two light propagation modes in common use: sequential and non
sequential. When using the sequential mode, light only interacts with
sequence elements in given sequence order.

   This class will hold the user defined ordered list of elements used
by sequential light propagation algorithm implemented in the tracer
(*note trace_tracer_class_reference::) class.

Members
-------

See also the full member list (*note
trace_sequence_class_full_member_list::) section for this class.

Functions
.........

   * sequence()

   * sequence(const sys::system &system)

   * void add(const sys::system &system)

   * unsigned int append(const sys::Element &element)

   * void clear()

   * const sys::Element & get_element(unsigned int index) const

   * void insert(unsigned int index, const sys::Element &element)

   * void remove(unsigned int index)

Members detail
--------------

sequence()
..........

Create a new empty sequence

sequence(const sys::system &system)
...................................

Create a new sequence and insert all elements present in the system.
This is equivalent to calling add() on empty sequence.

void add(const sys::system &system)
...................................

Add all elements from the given system. Element are sorted in axis
order starting from left; reflecting elements do reverse direction.

unsigned int append(const sys::Element &element)
................................................

Insert an element at end of sequence.

   The return value is position of the element in the sequence

void clear()
............

Remove all elements from sequence

const sys::Element & get_element(unsigned int index) const
..........................................................

Get a reference to an element in sequence

void insert(unsigned int index, const sys::Element &element)
............................................................

Insert an element in sequence at given position

void remove(unsigned int index)
...............................

Remove an element from sequence

trace::sequence class full member list
======================================

Functions
---------

   * sequence()

   * sequence(const sys::system &system)

   * void add(const sys::system &system)

   * unsigned int append(const sys::Element &element)

   * void clear()

   * const sys::Element & get_element(unsigned int index) const

   * void insert(unsigned int index, const sys::Element &element)

   * void remove(unsigned int index)

trace::tracer class reference
=============================

Declaration
-----------

     #include <goptical/core/trace/Tracer>

     namespace goptical {
       namespace trace {
         class tracer;
       };
     };

   This class is a member of the trace namespace.

Description
-----------

This class handle light propagation in an optical system.

   Propagation result is stored in a Result (*note
trace_Result_class_reference::) object. Propagation parameters are
stored in a params (*note trace_params_class_reference::) object.

   See also Performing light propagation (*note Performing light
propagation::) section.

Members
-------

See also the full member list (*note
trace_tracer_class_full_member_list::) section for this class.

Functions
.........

   * tracer(const const_ref<sys::system> &system)

   * ~tracer()

   * const params & get_params() const

   * params & get_params()

   * const sys::system & get_system() const

   * Result & get_trace_result() const

   * Result & set_default_trace_result()

   * void set_params(const params &params)

   * void set_trace_result(Result &res)

   * void trace()

Members detail
--------------

tracer(const  const_ref <sys::system> &system)
..............................................

Create a new light porpagator object

~tracer()
.........

No documentation available

const params & get_params() const
.................................

get tracer parameters

params & get_params()
.....................

get tracer parameters

const sys::system & get_system() const
......................................

Get attached system

Result & get_trace_result() const
.................................

No documentation available

Result & set_default_trace_result()
...................................

Undefine user defined Result object. Next ray trace operation will
allocate a new internal trace result object

void set_params(const params &params)
.....................................

replace all tracer parameters

void set_trace_result(Result &res)
..................................

Set the Result object which must be used to store ray tracing data. a
new Result object will be allocated on first ray trace operation if
none were defined.

void trace()
............

Launch ray tracing operation

trace::tracer class full member list
====================================

Functions
---------

   * tracer(const const_ref<sys::system> &system)

   * ~tracer()

   * const params & get_params() const

   * params & get_params()

   * const sys::system & get_system() const

   * Result & get_trace_result() const

   * Result & set_default_trace_result()

   * void set_params(const params &params)

   * void set_trace_result(Result &res)

   * void trace()

trace::Ray class reference
==========================

Declaration
-----------

     #include <goptical/core/trace/Ray>

     namespace goptical {
       namespace trace {
         class Ray;
       };
     };

   This class is a member of the trace namespace.

Inheritance
-----------

Description
-----------

This class is used to describe a light::Ray (*note
light_Ray_class_reference::) with all tracing and propagation
informations attached.

Members
-------

See also the full member list (*note
trace_Ray_class_full_member_list::) section for this class.

Inherited members
.................

   * 36 members inherited from light::Ray (*note
     light_Ray_class_reference::)

Functions
.........

   * Ray()

   * Ray(const light::Ray &r)

   * void add_generated(Ray *r)

   * const sys::Element * get_creator() const

   * math::vector3 get_direction() const

   * math::vector3 get_direction(const sys::Element &e) const

   * Ray * get_first_child() const

   * sys::Element & get_intercept_element() const

   * double get_intercept_intensity() const

   * const math::vector3 & get_intercept_point() const

   * double get_len() const

   * const material::Base * get_material() const

   * Ray * get_next_child() const

   * Ray * get_parent() const

   * math::vector3 get_position() const

   * math::vector3 get_position(const sys::Element &e) const

   * bool is_lost() const

   * void set_creator(const sys::Element *creator)

   * void set_intercept(const sys::Element &e, const math::vector3
     &point)

   * void set_intercept_intensity(double intercept_intensity)

   * void set_len(double len)

   * void set_material(const material::Base *material)

Members detail
--------------

Ray()
.....

This constructor shadows the `Ray (*note _489::)' constructor defined
in the `Ray (*note light_Ray_class_reference::)' base class.

   Create a propagated light ray

Ray(const light::Ray &r)
........................

Create a propagated light ray

void add_generated(Ray *r)
..........................

Define a new child generated ray

const sys::Element * get_creator() const
........................................

Get element which generated this ray..

   See also set_creator (*note _1443::) function.

math::vector3 get_direction() const
...................................

Get global direction

math::vector3 get_direction(const sys::Element &e) const
........................................................

Get direction relative to given element

Ray * get_first_child() const
.............................

Get first ray generated from this one

sys::Element & get_intercept_element() const
............................................

Get light ray interception element

double get_intercept_intensity() const
......................................

Get ray intensity at interception point..

   See also set_intercept_intensity (*note _1445::) function.

const math::vector3 & get_intercept_point() const
.................................................

Get light ray interception point

double get_len() const
......................

Get light ray length..

   See also set_len (*note _1446::) function.

const material::Base * get_material() const
...........................................

Get material ray is propagated in..

   See also set_material (*note _1447::) function.

Ray * get_next_child() const
............................

Get next sibling ray generated by same parent

Ray * get_parent() const
........................

Get ray which generated this one

math::vector3 get_position() const
..................................

Get global position

math::vector3 get_position(const sys::Element &e) const
.......................................................

Get position relative to given element

bool is_lost() const
....................

Return true if ray is not intercepted

void set_creator(const sys::Element *creator)
.............................................

Set element which generated this ray..

   See also get_creator (*note _1429::) function.

void set_intercept(const sys::Element &e, const math::vector3 &point)
.....................................................................

Set light ray interception point and element

void set_intercept_intensity(double intercept_intensity)
........................................................

Set ray intensity at interception point..

   See also get_intercept_intensity (*note _1434::) function.

void set_len(double len)
........................

Set light ray length..

   See also get_len (*note _1436::) function.

void set_material(const material::Base *material)
.................................................

Set material ray is propagated in..

   See also get_material (*note _1437::) function.

trace::Ray class full member list
=================================

Functions
---------

   * Ray()

   * Ray(const light::Ray &r)

   * void add_generated(Ray *r)

   * math::vector<N> & direction()

   * const math::vector<N> & direction() const

   * const sys::Element * get_creator() const

   * math::vector3 get_direction() const

   * math::vector3 get_direction(const sys::Element &e) const

   * Ray * get_first_child() const

   * double get_intensity() const

   * sys::Element & get_intercept_element() const

   * double get_intercept_intensity() const

   * const math::vector3 & get_intercept_point() const

   * double get_len() const

   * const material::Base * get_material() const

   * Ray * get_next_child() const

   * Ray * get_parent() const

   * math::vector3 get_position() const

   * math::vector3 get_position(const sys::Element &e) const

   * double get_wavelen() const

   * bool is_lost() const

   * math::vector<3> ln_ln_clst_pt(const math::vectorPair<3> &line)
     const

   * double ln_ln_clst_pt_scale(const math::vectorPair<3> &line) const

   * math::vector<N> ln_pt_clst_pt(const math::vector<N> &point) const

   * double ln_pt_clst_pt_scale(const math::vector<N> &point) const

   * math::vector<N> & normal()

   * const math::vector<N> & normal() const

   * math::vectorPairBase<3> operator*(double factor)

   * const math::vectorPairBase<3> & operator+=(const
     math::vectorPairBase<3> &p)

   * const math::vector<N> & operator[](int n) const

   * math::vector<N> & operator[](int n)

   * math::vector<N> & origin()

   * const math::vector<N> & origin() const

   * math::vector<3> pl_ln_intersect(const math::vectorPair<3> &line)
     const

   * double pl_ln_intersect_scale(const math::vectorPair<3> &line) const

   * math::vector<N> seg_pt_clst_pt(const math::vector<N> &point) const

   * double seg_pt_clst_pt_scale(const math::vector<N> &point) const

   * void set_creator(const sys::Element *creator)

   * void set_intensity(double intensity)

   * void set_intercept(const sys::Element &e, const math::vector3
     &point)

   * void set_intercept_intensity(double intercept_intensity)

   * void set_len(double len)

   * void set_material(const material::Base *material)

   * void set_wavelen(double wavelen)

   * double x0() const

   * double & x0()

   * double x1() const

   * double & x1()

   * double y0() const

   * double & y0()

   * double y1() const

   * double & y1()

   * double z0() const

   * double & z0()

   * double z1() const

   * double & z1()

