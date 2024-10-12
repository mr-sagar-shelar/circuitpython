#pragma once
#include "py/obj.h"

mp_int_t shared_modules_tts_initialize(void);
mp_int_t shared_modules_tts_register_voice(void);
mp_int_t shared_modules_tts_register_cmu_us_kal(void);
mp_int_t shared_modules_tts_synth_text(void);
mp_int_t shared_modules_tts_text_to_wave(void);
