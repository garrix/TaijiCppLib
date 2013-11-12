 
#include "INativeAdapter.hpp"

#include "LibClass.hpp"

#pragma once 

using namespace TaijiLib;  

namespace TaijiCppLibWrapper { 


	/*
	Platform specific class that implements any functionality that the Native Library 
	may rely on.
	*/
	public ref class NativeAdapter sealed 
	{  
	public: 
		NativeAdapter(){};
		/*Method that facilitates modifying a string from the Native Library*/
		Platform::String ^ ModifySomeStuff( Platform::String ^ someStuff); 
	};


	/*
	Platform class that implements a bridge between Platform and Native code;

	WinRT classes that are exposed must be declared ref sealed.
	*/
	public ref class  LibClassWrapper sealed {

	private : 
		// instance of the Native implementation of LibClass
		LibClass * l; 
		// public non-virtual destructors not allowed
		~LibClassWrapper(){ delete l;};
	public:

		/*
		the bulk of this implementation is just inline C++ methods that call methods on the private
		instance of the native object;
		*/

		// creates an instance of the native object to be used by the wrapper
		LibClassWrapper(){ l = new  LibClass();};

		static bool LibLoaded(){return  LibClass::LibLoaded();};

		static void LoadLib(bool load){return  LibClass::LoadLib(load);};

		void InstanceLoadLib(bool load){ l->InstanceLoadLib(load);}; 

		Platform::String ^ CallNativeDelegate( Platform::String ^ message);

	};

}

