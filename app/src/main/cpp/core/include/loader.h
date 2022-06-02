//
// Created by Lukas on 01/06/2022.
//
#pragma once
#ifndef USERLIB_LOADER_H
#define USERLIB_LOADER_H

#endif //USERLIB_LOADER_H
#include <dlfcn.h>
const char* launcherlibname = "libciphered.so";
long libid;

void (*userhook)(void *const addr, void *const replace, void **result, long id);
void (*toast)(const char*);

void start();
extern "C"
__attribute__ ((visibility ("default")))
void userlib_init(long id){
    LOGD("userlib_init");
    libid = id;
    void *launcher_lib  = dlopen(launcherlibname, RTLD_LOCAL);
    userhook = (void (*)(void *const, void *const, void **, long))dlsym(launcher_lib, "userhook");
    toast = (void (*)(const char*))dlsym(launcher_lib, "toast");
    toast("loaded userlib");
    start();

}

void hook(void *const addr, void *const replace, void **result){
    userhook(addr, replace, result, libid);
}