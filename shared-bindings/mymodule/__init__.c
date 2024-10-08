#include <stdint.h>

#include "py/obj.h"
#include "py/runtime.h"

#include "shared-bindings/mymodule/__init__.h"
#include "shared-bindings/mymodule/MyClass.h"

//| def randint(a: int, b: int) -> int:
//|     """Returns a randomly selected integer between a and b inclusive. Equivalent
//|     to ``randrange(a, b + 1, 1)``"""
//|     ...
//|
static mp_obj_t random_randint(mp_obj_t a_in, mp_obj_t b_in) {
    mp_int_t a = mp_obj_get_int(a_in);
    mp_int_t b = mp_obj_get_int(b_in);
    if (a > b) {
        mp_raise_ValueError(NULL);
    }
    return mp_obj_new_int(shared_modules_mymodule_randrange(a, b + 1, 1));
}
static MP_DEFINE_CONST_FUN_OBJ_2(random_randint_obj, random_randint);

static const mp_rom_map_elem_t mymodule_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_mymodule) },
    { MP_ROM_QSTR(MP_QSTR_randint), MP_ROM_PTR(&random_randint_obj) },
    // { MP_ROM_QSTR(MP_QSTR_MyClass), MP_ROM_PTR(&mymodule_myclass_type) },
};

static MP_DEFINE_CONST_DICT(mymodule_module_globals, mymodule_module_globals_table);

const mp_obj_module_t mymodule_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&mymodule_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_mymodule, mymodule_module);