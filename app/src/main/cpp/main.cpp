#include <android/log.h>
#include <dlfcn.h>
#include <pthread.h>
#include <unistd.h>
#include "core/include/obfuscate.h"
#include "core/include/Logger.h"
#include "core/include/Utils.h"
#include "core/include/Macros.h"
#include "core/include/loader.h"
#define targetLibname = "libBootloader.so"

__attribute__ ((visibility ("default")))
void start(){
    //init hooks here if needed
}


extern "C"
__attribute__ ((visibility ("default")))
void userlib_input(std::vector<std::string> vec){
    //userinput piped here args seperated by spaces
    if(vec[0] == "hello"){
        toast("helloworld");
        return;
    }
}


__unused __attribute__((constructor))
void constructor_main() {
    LOGI(OBFUSCATE("Starting Sky Userlib.. Build time: " __DATE__ " " __TIME__));
}