#pragma once

#define CHWND_EXCEPT( hr ) ZApplication::HrException( __LINE__,__FILE__,(hr) )
#define CHWND_LAST_EXCEPT() ZApplication::HrException( __LINE__,__FILE__,GetLastError() )
#define CHWND_NOGFX_EXCEPT() ZApplication::NoGfxException( __LINE__,__FILE__ )