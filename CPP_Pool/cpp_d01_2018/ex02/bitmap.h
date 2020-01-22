/*
** EPITECH PROJECT, 2019
** bitmap.h
** File description:
** Exersice 2 - The BMP Format
*/

#ifndef _BITMAP_H_
#define _BITMAP_H_

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

typedef struct __attribute__((packed)) bmp_header {
    uint16_t magic;
    uint32_t size;
    uint32_t offset;
    uint16_t _app1;
    uint16_t _app2;
} bmp_header_t;

typedef struct __attribute__((packed)) bmp_info_header {
    uint32_t size;
    uint32_t width;
    uint32_t height;
    uint16_t planes;
    uint16_t bpp;
    uint32_t compression;
    uint32_t raw_data_size;
    uint32_t h_resolution;
    uint32_t v_resolution;
    uint32_t palette_size;
    uint32_t important_colors;
} bmp_info_header_t;

void write_bmp_header(int fd);
void write_bmp_info_header(int fd);
void make_bmp_header(bmp_header_t *header, size_t size);
void make_bmp_info_header(bmp_info_header_t *header, size_t size);

#endif