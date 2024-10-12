#include <assert.h>
#include <string.h>

#include "py/runtime.h"
#include "shared-bindings/os/__init__.h"
#include "shared-bindings/tts/__init__.h"

mp_int_t shared_modules_tts_initialize() {
    return 0;
}

mp_int_t shared_modules_tts_register_voice() {
    return 1;
}

mp_int_t shared_modules_tts_register_cmu_us_kal() {
    return 2;
}

mp_int_t shared_modules_tts_synth_text() {
    return 3;
}

mp_int_t shared_modules_tts_text_to_wave() {
    return 4;
}