// This file is part of the CircuitPython project: https://circuitpython.org
//
// SPDX-FileCopyrightText: Copyright (c) 2024 Mark Komus
//
// SPDX-License-Identifier: MIT
#pragma once

#include "py/obj.h"

#include "shared-module/audiocore/__init__.h"

extern const mp_obj_type_t audioeffects_echo_type;

typedef struct {
    mp_obj_base_t base;
    uint32_t delay_ms;
    uint16_t decay;
    uint8_t bits_per_sample;
    bool samples_signed;
    uint8_t channel_count;
    uint32_t sample_rate;

    uint32_t *buffer;
    uint32_t buffer_len; // buffer in bytes

    uint32_t *echo_buffer;
    uint32_t echo_buffer_len; // bytes

    uint32_t echo_buffer_read_pos; // words
    uint32_t echo_buffer_write_pos; // words

    mp_obj_t sample;
} audioeffects_echo_obj_t;

void audioeffects_echo_reset_buffer(audioeffects_echo_obj_t *self,
    bool single_channel_output,
    uint8_t channel);

audioio_get_buffer_result_t audioeffects_echo_get_buffer(audioeffects_echo_obj_t *self,
    bool single_channel_output,
    uint8_t channel,
    uint8_t **buffer,
    uint32_t *buffer_length);  // length in bytes

void audioeffects_echo_get_buffer_structure(audioeffects_echo_obj_t *self, bool single_channel_output,
    bool *single_buffer, bool *samples_signed,
    uint32_t *max_buffer_length, uint8_t *spacing);
