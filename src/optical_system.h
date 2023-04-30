#pragma once
#include "goptical/core/material/air.hpp"
#include <goptical/core/analysis/rayfan.hpp>
#include <goptical/core/analysis/spot.hpp>
#include <goptical/core/curve/sphere.hpp>
#include <goptical/core/data/plot.hpp>
#include <goptical/core/io/renderer_svg.hpp>
#include <goptical/core/io/rgb.hpp>
#include <goptical/core/light/spectral_line.hpp>
#include <goptical/core/material/abbe.hpp>
#include <goptical/core/material/base.hpp>
#include <goptical/core/material/sellmeier.hpp>
#include <goptical/core/math/quaternion.hpp>
#include <goptical/core/math/transform.hpp>
#include <goptical/core/math/vector.hpp>
#include <goptical/core/shape/disk.hpp>
#include <goptical/core/sys/image.hpp>
#include <goptical/core/sys/lens.hpp>
#include <goptical/core/sys/source.hpp>
#include <goptical/core/sys/source_disk.hpp>
#include <goptical/core/sys/source_point.hpp>
#include <goptical/core/sys/source_rays.hpp>
#include <goptical/core/sys/stop.hpp>
#include <goptical/core/sys/surface.hpp>
#include <goptical/core/sys/system.hpp>
#include <goptical/core/trace/distribution.hpp>
#include <goptical/core/trace/params.hpp>
#include <goptical/core/trace/result.hpp>
#include <goptical/core/trace/sequence.hpp>
#include <goptical/core/trace/tracer.hpp>
#include <renderer_easy3d.hpp>
#include <memory>
class Optical_system
{
public:
std::shared_ptr<goptical::sys::System> opt_sys;
std::shared_ptr<goptical::trace::Tracer> tracer;
goptical::io::Renderer* renderer;
Optical_system();
~Optical_system();
//--------------------------------------------------------------------------
//
//--------------------------------------------------------------------------
void buildSystem(std::shared_ptr<goptical::sys::System>& opt_sys);
void update();
};



