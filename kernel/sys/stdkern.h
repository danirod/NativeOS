/*
 * This file is part of NativeOS
 * Copyright (C) 2015-2018 The NativeOS contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <stddef.h>

/**
 * @brief Allocate some memory buffer in the heap.
 * @param size the amount of bytes to allocate in the heap.
 * @return a pointer to the allocated buffer or NULL if there was an error.
 */
void *
malloc(size_t size);

/**
 * @brief Deallocate a memory buffer from the heap.
 * @param ptr a pointer to the memory region to be deallocated from heap.
 */
void
free(void *ptr);

/**
 * @brief Copies the given number of characters from one buffer to other.
 * @param dst the target buffer to copy data to.
 * @param src the source buffer to copy data from.
 * @param count the amount of bytes to transfer from source to dest.
 */
void *
memcpy(void *dst, void *src, size_t count);

/**
 * @brief Compare lexicographically both strings.
 * @param s1 the first string to compare
 * @param s2 the second string to compare
 * @return <0 if s1 > s2, >0 if s1 < s2, 0 if s1 == s2
 */
int
strcmp(const char *s1, const char *s2);

/**
 * @brief Compare lexicographically no more than n characters from both strings.
 * @param s1 the first string to compare
 * @param s2 the second string to compare
 * @param n the maximum number of characters to compare
 * @return <0 if s1 > s2, >0 if s1 < s2, 0 if s1 == s2
 */
int
strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Copies the string src into dst.
 * @param dst the target string where to put the copied characters.
 * @param src the source string to copy characters form.
 * @return a pointer to dst string.
 */
char *
strcpy(char *dst, const char *src);

/**
 * @brief Copies at most len characters from src into dst.
 * @param dst the target string where to put the copied characters.
 * @param src the source string to copy characters from.
 * @param len the maximum amount of characters to copy.
 * @return a pointer to dst string.
 */
char *
strncpy(char *dst, const char *src, size_t len);

/**
 * @brief Computes the length of the string s.
 * @param s the string whose length we want to compute.
 * @return the computed length of the string s.
 */
size_t
strlen(const char *s);

/**
 * @brief Computes the length of the string s as long as doesn't exceed maxlen.
 * @param s the string whose length we want to compute.
 * @param maxlen the maximum amount of characters to compute.
 * @return the computed length of the string s or maxlen if it's larger.
 */
size_t
strnlen(const char *s, size_t maxlen);
