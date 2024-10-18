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

int i2s_stream_chunk(const cst_wave *w, int start, int size,
                     int last, cst_audio_streaming_info *asi)
{
    // If you start to see multiple $ on console then it means TTS integration is working
    printf(" $ ");
    return CST_AUDIO_STREAM_CONT;
}

mp_int_t shared_modules_tts_initialize() {
    flite_init();

    cst_voice *v;
    v = register_cmu_us_kal(NULL);

    flite_add_lang("eng", usenglish_init, cmulex_init);
    flite_add_lang("usenglish", usenglish_init, cmulex_init);

    cst_audio_streaming_info *asi = cst_alloc(struct cst_audio_streaming_info_struct, 1);
    asi->min_buffsize = 256;
    asi->asc = i2s_stream_chunk;
    asi->userdata = NULL;
    feat_set(v->features, "streaming_info", audio_streaming_info_val(asi));

    cst_utterance *u = flite_synth_text("hello world, how are you doing today", v);
    printf("\n Done TTS...\n");
    delete_utterance(u);
    u = NULL;

    return 0;
}

mp_int_t shared_modules_tts_register_voice() {
    return 1;
}

mp_int_t shared_modules_tts_register_cmu_us_kal() {
    // cst_voice *v;
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

READONLY (rx): ORIGIN = 0x100000, LENGTH = 1536K --- mulitply by 3: 4608
    RAM (rw): ORIGIN = 0x200000, LENGTH = 1022M ---- Add 3 * 1024

0x100000 hex = 1048576 dec = 1024 kb
0x200000 hex = 2097152 dec = 2048 kb + add difference of 3072 for 3 times 1024
    = 2048 + 3072
    = 5120
    = 5120 * 1024
    = 5242880 in decimal
    =  0x500000 in hex
*/