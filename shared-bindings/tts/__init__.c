#include <stdint.h>
#include "py/obj.h"
#include "py/runtime.h"
#include "shared-bindings/tts/__init__.h"

static mp_obj_t tts_initialize(mp_obj_t a_in, mp_obj_t b_in)
{
    return mp_obj_new_int(shared_modules_tts_initialize());
}
static MP_DEFINE_CONST_FUN_OBJ_2(initialize_obj, tts_initialize);

static mp_obj_t tts_register_voice(mp_obj_t a_in, mp_obj_t b_in)
{
    return mp_obj_new_int(shared_modules_tts_register_voice());
}
static MP_DEFINE_CONST_FUN_OBJ_2(register_voice_obj, tts_register_voice);

static mp_obj_t tts_register_cmu_us_kal(mp_obj_t a_in, mp_obj_t b_in)
{
    return mp_obj_new_int(shared_modules_tts_register_cmu_us_kal());
}
static MP_DEFINE_CONST_FUN_OBJ_2(register_cmu_us_kal_obj, tts_register_cmu_us_kal);

static mp_obj_t tts_synth_text(mp_obj_t a_in, mp_obj_t b_in)
{
    return mp_obj_new_int(shared_modules_tts_synth_text());
}
static MP_DEFINE_CONST_FUN_OBJ_2(synth_text_obj, tts_synth_text);

static mp_obj_t tts_text_to_wave(mp_obj_t a_in, mp_obj_t b_in)
{
    return mp_obj_new_int(shared_modules_tts_text_to_wave());
}
static MP_DEFINE_CONST_FUN_OBJ_2(text_to_wave_obj, tts_text_to_wave);

static const mp_rom_map_elem_t tts_module_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_tts)},
    {MP_ROM_QSTR(MP_QSTR_initialize), MP_ROM_PTR(&initialize_obj)},
    {MP_ROM_QSTR(MP_QSTR_register_voice), MP_ROM_PTR(&register_voice_obj)},
    {MP_ROM_QSTR(MP_QSTR_register_cmu_us_kal), MP_ROM_PTR(&register_cmu_us_kal_obj)},
    {MP_ROM_QSTR(MP_QSTR_synth_text), MP_ROM_PTR(&synth_text_obj)},
    {MP_ROM_QSTR(MP_QSTR_text_to_wave), MP_ROM_PTR(&text_to_wave_obj)},
};

static MP_DEFINE_CONST_DICT(tts_module_globals, tts_module_globals_table);

const mp_obj_module_t tts_module = {
    .base = {&mp_type_module},
    .globals = (mp_obj_dict_t *)&tts_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_tts, tts_module);
