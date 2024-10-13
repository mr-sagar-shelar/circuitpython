#include <assert.h>
#include <string.h>

#include "py/runtime.h"
#include "shared-bindings/os/__init__.h"
#include "shared-bindings/tts/__init__.h"
#include "flite.h"

cst_voice *register_cmu_us_kal(const char *voxdir);
void usenglish_init(cst_voice *v);
void cmu_indic_lang_init(cst_voice *v);
cst_lexicon *cmulex_init(void);
cst_lexicon *cmu_indic_lex_init(void);

mp_int_t shared_modules_tts_initialize() {
    flite_init();
    return 0;
}

mp_int_t shared_modules_tts_register_voice() {
    return 1;
}

mp_int_t shared_modules_tts_register_cmu_us_kal() {
    cst_voice *v;
    // v = register_cmu_us_kal(NULL);
    // flite_add_lang("eng", usenglish_init, cmulex_init);
    // flite_add_lang("usenglish", usenglish_init, cmulex_init);
    return 2;
}

mp_int_t shared_modules_tts_synth_text() {
    return 3;
}

mp_int_t shared_modules_tts_text_to_wave() {
    return 4;
}

/*
Memory region         Used Size  Region Size  %age Used
        READONLY:      964161 B      1536 KB     61.30%
             RAM:       31496 B      1022 MB      0.00%


Memory region         Used Size  Region Size  %age Used
        READONLY:     3146480 B      1536 KB    200.05%
            RAM:       35880 B      1022 MB      0.00%
*/