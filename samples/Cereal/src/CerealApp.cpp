#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include "CinderCereal.h"

using namespace ci;
using namespace ci::app;
using namespace std;

// See http://uscilab.github.io/cereal/index.html for more examples

class CerealApp : public App {
  public:
	void setup() override
	{
		// create a JSON archive that output to the console
		cereal::JSONOutputArchive archive( console() );
		
		// some data to serialize
		vector<int> vec = {1, 2, 3, 4, 5};
		vector<vec3> vecOfVec3 = { vec3(1), vec3(2), vec3(3,4,5) };
		CameraPersp camera( getWindowWidth(), getWindowHeight(), 50.0f, 0.1f, 100.0f );
		fs::path p = getAppPath();
		auto args = getCommandLineArgs();

		// serialize
		archive( vec, CEREAL_NVP(vecOfVec3), CEREAL_NVP(camera), getWindowBounds(), getWindowPos(), getWindowBounds(), p, args );
		
		// quit the app
		quit();
	}
};

CINDER_APP( CerealApp, RendererGl )
