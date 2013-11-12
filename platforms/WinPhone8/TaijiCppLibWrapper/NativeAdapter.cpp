 /* Excluding this because we're not actually using debug output anymore,
 but they were required for the use of OutputDebugString()(
 #include <windows.h>
 #include <client.h>
 #include <debugapi.h> 
*/  

/*
http://msdn.microsoft.com/en-us/library/windowsphone/develop/ff402572(v=vs.105).aspx
Debugging apps for Windows Phone:
you cannot debug both the managed code and the native code portions of your app, or 
both the managed code and the native code portions of your background agent, at the same time.

Casting WinRt managed pointers
http://stackoverflow.com/questions/11460042/passing-an-winrt-object-type-through-non-winrt-code

http://www.i-programmer.info/programming/winrt/3172-building-and-using-winrt-components.html

some Platform::String mangling 
http://stackoverflow.com/questions/11545951/how-to-convert-from-char-to-platformstring-c-cli
*/ 

#include "NativeAdapter.h" 

using namespace TaijiCppLibWrapper;


INativeAdapter::INativeAdapter(){} 

INativeAdapter::~INativeAdapter(){ 
	delete self;
} 

void INativeAdapter::init(){   
	/*  
	Casting WinRt managed pointers
	http://stackoverflow.com/questions/11460042/passing-an-winrt-object-type-through-non-winrt-code

	http://www.i-programmer.info/programming/winrt/3172-building-and-using-winrt-components.html
	*/ 
	self = (void*) ref new NativeAdapter() ;  
}


std::string INativeAdapter::modifyInput(std::string message){


	NativeAdapter ^ n = ref new NativeAdapter();   
	Platform::String ^ someStuff = n->ModifySomeStuff(ref new Platform::String(std::wstring( message.begin(), message.end()).c_str()) ); 
	std::string modifiedMessage = std::string( someStuff->Begin(), someStuff->End()).c_str();
	return modifiedMessage;
}



Platform::String ^  NativeAdapter::ModifySomeStuff( Platform::String ^ someStuff ) 
{
	someStuff += "WinRt Modified" ;
	return someStuff; 
}


Platform::String ^ LibClassWrapper::CallNativeDelegate( Platform::String ^ message)
{ 
	std::string ms = std::string( message->Begin(), message->End()).c_str();
	ms =   l->CallNativeDelegate(ms);
	return ref new Platform::String(std::wstring( ms.begin(), ms.end()).c_str());
}
