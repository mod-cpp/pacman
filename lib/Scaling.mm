/*
This is an Objective C file to detect the window's
resolution scale on Apple platforms.
It is not a C++ file and is not part of this course!
*/
#import "AppKit/NSWindow.h"
#include <cassert>

double scaling_factor_for_window(void* ptr) {
    NSWindow* window = static_cast<NSWindow*>(ptr);
    assert(window);
    double d = [window backingScaleFactor];
    return d;
}