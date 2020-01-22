/*
** EPITECH PROJECT, 2019
** bitmap_header.c
** File description:
** Exersice 2 - The BMP Format
*/

#include "bitmap.h"

void make_bmp_header(bmp_header_t *header, size_t size)
{
    int len = sizeof(bmp_header_t) + sizeof(bmp_info_header_t);
    int x = 1;

    header->magic = (*(char *) &x ? 0x4D42 : 0x424D);
    header->size = size * size * sizeof(int) + len;
    header->_app1 = 0;
    header->_app2 = 0;
    header->offset = len;
}

void make_bmp_info_header(bmp_info_header_t *header, size_t size)
{
    header->size = sizeof(bmp_info_header_t);
    header->width = size;
    header->height = size;
    header->planes = 1;
    header->bpp = 32;
    header->compression = 0;
    header->h_resolution = 0;
    header->v_resolution = 0;
    header->palette_size = 0;
    header->raw_data_size = size * size * sizeof(uint32_t);
    header->important_colors = 0;
}

void write_bmp_header(int fd)
{
    bmp_header_t header;
    
    make_bmp_header(&header, 32);
    write(fd, &header, sizeof(header));
}

void write_bmp_info_header(int fd)
{
    bmp_info_header_t info;

    make_bmp_info_header(&info, 32);
    write(fd, &info, sizeof(info));
}