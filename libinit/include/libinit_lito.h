/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <string>
#include <vector>

typedef struct variant_info {
    std::string prop_key;
    std::string prop_value;

    std::string brand;
    std::string device;
    std::string marketname;
    std::string model;
    std::string build_description;
    std::string build_fingerprint;
} variant_info_t;

void search_variant(const std::vector<variant_info_t> variants);
void set_variant_props(const variant_info_t variant);

typedef struct dalvik_heap_info {
    std::string heapstartsize;
    std::string heapgrowthlimit;
    std::string heapsize;
    std::string heapminfree;
    std::string heapmaxfree;
    std::string heaptargetutilization;
} dalvik_heap_info_t;

void set_dalvik_heap(void);

void property_override(std::string prop, std::string value, bool add = true);
void set_ro_build_prop(const std::string &prop, const std::string &value, bool product = false);
