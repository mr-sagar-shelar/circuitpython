#include <assert.h>
#include <string.h>

#include "py/runtime.h"
#include "shared-bindings/os/__init__.h"
#include "shared-bindings/mymodule/__init__.h"

mp_int_t shared_modules_mymodule_randrange(mp_int_t start, mp_int_t stop, mp_int_t step) {
    mp_int_t n;
    if (step > 0) {
        n = (stop - start + step - 1) / step;
    } else {
        n = (stop - start + step + 1) / step;
    }
    return n;
}