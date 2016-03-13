#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "CinderCereal.h"
#include <cereal/archives/binary.hpp>

using namespace ci;
using namespace ci::app;
using namespace std;

class CerealApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void CerealApp::setup()
{
}

void CerealApp::mouseDown( MouseEvent event )
{
}

void CerealApp::update()
{
}

void CerealApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( CerealApp, RendererGl )
