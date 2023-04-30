#include "optical_system.h"

using namespace goptical;


Optical_system::Optical_system()
{
	// -----------------
	opt_sys = std::make_shared<sys::System>();
	buildSystem(opt_sys);
	//auto bb = opt_sys->get_bounding_box();
	renderer = (io::Renderer*) new io::RendererEasy3d();
	//------------------	
	update();
}

Optical_system::~Optical_system()
{
}
//--------------------------------------------------------------------------
//
//--------------------------------------------------------------------------
void Optical_system::buildSystem(std::shared_ptr<sys::System>& opt_sys)
{
	// light source
	auto source = std::make_shared<sys::SourcePoint>(sys::SourceAtInfinity, math::Vector3(0, 0, 1));
	auto image = std::make_shared<sys::Image>(math::Vector3(0, 0, 140.35), 30);
	auto lens1 = std::make_shared<sys::Lens>(math::Vector3(0, 0, 0));
	lens1->add_surface(30.0, 15.0, 4, std::make_shared<material::AbbeVd>(1.607170, 59.5002));
	lens1->add_surface(60.0, 15.0, 4);
	auto lens2 = std::make_shared<sys::Lens>(math::Vector3(0, 0, 50));
	lens2->add_surface(-50.0, 15.0, 4, std::make_shared<material::AbbeVd>(1.607170, 59.5002));
	lens2->add_surface(60.0, 15.0, 4);
	opt_sys->add(source);
	opt_sys->add(lens1);
	opt_sys->add(lens2);
	opt_sys->add(image);

	auto seq = std::make_shared<trace::Sequence>(*opt_sys);
	opt_sys->get_tracer_params().set_sequential_mode(seq);
	std::cout << "opt_system:" << std::endl;
	std::cout << opt_sys;
	std::cout << "sequence:" << std::endl << seq;

	// trace and draw rays from rays source
	opt_sys->enable_single<sys::Source>(*source);
	tracer = std::make_shared<trace::Tracer>(opt_sys.get());
	tracer->get_trace_result().set_generated_save_state(*source);
	tracer->trace();
}

void Optical_system::update()
{
	// fill arrays     
	auto ctx = static_cast<io::Context*>(renderer->user_data);
	ctx->clear();
	opt_sys->draw_3d(*renderer);
	// draw rays
	auto& res = tracer->get_trace_result();
	res.draw_3d(*renderer);
}




